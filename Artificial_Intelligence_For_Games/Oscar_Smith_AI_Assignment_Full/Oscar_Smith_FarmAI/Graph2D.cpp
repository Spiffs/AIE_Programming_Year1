#include "Graph2D.h"
#include <map>

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

bool Graph2D::pfstackcheck(std::list<PFNode*>& aList, Node* aNode)
{
	int length = aList.size();
	for (auto& node : aList)
	{
		if (node->graphNode == aNode)
			return true;
	}

	return false;
}

std::list<Graph2D::Node*> Graph2D::PathFind(Graph2D::Node* startNode, Graph2D::Node* endNode)
{
	std::list<PFNode*> mStack;
	std::list<PFNode*> mVisited;
	//std::map<PFNode*, Node*> mLinker;

	PFNode* temp = new PFNode();
	temp->graphNode = startNode;
	temp->gScore = 0;
	temp->parent = nullptr;

	mStack.push_back(temp);

	while (!mStack.empty())
	{
		// sort mStack by gScore lowest first 
		mStack.sort([](const PFNode* a, const PFNode* b) { return a->gScore < b->gScore; });
		temp = mStack.front();
		// if end node
		if (temp->graphNode == endNode)
		{
			break;
		}

		mStack.pop_front();
		mVisited.push_back(temp);

		for (auto& edge : temp->graphNode->connections)
		{
			auto newCPFNode = new PFNode();
			newCPFNode->graphNode = edge.to;

			if (!pfstackcheck(mVisited, edge.to))
			{
				float tScore = temp->gScore;

				if (!pfstackcheck(mStack, edge.to))
				{
					newCPFNode->gScore = sqrt(pow(newCPFNode->graphNode->data.x - endNode->data.x, 2)
						+ pow(newCPFNode->graphNode->data.y - endNode->data.y, 2))
						+ temp->gScore;
					newCPFNode->parent = temp;
					mStack.push_back(newCPFNode);
				}
				else if (newCPFNode->gScore > temp->gScore)
				{
					newCPFNode->gScore = sqrt(pow(newCPFNode->graphNode->data.x - endNode->data.x, 2)
						+ pow(newCPFNode->graphNode->data.y - endNode->data.y, 2))
						+ temp->gScore;
					newCPFNode->parent = temp;
				}
			}
		}
	}

	// final push
	std::list<Node*> mFinal;
	mFinal.push_back(temp->graphNode);
	while (temp->parent != nullptr)
	{
		mFinal.push_back(temp->parent->graphNode);
		temp = temp->parent;
	}

	return mFinal;
}
