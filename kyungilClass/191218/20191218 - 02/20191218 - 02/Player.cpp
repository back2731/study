#include "Player.h"

Player::Player()
{
}

Player::~Player()
{
}

void Player::init()
{
	publicMoney = 20000;
	familyMoney = 50000;

	cout << "�ڽ� Ŭ����" << endl;

	cout << "�츮�� �Ѵ� ��Ȱ�� : " << publicMoney << endl;
	cout << "�濡�� �ֿ� �� : " << familyMoney << endl;
}
