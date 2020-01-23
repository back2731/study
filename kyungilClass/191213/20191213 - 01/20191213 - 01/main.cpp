#include <iostream>
#include <time.h>

using namespace std;

/*
	열거형 : enumeration
	enum문
	열거형 타입의 멤버를 선택하고, 열거형 타입의 멤버들은 문자로 표현되나 실제로는 정수값이다.

	변수가 가질 수 있는 가능한 값들을 나열해 놓은 타입이다.
	어떤 변수가 가질 수 있는 값의 종류가 적정한 범위로 정해져 있다면
	정수형 대신 열거형을 쓰는것이 편리하다.

	코드의 가독성이 좋아진다.
*/

//enum color
//{
//	RED,
//	GREEN = 10,
//	BLUE,
//	BLACK,
//	WHITE
//};
//
//enum STATUS
//{
//
//};
//
//enum DIRECTION
//{
//	FORWARD,
//	LEFT,
//	RIGHT
//};
//
//enum MOTION
//{
//	R_WALK,
//	L_WALK,
//	R_RUN,
//	L_RUN,	
//};

enum STATE
{
	LEFT,
	RIGHT,
	UP,
	DOWN, 
	NO
};
int main()
{
	/*
	//cout << RED << endl;
	//cout << GREEN<< endl;
	//cout << BLUE<< endl;
	//cout << BLACK << endl;
	//cout << WHITE<< endl;	
	
	// 선언
	MOTION motion;
	// 위에 선언된 enum의 멤버를 입력받을 수 있다.
	motion = L_RUN;

	switch (motion)
	{
	case R_WALK:
		cout << "오른쪽으로 걷는다." << endl;
		break;
	case L_WALK:
		cout << "왼으로 걷는다." << endl;
		break;
	case R_RUN:
		cout << "오른쪽으로 뛴다." << endl;
		break;
	case L_RUN:
		cout << "오른쪽으로 뛴다." << endl;
		break;
	default:
		break;
	}
	*/


	/*
		지금 해볼것
		열거형을 사용해서 방향키 또는 WASD 또는 기타등등 상태를 표시할것

		방향 전환도 되어야한다.

	*/

	bool playGame = true;
	while (playGame)
	{
		STATE state;
		state = LEFT;
		char input;
		cin >> input;
		state = (STATE)input;

		if (input == 'a' || input == 'A')
		{
			state = LEFT;
		}
		else if (input == 'd' || input == 'D')
		{
			state = RIGHT;
		}
		else if (input == 'w' || input == 'W')
		{
			state = UP;
		}
		else if (input == 's' || input == 'S')
		{
			state = DOWN;
		}
		else
		{ 
			state = NO;
		}

		switch (state)
		{
		case LEFT:
			cout << "왼쪽" << endl;
			break;
		case RIGHT:
			cout << "오른쪽" << endl;
			break;
		case UP:
			cout << "위쪽" << endl;
			break;
		case DOWN:
			cout << "아래쪽" << endl;
			break;
		case NO:
			cout << "잘못 입력했다." << endl;
		default:
			break;
		}

	}
	system("pause");
	return 0;
}