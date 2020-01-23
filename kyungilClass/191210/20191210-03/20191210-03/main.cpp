#include <iostream>
#include <time.h>
using namespace std;

//void shuffleNum()
//{
//	int lottoNum[45];
//
//	int dest, sour, temp;	// 셔플용 변수
//
//	srand(time(NULL));
//	
//	// 셔플용 알고리즘
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
	지금 해볼것
	로또 번호 생성기를 만들어 보시오.

	1. 로또 45개
	2. 배열 초기화
*/

int main()
{
	int lottoNum[45];
	int dest, sour, temp;	// 셔플용 변수
	int myLotto[6];

	for (int i = 0; i < 6; i++)
	{
		cout << i + 1 << "번째 번호를 입력하시오. : ";
		cin >> myLotto[i];
	}
	cout << endl;

	srand(time(NULL));
		
	for (int i = 0; i < 45; i++)
	{
		lottoNum[i] = i + 1;
	}

	// 셔플용 알고리즘
	for (int i = 0; i < 777; i++)
	{
		dest = rand() % 45;
		sour = rand() % 45;

		temp = lottoNum[dest];
		lottoNum[dest] = lottoNum[sour];
		lottoNum[sour] = temp;
	}

	/*
	당첨 테스트용
	lottoNum[0] = 1;
	lottoNum[1] = 2;
	lottoNum[2] = 3;
	lottoNum[3] = 4;
	lottoNum[4] = 5;
	lottoNum[5] = 6;
	lottoNum[6] = 7;
	*/

	// 당첨 번호 발표
	for (int i = 0; i < 6; i++)
	{
		cout << i + 1 << "번째 번호  : " << lottoNum[i] << endl;
	}
	cout << "보너스 번호 : " << lottoNum[6] << endl;
	cout << endl;

	// 당첨 판정
	int count = 0;		// 당첨 숫자 판별
	int bonus = 0;		// 보너스 당첨 판별
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

	// 결과 판정
	if (count == 6)
	{
		cout << "6개 맞았다! 1등 당첨!" << endl;
	}
	if (count == 5 && bonus == 1)
	{
		cout << "보너스를 포함한 6개가 맞았다! 2등 당첨!" << endl;
	}
	else if (count == 5)
	{
		cout << "5개 맞았다! 3등 당첨!" << endl;
	}
	else if (count == 4)
	{
		cout << "4개 맞았다! 4등 당첨!" << endl;
	}
	else if (count == 3)
	{
		cout << "3개 맞았다! 5등 당첨!" << endl;
	}
	else if (count == 2)
	{
		cout << "2개 맞았다! 이건 꽝이다!" << endl;
	}
	else if (count == 1)
	{
		cout << "1개 맞았다! 꽝!" << endl;
	}

	system("pause");
	return 0;
}