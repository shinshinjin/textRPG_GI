#include "Type.h"
#include "Color.h"
#include "Youtuber.h"
#include "Villain.h"
#include "DrinkStore.h"
#include "EquipMent.h"

using namespace std;

// 색깔을 지정해준다.
Color color;
enum
{
	BLACK,
	DARK_BLUE,
	DARK_GREEN,
	DARK_SKYBLUE,
	DARK_RED,
	DARK_VOILET,
	DAKR_YELLOW,
	GRAY,
	DARK_GRAY,
	BLUE,
	GREEN,
	SKYBLUE,
	RED,
	VIOLET,
	YELLOW,
	WHITE,
};

// 유튜버 vs 개청자
void BattleSet(Villain* villain, Youtuber* youtuber)
{
	int selBattle;
	while (true)
	{
		system("cls");
		cout << "       개청자를 쫓아내자!! " << endl << endl;
		cout << "┌───────────────────────────────────────┐" << endl;
		cout << "              야생의 " << villain->name << " 스텟 " << endl;
		cout << "└───────────────────────────────────────┘" << endl;
		cout << "        " << villain->name << "의 멘탈 :  ";
		color.setColor(GREEN);
		cout << villain->mental << endl;
		color.setColor(WHITE);
		cout << "        " << villain->name << "의 말빨 :  " << villain->minDamage << " ~ " << villain->maxDamage << endl << endl;
		cout << "└───────────────────────────────────────┘" << endl;

		cout << "┌───────────────────────────────────────┐" << endl;
		cout << "              유튜버 " << youtuber->name << " 스텟 " << endl;
		cout << "└───────────────────────────────────────┘" << endl;
		cout << "        " << youtuber->name << "의 멘탈 :   ";
		color.setColor(GREEN);
		cout << youtuber->mental << endl;
		color.setColor(WHITE);
		cout << "        " << youtuber->name << "의 말빨 :  " << youtuber->minDamage << " ~ " << youtuber->maxDamage << endl << endl;
		cout << "└───────────────────────────────────────┘" << endl;

		cout << "┌───────────────────┬───────────────────┐" << endl;
		cout << "│   채팅창검열  [0]" << " │   무시하기  [1]   │" << endl;
		cout << "│                   │                   │" << endl;
		cout << "└───────────────────────────────────────┘" << endl;

		cin >> selBattle;
		switch (selBattle)
		{
		case 0:
		{
			color.setColor(RED);
			youtuber->Attack(villain, youtuber);
			// 랜덤 함수를 이용해서 데미지 값 입력
			cout << "┌───────────────────────────────────────┐" << endl;
			cout << youtuber->name << "의 채팅창검열" << endl;
			Sleep(1000);
			cout << villain->name << " 에게 ";
			color.setColor(SKYBLUE);
			cout << youtuber->_randomDamege;
			color.setColor(WHITE);
			cout << " 만큼 멘탈을 부숴버렸습니다." << endl << endl;
			Sleep(1000);

			color.setColor(YELLOW);
			cout << villain->name << "의 무-빙" << endl;
			Sleep(1000);
			color.setColor(WHITE);
			villain->villainAttack(youtuber, villain);
			cout << youtuber->name << " 에게 ";
			color.setColor(SKYBLUE);
			cout << villain->_randomDamege;
			color.setColor(WHITE);
			cout << "  만큼 멘탈이 부서졌습니다.." << endl;
			cout << "└───────────────────────────────────────┘" << endl;
			Sleep(1200);


			system("cls");

			//몬스터 사망시 돈 획득
			if (villain->mental <= 0)
			{

				cout << "┌───────────────────────────────────────┐" << endl;
				color.setColor(WHITE);
				cout << "   " << villain->name << "이 강퇴 당했습니다." << endl;
				youtuber->money = villain->money + youtuber->money;
				cout << "   " << "  강제 후원으로 " << villain->money << "  원 받았습니다." << endl;
				cout << "└───────────────────────────────────────┘" << endl;
				color.setColor(WHITE);

				return;
			}

			//유튜버 사망시 돈유무에 따라 방송할지, 다른일 할지
			else if (youtuber->mental <= 0)
			{
				cout << endl;
				cout << "   " << youtuber->name << "이 방종 했습니다." << endl;
				cout << endl;
				if (youtuber->money >= 250)
				{
					youtuber->money = youtuber->money - 250;
					cout << "100원으로 방송을 킬 체력을 회복 했습니다!!" << endl;
					youtuber->mental = (youtuber->mental * 0) + 500;
					return;
				}
				else
				{
					cout << endl;
					cout << "          그냥 방송말고 다른일이나 찾아보자..." << endl << endl;
					cout << "┌───────────────────────────────────────┐" << endl;
					cout << "│            G A M E O V E R            │ " << endl;
					cout << "└───────────────────────────────────────┘" << endl;

					color.setColor(WHITE);
					return;
				}
			}
			break;
		}
		// 그만두고 나가기.
		case 1:
		{
			system("cls");
			return;
		}
		}
	}
}

// 드링크 상점
void Drink_(Youtuber* youtuber)
{
	int drink_choice = 0;
	system("cls");

	color.setColor(WHITE);
	Sleep(500);
	cout << "┌───────────────────────────────────────────────┐" << endl;
	cout << "│        방송으로 인한 피곤함을 달래주지...     │" << endl;
	cout << "└───────────────────────────────────────────────┘" << endl;

	DrinkStore potionStore;
	cout << "                  드링크 상점        " << endl;
	cout << "┌───────────────────────────────────────────────┐" << endl;
	cout << "│  " << youtuber->name << "의 돈   : " << youtuber->money << endl;
	cout << "│  " << youtuber->name << "의 멘탈 : " << youtuber->mental << endl;
	cout << "│  " << endl;
	while (true)
	{
		cout << "│  " << "GS25다.. 저 둘중에 그냥 고르자." << endl;
		cout << "│  " << "구매할 드링크를 선택하세요" << endl;
		cout << "│  " << endl;
		cout << "│  " << "1) 핫식스  $50  ";
		cout << "    + 100 " << endl;
		cout << "│  " << "2) 몬스터X $200";
		cout << "     + 500 " << endl;
		cout << "│  " << "3) 나가기" << endl;
		cout << "└───────────────────────────────────────────────┘" << endl;

		cout << " 뭘 마실까?  ";
		cin >> drink_choice;
		cout << "│  " << endl;
		if (drink_choice == 1)
		{
			if (youtuber->money >= 50)
			{
				potionStore.DrinkInfo("핫식스", 100, 50);
				potionStore.Drink(youtuber);
				cout << "│ " << youtuber->name << "의 멘탈이 " << potionStore.hill << " 회복 되었습니다." << endl;
				youtuber->money = youtuber->money - potionStore.price;
				cout << "│ " << youtuber->money << "원 남았습니다." << endl;
				cout << "└───────────────────────────────────────────────┘" << endl;

				system("pause");
				system("cls");
			}
			else
			{
				cout << "돈이 부족합니다" << endl;
				break;
			}
			break;
		}
		else if (drink_choice == 2)
		{
			if (youtuber->money >= 90)
			{
				potionStore.DrinkInfo("몬스타X", 500, 200);
				potionStore.Drink(youtuber);
				cout << "│ " << youtuber->name << " 의 멘탈이 " << potionStore.hill << " 회복 되었습니다." << endl;
				youtuber->money = youtuber->money - potionStore.price;
				cout << "│ " << youtuber->money << " 원 남았습니다." << endl;
				cout << "└───────────────────────────────────────────────┘" << endl;

				system("pause");
				system("cls");
			}
			else
			{
				cout << "돈이 부족합니다" << endl;
				break;
			}
			break;
		}
		else
		{
			break;
		}

		cout << endl << endl;
		break;
	}
	return;
}

// 장비 상점
void Equip_(Youtuber* youtuber)
{
	EquipStore equipStore;
	int equip_choice = 0;   // 장비 구매창에서 선택
	int enforce_choice = 0; // 장비 강화창에서 선택
	string random_image[3] = { "■□■□■□■□■□ 강화 진행중 ■□■□■□■□■□", "□■□■□■□■□■ 강화 진행중 □■□■□■□■□■", "■□■□■□■□■□ 강화 진행중 ■□■□■□■□■□" };

	system("cls");
	Sleep(500);
	cout << "┌───────────────────────────────────────┐" << endl;
	cout << "│         방송은 장비 빨이지~           │ " << endl;
	cout << "└───────────────────────────────────────┘" << endl;

	Sleep(700);
	cout << "              장비 스토어        " << endl;
	cout << "┌─────────────────────────────────────────────────────────────────┐" << endl;
	cout << "│ " << "▷▷▷ " << youtuber->name << "의 소지금 : " << youtuber->money << " ◁◁◁" << endl;
	cout << "│ " << endl;

	while (true)
	{
		cout << "│ " << "장비 스토어에 오신걸 환영합니다." << endl;
		cout << "│ " << "어떤 장비를 구매하시겠습니까? " << endl;
		cout << "│ " << endl;

		cout << "│ " << "1)  10만 유튜버가 쓰던 방송장비  $1000" << endl;
		cout << "│ " << "최소사양 : +10     최대사양 : +50" << endl;
		cout << "├ " << " 일반적인 컴퓨터 사양입니다.." << endl;
		cout << "│ " << endl;

		cout << "│ " << "2)  50만 유튜버가 쓰던 방송장비  $5000" << endl;
		cout << "│ " << "최소사양 : +80     최대사양 : +200" << endl;
		cout << "├ " << " 고사양으로 장착된 장비입니다. 노력 더하면 100만 가능한 장비인듯? " << endl;
		cout << "│ " << endl;

		cout << "│ " << "3.☞☞☞☞장비 업그레이드 하기☜☜☜☜" << endl;
		cout << "│ " << endl;

		color.setColor(WHITE);
		cout << "│ " << "4.나가기" << endl;
		cout << "└─────────────────────────────────────────────────────────────────┘" << endl;

		cin >> equip_choice;
		system("cls");
		//10만 방송장비
		if (equip_choice == 1)
		{
			equipStore.EquipInfo("10만 유튜버가 쓰던 방송장비", 10, 50, 1000);
			if (youtuber->money >= 1000)
			{
				cout << "┌───────────────────────────────────────┐" << endl;
				cout << "│ 호갱(을) 해버렸다!" << endl;
				cout << "│ " << endl;
				equipStore.Equip(youtuber);
				cout << "│ " << youtuber->name << "의 최소 사양이 " << equipStore.minDamage << " 상승 되었습니다." << endl;
				cout << "│ " << youtuber->name << "의 최대 사양이 " << equipStore.maxDamage << " 상승 되었습니다." << endl;
				youtuber->money = youtuber->money - equipStore.price;
				cout << "│ " << youtuber->money << "원 남았습니다." << endl;
				cout << "└───────────────────────────────────────┘" << endl;

				break;
			}
			else
			{
				cout << "-------------------------------------- " << endl;
				color.setColor(GREEN);
				Sleep(700);

				cout << "다나와에 장비를 주문 했습니다.";
				Sleep(700);

				cout << "음..............";
				Sleep(500);

				cout << "어...어라...?...." << endl;
				Sleep(1500);

				color.setColor(BLUE);
				cout << "10만 유튜버가 쓰던 방송장비 ";

				color.setColor(GREEN);
				cout << "를 살 돈이 없잔슴~" << endl;
				Sleep(700);

				cout << "                  에바잔슴~ 돈 구해오셈~" << endl;
				Sleep(300);

				color.setColor(WHITE);
				cout << "-------------------------------------- " << endl;
				Sleep(200);

				break;
			}
			break;
		}
		//50만 장비
		else if (equip_choice == 2)
		{
			equipStore.EquipInfo("50만 유튜버가 쓰던 방송장비", 50, 270, 5000);
			if (youtuber->money >= 5000)
			{
				cout << "┌───────────────────────────────────────┐" << endl;
				cout << "│ 호갱(을) 해버렸다!" << endl;
				cout << "│ " << endl;
				equipStore.Equip(youtuber);
				cout << "│ " << youtuber->name << "의 최소 사양 :  " << equipStore.minDamage << " 상승 되었습니다." << endl;
				cout << "│ " << youtuber->name << "의 최대 사양 :  " << equipStore.maxDamage << " 상승 되었습니다." << endl;
				youtuber->money = youtuber->money - equipStore.price;
				cout << "│ " << youtuber->money << "원 남았습니다." << endl;
				cout << "└───────────────────────────────────────┘" << endl;

				break;
			}
			else
			{
				cout << "-------------------------------------- " << endl;
				color.setColor(GREEN);
				Sleep(700);

				cout << "다나와에 장비를 주문 했습니다.";
				Sleep(700);

				cout << "음..............";
				Sleep(500);

				cout << "어...어라...?...." << endl;
				Sleep(1500);

				color.setColor(BLUE);
				cout << "50만 유튜버가 쓰던 방송장비 ";

				color.setColor(GREEN);
				cout << "를 살 돈이 없잔슴~" << endl;
				Sleep(700);

				cout << "                  에바잔슴~ 돈 구해오셈~" << endl;
				Sleep(300);

				color.setColor(WHITE);
				cout << "-------------------------------------- " << endl;
				Sleep(200);

				break;
			}
			break;
		}
		//강화시스템
		else if (equip_choice == 3)
		{
			while (true)
			{
				cout << "┌─────────────────────────────────────────────────────────────────┐" << endl;
				cout << "│ " << "▷▷▷ " << youtuber->name << "의 소지금 :" << youtuber->money << " ◁◁◁" << endl;
				cout << "│ " << endl;
				cout << "│ " << youtuber->name << "의 말빨 : " << youtuber->minDamage << " ~ " << youtuber->maxDamage << " 말빨 " << endl;
				cout << "│ " << "참고로 말빨 = 장비빨이 됩니다." << endl;
				cout << "│ " << endl;
				cout << "│ ★★★  장비를 강화해보자..! 100원만 투자하면 더 강해질 수 있다고~  ★★★" << endl;
				cout << "│ " << endl;
				cout << "│ S급 성공확률 : 10 % " << endl;
				cout << "│ A급 성공확률 : 50 % " << endl;
				cout << "│ A급 실패확률 : 35 % " << endl;
				cout << "│ S급 실패확률 : 5  % " << endl;
				cout << "│" << endl;
				cout << "│    최소 데미지 강화  [1] " << endl;
				cout << "│    최대 데미지 강화  [2] " << endl;
				cout << "│    강화 나가기       [3] " << endl;
				cout << "└─────────────────────────────────────────────────────────────────┘" << endl;

				cout << " 선택 : ";
				cin >> enforce_choice;
				cout << endl;

				//돈이 부족할시 브레이크
				system("cls");
				if (youtuber->money < 100)
				{
					color.setColor(RED);
					cout << "      너. 없다. 돈. 가라.       " << endl << endl;
					system("pause");
					system("cls");
					Sleep(1000);
					color.setColor(WHITE);
					break;
				}
				//최소데미지는 최대데미지를 넘을수없습니다.
				if (youtuber->minDamage > youtuber->maxDamage)
				{
					color.setColor(RED);
					cout << "최소 데미지는 최대 데미지를 넘을수 없습니다." << endl;
					Sleep(1500);
					break;
				}
				//데미지는 -가 될수 없습니다.
				else if (youtuber->minDamage < 0 && youtuber->maxDamage < 0)
				{
					color.setColor(RED);
					cout << "데미지는 - 가 될수 없습니다." << endl;
					Sleep(1500);
					break;
				}
				//최소 데미지 업그레이드
				if (enforce_choice == 1)
				{
					for (int i = 0; i < 3; i++)
					{
						cout << random_image[i] << endl << endl;
						Sleep(1000);
					}

					random_device rd;
					mt19937 gen(rd());
					uniform_int_distribution<int> _equipUp(1, 103);


					int equipUp = _equipUp(gen);
					//50프로
					if (equipUp <= 50)// 
					{
						cout << "          A급 성공!       +5 SpeechPOWER" << endl;
						youtuber->minDamage += 5;
						youtuber->money -= 100;
						Sleep(500);
					}
					//10프로
					else if (51 <= equipUp && equipUp <= 61)
					{
						color.setColor(SKYBLUE);
						cout << "          S급 대성공!!!! +20 SpeechPOWER" << endl;
						youtuber->minDamage += 20;
						youtuber->money -= 100;
						color.setColor(WHITE);
						Sleep(500);
					}
					//35프로
					else if (62 <= equipUp && equipUp <= 97)
					{

						cout << "          A급 실패..      -3 SpeechPOWER" << endl;
						youtuber->minDamage -= 3;
						youtuber->money -= 100;
						//0보다 작아질시 다시 1로 초기화.
						if (youtuber->minDamage <= 0)
						{
							youtuber->minDamage = 1;
							cout << "말빨이 음수로 떨어져서 1로 초기화 되었습니다." << endl << endl;
						}
						Sleep(500);
					}
					//5프로
					else if (98 <= equipUp && equipUp <= 103)
					{
						color.setColor(RED);
						cout << "        S급 실패.....ㅠ   -15 SpeechPOWER " << endl;
						color.setColor(WHITE);
						youtuber->minDamage -= 15;
						youtuber->money -= 100;
						//0보다 작아질시 다시 1로 초기화.
						if (youtuber->minDamage <= 0)
						{
							youtuber->minDamage = 1;
							cout << "말빨이 음수로 떨어져서 1로 초기화 되었습니다." << endl << endl;
						}
						Sleep(500);
					}
					Sleep(1500);
					system("cls");
				}
				//최대 데미지 업그레이드
				if (enforce_choice == 2)
				{
					for (int i = 0; i < 3; i++)
					{
						cout << random_image[i] << endl << endl;
						Sleep(1000);
					}

					random_device rd;
					mt19937 gen(rd());
					uniform_int_distribution<int> _equipUp(1, 103);
					int equipUp = _equipUp(gen);

					//50프로
					if (equipUp <= 50)
					{
						cout << "          A급 성공!       +5 SpeechPOWER" << endl;
						youtuber->maxDamage += 5;
						youtuber->money -= 100;
						Sleep(500);
					}
					//10프로
					else if (51 <= equipUp && equipUp <= 61)
					{
						color.setColor(SKYBLUE);
						cout << "          S급 대성공!!!! +20 SpeechPOWER" << endl;
						youtuber->maxDamage += 20;
						youtuber->money -= 100;
						color.setColor(WHITE);
						Sleep(500);
					}
					//35프로
					else if (62 <= equipUp && equipUp <= 97)
					{
						cout << "          A급 실패..      -3 SpeechPOWER" << endl;
						youtuber->maxDamage -= 3;
						youtuber->money -= 100;
						//0보다 작아질시 다시 1로 초기화.
						if (youtuber->minDamage <= 0)
						{
							youtuber->minDamage = 1;
							cout << "말빨이 음수로 떨어져서 1로 초기화 되었습니다." << endl << endl;
						}
						Sleep(500);
					}
					//5프로
					else if (98 <= equipUp && equipUp <= 103)
					{
						color.setColor(RED);
						cout << "        S급 실패.....ㅠ   -15 SpeechPOWER " << endl;
						color.setColor(WHITE);
						youtuber->maxDamage -= 15;
						youtuber->money -= 100;
						//0보다 작아질시 다시 1로 초기화.
						if (youtuber->minDamage <= 0)
						{
							youtuber->minDamage = 1;
							cout << "말빨이 음수로 떨어져서 1로 초기화 되었습니다." << endl << endl;
						}
						Sleep(500);
					}
					Sleep(1500);
					system("cls");
				}
				else if (enforce_choice == 3)
				{
					break;
				}
			}
		}

		else
		{
			return;
		}
		break;
		cout << endl;
	}
	return;
}

// 뭐로 시작할지
enum GAME_MODE
{
	GM_MAIN,  // 0
	GM_START, // 1
	GM_END,   // 2
};

int main()
{
	// 변수 선언
	string name;				// 방송닉네임
	Youtuber youtuber_new;
	int GameMode = 0;			// 0, 1, 2 -> 게임 모드
	int MenuChoice = 0;			// 메뉴 선택 키
	int InfoChoice = 0;		    // 게임 정보 내 선택 키 
	int FightMenu = 0;          // 개청자 난입했을 때 
	int Store_Selection = 0;    // 상점 선택 키
	int Coin_Selection = 0;		// 코인장 선택 키
	string egg[3] = { "노우진", "NowooJin", "shdnwls"};	// 이스터에그
	string loading[10] = { "■", "■■", "■■■", "■■■■", "■■■■■", "■■■■■■", "■■■■■", "■■■■", "■■■", "■■", };

	// 개청자 선언
	vector<Villain*> villains;
	villains.push_back(new Villain("(BOSS)훈수충", "틀성", 10000, 100, 500, 50000));
	villains.push_back(new Villain("도배충", "악성", 1000, 25, 100, 2500));
	villains.push_back(new Villain("다른방 홍보충", "악성", 250, 10, 50, 500));
	villains.push_back(new Villain("욕설충", "악성", 100, 5, 20, 50));

	// 첫 타이틀 구성
	while (GameMode <= GM_MAIN || GameMode > GM_END)
	{
		color.setColor(YELLOW);
		cout << "■■■■■ ";
		color.setColor(SKYBLUE);
		cout << "100만 유튜버 키우기";
		color.setColor(YELLOW);
		cout << " ■■■■■" << endl;
		color.setColor(WHITE);
		cout << endl;
		cout << "┌───────────────────────────────────────┐" << endl;
		cout << "│            1.   시작한다.             │ " << endl;
		cout << "│            2.   종료한다.             │ " << endl;
		cout << "│                                       │ " << endl;
		cout << "│          나도 100만 유튜버?!          │ " << endl;
		cout << "└───────────────────────────────────────┘" << endl;
		cin >> GameMode;
		system("cls");
	}
	// 종료
	if (GameMode == GM_END) { return 0; }
	// 시작
	if (GameMode == GM_START)
	{
		cout << "┌───────────────────────────────────────┐" << endl;
		cout << "│			                │" << endl;
		cout << "│   당신의 유튜버 닉네임을 입력하세요   │" << endl;
		cout << "└───────────────────────────────────────┘" << endl;
		cin >> name;

		youtuber_new.name = name;

		if (name == egg[0] || name == egg[1] || name == egg[2])
		{
			system("cls");
			cout << "┌───────────────────────────────────────┐" << endl;
			cout << endl;
			cout << "   아, 이게임은 노우진은 할 수 없습니다." << endl;
			cout << endl;
			cout << "└───────────────────────────────────────┘" << endl;
			return 0;
		}
		system("cls");

		// 유튜버 정보 확인
		cout << "┌───────────────────────────────────────┐" << endl;
		cout << "│       이름    : " << youtuber_new.name << "\n";
		cout << "│       멘탈    : " << youtuber_new.mental << "\n";
		cout << "│       말빨    : " << youtuber_new.minDamage << " ~ " << youtuber_new.maxDamage << "\n";
		cout << "│       자금    : " << youtuber_new.money << "\n";
		cout << "└───────────────────────────────────────┘" << endl;
		color.setColor(WHITE);
	}

	// 메인 메뉴
	while (true)
	{   // 개청자 처리시 게임 종료
		if (villains[0]->mental <= 0)
		{
			cout << "            개청자를 처리했다." << endl;
			cout << "  휴~ 오늘 방송 여기까지 하겠습니다~ " << endl;
			return 0;
		}
		// 개청자 한테 처리 당하면..
		if (youtuber_new.mental <= 0)
		{
			cout << "개청자가 너무 날뛰어서 강제 방종 되었습니다." << endl;
			return 0;
		}
		// 기본 선택창
		cout << "┌───────────────────────────────────────┐" << '\n';
		cout << "│     게임 정보 보기     ";
		color.setColor(GREEN);
		cout << "    0";
		color.setColor(WHITE);
		cout << "          │" << endl;

		cout << "┌───────────────────────────────────────┐" << '\n';
		cout << "│     유튜브 방송 하기      ";
		color.setColor(GREEN);
		cout << " 1";
		color.setColor(WHITE);
		cout << "          │" << endl;

		cout << "┌───────────────────────────────────────┐" << '\n';
		cout << "│     스토어 구경하기       ";
		color.setColor(GREEN);
		cout << " 2";
		color.setColor(WHITE);
		cout << "          │" << endl;

		cout << "┌───────────────────────────────────────┐" << '\n';
		cout << "│     코인 하기     ";
		color.setColor(GREEN);
		cout << "         3";
		color.setColor(WHITE);
		cout << "          │" << endl;


		cout << "┌───────────────────────────────────────┐" << '\n';
		cout << "      게임 종료      ";
		color.setColor(GREEN);
		cout << "        4" << endl;
		color.setColor(WHITE);
		cout << "└───────────────────────────────────────┘" << endl;

		cin >> MenuChoice;
		system("cls");

		switch (MenuChoice)
		{
			// 게임 정보 보기
		case 0:
		{
			while (true)
			{
				color.setColor(BLUE);
				cout << "           ☆☆☆☆ 게임 오버 조건 : 유튜버 강제 방종☆☆☆☆ " << '\n';
				cout << endl;
				cout << "             ☆☆☆☆ 게임 승리 조건 : 개청자 처단 ☆☆☆☆ " << '\n';
				color.setColor(WHITE);
				cout << endl;
				cout << "         ☞ 멘탈이 0이 되면 강제방종 합니다." << '\n';
				cout << "         ☞ 다시 방송을 키려면 100원을 후원하고 부활할 수 있습니다." << '\n';
				cout << "         ☞ 멘탈을 올리고 말빨을 업그레이드 해서 개청자들을 물리치세요." << '\n';
				cout << endl;

				cout << "┌───────────────────────────────────────┐" << endl;
				cout << "└───────────────────────────────────────┘" << endl;

				cout << "│               내 유튜브               │" << '\n';
				cout << "└───────────────────────────────────────┘" << endl;

				youtuber_new.Youtuberinfo();

				cout << "│             메인 메뉴로               │ " << '\n' << "│ ";
				color.setColor(GREEN);
				cout << " 0 ~ 9중    아무 키나 누르세요... ";
				color.setColor(WHITE);
				cout << "    │ " << endl;
				cout << "├───────────────────────────────────────┤" << endl;


				cin >> InfoChoice;
				system("cls");

				// 다시 메인메뉴로 전환
				switch (InfoChoice)
				{
				case 1:
				{
					break;
				}
				break;

				case 9:
				{
					for (int i = 0; i < 10; i++)
					{
						cout << "롤 하고 싶당 ㅎㅎ" << loading[i] << endl;
						Sleep(200);
					}
					system("cls");
				}
				break;
				}
				break;
			}
			break;
		}
		// 방송 메뉴
		case 1:
		{
			while (true)
			{

				cout << "┌──────────────────────────────────────────────────────────────────────────┐" << '\n';
				cout << "│              방송하는데 개청자들이 난입했다! 누굴 쳐낼까....             │   " << '\n';
				cout << "│                                                                          │   " << '\n';
				cout << "│ 1.(BOSS)훈수충 2.도배충 3.다른방송 홍보충 4.욕설충 5.그냥 사이좋게 지내자│  " << '\n';
				cout << "└──────────────────────────────────────────────────────────────────────────┘" << endl;

				//개청자가 죽었을시 hp 회복	
				//도배충이 사망시 카운트가 올라서 도배충의 멘탈이 100씩 증가하고 부활한다.

				if (villains[1]->mental <= 0)
				{
					villains[1]->mental = 500 + (100 * (villains[1]->LongWritingCountVillain++));
					villains[1]->minDamage = 30 + (10 * villains[1]->LongWritingCountVillain++);
					villains[1]->maxDamage = 100 + (10 * villains[1]->LongWritingCountVillain++);

				}
				//욕설충이 사망시 데미지 2+ 씩 증가하고 부활한다.
				if (villains[2]->mental <= 0)
				{
					villains[2]->mental = +200;
					villains[2]->minDamage = 10 + (2 * villains[2]->AbuseCountVillain++);
					villains[2]->maxDamage = 40 + (2 * villains[2]->AbuseCountVillain++);
				}
				//다른방송 홍보충이 사망시 멘탈이 20씩 증가하고 부활한다.
				if (villains[3]->mental <= 0)
				{
					villains[3]->mental = 100 + (20 * villains[1]->D_R_PromotionCountVillain++);
				}

				string E_mark[10] = { "!", "!", "!", "!", "!", "!", "!", "!", "!", "!" };

				cout << "누굴 쳐낼까? : ";
				cin >> FightMenu;
				if (FightMenu == 1)
				{
					system("cls");
					cout << endl;
					cout << endl;
					cout << "           보스전!";
					for (int i = 0; i < 10; i++)
					{
						cout << E_mark[i];
						Sleep(200);
					}
				}
				//선택시 배틀 메뉴로 들어가기
				switch (FightMenu)
				{
				case 1:
				{
					BattleSet(villains[0], &youtuber_new);
					break;
					return 0;
				}
				case 2:
				{
					BattleSet(villains[1], &youtuber_new);
					break;
				}
				case 3:
				{
					BattleSet(villains[2], &youtuber_new);
					break;
				}
				case 4:
				{
					BattleSet(villains[3], &youtuber_new);
					break;
				}
				case 5:
				{
					break;
				}
				break;
				}
				break;
			}
			break;
		}
		case 2: // 상점 메뉴
		{
			while (true)
			{
				cout << "┌───────────────────────────────────────────────────┐" << endl;
				cout << "│                      상점 메뉴                    │             " << '\n';
				cout << "│                                                   │             " << '\n';
				cout << "│  1. 드링크 스토어     2.다나와      3.메인메뉴    │" << '\n';
				cout << "└───────────────────────────────────────────────────┘" << endl;

				cin >> Store_Selection;
				switch (Store_Selection)
				{
					//포션 상점으로
				case 1:
				{
					Drink_(&youtuber_new);
					break;
				}
				//화살 상점으로
				case 2:
				{
					Equip_(&youtuber_new);
					break;
				}
				//메인 메뉴로
				case 3:
				{
					break;
				}
				}
				break;
			}
			break;
		}
		/*case 3:
		{
			cout << "코인이 망해가지고~.. 서비스 종료다." << endl;
			system("pause");
			system("cls");
			Sleep(1400);
			break;
		}*/

		case 3: // 코인 떡상 가즈아~
		{
			Youtuber youtuber;

			while (true)
			{
				cout << "┌───────────────────────────────────────────────────────────────┐" << endl;
				cout << "│       ⓓ 안녕하세요? 다운비트에 오신 것을 환영합니다. ⓓ      │ " << endl;
				cout << "│                                                               │ " << endl;
				cout << "│                저희는 3종류의 코인이 있습니다.                │ " << endl;
				cout << "│     코인을 사시면 5초뒤에 자동으로 팔리며, 값은 랜덤입니다    │ " << endl;
				cout << "│                                                               │ " << endl;
				cout << "│   1. Penguin_Coin	   2. HaeDal_Coin	   3. Gal_Coin  │ " << endl;
				cout << "│   : 100 원	           : 500 원	           : 1000원     │ " << endl;
				cout << "│                                                               │ " << endl;
				cout << "└───────────────────────────────────────────────────────────────┘" << endl;

				cout << endl;
				cout << "참고로 나가기는 4를 입력하세요.";
				cout << endl;
				cout << "어떤 코인을 구매하시겠습니까?: " << endl;
				cin >> Coin_Selection;


				if (Coin_Selection == 1)
				{
					system("cls");
					cout << "┌───────────────────────────────────────────────────────────────┐" << endl;
					cout << "│                                                               │ " << endl;
					cout << "│ " << "        고른 코인이 상장폐지가 되어서 망했습니다....          │ " << endl;
					cout << "│                                                               │ " << endl;
					cout << "└───────────────────────────────────────────────────────────────┘" << endl;
					return 0;
				}

				else if (Coin_Selection == 2)
				{
					system("cls");
					cout << "┌───────────────────────────────────────────────────────────────┐" << endl;
					cout << "│                                                               │ " << endl;
					cout << "│ " << "        고른 코인이 상장폐지가 되어서 망했습니다....          │ " << endl;
					cout << "│                                                               │ " << endl;
					cout << "└───────────────────────────────────────────────────────────────┘" << endl;
					return 0;
				}

				else if (Coin_Selection == 3)
				{
					system("cls");
					cout << "┌───────────────────────────────────────────────────────────────┐" << endl;
					cout << "│                                                               │ " << endl;
					cout << "│ " << "        고른 코인이 상장폐지가 되어서 망했습니다....          │ " << endl;
					cout << "│                                                               │ " << endl;
					cout << "└───────────────────────────────────────────────────────────────┘" << endl;
					return 0;
				}

				else if (Coin_Selection == 4)
				{
					system("cls");
					break;
				}
				break;
			}
			break;
		}
		// 게임 종료
		case 4:
		{
			cout << endl;
			cout << endl;
			cout << "┌───────────────────────────────────────┐" << '\n';
			cout << "      이거 저장안되는데 종료 해버리기~" << endl;
			cout << "└───────────────────────────────────────┘" << endl;

			return 0;
		}
		break;
		}

	}

}

