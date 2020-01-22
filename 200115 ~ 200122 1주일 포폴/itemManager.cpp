#include "stdafx.h"
#include "itemManager.h"


itemManager::itemManager()
{
}


itemManager::~itemManager()
{
}

void itemManager::outPutItem()
{
	playerCommonBulletRedMinionCollision();
	playerCommonBulletBlueMinionCollision();
	playerCommonBulletGreenMinionCollision();
	playerCommonBulletYellowMinionCollision();
	playerCommonBulletBossCollision();
	playerHomingBulletRedMinionCollision();
	playerHomingBulletBlueMinionCollision();
	playerHomingBulletGreenMinionCollision();
	playerHomingBulletYellowMinionCollision();
	playerHomingBulletBossCollision();
}

void itemManager::playerCommonBulletRedMinionCollision()
{
	for (int i = 0; i < BULLETMANAGER
		)
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

					// 충돌시 점수
					PLAYER->setScore(PLAYER->getScore() + ENEMYPOINT);

					ENEMYMANAGER->getVRedMinion()[j]->setHp(ENEMYMANAGER->getVRedMinion()[j]->getHp() - 1);
					if (ENEMYMANAGER->getVRedMinion()[j]->getHp() <= 0)
					{
						ENEMYMANAGER->deleteRedEnemy(j);
					}
					break;
				}
			}
		}
	}
}

void itemManager::playerCommonBulletBlueMinionCollision()
{
}

void itemManager::playerCommonBulletGreenMinionCollision()
{
}

void itemManager::playerCommonBulletYellowMinionCollision()
{
}

void itemManager::playerCommonBulletBossCollision()
{
}

void itemManager::playerHomingBulletRedMinionCollision()
{
}

void itemManager::playerHomingBulletBlueMinionCollision()
{
}

void itemManager::playerHomingBulletGreenMinionCollision()
{
}

void itemManager::playerHomingBulletYellowMinionCollision()
{
}

void itemManager::playerHomingBulletBossCollision()
{
}
