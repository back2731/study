#include <iostream>
#include <string>

using namespace std;

const char 
CORECT_NUMBER = 100;

int main()
{
	char str[CORECT_NUMBER] = { };
	char change[CORECT_NUMBER] = { };

	cout << "�۾��� �Է��Ͻÿ�." << endl;
	cin >> str;

	for (int i = 0; i < CORECT_NUMBER; i++)
	{
		change[i] = str[i];
	}

	for (int i = 0; i < CORECT_NUMBER; i++)
	{
		change[i] = str[CORECT_NUMBER - i - 1];
	}

	cout << "�Է��� �۾��� : ";
	for (int i = 0; i < CORECT_NUMBER; i++)
	{
		cout << str[i];
		if (str[i] == 0)
		{
			break;
		}
	}
	cout << "�Դϴ�." << endl;

	cout << "������ �۾��� : ";
	for (int i = 0; i < CORECT_NUMBER; i++)
	{
		if (change[i] == 0)
		{
			continue;
		}
		cout << change[i];
	}
	cout << endl;

	cout << "������ �۾��� ¦����°�� :";
	for (int i = 0; i < CORECT_NUMBER; i+=2)
	{
		if (change[i] == 0)
		{
			continue;
		}
		cout << change[i];
	}
	cout << endl;

	cout << "������ �۾��� Ȧ����°�� :";
	for (int i = 1; i < CORECT_NUMBER; i += 2)
	{
		if (change[i] == 0)
		{
			continue;
		}
		cout << change[i];
	}
	cout << endl;
	/*
		�ָ�����
		1. ����, ������ ���� strcpy, strcmp, strtok
		2. ���ڿ��� ������. abcdef�� fedcba�� ������.
		3. ���ڿ��� ��������, ¦����°�� ����ϵ���.
		4. �Է¹޾Ƽ�
	*/
	system("pause");
	return 0;
}