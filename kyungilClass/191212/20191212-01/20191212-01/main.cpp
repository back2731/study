#include <iostream>

using namespace std;
/*
	함수 : 수학에서의 함수는 어떠한 X값이 정해지면 특정수식에 의해 Y값이 정해지는 관계를 이야기 한다.
	프로그래밍에서의 함수 : 어떠한 특정 값이 입력이 되면(X), 그 입력값을 처리해서(수식), 결과값(Y)를 산출한다.

	프로그래밍에서는 입력값을 인수, 인자, 매개(파라미터)라고 하며, 결과값을 반환값이라고 한다.(return value)

	어떤 하나의 특별한 목적의 작업을 수행하기 위해 독립적으로 설계된 코드의 집합으로 볼 수 있다.

	함수를 사용하는 이유
	1. 반복적인 프로그래밍을 피할 수 있다. - 동일한 작업을 할 때에 해당 작업을 하는 함수를 사용한다.
	2. 재사용이 가능하고, 유지보수가 수월하다. 코드가 간략화 된다.

	반환값	함수이름(매개변수) 

	void
	*/

// 함수의 프로토타입
int sum(int a, int b, int c);
void print();
void test();

void deco();		// 함수 이름은 동일하지만
void deco(int a);	// 인자로 받는 값이 다른 경우
int compare(int a, int b);

/*
void deco();
void deco(int a);
함수 이름이 동일하지만, 인자로 받는 값이 다른 경우 : 함수 오버로딩

1. 매개변수 개수가 달라야 한다.
2. 매개변수 타입이 달라야한다(int형 flaot형)

단골 문제 : 함수 오버로딩과 오버라이딩의 차이점
*/
/*
	지금 해볼것.
	두 개의 수를 비교하는 함수
*/

int main()
{
	//int res = sum(1,5,8);

	//cout << res << endl;

	//deco();
	//print();
	//deco();
	//test();
	//deco();	

	int inputA;
	int inputB;
	cout << "첫 번째 숫자를 입력하시오 : ";
	cin >> inputA;
	cout << "두 번째 숫자를 입력하시오 : ";
	cin >> inputB;

	compare(inputA, inputB);
	//deco();
	//deco(input);

	system("pause");
	return 0;
}

int sum(int a, int b, int c)
{
	return a + b + c;
}

void print()
{
	cout << "Hello, World" << endl;
}

void test()
{
	cout << "안녕! 세상!" << endl;
}

void deco()
{
	cout << "=============================" << endl;
}

void deco(int a)
{
	cout << a << endl;
}

int compare(int a, int b)
{
	if (a < b)
	{
		cout << b << "이(가) " << a << "보다 크다" << endl;
	}
	else if (b < a)
	{
		cout << a << "이(가) " << b << "보다 크다" << endl;
	}
	else
	{
		cout << a << "와" << b << "는 같다." << endl;
	}

	return 0;
}

/*

만약에 (조건이 만족하면)
{
	여기의 내용을 실행하시오	
}


*/