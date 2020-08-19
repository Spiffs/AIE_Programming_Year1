#include "Application.h"
#include "raylib.h"
#include "GameObject.h"
#include "Chicken.h"

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

	float xOffset = 10;
	float yOffset = 10;
	float spacing = 15;

	for (int y = 0; y < m_windowHeight / spacing; y++)
	{
		for (int x = 0; x < m_windowWidth / spacing; x++)
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
		m_graph->GetNearbyNodes(node->data, 25, nearbyNodes);

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

	chicken1 = new Chicken(this);
	chicken1->SetPosition(Vector2{ 100,100 });
	chicken1->SetBehavior(new KeyboardBehavior());
	chicken1->SetFriction(1.0f);
	chicken1->Load();
}


void Application::Unload()
{
	delete[] chicken1;
}

void Application::Run()
{
	InitWindow(m_windowWidth, m_windowHeight, "Hehe");

	Load();

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
	if (IsKeyPressed(KEY_TAB))
	{
		if (debug)
			debug = false;
		else
			debug = true;
	}

	chicken1->Update(dt);
	m_graphEditor->Update(dt);
}

void Application::Draw()
{
	BeginDrawing();
	ClearBackground(RAYWHITE);

	if (debug)
		m_graphEditor->Draw();

	chicken1->Draw();

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