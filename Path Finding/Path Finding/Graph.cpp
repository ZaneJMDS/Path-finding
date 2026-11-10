#include "Graph.h"

// Check if a node is in the graph
bool Graph::NodeExist(char _item)
{
    return node_indices.find(_item) != node_indices.end();
}

// Get all the items in order
std::vector<char> Graph::GetNodeList()
{
    std::vector<char> node_list; // list of nodes to return

    // Iterate over the map
    for (std::map<int, char>::iterator it = node_labels.begin(); it != node_labels.end(); it++)
    {
        node_list.push_back(it->second); // Orders by character first
    }

    return node_list;
}
