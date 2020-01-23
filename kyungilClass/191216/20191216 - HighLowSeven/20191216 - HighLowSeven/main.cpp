#include <string>
#include <iostream>
#include <time.h>
#include <windows.h>

using namespace std;

const int CORRECT_CARDNUMBERS_COUNT = 52;

int temp, sour, dest;
string temp2, sour2, dest2;

string cardShow[CORRECT_CARDNUMBERS_COUNT] =		// 문자열 배열
{ "♠A", "♠2", "♠3", "♠4", "♠5", "♠6", "♠7", "♠8", "♠9", "♠10", "♠J", "♠Q", "♠K",
	"◆A","◆2","◆3","◆4","◆5","◆6","◆7","◆8","◆9","◆10","◆J","◆Q","◆K",
	"♥A", "♥2", "♥3", "♥4", "♥5", "♥6", "♥7", "♥8", "♥9", "♥10", "♥J", "♥Q", "♥K",
	"♣A", "♣2", "♣3", "♣4", "♣5", "♣6", "♣7", "♣8", "♣9", "♣10", "♣J", "♣Q", "♣K" };

int cardCheck[52];									// 체크용 배열

int usedCard[52];									// 사용한 카드용 배열
int Number;
int betMoney;
int choiceNumber;
int gameMoney;
int cardCount;

void Shufflecards();		// 카드 셔플 함수
void inputNumber();			// 체크용 배열에 숫자를 넣는 함수
void checkCard();			// 카드 체크용 함수(두 배열에 제대로 들어갔는지)
void choiceCard();			// 카드 선택용 함수

int main()
{
	srand(time(NULL));

	inputNumber();

	Shufflecards();

	cardCount = 0;

	gameMoney = 10000;

	//checkCard();
	bool gameManager = true;
	while (gameManager)
	{
		// 게임 변수 초기화
		bool gamePlay = true;
		for (int i = 0; i < 52; i++)
		{
			usedCard[i] = 0;
		}		
		cardCount = 0;
		Number = 0;

		while (gamePlay)
		{
			if (gameMoney <= 0)
			{
				cout << "돈을 모두 잃었습니다." << endl;
				cout << "다시 하시겠습니까? 1.다시한다. 2. 종료한다." << endl;
				int gameOver;
				cin >> gameOver;

				if (gameOver == 1)
				{
					gameMoney = 10000;
					gamePlay = false;
				}
				else if (gameOver == 2)
				{
					gameManager = false;
					gamePlay = false;
				}
				else
				{
					cout << "잘못된 키를 입력했습니다. 종료로 간주합니다." << endl;
					gameManager = false;
					gamePlay = false;
				}
			}
			else if (cardCount > 45)		// 남은 카드로 게임이 불가능 할 때
			{
				cout << "카드를 모두 사용했습니다." << endl;
				cout << "다시 하시겠습니까? 1.다시한다. 2. 종료한다." << endl;
				int gameOver;
				cin >> gameOver;

				if (gameOver == 1)
				{
					gameMoney = 10000;
					gamePlay = false;
				}
				else if (gameOver == 2)
				{
					gameManager = false;
					gamePlay = false;
				}
				else
				{
					cout << "잘못된 키를 입력했습니다. 종료로 간주합니다." << endl;
					gameManager = false;
					gamePlay = false;
				}
			}
			else if(gameMoney > 0)
			{
				for (int i = 0; i < 4; i++)
				{
					choiceCard();

					cout << i + 1 << "번째 카드 : " << cardShow[Number] << "\t";
					cout << i + 1 << "번째 카드 : " << cardCheck[Number] << endl;
				}
				cout << "==========================================================" << endl;
				cout << "플레이어의 게임머니 : " << gameMoney << endl;
				cout << "다음에 올 카드를 맞추시오 : ? " << endl;
				choiceCard();
				cout << "치트키 : " << cardCheck[Number] << endl;
				cout << "사용된 카드 수 : " << cardCount << endl;

				bool betting = true;
				while (betting)
				{
					cout << "1. HIGH 2. LOW 3. SEVEN" << endl;
					cin >> choiceNumber;

					if (choiceNumber == 1)						// 플레이어 하이 선택
					{
						bool bettingMoneyCheck = true;
						while (bettingMoneyCheck)
						{
							cout << "베팅 금액을 입력하시오 : ";
							cin >> betMoney;

							if (betMoney > gameMoney)
							{
								cout << "베팅 금액이 플레이어의 소지금액을 넘어갔습니다." << endl;
							}
							else if (betMoney < 999)
							{
								cout << "최소 1000원 이상을 베팅해주세요." << endl;
							}
							else
							{
								bettingMoneyCheck = false;

								if (cardCheck[Number] > 7)				//하이
								{
									cout << cardShow[Number] << endl;
									cout << "비공개 카드는 7보다 큰 카드! 플레이어의 승리!" << endl;
									gameMoney += betMoney;
									betting = false;
								}
								else if (cardCheck[Number] < 7)			//로우
								{
									cout << cardShow[Number] << endl;
									cout << "비공개 카드는 7보다 작은 카드! 플레이어의 패배!" << endl;
									gameMoney -= betMoney;
									betting = false;
								}
								else									//세븐
								{
									cout << cardShow[Number] << endl;
									cout << "비공개 카드는 7! 플레이어의 패배!" << endl;
									gameMoney -= betMoney;
									betting = false;
								}

							}
						}
					}
					else if (choiceNumber == 2)					// 플레이어 로우 선택
					{
						bool bettingMoneyCheck = true;
						while (bettingMoneyCheck)
						{
							cout << "베팅 금액을 입력하시오 : ";
							cin >> betMoney;

							if (betMoney > gameMoney)
							{
								cout << "베팅 금액이 플레이어의 소지금액을 넘어갔습니다." << endl;
							}
							else if (betMoney < 999)
							{
								cout << "최소 1000원 이상을 베팅해주세요." << endl;
							}
							else
							{
								bettingMoneyCheck = false;

								if (cardCheck[Number] > 7)				//하이
								{
									cout << cardShow[Number] << endl;
									cout << "비공개 카드는 7보다 큰 카드! 플레이어 패배!" << endl;
									gameMoney -= betMoney;
									betting = false;
								}
								else if (cardCheck[Number] < 7)			//로우
								{
									cout << cardShow[Number] << endl;
									cout << "비공개 카드는 7보다 작은 카드! 플레이어 승리!" << endl;
									gameMoney += betMoney;
									betting = false;
								}
								else									//세븐
								{
									cout << cardShow[Number] << endl;
									cout << "비공개 카드는 7! 플레이어 패배!" << endl;
									gameMoney -= betMoney;
									betting = false;
								}

							}
						}
					}
					else if (choiceNumber == 3)					// 플레이어 세븐 선택
					{
						bool bettingMoneyCheck = true;
						while (bettingMoneyCheck)
						{
							cout << "베팅 금액을 입력하시오 : ";
							cin >> betMoney;

							if (betMoney > gameMoney)
							{
								cout << "베팅 금액이 플레이어의 소지금액을 넘어갔습니다." << endl;
							}
							else if (betMoney < 999)
							{
								cout << "최소 1000원 이상을 베팅해주세요." << endl;
							}
							else
							{
								bettingMoneyCheck = false;

								if (cardCheck[Number] > 7)				//하이
								{
									cout << cardShow[Number] << endl;
									cout << "플레이어의 카드는 7보다 큰 카드! 플레이어 패배!" << endl;
									gameMoney -= betMoney;
									betting = false;
								}
								else if (cardCheck[Number] < 7)			//로우
								{
									cout << cardShow[Number] << endl;
									cout << "플레이어의 카드는 7보다 작은 카드! 플레이어 패배!" << endl;
									gameMoney -= betMoney;
									betting = false;
								}
								else									//세븐
								{
									cout << cardShow[Number] << endl;
									cout << "플레이어의 카드는 7! 플레이어 승리! 7 보너스로 당첨금 77배!" << endl;
									gameMoney += betMoney * 77;
									betting = false;
								}
							}
						}
					}
					else
					{
						cout << "다시 입력하시오." << endl;
					}

					Sleep(2000);
					system("cls");
				}
			}
		}
	}
	system("pause");
	return 0;
}

void Shufflecards()
{
	for (int i = 0; i < 200; i++)
	{
		dest = rand() % CORRECT_CARDNUMBERS_COUNT;
		sour = rand() % CORRECT_CARDNUMBERS_COUNT;

		temp2 = cardShow[dest];
		cardShow[dest] = cardShow[sour];
		cardShow[sour] = temp2;

		temp = cardCheck[dest];
		cardCheck[dest] = cardCheck[sour];
		cardCheck[sour] = temp;
	}
}
void inputNumber()
{
	for (int i = 0; i < 13; i++)
	{
		cardCheck[i] = i + 1;
		cardCheck[i + 13] = i + 1;
		cardCheck[i + 26] = i + 1;
		cardCheck[i + 39] = i + 1;
	}
}
void checkCard()
{
	for (int i = 0; i < CORRECT_CARDNUMBERS_COUNT; i++)
	{
		cout << cardCheck[i] << "\t";
		cout << cardShow[i] << endl;
	}
}
void choiceCard()
{
	bool choice = true;
	while (choice)
	{
		Number = rand() % CORRECT_CARDNUMBERS_COUNT;
		for (int i = 0; i < CORRECT_CARDNUMBERS_COUNT; i++)
		{
			if (Number == usedCard[i])
			{
				choice = true;
				break;
			}
			else
			{
				choice = false;
			}
		}		
	}
	for (int i = 0; i < CORRECT_CARDNUMBERS_COUNT; i++)
	{
		if (usedCard[i] == 0)
		{
			usedCard[i] = Number;
			break;
		}
		else
		{
			continue;
		}
	}
	cardCount++;
}
