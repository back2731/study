#include <iostream>
#include <string>
using namespace std;
/*
	����ü : �������� ����ü
	���α׷����߿� ���Ǵ� ���� �������� �ϳ��� ��� �����ϱ� ���� ����ü�� ����Ѵ�.

	
	����ü�� ������ �ۺ�
	Ŭ������ ���������ڰ� �ۺ� / �����̺� �� ���������ִ�.
	
	ex) ������ ������(�̸�, ����, �ɷ�ġ ���...)�����Ѵٰ� �� ��
	�ϳ��� ���� �����͸� �����ϱ� ���ؼ� ���� ������ �ʿ��ϴ�.
	�̷� �� ����ü�� �̿��ϸ� �����ϱ� �����ϴ�.	
	
	// ���� ����
	struct Monster
	{
		int Hp;				// �������1
		int Mp;				// �������2
		int Atk;			// �������3
		int Def;			// �������4
		string name;		// �������5
	};

	// ����� �̸����� ����ü Ÿ���� �����Ѵ�.
	���ο� ���ǵ� �������� ����ü�� ������ ��������̴�.

*/
//struct Monster
//{
//	int Hp;				// �������
//	int Mp;				// �������
//	int Atk;			// �������
//	int Def;			// �������
//	string name;		// �������
//};


struct tagUnit
{
	string name;
	int Hp;
	float Atk;
	bool Die;
};
/*
	���� �غ���
	����ü�� �̿��ؼ� �������� �����ϱ�.
	�����̸�, ��������, ��ȭ��ȣ, �������, ��°�, ����, ����̰�?
	�����ϴ� ���� �����ϴ� ����

*/
struct family
{
	string name;
	int age;
	string phoneNumber;
	string birthDate;
	string state;
	string gender;
	bool human;
	string food;
	string game;
	string idealtype;
};

int main()
{
	/* 
	����ü ��������� �����ϱ� ���ؼ���
	.�����ڸ� �̿��Ѵ�. (�������)
	*/

	/*tagUnit marin;
	
	cout << "���� �������̽�" << endl;
	cout << "==============================" << endl;

	marin.name = "�غ�";
	marin.Hp = 100;
	marin.Atk = 5.5;
	marin.Die = false;

	cout << "�̸� : " << marin.name << endl;

	cout << "Hp  : " << marin.Hp  << endl;
	cout << "Atk : " << marin.Atk << endl;
	cout << "Die : " << marin.Die << endl;

	tagUnit zergling;

	cout << "���۸� �������̽�" << endl;
	cout << "==============================" << endl;


	zergling.name = "���۸�";
	zergling.Hp = 50;
	zergling.Atk = 2.5;
	zergling.Die = true;

	cout << "�̸� : " << zergling.name << endl;

	cout << "Hp  : " << zergling.Hp << endl;
	cout << "Atk : " << zergling.Atk << endl;
	cout << "Die : " << zergling.Die << endl;

	string name;
	int phoneNumber;
	string game;
*/

	family father;
	father.name = "������";
	father.age = 52;
	father.birthDate = "0501";
	father.gender = "����";
	father.human = true;
	father.state = "����";
	father.food = "����";
	father.phoneNumber = "010-0000-0000";
	father.game = "����";
	father.idealtype = "?";

	cout << "�̸� : " << father.name << endl;
	cout <<	"���� : " << father.age << endl;
	cout << "���� : " << father.birthDate << endl;
	cout << "���� : " << father.gender << endl;
	cout << "��� : " << father.human << endl;
	cout << "��°� : " << father.state << endl;
	cout << "��ȭ��ȣ : " << father.phoneNumber << endl;
	cout << "�����ϴ� ���� : " << father.food << endl;
	cout << "�����ϴ� ���� : " << father.game << endl;
	cout << "�̻��� : " << father.idealtype << endl;
	cout << "==============================" << endl;
	
	family mother;
	mother.name = "�����";
	mother.age = 50;
	mother.birthDate = "1202";
	mother.gender = "����";
	mother.human = true;
	mother.state = "����";
	mother.food = "���";
	mother.phoneNumber = "010-0000-0000";
	mother.game = "����?";
	mother.idealtype = "?";

	cout << "�̸� : " << mother.name << endl;
	cout << "���� : " << mother.age << endl;
	cout << "���� : " << mother.birthDate << endl;
	cout << "���� : " << mother.gender << endl;
	cout << "��� : " << mother.human << endl;
	cout << "��°� : " << mother.state << endl;
	cout << "��ȭ��ȣ : " << mother.phoneNumber << endl;
	cout << "�����ϴ� ���� : " << mother.food << endl;
	cout << "�����ϴ� ���� : " << mother.game << endl;
	cout << "�̻��� : " << mother.idealtype << endl;
	cout << "==============================" << endl;

	family my;
	my.name = "�����";
	my.age = 28;
	my.birthDate = "0617";
	my.gender = "����";
	my.human = true;
	my.state = "����";
	my.food = "���";
	my.phoneNumber = "010-2597-9206";
	my.game = "�����ϸ� �� ������";
	my.idealtype = "?";

	cout << "�̸� : " << my.name << endl;
	cout << "���� : " << my.age << endl;
	cout << "���� : " << my.birthDate << endl;
	cout << "���� : " << my.gender << endl;
	cout << "��� : " << my.human << endl;
	cout << "��°� : " << my.state << endl;
	cout << "��ȭ��ȣ : " << my.phoneNumber << endl;
	cout << "�����ϴ� ���� : " << my.food << endl;
	cout << "�����ϴ� ���� : " << my.game << endl;
	cout << "�̻��� : " << my.idealtype << endl;
	cout << "==============================" << endl;

	family sister;
	sister.name = "������";
	sister.age = 26;
	sister.birthDate = "0702";
	sister.gender = "����";
	sister.human = true;
	sister.state = "����";
	sister.food = "���";
	sister.phoneNumber = "010-0000-0000";
	sister.game = "����";
	sister.idealtype = "?";

	cout << "�̸� : " << sister.name << endl;
	cout << "���� : " << sister.age << endl;
	cout << "���� : " << sister.birthDate << endl;
	cout << "���� : " << sister.gender << endl;
	cout << "��� : " << sister.human << endl;
	cout << "��°� : " << sister.state << endl;
	cout << "��ȭ��ȣ : " << sister.phoneNumber << endl;
	cout << "�����ϴ� ���� : " << sister.food << endl;
	cout << "�����ϴ� ���� : " << sister.game << endl;
	cout << "�̻��� : " << sister.idealtype << endl;
	cout << "==============================" << endl;

	system("pause");
	return 0;
}