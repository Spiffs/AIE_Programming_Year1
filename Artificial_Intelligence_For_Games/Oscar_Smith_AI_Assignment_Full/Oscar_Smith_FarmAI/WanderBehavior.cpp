#include "WanderBehavior.h"
#include "GameObject.h"
#include "Graph2DEditor.h"

WanderBehavior::WanderBehavior()
{

}

WanderBehavior::~WanderBehavior()
{

}

void WanderBehavior::SetPath(std::list<Graph2D::Node*> path)
{
	m_path = path;
}

void WanderBehavior::Update(GameObject* obj, float deltaTime)
{
	if (!m_path.empty())
	{
		m_target = m_path.front()->data;
	}
	else
	{
		obj->SetBehavior(nullptr);
	}
	float distToTarget = Vector2Distance(obj->GetPosition(), m_target);

	if (distToTarget < m_targetRadius)
	{
		if (!m_path.empty())
			m_path.pop_front();
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
	for (auto node : m_path)
	{
		DrawCircle(node->data.x, node->data.y, 2, GREEN);
		DrawCircleLines(node->data.x, node->data.y, 3, GRAY);
	}
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


