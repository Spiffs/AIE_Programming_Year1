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

void FleeBehavior::Update(GameObject* obj, float deltaTime)
{
	Vector2 dirToTarget;
	switch (behaviorSwitch)
	{
		// setpath 
	case 1:
	{
		// direction to target replacement::
		dirToTarget = Vector2MultiplyV(Vector2Normalize(Vector2Subtract(m_target, obj->GetPosition())), { -1.0f, -1.0f });
		Vector2 fleeTarget = { dirToTarget.x + m_fleeRadius, dirToTarget.y + m_fleeRadius };

		//______________________________________________________________________________
		std::vector<Graph2D::Node*> tempVector;
		m_app->GetGraph()->GetNearbyNodes({ obj->GetPosition().x, obj->GetPosition().y }, 15, tempVector);
		// setting tempEnd
		Graph2D::Node* tempEnd = tempVector.back();
		Graph2D::Node* tempStart;
		bool found = false;
		// find node at Vector2 point
		while (!found)
		{
			for (auto& node : m_app->GetGraph()->GetNodes())
			{
				if ((node->data.x - 7) / 15 == fleeTarget.x &&
					(node->data.y - 7) / 15 == fleeTarget.y &&
					node->access == 2)
				{
					// setting tempStart
					tempStart = node;
					found = true;
					break;
				}
			}
		}

		//________________________________________________________________________________

		// find path
		m_app->GetGraph()->PathFind(tempStart, tempEnd);
		behaviorSwitch++;
		break;
	}
	// 
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
		//dirToTarget = Vector2Normalize(Vector2Subtract(m_target, obj->GetPosition()));					reversement to dirtotarget above		HAXXOR
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
		DrawCircle(node->data.x, node->data.y, 2, GREEN);
		DrawCircleLines(node->data.x, node->data.y, 3, GRAY);
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


