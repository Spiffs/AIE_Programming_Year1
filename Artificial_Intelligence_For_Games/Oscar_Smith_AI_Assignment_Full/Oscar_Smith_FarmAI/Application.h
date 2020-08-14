#pragma once

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

	Graph2D* GetGraph() { return m_graph; }

private:

	int m_windowWidth;
	int m_windowHeight;

	Graph2DEditor* m_graphEditor = nullptr;
	Graph2D* m_graph = nullptr;
	Chicken* chicken1;
	bool debug = false;

};