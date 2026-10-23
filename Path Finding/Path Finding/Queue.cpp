#include "Queue.h"

Queue::Queue()
{
}

Queue::~Queue()
{
    heap.clear();
}

struct comp
{
    bool operator() (Item& a, Item& b)
    {
        return a.GetPriority() < b.GetPriority();
    }
};

void Queue::Push(Item _Item)
{
    heap.push_back(_Item);
    std::push_heap(heap.begin(), heap.end(), comp());
}

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
