#include "Player.h"
#include <string.h>
#include <iostream>

void setscore(int newscore)
{
	score = newscore;
}

void setname(std::string newname)
{
	if (newname.length() == 8)
	{
		strcpy(name[8], newname.c_str());
	}
}