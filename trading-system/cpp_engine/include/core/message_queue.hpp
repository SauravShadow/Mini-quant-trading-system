#pragma once
#include <queue>
#include <mutex>
#include <condition_variable>

template<typename T>
class MessageQueue {
    std::queue<T> q;
    std::mutex m;
    std::condition_variable cv;
public:
    void push(const T& val) {
        {
            std::lock_guard<std::mutex> lock(m);
            q.push(val);
        }
        cv.notify_one();
    }
    
    T pop() {
        std::unique_lock<std::mutex> lock(m);
        cv.wait(lock, [&]() { return !q.empty(); });
        T val = q.front();
        q.pop();
        return val;
    }
};