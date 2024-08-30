#pragma once

#include <string>
#include <fstream>
#include <iostream>
#include <nlohmann/json.hpp>

class ServerConfiguration {
public:
    ServerConfiguration(const std::string& configFilePath) {
        parseConfigFile(configFilePath);
    }

    int getPort() const {
        return port_;
    }

    int getNumberOfThreads() const {
        return number_of_threads_;
    }

private:
    int port_;
    int number_of_threads_;
    std::string exit_flag_;

    void parseConfigFile(const std::string& configFilePath) {
        std::ifstream configFile(configFilePath);
        if (configFile.is_open()) {
            nlohmann::json configJson;
            configFile >> configJson;

            port_ = configJson.value("Port", 7878);
            number_of_threads_ = configJson.value("NumberOfThreadsInPool", 1);
            exit_flag_ = configJson.value("ServerCloseFlag", "E");
        } else {
            std::cerr << "Unable to open config file: " << configFilePath << std::endl;
            port_ = 7878;
            number_of_threads_ = 1;
        }
    }
};