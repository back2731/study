#pragma once
#include "enemyBase.h"
enum bossPattern
{
	IDLE,
	WORKRIGHT,
	WORKLEFT,
	FLY,
	SIT,
	MAGICCASTING,
	DRAWCARD,
	THROWSPEAR,
	UP,
	DOWN,
	RIGHT,
	LEFT,
	RIGHTUP,
	LEFTUP,
	RIGHTDOWN,
	LEFTDOWN
};

class boss : public enemyBase
{
private:

	int count;
	int frameCount;

	float rectX;
	float rectY;

	int addSpeed;
	RECT bossHitRect;

	int frameCountMagic;
	int frameY;

public:
	boss();
	~boss();

	HRESULT init(const char * imageName, POINT position);
	void release();
	void update();
	void render();

	void draw();
	void move(int pattern);
	void idleAnimation();
	void rightMoveAnimation();
	void leftMoveAnimation();
	void flyAnimation();
	void sitAnimation();
	void magicAnimation();
	void drawCardAnimation();
	void spearAnimation();


	float getBossX() { return rectX; }
	float getBossY() { return rectY; }

	RECT getRect() { return enemyRect; }

};

