#pragma once
#include "singletonBase.h"
#include"gameNode.h"
#include "bulletManager.h"
#include "enemyManager.h"

#define FRAMESPEED 10
#define PLAYERSPEED 5
#define PUSHSHIFTSPEED 2

class player : public gameNode, public singletonBase<player>
{
private:
	image*	playerImage;
	RECT	playerRect;
	RECT	playerHitRect;

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

	RECT getPlayerRect() { return playerHitRect; }
	int getPlayerRectX() { return (playerHitRect.left + (playerHitRect.right - playerHitRect.left) / 2); }
	int getPlayerRectY() { return (playerHitRect.top + (playerHitRect.bottom - playerHitRect.top) / 2); }

};

