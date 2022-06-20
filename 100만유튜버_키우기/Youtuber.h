#pragma once
#include"Type.h"

class Villain;

class Youtuber
{
public:
	string name;
	int mental = 100;
	int minDamage = 5;
	int maxDamage = 30;
	int money = 100;
	int _randomDamege;

	void Attack(Villain* villain, Youtuber* youtuber);
	void Youtuberinfo();
};