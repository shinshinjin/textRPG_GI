#include "Villain.h"
#include "Youtuber.h"

Villain::Villain(string name, string villainSize, int mental, int minDamage, int maxDamage, int money)
{
	this->name = name;
	this->villainSize = villainSize;
	this->mental = mental;
	this->minDamage = minDamage;
	this->maxDamage = maxDamage;
	this->money = money;
}
void Villain::setVillain(string name, string villainSize, int mental, int minDamage, int maxDamage, int money)
{
	this->name = name;
	this->villainSize = villainSize;
	this->mental = mental;
	this->minDamage = minDamage;
	this->maxDamage = maxDamage;
	this->money = money;
}
void Villain::villainAttack(Youtuber* youtuber, Villain* villain)
{
	random_device rd;
	mt19937 gen(rd());
	uniform_int_distribution<int> dis(villain->minDamage, villain->maxDamage);
	villain->_randomDamege = dis(gen);
	youtuber->mental = youtuber->mental - villain->_randomDamege;
}

void Villain::ShowVillainInfo()
{
	cout << "-----------------------" << endl;
	cout << "  종류 : " << this->villainSize << endl;
	cout << "  이름 : " << this->name << endl;
	cout << "  멘탈 : " << this->mental << endl;
	cout << "  채팅력 : " << this->minDamage << " ~ " << this->maxDamage << endl;
	cout << "  현금 : " << this->money << endl;
	cout << "-----------------------" << endl;
}
