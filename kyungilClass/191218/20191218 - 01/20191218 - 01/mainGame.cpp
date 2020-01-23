#include "mainGame.h"

mainGame::mainGame()
{
}


mainGame::~mainGame()
{
	release();
}

void mainGame::init()
{
	// 플레이어 클래스 동적할당
	m_player = new Player;	
	m_player->init();

	// 에너미 클래스 동적할당
	m_enemy = new enemy;
	m_enemy->init();
}

void mainGame::release()
{
	// 동적할당한 애들 클래스 해제
	delete m_player;
	delete m_enemy;
}

void mainGame::update()
{
	/*
	cout << "플레이어 HP : " << m_player->gethp() << endl;
	cout << "각성제를 마시자" << endl;
	cout << "1. 커피, 2. 몬스터 : ";
	
	cin >> m_key;

	switch (m_key)
	{
	case 1: 
		m_player->sethp(m_player->gethp() + 100);
		break;
	case 2:
		m_player->sethp(m_player->gethp() + 300);
		break;

	default:
		cout << "다시 입력하시오." << endl;
		break;
	}

	cout << "각성제를 마신 후 체력 : " << m_player->gethp() << endl;
	*/

	while (true)
	{
		cout << "플레이어 공격 1번";
		cin >> m_key;

		if (m_key == 1)
		{
			m_enemy->sethp(m_enemy->gethp() - m_player->gethp());
			cout << "플레이어가 공격 후 에너미 체력 : " << m_enemy->gethp();
		}
		if(m_enemy->gethp() == 0) break;
	}
}
