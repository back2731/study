#pragma once
#include "Player.h"
#include "enemy.h"

class mainGame
{
private:
	Player* m_player;	// �÷��̾� Ŭ���� ����
	enemy* m_enemy;		// ���ʹ� Ŭ���� ����

	int m_key;
		
public:
	mainGame();
	~mainGame();

	void init();		// �ʱ�ȭ
	void release();		// ����
	void update();		// ����
};

