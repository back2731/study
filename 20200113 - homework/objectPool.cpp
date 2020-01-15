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
		_vBulletRepository.push_back(bullet);
	}
}


void objectPool::setBulletVector(tagBullet vSpentBullet)
{
	_vBulletRepository.push_back(vSpentBullet);
}

tagBullet objectPool::getBullet()
{
	tagBullet getBullet;
	getBullet = _vBulletRepository.back();
	_vBulletRepository.pop_back();
	return getBullet;
}
