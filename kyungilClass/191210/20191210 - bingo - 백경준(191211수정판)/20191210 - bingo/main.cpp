#include <iostream>
#include <time.h>
#include <windows.h>
using namespace std;

int main()
{
	int playerBingo[5][5];
	int comBingo[5][5];
	int dest, sour, test, change, temp;
	int chooseNum;
	int checkchooseNum[500];
	int checkcomChoose[500];
	int playerCount = 0;
	int comCount = 0;
	int checkNum[25];
	int playerBingoCount = 0;
	int comBingoCount = 0;

	bool gamePlay = true;

	// �÷��̾� Ȯ�ο�
	bool horizontalCount = true;
	bool horizontalCount1 = true;
	bool horizontalCount2 = true;
	bool horizontalCount3 = true;
	bool horizontalCount4 = true;

	bool verticalCount = true;
	bool verticalCount1 = true;
	bool verticalCount2 = true;
	bool verticalCount3 = true;
	bool verticalCount4 = true;

	bool diagonalCount = true;
	bool diagonalCount1 = true;

	// ��ǻ�� Ȯ�ο�
	bool c_horizontalCount = true;
	bool c_horizontalCount1 = true;
	bool c_horizontalCount2 = true;
	bool c_horizontalCount3 = true;
	bool c_horizontalCount4 = true;
		 
	bool c_verticalCount = true;
	bool c_verticalCount1 = true;
	bool c_verticalCount2 = true;
	bool c_verticalCount3 = true;
	bool c_verticalCount4 = true;
		 
	bool c_diagonalCount = true;
	bool c_diagonalCount1 = true;

	srand(time(NULL));	
	
	bool game = true;

	// ���� ����
	while (gamePlay)
	{
		// Ȯ�ο� �迭
		for (int i = 0; i < 500; i++)
		{
			checkchooseNum[i] = 0;
		}

		// Ȯ�ο� �迭
		for (int i = 0; i < 25; i++)
		{
			checkNum[i] = i + 1;
		}// end of for

		// �迭 �� ���� 1 ~ 25
		for (int i = 0; i < 5; i++)
		{
			for (int j = 0; j < 5; j++)
			{
				playerBingo[i][j] = j + (i * 5) + 1;
				comBingo[i][j] = j + (i * 5) + 1;
			}
		}// end of for

		// �迭 �� ����ȭ (�÷��̾�)
		for (int i = 0; i < 200; i++)
		{
			dest = rand() % 5;
			sour = rand() % 5;
			test = rand() % 5;
			change = rand() % 5;

			temp = playerBingo[dest][sour];
			playerBingo[dest][sour] = playerBingo[test][change];
			playerBingo[test][change] = temp;
		}// end of for

		// �迭 �� ����ȭ (��ǻ��)
		for (int i = 0; i < 200; i++)
		{
			dest = rand() % 5;
			sour = rand() % 5;
			test = rand() % 5;
			change = rand() % 5;

			temp = comBingo[dest][sour];
			comBingo[dest][sour] = comBingo[test][change];
			comBingo[test][change] = temp;
		}// end of for

		// �� ���� �ʱ�ȭ
		bool game = true;
		playerBingoCount = 0;
		comBingoCount = 0;

		// ���� �÷���
		while (game)
		{
			// �÷��̾��� ���� ��
			cout << "�÷��̾��� ���� ��" << endl;
			cout << "�÷��̾� ���� �� : " << playerBingoCount << endl;

			for (int i = 0; i < 5; i++)
			{
				cout << "====================================" << endl;
				for (int j = 0; j < 5; j++)
				{
					if (playerBingo[i][j] > 25)
					{
						cout << "|" << (char)playerBingo[i][j] << "|" << "\t";
					}
					else
					{
						cout << "|" << playerBingo[i][j] << "|" << "\t";
					}
				}
				cout << endl;
			}// end of for
			cout << "====================================" << endl;

			cout << endl;

			// ��ǻ���� ���� ��
			cout << "��ǻ���� ���� ��" << endl;
			cout << "��ǻ�� ���� �� : " << comBingoCount << endl;

			for (int i = 0; i < 5; i++)
			{
				cout << "====================================" << endl;
				for (int j = 0; j < 5; j++)
				{
					if (comBingo[i][j] > 25)
					{
						cout << "|" << (char)comBingo[i][j] << "|" << "\t";
					}
					else
					{
						cout << "|" << comBingo[i][j] << "|" << "\t";
					}
				}
				cout << endl;
			}// end of for
			cout << "====================================" << endl;

			cout << endl;

			// �÷��̾� ���� ����
			bool playerChoice = true;
			while (playerChoice)
			{
				cout << "���ڸ� �Է��Ͻÿ� : ";
				cin >> chooseNum;				

				if (chooseNum < 26)
				{
					for (int i = 0; i < 500; i++)
					{
						if (checkchooseNum[i] == chooseNum)
						{
							cout << "�ߺ� ���� ����" << endl;
							playerChoice = true;
							break;
						}
						else
						{
							playerChoice = false;
							cout << "�´� ����" << endl;
							break;
						}
					}
				}
				else
				{
					cout << "������ ���� �ʰ�." << endl;
				}
			}
			checkchooseNum[playerCount] = chooseNum;
			playerCount++;

			// ��ǻ�� ���� Ȯ��
			int comChoose;

			bool comChoice = true;
			while (comChoice)
			{
				//cout << "�÷��̾� 2 ���ڸ� �Է��Ͻÿ� : ";
				//cin >> comChoose;
				comChoose = rand() % 25 + 1;
				if (chooseNum < 26)
				{
					for (int i = 0; i < 500; i++)
					{
						if (checkcomChoose[i] == comChoose)
						{
							//cout << "�ߺ� ���� ����" << endl;
							comChoice = true;
							break;
						}
						else
						{
							comChoice = false;
							break;
						}
					}
				}
				else
				{
					cout << "������ ���� �ʰ�." << endl;
				}
			}			
			checkcomChoose[comCount] = comChoose;
			comCount++;
						
			cout << "�÷��̾��� ���� : " << chooseNum << endl;

			//�÷��̾��� ���ÿ� ���� �÷��̾� ���̺� ��ȭ
			for (int i = 0; i < 5; i++)
			{
				for (int j = 0; j < 5; j++)
				{
					if (chooseNum == playerBingo[i][j])
					{
						int a = 64;
						playerBingo[i][j] = a;
					}
					if (comChoose == playerBingo[i][j])
					{
						int a = 64;
						playerBingo[i][j] = a;
					}
				}
			}// end of for

			// ��ǻ���� ���ÿ� ���� ��ǻ�� ���̺� ��ȭ
			for (int i = 0; i < 5; i++)
			{
				for (int j = 0; j < 5; j++)
				{
					if (chooseNum == comBingo[i][j])
					{
						int a = 64;
						comBingo[i][j] = a;
					}
					if (comChoose == comBingo[i][j])
					{
						int a = 64;
						comBingo[i][j] = a;
					}
				}
			}// end of for
			cout << "��ǻ���� ���� : " << comChoose << endl;

			// ������ Ȯ��
			if (horizontalCount == true)
			{
				if (playerBingo[0][0] == 64 && playerBingo[0][1] == 64 && playerBingo[0][2] == 64 && playerBingo[0][3] == 64 && playerBingo[0][4] == 64)
				{
					playerBingoCount++;
					horizontalCount = false;
				}
			}

			if (horizontalCount1 == true)
			{
				if (playerBingo[1][0] == 64 && playerBingo[1][1] == 64 && playerBingo[1][2] == 64 && playerBingo[1][3] == 64 && playerBingo[1][4] == 64)
				{
					playerBingoCount++;
					horizontalCount1 = false;
				}
			}

			if (horizontalCount2 == true)
			{
				if (playerBingo[2][0] == 64 && playerBingo[2][1] == 64 && playerBingo[2][2] == 64 && playerBingo[2][3] == 64 && playerBingo[2][4] == 64)
				{
					playerBingoCount++;
					horizontalCount2 = false;
				}
			}

			if (horizontalCount3 == true)
			{
				if (playerBingo[3][0] == 64 && playerBingo[3][1] == 64 && playerBingo[3][2] == 64 && playerBingo[3][3] == 64 && playerBingo[3][4] == 64)
				{
					playerBingoCount++;
					horizontalCount3 = false;
				}
			}

			if (horizontalCount4 == true)
			{
				if (playerBingo[4][0] == 64 && playerBingo[4][1] == 64 && playerBingo[4][2] == 64 && playerBingo[4][3] == 64 && playerBingo[4][4] == 64)
				{
					playerBingoCount++;
					horizontalCount4 = false;
				}
			}
			// ������ ��

			// ������ Ȯ��
			if (verticalCount == true)
			{
				if (playerBingo[0][0] == 64 && playerBingo[1][0] == 64 && playerBingo[2][0] == 64 && playerBingo[3][0] == 64 && playerBingo[4][0] == 64)
				{
					playerBingoCount++;
					verticalCount = false;
				}
			}

			if (verticalCount1 == true)
			{
				if (playerBingo[0][1] == 64 && playerBingo[1][1] == 64 && playerBingo[2][1] == 64 && playerBingo[3][1] == 64 && playerBingo[4][1] == 64)
				{
					playerBingoCount++;
					verticalCount1 = false;
				}
			}

			if (verticalCount2 == true)
			{
				if (playerBingo[0][2] == 64 && playerBingo[1][2] == 64 && playerBingo[2][2] == 64 && playerBingo[3][2] == 64 && playerBingo[4][2] == 64)
				{
					playerBingoCount++;
					verticalCount2 = false;
				}
			}

			if (verticalCount3 == true)
			{
				if (playerBingo[0][3] == 64 && playerBingo[1][3] == 64 && playerBingo[2][3] == 64 && playerBingo[3][3] == 64 && playerBingo[4][3] == 64)
				{
					playerBingoCount++;
					verticalCount3 = false;
				}
			}

			if (verticalCount4 == true)
			{
				if (playerBingo[0][4] == 64 && playerBingo[1][4] == 64 && playerBingo[2][4] == 64 && playerBingo[3][4] == 64 && playerBingo[4][4] == 64)
				{
					playerBingoCount++;
					verticalCount4 = false;
				}
			}
			// ������ ��

			// �밢�� ����
			if (diagonalCount == true)
			{
				if (playerBingo[0][0] == 64 && playerBingo[1][1] == 64 && playerBingo[2][2] == 64 && playerBingo[3][3] == 64 && playerBingo[4][4] == 64)
				{
					playerBingoCount++;
					diagonalCount = false;
				}
			}

			if (diagonalCount1 == true)
			{
				if (playerBingo[0][4] == 64 && playerBingo[1][3] == 64 && playerBingo[2][2] == 64 && playerBingo[3][1] == 64 && playerBingo[4][0] == 64)
				{
					playerBingoCount++;
					diagonalCount1 = false;
				}
			}
			// �밢�� ��

			// ��ǻ�� ���̺� ������ Ȯ��
			if (c_horizontalCount == true)
			{
				if (comBingo[0][0] == 64 && comBingo[0][1] == 64 && comBingo[0][2] == 64 && comBingo[0][3] == 64 && comBingo[0][4] == 64)
				{
					comBingoCount++;
					c_horizontalCount = false;
				}
			}

			if (c_horizontalCount1 == true)
			{
				if (comBingo[1][0] == 64 && comBingo[1][1] == 64 && comBingo[1][2] == 64 && comBingo[1][3] == 64 && comBingo[1][4] == 64)
				{
					comBingoCount++;
					c_horizontalCount1 = false;
				}
			}

			if (c_horizontalCount2 == true)
			{
				if (comBingo[2][0] == 64 && comBingo[2][1] == 64 && comBingo[2][2] == 64 && comBingo[2][3] == 64 && comBingo[2][4] == 64)
				{
					comBingoCount++;
					c_horizontalCount2 = false;
				}
			}

			if (c_horizontalCount3 == true)
			{
				if (comBingo[3][0] == 64 && comBingo[3][1] == 64 && comBingo[3][2] == 64 && comBingo[3][3] == 64 && comBingo[3][4] == 64)
				{
					comBingoCount++;
					c_horizontalCount3 = false;
				}
			}

			if (c_horizontalCount4 == true)
			{
				if (comBingo[4][0] == 64 && comBingo[4][1] == 64 && comBingo[4][2] == 64 && comBingo[4][3] == 64 && comBingo[4][4] == 64)
				{
					comBingoCount++;
					c_horizontalCount4 = false;
				}
			}
			// ������ ��

			// ������ Ȯ��
			if (c_verticalCount == true)
			{
				if (comBingo[0][0] == 64 && comBingo[1][0] == 64 && comBingo[2][0] == 64 && comBingo[3][0] == 64 && comBingo[4][0] == 64)
				{
					comBingoCount++;
					c_verticalCount = false;
				}
			}

			if (c_verticalCount1 == true)
			{
				if (comBingo[0][1] == 64 && comBingo[1][1] == 64 && comBingo[2][1] == 64 && comBingo[3][1] == 64 && comBingo[4][1] == 64)
				{
					comBingoCount++;
					c_verticalCount1 = false;
				}
			}

			if (c_verticalCount2 == true)
			{
				if (comBingo[0][2] == 64 && comBingo[1][2] == 64 && comBingo[2][2] == 64 && comBingo[3][2] == 64 && comBingo[4][2] == 64)
				{
					comBingoCount++;
					c_verticalCount2 = false;
				}
			}

			if (c_verticalCount3 == true)
			{
				if (comBingo[0][3] == 64 && comBingo[1][3] == 64 && comBingo[2][3] == 64 && comBingo[3][3] == 64 && comBingo[4][3] == 64)
				{
					comBingoCount++;
					c_verticalCount3 = false;
				}
			}

			if (c_verticalCount4 == true)
			{
				if (comBingo[0][4] == 64 && comBingo[1][4] == 64 && comBingo[2][4] == 64 && comBingo[3][4] == 64 && comBingo[4][4] == 64)
				{
					comBingoCount++;
					c_verticalCount4 = false;
				}
			}
			// ������ ��

			// �밢�� ����
			if (c_diagonalCount == true)
			{
				if (comBingo[0][0] == 64 && comBingo[1][1] == 64 && comBingo[2][2] == 64 && comBingo[3][3] == 64 && comBingo[4][4] == 64)
				{
					comBingoCount++;
					c_diagonalCount = false;
				}
			}

			if (c_diagonalCount1 == true)
			{
				if (comBingo[0][4] == 64 && comBingo[1][3] == 64 && comBingo[2][2] == 64 && comBingo[3][1] == 64 && comBingo[4][0] == 64)
				{
					comBingoCount++;
					c_diagonalCount1 = false;
				}
			}
			// �밢�� ��

			// ���� �Ǵ�
			if (playerBingoCount >= 3)
			{
				cout << "�÷��̾� WIN!" << endl;
				game = false;

				system("pause");
			}
			else if(comBingoCount >= 3)
			{
				cout << "��ǻ�� WIN!" << endl;
				game = false;

				system("pause");
			}

			Sleep(1000);
			system("cls");
		}
	}	
	system("pause");
	return 0;
}