#pragma once

#include "Graph.h"
#include "raymath.h"
#include <functional>
#include <vector>

class Graph2D : public Graph<Vector2, float>
{
public:

	Graph2D();
	virtual ~Graph2D();

	void GetNearbyNodes(Vector2 position, float radius, std::vector<Graph2D::Node*>& out_nodes);

	// FIFO
	Node* ForEachBFS(Node* startNode, std::function<bool(Node * n)> process)
	{
		std::vector<Node*> mStack;
		std::vector<Node*> mVisited;

		mStack.push_back(startNode);

		while (!mStack.empty())
		{
			Node* temp = mStack.front();
			mStack.
		}
	}

	// LIFO
	Node* ForEachDFS(Node* startNode, std::function<bool(Node * n)> process)
	{
		// todo, implement pseudo code here
	}

private:

};