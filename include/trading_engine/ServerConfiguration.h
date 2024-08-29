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
        return numberOfThreads_;
    }

private:
    int port_;
    int numberOfThreads_;

    void parseConfigFile(const std::string& configFilePath) {
        std::ifstream configFile(configFilePath);
        // can encapsualte this in try {} from engine class and throw exception ?
        if (configFile.is_open()) {
            nlohmann::json configJson;
            configFile >> configJson;

            port_ = configJson.value("Port", 7878);  // Default to 7878 if not specified
            numberOfThreads_ = configJson.value("NumberOfThreads", 1);  // Default to 1 if not specified
        } else {
            std::cerr << "Unable to open config file: " << configFilePath << std::endl;
            port_ = 7878;
            numberOfThreads_ = 1;
        }
    }
};