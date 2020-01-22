/*
	객체 objects - 메모리에 저장된 것을 객체라고 부른다.
	변수 variables - 메모리에 담겨있는 객체를 사용하기 위해 정해주는 이름
	Left-values Right-values
	L벨류 R벨류
	초기화 initialization
	대입 assignment

	초기화를 안 했을 때의 문제점
*/

#include <iostream>

int main()
{
	//// x 라는 정수형(integer type) 변수를 선언했다.
	//int x = 123; // initialization x라는 메모리를 잡을때 123을 바로 넣어준다. 초기화 한다.


	//x = 123; // = assignment / & ampersand

	//// L벨류 - 주소를 가지고 있는 것
	//// R벨류 - 임시로 저장되어있는 주소. 잠깐 작동을하고 사라짐 ex) 123, x + 2
	//
	//std::cout << x << std::endl;
	//std::cout << &x << std::endl;

	int x = 1;
	x = x + 2;
	std::cout << x << std::endl;

	int y = x;
	std::cout << y << std::endl;
	
	std::cout << x + y << std::endl;

	std::cout << x << std::endl;


	return 0;
}

