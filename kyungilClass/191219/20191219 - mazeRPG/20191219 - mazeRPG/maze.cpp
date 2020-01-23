#include "maze.h"
#include <Windows.h>


maze::maze()
{
	m_player = new Player;
}


maze::~maze()
{
	delete m_player;
}

void maze::boardTruefalse()
{
	// ���� ù ��° ��
	boardCheck[0][0] = true;
	boardCheck[0][1] = true;
	boardCheck[0][2] = false;
	boardCheck[0][3] = false;
	boardCheck[0][4] = false;
	boardCheck[0][5] = false;
	boardCheck[0][6] = false;
	boardCheck[0][7] = false;
	boardCheck[0][8] = false;
	boardCheck[0][9] = false;

	// ���� �� ��° ��
	boardCheck[1][0] = false;
	boardCheck[1][1] = true;
	boardCheck[1][2] = true;
	boardCheck[1][3] = true;
	boardCheck[1][4] = true;
	boardCheck[1][5] = true;
	boardCheck[1][6] = false;
	boardCheck[1][7] = true;
	boardCheck[1][8] = true;
	boardCheck[1][9] = false;

	// ���� �� ��° ��
	boardCheck[2][0] = false;
	boardCheck[2][1] = false;
	boardCheck[2][2] = true;
	boardCheck[2][3] = false;
	boardCheck[2][4] = false;
	boardCheck[2][5] = true;
	boardCheck[2][6] = false;
	boardCheck[2][7] = false;
	boardCheck[2][8] = true;
	boardCheck[2][9] = false;

	// ���� �� ��° ��
	boardCheck[3][0] = false;
	boardCheck[3][1] = false;
	boardCheck[3][2] = true;
	boardCheck[3][3] = false;
	boardCheck[3][4] = false;
	boardCheck[3][5] = true;
	boardCheck[3][6] = true;
	boardCheck[3][7] = true;
	boardCheck[3][8] = true;
	boardCheck[3][9] = true;

	// ���� �ټ� ���� ��
	boardCheck[4][0] = false;
	boardCheck[4][1] = true;
	boardCheck[4][2] = true;
	boardCheck[4][3] = false;
	boardCheck[4][4] = false;
	boardCheck[4][5] = true;
	boardCheck[4][6] = false;
	boardCheck[4][7] = false;
	boardCheck[4][8] = false;
	boardCheck[4][9] = false;

	// ���� ���� ���� ��
	boardCheck[5][0] = false;
	boardCheck[5][1] = true;
	boardCheck[5][2] = false;
	boardCheck[5][3] = false;
	boardCheck[5][4] = false;
	boardCheck[5][5] = true;
	boardCheck[5][6] = false;
	boardCheck[5][7] = false;
	boardCheck[5][8] = false;
	boardCheck[5][9] = false;

	// ���� �ϰ� ���� ��
	boardCheck[6][0] = false;
	boardCheck[6][1] = true;
	boardCheck[6][2] = false;
	boardCheck[6][3] = false;
	boardCheck[6][4] = false;
	boardCheck[6][5] = true;
	boardCheck[6][6] = true;
	boardCheck[6][7] = true;
	boardCheck[6][8] = true;
	boardCheck[6][9] = false;

	// ���� ���� ���� ��
	boardCheck[7][0] = false;
	boardCheck[7][1] = true;
	boardCheck[7][2] = true;
	boardCheck[7][3] = true;
	boardCheck[7][4] = false;
	boardCheck[7][5] = false;
	boardCheck[7][6] = false;
	boardCheck[7][7] = false;
	boardCheck[7][8] = true;
	boardCheck[7][9] = false;

	// ���� ��ȩ ���� ��
	boardCheck[8][0] = false;
	boardCheck[8][1] = true;
	boardCheck[8][2] = false;
	boardCheck[8][3] = true;
	boardCheck[8][4] = true;
	boardCheck[8][5] = true;
	boardCheck[8][6] = true;
	boardCheck[8][7] = false;
	boardCheck[8][8] = true;
	boardCheck[8][9] = false;

	// ���� �� ���� ��
	boardCheck[9][0] = false;
	boardCheck[9][1] = false;
	boardCheck[9][2] = false;
	boardCheck[9][3] = false;
	boardCheck[9][4] = false;
	boardCheck[9][5] = false;
	boardCheck[9][6] = true;
	boardCheck[9][7] = false;
	boardCheck[9][8] = true;
	boardCheck[9][9] = false;

}

// true false �� ���� Ȯ�ο�
//void maze::test()
//{
//	for (int i = 0; i < 10; i++)
//	{
//		for (int j = 0; j < 10; j++)
//		{
//			cout << boardCheck[i][j] << "\t";
//		}
//		cout << endl << endl;
//	}
//}

void maze::setBoard()
{
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			if (boardCheck[i][j] == true)
			{
				mazeMap[i][j] = "��";
			}
			else
			{
				mazeMap[i][j] = "��";
			}
		}
	}
}

void maze::printBoard()
{
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			cout << mazeMap[i][j];
		}
		cout << endl;
	}
}

void maze::firstprintBoard()
{
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			cout << mazeMap[i][j];
			Sleep(50);
		}
		Sleep(100);
		cout << endl;
	}
}

void maze::setPlayer()
{
	x = 0;
	y = 0;
	m_player->playerInit();
	mazeMap[x][y] = m_player->getplayerPosition(x, y);

}

void maze::movePlayer()
{
	printBoard();

	bool choice = true;
	while (choice)
	{
		inputKey = _getch();
		switch (inputKey)
		{
		case 72:				// ���� �̵�
			if (x == 0)
			{
				cout << "���δ� �̵� �� �� �����ϴ�." << endl;
			}
			else
			{
				if (boardCheck[x - 1][y] == false)
				{
					cout << "���� ������ �����ֽ��ϴ�." << endl;
				}
				else
				{
					temp = mazeMap[x][y];
					mazeMap[x][y] = mazeMap[x - 1][y];
					mazeMap[x - 1][y] = temp;
					x -= 1;

					cout << "���� �̵��մϴ�." << endl;
					choice = false;
				}
			}
			break;

		case 80:				// �Ʒ��� �̵�
			if (x == 9)
			{
				cout << "�Ʒ��δ� �̵� �� �� �����ϴ�." << endl;
			}
			else
			{
				if (boardCheck[x + 1][y] == false)
				{
					cout << "�Ʒ��� ������ �����ֽ��ϴ�." << endl;
				}
				else
				{
					temp = mazeMap[x][y];
					mazeMap[x][y] = mazeMap[x + 1][y];
					mazeMap[x + 1][y] = temp;
					x += 1;

					cout << "�Ʒ��� �̵��մϴ�." << endl;
					choice = false;
				}
			}
			break;
		case 75:				// �������� �̵�
			if (y == 0)
			{
				cout << "�������δ� �̵� �� �� �����ϴ�." << endl;
			}
			else
			{
				if (boardCheck[x][y - 1] == false)
				{
					cout << "������ ������ �����ֽ��ϴ�." << endl;
				}
				else
				{
					temp = mazeMap[x][y];
					mazeMap[x][y] = mazeMap[x][y - 1];
					mazeMap[x][y - 1] = temp;
					y -= 1;

					cout << "�������� �̵��մϴ�." << endl;
					choice = false;
				}
			}
			break;

		case 77:				// ���������� �̵�
			if (y == 9)
			{
				cout << "���������δ� �̵� �� �� �����ϴ�." << endl;
			}
			else
			{
				if (boardCheck[x][y + 1] == false)
				{
					cout << "�������� ������ �����ֽ��ϴ�." << endl;
				}
				else
				{
					temp = mazeMap[x][y];
					mazeMap[x][y] = mazeMap[x][y + 1];
					mazeMap[x][y + 1] = temp;
					y += 1;

					cout << "���������� �̵��մϴ�." << endl;
					choice = false;
				}
			}
			break;
		default:
			break;
		}
	}
}
