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

	// initialising Player variables 
	unsigned int m_score;
	char m_name[9];

	// virtual voids
	virtual void setscore(int a_score);
	virtual void setname(std::string a_newname);
	virtual void setname(char a_name[9]);
};

