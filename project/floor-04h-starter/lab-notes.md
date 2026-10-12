2.)
In push_back, I removed the line: new_node->prev = tail_
I ran log --oldest 5.
The forward walk could still reach the nodes because the next pointers were still connected, but the backward walk was broken 
because the new node did not have its prev pointer set correctly. 
When the program tried to walk backward from the tail,
it read the bad prev pointer of the newest node instead of finding the previous node in the chain.
The step that reads the bad pointer is the first backward move from the tail, when the code follows current->prev.
I restored the line: new_node->prev = tail_;

3.) Failure: for (const auto* p = c.head(); p != nullptr; p = p->next) ++n;
Line 44

4.) Chain& operator=(Chain other)
{
    swap(other);
    return *this;
}

Chain& operator=(const Chain& other)
{
    if (this == &other)
        return *this;

    Chain temp(other);

    clear();

    head_ = temp.head_;
    tail_ = temp.tail_;
    size_ = temp.size_;

    temp.head_ = nullptr;
    temp.tail_ = nullptr;
    temp.size_ = 0;

    return *this;
}

I am more confident writing the copy-and-swap version under exam pressure because it is shorter 
and uses the copy constructor to make the copy safely.
It also handles self-assignment naturally because the copied object is separate from the original, while the explicit
version requires me to remember the self-assignment check and carefully transfer ownership.

5.) A tail_ pointer lets you find the last node immediately, but after deleting the tail, the new tail must 
have its next pointer changed to nullptr. In a singly-linked list, 
you have to walk from the head to find the node immediately before the old tail, so pop_back is still O(n).

6.) The Rule of Three says that if a class needs a custom destructor, copy constructor, and copy-assignment operator because it manages a resource, it generally needs all three. 
The Chain<T> class needs these because it directly owns and deletes dynamically allocated nodes, so copying the object requires creating a separate set of nodes instead of simply copying the pointers.
I would use the Rule of Zero when a class can rely on resource-managing member types such as std::vector, std::string, or smart pointers to automatically manage its resources, 
because then I would not need to write a custom destructor, copy constructor, or copy-assignment operator. Chain<T> does not qualify because it manually manages its linked-list nodes 
with raw pointers and is responsible for allocating, copying, and deleting those nodes itself.