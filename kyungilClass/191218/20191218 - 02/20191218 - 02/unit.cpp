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

	cout << "부모 클래스" << endl;
	cout << "부모님의 비자금 : " << privateMoney << endl;
	cout << "우리집 한달 생활비 : " << familyMoney << endl;
	cout << "길에서 주운 돈 : " << publicMoney << endl;
}
