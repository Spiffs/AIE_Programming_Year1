#include "Marine.h"

Marine::Marine()
{
	int _health = Marine::gethealth();
	_health = 50;

	Marine::sethealth(_health);
}

Marine::~Marine()
{
}

int Marine::attack()
{
	return 10;
}

void Marine::takeDamage(int damage)
{
	int _health = Marine::gethealth();
	_health -= damage;

	Marine::sethealth(_health);
}
