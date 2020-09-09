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
	FoxStand1 = LoadTexture("../Images/l0_Fox1.png");
	FoxStand2 = LoadTexture("../Images/l0_Fox2.png");
	FoxStand3 = LoadTexture("../Images/l0_Fox3.png");
	FoxWalk1 = LoadTexture("../Images/l0_Fox4.png");
	FoxWalk2 = LoadTexture("../Images/l0_Fox5.png");
	FoxWalk3 = LoadTexture("../Images/l0_Fox6.png");
	FoxWalk4 = LoadTexture("../Images/l0_Fox7.png");

	FoxStand1flip = LoadTexture("../Images/l0_Fox1Flip.png");
	FoxStand2flip = LoadTexture("../Images/l0_Fox2Flip.png");
	FoxStand3flip = LoadTexture("../Images/l0_Fox3Flip.png");
	FoxWalk1flip = LoadTexture("../Images/l0_Fox4Flip.png");
	FoxWalk2flip = LoadTexture("../Images/l0_Fox5Flip.png");
	FoxWalk3flip = LoadTexture("../Images/l0_Fox6Flip.png");
	FoxWalk4flip = LoadTexture("../Images/l0_Fox7Flip.png");

	SetPosition({ 760, 380 });
	SetBehavior(nullptr);
	SetFriction(8.0f);
}

void Fox::Update(float deltaTime)
{
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
		case 1:
		{
			if (textureState >= 4)
				textureState = 1;

			y = TimerSeconds().y;
			if (y % 20 == 0)
			{
				switch (textureState)
				{
				case 1:
					textureState++;
					itexture = 1;
					break;
				case 2:
					textureState += itexture;
					break;
				case 3:
					textureState--;
					itexture = -1;
					break;
				}
			}

			if (TimerSeconds().x >= 2)
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
				int x = (rand() % 54) + 49;
				int y = (rand() % 29) + 26;
				for (auto& node : m_app->GetGraph()->GetNodes())
				{
					if ((node->data.x - 7) / 15 == x &&
						(node->data.y - 7) / 15 == y &&
						node->access == 3)
					{
						// setting tempStart
						tempStart = node;
						found = true;
						break;
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
				movesbeforechase++;
				RandomTimer = 0;
				CharacterState = 1;
				if (movesbeforechase <= 5)
				{

				}
			}
			else
			{
				y = TimerSeconds().y;
				if (y % 8 == 0)
				{
					textureState++;
					if (textureState > 7)
					{
						textureState = 4;
					}
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
	int textureoffsetx = -16;
	int textureoffsety = -16;

	if (!textureflip)
	{
		switch (textureState)
		{
		case 1:
			DrawTextureEx(FoxStand1, { m_position.x + textureoffsetx, m_position.y + textureoffsety }, 0.0f, 1.5f, WHITE);
			break;
		case 2:
			DrawTextureEx(FoxStand2, { m_position.x + textureoffsetx, m_position.y + textureoffsety }, 0.0f, 1.5f, WHITE);
			break;
		case 3:
			DrawTextureEx(FoxStand3, { m_position.x + textureoffsetx, m_position.y + textureoffsety }, 0.0f, 1.5f, WHITE);
			break;
		case 4:
			DrawTextureEx(FoxWalk1, { m_position.x + textureoffsetx, m_position.y + textureoffsety }, 0.0f, 1.5f, WHITE);
			break;
		case 5:
			DrawTextureEx(FoxWalk2, { m_position.x + textureoffsetx, m_position.y + textureoffsety }, 0.0f, 1.5f, WHITE);
			break;
		case 6:
			DrawTextureEx(FoxWalk3, { m_position.x + textureoffsetx, m_position.y + textureoffsety }, 0.0f, 1.5f, WHITE);
			break;
		case 7:
			DrawTextureEx(FoxWalk4, { m_position.x + textureoffsetx, m_position.y + textureoffsety }, 0.0f, 1.5f, WHITE);
			break;
		}
	}
	else if (textureflip)
	{
		switch (textureState)
		{
		case 1:
			DrawTextureEx(FoxStand1flip, { m_position.x + textureoffsetx, m_position.y + textureoffsety }, 0.0f, 1.5f, WHITE);
			break;
		case 2:
			DrawTextureEx(FoxStand2flip, { m_position.x + textureoffsetx, m_position.y + textureoffsety }, 0.0f, 1.5f, WHITE);
			break;
		case 3:
			DrawTextureEx(FoxStand3flip, { m_position.x + textureoffsetx, m_position.y + textureoffsety }, 0.0f, 1.5f, WHITE);
			break;
		case 4:
			DrawTextureEx(FoxWalk1flip, { m_position.x + textureoffsetx, m_position.y + textureoffsety }, 0.0f, 1.5f, WHITE);
			break;
		case 5:
			DrawTextureEx(FoxWalk2flip, { m_position.x + textureoffsetx, m_position.y + textureoffsety }, 0.0f, 1.5f, WHITE);
			break;
		case 6:
			DrawTextureEx(FoxWalk3flip, { m_position.x + textureoffsetx, m_position.y + textureoffsety }, 0.0f, 1.5f, WHITE);
			break;
		case 7:
			DrawTextureEx(FoxWalk4flip, { m_position.x + textureoffsetx, m_position.y + textureoffsety }, 0.0f, 1.5f, WHITE);
			break;
		}
	}

	if (m_app->GetDebug())
	{
		m_wanderBehavior->Draw(this);
	}
}