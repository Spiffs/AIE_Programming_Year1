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

	struct PFNode
	{
		Node* graphNode;
		PFNode* parent;
		float gScore;
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

	// return true if aNode exists in aList, false if not
	bool stackcheck(std::list<Node*>& aList, Node* aNode)
	{
		int length = aList.size();
		for(auto& node : aList)
		{
			if (node == aNode)
				return true;
		}

		return false;
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
			for (auto& edge : temp->connections)
			{
				if (!stackcheck(mStack, edge.to) && !stackcheck(mVisited, edge.to))
					mStack.push_back(edge.to);
			}
		}
	}

	// LIFO
	void ForEachDFS(Node* startNode, std::function<bool(Node * n)> process)
	{
		std::list<Node*> mStack;
		std::list<Node*> mVisited;

		mStack.push_back(startNode);

		while (!mStack.empty())
		{
			Node* temp = mStack.back();
			mStack.pop_back();
			process(temp);

			mVisited.push_back(temp);
			for (auto& edge : temp->connections)
			{
				if (!stackcheck(mStack, edge.to) && !stackcheck(mVisited, edge.to))
					mStack.push_back(edge.to);
			}
		}
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

	void SetSelected(Node aNode)
	{
		m_selected = aNode;
	}

protected:

	std::vector<Node*> m_nodes;
	Node m_selected;
};

