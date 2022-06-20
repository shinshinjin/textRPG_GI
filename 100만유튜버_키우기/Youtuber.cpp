#include "Youtuber.h"
#include "Villain.h"


void Youtuber::Attack(Villain* villain, Youtuber* youtuber)
{
	random_device rd;
	mt19937 gen(rd());
	uniform_int_distribution<int> dis(minDamage, youtuber->maxDamage);
	youtuber->_randomDamege = dis(gen);
	villain->mental = villain->mental - youtuber->_randomDamege;
}
void Youtuber::Youtuberinfo()
{
	cout << "忙式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式忖" << endl;
	cout << "弛       檜葷 : " << this->name << endl;
	cout << "弛       詮驍 : " << this->mental << endl;
	cout << "弛       蜓說 : " << this->minDamage << " ~ " << this->maxDamage << endl;
	cout << "弛       濠旎 : " << this->money << endl;
	cout << "戌式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式戎" << endl;


}