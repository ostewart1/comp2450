1.) 
=== THE HALL OF LINEAGES ===

What is your name, adventurer? olive

Welcome, olive.
> lineage Beasts
  Creatures of the Hold > Beasts
> lineage Skeleton
  Creatures of the Hold > Undead > Corporeal > Skeleton
> lineage Wisp
  Creatures of the Hold > Undead > Incorporeal > Wisp
> lineage Goblin
  'Goblin' is not in McCown's catalogue.

2.) countFrom: static std::size_t countFrom(const Node* n) {
## BASE CASE
    if (n == nullptr) return 0;

    ##  ACT ON THIS NODE
    std::size_t total = 1;
    ## RECURSION INTO CHILDREN
    for (std::size_t i = 0; i < n->children.size(); ++i) {
        total += countFrom(n->children[i]);
    }
    return total;
}
heightFrom: static std::size_t heightFrom(const Node* n) {
## BASE CASE
    if (n == nullptr || n->children.size() == 0) return 0;
    ## ACT ON THIS NODE
    std::size_t best = 0;
    ## RECURSION INTO CHILDREN
    for (std::size_t i = 0; i < n->children.size(); ++i) {
        best = std::max(best, heightFrom(n->children[i]));
    }
    return 1 + best;
}
preOrderInto:
static void preOrderInto(const Node* n, std::vector<T>& out) {
## BASE CASE
    if (n == nullptr) return;
    ## ACT ON THIS NODE
    out.push_back(n->data);
    ## RECURSION INTO CHILDREN
    for (std::size_t i = 0; i < n->children.size(); ++i) {
        preOrderInto(n->children[i], out);
    }
}
All 3 functions use recursion to visit the nodes and their children, but they do different thing with the 
information. countFrom counts the total nodes, heightFrom finds the longest path from the node
to a leaf, and preOrderInto adds each node to a list in the order it is visited.

3.) Skeleton and Stone Sentinel moved the most positions (10 places) because DFS explored
the branches deeply while BFS explored level by level.
4.) I classified Goblin under Beasts → Mammals because goblins are living creatures and share more similarities with beasts than undead or constructs
The terminal keeps saying Goblin isn't in the catalogue
5.) > taxonomy --dfs
  depth-first (pre-order):
    Skeleton
    Necrothrall
    Lich
    Corporeal
    Wraith
    Wisp
    Incorporeal
    Undead
    Shadow Hound
    Ironclaw Bear
    Cinder Bat
    Goblin
    Mammals
    Cave Troll
    Frostmaw
    Giants
    Beasts
    Bone Spider
    Ratking
    Marsh Lurker
    Vermin
    Stone Sentinel
    Constructs
    Creatures of the Hold
Post-order visits all of a node's children before visiting the node itself, which is why the parent appears after its descendants
6.) > lineage Stone Sentinel
Nodes checked: 24
Creatures of the Hold > Constructs > Stone Sentinel
A general tree does not have an ordering rule, so it may need to search through every node to find what it is looking for. 
A binary search tree uses an ordering rule that allows it to skip entire branches instead of checking every node
7.) The newest thing about the tree was learning how to work with nodes that can have multiple children instead of just one node.
Unlike the Chain, Stack, and Queue, a tree branches out, so I had to think about how to move through different levels
and use recursion. Some lessons felt the same as before, especially the pointers. Overall, the tree was a new way of organizing data,
but it still used many of the same pointer concepts. 
