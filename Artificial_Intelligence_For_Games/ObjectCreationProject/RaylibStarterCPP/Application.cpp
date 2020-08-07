#include "Application.h"
#include "raylib.h"
#include "GameObject.h"
#include "KeyboardBehavior.h"
#include "Player.h"

#include "Graph2D.h"
#include "Graph2DEditor.h"

Application::Application(int a_windowWidth, int a_windowHeight) :
	m_windowWidth(a_windowWidth), m_windowHeight(a_windowHeight) // same as "m_windowWidth = a_windowWidth"
{

}

Application::~Application() { }

void Application::Load()
{
	m_graph = new Graph2D();

	int numRows = 4;
	int numColumns = 6;
	float xOffset = 100;
	float yOffset = 100;
	float spacing = 50;

	for (int y = 0; y < numRows; y++)
	{
		for (int x = 0; x < numColumns; x++)
		{
			m_graph->AddNode({
				x * spacing + xOffset,
				y * spacing + yOffset
				});
		}
	}

	for (auto node : m_graph->GetNodes())
	{
		std::vector<Graph2D::Node*> nearbyNodes;
		m_graph->GetNearbyNodes(node->data, 60, nearbyNodes);

		for (auto connectNode : nearbyNodes)
		{
			if (connectNode == node)
				continue;

			float dist = Vector2Distance(node->data, connectNode->data);
			m_graph->AddEdge(node, connectNode, dist);
			m_graph->AddEdge(connectNode, node, dist);
		}
	}

	m_graphEditor = new Graph2DEditor();
	m_graphEditor->SetGraph(m_graph);

	m_graph->TestGraph();

}


void Application::Unload()
{
	delete m_graph;
	m_graph = nullptr;
}

void Application::Run()
{
	Load();
	InitWindow(m_windowWidth, m_windowHeight, "Hehe");

	while (!WindowShouldClose())
	{
		float dt = GetFrameTime();
		Update(dt);
		Draw();
	}

	Unload();

	CloseWindow();
}

void Application::Update(float dt)
{
	m_graphEditor->Update(dt);
}

void Application::Draw()
{
	BeginDrawing();
	ClearBackground(RAYWHITE);
	
	m_graphEditor->Draw(); 

	EndDrawing();
}



// TODO:
// fix hard coded "60" value representing the radius of nearby nodes to connect
// add variables to customise the Graph2DEditor
// - node radius
// - node coloue
// - node outine 
// - line colour

// - prevent nodes from overlapping when creating new nodes. 