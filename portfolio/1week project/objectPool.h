#pragma once
#include "singletonBase.h"
#define BULLETMAX 10000
#define ITEMMAX 100

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
struct ItemInfo
{
	image* itemImage;
	RECT rc;
	float x, y;
	float speed;
	float angle;
};
class objectPool : public singletonBase<objectPool>
{
private:
	vector<bulletInfo> _vBulletRepository;
	vector<bulletInfo>::iterator _viBulletRepository;

	vector<ItemInfo> _vItemRepository;
	vector<ItemInfo>::iterator _viItemRepository;

	char str[256];

public:
	objectPool();
	~objectPool();

	void init();
	void statusRender(HDC hdc);

	void setBulletVector(bulletInfo vSpentBullet);

	bulletInfo getBullet();
	vector<bulletInfo>::iterator getBulletVectorIterator() { return _viBulletRepository; }

	void setItemVector(ItemInfo vSpentItem);

	ItemInfo getItem();
	vector<ItemInfo>::iterator getItemVectorIterator() { return _viItemRepository; }


};

