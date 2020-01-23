#include "mainGame.h"



mainGame::mainGame()
{
	output(1);
	// 컴파일러가 알아서 매개변수의 타입을 지정하고
	// 아래와 같은 함수로 인스턴스화 시킨다.
	/*void output(int a)
	{
		cout << "데이터 : " << a << endl;
	}*/
	output(3.556f);			// 매개변수의 타입이 float
	output("안녕하세요");	// 매개변수의 타입이 string
	cout << "====================================" << endl;

	output1(10, 10);
	cout << "====================================" << endl;
	// output1(10, 3.5f);	// 매개변수가 2개지만 typename이 하나일 경우에는 안된다.

	output2(10, "안녕");		// typename이 2개라 다른 자료형도 반환.

	output3("A","♡");
}


mainGame::~mainGame()
{
}
