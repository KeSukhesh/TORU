#include <iostream>
#include <thread>
#include <chrono>
#include "TradingEngineServer.h"

void TradingEngineServer::run_trading_engine() {
    try {
        ServerConfiguration config = get_server_config();
        get_logger()->logInfo("Multithreaded Server Running with " + std::to_string(config.get_number_of_threads()) + " Threads...");
        start_server();
        stop_server();
    }
    catch (std::exception& e) {
        get_logger()->logError("Could Not Run Trading Engine", e);
    }
}

void TradingEngineServer::handle_server_connection(tcp::socket socket) {
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
        get_logger()->logInfo("Worker Thread ID: " + oss.str() + " - Responded With: " + status_line);
        boost::asio::write(socket, boost::asio::buffer(response));
    }
    catch (std::exception& e) {
        get_logger()->logError("Could Not Read Request in handle_server_connection()", e);
    }
}