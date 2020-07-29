#include "SeekBehavior.h"
#include "GameObject.h"
#include <iostream>

SeekBehavior::SeekBehavior()
{

}

SeekBehavior::~SeekBehavior()
{

}

void SeekBehavior::Update(GameObject* obj, float deltaTime)
{
	Vector2 heading = Vector2Add(obj->GetPosition(), obj->GetVelocity());
	float headingLen = Vector2Length(obj->GetVelocity());

	Vector2 vecToTarget = Vector2Normalize(Vector2Subtract(m_target, obj->GetPosition()));

	//__________________________________________________________________________________________________________________ 21.50 timestamp on 06 aie seekbehavior video	HAXXOR
}

void SeekBehavior::Draw(GameObject* obj)
{
	DrawCircle(m_target.x, m_target.y, m_targetRadius, LIGHTGRAY);
	DrawCircle(m_target.x, m_target.y, 4, GRAY);
}

const Vector2& SeekBehavior::GetTarget() const
{
	return m_target;
}

void SeekBehavior::SetTarget(const Vector2& target)
{
	m_target = target;
}

const float& SeekBehavior::GetTargetRadius() const
{
	return m_targetRadius;
}

void SeekBehavior::SetTargetRadius(const float& radius)
{
	m_targetRadius = radius;
}
