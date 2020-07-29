#include "Zergling.h"

Zergling::Zergling()
{
}

Zergling::~Zergling()
{
}

int Zergling::attack()
{
	return 10;
}

void Zergling::takeDamage(int damage)
{
	int _health = Zergling::gethealth();
	_health -= damage;
	if (_health <= 0) 
	{
		_health = 0;
	}

	Zergling::sethealth(_health);
}
