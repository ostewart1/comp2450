
#pragma once

#include <cstddef>

#include "Chain.h"

namespace dungeon {

    template <typename T>
    class Stack {
    public:
        using value_type = T;
        Stack() = default;
        ~Stack() = default;
        Stack(const Stack& other) = default;

        void push(const T& value) {
            chain_.push_front(value);
        }
        void pop() {
            chain_.pop_front();
        }
        T& top() {
            return chain_.head()->data;
        }
        const T& top() const {
            // same body as the non-const version above
            return chain_.head()->data;
        }
        std::size_t size() const {
            return chain_.size();
        }
        //     return size() == 0;
        bool empty() const {
            return size() == 0;
        }

    private:
        Chain<T> chain_;
    };

}  // namespace dungeon