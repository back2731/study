#include "Player.h"

Player::Player()
{
	initPlayer();
}

Player::~Player()
{
}

void Player::initPlayer()
{
	m_atk = 10;
	m_def = 10;
}

void Player::showStatus()
{
	int addAtk = m_equipWeapon.attribute; // 어트리뷰트 검색해봐
	int addDef = m_equipArmor.attribute;

	cout << "=============스텟=============" << endl;
	cout << "공격력\t\t" << m_atk << "+" << addAtk << "="<< m_atk + addAtk << endl;
	cout << "방어력\t\t" << m_def << "+" << addDef << "="<< m_def + addDef << endl;
	cout << "=============장착=============" << endl;
	cout << "무기\t\t" << m_equipWeapon.itemName << endl;
	cout << "방어구\t\t" << m_equipArmor.itemName << endl;

}
