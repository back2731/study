#pragma once
#include"gameNode.h"
#define PLAYERSPEED 5
#define FRAMESPEED 10

class player : public gameNode
{
private:
	image*	playerImage;
	RECT	playerRect;

	bool	isMove;
	bool	isLeft;
	bool	isRight;
	int		frameCount;		// 프레임 돌려주는용
	int		frameIndex;		// 프레임 돌려주는용


public:
	player();
	~player();

	HRESULT init();
	void release();
	void update();
	void render();
};

