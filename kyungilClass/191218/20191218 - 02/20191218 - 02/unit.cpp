#include "unit.h"



unit::unit()
{
}


unit::~unit()
{
}

void unit::init()
{
	privateMoney = 100;
	publicMoney = 500;
	familyMoney = 3000;

	cout << "�θ� Ŭ����" << endl;
	cout << "�θ���� ���ڱ� : " << privateMoney << endl;
	cout << "�츮�� �Ѵ� ��Ȱ�� : " << familyMoney << endl;
	cout << "�濡�� �ֿ� �� : " << publicMoney << endl;
}
