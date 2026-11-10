#include "Graph.h"

// Check if a node is in the graph
bool Graph::NodeExist(char _item)
{
    return node_indices.find(_item) != node_indices.end();
}

// Get number of nodes in the graph
int Graph::GetNumNodes()
{
    return node_indices.size();
}

// Get all the items
std::vector<char> Graph::GetNodeList()
{
    std::vector<char> node_list; // list of nodes to return

    // Iterate over the map
    for (std::map<char, int>::iterator it = node_indices.begin(); it != node_indices.end(); ++it)
    {
        node_list.push_back(it->first);
    }

    return node_list;
}
