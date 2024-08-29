#include "background_service/IBackgroundService.h"

void IBackgroundService::start_server(int port) {
    ThreadPool pool(num_threads_);
    boost::asio::io_context io_context;
    tcp::acceptor acceptor(io_context, tcp::endpoint(tcp::v4(), port));
    // log start
    std::cout << "Multithreaded Server Running with " << num_threads_ << " threads..." << std::endl;
    while(true) {
        auto socket = std::make_shared<tcp::socket>(io_context);
        acceptor.accept(*socket);

        pool.execute([this, socket]() mutable {
            handle_server_connection(std::move(*socket));
        });
    }
}

// base method that gets overriden
void IBackgroundService::handle_server_connection(tcp::socket socket) {
    std::stringstream ss;
    // can probably log here for indepedent workers.

    try {
        boost::asio::streambuf buffer;
        std::istream input_stream(&buffer);
        boost::asio::read_until(socket, buffer, "\r\n");
        std::string request_line;
        std::getline(input_stream, request_line);
        if (!request_line.empty() && request_line.back() == '\r') {
            request_line.pop_back();
        }

        std::string status_line;
        std::string filename;
        if (request_line == "GET / HTTP/1.1") {
            status_line = "HTTP/1.1 200 OK";
            filename = "../src/util/hello.html";
        }  else {
            status_line = "HTTP/1.1 404 NOT FOUND";
            filename = "../src/util/404.html";
        }

        std::string contents = read_file_to_string(filename);
        std::string length = std::to_string(contents.size());
        std::string response = status_line + "\r\nContent-Length: " + length + "\r\n\r\n" + contents;
        boost::asio::write(socket, boost::asio::buffer(response));
    }
    catch (std::exception& e) {
        // log
        // std::cerr << "Error: " << e.what() << std::endl;
    }
}

std::string IBackgroundService::read_file_to_string(const std::string& filename) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        throw std::runtime_error("Could not open file " + filename);
    }

    std::stringstream buffer;
    buffer << file.rdbuf();
    return buffer.str();
}

void IBackgroundService::stop_server() {
    // probably log?
}