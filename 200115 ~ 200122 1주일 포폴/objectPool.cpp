#include "stdafx.h"
#include "objectPool.h"


objectPool::objectPool()
{
}


objectPool::~objectPool()
{
}

void objectPool::init()
{
	for (int i = 0; i < BULLETMAX; i++)
	{
		tagBullet bullet;
		vBulletRepository.push_back(bullet);
	}
}

void objectPool::setBulletVector(tagBullet vSpentBullet)
{
	vUsedBullet.push_back(vSpentBullet);
}

void objectPool::reloadBullet()
{
	if (vUsedBullet.size() == BULLETMAX)
	{
		viUsedBullet = vUsedBullet.begin();
		for (viUsedBullet; viUsedBullet != vUsedBullet.end(); ++viUsedBullet)
		{
			vBulletRepository.push_back(*viUsedBullet);
		}
		vUsedBullet.clear();
	}
}

tagBullet objectPool::getBullet()
{
	tagBullet getBullet;
	getBullet = vBulletRepository.back();
	vBulletRepository.pop_back();
	return getBullet;
}
