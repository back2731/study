#include <iostream>
using namespace std;
/*
	while�� �������� -> ()���϶��� ����ȴ�.
	while(true)
	�⺻������ ���ѷ���

*/
int main()
{
	// true		= 1
	// false	= 0

	/*while (1)
	{
		cout << "��Ȧ" << endl;
	}
	*/
	//���� �غ���
	/*
	while�� �̿��Ѵ�.
	 1. �Է� ������ �ְ�
	 2. �Է��� ��� �� �� �ִ�.
	 3. 1 ~ 10�� ������ ������ ���ڸ� �Է��ϸ� 
	 4. ������� "���α׷��� �����մϴ�." ��� ��� 
	 */

	while (true)
	{
		int num;

		cout << "���ڸ� �Է��Ͻÿ�." << endl;
		cin >> num;

		if (num > 10 || num < 1)
		{
			cout << "����� �����մϴ�." << endl;
			break;
		}
	}

	system("pause");
	return 0;
}