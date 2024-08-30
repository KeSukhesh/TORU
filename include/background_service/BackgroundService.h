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
#include <ServerConfiguration.h>

using boost::asio::ip::tcp;

class BackgroundService {
public:
    BackgroundService(const std::string& log_file_path, const std::string& config_file_path)
    : logger_(std::make_unique<FileLogger>(log_file_path)), config_(ServerConfiguration(config_file_path)), close_flag_(false) {}

protected:
    virtual void start_server();
    virtual void stop_server();
    virtual std::string read_file_to_string(const std::string& filename);
    virtual void handle_server_connection(tcp::socket socket);
    void monitor_user_input();

    FileLogger* get_logger() { return logger_.get(); }
    void set_logger(std::unique_ptr<FileLogger> logger) { logger_ = std::move(logger); }
    ServerConfiguration get_server_config() { return config_; }
    void set_server_config(ServerConfiguration config) { config_ = config; }

private:
    ServerConfiguration config_;
    std::unique_ptr<FileLogger> logger_;
    std::atomic<bool> close_flag_;
};