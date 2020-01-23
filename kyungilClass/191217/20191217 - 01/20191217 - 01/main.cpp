#include <iostream>

using namespace std;

/* 
- Call_By_Value
�⺻������ C���� �����ϴ� �����. �Լ����� ���� ������ ����
�����ϴ� ����̴�. ���ڷ� ���޵Ǵ� ������ �Լ��� �Ű������� �����Ѵ�.
�̷��� �Ǹ� ���ڷ� ������ �����ʹ� ������ ������ �ȴ�.
�Ű������� �����ص� ������ �������� ������ ��ġ�� �ʴ´�.
�������� �ٲ� �ʿ䰡 ���� ��쿡 ����Ѵ�.
*/
void Swap(int a, int b);

/*
- Call_By_Reference
�Լ����� ���� �����ϴ� ��� �ּҰ��� �����ϴ� ����� Call_By_Reference��� �Ѵ�.
�����͸� �̿��� �ּҰ��� �Ѱ��ִ� ���.
��, ������ ���� a�� b�� ������ a�� b�� �ּҰ� ���� �Ǿ� ���� ���� ����ȴ�.
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
