#include "Type.h"
#include "DrinkStore.h"
#include "Youtuber.h"


void DrinkStore::Drink(Youtuber* youtuber)
{

	youtuber->mental = youtuber->mental + this->hill;

}
void DrinkStore::DrinkInfo(string name, int hill, int price)
{
	this->name = name;
	this->hill = hill;
	this->price = price;
}
