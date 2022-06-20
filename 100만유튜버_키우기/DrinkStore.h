#pragma once
#include"Type.h"
#include"Youtuber.h"


class DrinkStore
{
public:
	string name;
	int hill = 0;
	int price = 0;

	void DrinkInfo(string name, int hill, int price);
	void Drink(Youtuber* youtuber);
};