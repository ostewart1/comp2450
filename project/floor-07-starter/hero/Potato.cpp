// COMP 2450 — Floor 7
// hero/Potato.cpp

#include "Potato.h"
#include "Queue.h"

namespace dungeon {

    std::string hotPotato(const std::vector<std::string>& names,
        std::size_t k) {
        if (names.empty() || k == 0) {
            return "";
        }

        Queue<std::string> q;

        // Add all players to the queue.
        for (std::size_t i = 0; i < names.size(); ++i) {
            q.enqueue(names[i]);
        }

        // Eliminate players until only one remains.
        while (q.size() > 1) {
            // Pass the potato k - 1 times.
            for (std::size_t i = 0; i < k - 1; ++i) {
                std::string current = q.front();
                q.dequeue();
                q.enqueue(current);
            }

            // Eliminate the player holding the potato.
            q.dequeue();
        }

        return q.front();
    }

} // namespace dungeon