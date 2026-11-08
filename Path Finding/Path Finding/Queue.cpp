#include "Queue.h"

// This is a MIN HEAP
Queue::Queue()
{
}

Queue::~Queue()
{
    heap.clear();
}

// Compare 2 items
struct comp
{
    bool operator() (Item& a, Item& b)
    {
        return a.GetPriority() < b.GetPriority();
    }
};

// Add an item
void Queue::Push(Item _Item)
{
    heap.push_back(_Item);
    std::push_heap(heap.begin(), heap.end(), comp());
}

// Remove the head item
Item Queue::Pop()
{
    if (heap.size() < 1)
    {
        throw "Cannot pop from empty heap";
    }

    Item Head = heap[0];

    // Dosn't return anything, just moves it to the back
    std::pop_heap(heap.begin(), heap.end(), comp());
    heap.pop_back();

    return Head;
}

// Get priority of the front / top item
float Queue::PriorityFront()
{
    if (heap.size() < 1)
    {
        throw "Cannot get value from empty heap";
    }

    return heap[0].GetPriority();
}

// Find if item is in the heap
bool Queue::Find(Item _Item)
{
    // If found return true
    return std::find(heap.begin(), heap.end(), _Item) != heap.end();
}

// Like find, but returns the found item
// TODO find a better way to do this
Item Queue::GetItem(Item _Item)
{
    std::vector<Item>::iterator it = std::find(heap.begin(), heap.end(), _Item);
    std::distance(heap.begin(), it);

    // Still need to find a way to return the found item
    return _Item;
}
