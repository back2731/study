#pragma once
#include"gameNode.h"
#include "player.h"

class scene2 : public gameNode
{
private:
	player* _player;
	RECT sceneRect;
public:
	scene2();
	~scene2();

	HRESULT init();
	void release();
	void update();
	void render();
};

