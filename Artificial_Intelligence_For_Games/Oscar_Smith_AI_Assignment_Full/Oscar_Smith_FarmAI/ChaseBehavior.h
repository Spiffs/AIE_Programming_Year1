#pragma once
#include "Behavior.h"
#include "raymath.h"
#include "Graph2D.h"
#include <list>

class ChaseBehavior : public Behavior
{
public:

	ChaseBehavior(Application* a_app);
	virtual ~ChaseBehavior();

	virtual void Update(GameObject* obj, float deltaTime);
	virtual void Draw(GameObject* obj);

	const Vector2& GetTarget() const;
	void SetTarget(const Vector2& target);

	void SetTargetRadius(const float& radius);
	const float& GetTargetRadius() const;

	void SetPath(std::list<Graph2D::Node*> path);


protected:

	std::list<Graph2D::Node*> m_path;
	float m_targetRadius = 12.0f;
	Vector2 m_target;

	float maxSpeed = 500.0f;

	Application* m_app;
};

