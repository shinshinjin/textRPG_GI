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
	cout << "  ���� : " << this->villainSize << endl;
	cout << "  �̸� : " << this->name << endl;
	cout << "  ��Ż : " << this->mental << endl;
	cout << "  ä�÷� : " << this->minDamage << " ~ " << this->maxDamage << endl;
	cout << "  ���� : " << this->money << endl;
	cout << "-----------------------" << endl;
}
