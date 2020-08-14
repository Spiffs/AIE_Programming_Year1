#pragma once
#include "Behavior.h"
#include "raymath.h"
#include "Graph2D.h"

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

	const float& GetTargetRadius() const;
	void SetTargetRadius(const float& radius);

	void OnArrive(std::function<void()> callback);

protected:

	Vector2 m_target;
	float m_targetRadius = 1.0f;

	std::function<void()> m_onArriveFn;

};
