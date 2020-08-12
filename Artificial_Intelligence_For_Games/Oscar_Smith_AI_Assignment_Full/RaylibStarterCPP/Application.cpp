#include "Application.h"
#include "raylib.h"

Application::Application(int a_windowWidth, int a_windowHeight) :
	m_windowWidth(a_windowWidth), m_windowHeight(a_windowHeight) // same as "m_windowWidth = a_windowWidth"
{

}

Application::~Application() { }

void Application::Load()
{

}


void Application::Unload()
{

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

}

void Application::Draw()
{
	BeginDrawing();
	ClearBackground(RAYWHITE);

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