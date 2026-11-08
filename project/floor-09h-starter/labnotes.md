1.) 
=== THE HALVING HALL ===

What is your name, adventurer? o

Welcome, o.
Scrivener McCown stands before a tall, narrow chart where every name
forks just twice ΓÇö smaller to the left, larger to the right. "On the
last floor my tree remembered where things belonged," he says. "This
one remembers where they ARE. Ask it for a beast by name; watch it
throw away half the chart with every question."

(commands:
   search <name>                 ΓÇö look up by name in bestiary, inventory, OR event log
   list                          ΓÇö list the bestiary
   inventory                     ΓÇö list your inventory
   inspect <n>                   ΓÇö show the nth item in your inventory
   take <name>                   ΓÇö add a small item by that name to your inventory
   sort inventory by <key> [asc|desc]
                                 ΓÇö key is name, weight, or value
   undo                          ΓÇö reverse the most recent mutating command
   lint <text>                   ΓÇö check that brackets/parens/braces in <text> balance
   provoke <name>                ΓÇö enqueue an enemy action onto the line
   simulate                      ΓÇö drain the enemy line in FIFO order
   potato <name>... <k>          ΓÇö classical hot-potato survivor (FIFO elimination)
   taxonomy                      ΓÇö print McCown's classification tree as an outline
   taxonomy --dfs                ΓÇö list every entry depth-first (pre-order)
   taxonomy --bfs                ΓÇö list every entry breadth-first (level-order)
   lineage <name>                ΓÇö show the root-to-creature classification path
   catalogue                     ΓÇö list the bestiary in name order (BST in-order)
   recall <name>                 ΓÇö look up a monster fast in the BST
   forget <name>                 ΓÇö remove a monster from the BST
   balance                       ΓÇö is McCown's catalogue tree balanced? (height + factor)
   log [n]                       ΓÇö show the last n events, newest first
   log --oldest [n]              ΓÇö show the first n events, oldest first
   clone hero                    ΓÇö deep-copy the hero, print both logs, let the copy die
   selftest chain                ΓÇö Chain<T> leak + deep-copy harness
   selftest iterator             ΓÇö Chain<T>::iterator harness
   selftest stack                ΓÇö Stack<T> push/pop/top/LIFO harness
   selftest queue                ΓÇö Queue<T> enqueue/dequeue/front/FIFO harness
   selftest tree                 ΓÇö Tree<T> addChild/size/height/traversal/lineage harness
   selftest bst                  ΓÇö BST<T> insert/find/inorder/remove harness
   selftest balance              ΓÇö BST<T> balance factor / rotation harness
   benchmark [N]                 ΓÇö race the search algorithms
   benchmark sort [N] [--sorted] [--bad-pivot]
                                 ΓÇö race the sorting algorithms
   benchmark log [N]             ΓÇö race Chain::push_front vs vector insert(begin)
   benchmark bst [N]             ΓÇö race linear scan vs BST lookup over the bestiary
   benchmark balance [N]         ΓÇö same sorted input: plain BST (stick) vs std::set
   battle warden                 ΓÇö face the Warden of the Foundations
   help                          ΓÇö this screen
   quit                          ΓÇö leave the dungeon)

> selftest balance
  balanceFactor: empty==0, bushy==0, left-leaning==1: OK
  isBalanced: bushy {5,3,8,2,4,7,9} balanced (true): OK
  degenerate: sorted stick {1..6} is NOT balanced (height 5): OK
  rotate: rotateRootLeft on {1,2,3} -> root 2, height 1, order kept: OK
  balanceRoot: right- and left-heavy sticks both rebalance (order kept): FAIL ΓÇö rebalanceAt must rotate left when bf<-1 and right when bf>1
  (see FAILs above)
> balance
  McCown's catalogue: 15 names, height 6, root balance factor -3 ΓÇö NOT balanced (lopsided).
> benchmark balance

-- Same sorted input: your plain BST vs std::set (1000 iterations per cell) --
  N=     10  plain BST: height=     9  find=    0.688 us    std::set: find=   0.570 us
  N=    100  plain BST: height=    99  find=    6.800 us    std::set: find=   0.716 us
  N=   1000  plain BST: height=   999  find=   49.920 us    std::set: find=   0.949 us

Same data, same order. Inserted in sorted order, your plain BST
degenerated into a stick of height N-1 ΓÇö lookup is back to O(n).
std::set saw the identical input and stayed shallow: it is a
balanced tree (a red-black tree) that rotates on every insert to
hold its height near log2 N. You do not hand-write that balancing ΓÇö
you reach for std::set / std::map. That is the next floor, the
Hall of Names.

> quit
McCown notes your departure. "You leave in order."

C:\Users\Admin\Documents\GitHub\comp2450\project\floor-09h-starter\out\build\x64-Debug\the_descent.exe (process 6804) exited with code 0 (0x0).
To automatically close the console when debugging stops, enable Tools->Options->Debugging->Automatically close the console when debugging stops.
Press any key to close this window . . .

2.) The values and insertion rule are the same, but the balanced tree distributes the nodes across
both sides instead of creating a stick, so find has to examine fewer nodes to find a value
3.) In-order traversal remains unchanged because the values are still arranged from smallest to largest, following the BST ordering rule
4.) A real AVL tree uses a double rotation (right rotation at 3, followed by a left rotation at 1) to correctly balance this situation
5.) -- Same sorted input: your plain BST vs std::set (1000 iterations per cell) --
  N=     10  plain BST: height=     9  find=    0.771 us    std::set: find=   2.142 us
  N=    100  plain BST: height=    99  find=    5.080 us    std::set: find=   0.695 us
  N=   1000  plain BST: height=   999  find=   57.842 us    std::set: find=   1.003 us

  The plain BST and std::set received the same sorted input, but the plain BST became a stick because it does not automatically balance its nodes. 
  The std::set performs balancing operations during insertion, keeping the tree shorter and making searches more efficient

  6.) I think stopping one step short of building a self-balancing tree was the right decision because it allowed me to understand how a BST works before 
  adding rotations and balancing. I would write my own balancing system if I needed to learn how it works or had a special requirement that 
  an existing container could not meet, but normally I would use std::set or std::map because they already handle balancing very well. After building five 
  pointer structures, using one that someone else created gives me the advantage of reliable, tested code and saves time. 
  However, I give up some control over how the structure works internally and have to learn how to use its interface instead.
