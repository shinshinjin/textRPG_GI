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
	cout << "����������������������������������������������������������������������������������" << endl;
	cout << "��       �̸� : " << this->name << endl;
	cout << "��       ��Ż : " << this->mental << endl;
	cout << "��       ���� : " << this->minDamage << " ~ " << this->maxDamage << endl;
	cout << "��       �ڱ� : " << this->money << endl;
	cout << "����������������������������������������������������������������������������������" << endl;


}