#include <iostream>
#include <time.h>

using namespace std;

int main()
{
	// �õ� �� �ʱ�ȭ -> ������ �Ҷ� ���� ���� ���Ѵ�.
	srand(time(NULL));

	// rand() -> ������ ���ڸ� �̾Ƴ� �� ����Ѵ�.
	int rndNum = rand();
	cout << rndNum << endl;

	// rand() % 5		-> 0 ~ 4 ���� ������ ���ڸ� �̾� ����.
	int randomNumber = rand() % 5;
	cout << randomNumber << endl;
	// rand() % 5 + 1;	-> 1 ~ 5 ���� ������ ���ڸ� �̾� ����.
	int randomNumber1 = rand() % 5 + 1;
	cout << randomNumber1 << endl;

	cout << "������ ���� ���� ��ī����" << endl;

	int orcHp = 500;
	int orcAtk = rand() % 50;
	int humanHp = 500;
	int humanAtk = rand() % 50;
	int healingPotion = 200;

	cout << "A�� B�� ������!!" << endl;
	cout << "A�� ����!" << endl;
	
	humanHp = humanHp - orcAtk;

	cout << "���� " << orcAtk << "�� �޾Ƽ� B�� ü����" << humanHp << "��(��) �Ǿ���." << endl;
	
	orcHp -= humanAtk;
	cout << "B�� �ݰ�!!" << humanAtk << "��ŭ �ݰ��� ����! A�� ü����" << orcHp << "��ŭ ���Ҵ�!" << endl;

	humanHp += healingPotion;

	cout << "������ �ָӴϿ��� ����ĵ�� ���� ���̴�. ü���� " << healingPotion << "��ŭ ȸ��!" << endl;
	cout << "B�� ���� ü���� : " << humanHp << endl;

	cout << sizeof(double);
	return 0;
}