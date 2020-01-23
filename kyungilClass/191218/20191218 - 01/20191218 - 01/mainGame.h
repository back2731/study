#pragma once
#include "Player.h"
#include "enemy.h"

class mainGame
{
private:
	Player* m_player;	// 플레이어 클래스 선언
	enemy* m_enemy;		// 에너미 클래스 선언

	int m_key;
		
public:
	mainGame();
	~mainGame();

	void init();		// 초기화
	void release();		// 삭제
	void update();		// 연산
};

