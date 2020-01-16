#pragma once
#include"gameNode.h"
#include"bulletManager.h"

#define FRAMESPEED 10
#define PLAYERSPEED 5
#define PUSHSHIFTSPEED 2

class player : public gameNode
{
private:
	image*	playerImage;
	RECT	playerRect;
	RECT	testRect;

	bulletManager* playerBullet;

	bool	isMove;
	bool	isLeft;

	int		frameCount;		// 프레임 돌려주는용
	int		frameIndex;		// 프레임 돌려주는용

	int count;
	char str[256];

public:
	player();
	~player();

	HRESULT init();
	void release();
	void update();
	void render();
};

