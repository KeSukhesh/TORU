#pragma once
#include <iostream>
#include <thread>
#include <chrono>
#include <boost/asio.hpp>
#include <fstream>
#include <sstream>
#include <iomanip>

#include <ThreadPool.h>
#include <FileLogger.h>

using boost::asio::ip::tcp;

class BackgroundService {
public:
    BackgroundService(const std::string& logFilePath) : logger_(std::make_unique<FileLogger>(logFilePath)) {}

protected:
    virtual void start_server();
    virtual void stop_server();
    virtual std::string read_file_to_string(const std::string& filename);
    virtual void handle_server_connection(tcp::socket socket);

    int get_num_threads() { return num_threads_; }
    void set_num_threads(int num_threads) { num_threads_ = num_threads; }
    int get_server_port() { return port_; }
    void set_server_port(int port) { port_ = port; }
    FileLogger* get_logger() { return logger_.get(); }
    void set_logger(std::unique_ptr<FileLogger> logger) { logger_ = std::move(logger); }

private:
    int num_threads_ = 1;
    int port_ = 7878;
    std::unique_ptr<FileLogger> logger_;
};