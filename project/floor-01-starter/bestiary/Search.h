// COMP 2450 — Floor 1 starter
// bestiary/Search.h — interface only. Provided by the framework.
//
// You implement Search.cpp this week. The rest of the game calls only
// through these four functions; if your code is correct, the `search`
// command works.
#pragma once
#include <string>
#include <vector>
#include "Monster.h"

// Linear or binary search to find it by name? Justify, and give the Big-O for each: 
// I would use linear search because you're searching by value, not by name
// Big-O: O(n) for linear and O(log n) for binary if it was sorted by name, but you can't use it because it's not sorted by name...
namespace dungeon {

// Linear scan over the bestiary.
//   Returns: pointer into the vector at the matching Monster, or nullptr.
//   Pre:     none — works on any order.
//   Big-O:   O(n) worst case.
const Monster* linearSearch(const std::vector<Monster>& bestiary,
                            const std::string&         name);

// Iterative binary search over the bestiary by name.
//   Returns: pointer into the vector at the matching Monster, or nullptr.
//   Pre:     bestiary MUST be sorted ascending by name. If it isn't, you
//            will meet the Unsorted Lich (silent wrong answers).
//   Big-O:   O(log n) worst case.
const Monster* binarySearch(const std::vector<Monster>& bestiary,
                            const std::string&         name);

// Recursive binary search over the bestiary by name.
//   Returns: pointer into the vector at the matching Monster, or nullptr.
//   Pre:     bestiary MUST be sorted ascending by name (same as above).
//   Big-O:   O(log n) worst case.
//   Use a static helper inside Search.cpp that takes (low, high) — your
//   public function should keep this same signature.
const Monster* binarySearchRecursive(const std::vector<Monster>& bestiary,
                                     const std::string&         name);

// The function the rest of the game calls when it needs to look up a monster.
// You decide which of the three searches above to delegate to.
// Defend your choice in your commit message.
const Monster* findMonster(const std::vector<Monster>& bestiary,
                           const std::string&         name);

}
