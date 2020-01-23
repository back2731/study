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

		cout << "0�� �������� ������ ���߼���." << endl;

		render();

		cout << "4 : ����	6 : ������	8 : ����		2 : �Ʒ���" << endl;
		cin >> key;

		if (key == 4 || key == 6 || key == 8 || key == 2);
		else
		{
			cout << "�߸��� �Է��Դϴ�." << endl;
			Sleep(500);
			continue;
		}
		switch (key)
		{
		case 4:				// ����

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

		case 6:				// ������
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

		case 8:				// ����
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

		case 2:				// �Ʒ���
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
