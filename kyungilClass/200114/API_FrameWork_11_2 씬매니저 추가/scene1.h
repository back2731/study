#pragma once
#include"gameNode.h"
#include "player.h"

class scene1 : public gameNode
{
private:
	player* _player;
	RECT sceneRect; 

public:
	scene1();
	~scene1();

	HRESULT init();
	void release();
	void update();
	void render();
};

