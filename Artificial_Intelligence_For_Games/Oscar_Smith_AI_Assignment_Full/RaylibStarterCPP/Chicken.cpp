#include "Chicken.h"
#include <iostream>

void Chicken::Load()
{
	ChickenStand = LoadTexture("../Images/pixil-frame-0.png");
	ChickenWalk1 = LoadTexture("../Images/pixil-frame-0 (1).png");
	ChickenWalk2 = LoadTexture("../Images/pixil-frame-0 (2).png");
	ChickenEat1 = LoadTexture("../Images/pixil-frame-0 (3).png");
	ChickenEat2 = LoadTexture("../Images/pixil-frame-0 (4).png");

	SetPosition({ 180.0f, 180.0f });
}

void Chicken::Update(float deltaTime)
{
	std::cout << deltaTime << std::endl;
}

void Chicken::Draw()
{
	switch (textureState)
	{
	case 1:
		DrawTextureEx(ChickenStand, m_position, 0.0f, 1.5f, WHITE);
		break;
	case 2:
		DrawTextureEx(ChickenWalk1, m_position, 0.0f, 1.5f, WHITE);
		break;
	case 3:
		DrawTextureEx(ChickenWalk2, m_position, 0.0f, 1.5f, WHITE);
		break;
	case 4:
		DrawTextureEx(ChickenEat1, m_position, 0.0f, 1.5f, WHITE);
		break;
	case 5:
		DrawTextureEx(ChickenEat2, m_position, 0.0f, 1.5f, WHITE);
		break;
	}
	
}