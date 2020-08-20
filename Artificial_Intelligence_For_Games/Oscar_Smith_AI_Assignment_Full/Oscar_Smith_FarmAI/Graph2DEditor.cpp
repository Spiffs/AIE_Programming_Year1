#include "Graph2DEditor.h"
#include "Graph2D.h"

Graph2DEditor::Graph2DEditor()
{

}

Graph2DEditor::~Graph2DEditor()
{

}

void Graph2DEditor::Update(float deltaTime)
{
	if (IsMouseButtonPressed(0))
	{
		auto mousePos = GetMousePosition();

		auto newNode = m_graph->AddNode(mousePos);

		std::vector<Graph2D::Node*> nearbyNodes;
		m_graph->GetNearbyNodes(mousePos, 15, nearbyNodes);

		for (auto nearbyNode : nearbyNodes)
		{
			float dist = Vector2Distance(newNode->data, nearbyNode->data);
			m_graph->AddEdge(newNode, nearbyNode, dist);
			m_graph->AddEdge(nearbyNode, newNode, dist);
		}

		m_graph->SetSelected(*newNode);
		//m_graph->ForEachBFS();
	}
}

void Graph2DEditor::Draw()
{
	for (auto node : m_graph->GetNodes())
	{
		for (auto connection : node->connections)
		{
			DrawLine(node->data.x, node->data.y, connection.to->data.x, connection.to->data.y, GRAY);
		}
	}

	for (auto node : m_graph->GetNodes())
	{
		switch (node->access)
		{
		case 1:
			DrawCircle(node->data.x, node->data.y, 1, LIGHTGRAY);
			DrawCircleLines(node->data.x, node->data.y, 2, GRAY);
			break;
		case 2:
			DrawCircle(node->data.x, node->data.y, 1, MAROON);
			DrawCircleLines(node->data.x, node->data.y, 2, BROWN);
			break;
		}

	}

	auto mousePos = GetMousePosition();
	DrawCircle(mousePos.x, mousePos.y, 5, LIGHTGRAY);

	std::vector<Graph2D::Node*> nearbyNodes;
	m_graph->GetNearbyNodes(mousePos, 15, nearbyNodes);

	for (auto nearbyNode : nearbyNodes)
	{
		DrawLine(mousePos.x, mousePos.y, nearbyNode->data.x, nearbyNode->data.y, LIGHTGRAY);
	}
}

Graph2D* Graph2DEditor::GetGraph()
{
	return m_graph;
}

void Graph2DEditor::SetGraph(Graph2D* graph)
{
	m_graph = graph;
}
