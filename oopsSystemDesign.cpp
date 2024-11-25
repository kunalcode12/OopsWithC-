#include <iostream>
#include <vector>
#include <memory>
#include <unordered_map>
#include <functional>
#include <stdexcept>
#include <chrono>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <future>
#include <atomic>

// Abstract base class for resource management
class Resource {
public:
    virtual ~Resource() = default;
    virtual void acquire() = 0;
    virtual void release() = 0;
    virtual bool isAvailable() const = 0;
};

// Template metaprogramming for compile-time type constraints
template <typename T>
class ResourceValidator {
public:
    static constexpr bool validate() {
        return std::is_base_of<Resource, T>::value;
    }
};

// Advanced resource allocation strategy
template <typename ResourceType>
class ResourceAllocator {
private:
    std::vector<std::unique_ptr<ResourceType>> resources;
    std::mutex mutex;
    std::condition_variable cv;

public:
    void addResource(std::unique_ptr<ResourceType> resource) {
        std::lock_guard<std::mutex> lock(mutex);
        resources.push_back(std::move(resource));
    }

    std::unique_ptr<ResourceType> allocateResource(std::chrono::milliseconds timeout) {
        std::unique_lock<std::mutex> lock(mutex);
        auto start = std::chrono::steady_clock::now();

        cv.wait_for(lock, timeout, [this]() {
            return std::any_of(resources.begin(), resources.end(), 
                [](const auto& res) { return res->isAvailable(); });
        });

        auto resourceIt = std::find_if(resources.begin(), resources.end(), 
            [](const auto& res) { return res->isAvailable(); });

        if (resourceIt == resources.end()) {
            throw std::runtime_error("No available resources");
        }

        (*resourceIt)->acquire();
        return std::move(*resourceIt);
    }
};

// Concrete implementation of a network connection resource
class NetworkConnection : public Resource {
private:
    std::atomic<bool> available;
    std::string connectionString;

public:
    NetworkConnection(const std::string& connStr) 
        : available(true), connectionString(connStr) {}

    void acquire() override {
        bool expected = true;
        if (!available.compare_exchange_strong(expected, false)) {
            throw std::runtime_error("Resource already in use");
        }
    }

    void release() override {
        available.store(true);
    }

    bool isAvailable() const override {
        return available.load();
    }

    std::string getConnectionString() const {
        return connectionString;
    }
};

// Advanced task scheduler with dependency management
class TaskScheduler {
private:
    std::vector<std::function<void()>> tasks;
    std::vector<std::future<void>> futures;

public:
    void addTask(std::function<void()> task) {
        tasks.push_back(task);
    }

    void executeConcurrently() {
        for (auto& task : tasks) {
            futures.push_back(std::async(std::launch::async, task));
        }

        for (auto& future : futures) {
            future.wait();
        }
    }
};

int main() {
    try {
        
        ResourceAllocator<NetworkConnection> allocator;

        // Add network connection resources
        allocator.addResource(std::make_unique<NetworkConnection>("192.168.1.100:8080"));
        allocator.addResource(std::make_unique<NetworkConnection>("192.168.1.101:8081"));

       
        TaskScheduler scheduler;

      
        scheduler.addTask([&]() {
            try {
                auto connection = allocator.allocateResource(std::chrono::milliseconds(1000));
                std::cout << "Task 1: Using connection " 
                          << connection->getConnectionString() << std::endl;
                std::this_thread::sleep_for(std::chrono::milliseconds(500));
                connection->release();
            } catch (const std::exception& e) {
                std::cerr << "Task 1 error: " << e.what() << std::endl;
            }
        });

        scheduler.addTask([&]() {
            try {
                auto connection = allocator.allocateResource(std::chrono::milliseconds(1000));
                std::cout << "Task 2: Using connection " 
                          << connection->getConnectionString() << std::endl;
                std::this_thread::sleep_for(std::chrono::milliseconds(500));
                connection->release();
            } catch (const std::exception& e) {
                std::cerr << "Task 2 error: " << e.what() << std::endl;
            }
        });

        
        scheduler.executeConcurrently();
    }
    catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    }

    return 0;
}