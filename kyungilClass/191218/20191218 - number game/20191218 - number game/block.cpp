#include "block.h"


block::block()
{
}


block::~block()
{
}

void block::init()
{
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			blockNumber[i][j] = (i * 4) + j + 1;
		}
	}

	blockNumber[3][3] = 0;
}

void block::printBlock()
{
	for (int i = 0; i < 4; i++)
	{
		cout << "||" << "\t";
		for (int j = 0; j < 4; j++)
		{
			cout << blockNumber[i][j] << "\t" << "||" << "\t";
		}
		cout << endl;
		cout << "==================================================================" << endl;
	}
}

void block::moveBlock()
{
	int input;
	bool choice = true;
	while (choice)
	{
		cout << "�Է��Ͻÿ�." << endl;
		cin >> input;		
		
		if (input == 1)
		{
			if (X == 0)
			{
				cout << "���� �������ʰ��߽��ϴ�." << endl;
			}
			else
			{
				temp = blockNumber[X][Y];
				blockNumber[X][Y] = blockNumber[X - 1][Y];
				blockNumber[X - 1][Y] = temp;
				X -= 1;
				cout << "���� �̵�" << endl;
				choice = false;
			}
			// cout << X << endl;
			// cout << Y << endl;				
		}
		else if (input == 2)
		{
			if (Y == 0)
			{
				cout << "���� �������ʰ��߽��ϴ�." << endl;
			}
			else
			{
				temp = blockNumber[X][Y];
				blockNumber[X][Y] = blockNumber[X][Y - 1];
				blockNumber[X][Y - 1] = temp;
				cout << "�������� �̵�" << endl;
				choice = false;
				Y -= 1;
			}
			// cout << X << endl;
			// cout << Y << endl;
		}
		else if (input == 3)
		{
			if (X == 3)
			{
				cout << "���� �������ʰ��߽��ϴ�." << endl;
			}
			else
			{
				temp = blockNumber[X][Y];
				blockNumber[X][Y] = blockNumber[X + 1][Y];
				blockNumber[X + 1][Y] = temp;
				X += 1;
				cout << "�Ʒ������� �̵�" << endl;
				choice = false;
			}
			// cout << X << endl;
			// cout << Y << endl;
		}
		else if (input == 4)
		{
			if (Y == 3)
			{
				cout << "���� �������ʰ��߽��ϴ�." << endl;
			}
			else
			{
				temp = blockNumber[X][Y];
				blockNumber[X][Y] = blockNumber[X][Y + 1];
				blockNumber[X][Y + 1] = temp;
				Y += 1;
				cout << "���������� �̵�" << endl;
				choice = false;
			}
			// cout << X << endl;
			// cout << Y << endl;
		}
	}
}

void block::shuffleBoard()
{
	int rndNumber;
	srand(time(NULL));

	bool choice = true;
	while (choice)
	{
		for (int i = 0; i < 500; i++)
		{
			rndNumber = rand() % 4 + 1;
			
			if (rndNumber == 1)
			{
				if (X == 0)
				{
					//cout << "���� �������ʰ��߽��ϴ�." << endl;
				}
				else
				{
					temp = blockNumber[X][Y];
					blockNumber[X][Y] = blockNumber[X - 1][Y];
					blockNumber[X - 1][Y] = temp;
					X -= 1;
					//cout << "���� �̵�" << endl;
				}
				// cout << X << endl;
				// cout << Y << endl;				
			}
			else if (rndNumber == 2)
			{
				if (Y == 0)
				{
					//cout << "���� �������ʰ��߽��ϴ�." << endl;
				}
				else
				{
					temp = blockNumber[X][Y];
					blockNumber[X][Y] = blockNumber[X][Y - 1];
					blockNumber[X][Y - 1] = temp;
					//cout << "�������� �̵�" << endl;
					Y -= 1;
				}
				// cout << X << endl;
				// cout << Y << endl;
			}
			else if (rndNumber == 3)
			{
				if (X == 3)
				{
					//cout << "���� �������ʰ��߽��ϴ�." << endl;
				}
				else
				{
					temp = blockNumber[X][Y];
					blockNumber[X][Y] = blockNumber[X + 1][Y];
					blockNumber[X + 1][Y] = temp;
					X += 1;
					//cout << "�Ʒ������� �̵�" << endl;
				}
				// cout << X << endl;
				// cout << Y << endl;
			}
			else if (rndNumber == 4)
			{
				if (Y == 3)
				{
					//cout << "���� �������ʰ��߽��ϴ�." << endl;
				}
				else
				{
					temp = blockNumber[X][Y];
					blockNumber[X][Y] = blockNumber[X][Y + 1];
					blockNumber[X][Y + 1] = temp;
					Y += 1;
					//cout << "���������� �̵�" << endl;
				}
				// cout << X << endl;
				// cout << Y << endl;
			}
		}
		choice = false;
	}
}

void block::resetBoard()
{
	cout << "���� ������ �����ϰ� ���� �Ͻðڽ��ϱ�? Y / N" << endl;
	char resetKey;
	cin >> resetKey;
	char shuffleKey;

	if (resetKey == 'y' && 'Y')
	{
		cout << "������ �����մϴ�." << endl;
		init();
		X = 3;
		Y = 3;
		
		cout << "���� �Ͻðڽ��ϱ�? Y / N" << endl;
		cin >> shuffleKey;
		if (shuffleKey == 'y' && 'Y')
		{
			shuffleBoard();
		}
		else
		{
			cout << "���� ���� �ʾҽ��ϴ�." << endl;
		}
	}
	else
	{
		cout << "������ ����մϴ�" << endl;
	}
}
