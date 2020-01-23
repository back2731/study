#include <iostream>
#include <time.h>
using namespace std;

//void shuffleNum()
//{
//	int lottoNum[45];
//
//	int dest, sour, temp;	// ���ÿ� ����
//
//	srand(time(NULL));
//	
//	// ���ÿ� �˰���
//	for (int i = 0; i < 777; i++)
//	{
//		dest = rand() % 45;
//		sour = rand() % 45;
//
//		temp = lottoNum[dest];
//		lottoNum[dest] = lottoNum[sour];
//		lottoNum[sour] = temp;
//	}
//}

/*
	���� �غ���
	�ζ� ��ȣ �����⸦ ����� ���ÿ�.

	1. �ζ� 45��
	2. �迭 �ʱ�ȭ
*/

int main()
{
	int lottoNum[45];
	int dest, sour, temp;	// ���ÿ� ����
	int myLotto[6];

	for (int i = 0; i < 6; i++)
	{
		cout << i + 1 << "��° ��ȣ�� �Է��Ͻÿ�. : ";
		cin >> myLotto[i];
	}
	cout << endl;

	srand(time(NULL));
		
	for (int i = 0; i < 45; i++)
	{
		lottoNum[i] = i + 1;
	}

	// ���ÿ� �˰���
	for (int i = 0; i < 777; i++)
	{
		dest = rand() % 45;
		sour = rand() % 45;

		temp = lottoNum[dest];
		lottoNum[dest] = lottoNum[sour];
		lottoNum[sour] = temp;
	}

	/*
	��÷ �׽�Ʈ��
	lottoNum[0] = 1;
	lottoNum[1] = 2;
	lottoNum[2] = 3;
	lottoNum[3] = 4;
	lottoNum[4] = 5;
	lottoNum[5] = 6;
	lottoNum[6] = 7;
	*/

	// ��÷ ��ȣ ��ǥ
	for (int i = 0; i < 6; i++)
	{
		cout << i + 1 << "��° ��ȣ  : " << lottoNum[i] << endl;
	}
	cout << "���ʽ� ��ȣ : " << lottoNum[6] << endl;
	cout << endl;

	// ��÷ ����
	int count = 0;		// ��÷ ���� �Ǻ�
	int bonus = 0;		// ���ʽ� ��÷ �Ǻ�
	for (int i = 0; i < 6; i++)
	{
		for (int j = 0; j < 6; j++)
		{
			if (myLotto[j] == lottoNum[i])
			{
				count++;
				break;
			}
			if (myLotto[j] == lottoNum[6])
			{
				bonus++;
				break;
			}
		}
	}

	// ��� ����
	if (count == 6)
	{
		cout << "6�� �¾Ҵ�! 1�� ��÷!" << endl;
	}
	if (count == 5 && bonus == 1)
	{
		cout << "���ʽ��� ������ 6���� �¾Ҵ�! 2�� ��÷!" << endl;
	}
	else if (count == 5)
	{
		cout << "5�� �¾Ҵ�! 3�� ��÷!" << endl;
	}
	else if (count == 4)
	{
		cout << "4�� �¾Ҵ�! 4�� ��÷!" << endl;
	}
	else if (count == 3)
	{
		cout << "3�� �¾Ҵ�! 5�� ��÷!" << endl;
	}
	else if (count == 2)
	{
		cout << "2�� �¾Ҵ�! �̰� ���̴�!" << endl;
	}
	else if (count == 1)
	{
		cout << "1�� �¾Ҵ�! ��!" << endl;
	}

	system("pause");
	return 0;
}