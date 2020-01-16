#pragma once
#include "gameNode.h"
#include "player.h"
#include "enemyManager.h"

class gameScene : public gameNode
{
private:
	player*			m_player;
	enemyManager*	m_enemyManager;
	bulletManager*	m_bulletManager;

	float			loopX;
	float			loopY;

public:
	gameScene();
	~gameScene();

	HRESULT init();
	void release();
	void update();
	void render();
};

