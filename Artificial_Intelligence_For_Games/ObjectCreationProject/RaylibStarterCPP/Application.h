#pragma once

class Player;
class GameObject;
class Graph2D;
class Graph2DEditor;

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

private:

	int m_windowWidth;
	int m_windowHeight;

	Player* player;

	Graph2DEditor* m_graphEditor = nullptr;
	Graph2D* m_graph = nullptr;

};