#pragma once

#include "raymath.h"

class Application;
class Behavior;

class GameObject
{
public:

    struct Timer60
    {
        int framecount = 0;
        float seconds = 0;
    };


    GameObject(Application *app);
    virtual ~GameObject();

    virtual void Update(float deltaTime);
    virtual void Draw();
    // Getters
    const Vector2& GetPosition() const;
    const Vector2& GetVelocity() const;
    const float& GetFriction() const;

    Behavior* GetBehavior();

    // setters
    void SetPosition(const Vector2& pos);
    void SetVelocity(const Vector2& vel);
    void SetFriction(const float& friction);
    void ApplyForce(const Vector2& force);

    void SetBehavior(Behavior* behavior);

    void ResetTimer();
    void Timer();
    Vector2 TimerSeconds();


    Application* GetApp();

protected:
    Vector2 m_position = { 0, 0 };
    Vector2 m_velocity = { 0, 0 };
    Vector2 m_acceleration = { 0, 0 };
    float m_friction = 0.0f;

    Behavior* m_behavior = nullptr;

    Timer60 timer;

    Application* m_app = nullptr;

private:
};