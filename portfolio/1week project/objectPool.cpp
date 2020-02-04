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

void objectPool::statusRender(HDC hdc)
{
	sprintf_s((str), "총알 잔여 : %d", _vBulletRepository.size());
	TextOut(hdc, 740, 330, str, strlen(str));

	sprintf_s((str), "사용중인 총알 : %d", BULLETMAX - _vBulletRepository.size());
	TextOut(hdc, 740, 350, str, strlen(str));

	sprintf_s((str), "아이템 잔여 : %d", _vItemRepository.size());
	TextOut(hdc, 740, 370, str, strlen(str));

	sprintf_s((str), "사용중인 아이템 : %d", ITEMMAX - _vItemRepository.size());
	TextOut(hdc, 740, 390, str, strlen(str));
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
