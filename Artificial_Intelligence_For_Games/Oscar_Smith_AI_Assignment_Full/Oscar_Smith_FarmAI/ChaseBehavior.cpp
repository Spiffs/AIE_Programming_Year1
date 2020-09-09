#include "ChaseBehavior.h"
#include "GameObject.h"
#include <iostream>

ChaseBehavior::ChaseBehavior()
{

}

ChaseBehavior::~ChaseBehavior()
{

}

void ChaseBehavior::Update(GameObject* obj, float deltaTime)
{
	float distToTarget = Vector2Distance(obj->GetPosition(), m_target);
	if (distToTarget < m_targetRadius)
	{
		if (m_onArriveFn)
			m_onArriveFn();
	}

	Vector2 heading = Vector2Add(obj->GetPosition(), obj->GetVelocity());
	float headingLen = Vector2Length(heading);

	Vector2 dirToTarget = Vector2Normalize(Vector2Subtract(m_target, obj->GetPosition()));
	Vector2 vecToTarget = Vector2Scale(dirToTarget, headingLen);

	Vector2 targetForcePos = Vector2Add(vecToTarget, obj->GetPosition());
	Vector2 forceDir = Vector2Subtract(targetForcePos, heading);

	obj->ApplyForce(forceDir);
}

void ChaseBehavior::Draw(GameObject* obj)
{

}

const Vector2& ChaseBehavior::GetTarget() const
{
	return m_target;
}

void ChaseBehavior::SetTarget(const Vector2& target)
{
	m_target = target;
}

const float& ChaseBehavior::GetTargetRadius() const
{
	return m_targetRadius;
}

void ChaseBehavior::SetTargetRadius(const float& radius)
{
	m_targetRadius = radius;
}

void ChaseBehavior::OnArrive(std::function<void()> callback)
{
	m_onArriveFn = callback;
}
