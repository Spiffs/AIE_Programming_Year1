#pragma once
#include "Behavior.h"

class KeyboardBehavior : public Behavior
{
public:

	KeyboardBehavior();
	KeyboardBehavior(int upKey, int downKey, int leftKey, int rightKey, float moveForce);
	virtual ~KeyboardBehavior();

	virtual void Update(GameObject* obj, float deltatime);
	virtual void Draw(GameObject* obj);

protected:

	int m_upKey;
	int m_downKey;
	int m_leftKey;
	int m_rightKey;

	float m_moveForce = 0;

};

