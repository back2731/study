#pragma once
#include "singletonBase.h"
#define BULLETMAX 20

struct tagBullet
{
image* bulletImage;
RECT rc;
float x, y;
float fireX, fireY;
float radius;
float angle;
float speed;
bool fire;
int count;
};

class objectPool : public singletonBase<objectPool>
{
private:
	vector<tagBullet> _vBulletRepository;
	vector<tagBullet>::iterator _viBulletRepository;

public:
	objectPool();
	~objectPool();

	void init();

	void setBulletVector(tagBullet vSpentBullet);

	tagBullet getBullet();
	vector<tagBullet>::iterator getBulletVectorIterator() { return _viBulletRepository; }

};

