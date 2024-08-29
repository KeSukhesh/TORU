#pragma once
#include <iostream>
#include <thread>
#include <chrono>
#include <boost/asio.hpp>
#include <fstream>
#include <sstream>
#include <iomanip>

#include <trading_engine_threadpool/ThreadPool.h>

using boost::asio::ip::tcp;

class IBackgroundService {
public:
    IBackgroundService(int num_threads) : num_threads_(num_threads) {}

    virtual void start_server(int port);
    virtual void stop_server();

    int get_num_threads() { return num_threads_; }
    void set_num_threads(int num_threads) { num_threads_ = num_threads; }

protected:
    virtual std::string read_file_to_string(const std::string& filename);
    virtual void handle_server_connection(tcp::socket socket);

private:
    int num_threads_ = 0;
};