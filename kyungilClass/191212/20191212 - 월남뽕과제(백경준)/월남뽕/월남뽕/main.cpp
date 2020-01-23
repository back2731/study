#include <iostream>
#include <time.h>
#include <string>
#include <Windows.h>

using namespace std;

/*

ī����� �����Ͱ��� (CORRECT_CARDNUMBERS_COUNT��)

A 2 3 4 5 6 7 8 9 10 J Q K



������ ��

ī�带 �� ���� �������� �����ش�. �÷��̾ ����� �� ī�� ����



���� 4�� ��Ʈ ���̾� Ŭ�ι� �����̵�



1. ���� - ������ 10,000��

2. 1000�� �̸��� �ɸ� �ٽ� �Է�

3. �������� - ī�尡 ���� ��

*/

const int
CORRECT_CARDNUMBERS_COUNT = 52;
const int
MONEY_COUNT = 10000;

int dest, sour;
int temp1;
string temp2;
string cards[CORRECT_CARDNUMBERS_COUNT] =		// ���ڿ� �迭

{ "��A", "��2", "��3", "��4", "��5", "��6", "��7", "��8", "��9", "��10", "��J", "��Q", "��K",

	"��A","��2","��3","��4","��5","��6","��7","��8","��9","��10","��J","��Q","��K",

	"��A", "��2", "��3", "��4", "��5", "��6", "��7", "��8", "��9", "��10", "��J", "��Q", "��K",

	"��A", "��2", "��3", "��4", "��5", "��6", "��7", "��8", "��9", "��10", "��J", "��Q", "��K" };

int cardsNum[CORRECT_CARDNUMBERS_COUNT];		// ���� �񱳿� �迭
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

void Shufflecards();	// ���ڿ�, ���� �񱳿� �迭 ����


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

	// �迭 ����
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
				if (dealerA == checkNum[i]) // dealerA�� checkNum�迭�� ����� �������� ���� �Ǻ� ������ �ٷ� break�ϰ� ������ �ٽ� ���ư�
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
				// dealerB�� checkNum�迭�� ����� ����A�� ���ð� �������� ����. �Ǻ� ������ �ٷ� break�ϰ� ������ �ٽ� ���ư�
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
				// player�� checkNum�迭�� ����� ����A�� ���ð� ����B�� ���ð� �������� ����. �Ǻ� ������ �ٷ� break�ϰ� ������ �ٽ� ���ư�
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

		cout << "���� �� ī�� 1 : " << cards[dealerA] << endl;
		cout << "���� �� ī�� 2 : " << cards[dealerB] << endl;

		// ���õ� ī���� ��� ��
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
		// ī�带 ��� �������� �� ����
		if (num == 17)
		{
			cout << "ī�带 ��� �����߽��ϴ�." << endl;
			gamePlay = false;
			betting = false;
		}

		while (betting)
		{
			cout << "���� �ݾ� : " << money << endl;
			cout << "1. ���� 2. ����" << endl;
			cin >> goStop;

			if (goStop == 1)
			{
				cout << "����!!!" << endl;
				cin >> betMoney;

				if (betMoney <= 999)
				{
					cout << "1000�� �̻� �����Ͻÿ�." << endl;
				}
				else if (betMoney >= 1000)
				{
					if (cardsNum[player] < max && cardsNum[player] > min)
					{
						cout << "�÷��̾� ī�� : " << cards[player] << endl;
						cout << "���� ����!" << betMoney * 2 << "�� ȹ���ߴ�!" << endl;
						betting = false;
					}
					else
					{
						cout << "�÷��̾� ī�� : " << cards[player] << endl;
						cout << "�й�! ���� �Ҿ���!" << endl;
						money -= betMoney;
						if (money > 0)
						{
							betting = false;
						}
						else if (money <= 0)
						{
							cout << "���� ��� �Ҿ���!" << endl;
							cout << "Game Over" << endl;
							betting = false;
							gamePlay = false;
						}
					}
				}
			}
			else if (goStop == 2)
			{
				cout << "�÷��̾� ī�� : " << cards[player] << endl;
				cout << "���� ��ȸ��!" << endl;
				betting = false;				
			}
			else
			{
				cout << "�ٽ� �Է�!" << endl;
			}
		}
		Sleep(2000);
		system("cls");
	}
	system("pause");
	return 0;
}

// �Լ�
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