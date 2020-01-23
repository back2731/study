#include <iostream>

using namespace std;

/* 
반복문
반복시킨다.
while문 / for문
for(초기값, 조건, 증감문)

for (int i = 0; i < 10; i++)
{

}

제어문
1. break	: 연산을 중지하고 빠져나간다.
2. return	: 값을 반환하고(내뱉고) 나간다.
3. continue	: 연산을 건너뛴다. (마치 처음으로 가는것 처럼 ex) 예외처리)
4. go to	: 쓰지마
*/
int main()
{
	// int i = 0	: 초기값
	// i < 5		: 조건
	// i++ / i--	: 증감문
	/*for (int i = 0; i < 5; i++)
	{
		cout << "경일게임 아카데미" << endl;
	}*/

	// 지금 해볼것

	/*int sumNum = 0;

	for (int i = 1; i <= 100; i++)
	{
		sumNum += i;
	}

	cout << sumNum << endl;*/

	//cout << "좋아하는 숫자를 입력하시오. : " << endl;
	//int num;
	//cin >> num;

	//for (int i = 1; i < 10; i++)
	//{
	//	cout << num << " x " << i << " = " << num * i << endl;
	//}

	//for (int i = 2; i < 10; i++)
	//{
	//	for (int k = 1; k < 10; k++)
	//	{
	//		cout << i << " x " << k << " = " << i * k << endl;
	//	}
	//	cout << endl;
	//}

	int num;
	cout << "숫자를 입력하시오." << endl;
	cin >> num;

	for (int i = 1; i < num; i++)
	{
		//만약 i를 2로 나눴을때 나머지가 0이 아니라면
		if (i % 2 != 0)// 건너 뛰어라
		{
			continue;
		}
		cout << i << endl;
	}
	system("pause");
	return 0;
}