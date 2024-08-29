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
    return;
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