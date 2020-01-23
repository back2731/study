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

	cout << "자식 클래스" << endl;

	cout << "우리집 한달 생활비 : " << publicMoney << endl;
	cout << "길에서 주운 돈 : " << familyMoney << endl;
}
