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
	// �÷��̾� Ŭ���� �����Ҵ�
	m_player = new Player;	
	m_player->init();

	// ���ʹ� Ŭ���� �����Ҵ�
	m_enemy = new enemy;
	m_enemy->init();
}

void mainGame::release()
{
	// �����Ҵ��� �ֵ� Ŭ���� ����
	delete m_player;
	delete m_enemy;
}

void mainGame::update()
{
	/*
	cout << "�÷��̾� HP : " << m_player->gethp() << endl;
	cout << "�������� ������" << endl;
	cout << "1. Ŀ��, 2. ���� : ";
	
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
		cout << "�ٽ� �Է��Ͻÿ�." << endl;
		break;
	}

	cout << "�������� ���� �� ü�� : " << m_player->gethp() << endl;
	*/

	while (true)
	{
		cout << "�÷��̾� ���� 1��";
		cin >> m_key;

		if (m_key == 1)
		{
			m_enemy->sethp(m_enemy->gethp() - m_player->gethp());
			cout << "�÷��̾ ���� �� ���ʹ� ü�� : " << m_enemy->gethp();
		}
		if(m_enemy->gethp() == 0) break;
	}
}
