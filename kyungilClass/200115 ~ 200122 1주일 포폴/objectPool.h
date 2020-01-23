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
	char str[256];

public:
	objectPool();
	~objectPool();

	void init();
	void render(HDC hdc);

	void setBulletVector(bulletInfo vSpentBullet);

	bulletInfo getBullet();
	vector<bulletInfo>::iterator getBulletVectorIterator() { return _viBulletRepository; }

};

