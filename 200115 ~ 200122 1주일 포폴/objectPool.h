#pragma once
#include "singletonBase.h"
#define BULLETMAX 10000

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
	vector<tagBullet> vBulletRepository;
	vector<tagBullet>::iterator viBulletRepository;
	
	vector<tagBullet> vUsedBullet;
	vector<tagBullet>::iterator viUsedBullet;

public:
	objectPool();
	~objectPool();

	void init();

	void setBulletVector(tagBullet vSpentBullet);
	void reloadBullet();

	tagBullet getBullet();
	vector<tagBullet>::iterator getBulletVectorIterator() { return viBulletRepository; }

};

