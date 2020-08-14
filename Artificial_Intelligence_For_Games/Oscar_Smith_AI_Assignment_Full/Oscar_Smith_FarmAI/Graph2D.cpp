#include "Graph2D.h"

Graph2D::Graph2D()
{

}

Graph2D::~Graph2D()
{

}

void Graph2D::GetNearbyNodes(Vector2 position, float radius, std::vector<Graph2D::Node*>& out_nodes)
{
    for (auto node : m_nodes)
    {
        float dist = Vector2Distance(position, node->data);
        if (dist < radius)
        {
            out_nodes.push_back(node);
        }
    }
}


Graph2D::Node* Graph2D::FindNodePos(Vector2 pos)
{
    for (auto node : m_nodes)
    {
        if (node->data.x == pos.x && node->data.y == pos.y)
            return node;
    }
}