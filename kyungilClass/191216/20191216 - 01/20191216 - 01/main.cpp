#include <iostream>

using namespace std;
/*

	* 포인터 : 가리키다(이정표)

	메모리의 한 지점(메모리의 주소)을 가리키는 변수이다.
	포인터는 메모리의 번지를 값으로 가진다.
	즉, 포인터를 주소값이라고 이야기한다.(메모리 주소 저장)
	포인터를 선언 할 때는 *을 눌러준다.*(에스터리스크)
	모든 변수에는 메모리의 주소값을 가지고 있다. 

	int a = 10;
	-> 컴퓨터가 a가 있는 메모리 주소에 접근하여 그 공간 안에 값을 넣어준다.

	변수는 컴퓨터의 메모리에 생성된다.
	-> 메모리에 일정한 공간을 확보해 두고 원하는 값을 저장 또는 가져온다.
	
*/

int main()
{
	int num = 10;
	cout << num << endl;

	// & => 변수의 주소를 알 수 있다.
	cout << "num의 주소값" << &num << endl;

	/* 
	포인터 변수의 선언방법
		
		타입 * 변수이름
		int * P;
		p
	
	*/
	int * p;
	// 포인터 변수에는 일반적인 변수 값을 넣을 수 없다.
	// p = num 은 안되고 p = &num은 된다.
	p = &num;

	cout << "p의 값 : " << p << endl;

	// 포인터 변수에도 주소값이 개별로 있다. 
	cout << "p의 주소값 : " << &p << endl;

	// 역참조(포인터 변수 앞에 *)
	// 역참조를 하면 값을 가져오거나 변경할 수 있다.
	cout << "p(num의 값을 가지고 올 수 있다.) : " << *p << endl;
	cout << endl;
	cout << endl;

	// 현재 p는 주소값을 가지고있는 상태에서 아래와 같이 값을 변경 할 수 있다.
	*p = 777;
	
	cout << "역참조 후 num의 값이 바뀐다. 역참조 후(num의 값) : " << num << endl;
	// 포인터는 역참조를 이용해 값을 변경 할 수 있는 것이 역할이자 핵심이라고 볼 수 있다.
	
	int** pp;
	pp = &p;

	cout << "pp의 값은(p의 주소값) : " << pp << endl;
	cout << endl;

	cout << "*pp가리키고 있는 값은(num의 주소값) : " << *pp << endl;
	cout << endl;

	cout << "**pp가 가리키고 있는 값은(num의 값) : " << **pp << endl;
	cout << endl;

	**pp = 1234;

	cout << "변경 된 num의 값 : " << num << endl;

	const char* str = "abced";

	cout << str << endl;
	cout << endl;

	cout << (int*)str << endl;
	cout << endl;

	str = "decba";

	cout << str << endl;

	cout << endl;


	system("pause");
	return 0;
}