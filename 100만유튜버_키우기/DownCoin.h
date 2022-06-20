#pragma once
#include"Type.h"
#include"Youtuber.h"

class DownCoin
{
public:
	string name;
	int minPrice;
	int maxPrice;
	int myMoney;

	void CoinInfo(string name, int minPrice, int maxPrice, int myMoney);
	void Coin(Youtuber* youtuber);

};