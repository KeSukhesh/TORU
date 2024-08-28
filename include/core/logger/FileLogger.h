#pragma once

#include "Logger.h"

class FileLogger : public Logger
{
public:
    FileLogger(const std::string& filename) : logFile_(filename, std::ios::app) {
        if (!logFile_.is_open()) {
            throw std::runtime_error("Unable to open log file");
        }
    }

    ~FileLogger() {
        if (logFile_.is_open()) {
            logFile_.close();
        }
    }

    void setLogFile(const std::string& filename) {
        logFile_.open(filename, std::ios::app);
        if (!logFile_.is_open()) {
            throw std::runtime_error("Unable to open log file");
        }
    }

protected:
    void log(LogLevel level, const std::string& message) override {
        if (level >= getLogLevel()) {
            std::lock_guard<std::mutex> lock(logMutex);
            std::string formattedMessage = formatMessage(level, message);
            std::cout << formattedMessage; // Console logging
            if (logFile_.is_open()) {
                logFile_ << formattedMessage; // File logging
                logFile_.flush();
            }

        }
    }

private:
    std::ofstream logFile_;
    std::mutex logMutex;
};