#include "Application.h"
#include "raylib.h"
#include "GameObject.h"
#include "KeyboardBehavior.h"
#include "Player.h"

Application::Application(int a_windowWidth, int a_windowHeight) :
	m_windowWidth(a_windowWidth), m_windowHeight(a_windowHeight) // same as "m_windowWidth = a_windowWidth"
{

}

Application::~Application() { }

void Application::Load()
{
	m_player1 = new Player();
	m_player1->SetFriction(1.0f);
	m_player1->SetPosition({ m_windowWidth * 0.5f, m_windowHeight * 0.5f });

}

void Application::Unload()
{
	delete m_player1; 
	m_player1 = nullptr;
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
	m_player1->Update(dt);
}

void Application::Draw()
{
	BeginDrawing();
	ClearBackground(RAYWHITE);
	m_player1->Draw();
	EndDrawing();
}



