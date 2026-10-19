// COMP 2450 — Floor 7
// hero/Queue.h — FIFO queue template

#pragma once

#include <cstddef>

#include "Chain.h"

namespace dungeon {

    template <typename T>
    class Queue {
    public:
        using value_type = T;

        Queue() = default;
        ~Queue() = default;
        Queue(const Queue& other) = default;
        Queue& operator=(const Queue& other) = default;

        // Add an item to the back of the queue. O(1).
        void enqueue(const T& value) {
            chain_.push_back(value);
        }

        // Remove the oldest item. O(1).
        // Does nothing if the queue is empty.
        void dequeue() {
            chain_.pop_front();
        }

        // Return the oldest item.
        // Requires a non-empty queue.
        T& front() {
            return chain_.head()->data;
        }

        const T& front() const {
            return chain_.head()->data;
        }

        // Return the number of items in the queue.
        std::size_t size() const {
            return chain_.size();
        }

        // Return true if the queue is empty.
        bool empty() const {
            return size() == 0;
        }

    private:
        Chain<T> chain_;
    };

} // namespace dungeon