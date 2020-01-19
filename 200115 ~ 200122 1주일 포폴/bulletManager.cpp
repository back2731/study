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
	vPlayerCommonBullet.reserve(2000);

	vCommonRedBullet.reserve(1000);
	vSpinRedBullet.reserve(1000);
	vHomingRedBullet.reserve(1000);
	
	vCommonBlueBullet.reserve(1000);
	vSpinBlueBullet.reserve(1000);
	vHomingBlueBullet.reserve(1000);

	vCommonGreenBullet.reserve(1000);
	vSpinGreenBullet.reserve(1000);

	vCommonYellowBullet.reserve(1000);
	vSpinYellowBullet.reserve(1000);

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

void bulletManager::playerCommonBulletFire(float x, float y)
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

void bulletManager::playerHomingBulletFire(float playerBulletX, float playerBulletY)
{
	playerHomingBullet = OBJECTPOOL->getBullet();

	playerHomingBullet.bulletImage = IMAGEMANAGER->findImage("playerHomingBullet");
	playerHomingBullet.speed = 15.0f;
	playerHomingBullet.x = playerBulletX;
	playerHomingBullet.y = playerBulletY;
	playerHomingBullet.rc = RectMakeCenter(playerHomingBullet.x,
		playerHomingBullet.y,
		playerHomingBullet.bulletImage->getWidth(),
		playerHomingBullet.bulletImage->getHeight());
	vPlayerHomingBullet.push_back(playerHomingBullet);
}

void bulletManager::playerHomingBulletMove()
{
	if (ENEMYMANAGER->getVRedMinion().size() > 0)
	{
		if (ENEMYMANAGER->getVRedMinion()[0]->getRedMinionX() >= 0 && ENEMYMANAGER->getVRedMinion()[0]->getRedMinionX() <= WINSIZEX &&
			ENEMYMANAGER->getVRedMinion()[0]->getRedMinionY() >= 0 && ENEMYMANAGER->getVRedMinion()[0]->getRedMinionX() <= WINSIZEX)
		{
			for (viPlayerHomingBullet = vPlayerHomingBullet.begin(); viPlayerHomingBullet != vPlayerHomingBullet.end();)
			{
				float distance;
				distance = getDistance(viPlayerHomingBullet->x, viPlayerHomingBullet->y,
					ENEMYMANAGER->getVRedMinion()[0]->getRedMinionX(), ENEMYMANAGER->getVRedMinion()[0]->getRedMinionY());
				float vx, vy;
				if (distance)
				{
					vx = ((ENEMYMANAGER->getVRedMinion()[0]->getRedMinionX()) - viPlayerHomingBullet->x) / distance * viPlayerHomingBullet->speed;
					vy = ((ENEMYMANAGER->getVRedMinion()[0]->getRedMinionY()) - viPlayerHomingBullet->y) / distance * viPlayerHomingBullet->speed;
				}
				else
				{
					vx = 0;
					vy = playerHomingBullet.speed;
				}
				viPlayerHomingBullet->x += vx;
				viPlayerHomingBullet->y += vy;
				viPlayerHomingBullet->rc = RectMakeCenter(viPlayerHomingBullet->x, viPlayerHomingBullet->y,
					viPlayerHomingBullet->bulletImage->getWidth(), viPlayerHomingBullet->bulletImage->getHeight());

				if (0 >= viPlayerHomingBullet->rc.bottom)
				{
					playerHomingBullet = { 0, };
					OBJECTPOOL->setBulletVector(playerHomingBullet);
					viPlayerHomingBullet = vPlayerHomingBullet.erase(viPlayerHomingBullet);
				}
				else ++viPlayerHomingBullet;
			}
		}
		else
		{
			for (viPlayerHomingBullet = vPlayerHomingBullet.begin(); viPlayerHomingBullet != vPlayerHomingBullet.end();)
			{
				viPlayerHomingBullet->y -= viPlayerHomingBullet->speed;
				viPlayerHomingBullet->rc = RectMakeCenter(viPlayerHomingBullet->x, viPlayerHomingBullet->y,
					viPlayerHomingBullet->bulletImage->getWidth(), viPlayerHomingBullet->bulletImage->getHeight());

				if (0 >= viPlayerHomingBullet->rc.bottom)
				{
					playerHomingBullet = { 0, };
					OBJECTPOOL->setBulletVector(playerHomingBullet);
					viPlayerHomingBullet = vPlayerHomingBullet.erase(viPlayerHomingBullet);
				}
				else ++viPlayerHomingBullet;
			}
		}
	}
	else if (ENEMYMANAGER->getVBlueMinion().size() > 0)
	{
		if (ENEMYMANAGER->getVBlueMinion()[0]->getBlueMinionX() >= 0 && ENEMYMANAGER->getVBlueMinion()[0]->getBlueMinionX() <= WINSIZEX &&
			ENEMYMANAGER->getVBlueMinion()[0]->getBlueMinionY() >= 0 && ENEMYMANAGER->getVBlueMinion()[0]->getBlueMinionY() <= WINSIZEX)
		{
			for (viPlayerHomingBullet = vPlayerHomingBullet.begin(); viPlayerHomingBullet != vPlayerHomingBullet.end();)
			{
				float distance;
				distance = getDistance(viPlayerHomingBullet->x, viPlayerHomingBullet->y,
					ENEMYMANAGER->getVBlueMinion()[0]->getBlueMinionX(), ENEMYMANAGER->getVBlueMinion()[0]->getBlueMinionY());
				float vx, vy;
				if (distance)
				{
					vx = ((ENEMYMANAGER->getVBlueMinion()[0]->getBlueMinionX()) - viPlayerHomingBullet->x) / distance * viPlayerHomingBullet->speed;
					vy = ((ENEMYMANAGER->getVBlueMinion()[0]->getBlueMinionY()) - viPlayerHomingBullet->y) / distance * viPlayerHomingBullet->speed;
				}
				else
				{
					vx = 0;
					vy = playerHomingBullet.speed;
				}
				viPlayerHomingBullet->x += vx;
				viPlayerHomingBullet->y += vy;
				viPlayerHomingBullet->rc = RectMakeCenter(viPlayerHomingBullet->x, viPlayerHomingBullet->y,
					viPlayerHomingBullet->bulletImage->getWidth(), viPlayerHomingBullet->bulletImage->getHeight());

				if (0 >= viPlayerHomingBullet->rc.bottom)
				{
					playerHomingBullet = { 0, };
					OBJECTPOOL->setBulletVector(playerHomingBullet);
					viPlayerHomingBullet = vPlayerHomingBullet.erase(viPlayerHomingBullet);
				}
				else ++viPlayerHomingBullet;
			}
		}
		else
		{
			for (viPlayerHomingBullet = vPlayerHomingBullet.begin(); viPlayerHomingBullet != vPlayerHomingBullet.end();)
			{
				viPlayerHomingBullet->y -= viPlayerHomingBullet->speed;
				viPlayerHomingBullet->rc = RectMakeCenter(viPlayerHomingBullet->x, viPlayerHomingBullet->y,
					viPlayerHomingBullet->bulletImage->getWidth(), viPlayerHomingBullet->bulletImage->getHeight());

				if (0 >= viPlayerHomingBullet->rc.bottom)
				{
					playerHomingBullet = { 0, };
					OBJECTPOOL->setBulletVector(playerHomingBullet);
					viPlayerHomingBullet = vPlayerHomingBullet.erase(viPlayerHomingBullet);
				}
				else ++viPlayerHomingBullet;
			}
		}
	}
	else if (ENEMYMANAGER->getVGreenMinion().size() > 0)
	{
		if (ENEMYMANAGER->getVGreenMinion()[0]->getGreenMinionX() >= 0 && ENEMYMANAGER->getVGreenMinion()[0]->getGreenMinionX() <= WINSIZEX &&
			ENEMYMANAGER->getVGreenMinion()[0]->getGreenMinionY() >= 0 && ENEMYMANAGER->getVGreenMinion()[0]->getGreenMinionY() <= WINSIZEX)

		{
			for (viPlayerHomingBullet = vPlayerHomingBullet.begin(); viPlayerHomingBullet != vPlayerHomingBullet.end();)
			{
				float distance;
				distance = getDistance(viPlayerHomingBullet->x, viPlayerHomingBullet->y,
					ENEMYMANAGER->getVGreenMinion()[0]->getGreenMinionX(), ENEMYMANAGER->getVGreenMinion()[0]->getGreenMinionY());
				float vx, vy;
				if (distance)
				{
					vx = ((ENEMYMANAGER->getVGreenMinion()[0]->getGreenMinionX()) - viPlayerHomingBullet->x) / distance * viPlayerHomingBullet->speed;
					vy = ((ENEMYMANAGER->getVGreenMinion()[0]->getGreenMinionY()) - viPlayerHomingBullet->y) / distance * viPlayerHomingBullet->speed;
				}
				else
				{
					vx = 0;
					vy = playerHomingBullet.speed;
				}
				viPlayerHomingBullet->x += vx;
				viPlayerHomingBullet->y += vy;
				viPlayerHomingBullet->rc = RectMakeCenter(viPlayerHomingBullet->x, viPlayerHomingBullet->y,
					viPlayerHomingBullet->bulletImage->getWidth(), viPlayerHomingBullet->bulletImage->getHeight());

				if (0 >= viPlayerHomingBullet->rc.bottom)
				{
					playerHomingBullet = { 0, };
					OBJECTPOOL->setBulletVector(playerHomingBullet);
					viPlayerHomingBullet = vPlayerHomingBullet.erase(viPlayerHomingBullet);
				}
				else ++viPlayerHomingBullet;
			}
		}
		else
		{
			for (viPlayerHomingBullet = vPlayerHomingBullet.begin(); viPlayerHomingBullet != vPlayerHomingBullet.end();)
			{
				viPlayerHomingBullet->y -= viPlayerHomingBullet->speed;
				viPlayerHomingBullet->rc = RectMakeCenter(viPlayerHomingBullet->x, viPlayerHomingBullet->y,
					viPlayerHomingBullet->bulletImage->getWidth(), viPlayerHomingBullet->bulletImage->getHeight());

				if (0 >= viPlayerHomingBullet->rc.bottom)
				{
					playerHomingBullet = { 0, };
					OBJECTPOOL->setBulletVector(playerHomingBullet);
					viPlayerHomingBullet = vPlayerHomingBullet.erase(viPlayerHomingBullet);
				}
				else ++viPlayerHomingBullet;
			}
		}
	}
	else if (ENEMYMANAGER->getVYellowMinion().size() > 0)
	{
		if (ENEMYMANAGER->getVYellowMinion()[0]->getYellowMinionX() >= 0 && ENEMYMANAGER->getVYellowMinion()[0]->getYellowMinionX() <= WINSIZEX &&
			ENEMYMANAGER->getVYellowMinion()[0]->getYellowMinionY() >= 0 && ENEMYMANAGER->getVYellowMinion()[0]->getYellowMinionY() <= WINSIZEX)

		{
			for (viPlayerHomingBullet = vPlayerHomingBullet.begin(); viPlayerHomingBullet != vPlayerHomingBullet.end();)
			{
				float distance;
				distance = getDistance(viPlayerHomingBullet->x, viPlayerHomingBullet->y,
					ENEMYMANAGER->getVYellowMinion()[0]->getYellowMinionX(), ENEMYMANAGER->getVYellowMinion()[0]->getYellowMinionY());
				float vx, vy;
				if (distance)
				{
					vx = ((ENEMYMANAGER->getVYellowMinion()[0]->getYellowMinionX()) - viPlayerHomingBullet->x) / distance * viPlayerHomingBullet->speed;
					vy = ((ENEMYMANAGER->getVYellowMinion()[0]->getYellowMinionY()) - viPlayerHomingBullet->y) / distance * viPlayerHomingBullet->speed;
				}
				else
				{
					vx = 0;
					vy = playerHomingBullet.speed;
				}
				viPlayerHomingBullet->x += vx;
				viPlayerHomingBullet->y += vy;
				viPlayerHomingBullet->rc = RectMakeCenter(viPlayerHomingBullet->x, viPlayerHomingBullet->y,
					viPlayerHomingBullet->bulletImage->getWidth(), viPlayerHomingBullet->bulletImage->getHeight());

				if (0 >= viPlayerHomingBullet->rc.bottom)
				{
					playerHomingBullet = { 0, };
					OBJECTPOOL->setBulletVector(playerHomingBullet);
					viPlayerHomingBullet = vPlayerHomingBullet.erase(viPlayerHomingBullet);
				}
				else ++viPlayerHomingBullet;
			}
		}
		else
		{
			for (viPlayerHomingBullet = vPlayerHomingBullet.begin(); viPlayerHomingBullet != vPlayerHomingBullet.end();)
			{
				viPlayerHomingBullet->y -= viPlayerHomingBullet->speed;
				viPlayerHomingBullet->rc = RectMakeCenter(viPlayerHomingBullet->x, viPlayerHomingBullet->y,
					viPlayerHomingBullet->bulletImage->getWidth(), viPlayerHomingBullet->bulletImage->getHeight());

				if (0 >= viPlayerHomingBullet->rc.bottom)
				{
					playerHomingBullet = { 0, };
					OBJECTPOOL->setBulletVector(playerHomingBullet);
					viPlayerHomingBullet = vPlayerHomingBullet.erase(viPlayerHomingBullet);
				}
				else ++viPlayerHomingBullet;
			}
		}
	}
	else
	{
		for (viPlayerHomingBullet = vPlayerHomingBullet.begin(); viPlayerHomingBullet != vPlayerHomingBullet.end();)
		{
			viPlayerHomingBullet->y -= viPlayerHomingBullet->speed;
			viPlayerHomingBullet->rc = RectMakeCenter(viPlayerHomingBullet->x, viPlayerHomingBullet->y,
				viPlayerHomingBullet->bulletImage->getWidth(), viPlayerHomingBullet->bulletImage->getHeight());

			if (0 >= viPlayerHomingBullet->rc.bottom)
			{
				playerHomingBullet = { 0, };
				OBJECTPOOL->setBulletVector(playerHomingBullet);
				viPlayerHomingBullet = vPlayerHomingBullet.erase(viPlayerHomingBullet);
			}
			else ++viPlayerHomingBullet;
		}
	}
}

void bulletManager::playerHomingBulletRender()
{
	for (viPlayerHomingBullet = vPlayerHomingBullet.begin(); viPlayerHomingBullet != vPlayerHomingBullet.end(); ++viPlayerHomingBullet)
	{
		if (KEYMANAGER->isToggleKey(VK_TAB))
		{
			Rectangle(getMemDC(), viPlayerHomingBullet->rc.left, viPlayerHomingBullet->rc.top, viPlayerHomingBullet->rc.right, viPlayerHomingBullet->rc.bottom);
		}

		viPlayerHomingBullet->bulletImage->render(getMemDC(), viPlayerHomingBullet->rc.left, viPlayerHomingBullet->rc.top);
	}
}

void bulletManager::playerBulletCollision()
{
	playerCommonBulletRedMinionCollision();
	playerCommonBulletBlueMinionCollision();
	playerCommonBulletGreenMinionCollision();
	playerCommonBulletYellowMinionCollision();
	playerHomingBulletRedMinionCollision();
	playerHomingBulletBlueMinionCollision();
	playerHomingBulletGreenMinionCollision();
	playerHomingBulletYellowMinionCollision();
}

void bulletManager::playerCommonBulletRedMinionCollision()
{
	for (int i = 0; i < vPlayerCommonBullet.size(); i++)
	{
		for (int j = 0; j < ENEMYMANAGER->getVRedMinion().size(); j++)
		{
			RECT rc;
			if (getDistance(vPlayerCommonBullet[i].x, vPlayerCommonBullet[i].y,
				ENEMYMANAGER->getVRedMinion()[j]->getRedMinionX(), ENEMYMANAGER->getVRedMinion()[j]->getRedMinionY()) <= ENEMYHIT)
			{
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
}

void bulletManager::playerCommonBulletBlueMinionCollision()
{
	for (int i = 0; i < vPlayerCommonBullet.size(); i++)
	{
		for (int j = 0; j < ENEMYMANAGER->getVBlueMinion().size(); j++)
		{
			RECT rc;
			if (getDistance(vPlayerCommonBullet[i].x, vPlayerCommonBullet[i].y,
				ENEMYMANAGER->getVBlueMinion()[j]->getBlueMinionX(), ENEMYMANAGER->getVBlueMinion()[j]->getBlueMinionY()) <= ENEMYHIT)
			{
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
}

void bulletManager::playerCommonBulletGreenMinionCollision()
{
	for (int i = 0; i < vPlayerCommonBullet.size(); i++)
	{
		for (int j = 0; j < ENEMYMANAGER->getVGreenMinion().size(); j++)
		{
			RECT rc;
			if (getDistance(vPlayerCommonBullet[i].x, vPlayerCommonBullet[i].y,
				ENEMYMANAGER->getVGreenMinion()[j]->getGreenMinionX(), ENEMYMANAGER->getVGreenMinion()[j]->getGreenMinionY()) <= ENEMYHIT)
			{
				if (IntersectRect(&rc, &vPlayerCommonBullet[i].rc, &ENEMYMANAGER->getVGreenMinion()[j]->getRect()))
				{
					playerCommonBullet = { 0, };
					OBJECTPOOL->setBulletVector(playerCommonBullet);
					vPlayerCommonBullet.erase(vPlayerCommonBullet.begin() + i);
					ENEMYMANAGER->deleteGreenEnemy(j);
					break;
				}
			}
		}
	}
}

void bulletManager::playerCommonBulletYellowMinionCollision()
{
	for (int i = 0; i < vPlayerCommonBullet.size(); i++)
	{
		for (int j = 0; j < ENEMYMANAGER->getVYellowMinion().size(); j++)
		{
			RECT rc;
			if (getDistance(vPlayerCommonBullet[i].x, vPlayerCommonBullet[i].y,
				ENEMYMANAGER->getVYellowMinion()[j]->getYellowMinionX(), ENEMYMANAGER->getVYellowMinion()[j]->getYellowMinionY()) <= ENEMYHIT)
			{
				if (IntersectRect(&rc, &vPlayerCommonBullet[i].rc, &ENEMYMANAGER->getVYellowMinion()[j]->getRect()))
				{
					playerCommonBullet = { 0, };
					OBJECTPOOL->setBulletVector(playerCommonBullet);
					vPlayerCommonBullet.erase(vPlayerCommonBullet.begin() + i);
					ENEMYMANAGER->deleteYellowEnemy(j);
					break;
				}
			}
		}
	}
}

void bulletManager::playerHomingBulletRedMinionCollision()
{
	for (int i = 0; i < vPlayerHomingBullet.size(); i++)
	{
		for (int j = 0; j < ENEMYMANAGER->getVRedMinion().size(); j++)
		{
			RECT rc;
			if (getDistance(vPlayerHomingBullet[i].x, vPlayerHomingBullet[i].y,
				ENEMYMANAGER->getVRedMinion()[j]->getRedMinionX(), ENEMYMANAGER->getVRedMinion()[j]->getRedMinionY()) <= ENEMYHIT)
			{
				if (IntersectRect(&rc, &vPlayerHomingBullet[i].rc, &ENEMYMANAGER->getVRedMinion()[j]->getRect()))
				{
					playerHomingBullet = { 0, };
					OBJECTPOOL->setBulletVector(playerHomingBullet);
					vPlayerHomingBullet.erase(vPlayerHomingBullet.begin() + i);
					ENEMYMANAGER->deleteRedEnemy(j);
					break;
				}
			}
		}
	}
}

void bulletManager::playerHomingBulletBlueMinionCollision()
{
	for (int i = 0; i < vPlayerHomingBullet.size(); i++)
	{
		for (int j = 0; j < ENEMYMANAGER->getVBlueMinion().size(); j++)
		{
			RECT rc;
			if (getDistance(vPlayerHomingBullet[i].x, vPlayerHomingBullet[i].y,
				ENEMYMANAGER->getVBlueMinion()[j]->getBlueMinionX(), ENEMYMANAGER->getVBlueMinion()[j]->getBlueMinionY()) <= ENEMYHIT)
			{
				if (IntersectRect(&rc, &vPlayerHomingBullet[i].rc, &ENEMYMANAGER->getVBlueMinion()[j]->getRect()))
				{
					playerHomingBullet = { 0, };
					OBJECTPOOL->setBulletVector(playerHomingBullet);
					vPlayerHomingBullet.erase(vPlayerHomingBullet.begin() + i);
					ENEMYMANAGER->deleteBlueEnemy(j);
					break;
				}
			}
		}
	}
}

void bulletManager::playerHomingBulletGreenMinionCollision()
{
	for (int i = 0; i < vPlayerHomingBullet.size(); i++)
	{
		for (int j = 0; j < ENEMYMANAGER->getVGreenMinion().size(); j++)
		{
			RECT rc;
			if (getDistance(vPlayerHomingBullet[i].x, vPlayerHomingBullet[i].y,
				ENEMYMANAGER->getVGreenMinion()[j]->getGreenMinionX(), ENEMYMANAGER->getVGreenMinion()[j]->getGreenMinionY()) <= ENEMYHIT)
			{
				if (IntersectRect(&rc, &vPlayerHomingBullet[i].rc, &ENEMYMANAGER->getVGreenMinion()[j]->getRect()))
				{
					playerHomingBullet = { 0, };
					OBJECTPOOL->setBulletVector(playerHomingBullet);
					vPlayerHomingBullet.erase(vPlayerHomingBullet.begin() + i);
					ENEMYMANAGER->deleteGreenEnemy(j);
					break;
				}
			}
		}
	}
}

void bulletManager::playerHomingBulletYellowMinionCollision()
{
	for (int i = 0; i < vPlayerHomingBullet.size(); i++)
	{
		for (int j = 0; j < ENEMYMANAGER->getVYellowMinion().size(); j++)
		{
			RECT rc;
			if (getDistance(vPlayerHomingBullet[i].x, vPlayerHomingBullet[i].y,
				ENEMYMANAGER->getVYellowMinion()[j]->getYellowMinionX(), ENEMYMANAGER->getVYellowMinion()[j]->getYellowMinionY()) <= ENEMYHIT)
			{
				if (IntersectRect(&rc, &vPlayerHomingBullet[i].rc, &ENEMYMANAGER->getVYellowMinion()[j]->getRect()))
				{
					playerHomingBullet = { 0, };
					OBJECTPOOL->setBulletVector(playerHomingBullet);
					vPlayerHomingBullet.erase(vPlayerHomingBullet.begin() + i);
					ENEMYMANAGER->deleteYellowEnemy(j);
					break;
				}
			}
		}
	}
}

void bulletManager::minionCommonBulletFire(int bulletKind, float x, float y, float angle, float bulletSpeed, int interval)
{
	switch (bulletKind)
	{
	case MINION_REDBULLET:		// 레드 미니언 상모돌리기 탄
	{
		commonRedBullet = OBJECTPOOL->getBullet();
		commonRedCannon.center.x = x;
		commonRedCannon.center.y = y;
		commonRedCannon.angle = angle;

		commonRedBullet.bulletImage = IMAGEMANAGER->findImage("redMinionBullet");
		commonRedBullet.speed = bulletSpeed;
		commonRedBullet.angle = commonRedCannon.angle;

		if (commonRedBulletSpeed % interval == 0)		// 총알간 거리 조절
		{
			// 총알 무브
			commonRedBullet.x = commonRedCannon.center.x;
			commonRedBullet.y = commonRedCannon.center.y;
			commonRedBullet.rc = RectMakeCenter(commonRedBullet.x,
				commonRedBullet.y,
				commonRedBullet.bulletImage->getWidth(),
				commonRedBullet.bulletImage->getHeight());
			//
		}
		vCommonRedBullet.push_back(commonRedBullet);

		commonRedCannon.cannonEnd.x = cosf(commonRedCannon.angle) * commonRedCannon.cannon + commonRedCannon.center.x;
		commonRedCannon.cannonEnd.y = -sinf(commonRedCannon.angle) * commonRedCannon.cannon + commonRedCannon.center.y;
	}
	break;
	case MINION_BLUEBULLET:
	{
		commonBlueBullet = OBJECTPOOL->getBullet();
		commonBlueCannon.center.x = x;
		commonBlueCannon.center.y = y;
		commonBlueCannon.angle = angle;

		commonBlueBullet.bulletImage = IMAGEMANAGER->findImage("blueMinionBullet");
		commonBlueBullet.speed = bulletSpeed;
		commonBlueBullet.angle = commonBlueCannon.angle;

		if (commonBlueBulletSpeed % interval == 0)		// 총알간 거리 조절
		{
			// 총알 무브
			commonBlueBullet.x = commonBlueCannon.center.x;
			commonBlueBullet.y = commonBlueCannon.center.y;
			commonBlueBullet.rc = RectMakeCenter(commonBlueBullet.x,
				commonBlueBullet.y,
				commonBlueBullet.bulletImage->getWidth(),
				commonBlueBullet.bulletImage->getHeight());
			//
		}
		vCommonBlueBullet.push_back(commonBlueBullet);


		commonBlueCannon.cannonEnd.x = cosf(commonBlueCannon.angle) * commonBlueCannon.cannon + commonBlueCannon.center.x;
		commonBlueCannon.cannonEnd.y = -sinf(commonBlueCannon.angle) * commonBlueCannon.cannon + commonBlueCannon.center.y;
	}
	break;
	case MINION_GREENBULLET:
	{
		commonGreenBullet = OBJECTPOOL->getBullet();
		commonGreenCannon.center.x = x;
		commonGreenCannon.center.y = y;
		commonGreenCannon.angle = angle;

		commonGreenBullet.bulletImage = IMAGEMANAGER->findImage("greenMinionBullet");
		commonGreenBullet.speed = bulletSpeed;
		commonGreenBullet.angle = commonGreenCannon.angle;

		if (commonGreenBulletSpeed % interval == 0)		// 총알간 거리 조절
		{
			// 총알 무브
			commonGreenBullet.x = commonGreenCannon.center.x;
			commonGreenBullet.y = commonGreenCannon.center.y;
			commonGreenBullet.rc = RectMakeCenter(commonGreenBullet.x,
				commonGreenBullet.y,
				commonGreenBullet.bulletImage->getWidth(),
				commonGreenBullet.bulletImage->getHeight());
			//
		}
		vCommonGreenBullet.push_back(commonGreenBullet);


		commonGreenCannon.cannonEnd.x = cosf(commonGreenCannon.angle) * commonGreenCannon.cannon + commonGreenCannon.center.x;
		commonGreenCannon.cannonEnd.y = -sinf(commonGreenCannon.angle) * commonGreenCannon.cannon + commonGreenCannon.center.y;
	}
	break;
	case MINION_YELLOWBULLET:
	{
		commonYellowBullet = OBJECTPOOL->getBullet();
		commonYellowCannon.center.x = x;
		commonYellowCannon.center.y = y;
		commonYellowCannon.angle = angle;

		commonYellowBullet.bulletImage = IMAGEMANAGER->findImage("yellowMinionBullet");
		commonYellowBullet.speed = bulletSpeed;
		commonYellowBullet.angle = commonYellowCannon.angle;

		if (commonYellowBulletSpeed % interval == 0)		// 총알간 거리 조절
		{
			// 총알 무브
			commonYellowBullet.x = commonYellowCannon.center.x;
			commonYellowBullet.y = commonYellowCannon.center.y;
			commonYellowBullet.rc = RectMakeCenter(commonYellowBullet.x,
				commonYellowBullet.y,
				commonYellowBullet.bulletImage->getWidth(),
				commonYellowBullet.bulletImage->getHeight());
			//
		}
		vCommonYellowBullet.push_back(commonYellowBullet);

		commonYellowCannon.cannonEnd.x = cosf(commonYellowCannon.angle) * commonYellowCannon.cannon + commonYellowCannon.center.x;
		commonYellowCannon.cannonEnd.y = -sinf(commonYellowCannon.angle) * commonYellowCannon.cannon + commonYellowCannon.center.y;
	}
	break;
	default:
		break;
	}
}

void bulletManager::minionCommonBulletMove(int bulletKind)
{
	switch (bulletKind)
	{
	case MINION_REDBULLET:		// 레드 미니언 상모돌리기 탄
	{
		commonRedBulletSpeed++;

		// 총알 발사
		viCommonRedBullet = vCommonRedBullet.begin();
		for (viCommonRedBullet; viCommonRedBullet != vCommonRedBullet.end();)
		{
			viCommonRedBullet->x += cosf(viCommonRedBullet->angle) * viCommonRedBullet->speed;
			viCommonRedBullet->y += -sinf(viCommonRedBullet->angle) * viCommonRedBullet->speed;

			viCommonRedBullet->rc = RectMakeCenter(viCommonRedBullet->x,
				viCommonRedBullet->y, viCommonRedBullet->bulletImage->getWidth(),
				viCommonRedBullet->bulletImage->getHeight());

			if (100 >= viCommonRedBullet->rc.right || WINSIZEY <= viCommonRedBullet->rc.top ||
				WINSIZEX - 300 <= viCommonRedBullet->rc.left || 50 > viCommonRedBullet->rc.bottom)
			{
				commonRedBullet = { 0, };
				OBJECTPOOL->setBulletVector(commonRedBullet);
				viCommonRedBullet = vCommonRedBullet.erase(viCommonRedBullet);
			}
			else ++viCommonRedBullet;
		}
	}
	break;
	case MINION_BLUEBULLET:
	{
		commonBlueBulletSpeed++;

		// 총알 발사
		viCommonBlueBullet = vCommonBlueBullet.begin();
		for (viCommonBlueBullet; viCommonBlueBullet != vCommonBlueBullet.end();)
		{
			viCommonBlueBullet->x -= cosf(viCommonBlueBullet->angle) * viCommonBlueBullet->speed;
			viCommonBlueBullet->y -= -sinf(viCommonBlueBullet->angle) * viCommonBlueBullet->speed;

			viCommonBlueBullet->rc = RectMakeCenter(viCommonBlueBullet->x,
				viCommonBlueBullet->y, viCommonBlueBullet->bulletImage->getWidth(),
				viCommonBlueBullet->bulletImage->getHeight());

			if (100 >= viCommonBlueBullet->rc.right || WINSIZEY <= viCommonBlueBullet->rc.top ||
				WINSIZEX - 300 <= viCommonBlueBullet->rc.left || 50 > viCommonBlueBullet->rc.bottom)
			{
				commonBlueBullet = { 0, };
				OBJECTPOOL->setBulletVector(commonBlueBullet);
				viCommonBlueBullet = vCommonBlueBullet.erase(viCommonBlueBullet);
			}
			else ++viCommonBlueBullet;
		}
	}
	break;
	case MINION_GREENBULLET:
	{
		commonGreenBulletSpeed++;

		// 총알 발사
		viCommonGreenBullet = vCommonGreenBullet.begin();
		for (viCommonGreenBullet; viCommonGreenBullet != vCommonGreenBullet.end();)
		{
			viCommonGreenBullet->x += cosf(viCommonGreenBullet->angle) * viCommonGreenBullet->speed;
			viCommonGreenBullet->y += -sinf(viCommonGreenBullet->angle) * viCommonGreenBullet->speed;

			viCommonGreenBullet->rc = RectMakeCenter(viCommonGreenBullet->x,
				viCommonGreenBullet->y, viCommonGreenBullet->bulletImage->getWidth(),
				viCommonGreenBullet->bulletImage->getHeight());

			if (100 >= viCommonGreenBullet->rc.right || WINSIZEY <= viCommonGreenBullet->rc.top ||
				WINSIZEX - 300 <= viCommonGreenBullet->rc.left || 50 > viCommonGreenBullet->rc.bottom)
			{
				commonGreenBullet = { 0, };
				OBJECTPOOL->setBulletVector(commonGreenBullet);
				viCommonGreenBullet = vCommonGreenBullet.erase(viCommonGreenBullet);
			}
			else ++viCommonGreenBullet;
		}
	}
	break;
	case MINION_YELLOWBULLET:
	{
		commonYellowBulletSpeed++;

		// 총알 발사
		viCommonYellowBullet = vCommonYellowBullet.begin();
		for (viCommonYellowBullet; viCommonYellowBullet != vCommonYellowBullet.end();)
		{
			viCommonYellowBullet->x += cosf(viCommonYellowBullet->angle) * viCommonYellowBullet->speed;
			viCommonYellowBullet->y += -sinf(viCommonYellowBullet->angle) * viCommonYellowBullet->speed;

			viCommonYellowBullet->rc = RectMakeCenter(viCommonYellowBullet->x,
				viCommonYellowBullet->y, viCommonYellowBullet->bulletImage->getWidth(),
				viCommonYellowBullet->bulletImage->getHeight());

			if (100 >= viCommonYellowBullet->rc.right || WINSIZEY <= viCommonYellowBullet->rc.top ||
				WINSIZEX - 300 <= viCommonYellowBullet->rc.left || 50 > viCommonYellowBullet->rc.bottom)
			{
				commonYellowBullet = { 0, };
				OBJECTPOOL->setBulletVector(commonYellowBullet);
				viCommonYellowBullet = vCommonYellowBullet.erase(viCommonYellowBullet);
			}
			else ++viCommonYellowBullet;
		}
	}
	break;
	default:
		break;
	}
}

void bulletManager::minionCommonBulletRender(int bulletKind)
{
	switch (bulletKind)
	{
	case MINION_REDBULLET:
	{
		for (viCommonRedBullet = vCommonRedBullet.begin(); viCommonRedBullet != vCommonRedBullet.end(); ++viCommonRedBullet)
		{
			if (KEYMANAGER->isToggleKey(VK_TAB))
			{
				Rectangle(getMemDC(), viCommonRedBullet->rc.left, viCommonRedBullet->rc.top, viCommonRedBullet->rc.right, viCommonRedBullet->rc.bottom);
			}

			viCommonRedBullet->bulletImage->render(getMemDC(), viCommonRedBullet->rc.left, viCommonRedBullet->rc.top);
		}
	}
	break;
	case MINION_BLUEBULLET:
	{
		for (viCommonBlueBullet = vCommonBlueBullet.begin(); viCommonBlueBullet != vCommonBlueBullet.end(); ++viCommonBlueBullet)
		{
			if (KEYMANAGER->isToggleKey(VK_TAB))
			{
				Rectangle(getMemDC(), viCommonBlueBullet->rc.left, viCommonBlueBullet->rc.top, viCommonBlueBullet->rc.right, viCommonBlueBullet->rc.bottom);
			}

			viCommonBlueBullet->bulletImage->render(getMemDC(), viCommonBlueBullet->rc.left, viCommonBlueBullet->rc.top);
		}
	}
	break;
	case MINION_GREENBULLET:
	{
		for (viCommonGreenBullet = vCommonGreenBullet.begin(); viCommonGreenBullet != vCommonGreenBullet.end(); ++viCommonGreenBullet)
		{
			if (KEYMANAGER->isToggleKey(VK_TAB))
			{
				Rectangle(getMemDC(), viCommonGreenBullet->rc.left, viCommonGreenBullet->rc.top, viCommonGreenBullet->rc.right, viCommonGreenBullet->rc.bottom);
			}

			viCommonGreenBullet->bulletImage->render(getMemDC(), viCommonGreenBullet->rc.left, viCommonGreenBullet->rc.top);
		}
	}
	break;
	case MINION_YELLOWBULLET:
	{
		for (viCommonYellowBullet = vCommonYellowBullet.begin(); viCommonYellowBullet != vCommonYellowBullet.end(); ++viCommonYellowBullet)
		{
			if (KEYMANAGER->isToggleKey(VK_TAB))
			{
				Rectangle(getMemDC(), viCommonYellowBullet->rc.left, viCommonYellowBullet->rc.top, viCommonYellowBullet->rc.right, viCommonYellowBullet->rc.bottom);
			}

			viCommonYellowBullet->bulletImage->render(getMemDC(), viCommonYellowBullet->rc.left, viCommonYellowBullet->rc.top);
		}
	}
	break;
	default:
		break;
	}
}

void bulletManager::minionSpinBulletFire(int bulletKind, float x, float y, int interval)
{
	switch (bulletKind)
	{
	case MINION_REDBULLET:		// 레드 미니언 상모돌리기 탄
	{
		spinRedBullet = OBJECTPOOL->getBullet();
		spinRedCannon.center.x = x;
		spinRedCannon.center.y = y;
		spinRedCannon.cannon = 100;

		spinRedBullet.bulletImage = IMAGEMANAGER->findImage("redMinionBullet");
		spinRedBullet.speed = 5.0f;
		spinRedBullet.angle = spinRedCannon.angle;

		if (spinRedBulletSpeed % interval == 0)		// 총알간 거리 조절
		{
			// 총알 무브
			//redMinionCannon.angle -=0.05f;
			spinRedBullet.x = spinRedCannon.center.x;
			spinRedBullet.y = spinRedCannon.center.y;
			spinRedBullet.rc = RectMakeCenter(spinRedBullet.x,
				spinRedBullet.y,
				spinRedBullet.bulletImage->getWidth(),
				spinRedBullet.bulletImage->getHeight());
			//
		}
		vSpinRedBullet.push_back(spinRedBullet);
		
		spinRedCannon.cannonEnd.x = cosf(spinRedCannon.angle) * spinRedCannon.cannon + spinRedCannon.center.x;
		spinRedCannon.cannonEnd.y = -sinf(spinRedCannon.angle) * spinRedCannon.cannon + spinRedCannon.center.y;
	}
	break;
	case MINION_BLUEBULLET:
	{
		spinBlueBullet = OBJECTPOOL->getBullet();
		spinBlueCannon.center.x = x;
		spinBlueCannon.center.y = y;
		spinBlueCannon.cannon = 100;

		spinBlueBullet.bulletImage = IMAGEMANAGER->findImage("blueMinionBullet");
		spinBlueBullet.speed = 5.0f;
		spinBlueBullet.angle = spinBlueCannon.angle;

		if (spinBlueBulletSpeed % interval == 0)		// 총알간 거리 조절
		{
			// 총알 무브
			//blueMinionCannon.angle -=0.05f;
			spinBlueBullet.x = spinBlueCannon.center.x;
			spinBlueBullet.y = spinBlueCannon.center.y;
			spinBlueBullet.rc = RectMakeCenter(spinBlueBullet.x,
				spinBlueBullet.y,
				spinBlueBullet.bulletImage->getWidth(),
				spinBlueBullet.bulletImage->getHeight());
			//
		}
		vSpinBlueBullet.push_back(spinBlueBullet);


		spinBlueCannon.cannonEnd.x = cosf(spinBlueCannon.angle) * spinBlueCannon.cannon + spinBlueCannon.center.x;
		spinBlueCannon.cannonEnd.y = -sinf(spinBlueCannon.angle) * spinBlueCannon.cannon + spinBlueCannon.center.y;
	}
		break;
	case MINION_GREENBULLET:
	{
		spinGreenBullet = OBJECTPOOL->getBullet();
		spinGreenCannon.center.x = x;
		spinGreenCannon.center.y = y;
		spinGreenCannon.cannon = 100;

		spinGreenBullet.bulletImage = IMAGEMANAGER->findImage("greenMinionBullet");
		spinGreenBullet.speed = 5.0f;
		spinGreenBullet.angle = spinGreenCannon.angle;

		if (spinGreenBulletSpeed % interval == 0)		// 총알간 거리 조절
		{
			// 총알 무브
			//greenMinionCannon.angle -=0.05f;
			spinGreenBullet.x = spinGreenCannon.center.x;
			spinGreenBullet.y = spinGreenCannon.center.y;
			spinGreenBullet.rc = RectMakeCenter(spinGreenBullet.x,
				spinGreenBullet.y,
				spinGreenBullet.bulletImage->getWidth(),
				spinGreenBullet.bulletImage->getHeight());
			//
		}
		vSpinGreenBullet.push_back(spinGreenBullet);


		spinGreenCannon.cannonEnd.x = cosf(spinGreenCannon.angle) * spinGreenCannon.cannon + spinGreenCannon.center.x;
		spinGreenCannon.cannonEnd.y = -sinf(spinGreenCannon.angle) * spinGreenCannon.cannon + spinGreenCannon.center.y;
	}
		break;	
	case MINION_YELLOWBULLET:
	{
		spinYellowBullet = OBJECTPOOL->getBullet();
		spinYellowCannon.center.x = x;
		spinYellowCannon.center.y = y;
		spinYellowCannon.cannon = 100;

		spinYellowBullet.bulletImage = IMAGEMANAGER->findImage("yellowMinionBullet");
		spinYellowBullet.speed = 5.0f;
		spinYellowBullet.angle = spinYellowCannon.angle;

		if (spinYellowBulletSpeed % interval == 0)		// 총알간 거리 조절
		{
			// 총알 무브
			//yellowMinionCannon.angle -=0.05f;
			spinYellowBullet.x = spinYellowCannon.center.x;
			spinYellowBullet.y = spinYellowCannon.center.y;
			spinYellowBullet.rc = RectMakeCenter(spinYellowBullet.x,
				spinYellowBullet.y,
				spinYellowBullet.bulletImage->getWidth(),
				spinYellowBullet.bulletImage->getHeight());
			//
		}
		vSpinYellowBullet.push_back(spinYellowBullet);

		spinYellowCannon.cannonEnd.x = cosf(spinYellowCannon.angle) * spinYellowCannon.cannon + spinYellowCannon.center.x;
		spinYellowCannon.cannonEnd.y = -sinf(spinYellowCannon.angle) * spinYellowCannon.cannon + spinYellowCannon.center.y;
	}
		break;
	default:
		break;
	}
}

void bulletManager::minionSpinBulletMove(int bulletKind)
{
	switch (bulletKind)
	{
	case MINION_REDBULLET:		// 레드 미니언 상모돌리기 탄
	{
		spinRedBulletSpeed++;

		if (spinRedBulletSpeed % 1 == 0)		// 총알발사 각도 조절
		{
			spinRedCannon.angle -= 0.05f;
		}

		// 총알 발사
		viSpinRedBullet = vSpinRedBullet.begin();
		for (viSpinRedBullet; viSpinRedBullet != vSpinRedBullet.end();)
		{
			viSpinRedBullet->x += cosf(viSpinRedBullet->angle) * viSpinRedBullet->speed;
			viSpinRedBullet->y += -sinf(viSpinRedBullet->angle) * viSpinRedBullet->speed;

			viSpinRedBullet->rc = RectMakeCenter(viSpinRedBullet->x,
				viSpinRedBullet->y, viSpinRedBullet->bulletImage->getWidth(),
				viSpinRedBullet->bulletImage->getHeight());

			if (100 >= viSpinRedBullet->rc.right || WINSIZEY <= viSpinRedBullet->rc.top ||
				WINSIZEX - 300 <= viSpinRedBullet->rc.left || 50 > viSpinRedBullet->rc.bottom)
			{
				spinRedBullet = { 0, };
				OBJECTPOOL->setBulletVector(spinRedBullet);
				viSpinRedBullet = vSpinRedBullet.erase(viSpinRedBullet);
			}
			else ++viSpinRedBullet;
		}
	}
		break;
	case MINION_BLUEBULLET:
	{
		spinBlueBulletSpeed++;

		if (spinBlueBulletSpeed % 1 == 0)		// 총알발사 각도 조절
		{
			spinBlueCannon.angle += 0.05f;
		}

		// 총알 발사
		viSpinBlueBullet = vSpinBlueBullet.begin();
		for (viSpinBlueBullet; viSpinBlueBullet != vSpinBlueBullet.end();)
		{
			viSpinBlueBullet->x += cosf(viSpinBlueBullet->angle) * viSpinBlueBullet->speed;
			viSpinBlueBullet->y += -sinf(viSpinBlueBullet->angle) * viSpinBlueBullet->speed;

			viSpinBlueBullet->rc = RectMakeCenter(viSpinBlueBullet->x,
				viSpinBlueBullet->y, viSpinBlueBullet->bulletImage->getWidth(),
				viSpinBlueBullet->bulletImage->getHeight());

			if (100 >= viSpinBlueBullet->rc.right || WINSIZEY <= viSpinBlueBullet->rc.top ||
				WINSIZEX - 300 <= viSpinBlueBullet->rc.left || 50 > viSpinBlueBullet->rc.bottom)
			{
				spinBlueBullet = { 0, };
				OBJECTPOOL->setBulletVector(spinBlueBullet);
				viSpinBlueBullet = vSpinBlueBullet.erase(viSpinBlueBullet);
			}
			else ++viSpinBlueBullet;
		}
	}
		break;
	case MINION_GREENBULLET:
	{
		spinGreenBulletSpeed++;

		if (spinGreenBulletSpeed % 1 == 0)		// 총알발사 각도 조절
		{
			spinGreenCannon.angle += 0.05f;
		}

		// 총알 발사
		viSpinGreenBullet = vSpinGreenBullet.begin();
		for (viSpinGreenBullet; viSpinGreenBullet != vSpinGreenBullet.end();)
		{
			viSpinGreenBullet->x += cosf(viSpinGreenBullet->angle) * viSpinGreenBullet->speed;
			viSpinGreenBullet->y += -sinf(viSpinGreenBullet->angle) * viSpinGreenBullet->speed;

			viSpinGreenBullet->rc = RectMakeCenter(viSpinGreenBullet->x,
				viSpinGreenBullet->y, viSpinGreenBullet->bulletImage->getWidth(),
				viSpinGreenBullet->bulletImage->getHeight());

			if (100 >= viSpinGreenBullet->rc.right || WINSIZEY <= viSpinGreenBullet->rc.top ||
				WINSIZEX - 300 <= viSpinGreenBullet->rc.left || 50 > viSpinGreenBullet->rc.bottom)
			{
				spinGreenBullet = { 0, };
				OBJECTPOOL->setBulletVector(spinGreenBullet);
				viSpinGreenBullet = vSpinGreenBullet.erase(viSpinGreenBullet);
			}
			else ++viSpinGreenBullet;
		}
	}
		break;
	case MINION_YELLOWBULLET:
	{
		spinYellowBulletSpeed++;

		if (spinYellowBulletSpeed % 1 == 0)		// 총알발사 각도 조절
		{
			spinYellowCannon.angle -= 0.05f;
		}

		// 총알 발사
		viSpinYellowBullet = vSpinYellowBullet.begin();
		for (viSpinYellowBullet; viSpinYellowBullet != vSpinYellowBullet.end();)
		{
			viSpinYellowBullet->x -= cosf(viSpinYellowBullet->angle) * viSpinYellowBullet->speed;
			viSpinYellowBullet->y -= -sinf(viSpinYellowBullet->angle) * viSpinYellowBullet->speed;

			viSpinYellowBullet->rc = RectMakeCenter(viSpinYellowBullet->x,
				viSpinYellowBullet->y, viSpinYellowBullet->bulletImage->getWidth(),
				viSpinYellowBullet->bulletImage->getHeight());

			if (100 >= viSpinYellowBullet->rc.right || WINSIZEY <= viSpinYellowBullet->rc.top ||
				WINSIZEX - 300 <= viSpinYellowBullet->rc.left || 50 > viSpinYellowBullet->rc.bottom)
			{
				spinYellowBullet = { 0, };
				OBJECTPOOL->setBulletVector(spinYellowBullet);
				viSpinYellowBullet = vSpinYellowBullet.erase(viSpinYellowBullet);
			}
			else ++viSpinYellowBullet;
		}
	}
		break;

	default:
		break;
	}	
}

void bulletManager::minionSpinBulletRender(int bulletKind)
{
	switch (bulletKind)
	{
	case MINION_REDBULLET:		// 레드 미니언 상모돌리기 탄
	{
		for (viSpinRedBullet = vSpinRedBullet.begin(); viSpinRedBullet != vSpinRedBullet.end(); ++viSpinRedBullet)
		{
			if (KEYMANAGER->isToggleKey(VK_TAB))
			{
				Rectangle(getMemDC(), viSpinRedBullet->rc.left, viSpinRedBullet->rc.top, viSpinRedBullet->rc.right, viSpinRedBullet->rc.bottom);
			}

			viSpinRedBullet->bulletImage->render(getMemDC(), viSpinRedBullet->rc.left, viSpinRedBullet->rc.top);
		}
	}
	break;
	case MINION_BLUEBULLET :
	{
		for (viSpinBlueBullet = vSpinBlueBullet.begin(); viSpinBlueBullet != vSpinBlueBullet.end(); ++viSpinBlueBullet)
		{
			if (KEYMANAGER->isToggleKey(VK_TAB))
			{
				Rectangle(getMemDC(), viSpinBlueBullet->rc.left, viSpinBlueBullet->rc.top, viSpinBlueBullet->rc.right, viSpinBlueBullet->rc.bottom);
			}

			viSpinBlueBullet->bulletImage->render(getMemDC(), viSpinBlueBullet->rc.left, viSpinBlueBullet->rc.top);
		}
	}
	break;
	case MINION_GREENBULLET:
	{
		for (viSpinGreenBullet = vSpinGreenBullet.begin(); viSpinGreenBullet != vSpinGreenBullet.end(); ++viSpinGreenBullet)
		{
			if (KEYMANAGER->isToggleKey(VK_TAB))
			{
				Rectangle(getMemDC(), viSpinGreenBullet->rc.left, viSpinGreenBullet->rc.top, viSpinGreenBullet->rc.right, viSpinGreenBullet->rc.bottom);
			}

			viSpinGreenBullet->bulletImage->render(getMemDC(), viSpinGreenBullet->rc.left, viSpinGreenBullet->rc.top);
		}
	}
	break;
	case MINION_YELLOWBULLET:
	{
		for (viSpinYellowBullet = vSpinYellowBullet.begin(); viSpinYellowBullet != vSpinYellowBullet.end(); ++viSpinYellowBullet)
		{
			if (KEYMANAGER->isToggleKey(VK_TAB))
			{
				Rectangle(getMemDC(), viSpinYellowBullet->rc.left, viSpinYellowBullet->rc.top, viSpinYellowBullet->rc.right, viSpinYellowBullet->rc.bottom);
			}

			viSpinYellowBullet->bulletImage->render(getMemDC(), viSpinYellowBullet->rc.left, viSpinYellowBullet->rc.top);
		}
	}
	break;
	default:
		break;
	}	
}

void bulletManager::minionHomingBulletFire(int bulletKind, float x, float y, float playerX, float playerY, float bulletSpeed, int interval)
{
	switch (bulletKind)
	{
	case MINION_REDBULLET:		// 레드 미니언 상모돌리기 탄
	{
		homingRedBullet = OBJECTPOOL->getBullet();
		homingRedCannon.center.x = x;
		homingRedCannon.center.y = y;
		homingRedCannon.angle = getAngle(homingRedCannon.center.x, homingRedCannon.center.y, playerX, playerY);

		homingRedBullet.bulletImage = IMAGEMANAGER->findImage("minionHomingRedBullet");
		homingRedBullet.speed = bulletSpeed;
		homingRedBullet.angle = homingRedCannon.angle;

		if (homingRedBulletSpeed % interval == 0)		// 총알간 거리 조절
		{
			// 총알 무브
			homingRedBullet.x = homingRedCannon.center.x;
			homingRedBullet.y = homingRedCannon.center.y;
			homingRedBullet.rc = RectMakeCenter(homingRedBullet.x,
				homingRedBullet.y,
				homingRedBullet.bulletImage->getWidth(),
				homingRedBullet.bulletImage->getHeight());
			//
		}
		vHomingRedBullet.push_back(homingRedBullet);

		homingRedCannon.cannonEnd.x = cosf(homingRedCannon.angle) * homingRedCannon.cannon + homingRedCannon.center.x;
		homingRedCannon.cannonEnd.y = -sinf(homingRedCannon.angle) * homingRedCannon.cannon + homingRedCannon.center.y;
	}
	break;
	case MINION_BLUEBULLET:
	{
		homingBlueBullet = OBJECTPOOL->getBullet();
		homingBlueCannon.center.x = x;
		homingBlueCannon.center.y = y;
		homingBlueCannon.angle = getAngle(homingBlueCannon.center.x, homingBlueCannon.center.y, playerX, playerY);

		homingBlueBullet.bulletImage = IMAGEMANAGER->findImage("minionHomingBlueBullet");
		homingBlueBullet.speed = bulletSpeed;
		homingBlueBullet.angle = homingBlueCannon.angle;

		if (homingBlueBulletSpeed % interval == 0)		// 총알간 거리 조절
		{
			// 총알 무브
			homingBlueBullet.x = homingBlueCannon.center.x;
			homingBlueBullet.y = homingBlueCannon.center.y;
			homingBlueBullet.rc = RectMakeCenter(homingBlueBullet.x,
				homingBlueBullet.y,
				homingBlueBullet.bulletImage->getWidth(),
				homingBlueBullet.bulletImage->getHeight());
			//
		}
		vHomingBlueBullet.push_back(homingBlueBullet);

		homingBlueCannon.cannonEnd.x = cosf(homingBlueCannon.angle) * homingBlueCannon.cannon + homingBlueCannon.center.x;
		homingBlueCannon.cannonEnd.y = -sinf(homingBlueCannon.angle) * homingBlueCannon.cannon + homingBlueCannon.center.y;
	}
	break;
	default:
		break;
	}
}

void bulletManager::minionHomingBulletMove(int bulletKind)
{
	switch (bulletKind)
	{
	case MINION_REDBULLET:		
	{
		homingRedBulletSpeed++;

		// 총알 발사
		viHomingRedBullet = vHomingRedBullet.begin();
		for (viHomingRedBullet; viHomingRedBullet != vHomingRedBullet.end();)
		{
			viHomingRedBullet->x += cosf(viHomingRedBullet->angle) * viHomingRedBullet->speed;
			viHomingRedBullet->y += -sinf(viHomingRedBullet->angle) * viHomingRedBullet->speed;

			viHomingRedBullet->rc = RectMakeCenter(viHomingRedBullet->x,
				viHomingRedBullet->y, viHomingRedBullet->bulletImage->getWidth(),
				viHomingRedBullet->bulletImage->getHeight());

			if (100 >= viHomingRedBullet->rc.right || WINSIZEY <= viHomingRedBullet->rc.top ||
				WINSIZEX - 300 <= viHomingRedBullet->rc.left || 50 > viHomingRedBullet->rc.bottom)
			{
				homingRedBullet = { 0, };
				OBJECTPOOL->setBulletVector(homingRedBullet);
				viHomingRedBullet = vHomingRedBullet.erase(viHomingRedBullet);
			}
			else ++viHomingRedBullet;
		}
	}
	break;
	case MINION_BLUEBULLET:
	{
		homingBlueBulletSpeed++;

		// 총알 발사
		viHomingBlueBullet = vHomingBlueBullet.begin();
		for (viHomingBlueBullet; viHomingBlueBullet != vHomingBlueBullet.end();)
		{
			viHomingBlueBullet->x += cosf(viHomingBlueBullet->angle) * viHomingBlueBullet->speed;
			viHomingBlueBullet->y += -sinf(viHomingBlueBullet->angle) * viHomingBlueBullet->speed;

			viHomingBlueBullet->rc = RectMakeCenter(viHomingBlueBullet->x,
				viHomingBlueBullet->y, viHomingBlueBullet->bulletImage->getWidth(),
				viHomingBlueBullet->bulletImage->getHeight());

			if (100 >= viHomingBlueBullet->rc.right || WINSIZEY <= viHomingBlueBullet->rc.top ||
				WINSIZEX - 300 <= viHomingBlueBullet->rc.left || 50 > viHomingBlueBullet->rc.bottom)
			{
				homingBlueBullet = { 0, };
				OBJECTPOOL->setBulletVector(homingBlueBullet);
				viHomingBlueBullet = vHomingBlueBullet.erase(viHomingBlueBullet);
			}
			else ++viHomingBlueBullet;
		}
	}
	break;
	default:
		break;
	}
}

void bulletManager::minionHomingBulletRender(int bulletKind)
{
	switch (bulletKind)
	{
	case MINION_REDBULLET:		// 레드 미니언 상모돌리기 탄
	{
		for (viHomingRedBullet = vHomingRedBullet.begin(); viHomingRedBullet != vHomingRedBullet.end(); ++viHomingRedBullet)
		{
			if (KEYMANAGER->isToggleKey(VK_TAB))
			{
				Rectangle(getMemDC(), viHomingRedBullet->rc.left, viHomingRedBullet->rc.top, viHomingRedBullet->rc.right, viHomingRedBullet->rc.bottom);
			}

			viHomingRedBullet->bulletImage->render(getMemDC(), viHomingRedBullet->rc.left, viHomingRedBullet->rc.top);
		}
	}
	break;
	case MINION_BLUEBULLET:
	{
		for (viHomingBlueBullet = vHomingBlueBullet.begin(); viHomingBlueBullet != vHomingBlueBullet.end(); ++viHomingBlueBullet)
		{
			if (KEYMANAGER->isToggleKey(VK_TAB))
			{
				Rectangle(getMemDC(), viHomingBlueBullet->rc.left, viHomingBlueBullet->rc.top, viHomingBlueBullet->rc.right, viHomingBlueBullet->rc.bottom);
			}

			viHomingBlueBullet->bulletImage->render(getMemDC(), viHomingBlueBullet->rc.left, viHomingBlueBullet->rc.top);
		}
	}
	break;
	default:
		break;
	}
}

void bulletManager::minionBulletCollision()
{
	redBulletPlayerCollision();
	blueBulletPlayerCollision();
	greenBulletPlayerCollision();
	yellowBulletPlayerCollision();
}

void bulletManager::redBulletPlayerCollision()
{
	for (int i = 0; i < vCommonRedBullet.size(); i++)
	{
		RECT rc;
		if (getDistance(vCommonRedBullet[i].x, vCommonRedBullet[i].y,
			PLAYER->getPlayerRectX(), PLAYER->getPlayerRectY()) <= PLAYERHIT)
		{
			if (IntersectRect(&rc, &vCommonRedBullet[i].rc, &PLAYER->getPlayerRect()))
			{
				commonRedBullet = { 0, };
				OBJECTPOOL->setBulletVector(commonRedBullet);
				vCommonRedBullet.erase(vCommonRedBullet.begin() + i);
				// 플레이어 히트
				collisionCheckNum++;
				break;
			}
		}
	}
	for (int i = 0; i < vSpinRedBullet.size(); i++)
	{
		RECT rc;
		if (getDistance(vSpinRedBullet[i].x, vSpinRedBullet[i].y,
			PLAYER->getPlayerRectX(), PLAYER->getPlayerRectY()) <= PLAYERHIT)
		{
			if (IntersectRect(&rc, &vSpinRedBullet[i].rc, &PLAYER->getPlayerRect()))
			{
				spinRedBullet = { 0, };
				OBJECTPOOL->setBulletVector(spinRedBullet);
				vSpinRedBullet.erase(vSpinRedBullet.begin() + i);
				// 플레이어 히트
				collisionCheckNum++;
				break;
			}
		}
	}
	for (int i = 0; i < vHomingRedBullet.size(); i++)
	{
		RECT rc;
		if (getDistance(vHomingRedBullet[i].x, vHomingRedBullet[i].y,
			PLAYER->getPlayerRectX(), PLAYER->getPlayerRectY()) <= PLAYERHIT)
		{
			if (IntersectRect(&rc, &vHomingRedBullet[i].rc, &PLAYER->getPlayerRect()))
			{
				homingRedBullet = { 0, };
				OBJECTPOOL->setBulletVector(homingRedBullet);
				vHomingRedBullet.erase(vHomingRedBullet.begin() + i);
				// 플레이어 히트
				collisionCheckNum++;
				break;
			}
		}
	}
}

void bulletManager::blueBulletPlayerCollision()
{
	for (int i = 0; i < vCommonBlueBullet.size(); i++)
	{
		RECT rc;
		if (getDistance(vCommonBlueBullet[i].x, vCommonBlueBullet[i].y,
			PLAYER->getPlayerRectX(), PLAYER->getPlayerRectY()) <= PLAYERHIT)
		{
			if (IntersectRect(&rc, &vCommonBlueBullet[i].rc, &PLAYER->getPlayerRect()))
			{
				commonBlueBullet = { 0, };
				OBJECTPOOL->setBulletVector(commonBlueBullet);
				vCommonBlueBullet.erase(vCommonBlueBullet.begin() + i);
				// 플레이어 히트
				collisionCheckNum++;
				break;
			}
		}
	}
	for (int i = 0; i < vSpinBlueBullet.size(); i++)
	{
		RECT rc;
		if (getDistance(vSpinBlueBullet[i].x, vSpinBlueBullet[i].y,
			PLAYER->getPlayerRectX(), PLAYER->getPlayerRectY()) <= PLAYERHIT)
		{
			if (IntersectRect(&rc, &vSpinBlueBullet[i].rc, &PLAYER->getPlayerRect()))
			{
				spinBlueBullet = { 0, };
				OBJECTPOOL->setBulletVector(spinBlueBullet);
				vSpinBlueBullet.erase(vSpinBlueBullet.begin() + i);
				// 플레이어 히트
				collisionCheckNum++;
				break;
			}
		}
	}
	for (int i = 0; i < vHomingBlueBullet.size(); i++)
	{
		RECT rc;
		if (getDistance(vHomingBlueBullet[i].x, vHomingBlueBullet[i].y,
			PLAYER->getPlayerRectX(), PLAYER->getPlayerRectY()) <= PLAYERHIT)
		{
			if (IntersectRect(&rc, &vHomingBlueBullet[i].rc, &PLAYER->getPlayerRect()))
			{
				homingBlueBullet = { 0, };
				OBJECTPOOL->setBulletVector(homingBlueBullet);
				vHomingBlueBullet.erase(vHomingBlueBullet.begin() + i);
				// 플레이어 히트
				collisionCheckNum++;
				break;
			}
		}
	}
}

void bulletManager::greenBulletPlayerCollision()
{
	for (int i = 0; i < vCommonGreenBullet.size(); i++)
	{
		RECT rc;
		if (getDistance(vCommonGreenBullet[i].x, vCommonGreenBullet[i].y,
			PLAYER->getPlayerRectX(), PLAYER->getPlayerRectY()) <= PLAYERHIT)
		{
			if (IntersectRect(&rc, &vCommonGreenBullet[i].rc, &PLAYER->getPlayerRect()))
			{
				commonGreenBullet = { 0, };
				OBJECTPOOL->setBulletVector(commonGreenBullet);
				vCommonGreenBullet.erase(vCommonGreenBullet.begin() + i);
				// 플레이어 히트
				collisionCheckNum++;
				break;
			}
		}
	}
	for (int i = 0; i < vSpinGreenBullet.size(); i++)
	{
		RECT rc;
		if (getDistance(vSpinGreenBullet[i].x, vSpinGreenBullet[i].y,
			PLAYER->getPlayerRectX(), PLAYER->getPlayerRectY()) <= PLAYERHIT)
		{
			if (IntersectRect(&rc, &vSpinGreenBullet[i].rc, &PLAYER->getPlayerRect()))
			{
				spinGreenBullet = { 0, };
				OBJECTPOOL->setBulletVector(spinGreenBullet);
				vSpinGreenBullet.erase(vSpinGreenBullet.begin() + i);
				// 플레이어 히트
				collisionCheckNum++;
				break;
			}
		}
	}
}

void bulletManager::yellowBulletPlayerCollision()
{
	for (int i = 0; i < vCommonYellowBullet.size(); i++)
	{
		RECT rc;
		if (getDistance(vCommonYellowBullet[i].x, vCommonYellowBullet[i].y,
			PLAYER->getPlayerRectX(), PLAYER->getPlayerRectY()) <= PLAYERHIT)
		{
			if (IntersectRect(&rc, &vCommonYellowBullet[i].rc, &PLAYER->getPlayerRect()))
			{
				commonYellowBullet = { 0, };
				OBJECTPOOL->setBulletVector(commonYellowBullet);
				vCommonYellowBullet.erase(vCommonYellowBullet.begin() + i);
				// 플레이어 히트
				collisionCheckNum++;
				break;
			}
		}
	}
	for (int i = 0; i < vSpinYellowBullet.size(); i++)
	{
		RECT rc;
		if (getDistance(vSpinYellowBullet[i].x, vSpinYellowBullet[i].y,
			PLAYER->getPlayerRectX(), PLAYER->getPlayerRectY()) <= PLAYERHIT)
		{
			if (IntersectRect(&rc, &vSpinYellowBullet[i].rc, &PLAYER->getPlayerRect()))
			{
				spinYellowBullet = { 0, };
				OBJECTPOOL->setBulletVector(spinYellowBullet);
				vSpinYellowBullet.erase(vSpinYellowBullet.begin() + i);
				// 플레이어 히트
				collisionCheckNum++;
				break;
			}
		}
	}
}