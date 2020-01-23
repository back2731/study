#include <iostream>
#include <string>

using namespace std;

const char 
CORECT_NUMBER = 100;

int main()
{
	char str[CORECT_NUMBER] = { };
	char change[CORECT_NUMBER] = { };

	cout << "글씨를 입력하시오." << endl;
	cin >> str;

	for (int i = 0; i < CORECT_NUMBER; i++)
	{
		change[i] = str[i];
	}

	for (int i = 0; i < CORECT_NUMBER; i++)
	{
		change[i] = str[CORECT_NUMBER - i - 1];
	}

	cout << "입력한 글씨는 : ";
	for (int i = 0; i < CORECT_NUMBER; i++)
	{
		cout << str[i];
		if (str[i] == 0)
		{
			break;
		}
	}
	cout << "입니다." << endl;

	cout << "뒤집힌 글씨는 : ";
	for (int i = 0; i < CORECT_NUMBER; i++)
	{
		if (change[i] == 0)
		{
			continue;
		}
		cout << change[i];
	}
	cout << endl;

	cout << "뒤집힌 글씨의 짝수번째는 :";
	for (int i = 0; i < CORECT_NUMBER; i+=2)
	{
		if (change[i] == 0)
		{
			continue;
		}
		cout << change[i];
	}
	cout << endl;

	cout << "뒤집힌 글씨의 홀수번째는 :";
	for (int i = 1; i < CORECT_NUMBER; i += 2)
	{
		if (change[i] == 0)
		{
			continue;
		}
		cout << change[i];
	}
	cout << endl;
	/*
		주말과제
		1. 복습, 포인터 공부 strcpy, strcmp, strtok
		2. 문자열을 뒤집자. abcdef면 fedcba로 뒤집기.
		3. 문자열을 뒤집지만, 짝수번째만 출력하도록.
		4. 입력받아서
	*/
	system("pause");
	return 0;
}