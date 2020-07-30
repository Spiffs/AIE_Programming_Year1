#include "Player.h"
#include "KeyboardBehavior.h"
#include "SeekBehavior.h"

Player::Player()
{
	m_kbBehavior = new KeyboardBehavior();
	m_seekBehavior = new SeekBehavior();
	m_seekBehavior->SetTargetRadius(25.0f);


	m_seekBehavior->OnArrive([this]()
		{
			SetBehavior(m_kbBehavior);
		});
}

Player::~Player()
{
	SetBehavior(nullptr);
	// delete m_seekBehavior
	delete m_kbBehavior;
}

void Player::Update(float deltaTime)
{
	if (IsMouseButtonPressed(0))
	{
		m_seekBehavior->SetTarget(GetMousePosition());
		SetBehavior(m_seekBehavior);
	}

	GameObject::Update(deltaTime);
}


void Player::Draw()
{
	GameObject::Draw();
}

