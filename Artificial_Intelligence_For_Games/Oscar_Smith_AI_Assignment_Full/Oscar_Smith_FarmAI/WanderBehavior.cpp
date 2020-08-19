#include "WanderBehavior.h"
#include "GameObject.h"
#include "Graph2DEditor.h"

WanderBehavior::WanderBehavior()
{

}

WanderBehavior::~WanderBehavior()
{

}

void WanderBehavior::FindPath()
{
	m_path = m_app->GetGraph()->PathFind( );
}

void WanderBehavior::Update(Graph2D* a_graph, GameObject* obj, float deltaTime)
{
	m_target = m_path.back()->data;

	float distToTarget = Vector2Distance(obj->GetPosition(), m_target);
	if (distToTarget < m_targetRadius)
	{
		m_path.pop_back();
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
	
}


const float& WanderBehavior::GetTargetRadius() const
{
	return m_targetRadius;
}

void WanderBehavior::SetTargetRadius(const float& radius)
{
	m_targetRadius = radius;
}


