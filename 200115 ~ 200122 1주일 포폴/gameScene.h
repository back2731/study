#pragma once
#include "gameNode.h"
#include "player.h"
#include "enemyManager.h"
#include "bulletManager.h"

#define PLAYER				player::getSingleton()
#define ENEMYMANAGER		enemyManager::getSingleton()
#define BULLETMANAGER		bulletManager::getSingleton()

class gameScene : public gameNode
{
private:

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

