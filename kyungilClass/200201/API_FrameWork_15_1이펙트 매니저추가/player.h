#pragma once
#include "gameNode.h"
class player : public gameNode
{
private:

protected:
	int playerHp;
	int playerMp;
	int playerAtk;
	int playerDef;
	int playerDex;
	int playerLux;
	int playerGold;

public:
	player();
	~player();

	HRESULT init();
	void release();
	void update();
	void render();

};

