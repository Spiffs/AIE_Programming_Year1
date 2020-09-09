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
		case 3:
			DrawCircle(node->data.x, node->data.y, 1, GREEN);
			DrawCircleLines(node->data.x, node->data.y, 2, DARKGREEN);
			break;

		}

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
