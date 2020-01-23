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
		cout << "입력하시오." << endl;
		cin >> input;		
		
		if (input == 1)
		{
			if (X == 0)
			{
				cout << "지정 범위를초과했습니다." << endl;
			}
			else
			{
				temp = blockNumber[X][Y];
				blockNumber[X][Y] = blockNumber[X - 1][Y];
				blockNumber[X - 1][Y] = temp;
				X -= 1;
				cout << "위로 이동" << endl;
				choice = false;
			}
			// cout << X << endl;
			// cout << Y << endl;				
		}
		else if (input == 2)
		{
			if (Y == 0)
			{
				cout << "지정 범위를초과했습니다." << endl;
			}
			else
			{
				temp = blockNumber[X][Y];
				blockNumber[X][Y] = blockNumber[X][Y - 1];
				blockNumber[X][Y - 1] = temp;
				cout << "왼쪽으로 이동" << endl;
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
				cout << "지정 범위를초과했습니다." << endl;
			}
			else
			{
				temp = blockNumber[X][Y];
				blockNumber[X][Y] = blockNumber[X + 1][Y];
				blockNumber[X + 1][Y] = temp;
				X += 1;
				cout << "아래쪽으로 이동" << endl;
				choice = false;
			}
			// cout << X << endl;
			// cout << Y << endl;
		}
		else if (input == 4)
		{
			if (Y == 3)
			{
				cout << "지정 범위를초과했습니다." << endl;
			}
			else
			{
				temp = blockNumber[X][Y];
				blockNumber[X][Y] = blockNumber[X][Y + 1];
				blockNumber[X][Y + 1] = temp;
				Y += 1;
				cout << "오른쪽으로 이동" << endl;
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
					//cout << "지정 범위를초과했습니다." << endl;
				}
				else
				{
					temp = blockNumber[X][Y];
					blockNumber[X][Y] = blockNumber[X - 1][Y];
					blockNumber[X - 1][Y] = temp;
					X -= 1;
					//cout << "위로 이동" << endl;
				}
				// cout << X << endl;
				// cout << Y << endl;				
			}
			else if (rndNumber == 2)
			{
				if (Y == 0)
				{
					//cout << "지정 범위를초과했습니다." << endl;
				}
				else
				{
					temp = blockNumber[X][Y];
					blockNumber[X][Y] = blockNumber[X][Y - 1];
					blockNumber[X][Y - 1] = temp;
					//cout << "왼쪽으로 이동" << endl;
					Y -= 1;
				}
				// cout << X << endl;
				// cout << Y << endl;
			}
			else if (rndNumber == 3)
			{
				if (X == 3)
				{
					//cout << "지정 범위를초과했습니다." << endl;
				}
				else
				{
					temp = blockNumber[X][Y];
					blockNumber[X][Y] = blockNumber[X + 1][Y];
					blockNumber[X + 1][Y] = temp;
					X += 1;
					//cout << "아래쪽으로 이동" << endl;
				}
				// cout << X << endl;
				// cout << Y << endl;
			}
			else if (rndNumber == 4)
			{
				if (Y == 3)
				{
					//cout << "지정 범위를초과했습니다." << endl;
				}
				else
				{
					temp = blockNumber[X][Y];
					blockNumber[X][Y] = blockNumber[X][Y + 1];
					blockNumber[X][Y + 1] = temp;
					Y += 1;
					//cout << "오른쪽으로 이동" << endl;
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
	cout << "현재 게임을 포기하고 리셋 하시겠습니까? Y / N" << endl;
	char resetKey;
	cin >> resetKey;
	char shuffleKey;

	if (resetKey == 'y' && 'Y')
	{
		cout << "게임을 리셋합니다." << endl;
		init();
		X = 3;
		Y = 3;
		
		cout << "셔플 하시겠습니까? Y / N" << endl;
		cin >> shuffleKey;
		if (shuffleKey == 'y' && 'Y')
		{
			shuffleBoard();
		}
		else
		{
			cout << "셔플 하지 않았습니다." << endl;
		}
	}
	else
	{
		cout << "게임을 계속합니다" << endl;
	}
}
