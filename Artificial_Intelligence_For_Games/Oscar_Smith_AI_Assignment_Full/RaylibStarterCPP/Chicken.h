#pragma once
#include "GameObject.h"

class Chicken : GameObject
{
public:
	Chicken()
	{

	}
	virtual ~Chicken()
	{

	}

	void Load();

	virtual void Update(float deltaTime);
	virtual void Draw();

protected:
	Texture2D ChickenStand; // texture state 1
	Texture2D ChickenWalk1; // texture state 2
	Texture2D ChickenWalk2; // texture state 3
	Texture2D ChickenEat1; // texture state 4
	Texture2D ChickenEat2; // texture state 5
	int textureState = 4;

	int timeStamp = 0;

};

