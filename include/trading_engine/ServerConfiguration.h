#pragma once

#include <string>
#include <fstream>
#include <iostream>
#include <nlohmann/json.hpp>

class ServerConfiguration {
public:
    ServerConfiguration(const std::string& configFilePath) {
        parse_config_file(configFilePath);
    }

    int get_port() const {
        return port_;
    }

    int get_number_of_threads() const {
        return number_of_threads_;
    }

    std::string get_exit_flag() const {
        return exit_flag_;
    }

private:
    int port_;
    int number_of_threads_;
    std::string exit_flag_;

    void parse_config_file(const std::string& config_file_path) {
        std::ifstream config_file(config_file_path);
        if (config_file.is_open()) {
            nlohmann::json config_json;
            config_file >> config_json;

            port_ = config_json.value("Port", 7878);
            number_of_threads_ = config_json.value("NumberOfThreadsInPool", 1);
            exit_flag_ = config_json.value("ServerCloseFlag", "E");
        } else {
            std::cerr << "Unable to open config file: " << config_file_path << std::endl;
            port_ = 7878;
            number_of_threads_ = 1;
        }
    }
};