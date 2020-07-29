#include "KeyboardBehavior.h"
#include "GameObject.h"
#include "raylib.h"

KeyboardBehavior::KeyboardBehavior() : Behavior()
{
	m_upKey = KEY_W;
	m_downKey = KEY_S;
	m_leftKey = KEY_A;
	m_rightKey = KEY_D;
	m_moveForce = 100;
}

KeyboardBehavior::KeyboardBehavior(int upKey, int downKey, int leftKey, int rightKey, float moveForce) :
	Behavior(), 
	m_upKey(upKey), 
	m_downKey(downKey), 
	m_leftKey(leftKey), 
	m_rightKey(rightKey),
	m_moveForce(moveForce)
{

}

KeyboardBehavior::~KeyboardBehavior()
{

}

void KeyboardBehavior::Update(GameObject* obj, float deltatime)
{
	if (IsKeyDown(m_leftKey)) obj->ApplyForce({ -m_moveForce, 0 });
	if (IsKeyDown(m_rightKey)) obj->ApplyForce({ m_moveForce, 0 });
	if (IsKeyDown(m_upKey)) obj->ApplyForce({ 0,  -m_moveForce });
	if (IsKeyDown(m_downKey)) obj->ApplyForce({ 0,   m_moveForce });
}

void KeyboardBehavior::Draw(GameObject* obj)
{

}