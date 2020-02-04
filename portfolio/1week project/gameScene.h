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
	int				addSpeed;

	char str[256];
	bool change;
	int stageBG;
	int bossBG;
	int black;
	int gameOver;
	int clear;
	RECT	statusWindow;

public:
	gameScene();
	~gameScene();

	HRESULT init();
	void release();
	void update();
	void render();
};

