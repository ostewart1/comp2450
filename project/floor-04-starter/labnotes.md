1.) 
=== THE CHAIN VAULT ===

What is your name, adventurer? olive

Welcome, olive.
The Warden's gate stands open behind you. Mavren waits at the chain.
Type `log` at any time to see what the chain remembers.

(commands:
   search <name>                 ΓÇö look up by name in bestiary or inventory
   list                          ΓÇö list the bestiary
   inventory                     ΓÇö list your inventory
   inspect <n>                   ΓÇö show the nth item in your inventory
   sort inventory by <key> [asc|desc]
                                 ΓÇö key is name, weight, or value
   log [n]                       ΓÇö show the last n events, newest first
   selftest chain                ΓÇö run the Chain<T> leak-check harness
   benchmark [N]                 ΓÇö race the search algorithms
   benchmark sort [N] [--sorted] [--bad-pivot]
                                 ΓÇö race the sorting algorithms
   benchmark log [N]             ΓÇö race Chain::push_front vs vector insert(begin)
   battle warden                 ΓÇö face the Warden of the Foundations
   help                          ΓÇö this screen
   quit                          ΓÇö leave the dungeon)

> search Goblin
Goblin   HP 8   ATK 2   weakness: fire
> inventory
   1.  Rusty sword       (wt 4.0, val 5)
   2.  Healing potion    (wt 0.5, val 12)
   3.  Iron key          (wt 0.1, val 0)
   4.  Loaf of bread     (wt 0.1, val 1)
   5.  Cloak of shadows  (wt 1.5, val 80)
> sort inventory by value desc
   1.  Cloak of shadows  (wt 1.5, val 80)
   2.  Healing potion    (wt 0.5, val 12)
   3.  Rusty sword       (wt 4.0, val 5)
   4.  Loaf of bread     (wt 0.1, val 1)
   5.  Iron key          (wt 0.1, val 0)
> inspect 99
No such item. (index 98 out of bounds for size 5)
> log 8
  1.  error: index 98 out of bounds for size 5
Newest first; chain length 5
  2.  sort inventory by value desc
Newest first; chain length 5
  3.  inventory ΓÇö listed 5 items
Newest first; chain length 5
  4.  search Goblin ΓÇö found in bestiary
Newest first; chain length 5
  5.  began session as "olive"
Newest first; chain length 5
> benchmark log 100000
> selftest chain
  Chain<int> allocations:  1000   deallocations:  1000   leaked:     0   OK
> quit
2.)

=== THE CHAIN VAULT ===

What is your name, adventurer? o

Welcome, o.
The Warden's gate stands open behind you. Mavren waits at the chain.
Type `log` at any time to see what the chain remembers.

(commands:
   search <name>                 ΓÇö look up by name in bestiary or inventory
   list                          ΓÇö list the bestiary
   inventory                     ΓÇö list your inventory
   inspect <n>                   ΓÇö show the nth item in your inventory
   sort inventory by <key> [asc|desc]
                                 ΓÇö key is name, weight, or value
   log [n]                       ΓÇö show the last n events, newest first
   selftest chain                ΓÇö run the Chain<T> leak-check harness
   benchmark [N]                 ΓÇö race the search algorithms
   benchmark sort [N] [--sorted] [--bad-pivot]
                                 ΓÇö race the sorting algorithms
   benchmark log [N]             ΓÇö race Chain::push_front vs vector insert(begin)
   battle warden                 ΓÇö face the Warden of the Foundations
   help                          ΓÇö this screen
   quit                          ΓÇö leave the dungeon)

> selftest chain
  Chain<int> allocations:  1000   deallocations:     0   leaked:  1000   LEAK ΓÇö implement ~Chain() / clear()
>

=== THE CHAIN VAULT ===

What is your name, adventurer? o

Welcome, o.
The Warden's gate stands open behind you. Mavren waits at the chain.
Type `log` at any time to see what the chain remembers.

(commands:
   search <name>                 ΓÇö look up by name in bestiary or inventory
   list                          ΓÇö list the bestiary
   inventory                     ΓÇö list your inventory
   inspect <n>                   ΓÇö show the nth item in your inventory
   sort inventory by <key> [asc|desc]
                                 ΓÇö key is name, weight, or value
   log [n]                       ΓÇö show the last n events, newest first
   selftest chain                ΓÇö run the Chain<T> leak-check harness
   benchmark [N]                 ΓÇö race the search algorithms
   benchmark sort [N] [--sorted] [--bad-pivot]
                                 ΓÇö race the sorting algorithms
   benchmark log [N]             ΓÇö race Chain::push_front vs vector insert(begin)
   battle warden                 ΓÇö face the Warden of the Foundations
   help                          ΓÇö this screen
   quit                          ΓÇö leave the dungeon)

> selftest chain
  Chain<int> allocations:  1000   deallocations:     0   leaked:  1000   LEAK ΓÇö implement ~Chain() / clear()
>
1,000 leaked nodes

3.) function "dungeon::Chain<T>::Chain(const dungeon::Chain<T> &) [with T=int]" (declared at line 122 of "C:\Users\Admin\Documents\GitHub\comp2450\project\floor-04-starter\hero\Chain.h") cannot be referenced -- it is a deleted function
'dungeon::Chain<int>::Chain(const dungeon::Chain<int> &)': attempting to reference a deleted function
Line 122: The compiler refuses to copy the chain because both objects would point to the same nodes,
causing a double deletion.
4.)  I don't think the benchmark was loading because the number was so high
5.) Mavren uses a Bag<Monster> for the bestiary because she needs to store and search through monsters, making a vector-based
container a good choice. She uses a Chain<std::string> for the event log because new events are constantly added to the front, and a linked list 
can do this without moving all the elements. If she swapped the containers, adding events to the front of a vector would be slower because all the elements would have to shift in memory. 
Using a chain for the bestiary would also make searching and accessing monsters less convenient because each element must be reached by following pointers.

