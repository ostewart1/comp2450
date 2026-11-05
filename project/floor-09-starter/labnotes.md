2.) Start at 8: go left because 7 is smaller.
At 3: go right because 7 is larger.
At 6: go right because 7 is larger.
At 7: found the value.
Nodes looked at: 4
Nodes never looked at: 5
The search looked at four nodes, which is one more than the tree's height of 3 edges.
3.) In-order traversal produces sorted numbers because it goes to the left subtree, the current node, and then the right subtree. 
The BST invariant guarantees that every value in the left subtree is smaller than the current node, while every value in the right subtree is larger.
4.) Node 13 moved up to replace the root, 8. It was the in-order successor because it was the smallest value in the right subtree. 
This keeps the BST in order because 13 is larger than everything on its left and smaller than everything else on its right
5.) 
-- Bestiary: linear scan vs BST lookup (1000 iterations per cell) --
  N=    100  query=last    linear=     3.618 us  BST=     0.240 us  (tree height 13)
  N=    100  query=absent  linear=     1.153 us  BST=     0.198 us  (tree height 13)
  N=   1000  query=last    linear=    18.154 us  BST=     0.535 us  (tree height 22)
  N=   1000  query=absent  linear=    11.107 us  BST=     0.503 us  (tree height 22)
  N=  10000  query=last    linear=   162.989 us  BST=     0.977 us  (tree height 30)
  N=  10000  query=absent  linear=   116.223 us  BST=     0.577 us  (tree height 30)
  N= 100000  query=last    linear=  1721.080 us  BST=     0.487 us  (tree height 40)
  N= 100000  query=absent  linear=  1332.692 us  BST=     0.451 us  (tree height 40)
If I had inserted the monsters in alphabetical order instead of shuffled, the tree would have degenerated into a linear chain with a height of 
N - 1. Recall's speed would have been linear instead of logarithmic. 
6.) Building Chain, Stack, Queue, Tree, and BST marks a big shift: the BST is the first container whose speed depends entirely on its shape. Its strict ordering rule gives fast, 
logarithmic lookups that a general tree can't match, but it comes at the cost of complex maintenance. ESPECIALLY during removals and the risk of worst-case linear degeneracy. Writing my own destructor 
this week also felt very different from reading about it on Floor 8. While reading offered a calm, abstract view, writing it meant dealing with the risks where a single missed pointer leads directly crashes.