#include "background_service/BackgroundService.h"

void BackgroundService::start_server() {
    ThreadPool pool(num_threads_);
    boost::asio::io_context io_context;
    tcp::acceptor acceptor(io_context, tcp::endpoint(tcp::v4(), port_));
    // log start
    // std::cout << "Multithreaded Server Running with " << num_threads_ << " threads..." << std::endl;
    while(true) {
        auto socket = std::make_shared<tcp::socket>(io_context);
        acceptor.accept(*socket);

        pool.execute([this, socket]() mutable {
            handle_server_connection(std::move(*socket));
        });
    }
}

// base method to get overriden
void BackgroundService::handle_server_connection(tcp::socket socket) {
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

        std::string status_line = "HTTP/1.1 200 OK";
        std::string filename = "../src/util/hello.html";

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

std::string BackgroundService::read_file_to_string(const std::string& filename) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        throw std::runtime_error("Could not open file " + filename);
    }

    std::stringstream buffer;
    buffer << file.rdbuf();
    return buffer.str();
}

void BackgroundService::stop_server() {
    // probably log?
}