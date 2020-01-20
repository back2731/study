#pragma once
#include "enemyBase.h"

class greenMinion : public enemyBase
{
private:

	int count;
	int frameCount;

	float rectX;
	float rectY;

	int addSpeed;

public:
	greenMinion();
	~greenMinion();

	HRESULT init(const char * imageName, POINT position);
	void release();
	void update();
	void render();

	void draw();
	void move(int pattern);
	void leftAnimation();
	void rightAnimation();
	void idleAnimation();

	float getGreenMinionX() { return rectX; }
	float getGreenMinionY() { return rectY; }

	RECT getRect() { return enemyRect; }

};

