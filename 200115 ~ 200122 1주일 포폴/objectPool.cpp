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
		bulletInfo bullet;
		_vBulletRepository.push_back(bullet);
	}
}


void objectPool::setBulletVector(bulletInfo vSpentBullet)
{
	_vBulletRepository.push_back(vSpentBullet);
}

bulletInfo objectPool::getBullet()
{
	bulletInfo getBullet;
	getBullet = _vBulletRepository.back();
	_vBulletRepository.pop_back();
	return getBullet;
}
