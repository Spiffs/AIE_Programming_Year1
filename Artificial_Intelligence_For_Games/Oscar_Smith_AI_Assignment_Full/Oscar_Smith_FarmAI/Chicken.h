#pragma once
#include "GameObject.h"
#include "Behavior.h"
#include "KeyboardBehavior.h"
#include "SeekBehavior.h"
#include "WanderBehavior.h"


class Chicken : public GameObject
{
public:

	Chicken(Application* app);
	virtual ~Chicken();

	void Load();

	virtual void Update(float deltaTime);
	virtual void Draw();

	bool Moving();

protected:
	Texture2D ChickenStand; // texture state 1
	Texture2D ChickenWalk1; // texture state 2
	Texture2D ChickenWalk2; // texture state 3
	Texture2D ChickenEat1; // texture state 4
	Texture2D ChickenEat2; // texture state 5
	int textureState = 1;

	int CharacterState = 0;
	
	// behavior

	Vector2 temppos;

	KeyboardBehavior* m_kbBehavior;
	SeekBehavior* m_seekBehavior;
	WanderBehavior* m_wanderBehavior;

};

