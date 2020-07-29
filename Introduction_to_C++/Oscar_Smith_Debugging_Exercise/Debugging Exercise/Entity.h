#pragma once
class Entity
{
public:
	Entity();
	~Entity();

	virtual int attack();
	virtual void takeDamage(int damage);
	bool isAlive();



	//Set private variable
	void sethealth(int x)
	{
		health = x;
	}

	//Set private variable
	void setmaxhealth(int x)
	{
		maxHealth = x;
	}

	//Get private variable
	int gethealth()
	{
		return health;
	}

	//Get private variable
	int getmaxhealth()
	{
		return maxHealth;
	}

private:
	int health;
	int maxHealth;
};

