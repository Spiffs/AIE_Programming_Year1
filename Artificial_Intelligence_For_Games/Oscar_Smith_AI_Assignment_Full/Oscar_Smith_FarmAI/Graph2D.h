#pragma once

#include <iostream>
#include "Graph.h"
#include "raymath.h"
#include <functional>
#include <vector>
#include <list>
#include <map>

class Graph2D : public Graph<Vector2, float>
{
public:

    Graph2D();
    virtual ~Graph2D();

    void GetNearbyNodes(Vector2 position, float radius, std::vector<Graph2D::Node*>& out_nodes);

    void SetAccess(std::vector<int> graph);
    bool pfstackcheck(std::list<PFNode*>& aList, Node* aNode);
    Node* FindNodePos(Vector2 pos);
    std::list<Graph2D::Node*> PathFind(Graph2D::Node* startNode, Graph2D::Node* endNode);

private:

};