#include <iostream>

using namespace std;

/* 
�ݺ���
�ݺ���Ų��.
while�� / for��
for(�ʱⰪ, ����, ������)

for (int i = 0; i < 10; i++)
{

}

���
1. break	: ������ �����ϰ� ����������.
2. return	: ���� ��ȯ�ϰ�(�����) ������.
3. continue	: ������ �ǳʶڴ�. (��ġ ó������ ���°� ó�� ex) ����ó��)
4. go to	: ������
*/
int main()
{
	// int i = 0	: �ʱⰪ
	// i < 5		: ����
	// i++ / i--	: ������
	/*for (int i = 0; i < 5; i++)
	{
		cout << "���ϰ��� ��ī����" << endl;
	}*/

	// ���� �غ���

	/*int sumNum = 0;

	for (int i = 1; i <= 100; i++)
	{
		sumNum += i;
	}

	cout << sumNum << endl;*/

	//cout << "�����ϴ� ���ڸ� �Է��Ͻÿ�. : " << endl;
	//int num;
	//cin >> num;

	//for (int i = 1; i < 10; i++)
	//{
	//	cout << num << " x " << i << " = " << num * i << endl;
	//}

	//for (int i = 2; i < 10; i++)
	//{
	//	for (int k = 1; k < 10; k++)
	//	{
	//		cout << i << " x " << k << " = " << i * k << endl;
	//	}
	//	cout << endl;
	//}

	int num;
	cout << "���ڸ� �Է��Ͻÿ�." << endl;
	cin >> num;

	for (int i = 1; i < num; i++)
	{
		//���� i�� 2�� �������� �������� 0�� �ƴ϶��
		if (i % 2 != 0)// �ǳ� �پ��
		{
			continue;
		}
		cout << i << endl;
	}
	system("pause");
	return 0;
}