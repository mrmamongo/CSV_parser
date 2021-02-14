//
// Created by lamp on 06.02.2021.
//

#ifndef PRODUCER_CONSUMER_SYNC_QUEUE_HPP
#define PRODUCER_CONSUMER_SYNC_QUEUE_HPP

#include <queue>
#include <mutex>

template <typename T>
class sync_queue {
private:
    std::queue<T> _queue;
    std::mutex mutex;
public:
    sync_queue(const sync_queue&) = delete;
    sync_queue operator=(const sync_queue&) = delete;
    sync_queue() = default;

    T pop() {
        std::unique_lock<std::mutex> lock (mutex);
        T value = _queue.front();
        _queue.pop();
        return value;
    }
    T front() {
        std::unique_lock<std::mutex> lock (mutex);
        return _queue.front();
    }
    bool empty() {
        std::unique_lock<std::mutex> lock (mutex);
        return _queue.empty();
    }
    void push(const T& value) {
        std::unique_lock<std::mutex> lock(mutex);
        _queue.push(value);
    }
    size_t size(){
        std::unique_lock<std::mutex> lock(mutex);
        return _queue.size();
    }
};


#endif //PRODUCER_CONSUMER_SYNC_QUEUE_HPP
