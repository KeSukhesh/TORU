#include "background_service/BackgroundService.h"

void BackgroundService::start_server() {
    ThreadPool pool(num_threads_);
    boost::asio::io_context io_context;
    tcp::acceptor acceptor(io_context, tcp::endpoint(tcp::v4(), port_));

    std::thread input_thread(&BackgroundService::monitor_user_input, this);

    while (!close_flag_) {
        auto socket = std::make_shared<tcp::socket>(io_context);
        boost::system::error_code ec;
        acceptor.accept(*socket, ec);

        if (ec) {
            if (close_flag_) {
                get_logger()->logInfo("Server is finalising last requests and then shutting down...");
                acceptor.close();
                io_context.stop();
            } else {
                get_logger()->logError("Error accepting connection", std::runtime_error(ec.message()));
            }
            break;
        }

        pool.execute([this, socket]() mutable {
            handle_server_connection(std::move(*socket));
        });
    }

    if (input_thread.joinable()) {
        input_thread.join();
    }
}

// base method to get overriden
void BackgroundService::handle_server_connection(tcp::socket socket) {
    try {
        boost::asio::streambuf buffer;
        std::istream input_stream(&buffer);
        boost::asio::read_until(socket, buffer, "\r\n");
        std::string request_line;
        std::getline(input_stream, request_line);
        if (!request_line.empty() && request_line.back() == '\r') {
            request_line.pop_back();
        }

        std::ostringstream oss;
        oss << std::this_thread::get_id();
        get_logger()->logInfo("Worker Thread ID: " + oss.str() + " - Request Receieved: " + request_line);


        std::string status_line = "HTTP/1.1 200 OK";
        std::string filename = "../src/util/hello.html";

        std::string contents = read_file_to_string(filename);
        std::string length = std::to_string(contents.size());
        std::string response = status_line + "\r\nContent-Length: " + length + "\r\n\r\n" + contents;
        get_logger()->logInfo("Worker Thread ID: " + oss.str() + " - Responded With: " + status_line);
        boost::asio::write(socket, boost::asio::buffer(response));
    }
    catch (std::exception& e) {
        get_logger()->logError("Could Not Read Request in handle_server_connection()", e);
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
    get_logger()->logInfo("Server has Shut Down.");
}

void BackgroundService::monitor_user_input() {
    char input;
    while (!close_flag_) {
        std::cin >> input;
        if (input == 'E') {
            get_logger()->logInfo("Shutdown Signal Received, Finalising Last Requests...");
            close_flag_ = true;
        }
    }
}