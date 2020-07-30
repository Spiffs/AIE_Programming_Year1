#pragma once

class GameObject;

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

	GameObject* m_player1 = nullptr;

};