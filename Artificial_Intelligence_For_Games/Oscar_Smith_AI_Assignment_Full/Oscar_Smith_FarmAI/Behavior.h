#pragma once
#include "Application.h"

class GameObject;

class Behavior
{
public:
	Behavior() {}
	virtual ~Behavior() {}

	virtual void Update(GameObject* obj, float deltatime) { }
	virtual void Draw(GameObject* obj) { }

protected:
	Application* m_app;

};
