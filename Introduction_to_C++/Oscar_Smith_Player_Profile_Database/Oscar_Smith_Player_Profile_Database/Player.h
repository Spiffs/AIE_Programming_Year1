#pragma once
#include <string.h>

class Player
{
public:
	unsigned int score;
	char* name[8];

	virtual void setscore(int newscore);
	virtual void setname(string newname);


};