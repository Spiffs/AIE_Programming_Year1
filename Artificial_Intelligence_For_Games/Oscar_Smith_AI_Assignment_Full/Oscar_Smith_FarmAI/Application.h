#pragma once

#include "raymath.h"

class GameObject;
class Graph2D;
class Graph2DEditor;
class Chicken;

class Application
{
public:

	Application(int a_windowWidth, int a_windowHeight);
	~Application();

	void Run();

	void Load();
	void Unload();

	void Update(float deltatime);
	void Draw();

	bool GetDebug()
	{
		return debug;
	}

	Graph2D* GetGraph() { return m_graph; }

protected:

	int m_windowWidth;
	int m_windowHeight;

	Texture2D m_background;

	Graph2DEditor* m_graphEditor = nullptr;
	Graph2D* m_graph = nullptr;
	
	Chicken* chicken1;
	Chicken* chicken2;
	Chicken* chicken3;
	Chicken* chicken4;

	bool debug = false;

};