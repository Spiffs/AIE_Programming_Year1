#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

#include "Player.h"
#include <string.h>
#include <iostream>

// constructor and deconstructor
Player::Player()
{
	m_score = 0;
	strcpy_s(m_name, "");
}

Player::~Player()
{

}

// int score to int 
void Player::SetScore(int a_score)
{
	m_score = a_score;
}

// char name to char 
void Player::SetName(char a_name[4])
{
	strcpy_s(m_name, 4, a_name);
}