// COMP 2450 — Warden of the Foundations (Midterm 1)
// battle/Battle.cpp — YOU build the body.
//
// =====================================================================
// REQUIRED MECHANICS
// =====================================================================
// Re-read the public midterm page if anything below is unclear.
//
// MENU (at minimum, four options):
//   1. Attack          — damage the warden; warden retaliates that turn
//   2. Use item        — pick from inventory; effect; turn ends
//   3. Inspect Warden  — print warden's state; FREE action — turn does
//                        NOT end
//   4. Flee            — leave; gate stays closed
//
// END:
//   Victory  when wardenHP <= 0
//   Defeat   when playerHP <= 0
//   Fled     when the player chose Flee
//
// =====================================================================
// FLOOR-TIED REQUIREMENTS — ALL FOUR MUST APPEAR IN YOUR CODE
// =====================================================================
//
//   F0 (ADT)         — the available actions on a turn must live in a
//                      container of your choice. ABOVE the declaration,
//                      in a comment, name the ADT and defend it in one
//                      sentence (the same kind of defence Trial I Q1
//                      practiced — but this is a different collection
//                      than Q1's items menu; the right ADT may differ).
//
//   F1 (search)      — the Use-item branch MUST call findByName<Item>
//                      against hero.inventory to look up the item the
//                      player typed.
//
//   F2 (sort)        — when the items menu is displayed, sort the
//                      inventory at display time with a comparator
//                      (std::sort or your Floor 2 sortInventory). Pick
//                      a criterion (value — the healing-power stand-in
//                      — weight, or name) and document it in a comment.
//
//   F3 (templates +  — invalid menu input must `throw BattleException`
//      exceptions)     (ready skeleton in Battle.h) — or BagException
//                      where a genuinely bad index is the fault —
//                      caught INSIDE the battle loop so the player gets
//                      another prompt — not a crash, not an exit.
//
// =====================================================================
// WHAT THE GRADER WILL DO
// =====================================================================
//   1. cmake --build the project. If it does not compile, the Warden
//      has won by default.
//   2. Type `battle warden`, play through to BOTH a victory and a
//      defeat (or attempt to — items + RNG permitting).
//   3. Type a deliberately invalid menu choice (e.g., "9" for a
//      4-option menu). The game must NOT crash; it must re-prompt.
//   4. Open this file and find each of the four Floor ties. They must
//      be REAL — i.e., the menu actually runs through your container,
//      Use-item actually goes through findByName, the items menu is
//      actually sorted, the throw actually fires on bad input.

// Battle.h contains the declarations associated with this implementation,
// including Hero, BattleOutcome, BattleException, and runWardenBattle().
#include "Battle.h"

// Standard-library headers used in this file.
#include <algorithm>  // std::min and std::max
#include <iostream>   // std::cout and std::cin
#include <string>     // std::string, std::getline, std::stoi

// Project-specific headers from neighboring directories.
#include "../bestiary/Search.h"     // findByName<T>()
#include "../hero/Bag.h"            // Bag<T>
#include "../hero/BagException.h"   // BagException
#include "../hero/Item.h"           // Item
#include "../hero/Sort.h"           // sortInventory()

namespace dungeon {


    namespace {
        // constexpr means these values are compile-time constants
        // k prefix --> means constant
        constexpr int kPlayerStartHP = 30;
        constexpr int kWardenStartHP = 50;
        constexpr int kPlayerAttackDmg = 6;
        constexpr int kWardenAttackDmg = 4;

        // enum creates a set of named choices
        // enum class, keeps our names scoped
        enum class MenuAction {
            Attack,
            UseItem,
            Inspect,
            Flee
        };
        // {1, "Attack", MenuAction::Attack}

        struct MenuOption {
            int number; // number typed by the player
            std::string label; // text displayed by the menu
            MenuAction action; // action performed by our program
        };

        void printMenu(
            Bag<MenuOption>& menu,
            int playerHP,
            int wardenHP
        ) {
            std::cout << "\n -- Your turn -- your hp" << playerHP
                << "     Warden hp " << wardenHP << "\n";

            for (std::size_t i = 0; i < menu.size(); ++i) {
                // bag overload our operator[], allow menu[i]
                // to retrieve our menuoption at index i
                std::cout << "     "
                    << menu[i].number
                    << ". "
                    << menu[i].label
                    << "\n";
            }
            std::cout << " > ";
        }
        // read the user's input and convert that into a MenuAction
        MenuAction readMenuChoice(const Bag<MenuOption>& menu) {
            std::string line;
            // getline will get the entire line up to the enter key
            // if getline fails, standard input may have been closed
            // if problem... flee!
            if (!std::getline(std::cin, line)) {
                return MenuAction::Flee;
            }

            int n = -1;

            try {
                // "2" --> 2
                // if the string can't be converted...
                // stoi throw an excp
                n = std::stoi(line);
            }
            catch (...) {
                // catch any exception type
                // we will replace our low-level stoi
                // exception with a domain-specific
                // BattleException
                throw BattleException(
                    "'" + line + "' is not a menu number (enter 1 to "
                    + std::to_string(menu.size()) + ")"
                );
            }
            // search our menu for an option whose displayed number
            // matches the number entered by the player
            for (std::size_t i = 0; i < menu.size(); ++i) {
                if (menu[i].number == n) {
                    // return associated matching option
                    return menu[i].action;
                }
            }

            // the input was numeric but it did not match a menu option
            throw BagException(
                static_cast<std::size_t>(n),
                menu.size()
            );
        }

        // handle the player's "use item" action
        // Hero& will give the function access to the
        // original hero object instead of a copy
        void useItem(Hero& hero, int& playerHP) {
            // handle empty inventory case
            if (hero.inventory.empty()) {
                std::cout << "Your satchel is empty.\n";
                return;
            }
            // sort hero's inventory from highest to lowest
            sortInventory(hero, "value desc");

            std::cout << "Choose an item by name:\n";
            printInventory(hero);
            std::cout << " > ";

            std::string name;

            // || short-circuit
            // 1. try to read the line
            // 2. if that succeeds, then i will check whether the
            // line is empty
            // if either condition is true, the player does nothing
            if (!std::getline(std::cin, name) || name.empty()) {
                std::cout << "you hesitated.\n";
                return;
            }

            // findByName<Item> <-- function-template specialization
            // <Item> will tell the compiler this search will operate
            // on Item objects
            const Item* it = findByName<Item>(hero.inventory, name);

            // a nullptr converts to false
            if (!it) {
                throw BattleException(
                    "no item found '" + name + "' in your satchel"
                );
            }

            // if you say Potion, Healing potion
            if (it->name.find("otion") != std::string::npos) {
                // heal 12 hp, but we also don't need our healing
                // to exceed our max health
                playerHP = std::min(
                    playerHP + 12,
                    kPlayerStartHP
                );
                std::cout << " You drink "
                    << it->name
                    << ". HP -> "
                    << playerHP
                    << ".\n";
            }
            else {
                std::cout << " You ready "
                    << it->name
                    << " - but it is not a consumable.\n";
            }
        }
    }


    BattleOutcome runWardenBattle(Hero& hero) {
        // create two variables for the player and
        // warden health; represent the state
        int playerHP = kPlayerStartHP;
        int wardenHP = kWardenStartHP;

        // create a bag specialized to store
        // menuoption objects
        Bag<MenuOption> menu;
        menu.push_back({ 1, "Attack", MenuAction::Attack });
        menu.push_back({ 2, "Use item", MenuAction::UseItem });
        menu.push_back({ 3, "Inspect warden", MenuAction::Inspect });
        menu.push_back({ 4, "Flee", MenuAction::Flee });

        // continue the battle ONLY while both participants
        // are alive
        while (playerHP > 0 && wardenHP > 0) {
            try {
                printMenu(menu, playerHP, wardenHP);

                // readMenuChoice returns a MenuAction
                // switch statement to select the
                // corresp block of code
                switch (readMenuChoice(menu)) {
                case MenuAction::Attack: {
                    // subtract player's damage from warden's hp
                    wardenHP -= kPlayerAttackDmg;
                    // hp may internally fall below 0.
                    std::cout << "you strike for "
                        << kPlayerAttackDmg
                        << ". Warden HP -> "
                        << std::max(wardenHP, 0)
                        << ".\n";

                    // is warden dead?
                    if (wardenHP > 0) {
                        playerHP -= kWardenAttackDmg;

                        std::cout << "The warden retaliates for "
                            << kWardenAttackDmg
                            << ". Your HP -> "
                            << std::max(playerHP, 0)
                            << ".\n";
                    }

                    // break to exit the switch case, not the while loop
                    break;
                }
                case MenuAction::UseItem: {
                    // lets use an item, yeah?
                    useItem(hero, playerHP);
                    // using an item does consume our turn
                    // the warden will attack, assuming we are both
                    // alive
                    if (wardenHP > 0 && playerHP > 0) {
                        playerHP -= kWardenAttackDmg;

                        std::cout << "The warden strikes while you fumble. Your HP -> "
                            << std::max(playerHP, 0)
                            << ".\n";
                    }
                    break;
                }
                case MenuAction::Inspect: {
                    std::cout << "Warden of the Foundations. HP -> "
                        << wardenHP
                        << " / "
                        << kWardenStartHP
                        << ". No visible weakness (free action).\n";

                    break;
                }
                case MenuAction::Flee: {
                    // return to immediately exit the function
                    return BattleOutcome::Fled;
                }
                } // end switch
            } // end of try
            catch (const std::exception& e) {
                // battle exception & bag exception will inherit
                std::cout << e.what()
                    << " - try again.\n";
            }
        }
        // condition ? value_if_true : value_if_false
        return wardenHP <= 0
            ? BattleOutcome::Victory
            : BattleOutcome::Defeat;
    }

}  // End namespace dungeon
