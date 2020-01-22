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
	for (int i = 0; i < ITEMMAX; i++)
	{
		ItemInfo item;
		_vItemRepository.push_back(item);
	}
}

void objectPool::render(HDC hdc)
{
	//sprintf_s((str), "ÃÑ¾Ë ÀÜ¿© : %d", _vBulletRepository.size());
	//TextOut(hdc, 100, 100, str, strlen(str));

	//sprintf_s((str), "¾ÆÀÌÅÛ ÀÜ¿© : %d", _vItemRepository.size());
	//TextOut(hdc, 100, 150, str, strlen(str));
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

void objectPool::setItemVector(ItemInfo vSpentItem)
{
	_vItemRepository.push_back(vSpentItem);
}

ItemInfo objectPool::getItem()
{
	ItemInfo item;
	item = _vItemRepository.back();
	_vItemRepository.pop_back();
	return item;
}
