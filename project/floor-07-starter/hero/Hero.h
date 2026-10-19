// COMP 2450 — Floor 7
// hero/Hero.h

#pragma once

#include <cstddef>
#include <iomanip>
#include <iostream>
#include <string>

#include "Bag.h"
#include "Chain.h"
#include "Item.h"
#include "Queue.h"
#include "Stack.h"
#include "UndoAction.h"

namespace dungeon {

    struct Hero {
        std::string        heroName;
        Bag<Item>          inventory;
        Chain<std::string> eventLog;
        Stack<UndoAction>  undoStack;
        Queue<std::string> enemyActionQueue;
    };

    Bag<Item> loadInventory(const std::string& path);
    void printInventory(const Hero& hero);

    template <typename It>
    void printLog(It first, It last,
        std::size_t n,
        const char* label,
        std::size_t total) {
        if (first == last) {
            std::cout
                << "  (the chain is empty — nothing to remember yet)\n";
            return;
        }

        std::size_t printed = 0;

        for (It it = first;
            it != last && (n == 0 || printed < n);
            ++it, ++printed) {
            std::cout << "  " << std::setw(2) << std::right
                << (printed + 1) << ".  " << *it << "\n";
        }

        std::cout << "  (" << label
            << "; chain length " << total << ")\n";
    }

} // namespace dungeon