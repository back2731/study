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
	�迭�� �� ���� NULL���ڰ� �ְ� NULL���ڸ� ������ ũ�⸦ �ν��Ѵ�.
	char name[10] = "��������";		: ��
	char name[10] = "����������";	: �ȵ�

	NULL���ڸ� �ݵ�� ���Խ��Ѿ� �ǹǷ� ���ڸ� ������ �ݵ�� +1 ������ �Ҵ��ؾ� �Ѵ�.
	*/
	char name[10] = "��������";
	
	cout << name << endl;

	system("pause");
	return 0;
}