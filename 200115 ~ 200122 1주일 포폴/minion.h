#pragma once
#include "enemyBase.h"

class minion : public enemyBase
{
private:

	int count;
	int addSpeed;

public:
	minion();
	~minion();

	HRESULT init(const char * imageName, POINT position);
	void release();
	void update();
	void render();

	void draw();
	void move(int pattern);
	void leftAnimation();
	void rightAnimation();
	void idleAnimation();
};

