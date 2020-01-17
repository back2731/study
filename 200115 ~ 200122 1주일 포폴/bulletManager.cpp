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
	playerCommonBullet.speed = 15.0f;
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
			playerCommonBullet = { 0, };
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
	redMinionCannon.cannon = 100;
	
	redMinionBullet.bulletImage = IMAGEMANAGER->findImage("redMinionBullet");
	redMinionBullet.speed = 5.0f;
	redMinionBullet.angle = redMinionCannon.angle;

	if (redMinionBulletSpeed % 5 == 0)		// 총알간 거리 조절
	{
		// 총알 무브
		//redMinionCannon.angle -=0.05f;
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
	redMinionBulletSpeed++;

	if (redMinionBulletSpeed % 1 == 0)		// 총알발사 각도 조절
	{
		redMinionCannon.angle -= 0.05f;
	}

	// 총알 발사
	viRedMinionBullet = vRedMinionBullet.begin();
	for (viRedMinionBullet; viRedMinionBullet != vRedMinionBullet.end();)
	{
		viRedMinionBullet->x += cosf(viRedMinionBullet->angle) * viRedMinionBullet->speed;
		viRedMinionBullet->y += -sinf(viRedMinionBullet->angle) * viRedMinionBullet->speed;

		viRedMinionBullet->rc = RectMakeCenter(viRedMinionBullet->x,
			viRedMinionBullet->y, viRedMinionBullet->bulletImage->getWidth(),
			viRedMinionBullet->bulletImage->getHeight());
		
		if (100 >= viRedMinionBullet->rc.right || WINSIZEY <= viRedMinionBullet->rc.top ||
			WINSIZEX - 300 <= viRedMinionBullet->rc.left || 50 > viRedMinionBullet->rc.bottom)
		{
			redMinionBullet = { 0, };
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

void bulletManager::playerCommonBulletRedMinionCollision()
{
	for (int i = 0; i < vPlayerCommonBullet.size(); i++)
	{
		for (int j = 0; j < ENEMYMANAGER->getVRedMinion().size(); j++)
		{
			RECT rc;

			if (IntersectRect(&rc, &vPlayerCommonBullet[i].rc, &ENEMYMANAGER->getVRedMinion()[j]->getRect()))
			{
				playerCommonBullet = { 0, };
				OBJECTPOOL->setBulletVector(playerCommonBullet);
				vPlayerCommonBullet.erase(vPlayerCommonBullet.begin() + i);
				ENEMYMANAGER->deleteRedEnemy(j);
				break;
			}
		}
	}
}

void bulletManager::blueMinionBulletfire(float x, float y)
{
	blueMinionBullet = OBJECTPOOL->getBullet();
	blueMinionCannon.center.x = x;
	blueMinionCannon.center.y = y;
	blueMinionCannon.cannon = 100;

	blueMinionBullet.bulletImage = IMAGEMANAGER->findImage("blueMinionBullet");
	blueMinionBullet.speed = 5.0f;
	blueMinionBullet.angle = blueMinionCannon.angle;

	if (blueMinionBulletSpeed % 5 == 0)		// 총알간 거리 조절
	{
		// 총알 무브
		//redMinionCannon.angle -=0.05f;
		blueMinionBullet.x = blueMinionCannon.center.x;
		blueMinionBullet.y = blueMinionCannon.center.y;
		blueMinionBullet.rc = RectMakeCenter(blueMinionBullet.x,
			blueMinionBullet.y,
			blueMinionBullet.bulletImage->getWidth(),
			blueMinionBullet.bulletImage->getHeight());
		//
	}
	vBlueMinionBullet.push_back(blueMinionBullet);


	blueMinionCannon.cannonEnd.x = cosf(blueMinionCannon.angle) * blueMinionCannon.cannon + blueMinionCannon.center.x;
	blueMinionCannon.cannonEnd.y = -sinf(blueMinionCannon.angle) * blueMinionCannon.cannon + blueMinionCannon.center.y;
}

void bulletManager::blueMinionBulletMove()
{
	blueMinionBulletSpeed++;

	if (blueMinionBulletSpeed % 1 == 0)		// 총알발사 각도 조절
	{
		blueMinionCannon.angle += 0.05f;
	}

	// 총알 발사
	viBlueMinionBullet = vBlueMinionBullet.begin();
	for (viBlueMinionBullet; viBlueMinionBullet != vBlueMinionBullet.end();)
	{
		viBlueMinionBullet->x -= cosf(viBlueMinionBullet->angle) * viBlueMinionBullet->speed;
		viBlueMinionBullet->y -= -sinf(viBlueMinionBullet->angle) * viBlueMinionBullet->speed;

		viBlueMinionBullet->rc = RectMakeCenter(viBlueMinionBullet->x,
			viBlueMinionBullet->y, viBlueMinionBullet->bulletImage->getWidth(),
			viBlueMinionBullet->bulletImage->getHeight());

		if (100 >= viBlueMinionBullet->rc.right || WINSIZEY <= viBlueMinionBullet->rc.top ||
			WINSIZEX - 300 <= viBlueMinionBullet->rc.left || 50 > viBlueMinionBullet->rc.bottom)
		{
			redMinionBullet = { 0, };
			OBJECTPOOL->setBulletVector(redMinionBullet);
			viBlueMinionBullet = vBlueMinionBullet.erase(viBlueMinionBullet);
		}
		else ++viBlueMinionBullet;
	}
}

void bulletManager::blueMinionBulletRender()
{
	for (viBlueMinionBullet = vBlueMinionBullet.begin(); viBlueMinionBullet != vBlueMinionBullet.end(); ++viBlueMinionBullet)
	{
		if (KEYMANAGER->isToggleKey(VK_TAB))
		{
			Rectangle(getMemDC(), viBlueMinionBullet->rc.left, viBlueMinionBullet->rc.top, viBlueMinionBullet->rc.right, viBlueMinionBullet->rc.bottom);
		}

		viBlueMinionBullet->bulletImage->render(getMemDC(), viBlueMinionBullet->rc.left, viBlueMinionBullet->rc.top);
	}
}

void bulletManager::playerCommonBulletBlueMinionCollision()
{
	for (int i = 0; i < vPlayerCommonBullet.size(); i++)
	{
		for (int j = 0; j < ENEMYMANAGER->getVBlueMinion().size(); j++)
		{
			RECT rc;

			if (IntersectRect(&rc, &vPlayerCommonBullet[i].rc, &ENEMYMANAGER->getVBlueMinion()[j]->getRect()))
			{
				playerCommonBullet = { 0, };
				OBJECTPOOL->setBulletVector(playerCommonBullet);
				vPlayerCommonBullet.erase(vPlayerCommonBullet.begin() + i);
				ENEMYMANAGER->deleteBlueEnemy(j);
				break;
			}
		}
	}
}
