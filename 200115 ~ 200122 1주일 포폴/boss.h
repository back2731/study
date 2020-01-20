#pragma once
#include "enemyBase.h"
class boss : public enemyBase
{
private:

	int count;
	int frameCount;

	float rectX;
	float rectY;

	int addSpeed;

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

	float getBossX() { return rectX; }
	float getBossY() { return rectY; }

	RECT getRect() { return enemyRect; }

};

