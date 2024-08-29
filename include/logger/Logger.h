#pragma once

#include <string>
#include <iostream>
#include <exception>
#include <fstream>
#include <sstream>
#include <mutex>
#include <memory>
#include <chrono>
#include <ctime>
#include <map>


#include "LogLevel.h"

class Logger
{
public:
    virtual ~Logger() = default;

    void setLogLevel(LogLevel level) {
        logLevel_ = level;
    }

    LogLevel getLogLevel() {
        return logLevel_;
    }

    void logInfo(const std::string& message) {
        log(LogLevel::INFO, message);
    }

    void logWarning(const std::string& message) {
        log(LogLevel::WARNING, message);
    }

    void logError(const std::string& message) {
        log(LogLevel::ERROR, message);
    }

    void logDebug(const std::string& message) {
        log(LogLevel::DEBUG, message);
    }

    void logInfo(const std::string& module, const std::exception& ex) {
        log(LogLevel::INFO, module);
        throw ex;
    }

    void logWarning(const std::string& module, const std::exception& ex) {
        log(LogLevel::WARNING, module);
        throw ex;
    }

    void logError(const std::string& module, const std::exception& ex) {
        log(LogLevel::ERROR, module);
        throw ex;
    }

protected:
    std::string formatMessage(LogLevel level, const std::string& message) {
        std::ostringstream oss;
        oss << "[" << getCurrentTime() << "] [" << logLevelToString(level) << "] " << message << std::endl;
        return oss.str();
    }

private:
    virtual void log(LogLevel level, const std::string& message) = 0;
    LogLevel logLevel_ = LogLevel::INFO;

    std::string getCurrentTime() {
        auto now = std::chrono::system_clock::now();
        std::time_t now_time = std::chrono::system_clock::to_time_t(now);
        char buffer[20];
        std::strftime(buffer, sizeof(buffer), "%Y-%m-%d %H:%M:%S", std::localtime(&now_time));
        return std::string(buffer);
    }

    std::string logLevelToString(LogLevel level) {
        static std::map<LogLevel, std::string> logLevelMap = {
            { LogLevel::INFO, "INFO" },
            { LogLevel::WARNING, "WARNING" },
            { LogLevel::ERROR, "ERROR" },
            { LogLevel::DEBUG, "DEBUG" }
        };
        return logLevelMap[level];
    }
};
