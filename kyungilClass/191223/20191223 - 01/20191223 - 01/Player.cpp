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
	int addAtk = m_equipWeapon.attribute; // ��Ʈ����Ʈ �˻��غ�
	int addDef = m_equipArmor.attribute;

	cout << "=============����=============" << endl;
	cout << "���ݷ�\t\t" << m_atk << "+" << addAtk << "="<< m_atk + addAtk << endl;
	cout << "����\t\t" << m_def << "+" << addDef << "="<< m_def + addDef << endl;
	cout << "=============����=============" << endl;
	cout << "����\t\t" << m_equipWeapon.itemName << endl;
	cout << "��\t\t" << m_equipArmor.itemName << endl;

}
