#include "Entity.h"

Entity::Entity()
{
}

int Entity::attack() { return 0; };
void Entity::takeDamage(int damage) {};

Entity::~Entity()
{
}

bool Entity::isAlive()
{
	if (health <= 0)
	{
		return health = 0;
	}
	else
	{
		return true;
	}
}
