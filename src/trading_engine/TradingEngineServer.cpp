#include <iostream>
#include <thread>
#include <chrono>
#include "TradingEngineServer.h"

void TradingEngineServer::run_trading_engine() {
    try {
        set_server_port(config_->getPort());
        set_num_threads(config_->getNumberOfThreads());
        start_server();
    }
    catch (std::exception& e) {
        // log error;
        return;
    }
}

void TradingEngineServer::handle_server_connection(tcp::socket socket) {
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
        } else if (request_line == "GET /sleep HTTP/1.1") {
            std::this_thread::sleep_for(std::chrono::seconds(5));
            status_line = "HTTP/1.1 200 OK";
            filename = "../src/util/hello.html";
        }  else if (request_line == "GET /buy HTTP/1.1") {
            status_line = "HTTP/1.1 200 OK";
            filename = "../src/util/buy.html";
        }  else if (request_line == "GET /sell HTTP/1.1") {
            status_line = "HTTP/1.1 200 OK";
            filename = "../src/util/sell.html";
        } else {
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