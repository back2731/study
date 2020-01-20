#pragma once
#include "enemyBase.h"

class blueMinion : public enemyBase
{
private:

	int count;
	int frameCount;

	float rectX;
	float rectY;
	
	int addSpeed;
public:
	blueMinion();
	~blueMinion();

	HRESULT init(const char * imageName, POINT position);
	void release();
	void update();
	void render();

	void draw();
	void move(int pattern);
	void leftAnimation();
	void rightAnimation();
	void idleAnimation();

	float getBlueMinionX() { return rectX; }
	float getBlueMinionY() { return rectY; }

	RECT getRect() { return enemyRect; }
};

