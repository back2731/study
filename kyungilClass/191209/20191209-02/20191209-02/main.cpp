#include <iostream>

using namespace std;
/*
	switch��
	if���� ������ �༮�̴�.
	enum(������)�� ���� ������ ����Ѵ�.
*/



int main()
{
	cout << "��ƺ���� ���迡 �� ���� ȯ���մϴ�." << endl;
	cout << "������ �����Ͻÿ�. : " << endl;
	cout << "1. �ٹٸ��� 2. �Ҽ����� 3. ��ũ�θǼ� 4. �ȶ�� 5. �Ƹ���" << endl;
	cout << "���� : ";

	int selectNum;		// ���ÿ� ����
	
	cin >> selectNum;

	switch (selectNum)
	{
	case 1:				// if (selectNum == 1)
		cout << "�ٹٸ����� �����߽��ϴ�." << endl;
		break;			// break�� �ɾ�� �� �κп��� �����.
	case 2:				// if (selectNum == 2)
		cout << "�Ҽ������� �����߽��ϴ�." << endl;
		break;
	case 3:				// if (selectNum == 3)
		cout << "��ũ�θǼ��� �����߽��ϴ�." << endl;
		break;
	case 4:				// if (selectNum == 4)
		cout << "�ȶ���� �����߽��ϴ�." << endl;
		break;
	case 5:				// if (selectNum == 5)
		cout << "�Ƹ����� �����߽��ϴ�." << endl;
		break;
	default:			// else ����
		cout << "1 ~ 5 �߿��� ������ �ֽʽÿ�." << endl;
		break;
	}// end of switch


	system("pause");
	return 0;
}
