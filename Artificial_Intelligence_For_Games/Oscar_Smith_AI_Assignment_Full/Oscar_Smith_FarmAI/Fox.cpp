#include "Fox.h"
#include "Application.h"

Fox::Fox(Application* app) : GameObject(app)
{
	m_wanderBehavior = new WanderBehavior();
	m_wanderBehavior->SetTargetRadius(12.0f);
}
Fox::~Fox()
{
	SetBehavior(nullptr);
	delete m_wanderBehavior;
}

void Fox::Load()
{
	FoxStand1 = LoadTexture("../Images/pixil-frame-0 (12).png");
	FoxStand2 = LoadTexture("../Images/pixil-frame-0 (13).png");
	FoxStand3 = LoadTexture("../Images/pixil-frame-0 (14).png");
	FoxWalk1 = LoadTexture("../Images/pixil-frame-0 (15).png");
	FoxWalk2 = LoadTexture("../Images/pixil-frame-0 (16).png");
	FoxWalk3 = LoadTexture("../Images/pixil-frame-0 (17).png");

	FoxStand1flip = LoadTexture("../Images/pixil-frame-0 (18).png");
	FoxStand2flip = LoadTexture("../Images/pixil-frame-0 (19).png");
	FoxStand3flip = LoadTexture("../Images/pixil-frame-0 (20).png");
	FoxWalk1flip = LoadTexture("../Images/pixil-frame-0 (21).png");
	FoxWalk2flip = LoadTexture("../Images/pixil-frame-0 (22).png");
	FoxWalk3flip = LoadTexture("../Images/pixil-frame-0 (23).png");

	SetPosition({ 200, 200 });
	SetBehavior(nullptr);
	SetFriction(8.0f);
}

void Fox::Update(float deltaTime)
{
	GameObject::Update(deltaTime);
	Timer();

	int y;
	int timer = 1;
	int itexture = +1;

	switch (RandomTimer)
	{
	case 0:
		timer = rand() % 4;
		RandomTimer = 1;
		break;
	case 1:
		switch (CharacterState)
		{
		case 1:
		{
			y = TimerSeconds().y;
			if (y % 20 == 0)
			{
				if (textureState == 1)
				{
					textureState++;
					itexture = 1;
				}
				else if (textureState == 2)
				{
					textureState += itexture;
				}
				else if (textureState == 3)
				{
					textureState--;
					itexture = -1;
				}
			}

			if (TimerSeconds().x >= 30)
			{
				RandomTimer = 0;
				CharacterState++;
				ResetTimer();
			}
			break;
		}
		case 2:
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
		case 3:
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

void Fox::Draw()
{
	int textureoffset = -12;

	if (!textureflip)
	{
		switch (textureState)
		{
		case 1:
			DrawTextureEx(FoxStand1, { m_position.x + textureoffset, m_position.y + textureoffset }, 0.0f, 1.75f, WHITE);
			break;
		case 2:
			DrawTextureEx(FoxStand2, { m_position.x + textureoffset, m_position.y + textureoffset }, 0.0f, 1.75f, WHITE);
			break;
		case 3:
			DrawTextureEx(FoxStand3, { m_position.x + textureoffset, m_position.y + textureoffset }, 0.0f, 1.75f, WHITE);
			break;
		case 4:
			DrawTextureEx(FoxWalk1, { m_position.x + textureoffset, m_position.y + textureoffset }, 0.0f, 1.75f, WHITE);
			break;
		case 5:
			DrawTextureEx(FoxWalk2, { m_position.x + textureoffset, m_position.y + textureoffset }, 0.0f, 1.75f, WHITE);
			break;
		case 6:
			DrawTextureEx(FoxWalk3, { m_position.x + textureoffset, m_position.y + textureoffset }, 0.0f, 1.75f, WHITE);
			break;
		}
	}
	else if (textureflip)
	{
		switch (textureState)
		{
		case 1:
			DrawTextureEx(FoxStand1, { m_position.x + textureoffset, m_position.y + textureoffset }, 0.0f, 1.75f, WHITE);
			break;
		case 2:
			DrawTextureEx(FoxStand2, { m_position.x + textureoffset, m_position.y + textureoffset }, 0.0f, 1.75f, WHITE);
			break;
		case 3:
			DrawTextureEx(FoxStand3, { m_position.x + textureoffset, m_position.y + textureoffset }, 0.0f, 1.75f, WHITE);
			break;
		case 4:
			DrawTextureEx(FoxWalk1, { m_position.x + textureoffset, m_position.y + textureoffset }, 0.0f, 1.75f, WHITE);
			break;
		case 5:
			DrawTextureEx(FoxWalk2, { m_position.x + textureoffset, m_position.y + textureoffset }, 0.0f, 1.75f, WHITE);
			break;
		case 6:
			DrawTextureEx(FoxWalk3, { m_position.x + textureoffset, m_position.y + textureoffset }, 0.0f, 1.75f, WHITE);
			break;
		}
	}
}