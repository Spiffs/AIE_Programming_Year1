#pragma once
#include "GameObject.h"
#include "Behavior.h"
#include "KeyboardBehavior.h"
#include "WanderBehavior.h"
#include "ChaseBehavior.h"

class Fox : public GameObject
{
public:
	Fox(Application* app);
	virtual ~Fox();

	void Load();

	virtual void Update(float deltaTime);
	virtual void Draw();

protected:
	Texture2D FoxStand1;
	Texture2D FoxStand2;
	Texture2D FoxStand3;
	Texture2D FoxWalk1;
	Texture2D FoxWalk2;
	Texture2D FoxWalk3;
	Texture2D FoxWalk4;

	Texture2D FoxStand1flip;
	Texture2D FoxStand2flip;
	Texture2D FoxStand3flip;
	Texture2D FoxWalk1flip;
	Texture2D FoxWalk2flip;
	Texture2D FoxWalk3flip;
	Texture2D FoxWalk4flip;

	int textureState = 1;
	bool textureflip = false;
	int RandomTimer = 0;
	int CharacterState = 1;
	int itexture = 0;
	int movesbeforechase = 0;

	WanderBehavior* m_wanderBehavior;
	ChaseBehavior* m_chaseBehavior;
	


};

