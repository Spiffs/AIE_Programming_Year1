#include "WanderBehavior.h"
#include "GameObject.h"
#include <iostream>
#include "Graph2DEditor.h"

WanderBehavior::WanderBehavior()
{

}

WanderBehavior::~WanderBehavior()
{

}

void WanderBehavior::Update(Graph2D* a_graph, GameObject* obj, float deltaTime)
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

void WanderBehavior::Draw(GameObject* obj)
{
	DrawCircle(m_target.x, m_target.y, m_targetRadius, LIGHTGRAY);
	DrawCircle(m_target.x, m_target.y, 4, GRAY);
}

const Vector2& WanderBehavior::GetTarget() const
{
	return m_target;
}

void WanderBehavior::SetTarget(const Vector2& target)
{
	m_target = target;
}

const float& WanderBehavior::GetTargetRadius() const
{
	return m_targetRadius;
}

void WanderBehavior::SetTargetRadius(const float& radius)
{
	m_targetRadius = radius;
}

void WanderBehavior::OnArrive(std::function<void()> callback)
{
	m_onArriveFn = callback;
}
