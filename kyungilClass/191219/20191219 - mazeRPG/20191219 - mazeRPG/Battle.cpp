#include "Battle.h"



Battle::Battle()
{
	m_player = new Player;
	m_monster = new Monster;
}


Battle::~Battle()
{
	delete m_player;
	delete m_monster;
}

void Battle::battleSet()
{
	m_player->getHp();
	m_player->setAtk();
}

void Battle::doBattle()
{
	int input;

	bool battle = true;
	while (battle)
	{
		cout << "������ �����մϴ�." << endl;
		cout << "1. ���� 2. ����" << endl;
		cin >> input;

		switch (input)
		{
		case 1:
			cout << "����!" << endl;
			m_player->setHp(m_player->getHp() - m_monster->setmonsterAtk());
			cout << "�÷��̾��� Hp : ";
			m_player->showHp();

			m_monster->setmonsterHp(m_monster->getmonsterHp() - m_player->setAtk());
			cout << "������ Hp : ";
			m_monster->showmonsterHp();

			if (m_monster->monsterHp <= 0)
			{
				cout << "������ �����߷Ƚ��ϴ�." << endl;
				battle = false;
				break;
			}
			break;
		case 2:
			cout << "����!" << endl;
			battle = false;
			break;
		default:
			cout << "�ٽ��Է����ּ���." << endl;
			break;
		}
	}
}
