#include "Chicken.h"
#include "Application.h"

Chicken::Chicken(Application* app) : GameObject(app)
{
	m_kbBehavior = new KeyboardBehavior();
	m_wanderBehavior = new WanderBehavior();
	m_wanderBehavior->SetTargetRadius(12.0f);
}

Chicken::~Chicken()
{
	SetBehavior(nullptr);
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

	ChickenStandflip = LoadTexture("../Images/pixil-frame-0 (7).png");
	ChickenWalk1flip = LoadTexture("../Images/pixil-frame-0 (8).png");
	ChickenWalk2flip = LoadTexture("../Images/pixil-frame-0 (9).png");
	ChickenEat1flip = LoadTexture("../Images/pixil-frame-0 (10).png");
	ChickenEat2flip = LoadTexture("../Images/pixil-frame-0 (11).png");

	bool validpos = false;
	while (!validpos)
	{
		int x = (rand() % 16) + 3;
		int y = (rand() % 25) + 11;

		for (auto& node : m_app->GetGraph()->GetNodes())
		{
			if ((node->data.x - 7) / 15 == x &&
				(node->data.y - 7) / 15 == y &&
				node->access == 2)
			{
				validpos = true;
				SetPosition({ (float)x * 15, (float)y * 15 });
			}
		}
	}

	SetBehavior(nullptr);
	SetFriction(8.0f);
}

void Chicken::Update(float deltaTime)
{
	if (m_behavior == m_kbBehavior)
		CharacterState = 1;

	GameObject::Update(deltaTime);
	Timer();

	int y;
	int timer = 1;

	switch (RandomTimer)
	{
	case 0:
		timer = rand() % 4;
		RandomTimer = 1;
		break;
	case 1:
		switch (CharacterState)
		{
		case 0:
		{
			break;
		}
		case 1:
		{
			if (TimerSeconds().x >= timer)
			{
				RandomTimer = 0;
				CharacterState++;
				ResetTimer();
			}
			break;
		}
		case 2:
		{
			y = TimerSeconds().y;
			if (y % 10 == 0)
			{
				if (textureState == 4)
					textureState = 5;
				else if (textureState == 5)
					textureState = 4;
				else
					textureState = 4;
			}
			if (TimerSeconds().x >= timer && TimerSeconds().y >= 20)
			{
				RandomTimer = 0;
				CharacterState++;
				ResetTimer();
			}
			break;
		}
		case 3:
		{
			textureState = 1;
			if (TimerSeconds().x >= timer)
			{
				RandomTimer = 0;
				CharacterState++;
				ResetTimer();
			}
			break;
		}
		case 4:
		{
			Graph2D::Node* tempEnd = nullptr;
			Graph2D::Node* tempStart = nullptr;

			std::vector<Graph2D::Node*> tempVector;
			m_app->GetGraph()->GetNearbyNodes({ m_position.x, m_position.y }, 15, tempVector);

			// setting tempEnd
			tempEnd = tempVector.back();

			bool found = false;
			while (!found)
			{
				int x = (rand() % 16) + 3;
				int y = (rand() % 25) + 11;
				for (auto& node : m_app->GetGraph()->GetNodes())
				{
					if ((node->data.x - 7) / 15 == x &&
						(node->data.y - 7) / 15 == y &&
						node->access == 2)
					{
						// setting tempStart
						tempStart = node;
						found = true;
					}
				}
			}

			SetBehavior(m_wanderBehavior);
			m_wanderBehavior->SetPath(m_app->GetGraph()->PathFind(tempStart, tempEnd));

			CharacterState++;
			ResetTimer();
			break;
		}
		case 5:
		{
			if (m_behavior == nullptr)
			{
				RandomTimer = 0;
				CharacterState = 1;
			}
			else
			{
				y = TimerSeconds().y;
				if (y % 10 == 0)
				{
					if (textureState == 2)
						textureState = 3;
					else if (textureState == 3)
						textureState = 2;
					else
						textureState = 2;
				}
				break;
			}
		}
		break;
		}

		if (m_velocity.x < 0)
			textureflip = false;
		else
			textureflip = true;
	}
}

void Chicken::Draw()
{
	int textureoffset = -12;

	if (!textureflip)
	{
		switch (textureState)
		{
		case 1:
			DrawTextureEx(ChickenStand, { m_position.x + textureoffset, m_position.y + textureoffset }, 0.0f, 1.5f, WHITE);
			break;
		case 2:
			DrawTextureEx(ChickenWalk1, { m_position.x + textureoffset, m_position.y + textureoffset }, 0.0f, 1.5f, WHITE);
			break;
		case 3:
			DrawTextureEx(ChickenWalk2, { m_position.x + textureoffset, m_position.y + textureoffset }, 0.0f, 1.5f, WHITE);
			break;
		case 4:
			DrawTextureEx(ChickenEat1, { m_position.x + textureoffset, m_position.y + textureoffset }, 0.0f, 1.5f, WHITE);
			break;
		case 5:
			DrawTextureEx(ChickenEat2, { m_position.x + textureoffset, m_position.y + textureoffset }, 0.0f, 1.5f, WHITE);
			break;
		}
	}
	else if (textureflip)
	{
		switch (textureState)
		{
		case 1:
			DrawTextureEx(ChickenStandflip, { m_position.x + textureoffset, m_position.y + textureoffset }, 0.0f, 1.5f, WHITE);
			break;
		case 2:
			DrawTextureEx(ChickenWalk1flip, { m_position.x + textureoffset, m_position.y + textureoffset }, 0.0f, 1.5f, WHITE);
			break;
		case 3:
			DrawTextureEx(ChickenWalk2flip, { m_position.x + textureoffset, m_position.y + textureoffset }, 0.0f, 1.5f, WHITE);
			break;
		case 4:
			DrawTextureEx(ChickenEat1flip, { m_position.x + textureoffset, m_position.y + textureoffset }, 0.0f, 1.5f, WHITE);
			break;
		case 5:
			DrawTextureEx(ChickenEat2flip, { m_position.x + textureoffset, m_position.y + textureoffset }, 0.0f, 1.5f, WHITE);
			break;
		}
	}

	if (m_app->GetDebug())
	{
		m_wanderBehavior->Draw(this);
	}
}

void Chicken::SetState(int state)
{
	CharacterState = state;
}