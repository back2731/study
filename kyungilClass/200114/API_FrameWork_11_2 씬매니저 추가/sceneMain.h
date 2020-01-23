#pragma once
#include"gameNode.h"
#include "player.h"
class sceneMain : public gameNode
{
private:
	player* _player;

	RECT scene1Rect;
	RECT scene2Rect;
	RECT scene3Rect;
	RECT scene4Rect;
public:
	sceneMain();
	~sceneMain();

	HRESULT init();
	void release();
	void update();
	void render();

};

