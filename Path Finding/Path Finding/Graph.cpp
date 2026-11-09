#include "Graph.h"

bool Graph::NodeExist(Item* _item)
{
    return node_indices.find(_item) != node_indices.end();
}

int Graph::GetNumNodes()
{
    return node_indices.size();
}

std::vector<Item*> Graph::GetNodeList()
{
    std::vector<Item*> node_list; // list of nodes to return

    // Iterate over the map
    for (std::map<Item*, Item*>::iterator it = node_indices.begin(); it != node_indices.end(); ++it)
    {
        node_list.push_back(it->first);
    }

    return node_list;
}
