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
	//memset(m_name, NULL, 9);
}

Player::~Player()
{
	
}

// int score to int 
void Player::setscore(int a_score)
{
	m_score = a_score;
}

// string to char[]
void Player::setname(std::string a_name)
{
	if (a_name.length() == 9)
	{
		strcpy(&m_name[9], a_name.c_str());
	}
}

// char name to char 
void Player::setname(char a_name[9])
{
	m_name[9] = a_name[9];
}