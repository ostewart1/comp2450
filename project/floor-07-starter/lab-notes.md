1.) 
> selftest queue
  empty Queue<int>: size==0 && empty(): OK
  enqueue(7): size==1 && front()==7: OK
  enqueue 1,2,3: size==3 && front()==1 (FIFO): OK
  after dequeue(): size==2 && front()==2: OK
  drain to empty: size==0 && empty(): OK
  all phases OK
> potato A B C D E 3
  Survivor: D
> potato Grix Skrit Quill Vael Resh 2
  Survivor: Quill
> potato OnlyOne 7
  Survivor: OnlyOne
> provoke Goblin
  Goblin takes a number and joins the line.
> provoke Skeleton
  Skeleton takes a number and joins the line.
> provoke Imp
  Imp takes a number and joins the line.
> simulate
Turn 1: Goblin stirs in the dark.
Turn 2: Skeleton stirs in the dark.
Turn 3: Imp stirs in the dark.
All enemies have acted. The line is empty.
> simulate
No enemies in the line. Use provoke <name> first.
> quit

2.) Job	Stack<T> calls…	Queue<T> calls…
Add an item (push / enqueue)	chain_.push_front(value);	chain_.push_back(value);
Remove an item (pop / dequeue)	chain_.pop_front();	chain_.pop_front();
Read the next item out (top / front)	chain_.head()->data	chain_.head()->data
A stack and a queue are different because a stack uses LIFO, while a queue uses FIFO.
Queue uses a Chain<T> instead of a Bag<T> because queues need to maintain the order of elements, while bags do not. 

3.) > selftest queue
  empty Queue<int>: size==0 && empty(): OK
  enqueue(7): size==1 && front()==7: OK
  enqueue 1,2,3: size==3 && front()==1 (FIFO): FAIL ΓÇö front() did not return the FIRST enqueued value ΓÇö enqueue/front are on the same end (that's a stack, not a queue)
  after dequeue(): size==2 && front()==2: OK
  drain to empty: size==0 && empty(): OK
  (see FAILs above)
>

> potato A B C D E 3
  Survivor: A

  - I built a stack-like structure instead of a FIFO queue because new items were added to the front instead of the back.

5.) Command: potato A B C D 2


start:               A B C D
rotate (A to back):  B C D A
eliminate B:         C D A
rotate (C to back):  D A C
eliminate D:         A C
rotate (A to back):  C A
eliminate C:         A
Predicted survivor: A

Program output:


Survivor: A

the program's results matched my prediction

6.) Writing the queue was easier the second time because I already understood how to use a Chain<T>.
I just had to change which end items were added to so the queue would follow FIFO instead of LIFO. 
The project helped me understand how choosing different ends changes how a data structure works.