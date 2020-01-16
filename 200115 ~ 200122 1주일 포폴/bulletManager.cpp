#include "stdafx.h"
#include "bulletManager.h"


bulletManager::bulletManager()
{
}


bulletManager::~bulletManager()
{
}

HRESULT bulletManager::init()
{
	return S_OK;
}

void bulletManager::release()
{
}

void bulletManager::update()
{
	
}

void bulletManager::render()
{
}

void bulletManager::playerCommonBulletfire(float x, float y)
{
	playerCommonBullet = OBJECTPOOL->getBullet();

	playerCommonBullet.bulletImage = IMAGEMANAGER->findImage("playerCommonBullet");
	playerCommonBullet.speed = 10.0f;
	playerCommonBullet.x = x;
	playerCommonBullet.y = y;
	playerCommonBullet.rc = RectMakeCenter(playerCommonBullet.x, 
										   playerCommonBullet.y,
										   playerCommonBullet.bulletImage->getWidth(),
										   playerCommonBullet.bulletImage->getHeight());
	vPlayerCommonBullet.push_back(playerCommonBullet);
}

void bulletManager::playerCommonBulletMove()
{
	for (viPlayerCommonBullet = vPlayerCommonBullet.begin(); viPlayerCommonBullet != vPlayerCommonBullet.end();)
	{
		viPlayerCommonBullet->y -= viPlayerCommonBullet->speed;
		viPlayerCommonBullet->rc = RectMakeCenter(viPlayerCommonBullet->x, viPlayerCommonBullet->y,
			viPlayerCommonBullet->bulletImage->getWidth(), viPlayerCommonBullet->bulletImage->getHeight());


		if (0 >= viPlayerCommonBullet->rc.bottom)
		{
			OBJECTPOOL->setBulletVector(playerCommonBullet);
			viPlayerCommonBullet = vPlayerCommonBullet.erase(viPlayerCommonBullet);
		}
		else ++viPlayerCommonBullet;
	}
}

void bulletManager::playerCommonBulletRender()
{
	for (viPlayerCommonBullet = vPlayerCommonBullet.begin(); viPlayerCommonBullet != vPlayerCommonBullet.end(); ++viPlayerCommonBullet)
	{
		if (KEYMANAGER->isToggleKey(VK_TAB))
		{
			Rectangle(getMemDC(), viPlayerCommonBullet->rc.left, viPlayerCommonBullet->rc.top, viPlayerCommonBullet->rc.right, viPlayerCommonBullet->rc.bottom);
		}

		viPlayerCommonBullet->bulletImage->render(getMemDC(), viPlayerCommonBullet->rc.left, viPlayerCommonBullet->rc.top);
	}
}

void bulletManager::redMinionBulletfire(float x, float y)
{
	redMinionBullet = OBJECTPOOL->getBullet();

	redMinionCannon.center.x = x;
	redMinionCannon.center.y = y;
	redMinionCannon.cannon = 50;


	redMinionBullet.bulletImage = IMAGEMANAGER->findImage("redMinionBullet");
	redMinionBullet.speed = 5.0f;

	if (bulletSpeed % 1 == 0)
	{
	// ÃÑ¾Ë ¹«ºê
	redMinionBullet.angle = redMinionCannon.angle;
	redMinionBullet.x = redMinionCannon.center.x;
	redMinionBullet.y = redMinionCannon.center.y;
	redMinionBullet.rc = RectMakeCenter(redMinionBullet.x,
		redMinionBullet.y,
		redMinionBullet.bulletImage->getWidth(),
		redMinionBullet.bulletImage->getHeight());
	//
	}
	vRedMinionBullet.push_back(redMinionBullet);


	redMinionCannon.cannonEnd.x = cosf(redMinionCannon.angle) * redMinionCannon.cannon + redMinionCannon.center.x;
	redMinionCannon.cannonEnd.y = -sinf(redMinionCannon.angle) * redMinionCannon.cannon + redMinionCannon.center.y;

}

void bulletManager::redMinionBulletMove()
{
	bulletSpeed++;

	if (bulletSpeed % 3 == 0)
	{
		redMinionCannon.angle -= 0.05f;
	}

	// ÃÑ¾Ë ¹ß»ç
	viRedMinionBullet = vRedMinionBullet.begin();
	for (viRedMinionBullet; viRedMinionBullet != vRedMinionBullet.end();)
	{
		
		//viRedMinionBullet->y += viRedMinionBullet->speed;
		
		viRedMinionBullet->x += cosf(viRedMinionBullet->angle) * viRedMinionBullet->speed;
		viRedMinionBullet->y += -sinf(viRedMinionBullet->angle) * viRedMinionBullet->speed;

		viRedMinionBullet->rc = RectMakeCenter(viRedMinionBullet->x,
			viRedMinionBullet->y, viRedMinionBullet->bulletImage->getWidth(),
			viRedMinionBullet->bulletImage->getHeight());
		
		if (150 >= viRedMinionBullet->rc.right || WINSIZEY - 50 <= viRedMinionBullet->rc.top ||
			WINSIZEX - 400 <= viRedMinionBullet->rc.left || 100 > viRedMinionBullet->rc.bottom)
		{
			OBJECTPOOL->setBulletVector(redMinionBullet);
			viRedMinionBullet = vRedMinionBullet.erase(viRedMinionBullet);
		}
		else ++viRedMinionBullet;
	}
	
}

void bulletManager::redMinionBulletRender()
{
	for (viRedMinionBullet = vRedMinionBullet.begin(); viRedMinionBullet != vRedMinionBullet.end(); ++viRedMinionBullet)
	{
		if (KEYMANAGER->isToggleKey(VK_TAB))
		{
			Rectangle(getMemDC(), viRedMinionBullet->rc.left, viRedMinionBullet->rc.top, viRedMinionBullet->rc.right, viRedMinionBullet->rc.bottom);
		}

		viRedMinionBullet->bulletImage->render(getMemDC(), viRedMinionBullet->rc.left, viRedMinionBullet->rc.top);
	}

}
