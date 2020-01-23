#include "slidePuzzle.h"

slidePuzzle::slidePuzzle()
{
}

slidePuzzle::~slidePuzzle()
{
}

void slidePuzzle::init()
{
	srand(time(NULL));

	for (int i = 24; i >= 0; i--)
	{
		num[save - i] = i;
	}

	for (int i = 0; i < 200; i++)
	{
		dest = rand() % 24;
		sour = rand() % 24;

		temp = num[dest];
		num[dest] = num[sour];
		num[sour] = temp;
	}
}

void slidePuzzle::update()
{
	while (true)
	{
		system("cls");

		cout << "0을 움직여서 퍼즐을 맞추세요." << endl;

		render();

		cout << "4 : 왼쪽	6 : 오른쪽	8 : 위쪽		2 : 아래쪽" << endl;
		cin >> key;

		if (key == 4 || key == 6 || key == 8 || key == 2);
		else
		{
			cout << "잘못된 입력입니다." << endl;
			Sleep(500);
			continue;
		}
		switch (key)
		{
		case 4:				// 왼쪽

			if (save % 5 == 0)
			{
				Sleep(500);
				break;
			}
			move = num[save];
			num[save] = num[save - 1];
			num[save - 1] = move;
			save--;

			break;

		case 6:				// 오른쪽
			if ((save + 1) % 5 == 0)
			{
				Sleep(500);
				break;
			}
			move = num[save];
			num[save] = num[save + 1];
			num[save + 1] = move;
			save++;

			break;

		case 8:				// 위쪽
			if (save < 5)
			{
				Sleep(500);
				break;
			}
			move = num[save];
			num[save] = num[save - 5];
			num[save - 5] = move;
			save -= 5;

			break;

		case 2:				// 아래쪽
			if (save >= 20)
			{
				Sleep(500);
				break;
			}
			move = num[save];
			num[save] = num[save + 5];
			num[save + 5] = move;
			save += 5;			

			break;
		default:
			break;
		}
	}
}

void slidePuzzle::render()
{
	for (int i = 0; i < 25; i++)
	{
		cout << num[i] << "\t";

		if ((i + 1) % 5 == 0)
		{
			cout << endl << endl << endl << endl;
		}
	}
}
