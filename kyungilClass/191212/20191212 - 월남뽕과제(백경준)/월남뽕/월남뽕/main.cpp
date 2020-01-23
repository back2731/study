#include <iostream>
#include <time.h>
#include <string>
#include <Windows.h>

using namespace std;

/*

카드게임 월남뽕게임 (CORRECT_CARDNUMBERS_COUNT장)

A 2 3 4 5 6 7 8 9 10 J Q K



게임의 룰

카드를 두 장을 랜덤으로 보여준다. 플레이어가 맞춰야 할 카드 공개



문양 4개 하트 다이아 클로버 스페이드



1. 조건 - 소지금 10,000원

2. 1000원 미만을 걸면 다시 입력

3. 종료조건 - 카드가 없을 때

*/

const int
CORRECT_CARDNUMBERS_COUNT = 52;
const int
MONEY_COUNT = 10000;

int dest, sour;
int temp1;
string temp2;
string cards[CORRECT_CARDNUMBERS_COUNT] =		// 문자열 배열

{ "♠A", "♠2", "♠3", "♠4", "♠5", "♠6", "♠7", "♠8", "♠9", "♠10", "♠J", "♠Q", "♠K",

	"◆A","◆2","◆3","◆4","◆5","◆6","◆7","◆8","◆9","◆10","◆J","◆Q","◆K",

	"♥A", "♥2", "♥3", "♥4", "♥5", "♥6", "♥7", "♥8", "♥9", "♥10", "♥J", "♥Q", "♥K",

	"♣A", "♣2", "♣3", "♣4", "♣5", "♣6", "♣7", "♣8", "♣9", "♣10", "♣J", "♣Q", "♣K" };

int cardsNum[CORRECT_CARDNUMBERS_COUNT];		// 승패 비교용 배열
int checkNum[CORRECT_CARDNUMBERS_COUNT];

int dealerA;
int dealerB;
int player;
int num;
int max, min;
int money;
int betMoney;
int goStop;

bool gamePlay = true;

void Shufflecards();	// 문자열, 승패 비교용 배열 셔플


int main()
{
	num = 0;
	money = MONEY_COUNT;
	srand(time(NULL));

	for (int i = 0; i < 13; i++)
	{
		cardsNum[i] = i + 1;
		cardsNum[i + 13] = i + 1;
		cardsNum[i + 26] = i + 1;
		cardsNum[i + 39] = i + 1;
	}

	// 배열 셔플
	Shufflecards();

	while (gamePlay)
	{
		betMoney = 0;
		bool checkA = true;
		while (checkA)
		{
			dealerA = rand() % CORRECT_CARDNUMBERS_COUNT;
			for (int i = 0; i < CORRECT_CARDNUMBERS_COUNT; i++)
			{
				if (dealerA == checkNum[i]) // dealerA가 checkNum배열의 수들과 같은지에 대한 판별 같으면 바로 break하고 랜덤이 다시 돌아감
				{
					checkA = true;
					break;
				}
				else if (dealerA != checkNum[i])
				{
					checkA = false;
				}
			}
		}
		bool checkB = true;
		while (checkB)
		{
			dealerB = rand() % CORRECT_CARDNUMBERS_COUNT;
			for (int i = 0; i < CORRECT_CARDNUMBERS_COUNT; i++)
			{
				// dealerB가 checkNum배열의 수들과 딜러A의 선택과 같은지에 대한. 판별 같으면 바로 break하고 랜덤이 다시 돌아감
				if (dealerB == checkNum[i] || dealerB == dealerA)
				{
					checkB = true;
					break;
				}
				else if (dealerB != dealerA && dealerB != checkNum[i])
				{
					checkB = false;
				}
			}
		}

		bool checkP = true;
		while (checkP)
		{
			player = rand() % CORRECT_CARDNUMBERS_COUNT;
			for (int i = 0; i < CORRECT_CARDNUMBERS_COUNT; i++)
			{
				// player가 checkNum배열의 수들과 딜러A의 선택과 딜러B의 선택과 같은지에 대한. 판별 같으면 바로 break하고 랜덤이 다시 돌아감
				if (player == checkNum[i] || player == dealerA || player == dealerB)
				{
					checkP = true;
					break;
				}
				else if (player != dealerA && player != dealerB && player != checkNum[i])
				{
					checkP = false;
				}
			}
		}

		for (int i = 0; i < 13; i+=3)
		{
			checkNum[num * 3] = dealerA;
			checkNum[num * 3 + 1] = dealerB;
			checkNum[num * 3 + 2] = player;
		}
		num++;

		cout << "선택 된 카드 1 : " << cards[dealerA] << endl;
		cout << "선택 된 카드 2 : " << cards[dealerB] << endl;

		// 선택된 카드의 대소 비교
		if (cardsNum[dealerA] < cardsNum[dealerB])
		{
			min = cardsNum[dealerA];
			max = cardsNum[dealerB];
		}
		else if (cardsNum[dealerA] > cardsNum[dealerB])
		{
			max = cardsNum[dealerA];
			min = cardsNum[dealerB];
		}

		bool betting = true;
		// 카드를 모두 소진했을 때 종료
		if (num == 17)
		{
			cout << "카드를 모두 소진했습니다." << endl;
			gamePlay = false;
			betting = false;
		}

		while (betting)
		{
			cout << "소지 금액 : " << money << endl;
			cout << "1. 베팅 2. 포기" << endl;
			cin >> goStop;

			if (goStop == 1)
			{
				cout << "베팅!!!" << endl;
				cin >> betMoney;

				if (betMoney <= 999)
				{
					cout << "1000원 이상 베팅하시오." << endl;
				}
				else if (betMoney >= 1000)
				{
					if (cardsNum[player] < max && cardsNum[player] > min)
					{
						cout << "플레이어 카드 : " << cards[player] << endl;
						cout << "베팅 성공!" << betMoney * 2 << "를 획득했다!" << endl;
						betting = false;
					}
					else
					{
						cout << "플레이어 카드 : " << cards[player] << endl;
						cout << "패배! 돈을 잃었다!" << endl;
						money -= betMoney;
						if (money > 0)
						{
							betting = false;
						}
						else if (money <= 0)
						{
							cout << "돈을 모두 잃었다!" << endl;
							cout << "Game Over" << endl;
							betting = false;
							gamePlay = false;
						}
					}
				}
			}
			else if (goStop == 2)
			{
				cout << "플레이어 카드 : " << cards[player] << endl;
				cout << "다음 기회에!" << endl;
				betting = false;				
			}
			else
			{
				cout << "다시 입력!" << endl;
			}
		}
		Sleep(2000);
		system("cls");
	}
	system("pause");
	return 0;
}

// 함수
void Shufflecards()
{
	for (int i = 0; i < 200; i++)
	{
		dest = rand() % CORRECT_CARDNUMBERS_COUNT;
		sour = rand() % CORRECT_CARDNUMBERS_COUNT;

		temp2 = cards[dest];
		cards[dest] = cards[sour];
		cards[sour] = temp2;

		temp1 = cardsNum[dest];
		cardsNum[dest] = cardsNum[sour];
		cardsNum[sour] = temp1;
	}
}