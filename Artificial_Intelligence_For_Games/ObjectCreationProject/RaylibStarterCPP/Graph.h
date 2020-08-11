#pragma once
#include <list>
#include <vector>
#include <functional>

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
		for (auto node : m_nodes)
		{
			delete node;
		}
		m_nodes.clear();
	}

	// FIFO
	void ForEachBFS(Node* startNode, std::function<bool(Node * n)> process)
	{
		std::list<Node*> mStack;
		std::list<Node*> mVisited;

		mStack.push_back(startNode);
		
		while (!mStack.empty())
		{
			Node* temp = mStack.front();
			mStack.pop_front();
			process(temp);
			
			mVisited.push_back(temp);
			for (int i = 0; i < temp->connections.size(); i++)
			{

			}
		}
	}

	// LIFO
	void ForEachDFS(Node* startNode, std::function<bool(Node * n)> process)
	{
		// todo, implement pseudo code here
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

protected:

	std::vector<Node*> m_nodes;
};

