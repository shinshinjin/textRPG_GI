#pragma once
#include"Type.h"
#include"Youtuber.h"

class EquipStore
{
public:
	string name;
	int minDamage;
	int maxDamage;
	int price;

	void EquipInfo(string name, int minDamage, int maxDamage, int price);
	void Equip(Youtuber* youtuber);

};