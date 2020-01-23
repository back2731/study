#include <iostream>

using namespace std;
/*
	switch문
	if문과 동일한 녀석이다.
	enum(열거형)과 거의 쌍으로 사용한다.
*/



int main()
{
	cout << "디아블로의 세계에 온 것을 환영합니다." << endl;
	cout << "직업을 선택하시오. : " << endl;
	cout << "1. 바바리안 2. 소서리스 3. 네크로맨서 4. 팔라딘 5. 아마존" << endl;
	cout << "선택 : ";

	int selectNum;		// 선택용 변수
	
	cin >> selectNum;

	switch (selectNum)
	{
	case 1:				// if (selectNum == 1)
		cout << "바바리안을 선택했습니다." << endl;
		break;			// break를 걸어야 그 부분에서 멈춘다.
	case 2:				// if (selectNum == 2)
		cout << "소서리스를 선택했습니다." << endl;
		break;
	case 3:				// if (selectNum == 3)
		cout << "네크로맨서를 선택했습니다." << endl;
		break;
	case 4:				// if (selectNum == 4)
		cout << "팔라딘을 선택했습니다." << endl;
		break;
	case 5:				// if (selectNum == 5)
		cout << "아마존을 선택했습니다." << endl;
		break;
	default:			// else 예외
		cout << "1 ~ 5 중에서 선택해 주십시오." << endl;
		break;
	}// end of switch


	system("pause");
	return 0;
}
