#include <iostream>	

using namespace std;

int main()
{
	// 복습 내용
	// 자료형이 뭐가 있냐?
	// 변수란 무엇인가? (지역, 전역)

	// 연산자
	/*
		대입 연산자		: = int num = 10;
		쉬프트 연산자		: << , >>
		사칙 연산자		: +(더하기) -(빼기) *(곱하기) /(나머지) %(나머지 연산 - 몫은 버리고 나머지)
		비교 연산자		: <, >, <=, >=, ==, !=
		논술 연산자		: and 연산 - &&, or 연산 - ||
		(and) a(참) && b(참)		-> 참
			  a(거짓) && b(참)	-> 거짓
			  a(참) && b(거짓)	-> 거짓

		(or)  a(참) || b(참)		-> 참
			  a(거짓) || b(참)	-> 참
			  a(참) || b(거짓)	-> 참
			  a(거짓) || b(거짓)	-> 거짓
	*/

	//지금 해볼것.
	
	// 3개의 수를 입력 받아 합을 구하시오

	int a;
	int b;
	int c;

	cout << "첫 번째 숫자를 입력하시오. : ";
	cin >> a;
	cout << "두 번째 숫자를 입력하시오. : ";
	cin >> b;
	cout << "세 번째 숫자를 입력하시오. : ";
	cin >> c;

	cout << "입력하신 숫자의 합은 : " << a + b + c << " 입니다." << endl;

	system("pause");
	return 0;
}