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
	X = 3;
	Y = 3;
}

void block::printBlock()
{
	cout << "==================================================================" << endl;
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
	
	cout << "방향키로 조작. R - 리셋 S - 셔플 G - 게임 종료" << endl;
	bool choice = true;
	while (choice)
	{
		input = _getch();
		switch (input)
		{
		case 72:
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
			break;
		case 75:
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
			break;
		case 80:
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
			break;
		case 77:
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
			break;
		case 82:			// 초기화 리셋
			init();
			printBlock();
			break;
		case 114:			// 초기화 리셋
			init();
			printBlock();
			break;
		case 83:			// 셔플
			shuffleBoard();
			printBlock();
			break;
		case 115:			// 셔플
			shuffleBoard();
			printBlock();
			break;
		case 71:
			exit(0);
			break;		
		case 103:
			exit(0);
			break;
		default:
			break;
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