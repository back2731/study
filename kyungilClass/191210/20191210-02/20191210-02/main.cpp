#include <iostream>
using namespace std;

int main()
{
	int arr[10] = { 1,32,4,5,8,10,12,27,29,30 };

	for (int i = 0; i < 10; i++)
	{
		cout << arr[i] << endl;
	}

	/* 
	배열의 맨 끝에 NULL문자가 있고 NULL문자를 만나면 크기를 인식한다.
	char name[10] = "ㅁㄴㅇㄹ";		: 됨
	char name[10] = "ㅁㄴㅇㄹㅁ";	: 안됨

	NULL문자를 반드시 포함시켜야 되므로 문자를 쓸때는 반드시 +1 공간을 할당해야 한다.
	*/
	char name[10] = "ㅁㄴㅇㄹ";
	
	cout << name << endl;

	system("pause");
	return 0;
}