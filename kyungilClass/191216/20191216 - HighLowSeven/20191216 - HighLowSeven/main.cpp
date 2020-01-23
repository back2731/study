#include <string>
#include <iostream>
#include <time.h>
#include <windows.h>

using namespace std;

const int CORRECT_CARDNUMBERS_COUNT = 52;

int temp, sour, dest;
string temp2, sour2, dest2;

string cardShow[CORRECT_CARDNUMBERS_COUNT] =		// ���ڿ� �迭
{ "��A", "��2", "��3", "��4", "��5", "��6", "��7", "��8", "��9", "��10", "��J", "��Q", "��K",
	"��A","��2","��3","��4","��5","��6","��7","��8","��9","��10","��J","��Q","��K",
	"��A", "��2", "��3", "��4", "��5", "��6", "��7", "��8", "��9", "��10", "��J", "��Q", "��K",
	"��A", "��2", "��3", "��4", "��5", "��6", "��7", "��8", "��9", "��10", "��J", "��Q", "��K" };

int cardCheck[52];									// üũ�� �迭

int usedCard[52];									// ����� ī��� �迭
int Number;
int betMoney;
int choiceNumber;
int gameMoney;
int cardCount;

void Shufflecards();		// ī�� ���� �Լ�
void inputNumber();			// üũ�� �迭�� ���ڸ� �ִ� �Լ�
void checkCard();			// ī�� üũ�� �Լ�(�� �迭�� ����� ������)
void choiceCard();			// ī�� ���ÿ� �Լ�

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
		// ���� ���� �ʱ�ȭ
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
				cout << "���� ��� �Ҿ����ϴ�." << endl;
				cout << "�ٽ� �Ͻðڽ��ϱ�? 1.�ٽ��Ѵ�. 2. �����Ѵ�." << endl;
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
					cout << "�߸��� Ű�� �Է��߽��ϴ�. ����� �����մϴ�." << endl;
					gameManager = false;
					gamePlay = false;
				}
			}
			else if (cardCount > 45)		// ���� ī��� ������ �Ұ��� �� ��
			{
				cout << "ī�带 ��� ����߽��ϴ�." << endl;
				cout << "�ٽ� �Ͻðڽ��ϱ�? 1.�ٽ��Ѵ�. 2. �����Ѵ�." << endl;
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
					cout << "�߸��� Ű�� �Է��߽��ϴ�. ����� �����մϴ�." << endl;
					gameManager = false;
					gamePlay = false;
				}
			}
			else if(gameMoney > 0)
			{
				for (int i = 0; i < 4; i++)
				{
					choiceCard();

					cout << i + 1 << "��° ī�� : " << cardShow[Number] << "\t";
					cout << i + 1 << "��° ī�� : " << cardCheck[Number] << endl;
				}
				cout << "==========================================================" << endl;
				cout << "�÷��̾��� ���ӸӴ� : " << gameMoney << endl;
				cout << "������ �� ī�带 ���߽ÿ� : ? " << endl;
				choiceCard();
				cout << "ġƮŰ : " << cardCheck[Number] << endl;
				cout << "���� ī�� �� : " << cardCount << endl;

				bool betting = true;
				while (betting)
				{
					cout << "1. HIGH 2. LOW 3. SEVEN" << endl;
					cin >> choiceNumber;

					if (choiceNumber == 1)						// �÷��̾� ���� ����
					{
						bool bettingMoneyCheck = true;
						while (bettingMoneyCheck)
						{
							cout << "���� �ݾ��� �Է��Ͻÿ� : ";
							cin >> betMoney;

							if (betMoney > gameMoney)
							{
								cout << "���� �ݾ��� �÷��̾��� �����ݾ��� �Ѿ���ϴ�." << endl;
							}
							else if (betMoney < 999)
							{
								cout << "�ּ� 1000�� �̻��� �������ּ���." << endl;
							}
							else
							{
								bettingMoneyCheck = false;

								if (cardCheck[Number] > 7)				//����
								{
									cout << cardShow[Number] << endl;
									cout << "����� ī��� 7���� ū ī��! �÷��̾��� �¸�!" << endl;
									gameMoney += betMoney;
									betting = false;
								}
								else if (cardCheck[Number] < 7)			//�ο�
								{
									cout << cardShow[Number] << endl;
									cout << "����� ī��� 7���� ���� ī��! �÷��̾��� �й�!" << endl;
									gameMoney -= betMoney;
									betting = false;
								}
								else									//����
								{
									cout << cardShow[Number] << endl;
									cout << "����� ī��� 7! �÷��̾��� �й�!" << endl;
									gameMoney -= betMoney;
									betting = false;
								}

							}
						}
					}
					else if (choiceNumber == 2)					// �÷��̾� �ο� ����
					{
						bool bettingMoneyCheck = true;
						while (bettingMoneyCheck)
						{
							cout << "���� �ݾ��� �Է��Ͻÿ� : ";
							cin >> betMoney;

							if (betMoney > gameMoney)
							{
								cout << "���� �ݾ��� �÷��̾��� �����ݾ��� �Ѿ���ϴ�." << endl;
							}
							else if (betMoney < 999)
							{
								cout << "�ּ� 1000�� �̻��� �������ּ���." << endl;
							}
							else
							{
								bettingMoneyCheck = false;

								if (cardCheck[Number] > 7)				//����
								{
									cout << cardShow[Number] << endl;
									cout << "����� ī��� 7���� ū ī��! �÷��̾� �й�!" << endl;
									gameMoney -= betMoney;
									betting = false;
								}
								else if (cardCheck[Number] < 7)			//�ο�
								{
									cout << cardShow[Number] << endl;
									cout << "����� ī��� 7���� ���� ī��! �÷��̾� �¸�!" << endl;
									gameMoney += betMoney;
									betting = false;
								}
								else									//����
								{
									cout << cardShow[Number] << endl;
									cout << "����� ī��� 7! �÷��̾� �й�!" << endl;
									gameMoney -= betMoney;
									betting = false;
								}

							}
						}
					}
					else if (choiceNumber == 3)					// �÷��̾� ���� ����
					{
						bool bettingMoneyCheck = true;
						while (bettingMoneyCheck)
						{
							cout << "���� �ݾ��� �Է��Ͻÿ� : ";
							cin >> betMoney;

							if (betMoney > gameMoney)
							{
								cout << "���� �ݾ��� �÷��̾��� �����ݾ��� �Ѿ���ϴ�." << endl;
							}
							else if (betMoney < 999)
							{
								cout << "�ּ� 1000�� �̻��� �������ּ���." << endl;
							}
							else
							{
								bettingMoneyCheck = false;

								if (cardCheck[Number] > 7)				//����
								{
									cout << cardShow[Number] << endl;
									cout << "�÷��̾��� ī��� 7���� ū ī��! �÷��̾� �й�!" << endl;
									gameMoney -= betMoney;
									betting = false;
								}
								else if (cardCheck[Number] < 7)			//�ο�
								{
									cout << cardShow[Number] << endl;
									cout << "�÷��̾��� ī��� 7���� ���� ī��! �÷��̾� �й�!" << endl;
									gameMoney -= betMoney;
									betting = false;
								}
								else									//����
								{
									cout << cardShow[Number] << endl;
									cout << "�÷��̾��� ī��� 7! �÷��̾� �¸�! 7 ���ʽ��� ��÷�� 77��!" << endl;
									gameMoney += betMoney * 77;
									betting = false;
								}
							}
						}
					}
					else
					{
						cout << "�ٽ� �Է��Ͻÿ�." << endl;
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
