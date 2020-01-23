#include <iostream>	
using namespace std;

// # = 전 처리기. 인풋 아웃풋 스트림 - 라이브러리
// int = 정수형 void = 공허
// {} 중괄호 scope

int main()
{
	// cout -> c++
	// printf -> c
	// << 쉬프트 연산

	cout << "Hello, world!" << endl;
	cout << "아아, 이것은 지옥이라는 것이다." << endl;
	cout << "춥다.";
	cout << "★" << endl;

	int input;
	cout << "아무 숫자나 입력해 보시오." << endl;
	cin >> input;
	cout << "입력한 숫자는 : " << input << endl;

	// 변수 -> 변하는 수
	// = : 대입 연산자. ex) a = 1 -> 1을 a에 대입한다.
	// int	= 4 byte 32 bit 정수형
	// char = 1 byte 8 bit 문자
	/*
	int		: 정수형
	float	: 실수형
	char	: 문자
	double	
	short	
	bool	: 참과 거짓을 판별. 0, 1.
	unsigned int = 양의 부호만 사용.
	const int = 값을 바꾸지 않겠다.
	*/
	
	int getMoney;
	int a = 1;
	float b = 12.12345f;
	
	char name = 'a';
	// '' -> 단일 문자 "" -> 문자열

	cout << name << endl;

	// a라는 변수가 자료형이 integer형이다.

	cout << "a에 들어간 녀석 : " << a << endl;

	system("pause");
	return 0;
}
