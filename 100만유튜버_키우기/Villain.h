#pragma once
#include "Type.h"
#include <vector>
using namespace std;

class Youtuber;

class Villain
{
public:	

	string name;
	string villainSize;
	int mental;
	int minDamage;
	int maxDamage;
	int money;
	int _randomDamege;
	int AbuseCountVillain = 1;
	int LongWritingCountVillain = 1;
	int D_R_PromotionCountVillain = 1;

	Villain(string name, string villainSize, int mental, int minDamage, int maxDamage, int money);

	void setVillain(string name, string vllainSize, int mental, int minDamage, int maxDamage, int money);

	void villainAttack(Youtuber* youtuber, Villain* villain);

	void ShowVillainInfo();
};

