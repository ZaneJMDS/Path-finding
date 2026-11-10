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
    return std::find(heap.begin(), heap.end(), _Item) != heap.end();
}

// Like find, but returns the found item
// TODO Might not be needed
Item Queue::GetItem(Item _Item)
{
    std::vector<Item>::iterator it = std::find(heap.begin(), heap.end(), _Item);
    std::distance(heap.begin(), it);

    return _Item;
}

Item Queue::FindNode(float x, float y)
{
    Item current = heap[0]; // Start at the beggining

    // Iterate until the node has been found
    while (current.x != x && current.y != y)
    {
        // Implement iterative here
    }

    return current;
}

// Return the surrounding nodes of this item
std::vector<Item> Queue::GetNeighbourNodes(Item _Item)
{
    std::vector<Item> neighbours;

    // Eight neighbours
    // Collumns
    for (int i = -1; i < 2; i++)
    {
        // Rows
        for (int j = -1; j < 2; j++)
        {
            // Don't return the current node
            if (i != 0 && j != 0)
            {
                neighbours.push_back(FindNode(_Item.x + i, _Item.y + j));
            }
        }
    }

    bool near_wall = false;

    for (int i = 0; i < neighbours.size(); i++)
    {
        neighbours[i].GetIdentifier() == 'x'; // Wall
        near_wall = true;
    }

    // If neighbours contain a wall, only return the 4 cardinal directions
    if (near_wall)
    {
        neighbours.clear();

        neighbours.push_back(FindNode(_Item.x + 1, _Item.y));
        neighbours.push_back(FindNode(_Item.x - 1, _Item.y));
        neighbours.push_back(FindNode(_Item.x, _Item.y + 1));
        neighbours.push_back(FindNode(_Item.x, _Item.y - 1));
    }

    return neighbours;
}
