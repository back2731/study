#include <iostream>

using namespace std;

/* 
- Call_By_Value
기본적으로 C에서 지원하는 방식임. 함수에서 값을 복사한 다음
전달하는 방식이다. 인자로 전달되는 변수를 함수의 매개변수에 복사한다.
이렇게 되면 인자로 전달한 변수와는 별개의 변수가 된다.
매개변수를 변경해도 원래의 변수에는 영향을 미치지 않는다.
원본값을 바꿀 필요가 없는 경우에 사용한다.
*/
void Swap(int a, int b);

/*
- Call_By_Reference
함수에서 값을 전달하는 대신 주소값을 전달하는 방식을 Call_By_Reference라고 한다.
포인터를 이용해 주소값을 넘겨주는 방식.
즉, 포인터 변수 a와 b에 각각에 a와 b의 주소가 전달 되어 실제 값이 변경된다.
*/
void Swap(int *a, int *b);

int main()
{
	int a = 10;
	int b = 20;

	Swap(&a, &b);

	cout << a << endl;
	cout << b << endl;

	system("pause");
	return 0;
}

void Swap(int a, int b)
{
	int temp = a;
	a = b;
	b = temp;
}

void Swap(int * a, int * b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}
