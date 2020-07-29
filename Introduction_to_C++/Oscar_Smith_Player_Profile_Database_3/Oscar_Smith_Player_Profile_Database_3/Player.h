#pragma once
#include <string.h>
#include <iostream>

// player class
class Player
{
public:
	// constructor and deconstructor call
	Player();
	~Player();

	// virtual voids
	void SetScore(int a_score);

	void SetName(char a_name[4]);
	
	int GetScore();

	char* GetName();

	// initialising Player variables 
	unsigned int m_score;
	char m_name[4];

};

