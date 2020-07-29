#pragma once
#include "GameObject.h"

class KeyboardBehavior;
class SeekBehavior;

class Player : public GameObject
{
public:

	Player();
	virtual ~Player();

	virtual void Update(float deltaTime);
	virtual void Draw();

protected:

	KeyboardBehavior* m_kbBehavior;
	SeekBehavior* m_seekBehavior;
};

