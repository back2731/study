#include <iostream>
#include <time.h>
#include <string>
#include <Windows.h>
#include <time.h>
#include <cstdlib>

using namespace std;
/*
ī����� �����Ͱ��� (52��)
A 2 3 4 5 6 7 8 9 10 J Q K

������ ��
ī�带 �� ���� �������� �����ش�. �÷��̾ ����� �� ī�� ����

���� 4�� ��Ʈ ���̾� Ŭ�ι� �����̵�

1. ���� - ������ 10,000��
2. 1000�� �̸��� �ɸ� �ٽ� �Է�
3. �������� - ī�尡 ���� ��
*/
int dest, sour;
int temp1;
string temp2;
string cards[52] =		// ���ڿ� �迭
{ "��A", "��2", "��3", "��4", "��5", "��6", "��7", "��8", "��9", "��10", "��J", "��Q", "��K",
	"��A","��2","��3","��4","��5","��6","��7","��8","��9","��10","��J","��Q","��K",
	"��A", "��2", "��3", "��4", "��5", "��6", "��7", "��8", "��9", "��10", "��J", "��Q", "��K",
	"��A", "��2", "��3", "��4", "��5", "��6", "��7", "��8", "��9", "��10", "��J", "��Q", "��K" };
int cardsNum[52];		// ���� �񱳿� �迭
int change[52];
string change2[52];

int throwCards[52];		// ���� �÷��� ����
int money = 10000;
int dealerA;
int dealerB;
int sameCheck[52];
int cardCounting = 0;
int player;
int countNum = 0;


bool gamePlay = true;

void Shufflecards();	// ���ڿ�, ���� �񱳿� �迭 ����

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
			cout << "ù ��° ī�� : " << cards[i + countNum * 3] << endl;
			
			cout << cardsNum[i+ countNum * 3 + 1] << "\t";
			cout << "�� ��° ī�� : " << cards[i + countNum * 3 + 1] << endl;
			
			cout << cardsNum[i+ countNum * 3 + 2] << "\t";
			cout << "�÷��̾� ī�� : " << cards[i + countNum * 3 + 2] << endl;

			if (cardsNum[i + countNum * 3] < cardsNum[i + countNum * 3 + 1])
			{

			}
			break;
		}
		countNum++;


		cout << endl;
		if (countNum == 13)
		{
			cout << "ī�带 ��� ����߽��ϴ�." << endl;
			gamePlay = false;
		}
	}

	system("pause");
	return 0;
}

// �Լ� ����
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