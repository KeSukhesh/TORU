#pragma once
#include <atomic>
#include <thread>
#include <functional>

class BackgroundService {
public:
    BackgroundService() : stopRequested(false) {}
    virtual ~BackgroundService() {
        if (serviceThread.joinable()) {
            serviceThread.join();
        }
    }

    void start() {
        serviceThread = std::thread(&BackgroundService::executeAsync, this);
    }

    void stop() {
        stopRequested.store(true);
        if (serviceThread.joinable()) {
            serviceThread.join();
        }
        onStopped();
    }

protected:
    std::atomic<bool> stopRequested;

    virtual void executeAsync() = 0;

private:
    std::thread serviceThread;

    virtual void onStopped() = 0;
};