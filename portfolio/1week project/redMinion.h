#pragma once
#include "enemyBase.h"

class redMinion : public enemyBase
{
private:

	int count;
	int frameCount;
	float rectX;
	float rectY;	

	int addSpeed;
public:
	redMinion();
	~redMinion();

	HRESULT init(const char * imageName, POINT position);
	void release();
	void update();
	void render();

	void draw();
	void move(int pattern);
	void leftAnimation();
	void rightAnimation();
	void idleAnimation();

	float getRedMinionX() { return rectX; }
	float getRedMinionY() { return rectY; }

	RECT getRect() { return enemyRect; }

};

