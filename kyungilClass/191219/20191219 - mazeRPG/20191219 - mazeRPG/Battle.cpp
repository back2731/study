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
		cout << "전투를 시작합니다." << endl;
		cout << "1. 공격 2. 도주" << endl;
		cin >> input;

		switch (input)
		{
		case 1:
			cout << "공격!" << endl;
			m_player->setHp(m_player->getHp() - m_monster->setmonsterAtk());
			cout << "플레이어의 Hp : ";
			m_player->showHp();

			m_monster->setmonsterHp(m_monster->getmonsterHp() - m_player->setAtk());
			cout << "보스의 Hp : ";
			m_monster->showmonsterHp();

			if (m_monster->monsterHp <= 0)
			{
				cout << "보스를 쓰러뜨렸습니다." << endl;
				battle = false;
				break;
			}
			break;
		case 2:
			cout << "도주!" << endl;
			battle = false;
			break;
		default:
			cout << "다시입력해주세요." << endl;
			break;
		}
	}
}
