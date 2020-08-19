#include "Chicken.h"
#include "Application.h"

Chicken::Chicken(Application* app) : GameObject(app)
{
	m_kbBehavior = new KeyboardBehavior();
	m_seekBehavior = new SeekBehavior();
	m_wanderBehavior = new WanderBehavior();
	m_seekBehavior->SetTargetRadius(25.0f);

	m_seekBehavior->OnArrive([this]()
		{
			SetBehavior(m_kbBehavior);
		});



}

Chicken::~Chicken()
{
	SetBehavior(nullptr);
	delete m_seekBehavior;
	delete m_kbBehavior;
	delete m_wanderBehavior;
}

void Chicken::Load()
{
	ChickenStand = LoadTexture("../Images/pixil-frame-0.png");
	ChickenWalk1 = LoadTexture("../Images/pixil-frame-0 (1).png");
	ChickenWalk2 = LoadTexture("../Images/pixil-frame-0 (2).png");
	ChickenEat1 = LoadTexture("../Images/pixil-frame-0 (3).png");
	ChickenEat2 = LoadTexture("../Images/pixil-frame-0 (4).png");

	SetPosition({ 180.0f, 180.0f });
}

bool Chicken::Moving()
{
	if (temppos.x != m_position.x ||
		temppos.y != m_position.y)
		return true;
	else
		return false;
}

void Chicken::Update(float deltaTime)
{
	if (m_behavior == m_kbBehavior)
		CharacterState = 1;


	GameObject::Update(deltaTime);
	Timer();
	// TODO: flip chicken 

	switch (CharacterState)
	{
	case 1:

		if (!Moving())
		{
			if (TimerSeconds().x == 1)
			{

			}
		}

		break;
	}



	// update temp pos
	temppos.x = m_position.x;
	temppos.y = m_position.y;
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