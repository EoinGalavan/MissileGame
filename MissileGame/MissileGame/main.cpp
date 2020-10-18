#include <stdlib.h>
#include <time.h>
#include <iostream>

void selectWarhead();
void acquireTarget();
void launchCode();
void armMissile();
bool collision();
void destroyTarget();
bool viable();
void deactivate();

bool gameOver = false;
int targetX = 0;
int targetY = 0;
int aimX = 0;
int aimY = 0;
int ammo = 3;
int missileType = 0;

int main()
{
	while (!gameOver)
	{
	selectWarhead();
	acquireTarget();
	launchCode();
	armMissile();
	if (collision())
	{
		destroyTarget();
	}
	else if (!viable())
	{
		deactivate();
	}
	}
}

void selectWarhead()
{
	std::cout << "What Missile do you want?" << std::endl << "1 - Line" << std::endl << "2 - Spread" << std::endl;
	std::cin >> missileType;
}

void acquireTarget()
{
	srand(time(NULL));
	targetX = rand() % 5 + 1;
	targetY = rand() % 5 + 1;
}

void launchCode()
{
	std::cout << "What is the X coordinate of your target?(1-5)" << std::endl;
	std::cin >> aimX;
	std::cout << "What is the Y coordinate of your target?(1-5)" << std::endl;
	std::cin >> aimY;
}

void armMissile()
{
	std::string code = "";
	while (code != "FIRE")
	{
		std::cout << "type \"FIRE\" to fire the missile" << std::endl;
		std::cin >> code;
	}
}

bool collision()
{
	ammo -= 1;
	bool hit = false;
	switch (missileType)
	{
	case 1:
		if (aimX == targetX || aimY == targetY)
		{
			hit = true;
		}
		break;
	case 2: 
		if (targetX >= (aimX - 1) && targetX <= (aimX + 1) && targetY >= (aimY - 1) && targetY <= (aimY + 1))
		{
			hit = true;
		}
		break;
	default:
		std::cout << "seems you chose an invalid missile and wasted your ammo" << std::endl;
		break;
	}
	return hit;
}

void destroyTarget()
{
	std::cout << "You hit the target at " << targetX << "," << targetY << " congragulations!!" << std::endl;
	gameOver = true;
}

bool viable()
{
	bool viable = true;
	if (ammo <= 0)
	{
		viable = false;
	}
	return viable;
}

void deactivate()
{
	gameOver = true;
}
