#include <iostream>	
using namespace std;

// # = �� ó����. ��ǲ �ƿ�ǲ ��Ʈ�� - ���̺귯��
// int = ������ void = ����
// {} �߰�ȣ scope

int main()
{
	// cout -> c++
	// printf -> c
	// << ����Ʈ ����

	cout << "Hello, world!" << endl;
	cout << "�ƾ�, �̰��� �����̶�� ���̴�." << endl;
	cout << "���.";
	cout << "��" << endl;

	int input;
	cout << "�ƹ� ���ڳ� �Է��� ���ÿ�." << endl;
	cin >> input;
	cout << "�Է��� ���ڴ� : " << input << endl;

	// ���� -> ���ϴ� ��
	// = : ���� ������. ex) a = 1 -> 1�� a�� �����Ѵ�.
	// int	= 4 byte 32 bit ������
	// char = 1 byte 8 bit ����
	/*
	int		: ������
	float	: �Ǽ���
	char	: ����
	double	
	short	
	bool	: ���� ������ �Ǻ�. 0, 1.
	unsigned int = ���� ��ȣ�� ���.
	const int = ���� �ٲ��� �ʰڴ�.
	*/
	
	int getMoney;
	int a = 1;
	float b = 12.12345f;
	
	char name = 'a';
	// '' -> ���� ���� "" -> ���ڿ�

	cout << name << endl;

	// a��� ������ �ڷ����� integer���̴�.

	cout << "a�� �� �༮ : " << a << endl;

	system("pause");
	return 0;
}
