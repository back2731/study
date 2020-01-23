#include <iostream>
#include <time.h>

using namespace std;

/*
	������ : enumeration
	enum��
	������ Ÿ���� ����� �����ϰ�, ������ Ÿ���� ������� ���ڷ� ǥ���ǳ� �����δ� �������̴�.

	������ ���� �� �ִ� ������ ������ ������ ���� Ÿ���̴�.
	� ������ ���� �� �ִ� ���� ������ ������ ������ ������ �ִٸ�
	������ ��� �������� ���°��� ���ϴ�.

	�ڵ��� �������� ��������.
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
	
	// ����
	MOTION motion;
	// ���� ����� enum�� ����� �Է¹��� �� �ִ�.
	motion = L_RUN;

	switch (motion)
	{
	case R_WALK:
		cout << "���������� �ȴ´�." << endl;
		break;
	case L_WALK:
		cout << "������ �ȴ´�." << endl;
		break;
	case R_RUN:
		cout << "���������� �ڴ�." << endl;
		break;
	case L_RUN:
		cout << "���������� �ڴ�." << endl;
		break;
	default:
		break;
	}
	*/


	/*
		���� �غ���
		�������� ����ؼ� ����Ű �Ǵ� WASD �Ǵ� ��Ÿ��� ���¸� ǥ���Ұ�

		���� ��ȯ�� �Ǿ���Ѵ�.

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
			cout << "����" << endl;
			break;
		case RIGHT:
			cout << "������" << endl;
			break;
		case UP:
			cout << "����" << endl;
			break;
		case DOWN:
			cout << "�Ʒ���" << endl;
			break;
		case NO:
			cout << "�߸� �Է��ߴ�." << endl;
		default:
			break;
		}

	}
	system("pause");
	return 0;
}