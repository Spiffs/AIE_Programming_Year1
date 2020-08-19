#pragma once
#include "Behavior.h"
#include "raymath.h"
#include "Graph2D.h"
#include <list>

#include <functional>

class WanderBehavior : public Behavior
{
public:

	WanderBehavior();
	virtual ~WanderBehavior();

	virtual void Update(Graph2D* a_graph, GameObject* obj, float deltaTime);
	virtual void Draw(GameObject* obj);

	const Vector2& GetTarget() const;
	void SetTarget(const Vector2& target);

	void SetTargetRadius(const float& radius);
	const float& GetTargetRadius() const;
	void FindPath();

protected:

	std::list<Graph2D::Node*> m_path;
	float m_targetRadius = 1.0f;
	Vector2 m_target;

};

