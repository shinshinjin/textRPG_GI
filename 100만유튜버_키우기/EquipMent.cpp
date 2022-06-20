#include "Type.h"
#include "EquipMent.h"
#include "Youtuber.h"

void EquipStore::Equip(Youtuber* youtuber)
{
	youtuber->minDamage = youtuber->minDamage + this->minDamage;
	youtuber->maxDamage = youtuber->maxDamage + this->maxDamage;
}

void EquipStore::EquipInfo(string name, int minDamage, int maxDamage, int price)
{
	this->name = name;			 //이름
	this->minDamage = minDamage; //데미지
	this->maxDamage = maxDamage;
	this->price = price;	     //가격
}
