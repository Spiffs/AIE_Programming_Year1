#pragma once
#include <vector>

template<class TNodeData, class TEdgeData>
class Graph
{
public:
	struct Node;
	struct Edge;


	struct Node
	{
		TNodeData data;
		std::vector<Edge> connections;
	};

	struct Edge
	{
		Node* to;
		TEdgeData data;
	};

public:

	// constructor
	Graph()
	{

	}

	// decpnstructor
	virtual ~Graph()
	{

	}

	// add node
	Node* AddNode(const TNodeData& data)
	{
		Node* node = new Node();
		node->data = data;
		m_nodes.push_back(node);
		return node;
	}

	// add edge
	void AddEdge(Node* nodeA, Node* nodeB, const TEdgeData& data)
	{
		nodeA->connections.push_back({ nodeB, data });
	}

	// get nodes
	std::vector<Node*>& GetNodes()
	{
		return m_nodes;
	}

private:

	std::vector<Node*> m_nodes;
};

