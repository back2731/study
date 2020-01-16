#pragma once
#include "singletonBase.h"
#define BULLETMAX 10000

struct bulletInfo
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
	vector<bulletInfo> _vBulletRepository;
	vector<bulletInfo>::iterator _viBulletRepository;

public:
	objectPool();
	~objectPool();

	void init();

	void setBulletVector(bulletInfo vSpentBullet);

	bulletInfo getBullet();
	vector<bulletInfo>::iterator getBulletVectorIterator() { return _viBulletRepository; }

};

