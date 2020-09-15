#include "FleeBehavior.h"
#include "GameObject.h"
#include "Graph2DEditor.h"
#include <iostream>

FleeBehavior::FleeBehavior(Application* app)
{
	m_app = app;
}

FleeBehavior::~FleeBehavior()
{

}

void FleeBehavior::SetPath(std::list<Graph2D::Node*> path)
{
	m_path = path;
}

void FleeBehavior::SetBehaviorSwitch(int i)
{
	behaviorSwitch = i;
}

void FleeBehavior::Update(GameObject* obj, float deltaTime)
{
	Vector2 dirToTarget = { 0, 0 };
	switch (behaviorSwitch)
	{
		// setpath 
	case 1:
	{
		// direction to target replacement::
		dirToTarget = Vector2MultiplyV(Vector2Normalize(Vector2Subtract(m_target, obj->GetPosition())), { -1.0f, -1.0f });
		Vector2 fleeTarget = { obj->GetPosition().x + (dirToTarget.x * m_fleeRadius), obj->GetPosition().y + (dirToTarget.y * m_fleeRadius) };

		//______________________________________________________________________________
			// chicken pos
		std::vector<Graph2D::Node*> tempVectorstart;
		    // destination pos
		std::vector<Graph2D::Node*> tempVectorend;

		// loop through adding to the radius until found
		int radius = 15;
		while (tempVectorstart.size() == 0)
		{
			m_app->GetGraph()->GetNearbyNodes(obj->GetPosition(), radius, tempVectorstart);
			radius += 15;
		}
		radius = 15;

		// destination
		while (tempVectorend.size() == 0)
		{
			m_app->GetGraph()->GetNearbyNodes(fleeTarget, radius, tempVectorend);
			radius += 15;
		}

		// setting temps
		Graph2D::Node* tempEnd = tempVectorstart.back();
		Graph2D::Node* tempStart = tempVectorend.back();

		//________________________________________________________________________________

		// find path
		SetPath(m_app->GetGraph()->PathFind(tempStart, tempEnd));
		behaviorSwitch++;
		break;
	}
	// follow path
	case 2:
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

		// target direction in terms of 1 = NSEW is dirToTarget
		dirToTarget = Vector2Normalize(Vector2Subtract(m_target, obj->GetPosition()));
		Vector2 vecToTarget = Vector2Scale(dirToTarget, headingLen);

		Vector2 targetForcePos = Vector2Add(vecToTarget, obj->GetPosition());
		Vector2 forceDir = Vector2Subtract(targetForcePos, heading);

		obj->ApplyForce(forceDir);
		break;
	}
	}
}

void FleeBehavior::Draw(GameObject* obj)
{
	for (auto node : m_path)
	{
		DrawCircle(node->data.x, node->data.y, 4, SKYBLUE);
		DrawCircleLines(node->data.x, node->data.y, 5, BLUE);
	}
}


const Vector2& FleeBehavior::GetTarget() const
{
	return m_target;
}

void FleeBehavior::SetTarget(const Vector2& target)
{
	m_target = target;
}

const float& FleeBehavior::GetTargetRadius() const
{
	return m_targetRadius;
}

void FleeBehavior::SetTargetRadius(const float& radius)
{
	m_targetRadius = radius;
}


