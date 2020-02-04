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
	RECT	playerLeftCannon;
	RECT	playerRightCannon;


	bool	isMove;
	bool	isLeft;

	int		frameCount;		// 프레임 돌려주는용
	int		frameIndex;		// 프레임 돌려주는용

	image*	indexOne;
	image*	indexTen;
	image*	indexHundred;
	image*	indexThousand;
	image*	indexTenThousand;
	image*	indexHundredThousand;
	image*	indexMillion;
	
	image*	scoreUi;
	image*	powerUi;
	image*	hpUi;

	int		score;
	int		power;
	int		life;

	int		count;
	char	str[256];

public:
	player();
	~player();

	HRESULT init();
	void release();
	void update();
	void render();
	void statusRender();

	RECT getPlayerRect() { return playerHitRect; }
	int getPlayerRectX() { return (playerHitRect.left + (playerHitRect.right - playerHitRect.left) / 2); }
	int getPlayerRectY() { return (playerHitRect.top + (playerHitRect.bottom - playerHitRect.top) / 2); }
	
	RECT getPlayerItemRect() { return playerRect; }
	int getPlayerItemRectX() { return (playerRect.left + (playerRect.right - playerRect.left) / 2); }
	int getPlayerItemRectY() { return (playerRect.top + (playerRect.bottom - playerRect.top) / 2); }

	int getScore() { return score; }
	void setScore(int num) { score = num; }

	int getPower() { return power; }
	void setPower(int num) { power = num; }

	int getLife() { return life; }
	void setLife(int num) { life = num; }

	void scoreRender();

};

