> selftest stack
  empty Stack<int>: size==0 && empty(): OK
  push(7): size==1 && top()==7: OK
  push 1,2,3: size==3 && top()==3 (LIFO): OK
  after pop(): size==2 && top()==2: OK
  drain to empty: size==0 && empty(): OK
  all phases OK

> lint ({a} (b) [c])
  balanced
> lint ({)}
  not balanced
> lint hello (world
  not balanced

> inventory
   1.  Rusty sword       (wt 4.0, val 5)
   2.  Healing potion    (wt 0.5, val 12)
   3.  Iron key          (wt 0.1, val 0)
   4.  Loaf of bread     (wt 0.1, val 1)
   5.  Cloak of shadows  (wt 1.5, val 80)
> take Lantern
  Taken: Lantern  (wt 0.1, val 1)
> sort inventory by weight
   1.  Iron key          (wt 0.1, val 0)
   2.  Loaf of bread     (wt 0.1, val 1)
   3.  Lantern           (wt 0.1, val 1)
   4.  Healing potion    (wt 0.5, val 12)
   5.  Cloak of shadows  (wt 1.5, val 80)
   6.  Rusty sword       (wt 4.0, val 5)
> undo
Undid: sort inventory by weight
> inventory
   1.  Rusty sword       (wt 4.0, val 5)
   2.  Healing potion    (wt 0.5, val 12)
   3.  Iron key          (wt 0.1, val 0)
   4.  Loaf of bread     (wt 0.1, val 1)
   5.  Cloak of shadows  (wt 1.5, val 80)
   6.  Lantern           (wt 0.1, val 1)
> undo
Undid: take Lantern
> inventory
   1.  Rusty sword       (wt 4.0, val 5)
   2.  Healing potion    (wt 0.5, val 12)
   3.  Iron key          (wt 0.1, val 0)
   4.  Loaf of bread     (wt 0.1, val 1)
   5.  Cloak of shadows  (wt 1.5, val 80)
> undo
Nothing to undo.
> quit
The cantor falls silent. The last echo decays. The hall is quiet.

2.) ADT describes what a type does and the rules it follows without worrying how it's implemented
A stack is an ADT because it describes how items are added and removed using LIFO (Last In, First Out).
The stack tells you what operations you can perform (push, pop, top, empty, size) and 
what the expected behavior is, but it does not specify how the stack is implemented.
	A data structure describes how data is actually stored and organized in memory.
	A chain is a data structure because it stores elements using linked nodes. In this project,
	the stack is the ADT and the Chain is the data structure that implements the stack. Having 
	Stack<T> as an adapter over Chain<T> reinforces the distinction because the Stack 
	can provide stack behavior while the Chain can be replaced with a different
	data structure without changing what the Stack does. 
3.) After running selftest stack:
	empty Stack<int>: size==0 && empty(): OK
	push(7): size==1 && top()==7: OK
	push 1,2,3: size==3 && top()==3 (LIFO): OK
	after pop(): size==2 && top()==2: OK
	drain to empty: size==0 && empty(): OK
	all phases OK
After running benchmark log 1000
N=	1000	Chain::push_front =		1.81 ms		Bag::inster(begin) =	75.39 ms
The benchmark does not change because it's measuring Chain::push_front and Bag::insert(begin) 
which are not affected by Stack. The benchmark is measuring the performance of Chain and the Bag's insert method, 
which are separate from Stack.

4.) The program printed:

about to call top() on an empty stack...

Then Visual Studio stopped the program with an exception:
read access violation.
dungeon::Stack<int>::top() returned nullptr.

Next:
about to call top() on an empty stack...
stack is empty
survived

The Stack ADT doesn't gurantee that top() is safe to call when the stack is empty, 
so caller should always check empty() before calling top().

5.) 2: recursive=0  stack=0
13: recursive=3  stack=3
55: recursive=6  stack=6
4: recursive=-1  stack=-1
99: recursive=-1  stack=-1

The stack version shows that recursion is using a stack to keep track of the ranges 
that need to be searched. The recursive version hides this stack because the programming language
handles it. 
Max number of Ranges: 1 at a time because the binary serach only continues into 1 half of the search range.

6.) I learned that different programming techniques can accomplish similar tasks while hiding different details. 
The 4 one-line methods made common operations easier to use because the implementation details were handled by the 
function. The stack exercise also showed the difference between an ADT and a data structure because the Stack<T>
descibes the behavior while Chain<T> provides the storage. The Floor 4 Rule of Three work also showed why classes that manage resources 
need special care with copying, assignment, and destruction. Overall, these exercises helped me understand that good abstractions make code easier to use 
while the underlying data structures and implementation still matter.