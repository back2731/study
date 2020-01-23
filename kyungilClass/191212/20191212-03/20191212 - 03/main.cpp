#include <iostream>
#include <time.h>
#include <string>
#include <Windows.h>
#include <time.h>
#include <cstdlib>

using namespace std;
/*
카드게임 월남뽕게임 (52장)
A 2 3 4 5 6 7 8 9 10 J Q K

게임의 룰
카드를 두 장을 랜덤으로 보여준다. 플레이어가 맞춰야 할 카드 공개

문양 4개 하트 다이아 클로버 스페이드

1. 조건 - 소지금 10,000원
2. 1000원 미만을 걸면 다시 입력
3. 종료조건 - 카드가 없을 때
*/
int dest, sour;
int temp1;
string temp2;
string cards[52] =		// 문자열 배열
{ "♠A", "♠2", "♠3", "♠4", "♠5", "♠6", "♠7", "♠8", "♠9", "♠10", "♠J", "♠Q", "♠K",
	"◆A","◆2","◆3","◆4","◆5","◆6","◆7","◆8","◆9","◆10","◆J","◆Q","◆K",
	"♥A", "♥2", "♥3", "♥4", "♥5", "♥6", "♥7", "♥8", "♥9", "♥10", "♥J", "♥Q", "♥K",
	"♣A", "♣2", "♣3", "♣4", "♣5", "♣6", "♣7", "♣8", "♣9", "♣10", "♣J", "♣Q", "♣K" };
int cardsNum[52];		// 승패 비교용 배열
int change[52];
string change2[52];

int throwCards[52];		// 게임 플레이 변수
int money = 10000;
int dealerA;
int dealerB;
int sameCheck[52];
int cardCounting = 0;
int player;
int countNum = 0;


bool gamePlay = true;

void Shufflecards();	// 문자열, 승패 비교용 배열 셔플

int main()
{
	srand(time(NULL));

	for (int i = 0; i < 13; i++)
	{
		cardsNum[i] = i + 1;
		cardsNum[i + 13] = i + 1;
		cardsNum[i + 26] = i + 1;
		cardsNum[i + 39] = i + 1;
	}

	Shufflecards();

	while (gamePlay)
	{
		for (int i = countNum; i < 13; i += 3)
		{
			cout << cardsNum[i + countNum * 3] << "\t";
			cout << "첫 번째 카드 : " << cards[i + countNum * 3] << endl;
			
			cout << cardsNum[i+ countNum * 3 + 1] << "\t";
			cout << "두 번째 카드 : " << cards[i + countNum * 3 + 1] << endl;
			
			cout << cardsNum[i+ countNum * 3 + 2] << "\t";
			cout << "플레이어 카드 : " << cards[i + countNum * 3 + 2] << endl;

			if (cardsNum[i + countNum * 3] < cardsNum[i + countNum * 3 + 1])
			{

			}
			break;
		}
		countNum++;


		cout << endl;
		if (countNum == 13)
		{
			cout << "카드를 모두 사용했습니다." << endl;
			gamePlay = false;
		}
	}

	system("pause");
	return 0;
}

// 함수 모음
void Shufflecards()
{
	for (int i = 0; i < 200; i++)
	{
		dest = rand() % 52;
		sour = rand() % 52;

		temp2 = cards[dest];
		cards[dest] = cards[sour];
		cards[sour] = temp2;
		
		temp1 = cardsNum[dest];
		cardsNum[dest] = cardsNum[sour];
		cardsNum[sour] = temp1;
	}
}