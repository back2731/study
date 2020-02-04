#pragma once
#include "gameNode.h"
#define FRAMESPEED 10
class enemyBase : public gameNode
{
protected:

	image*	enemyImage;
	RECT	enemyRect;

	int		currentFrameX;
	int		currentFrameY;
	int		count;

	int		hp;

public:
	enemyBase();
	~enemyBase();

	HRESULT init(const char * imageName, POINT position);
	void release();
	void update();
	void render();

	virtual void draw();
	virtual void move();
	virtual void leftAnimation();
	virtual void rightAnimation();
	virtual void idleAnimation();
	
	RECT getRect() { return enemyRect; }
	float getRectX() { return (enemyRect.left + (enemyRect.right - enemyRect.left) / 2); }
	float getRectY() { return (enemyRect.top + (enemyRect.bottom - enemyRect.top) / 2); }
	
	int getHp() { return hp; }
	void setHp(int num) { hp = num; }

};

