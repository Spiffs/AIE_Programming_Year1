#include "ChaseBehavior.h"
#include "GameObject.h"
#include "Graph2DEditor.h"
#include <iostream>

ChaseBehavior::ChaseBehavior(Application* a_app)
{
	m_app = a_app;
}

ChaseBehavior::~ChaseBehavior()
{

}

void ChaseBehavior::SetPath(std::list<Graph2D::Node*> path)
{
	m_path = path;
}

void ChaseBehavior::Update(GameObject* obj, float deltaTime)
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
	Vector2 dirToTarget = Vector2Normalize(Vector2Subtract(m_target, obj->GetPosition()) );

	obj->ApplyForce(Vector2Scale(dirToTarget, maxSpeed));

}

void ChaseBehavior::Draw(GameObject* obj)
{
	for (auto node : m_path)
	{
		DrawCircle(node->data.x, node->data.y, 2, GREEN);
		DrawCircleLines(node->data.x, node->data.y, 3, GRAY);
	}
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


