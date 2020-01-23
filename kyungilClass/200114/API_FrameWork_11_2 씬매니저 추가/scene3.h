#pragma once
#include"gameNode.h"
#include "player.h"

class scene3 : public gameNode
{
private:
	player* _player;
	RECT sceneRect;
public:
	scene3();
	~scene3();

	HRESULT init();
	void release();
	void update();
	void render();
};

