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
	vRedMinionBullet.reserve(2000);
	vBlueMinionBullet.reserve(2000);
	vGreenMinionBullet.reserve(2000);
	vYellowMinionBullet.reserve(2000);

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

void bulletManager::playerBulletCollision()
{
	playerCommonBulletRedMinionCollision();
	playerCommonBulletBlueMinionCollision();
	playerCommonBulletGreenMinionCollision();
	playerCommonBulletYellowMinionCollision();
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
	for (int i = 0; i < vRedMinionBullet.size(); i++)
	{
		RECT rc;
		if (getDistance(vRedMinionBullet[i].x, vRedMinionBullet[i].y,
			PLAYER->getPlayerRectX(), PLAYER->getPlayerRectY()) <= 10)
		{
			if (IntersectRect(&rc, &vRedMinionBullet[i].rc, &PLAYER->getPlayerRect()))
			{
				redMinionBullet = { 0, };
				OBJECTPOOL->setBulletVector(redMinionBullet);
				vRedMinionBullet.erase(vRedMinionBullet.begin() + i);
				// 플레이어 히트
				collisionCheckNum++;
				break;
			}
		}
	}
}

void bulletManager::blueBulletPlayerCollision()
{
	for (int i = 0; i < vBlueMinionBullet.size(); i++)
	{
		RECT rc;
		if (getDistance(vBlueMinionBullet[i].x, vBlueMinionBullet[i].y,
			PLAYER->getPlayerRectX(), PLAYER->getPlayerRectY()) <= 10)
		{
			if (IntersectRect(&rc, &vBlueMinionBullet[i].rc, &PLAYER->getPlayerRect()))
			{
				blueMinionBullet = { 0, };
				OBJECTPOOL->setBulletVector(blueMinionBullet);
				vBlueMinionBullet.erase(vBlueMinionBullet.begin() + i);
				// 플레이어 히트
				collisionCheckNum++;
				break;
			}
		}
	}
}

void bulletManager::greenBulletPlayerCollision()
{
	for (int i = 0; i < vGreenMinionBullet.size(); i++)
	{
		RECT rc;
		if (getDistance(vGreenMinionBullet[i].x, vGreenMinionBullet[i].y,
			PLAYER->getPlayerRectX(), PLAYER->getPlayerRectY()) <= 10)
		{
			if (IntersectRect(&rc, &vGreenMinionBullet[i].rc, &PLAYER->getPlayerRect()))
			{
				greenMinionBullet = { 0, };
				OBJECTPOOL->setBulletVector(greenMinionBullet);
				vGreenMinionBullet.erase(vGreenMinionBullet.begin() + i);
				// 플레이어 히트
				collisionCheckNum++;
				break;
			}
		}
	}
}

void bulletManager::yellowBulletPlayerCollision()
{
	for (int i = 0; i < vYellowMinionBullet.size(); i++)
	{
		RECT rc;
		if (getDistance(vYellowMinionBullet[i].x, vYellowMinionBullet[i].y,
			PLAYER->getPlayerRectX(), PLAYER->getPlayerRectY()) <= 10)
		{
			if (IntersectRect(&rc, &vYellowMinionBullet[i].rc, &PLAYER->getPlayerRect()))
			{
				yellowMinionBullet = { 0, };
				OBJECTPOOL->setBulletVector(yellowMinionBullet);
				vYellowMinionBullet.erase(vYellowMinionBullet.begin() + i);
				// 플레이어 히트
				collisionCheckNum++;
				break;
			}
		}
	}
}

void bulletManager::playerCommonBulletRedMinionCollision()
{
	for (int i = 0; i < vPlayerCommonBullet.size(); i++)
	{
		for (int j = 0; j < ENEMYMANAGER->getVRedMinion().size(); j++)
		{
			RECT rc;
			if (getDistance(vPlayerCommonBullet[i].x, vPlayerCommonBullet[i].y,
				ENEMYMANAGER->getVRedMinion()[j]->getRedMinionX(), ENEMYMANAGER->getVRedMinion()[j]->getRedMinionY()) <= 20)
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
				ENEMYMANAGER->getVBlueMinion()[j]->getBlueMinionX(), ENEMYMANAGER->getVBlueMinion()[j]->getBlueMinionY()) <= 20)
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
				ENEMYMANAGER->getVGreenMinion()[j]->getGreenMinionX(), ENEMYMANAGER->getVGreenMinion()[j]->getGreenMinionY()) <= 20)
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
				ENEMYMANAGER->getVYellowMinion()[j]->getYellowMinionX(), ENEMYMANAGER->getVYellowMinion()[j]->getYellowMinionY()) <= 20)
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


void bulletManager::minionSpinBulletFire(int bulletKind, float x, float y)
{
	switch (bulletKind)
	{
	case MINION_REDBULLET:		// 레드 미니언 상모돌리기 탄
	{
		redMinionBullet = OBJECTPOOL->getBullet();
		redMinionCannon.center.x = x;
		redMinionCannon.center.y = y;
		redMinionCannon.cannon = 100;

		redMinionBullet.bulletImage = IMAGEMANAGER->findImage("redMinionBullet");
		redMinionBullet.speed = 5.0f;
		redMinionBullet.angle = redMinionCannon.angle;

		if (redMinionBulletSpeed % 10 == 0)		// 총알간 거리 조절
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
	break;
	case MINION_BLUEBULLET:
	{
		blueMinionBullet = OBJECTPOOL->getBullet();
		blueMinionCannon.center.x = x;
		blueMinionCannon.center.y = y;
		blueMinionCannon.cannon = 100;

		blueMinionBullet.bulletImage = IMAGEMANAGER->findImage("blueMinionBullet");
		blueMinionBullet.speed = 5.0f;
		blueMinionBullet.angle = blueMinionCannon.angle;

		if (blueMinionBulletSpeed % 10 == 0)		// 총알간 거리 조절
		{
			// 총알 무브
			//blueMinionCannon.angle -=0.05f;
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
		break;
	case MINION_GREENBULLET:
	{
		greenMinionBullet = OBJECTPOOL->getBullet();
		greenMinionCannon.center.x = x;
		greenMinionCannon.center.y = y;
		greenMinionCannon.cannon = 100;

		greenMinionBullet.bulletImage = IMAGEMANAGER->findImage("greenMinionBullet");
		greenMinionBullet.speed = 5.0f;
		greenMinionBullet.angle = greenMinionCannon.angle;

		if (greenMinionBulletSpeed % 10 == 0)		// 총알간 거리 조절
		{
			// 총알 무브
			//greenMinionCannon.angle -=0.05f;
			greenMinionBullet.x = greenMinionCannon.center.x;
			greenMinionBullet.y = greenMinionCannon.center.y;
			greenMinionBullet.rc = RectMakeCenter(greenMinionBullet.x,
				greenMinionBullet.y,
				greenMinionBullet.bulletImage->getWidth(),
				greenMinionBullet.bulletImage->getHeight());
			//
		}
		vGreenMinionBullet.push_back(greenMinionBullet);


		greenMinionCannon.cannonEnd.x = cosf(greenMinionCannon.angle) * greenMinionCannon.cannon + greenMinionCannon.center.x;
		greenMinionCannon.cannonEnd.y = -sinf(greenMinionCannon.angle) * greenMinionCannon.cannon + greenMinionCannon.center.y;
	}
		break;	
	case MINION_YELLOWBULLET:
	{
		yellowMinionBullet = OBJECTPOOL->getBullet();
		yellowMinionCannon.center.x = x;
		yellowMinionCannon.center.y = y;
		yellowMinionCannon.cannon = 100;

		yellowMinionBullet.bulletImage = IMAGEMANAGER->findImage("yellowMinionBullet");
		yellowMinionBullet.speed = 5.0f;
		yellowMinionBullet.angle = yellowMinionCannon.angle;

		if (redMinionBulletSpeed % 10 == 0)		// 총알간 거리 조절
		{
			// 총알 무브
			//yellowMinionCannon.angle -=0.05f;
			yellowMinionBullet.x = yellowMinionCannon.center.x;
			yellowMinionBullet.y = yellowMinionCannon.center.y;
			yellowMinionBullet.rc = RectMakeCenter(yellowMinionBullet.x,
				yellowMinionBullet.y,
				yellowMinionBullet.bulletImage->getWidth(),
				yellowMinionBullet.bulletImage->getHeight());
			//
		}
		vYellowMinionBullet.push_back(yellowMinionBullet);

		yellowMinionCannon.cannonEnd.x = cosf(yellowMinionCannon.angle) * yellowMinionCannon.cannon + yellowMinionCannon.center.x;
		yellowMinionCannon.cannonEnd.y = -sinf(yellowMinionCannon.angle) * yellowMinionCannon.cannon + yellowMinionCannon.center.y;
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
		break;
	case MINION_BLUEBULLET:
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
				blueMinionBullet = { 0, };
				OBJECTPOOL->setBulletVector(blueMinionBullet);
				viBlueMinionBullet = vBlueMinionBullet.erase(viBlueMinionBullet);
			}
			else ++viBlueMinionBullet;
		}
	}
		break;
	case MINION_GREENBULLET:
	{
		greenMinionBulletSpeed++;

		if (greenMinionBulletSpeed % 1 == 0)		// 총알발사 각도 조절
		{
			greenMinionCannon.angle += 0.05f;
		}

		// 총알 발사
		viGreenMinionBullet = vGreenMinionBullet.begin();
		for (viGreenMinionBullet; viGreenMinionBullet != vGreenMinionBullet.end();)
		{
			viGreenMinionBullet->x -= cosf(viGreenMinionBullet->angle) * viGreenMinionBullet->speed;
			viGreenMinionBullet->y -= -sinf(viGreenMinionBullet->angle) * viGreenMinionBullet->speed;

			viGreenMinionBullet->rc = RectMakeCenter(viGreenMinionBullet->x,
				viGreenMinionBullet->y, viGreenMinionBullet->bulletImage->getWidth(),
				viGreenMinionBullet->bulletImage->getHeight());

			if (100 >= viGreenMinionBullet->rc.right || WINSIZEY <= viGreenMinionBullet->rc.top ||
				WINSIZEX - 300 <= viGreenMinionBullet->rc.left || 50 > viGreenMinionBullet->rc.bottom)
			{
				greenMinionBullet = { 0, };
				OBJECTPOOL->setBulletVector(greenMinionBullet);
				viGreenMinionBullet = vGreenMinionBullet.erase(viGreenMinionBullet);
			}
			else ++viGreenMinionBullet;
		}
	}
		break;
	case MINION_YELLOWBULLET:
	{
		yellowMinionBulletSpeed++;

		if (yellowMinionBulletSpeed % 1 == 0)		// 총알발사 각도 조절
		{
			yellowMinionCannon.angle -= 0.05f;
		}

		// 총알 발사
		viYellowMinionBullet = vYellowMinionBullet.begin();
		for (viYellowMinionBullet; viYellowMinionBullet != vYellowMinionBullet.end();)
		{
			viYellowMinionBullet->x += cosf(viYellowMinionBullet->angle) * viYellowMinionBullet->speed;
			viYellowMinionBullet->y += -sinf(viYellowMinionBullet->angle) * viYellowMinionBullet->speed;

			viYellowMinionBullet->rc = RectMakeCenter(viYellowMinionBullet->x,
				viYellowMinionBullet->y, viYellowMinionBullet->bulletImage->getWidth(),
				viYellowMinionBullet->bulletImage->getHeight());

			if (100 >= viYellowMinionBullet->rc.right || WINSIZEY <= viYellowMinionBullet->rc.top ||
				WINSIZEX - 300 <= viYellowMinionBullet->rc.left || 50 > viYellowMinionBullet->rc.bottom)
			{
				yellowMinionBullet = { 0, };
				OBJECTPOOL->setBulletVector(yellowMinionBullet);
				viYellowMinionBullet = vYellowMinionBullet.erase(viYellowMinionBullet);
			}
			else ++viYellowMinionBullet;
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
		for (viRedMinionBullet = vRedMinionBullet.begin(); viRedMinionBullet != vRedMinionBullet.end(); ++viRedMinionBullet)
		{
			if (KEYMANAGER->isToggleKey(VK_TAB))
			{
				Rectangle(getMemDC(), viRedMinionBullet->rc.left, viRedMinionBullet->rc.top, viRedMinionBullet->rc.right, viRedMinionBullet->rc.bottom);
			}

			viRedMinionBullet->bulletImage->render(getMemDC(), viRedMinionBullet->rc.left, viRedMinionBullet->rc.top);
		}
	}
	break;
	case MINION_BLUEBULLET :
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
	break;
	case MINION_GREENBULLET:
	{
		for (viGreenMinionBullet = vGreenMinionBullet.begin(); viGreenMinionBullet != vGreenMinionBullet.end(); ++viGreenMinionBullet)
		{
			if (KEYMANAGER->isToggleKey(VK_TAB))
			{
				Rectangle(getMemDC(), viGreenMinionBullet->rc.left, viGreenMinionBullet->rc.top, viGreenMinionBullet->rc.right, viGreenMinionBullet->rc.bottom);
			}

			viGreenMinionBullet->bulletImage->render(getMemDC(), viGreenMinionBullet->rc.left, viGreenMinionBullet->rc.top);
		}
	}
	break;
	case MINION_YELLOWBULLET:
	{
		for (viYellowMinionBullet = vYellowMinionBullet.begin(); viYellowMinionBullet != vYellowMinionBullet.end(); ++viYellowMinionBullet)
		{
			if (KEYMANAGER->isToggleKey(VK_TAB))
			{
				Rectangle(getMemDC(), viYellowMinionBullet->rc.left, viYellowMinionBullet->rc.top, viYellowMinionBullet->rc.right, viYellowMinionBullet->rc.bottom);
			}

			viYellowMinionBullet->bulletImage->render(getMemDC(), viYellowMinionBullet->rc.left, viYellowMinionBullet->rc.top);
		}
	}
	break;
	default:
		break;
	}	
}

void bulletManager::minionCommonBulletFire(int bulletKind, float x, float y, float angle)
{
	switch (bulletKind)
	{
	case MINION_REDBULLET:		// 레드 미니언 상모돌리기 탄
	{
		redMinionBullet = OBJECTPOOL->getBullet();
		redMinionCannon.center.x = x;
		redMinionCannon.center.y = y;
		redMinionCannon.angle = angle;

		redMinionBullet.bulletImage = IMAGEMANAGER->findImage("redMinionBullet");
		redMinionBullet.speed = 5.0f;
		redMinionBullet.angle = redMinionCannon.angle;

		if (redMinionBulletSpeed % 50 == 0)		// 총알간 거리 조절
		{
			// 총알 무브
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
	break;
	case MINION_BLUEBULLET:
	{
		blueMinionBullet = OBJECTPOOL->getBullet();
		blueMinionCannon.center.x = x;
		blueMinionCannon.center.y = y;
		blueMinionCannon.angle = angle;

		blueMinionBullet.bulletImage = IMAGEMANAGER->findImage("blueMinionBullet");
		blueMinionBullet.speed = 5.0f;
		blueMinionBullet.angle = blueMinionCannon.angle;

		if (blueMinionBulletSpeed % 40 == 0)		// 총알간 거리 조절
		{
			// 총알 무브
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
	break;
	case MINION_GREENBULLET:
	{
		greenMinionBullet = OBJECTPOOL->getBullet();
		greenMinionCannon.center.x = x;
		greenMinionCannon.center.y = y;
		greenMinionCannon.angle = angle;

		greenMinionBullet.bulletImage = IMAGEMANAGER->findImage("greenMinionBullet");
		greenMinionBullet.speed = 5.0f;
		greenMinionBullet.angle = greenMinionCannon.angle;

		if (greenMinionBulletSpeed % 20 == 0)		// 총알간 거리 조절
		{
			// 총알 무브
			greenMinionBullet.x = greenMinionCannon.center.x;
			greenMinionBullet.y = greenMinionCannon.center.y;
			greenMinionBullet.rc = RectMakeCenter(greenMinionBullet.x,
				greenMinionBullet.y,
				greenMinionBullet.bulletImage->getWidth(),
				greenMinionBullet.bulletImage->getHeight());
			//
		}
		vGreenMinionBullet.push_back(greenMinionBullet);


		greenMinionCannon.cannonEnd.x = cosf(greenMinionCannon.angle) * greenMinionCannon.cannon + greenMinionCannon.center.x;
		greenMinionCannon.cannonEnd.y = -sinf(greenMinionCannon.angle) * greenMinionCannon.cannon + greenMinionCannon.center.y;
	}
	break;
	case MINION_YELLOWBULLET:
	{
		yellowMinionBullet = OBJECTPOOL->getBullet();
		yellowMinionCannon.center.x = x;
		yellowMinionCannon.center.y = y;
		yellowMinionCannon.angle = angle;

		yellowMinionBullet.bulletImage = IMAGEMANAGER->findImage("yellowMinionBullet");
		yellowMinionBullet.speed = 5.0f;
		yellowMinionBullet.angle = yellowMinionCannon.angle;

		if (redMinionBulletSpeed % 10 == 0)		// 총알간 거리 조절
		{
			// 총알 무브
			yellowMinionBullet.x = yellowMinionCannon.center.x;
			yellowMinionBullet.y = yellowMinionCannon.center.y;
			yellowMinionBullet.rc = RectMakeCenter(yellowMinionBullet.x,
				yellowMinionBullet.y,
				yellowMinionBullet.bulletImage->getWidth(),
				yellowMinionBullet.bulletImage->getHeight());
			//
		}
		vYellowMinionBullet.push_back(yellowMinionBullet);

		yellowMinionCannon.cannonEnd.x = cosf(yellowMinionCannon.angle) * yellowMinionCannon.cannon + yellowMinionCannon.center.x;
		yellowMinionCannon.cannonEnd.y = -sinf(yellowMinionCannon.angle) * yellowMinionCannon.cannon + yellowMinionCannon.center.y;
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
		redMinionBulletSpeed++;

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
	break;
	case MINION_BLUEBULLET:
	{
		blueMinionBulletSpeed++;

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
				blueMinionBullet = { 0, };
				OBJECTPOOL->setBulletVector(blueMinionBullet);
				viBlueMinionBullet = vBlueMinionBullet.erase(viBlueMinionBullet);
			}
			else ++viBlueMinionBullet;
		}
	}
	break;
	case MINION_GREENBULLET:
	{
		greenMinionBulletSpeed++;

		// 총알 발사
		viGreenMinionBullet = vGreenMinionBullet.begin();
		for (viGreenMinionBullet; viGreenMinionBullet != vGreenMinionBullet.end();)
		{
			viGreenMinionBullet->x -= cosf(viGreenMinionBullet->angle) * viGreenMinionBullet->speed;
			viGreenMinionBullet->y -= -sinf(viGreenMinionBullet->angle) * viGreenMinionBullet->speed;

			viGreenMinionBullet->rc = RectMakeCenter(viGreenMinionBullet->x,
				viGreenMinionBullet->y, viGreenMinionBullet->bulletImage->getWidth(),
				viGreenMinionBullet->bulletImage->getHeight());

			if (100 >= viGreenMinionBullet->rc.right || WINSIZEY <= viGreenMinionBullet->rc.top ||
				WINSIZEX - 300 <= viGreenMinionBullet->rc.left || 50 > viGreenMinionBullet->rc.bottom)
			{
				greenMinionBullet = { 0, };
				OBJECTPOOL->setBulletVector(greenMinionBullet);
				viGreenMinionBullet = vGreenMinionBullet.erase(viGreenMinionBullet);
			}
			else ++viGreenMinionBullet;
		}
	}
	break;
	case MINION_YELLOWBULLET:
	{
		yellowMinionBulletSpeed++;

		// 총알 발사
		viYellowMinionBullet = vYellowMinionBullet.begin();
		for (viYellowMinionBullet; viYellowMinionBullet != vYellowMinionBullet.end();)
		{
			viYellowMinionBullet->x += cosf(viYellowMinionBullet->angle) * viYellowMinionBullet->speed;
			viYellowMinionBullet->y += -sinf(viYellowMinionBullet->angle) * viYellowMinionBullet->speed;

			viYellowMinionBullet->rc = RectMakeCenter(viYellowMinionBullet->x,
				viYellowMinionBullet->y, viYellowMinionBullet->bulletImage->getWidth(),
				viYellowMinionBullet->bulletImage->getHeight());

			if (100 >= viYellowMinionBullet->rc.right || WINSIZEY <= viYellowMinionBullet->rc.top ||
				WINSIZEX - 300 <= viYellowMinionBullet->rc.left || 50 > viYellowMinionBullet->rc.bottom)
			{
				yellowMinionBullet = { 0, };
				OBJECTPOOL->setBulletVector(yellowMinionBullet);
				viYellowMinionBullet = vYellowMinionBullet.erase(viYellowMinionBullet);
			}
			else ++viYellowMinionBullet;
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
	case MINION_REDBULLET:		// 레드 미니언 상모돌리기 탄
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
	break;
	case MINION_BLUEBULLET:
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
	break;
	case MINION_GREENBULLET:
	{
		for (viGreenMinionBullet = vGreenMinionBullet.begin(); viGreenMinionBullet != vGreenMinionBullet.end(); ++viGreenMinionBullet)
		{
			if (KEYMANAGER->isToggleKey(VK_TAB))
			{
				Rectangle(getMemDC(), viGreenMinionBullet->rc.left, viGreenMinionBullet->rc.top, viGreenMinionBullet->rc.right, viGreenMinionBullet->rc.bottom);
			}

			viGreenMinionBullet->bulletImage->render(getMemDC(), viGreenMinionBullet->rc.left, viGreenMinionBullet->rc.top);
		}
	}
	break;
	case MINION_YELLOWBULLET:
	{
		for (viYellowMinionBullet = vYellowMinionBullet.begin(); viYellowMinionBullet != vYellowMinionBullet.end(); ++viYellowMinionBullet)
		{
			if (KEYMANAGER->isToggleKey(VK_TAB))
			{
				Rectangle(getMemDC(), viYellowMinionBullet->rc.left, viYellowMinionBullet->rc.top, viYellowMinionBullet->rc.right, viYellowMinionBullet->rc.bottom);
			}

			viYellowMinionBullet->bulletImage->render(getMemDC(), viYellowMinionBullet->rc.left, viYellowMinionBullet->rc.top);
		}
	}
	break;
	default:
		break;
	}
}
