#pragma once

#include "Logger.h"
#include <fstream>
#include <mutex>
#include <stdexcept>
#include <iostream>

class FileLogger : public Logger
{
public:
    FileLogger(const std::string& filename) {
        // Open in trunc mode to clear the file // Open in trunc mode to clear the file
        openLogFile(filename, std::ios::trunc);
    }

    ~FileLogger() {
        if (logFile_.is_open()) {
            logFile_.close();
        }
    }

    void setLogFile(const std::string& filename) {
        // Open in append mode for subsequent use
        openLogFile(filename, std::ios::app);
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
    void openLogFile(const std::string& filename, std::ios_base::openmode mode) {
        logFile_.open(filename, mode);
        if (!logFile_.is_open()) {
            throw std::runtime_error("Unable to open log file");
        }
    }

    std::ofstream logFile_;
    std::mutex logMutex;
};