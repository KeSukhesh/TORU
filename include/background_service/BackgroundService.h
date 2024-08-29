#pragma once
#include <iostream>
#include <thread>
#include <chrono>
#include <boost/asio.hpp>
#include <fstream>
#include <sstream>
#include <iomanip>

#include <ThreadPool.h>

using boost::asio::ip::tcp;

class BackgroundService {
public:
    BackgroundService(int num_threads) : num_threads_(num_threads) {}

protected:
    virtual void start_server(int port);
    virtual void stop_server();
    virtual std::string read_file_to_string(const std::string& filename);
    virtual void handle_server_connection(tcp::socket socket);

    int get_num_threads() { return num_threads_; }
    void set_num_threads(int num_threads) { num_threads_ = num_threads; }
    int get_server_port() { return port_; }
    void set_server_port(int port) { port_ = port; }
private:
    int num_threads_ = 0;
    int port_ = 7878;
};