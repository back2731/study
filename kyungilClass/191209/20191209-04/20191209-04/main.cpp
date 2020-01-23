#include <iostream>
using namespace std;
/*
	while의 동작조건 -> ()참일때만 실행된다.
	while(true)
	기본적으로 무한루프

*/
int main()
{
	// true		= 1
	// false	= 0

	/*while (1)
	{
		cout << "블랙홀" << endl;
	}
	*/
	//지금 해볼것
	/*
	while을 이용한다.
	 1. 입력 변수가 있고
	 2. 입력을 계속 할 수 있다.
	 3. 1 ~ 10을 제외한 나머지 숫자를 입력하면 
	 4. 출력으로 "프로그램을 종료합니다." 라고 출력 
	 */

	while (true)
	{
		int num;

		cout << "숫자를 입력하시오." << endl;
		cin >> num;

		if (num > 10 || num < 1)
		{
			cout << "출력을 종료합니다." << endl;
			break;
		}
	}

	system("pause");
	return 0;
}