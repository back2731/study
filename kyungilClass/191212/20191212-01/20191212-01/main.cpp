#include <iostream>

using namespace std;
/*
	�Լ� : ���п����� �Լ��� ��� X���� �������� Ư�����Ŀ� ���� Y���� �������� ���踦 �̾߱� �Ѵ�.
	���α׷��ֿ����� �Լ� : ��� Ư�� ���� �Է��� �Ǹ�(X), �� �Է°��� ó���ؼ�(����), �����(Y)�� �����Ѵ�.

	���α׷��ֿ����� �Է°��� �μ�, ����, �Ű�(�Ķ����)��� �ϸ�, ������� ��ȯ���̶�� �Ѵ�.(return value)

	� �ϳ��� Ư���� ������ �۾��� �����ϱ� ���� ���������� ����� �ڵ��� �������� �� �� �ִ�.

	�Լ��� ����ϴ� ����
	1. �ݺ����� ���α׷����� ���� �� �ִ�. - ������ �۾��� �� ���� �ش� �۾��� �ϴ� �Լ��� ����Ѵ�.
	2. ������ �����ϰ�, ���������� �����ϴ�. �ڵ尡 ����ȭ �ȴ�.

	��ȯ��	�Լ��̸�(�Ű�����) 

	void
	*/

// �Լ��� ������Ÿ��
int sum(int a, int b, int c);
void print();
void test();

void deco();		// �Լ� �̸��� ����������
void deco(int a);	// ���ڷ� �޴� ���� �ٸ� ���
int compare(int a, int b);

/*
void deco();
void deco(int a);
�Լ� �̸��� ����������, ���ڷ� �޴� ���� �ٸ� ��� : �Լ� �����ε�

1. �Ű����� ������ �޶�� �Ѵ�.
2. �Ű����� Ÿ���� �޶���Ѵ�(int�� flaot��)

�ܰ� ���� : �Լ� �����ε��� �������̵��� ������
*/
/*
	���� �غ���.
	�� ���� ���� ���ϴ� �Լ�
*/

int main()
{
	//int res = sum(1,5,8);

	//cout << res << endl;

	//deco();
	//print();
	//deco();
	//test();
	//deco();	

	int inputA;
	int inputB;
	cout << "ù ��° ���ڸ� �Է��Ͻÿ� : ";
	cin >> inputA;
	cout << "�� ��° ���ڸ� �Է��Ͻÿ� : ";
	cin >> inputB;

	compare(inputA, inputB);
	//deco();
	//deco(input);

	system("pause");
	return 0;
}

int sum(int a, int b, int c)
{
	return a + b + c;
}

void print()
{
	cout << "Hello, World" << endl;
}

void test()
{
	cout << "�ȳ�! ����!" << endl;
}

void deco()
{
	cout << "=============================" << endl;
}

void deco(int a)
{
	cout << a << endl;
}

int compare(int a, int b)
{
	if (a < b)
	{
		cout << b << "��(��) " << a << "���� ũ��" << endl;
	}
	else if (b < a)
	{
		cout << a << "��(��) " << b << "���� ũ��" << endl;
	}
	else
	{
		cout << a << "��" << b << "�� ����." << endl;
	}

	return 0;
}

/*

���࿡ (������ �����ϸ�)
{
	������ ������ �����Ͻÿ�	
}


*/