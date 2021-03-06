#pragma once
#include "enemyBase.h"

class yellowMinion : public enemyBase
{
private:

	int count;

	int frameCount;

	float rectX;
	float rectY;

	int addSpeed;

public:
	yellowMinion();
	~yellowMinion();

	HRESULT init(const char * imageName, POINT position);
	void release();
	void update();
	void render();

	void draw();
	void move(int pattern);
	void leftAnimation();
	void rightAnimation();
	void idleAnimation();

	float getYellowMinionX() { return rectX; }
	float getYellowMinionY() { return rectY; }

	RECT getRect() { return enemyRect; }

};

