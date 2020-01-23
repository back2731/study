#include "stdafx.h"
#include "enemyManager.h"

enemyManager::enemyManager()
{
}


enemyManager::~enemyManager()
{
}

HRESULT enemyManager::init()
{
	count = 0;
	alphaValue1 = 0;
	change = true;
	update();

	return S_OK;
}

void enemyManager::release()
{
	SAFE_DELETE(m_redMinion);
	SAFE_DELETE(m_blueMinion);
	SAFE_DELETE(m_greenMinion);
	SAFE_DELETE(m_yellowMinion);
	SAFE_DELETE(m_Boss);
	count = 0;
}

void enemyManager::update()
{

	count++;
	if (count == 100)
	{
		setRedMinion(0);
		setBlueMinion(0);
		setGreenMinion(0);
	}
	if (count >= 100 && count < 800)
	{
		redMinionUpdate(0);
		blueMinionUpdate(0);
	}
	if (count >= 300 && count < 500)
	{
		greenMinionUpdate(0);
		greenMinionBulletFire(0);
	}
	if (count >= 500 && count < 730)
	{
		greenMinionUpdate(0);
		greenMinionBulletFire(1);
		greenMinionBulletFire(2);
	}
	if (count == 600)
	{
		setYellowMinion(0);
	}
	if (count >= 600 && count <850)
	{
		yellowMinionUpdate(0);
	}
	if (count == 730)
	{
		setGreenMinion(1);
	}
	if (count >= 730 && count < 1200)
	{
		greenMinionUpdate(1);
		greenMinionBulletFire(3);
	}
	if (count == 850)
	{
		setBlueMinion(1);
	}
	if (count >= 850 && count < 1250)
	{
		blueMinionUpdate(1);
	}
	if (count == 1000)
	{
		setRedMinion(1);
	}
	if (count >= 1000 && count < 1350)
	{
		redMinionUpdate(1);
	}
	if (count == 1200)
	{
		setGreenMinion(2);
		setYellowMinion(1);
	}
	if (count >= 1200 && count < 1800)
	{
		greenMinionUpdate(2);
		yellowMinionUpdate(1);
	}

	BULLETMANAGER->enemyBulletCollision();

	if (count == 1)
	{
		setBoss();
	}
	bossUpdate(0);
	if (count < 200)
	{
		m_vBoss[0]->move(FLY);
	}
	if (count >= 200 && count < 250)
	{
		m_vBoss[0]->move(SIT);
	}
	if (count >= 250 && count < 400)
	{
		m_vBoss[0]->move(IDLE);
	}
	if (count >= 400 && count < 580)
	{
		m_vBoss[0]->move(THROWSPEAR);
	}
	if (count >= 490 && count < 580)
	{
		bossBulletFire(2);
	}
	if (count >= 580 && count < 1100)
	{
		m_vBoss[0]->move(IDLE);
	}

	bossPatternRain(600);

	if (count >= 1100 && count < 1150)
	{
		m_vBoss[0]->move(UP);
		m_vBoss[0]->move(WORKLEFT);
	}
	if (count >= 1200 && count < 1250)
	{
		m_vBoss[0]->move(LEFT);
		m_vBoss[0]->move(WORKLEFT);
	}
	if (count >= 1250 && count < 1300)
	{
		m_vBoss[0]->move(IDLE);
		alphaValue1 += 4;
	}
	if (count >= 1300 && count < 1350)
	{
		m_vBoss[0]->move(LEFTDOWN);		
		m_vBoss[0]->move(WORKLEFT);
	}
	if (count >= 1350 && count < 1400)
	{
		m_vBoss[0]->move(IDLE);
		alphaValue2 += 4;
	}
	if (count >= 1400 && count < 1500)
	{
		m_vBoss[0]->move(DOWN);
		m_vBoss[0]->move(IDLE);
	}
	if (count >= 1500 && count < 1550)
	{
		m_vBoss[0]->move(IDLE);
		alphaValue3 += 4;
	}
	if (count >= 1550 && count < 1600)
	{
		m_vBoss[0]->move(RIGHTDOWN);
		m_vBoss[0]->move(WORKRIGHT);
	}
	if (count >= 1600 && count < 1650)
	{
		m_vBoss[0]->move(IDLE);
		alphaValue4 += 4;
	}
	if (count >= 1650 && count < 1750)
	{
		m_vBoss[0]->move(RIGHT);
		m_vBoss[0]->move(WORKRIGHT);
	}
	if (count >= 1750 && count < 1800)
	{
		m_vBoss[0]->move(IDLE);
		alphaValue5 += 4;
	}
	if (count >= 1800 && count < 1850)
	{
		m_vBoss[0]->move(RIGHTUP);
		m_vBoss[0]->move(WORKRIGHT);
	}
	if (count >= 1850 && count < 1900)
	{
		m_vBoss[0]->move(IDLE);
		alphaValue6 += 4;
	}
	if (count >= 1900 && count < 2000)
	{
		m_vBoss[0]->move(UP);
		m_vBoss[0]->move(IDLE);
	}
	if (count >= 2000 && count < 2050)
	{
		m_vBoss[0]->move(IDLE);
		alphaValue7 += 4;
	}
	if (count >= 2050 && count < 2100)
	{
		m_vBoss[0]->move(LEFTUP);
		m_vBoss[0]->move(WORKLEFT);
	}
	if (count >= 2100 && count < 2150)
	{
		m_vBoss[0]->move(IDLE);
		alphaValue8 +=4;
	}
	if (count >= 2150 && count < 2200)
	{
		m_vBoss[0]->move(LEFT);
		m_vBoss[0]->move(WORKLEFT);
	}
	if (count >= 2200 && count < 2250)
	{
		m_vBoss[0]->move(IDLE);
	}
	if (count >= 2250 && count < 2350)
	{
		m_vBoss[0]->move(DOWN);
		m_vBoss[0]->move(IDLE);
	}
	if (count >= 2350 && count < 2400)
	{
		m_vBoss[0]->move(IDLE);
	}
	if (count >= 2550)
	{
		m_vBoss[0]->move(MAGICCASTING);
	}
	if (count >= 1100 && count < 2500)
	{
		bossBulletFire(5);
		bossBulletFire(0);
		bossBulletFire(1);
	}


}

void enemyManager::render()
{
	if (count >= 100 && count < 550)
	{
		redMinionRender(0);
		blueMinionRender(0);
	}	
	if (count >= 300 && count < 850)
	{
		greenMinionRender(0);
	}
	if (count >= 600 && count < 1300)
	{
		yellowMinionRender(0);
	}
	if (count >= 650)
	{
		greenMinionRender(0);
	}
	if (count >= 850 && count < 1250)
	{
		blueMinionRender(1);
	}
	if (count >= 1000 && count < 1350)
	{
		redMinionRender(1);
	}
	if (count >= 1200 && count < 1800)
	{
		greenMinionRender(1);
		yellowMinionRender(1);
	}

	bossRender(0);

	sprintf_s(str, "카운트 :  %d", count);
	TextOut(getMemDC(), 400, 150, str, strlen(str));

	sprintf_s(str, "레드미니언 사이즈 :  %d", m_vRedMinion.size());
	TextOut(getMemDC(), 200, 150, str, strlen(str));

	sprintf_s(str, "옐로미니언 사이즈 :  %d", m_vYellowMinion.size());
	TextOut(getMemDC(), 200, 200, str, strlen(str));

	sprintf_s(str, "그린미니언 사이즈 :  %d", m_vGreenMinion.size());
	TextOut(getMemDC(), 200, 250, str, strlen(str));

	sprintf_s(str, "블루미니언 사이즈 :  %d", m_vBlueMinion.size());
	TextOut(getMemDC(), 200, 300, str, strlen(str));

}

bool enemyManager::mapChange()
{
	if (count == 1500)
	{
		change = false;
	}
	return change;
}

void enemyManager::redMinionUpdate(int pattern)
{
	switch (pattern)
	{
	case 0:		// 레드 미니언 회전 탄
	{
		for (int i = 0; i < m_vRedMinion.size(); i++)
		{
			m_vRedMinion[i]->update();
			m_vRedMinion[i]->move(0);

			if (-500 >= m_vRedMinion[i]->getRect().right || 1200 <= m_vRedMinion[i]->getRect().top ||
				1500 <= m_vRedMinion[i]->getRect().left || -500 > m_vRedMinion[i]->getRect().bottom)
			{
				m_vRedMinion.erase(m_vRedMinion.begin() + i);
			}
		}
		redMinionBulletFire(0);
		BULLETMANAGER->minionHomingBulletMove(0);
	}
		break;
	case 1:
	{
		for (int i = 0; i < m_vRedMinion.size(); i++)
		{
			m_vRedMinion[i]->update();
			m_vRedMinion[i]->move(2);

			if (-500 >= m_vRedMinion[i]->getRect().right || 1200 <= m_vRedMinion[i]->getRect().top ||
				1500 <= m_vRedMinion[i]->getRect().left || -500 > m_vRedMinion[i]->getRect().bottom)
			{
				m_vRedMinion.erase(m_vRedMinion.begin() + i);
			}
		}
		redMinionBulletFire(2);
		BULLETMANAGER->minionCommonBulletMove(0);

	}
	default:
		break;
	}
}

void enemyManager::redMinionRender(int pattern)
{
	switch (pattern)
	{
	case 0:		// 레드 미니언 회전 탄
	{
		BULLETMANAGER->minionHomingBulletRender(0);

		for (m_viRedMinion = m_vRedMinion.begin(); m_viRedMinion != m_vRedMinion.end(); ++m_viRedMinion)
		{
			(*m_viRedMinion)->render();
		}
	}
		break;
	case 1:
	{
		BULLETMANAGER->minionCommonBulletRender(0);
		for (m_viRedMinion = m_vRedMinion.begin(); m_viRedMinion != m_vRedMinion.end(); ++m_viRedMinion)
		{
			(*m_viRedMinion)->render();
		}
	}
		break;
	default:
		break;
	}
}

void enemyManager::setRedMinion(int pattern)
{
	switch (pattern)
	{
		case 0:		// 1열 종대 6기 1 * 12
		{
			for (int i = 0; i < 4; i++)
			{
				m_redMinion = new redMinion;
				m_redMinion->init("redMinion", PointMake(200, -400 - (i * 50)));
				m_vRedMinion.push_back(m_redMinion);
			}
			for (int i = 4; i < 8; i++)
			{
				m_redMinion = new redMinion;
				m_redMinion->init("redMinion", PointMake(300, -400 - ((i - 4) * 50)));
				m_vRedMinion.push_back(m_redMinion);
			}
		}
			break;	
		case 1:
			for (int i = 0; i < 2; i++)
			{
				m_redMinion = new redMinion;
				m_redMinion->init("redEnemy", PointMake(175 + (i * 250), -150));
				m_vRedMinion.push_back(m_redMinion);
			}			
			for (int i = 2; i < 5; i++)
			{
				m_redMinion = new redMinion;
				m_redMinion->init("redEnemy", PointMake(50 + ((i - 2) * 250), -50));
				m_vRedMinion.push_back(m_redMinion);
			}
		default:
			break;
	}	
}

void enemyManager::redMinionBulletFire(int pattern)
{
	switch (pattern)
	{
	case 0:		// 레드 미니언 회전 탄
	{
		for (m_viRedMinion = m_vRedMinion.begin(); m_viRedMinion != m_vRedMinion.end(); ++m_viRedMinion)
		{
			BULLETMANAGER->minionHomingBulletFire(0, "minionHomingRedBullet" ,(*m_viRedMinion)->getRedMinionX(), (*m_viRedMinion)->getRedMinionY(),
				PLAYER->getPlayerRectX(), PLAYER->getPlayerRectY(), 4.0f, 80);
		}
	}
		break;
	case 1:
	{
		for (m_viRedMinion = m_vRedMinion.begin(); m_viRedMinion != m_vRedMinion.end(); ++m_viRedMinion)
		{
			BULLETMANAGER->minionCommonBulletFire(0, "redMinionBullet", (*m_viRedMinion)->getRedMinionX(), (*m_viRedMinion)->getRedMinionY(), ANGLE_210, 5.0f, 80);
			BULLETMANAGER->minionCommonBulletFire(0, "redMinionBullet", (*m_viRedMinion)->getRedMinionX(), (*m_viRedMinion)->getRedMinionY(), ANGLE_225, 5.0f, 80);
			BULLETMANAGER->minionCommonBulletFire(0, "redMinionBullet", (*m_viRedMinion)->getRedMinionX(), (*m_viRedMinion)->getRedMinionY(), ANGLE_240, 5.0f, 80);
			BULLETMANAGER->minionCommonBulletFire(0, "redMinionBullet", (*m_viRedMinion)->getRedMinionX(), (*m_viRedMinion)->getRedMinionY(), ANGLE_255, 5.0f, 80);
			BULLETMANAGER->minionCommonBulletFire(0, "redMinionBullet", (*m_viRedMinion)->getRedMinionX(), (*m_viRedMinion)->getRedMinionY(), ANGLE_270, 5.0f, 80);
			BULLETMANAGER->minionCommonBulletFire(0, "redMinionBullet", (*m_viRedMinion)->getRedMinionX(), (*m_viRedMinion)->getRedMinionY(), ANGLE_285, 5.0f, 80);
			BULLETMANAGER->minionCommonBulletFire(0, "redMinionBullet", (*m_viRedMinion)->getRedMinionX(), (*m_viRedMinion)->getRedMinionY(), ANGLE_300, 5.0f, 80);
			BULLETMANAGER->minionCommonBulletFire(0, "redMinionBullet", (*m_viRedMinion)->getRedMinionX(), (*m_viRedMinion)->getRedMinionY(), ANGLE_315, 5.0f, 80);
			BULLETMANAGER->minionCommonBulletFire(0, "redMinionBullet", (*m_viRedMinion)->getRedMinionX(), (*m_viRedMinion)->getRedMinionY(), ANGLE_330, 5.0f, 80);
		}
	}
	break;
	case 2:
	{
		for (m_viRedMinion = m_vRedMinion.begin(); m_viRedMinion != m_vRedMinion.end(); ++m_viRedMinion)
		{
			BULLETMANAGER->minionCommonBulletFire(0, "redDoubleCircleBullet", (*m_viRedMinion)->getRedMinionX(), (*m_viRedMinion)->getRedMinionY(), ANGLE_0, 5.0f, 20);
			BULLETMANAGER->minionCommonBulletFire(0, "redDoubleCircleBullet", (*m_viRedMinion)->getRedMinionX(), (*m_viRedMinion)->getRedMinionY(), ANGLE_30, 5.0f, 20);
			BULLETMANAGER->minionCommonBulletFire(0, "redDoubleCircleBullet", (*m_viRedMinion)->getRedMinionX(), (*m_viRedMinion)->getRedMinionY(), ANGLE_60, 5.0f, 20);
			BULLETMANAGER->minionCommonBulletFire(0, "redDoubleCircleBullet", (*m_viRedMinion)->getRedMinionX(), (*m_viRedMinion)->getRedMinionY(), ANGLE_90, 5.0f, 20);
			BULLETMANAGER->minionCommonBulletFire(0, "redDoubleCircleBullet", (*m_viRedMinion)->getRedMinionX(), (*m_viRedMinion)->getRedMinionY(), ANGLE_120, 5.0f, 20);
			BULLETMANAGER->minionCommonBulletFire(0, "redDoubleCircleBullet", (*m_viRedMinion)->getRedMinionX(), (*m_viRedMinion)->getRedMinionY(), ANGLE_150, 5.0f, 20);
			BULLETMANAGER->minionCommonBulletFire(0, "redDoubleCircleBullet", (*m_viRedMinion)->getRedMinionX(), (*m_viRedMinion)->getRedMinionY(), ANGLE_180, 5.0f, 20);
			BULLETMANAGER->minionCommonBulletFire(0, "redDoubleCircleBullet", (*m_viRedMinion)->getRedMinionX(), (*m_viRedMinion)->getRedMinionY(), ANGLE_210, 5.0f, 20);
			BULLETMANAGER->minionCommonBulletFire(0, "redDoubleCircleBullet", (*m_viRedMinion)->getRedMinionX(), (*m_viRedMinion)->getRedMinionY(), ANGLE_240, 5.0f, 20);
			BULLETMANAGER->minionCommonBulletFire(0, "redDoubleCircleBullet", (*m_viRedMinion)->getRedMinionX(), (*m_viRedMinion)->getRedMinionY(), ANGLE_270, 5.0f, 20);
			BULLETMANAGER->minionCommonBulletFire(0, "redDoubleCircleBullet", (*m_viRedMinion)->getRedMinionX(), (*m_viRedMinion)->getRedMinionY(), ANGLE_300, 5.0f, 20);
			BULLETMANAGER->minionCommonBulletFire(0, "redDoubleCircleBullet", (*m_viRedMinion)->getRedMinionX(), (*m_viRedMinion)->getRedMinionY(), ANGLE_330, 5.0f, 20);
		}
	}
	default:
		break;
	}	
}

void enemyManager::deleteRedEnemy(int num)
{
	m_vRedMinion.erase(m_vRedMinion.begin() + num);
}

void enemyManager::blueMinionUpdate(int pattern)
{
	switch (pattern)
	{
	case 0:		// 블루 미니언 회전 탄
	{
		for (int i = 0; i < m_vBlueMinion.size(); i++)
		{
			m_vBlueMinion[i]->update();
			m_vBlueMinion[i]->move(1);

			if (-500 >= m_vBlueMinion[i]->getRect().right || 1200 <= m_vBlueMinion[i]->getRect().top ||
				1500 <= m_vBlueMinion[i]->getRect().left || -500 > m_vBlueMinion[i]->getRect().bottom)
			{
				m_vBlueMinion.erase(m_vBlueMinion.begin() + i);
			}
		}
		
		blueMinionBulletFire(0);
		BULLETMANAGER->minionHomingBulletMove(1);
	}
		break;
	case 1:
	{
		for (int i = 0; i < m_vBlueMinion.size(); i++)
		{
			m_vBlueMinion[i]->update();
			m_vBlueMinion[i]->move(2);

			if (-500 >= m_vBlueMinion[i]->getRect().right || 1200 <= m_vBlueMinion[i]->getRect().top ||
				1500 <= m_vBlueMinion[i]->getRect().left || -500 > m_vBlueMinion[i]->getRect().bottom)
			{
				m_vBlueMinion.erase(m_vBlueMinion.begin() + i);
			}
		}
		blueMinionBulletFire(1);
		BULLETMANAGER->minionCommonBulletMove(1);
	}
	break;	default:
		break;
	}
}

void enemyManager::blueMinionRender(int pattern)
{
	switch (pattern)
	{
		case 0:		// 블루 미니언 회전 탄
		{
			BULLETMANAGER->minionHomingBulletRender(1);
			for (m_viBlueMinion = m_vBlueMinion.begin(); m_viBlueMinion != m_vBlueMinion.end(); ++m_viBlueMinion)
			{
				(*m_viBlueMinion)->render();
			}
		}
			break;
		case 1:
		{
			BULLETMANAGER->minionCommonBulletRender(1);
			//BULLETMANAGER->minionSpinBulletRender(1);
			for (m_viBlueMinion = m_vBlueMinion.begin(); m_viBlueMinion != m_vBlueMinion.end(); ++m_viBlueMinion)
			{
				(*m_viBlueMinion)->render();
			}
		}
			break;
	default:
		break;
	}
}

void enemyManager::setBlueMinion(int pattern)
{
	switch (pattern)
	{
	case 0:		// 블루 미니언 회전 탄
	{
		for (int i = 0; i < 4; i++)
		{
			m_blueMinion = new blueMinion;
			m_blueMinion->init("blueMinion", PointMake(600, -400 - (i * 50)));
			m_vBlueMinion.push_back(m_blueMinion);
		}
		for (int i = 4; i < 8; i++)
		{
			m_blueMinion = new blueMinion;
			m_blueMinion->init("blueMinion", PointMake(500, -400 - ((i - 4) * 50)));
			m_vBlueMinion.push_back(m_blueMinion);
		}
	}
		break;
	case 1:
	{
		for (int i = 0; i < 2; i++)
		{
			m_blueMinion = new blueMinion;
			m_blueMinion->init("blueEnemy", PointMake(475 + (i * 250), -150));
			m_vBlueMinion.push_back(m_blueMinion);
		}
		for (int i = 2; i < 5; i++)
		{
			m_blueMinion = new blueMinion;
			m_blueMinion->init("blueEnemy", PointMake(350 + ((i - 2) * 250), -50));
			m_vBlueMinion.push_back(m_blueMinion);
		}
	}
	default:
		break;
	}
}

void enemyManager::blueMinionBulletFire(int pattern)
{
	switch (pattern)
	{
	case 0:		
	{
		for (m_viBlueMinion = m_vBlueMinion.begin(); m_viBlueMinion != m_vBlueMinion.end(); ++m_viBlueMinion)
		{
			BULLETMANAGER->minionHomingBulletFire(1, "minionHomingBlueBullet", (*m_viBlueMinion)->getBlueMinionX(), (*m_viBlueMinion)->getBlueMinionY(), 
				PLAYER->getPlayerRectX(), PLAYER->getPlayerRectY(), 4.0f, 80);
		}
	}
		break;
	case 1:		
	{
		for (m_viBlueMinion = m_vBlueMinion.begin(); m_viBlueMinion != m_vBlueMinion.end(); ++m_viBlueMinion)
		{
			BULLETMANAGER->minionCommonBulletFire(1, "blueDoubleCircleBullet", (*m_viBlueMinion)->getBlueMinionX(), (*m_viBlueMinion)->getBlueMinionY(), ANGLE_0, 5.0f, 20);
			BULLETMANAGER->minionCommonBulletFire(1, "blueDoubleCircleBullet", (*m_viBlueMinion)->getBlueMinionX(), (*m_viBlueMinion)->getBlueMinionY(), ANGLE_30, 5.0f, 20);
			BULLETMANAGER->minionCommonBulletFire(1, "blueDoubleCircleBullet", (*m_viBlueMinion)->getBlueMinionX(), (*m_viBlueMinion)->getBlueMinionY(), ANGLE_60, 5.0f, 20);
			BULLETMANAGER->minionCommonBulletFire(1, "blueDoubleCircleBullet", (*m_viBlueMinion)->getBlueMinionX(), (*m_viBlueMinion)->getBlueMinionY(), ANGLE_90, 5.0f, 20);
			BULLETMANAGER->minionCommonBulletFire(1, "blueDoubleCircleBullet", (*m_viBlueMinion)->getBlueMinionX(), (*m_viBlueMinion)->getBlueMinionY(), ANGLE_120, 5.0f, 20);
			BULLETMANAGER->minionCommonBulletFire(1, "blueDoubleCircleBullet", (*m_viBlueMinion)->getBlueMinionX(), (*m_viBlueMinion)->getBlueMinionY(), ANGLE_150, 5.0f, 20);
			BULLETMANAGER->minionCommonBulletFire(1, "blueDoubleCircleBullet", (*m_viBlueMinion)->getBlueMinionX(), (*m_viBlueMinion)->getBlueMinionY(), ANGLE_180, 5.0f, 20);
			BULLETMANAGER->minionCommonBulletFire(1, "blueDoubleCircleBullet", (*m_viBlueMinion)->getBlueMinionX(), (*m_viBlueMinion)->getBlueMinionY(), ANGLE_210, 5.0f, 20);
			BULLETMANAGER->minionCommonBulletFire(1, "blueDoubleCircleBullet", (*m_viBlueMinion)->getBlueMinionX(), (*m_viBlueMinion)->getBlueMinionY(), ANGLE_240, 5.0f, 20);
			BULLETMANAGER->minionCommonBulletFire(1, "blueDoubleCircleBullet", (*m_viBlueMinion)->getBlueMinionX(), (*m_viBlueMinion)->getBlueMinionY(), ANGLE_270, 5.0f, 20);
			BULLETMANAGER->minionCommonBulletFire(1, "blueDoubleCircleBullet", (*m_viBlueMinion)->getBlueMinionX(), (*m_viBlueMinion)->getBlueMinionY(), ANGLE_300, 5.0f, 20);
			BULLETMANAGER->minionCommonBulletFire(1, "blueDoubleCircleBullet", (*m_viBlueMinion)->getBlueMinionX(), (*m_viBlueMinion)->getBlueMinionY(), ANGLE_330, 5.0f, 20);
		}
	}
		break;
	default:
		break;
	}
}

void enemyManager::deleteBlueEnemy(int num)
{
	m_vBlueMinion.erase(m_vBlueMinion.begin() + num);
}

void enemyManager::greenMinionUpdate(int pattern)
{
	switch (pattern)
	{
	case 0:	
	{
		for (int i = 0; i < m_vGreenMinion.size(); i++)
		{
			m_vGreenMinion[i]->update();
			m_vGreenMinion[i]->move(0);

			if (-500 >= m_vGreenMinion[i]->getRect().right || 1200 <= m_vGreenMinion[i]->getRect().top ||
				1500 <= m_vGreenMinion[i]->getRect().left || -500 > m_vGreenMinion[i]->getRect().bottom)
			{
				m_vGreenMinion.erase(m_vGreenMinion.begin() + i);
			}
		}	

		BULLETMANAGER->minionCommonBulletMove(2);
		BULLETMANAGER->minionSpinBulletMove(2);
		BULLETMANAGER->minionSpinBulletMove(3);
	}
	break;
	case 1:
	{
		for (int i = 0; i < m_vGreenMinion.size(); i++)
		{
			m_vGreenMinion[i]->update();
			m_vGreenMinion[i]->move(1);

			if (-500 >= m_vGreenMinion[i]->getRect().right || 1200 <= m_vGreenMinion[i]->getRect().top ||
				1500 <= m_vGreenMinion[i]->getRect().left || -500 > m_vGreenMinion[i]->getRect().bottom)
			{
				m_vGreenMinion.erase(m_vGreenMinion.begin() + i);
			}
		}
		BULLETMANAGER->minionCommonBulletMove(2);
	}
	break;
	case 2:
	{
		for (int i = 0; i < m_vGreenMinion.size(); i++)
		{
			m_vGreenMinion[i]->update();
			m_vGreenMinion[i]->move(2);

			if (-500 >= m_vGreenMinion[i]->getRect().right || 1200 <= m_vGreenMinion[i]->getRect().top ||
				1500 <= m_vGreenMinion[i]->getRect().left || -500 > m_vGreenMinion[i]->getRect().bottom)
			{
				m_vGreenMinion.erase(m_vGreenMinion.begin() + i);
			}
		}
		greenMinionBulletFire(4);
		BULLETMANAGER->minionSpinBulletMove(2);
	}
	break;
	default:
		break;
	}
}

void enemyManager::greenMinionRender(int pattern)
{
	switch (pattern)
	{
	case 0:		// 그린 미니언 회전 탄
	{
		BULLETMANAGER->minionCommonBulletRender(2);
		BULLETMANAGER->minionSpinBulletRender(2);
		BULLETMANAGER->minionSpinBulletRender(3);
		for (m_viGreenMinion = m_vGreenMinion.begin(); m_viGreenMinion != m_vGreenMinion.end(); ++m_viGreenMinion)
		{
			(*m_viGreenMinion)->render();
		}
	}
	break;
	case 1:
	{				
		BULLETMANAGER->minionCommonBulletRender(2);
		for (m_viGreenMinion = m_vGreenMinion.begin(); m_viGreenMinion != m_vGreenMinion.end(); ++m_viGreenMinion)
		{
			(*m_viGreenMinion)->render();
		}
	}
	break;
	case 2:
	{
		BULLETMANAGER->minionSpinBulletRender(2);
		for (m_viGreenMinion = m_vGreenMinion.begin(); m_viGreenMinion != m_vGreenMinion.end(); ++m_viGreenMinion)
		{
			(*m_viGreenMinion)->render();
		}

	}
	break;
	default:
		break;
	}
}

void enemyManager::setGreenMinion(int pattern)
{
	switch (pattern)
	{
	case 0:		// 그린 미니언 회전 탄
	{
		for (int i = 0; i < 3; i++)
		{
			m_greenMinion = new greenMinion;
			m_greenMinion->init("greenEnemy", PointMake(200 + (i * 200), -150));
			m_vGreenMinion.push_back(m_greenMinion);
		}
		for (int i = 3; i < 6; i++)
		{
			m_greenMinion = new greenMinion;
			m_greenMinion->init("greenEnemy", PointMake(200 + ((i - 3) * 200), -250));
			m_vGreenMinion.push_back(m_greenMinion);
		}
	}
	break;
	case 1:
	{
		for (int i = 0; i < 8; i++)
		{
			m_greenMinion = new greenMinion;
			m_greenMinion->init("greenMinion", PointMake(0, 450 - i * 50));
			m_vGreenMinion.push_back(m_greenMinion);
		}
	}
	break;
	case 2:
	{
		for (int i = 0; i < 5; i++)
		{
			m_greenMinion = new greenMinion;
			m_greenMinion->init("greenMinion", PointMake(-500 + i * 100, 600));
			m_vGreenMinion.push_back(m_greenMinion);
		}
		for (int i = 5; i < 10; i++)
		{
			m_greenMinion = new greenMinion;
			m_greenMinion->init("greenMinion", PointMake(-500 + (i - 5) * 100, 700));
			m_vGreenMinion.push_back(m_greenMinion);
		}
	}
	default:
		break;
	}

}

void enemyManager::greenMinionBulletFire(int pattern)
{
	switch (pattern)
	{
	case 0:		
	{
		for (m_viGreenMinion = m_vGreenMinion.begin(); m_viGreenMinion != m_vGreenMinion.end(); ++m_viGreenMinion)
		{
			BULLETMANAGER->minionCommonBulletFire(2, "greenBullet", (*m_viGreenMinion)->getGreenMinionX(), (*m_viGreenMinion)->getGreenMinionY(), ANGLE_240, 5.0f, 50);
			BULLETMANAGER->minionCommonBulletFire(2, "greenBullet", (*m_viGreenMinion)->getGreenMinionX(), (*m_viGreenMinion)->getGreenMinionY(), ANGLE_270, 5.0f, 50);
			BULLETMANAGER->minionCommonBulletFire(2, "greenBullet", (*m_viGreenMinion)->getGreenMinionX(), (*m_viGreenMinion)->getGreenMinionY(), ANGLE_300, 5.0f, 50);
		}
	}
	break;
	case 1:
	{
		for (m_viGreenMinion = m_vGreenMinion.begin(); m_viGreenMinion != m_vGreenMinion.end(); ++m_viGreenMinion)
		{
			BULLETMANAGER->minionSpinBulletFire(2,"greenMinionBullet", (*m_viGreenMinion)->getGreenMinionX(), (*m_viGreenMinion)->getGreenMinionY(), 5);
		}
	}
	break;
	case 2:
	{
		for (m_viGreenMinion = m_vGreenMinion.begin(); m_viGreenMinion != m_vGreenMinion.end(); ++m_viGreenMinion)
		{
			BULLETMANAGER->minionSpinBulletFire(3, "greenMinionBullet", (*m_viGreenMinion)->getGreenMinionX(), (*m_viGreenMinion)->getGreenMinionY(), 5);
		}
	}
	break;
	case 3:
	{
		for (m_viGreenMinion = m_vGreenMinion.begin(); m_viGreenMinion != m_vGreenMinion.end(); ++m_viGreenMinion)
		{
			BULLETMANAGER->minionCommonBulletFire(2, "greenStarBullet", (*m_viGreenMinion)->getGreenMinionX(), (*m_viGreenMinion)->getGreenMinionY(), ANGLE_210, 6.0f, 70);
			BULLETMANAGER->minionCommonBulletFire(2, "greenStarBullet", (*m_viGreenMinion)->getGreenMinionX(), (*m_viGreenMinion)->getGreenMinionY(), ANGLE_225, 6.0f, 70);
			BULLETMANAGER->minionCommonBulletFire(2, "greenStarBullet", (*m_viGreenMinion)->getGreenMinionX(), (*m_viGreenMinion)->getGreenMinionY(), ANGLE_240, 6.0f, 70);
			BULLETMANAGER->minionCommonBulletFire(2, "greenStarBullet", (*m_viGreenMinion)->getGreenMinionX(), (*m_viGreenMinion)->getGreenMinionY(), ANGLE_255, 6.0f, 70);
			BULLETMANAGER->minionCommonBulletFire(2, "greenStarBullet", (*m_viGreenMinion)->getGreenMinionX(), (*m_viGreenMinion)->getGreenMinionY(), ANGLE_270, 6.0f, 70);
			BULLETMANAGER->minionCommonBulletFire(2, "greenStarBullet", (*m_viGreenMinion)->getGreenMinionX(), (*m_viGreenMinion)->getGreenMinionY(), ANGLE_285, 6.0f, 70);
			BULLETMANAGER->minionCommonBulletFire(2, "greenStarBullet", (*m_viGreenMinion)->getGreenMinionX(), (*m_viGreenMinion)->getGreenMinionY(), ANGLE_300, 6.0f, 70);
			BULLETMANAGER->minionCommonBulletFire(2, "greenStarBullet", (*m_viGreenMinion)->getGreenMinionX(), (*m_viGreenMinion)->getGreenMinionY(), ANGLE_315, 6.0f, 70);
			BULLETMANAGER->minionCommonBulletFire(2, "greenStarBullet", (*m_viGreenMinion)->getGreenMinionX(), (*m_viGreenMinion)->getGreenMinionY(), ANGLE_330, 6.0f, 70);
		}
	}
	break;
	case 4:
	{
		for (m_viGreenMinion = m_vGreenMinion.begin(); m_viGreenMinion != m_vGreenMinion.end(); ++m_viGreenMinion)
		{
			BULLETMANAGER->minionSpinBulletFire(2, "greenSmallBullet", (*m_viGreenMinion)->getGreenMinionX(), (*m_viGreenMinion)->getGreenMinionY(), 2);
		}
	}
	break;
	default:
		break;
	}
}

void enemyManager::deleteGreenEnemy(int num)
{
	m_vGreenMinion.erase(m_vGreenMinion.begin() + num);
}

void enemyManager::yellowMinionUpdate(int pattern)
{
	switch (pattern)
	{
	case 0:		// 옐로우 미니언 회전 탄
	{		
		for (int i = 0; i < m_vYellowMinion.size(); i++)
		{
			m_vYellowMinion[i]->update();
			m_vYellowMinion[i]->move(0);

			if (-500 >= m_vYellowMinion[i]->getRect().right || 1200 <= m_vYellowMinion[i]->getRect().top ||
				1500 <= m_vYellowMinion[i]->getRect().left || -500 > m_vYellowMinion[i]->getRect().bottom)
			{
				m_vYellowMinion.erase(m_vYellowMinion.begin() + i);
			}
		}
		yellowMinionBulletFire(0);
		BULLETMANAGER->minionCommonBulletMove(3);
	}
	break;
	case 1:
	{
		for (int i = 0; i < m_vYellowMinion.size(); i++)
		{
			m_vYellowMinion[i]->update();
			m_vYellowMinion[i]->move(1);

			if (-500 >= m_vYellowMinion[i]->getRect().right || 1200 <= m_vYellowMinion[i]->getRect().top ||
				1500 <= m_vYellowMinion[i]->getRect().left || -500 > m_vYellowMinion[i]->getRect().bottom)
			{
				m_vYellowMinion.erase(m_vYellowMinion.begin() + i);
			}
		}
		yellowMinionBulletFire(1);
		BULLETMANAGER->minionSpinBulletMove(3);
	}
	default:
		break;
	}
}

void enemyManager::yellowMinionRender(int pattern)
{
	switch (pattern)
	{
	case 0:		// 옐로우 미니언 회전 탄
	{
		BULLETMANAGER->minionCommonBulletRender(3);
		for (m_viYellowMinion = m_vYellowMinion.begin(); m_viYellowMinion != m_vYellowMinion.end(); ++m_viYellowMinion)
		{
			(*m_viYellowMinion)->render();
		}
	}
	break;
	case 1:
	{
		BULLETMANAGER->minionSpinBulletRender(3);
		for (m_viYellowMinion = m_vYellowMinion.begin(); m_viYellowMinion != m_vYellowMinion.end(); ++m_viYellowMinion)
		{
			(*m_viYellowMinion)->render();
		}
	}
	default:
		break;
	}
}

void enemyManager::setYellowMinion(int pattern)
{
	switch (pattern)
	{
	case 0:		
	{
		for (int i = 0; i < 8; i++)
		{
			m_yellowMinion = new yellowMinion;
			m_yellowMinion->init("yellowMinion", PointMake(800, 450-i*50));
			m_vYellowMinion.push_back(m_yellowMinion);
		}
	}
	break;
	case 1:
	{
		for (int i = 0; i < 5; i++)
		{
			m_yellowMinion = new yellowMinion;
			m_yellowMinion->init("yellowMinion", PointMake(950 + (i * 100), 600));
			m_vYellowMinion.push_back(m_yellowMinion);
		}
		for (int i = 5; i < 10; i++)
		{
			m_yellowMinion = new yellowMinion;
			m_yellowMinion->init("yellowMinion", PointMake(950 + ((i-5) * 100), 700));
			m_vYellowMinion.push_back(m_yellowMinion);
		}
	}
	break;
	default:
		break;
	}
}

void enemyManager::yellowMinionBulletFire(int pattern)
{
	switch (pattern)
	{
	case 0:		// 옐로우 미니언 회전 탄
	{
		for (m_viYellowMinion = m_vYellowMinion.begin(); m_viYellowMinion != m_vYellowMinion.end(); ++m_viYellowMinion)
		{
			BULLETMANAGER->minionCommonBulletFire(3, "yellowStarBullet", (*m_viYellowMinion)->getYellowMinionX(), (*m_viYellowMinion)->getYellowMinionY(), ANGLE_210, 6.0f, 70);
			BULLETMANAGER->minionCommonBulletFire(3, "yellowStarBullet", (*m_viYellowMinion)->getYellowMinionX(), (*m_viYellowMinion)->getYellowMinionY(), ANGLE_225, 6.0f, 70);
			BULLETMANAGER->minionCommonBulletFire(3, "yellowStarBullet", (*m_viYellowMinion)->getYellowMinionX(), (*m_viYellowMinion)->getYellowMinionY(), ANGLE_240, 6.0f, 70);
			BULLETMANAGER->minionCommonBulletFire(3, "yellowStarBullet", (*m_viYellowMinion)->getYellowMinionX(), (*m_viYellowMinion)->getYellowMinionY(), ANGLE_255, 6.0f, 70);
			BULLETMANAGER->minionCommonBulletFire(3, "yellowStarBullet", (*m_viYellowMinion)->getYellowMinionX(), (*m_viYellowMinion)->getYellowMinionY(), ANGLE_270, 6.0f, 70);
			BULLETMANAGER->minionCommonBulletFire(3, "yellowStarBullet", (*m_viYellowMinion)->getYellowMinionX(), (*m_viYellowMinion)->getYellowMinionY(), ANGLE_285, 6.0f, 70);
			BULLETMANAGER->minionCommonBulletFire(3, "yellowStarBullet", (*m_viYellowMinion)->getYellowMinionX(), (*m_viYellowMinion)->getYellowMinionY(), ANGLE_300, 6.0f, 70);
			BULLETMANAGER->minionCommonBulletFire(3, "yellowStarBullet", (*m_viYellowMinion)->getYellowMinionX(), (*m_viYellowMinion)->getYellowMinionY(), ANGLE_315, 6.0f, 70);
			BULLETMANAGER->minionCommonBulletFire(3, "yellowStarBullet", (*m_viYellowMinion)->getYellowMinionX(), (*m_viYellowMinion)->getYellowMinionY(), ANGLE_330, 6.0f, 70);
		}
	}
	break;
	case 1:
	{
		for (m_viYellowMinion = m_vYellowMinion.begin(); m_viYellowMinion != m_vYellowMinion.end(); ++m_viYellowMinion)
		{
			BULLETMANAGER->minionSpinBulletFire(3, "yellowSmallBullet", (*m_viYellowMinion)->getYellowMinionX(), (*m_viYellowMinion)->getYellowMinionY(), 2);
		}
	}
	default:
		break;
	}
}

void enemyManager::deleteYellowEnemy(int num)
{
	m_vYellowMinion.erase(m_vYellowMinion.begin() + num);
}

void enemyManager::bossUpdate(int pattern)
{
	switch (pattern)
	{
	case 0:
		{
			m_vBoss[0]->update();
			BULLETMANAGER->bossHorizontalBulletMove();
			BULLETMANAGER->bossVerticalBulletMove();
			BULLETMANAGER->bossRightSpinBulletMove();
			BULLETMANAGER->bossLeftSpinBulletMove();
			BULLETMANAGER->bossCommonBulletMove();
		}
		break;
	default:
		break;
	}
}

void enemyManager::bossRender(int pattern)
{	
	
	if (KEYMANAGER->isToggleKey(VK_TAB))
	{
		Rectangle(getMemDC(), bossCannon1.left, bossCannon1.top, bossCannon1.right, bossCannon1.bottom);
		Rectangle(getMemDC(), bossCannon2.left, bossCannon2.top, bossCannon2.right, bossCannon2.bottom);
		Rectangle(getMemDC(), bossCannon3.left, bossCannon3.top, bossCannon3.right, bossCannon3.bottom);
		Rectangle(getMemDC(), bossCannon4.left, bossCannon4.top, bossCannon4.right, bossCannon4.bottom);
		Rectangle(getMemDC(), bossCannon5.left, bossCannon5.top, bossCannon5.right, bossCannon5.bottom);
		Rectangle(getMemDC(), bossCannon6.left, bossCannon6.top, bossCannon6.right, bossCannon6.bottom);
		Rectangle(getMemDC(), bossCannon7.left, bossCannon7.top, bossCannon7.right, bossCannon7.bottom);
		Rectangle(getMemDC(), bossCannon8.left, bossCannon8.top, bossCannon8.right, bossCannon8.bottom);
	}

	bossCannonImage->alphaRender(getMemDC(), bossCannon1.left, bossCannon1.top, alphaValue1);
	bossCannonImage->alphaRender(getMemDC(), bossCannon2.left, bossCannon2.top, alphaValue2);
	bossCannonImage->alphaRender(getMemDC(), bossCannon3.left, bossCannon3.top, alphaValue3);
	bossCannonImage->alphaRender(getMemDC(), bossCannon4.left, bossCannon4.top, alphaValue4);
	bossCannonImage->alphaRender(getMemDC(), bossCannon5.left, bossCannon5.top, alphaValue5);
	bossCannonImage->alphaRender(getMemDC(), bossCannon6.left, bossCannon6.top, alphaValue6);
	bossCannonImage->alphaRender(getMemDC(), bossCannon7.left, bossCannon7.top, alphaValue7);
	bossCannonImage->alphaRender(getMemDC(), bossCannon8.left, bossCannon8.top, alphaValue8);


	BULLETMANAGER->bossVerticalBulletRender();
	BULLETMANAGER->bossHorizontalBulletRender();
	BULLETMANAGER->bossRightSpinBulletRender();
	BULLETMANAGER->bossLeftSpinBulletRender();
	BULLETMANAGER->bossCommonBulletRender();

	for (int i = 0; i < m_vBoss.size(); i++)
	{
		m_vBoss[i]->render();
	}

}

void enemyManager::setBoss()
{
	m_Boss = new boss;
	m_Boss->init("remilia", PointMake(150 , -200));
	m_vBoss.push_back(m_Boss);

	bossCannonImage = IMAGEMANAGER->findImage("bulletCanon");
	bossCannon1 = RectMakeCenter(325, 175, bossCannonImage->getWidth(), bossCannonImage->getHeight());

	bossCannonImage = IMAGEMANAGER->findImage("bulletCanon");
	bossCannon2 = RectMakeCenter(225, 275, bossCannonImage->getWidth(), bossCannonImage->getHeight());

	bossCannonImage = IMAGEMANAGER->findImage("bulletCanon");
	bossCannon3 = RectMakeCenter(225, 475, bossCannonImage->getWidth(), bossCannonImage->getHeight());
	
	bossCannonImage = IMAGEMANAGER->findImage("bulletCanon");
	bossCannon4 = RectMakeCenter(325, 575, bossCannonImage->getWidth(), bossCannonImage->getHeight());

	bossCannonImage = IMAGEMANAGER->findImage("bulletCanon");
	bossCannon5 = RectMakeCenter(525, 575, bossCannonImage->getWidth(), bossCannonImage->getHeight());

	bossCannonImage = IMAGEMANAGER->findImage("bulletCanon");
	bossCannon6 = RectMakeCenter(625, 475, bossCannonImage->getWidth(), bossCannonImage->getHeight());

	bossCannonImage = IMAGEMANAGER->findImage("bulletCanon");
	bossCannon7 = RectMakeCenter(625, 275, bossCannonImage->getWidth(), bossCannonImage->getHeight());

	bossCannonImage = IMAGEMANAGER->findImage("bulletCanon");
	bossCannon8 = RectMakeCenter(525, 175, bossCannonImage->getWidth(), bossCannonImage->getHeight());

}

void enemyManager::bossBulletFire(int pattern)
{
	switch (pattern)
	{
	case 0:		// 보스 버티컬 샷
	{	
		for (m_viBoss = m_vBoss.begin(); m_viBoss != m_vBoss.end(); ++m_viBoss)
		{
			BULLETMANAGER->bossVerticalBulletFire("redVerticalBullet", 275, WINSIZEY + 100, ANGLE_90, 6, 50);
			BULLETMANAGER->bossVerticalBulletFire("redVerticalBullet", 525, WINSIZEY + 50, ANGLE_90, 6, 60);

			BULLETMANAGER->bossVerticalBulletFire("redVerticalBullet", 150, -50, ANGLE_270, 6, 30);
			BULLETMANAGER->bossVerticalBulletFire("redVerticalBullet", 400, -100, ANGLE_270, 6, 60);
			BULLETMANAGER->bossVerticalBulletFire("redVerticalBullet", 650, -150, ANGLE_270, 6, 50);
		}
	}
		break;
	case 1:		// 보스 호리젠탈 샷
	{
		for (m_viBoss = m_vBoss.begin(); m_viBoss != m_vBoss.end(); ++m_viBoss)
		{
			BULLETMANAGER->bossHorizontalBulletFire("redHorizontalBullet", -50, 100, ANGLE_0, 6, 50);
			BULLETMANAGER->bossHorizontalBulletFire("redHorizontalBullet", -100, 400, ANGLE_0, 6, 30);
			BULLETMANAGER->bossHorizontalBulletFire("redHorizontalBullet", -150, 700, ANGLE_0, 6, 60);

			BULLETMANAGER->bossHorizontalBulletFire("redHorizontalBullet", 800, 250, ANGLE_180, 6, 40);
			BULLETMANAGER->bossHorizontalBulletFire("redHorizontalBullet", 850, 550, ANGLE_180, 6, 30);
		}
	}
		break;
	case 2:
	{
		BULLETMANAGER->bossHorizontalBulletFire("redHorizontalBullet", 300, 100, ANGLE_0, 40, 100);
		BULLETMANAGER->bossHorizontalBulletFire("redHorizontalBullet", 300, 150, ANGLE_0, 40, 100);
		BULLETMANAGER->bossHorizontalBulletFire("redHorizontalBullet", 300, 200, ANGLE_0, 40, 100);
		BULLETMANAGER->bossHorizontalBulletFire("redHorizontalBullet", 300, 250, ANGLE_0, 40, 100);
		BULLETMANAGER->bossHorizontalBulletFire("redHorizontalBullet", 300, 300, ANGLE_0, 40, 100);
		BULLETMANAGER->bossHorizontalBulletFire("redHorizontalBullet", 300, 350, ANGLE_0, 40, 100);
	}
	break;
	case 3:
	{
		BULLETMANAGER->bossVerticalBulletFire("redVerticalBullet", 100, 0, ANGLE_270, 10, 10);
		BULLETMANAGER->bossVerticalBulletFire("redVerticalBullet", 150, 0, ANGLE_270, 10, 10);
		BULLETMANAGER->bossVerticalBulletFire("redVerticalBullet", 200, 0, ANGLE_270, 10, 10);
		BULLETMANAGER->bossVerticalBulletFire("redVerticalBullet", 250, 0, ANGLE_270, 10, 10);
		BULLETMANAGER->bossVerticalBulletFire("redVerticalBullet", 300, 0, ANGLE_270, 10, 10);
		BULLETMANAGER->bossVerticalBulletFire("redVerticalBullet", 350, 0, ANGLE_270, 10, 10);
		BULLETMANAGER->bossVerticalBulletFire("redVerticalBullet", 400, 0, ANGLE_270, 10, 10);
		BULLETMANAGER->bossVerticalBulletFire("redVerticalBullet", 450, 0, ANGLE_270, 10, 10);
		BULLETMANAGER->bossVerticalBulletFire("redVerticalBullet", 500, 0, ANGLE_270, 10, 10);
		BULLETMANAGER->bossVerticalBulletFire("redVerticalBullet", 550, 0, ANGLE_270, 10, 10);
		BULLETMANAGER->bossVerticalBulletFire("redVerticalBullet", 600, 0, ANGLE_270, 10, 10);
		BULLETMANAGER->bossVerticalBulletFire("redVerticalBullet", 650, 0, ANGLE_270, 10, 10);
		BULLETMANAGER->bossVerticalBulletFire("redVerticalBullet", 700, 0, ANGLE_270, 10, 10);
	}																				  
	break;																			  
	case 4:																			  
	{					
		BULLETMANAGER->bossVerticalBulletFire("redVerticalBullet", 125, 0, ANGLE_270, 10, 10);
		BULLETMANAGER->bossVerticalBulletFire("redVerticalBullet", 175, 0, ANGLE_270, 10, 10);
		BULLETMANAGER->bossVerticalBulletFire("redVerticalBullet", 225, 0, ANGLE_270, 10, 10);
		BULLETMANAGER->bossVerticalBulletFire("redVerticalBullet", 275, 0, ANGLE_270, 10, 10);
		BULLETMANAGER->bossVerticalBulletFire("redVerticalBullet", 325, 0, ANGLE_270, 10, 10);
		BULLETMANAGER->bossVerticalBulletFire("redVerticalBullet", 375, 0, ANGLE_270, 10, 10);
		BULLETMANAGER->bossVerticalBulletFire("redVerticalBullet", 425, 0, ANGLE_270, 10, 10);
		BULLETMANAGER->bossVerticalBulletFire("redVerticalBullet", 475, 0, ANGLE_270, 10, 10);
		BULLETMANAGER->bossVerticalBulletFire("redVerticalBullet", 525, 0, ANGLE_270, 10, 10);
		BULLETMANAGER->bossVerticalBulletFire("redVerticalBullet", 575, 0, ANGLE_270, 10, 10);
		BULLETMANAGER->bossVerticalBulletFire("redVerticalBullet", 625, 0, ANGLE_270, 10, 10);
		BULLETMANAGER->bossVerticalBulletFire("redVerticalBullet", 675, 0, ANGLE_270, 10, 10);
	}
	break;
	case 5:
	{
		for (m_viBoss = m_vBoss.begin(); m_viBoss != m_vBoss.end(); ++m_viBoss)
		{
			BULLETMANAGER->bossCommonBulletFire("redBullet", (*m_viBoss)->getBossX(), (*m_viBoss)->getBossY(), ANGLE_0, 5, 20);
			BULLETMANAGER->bossCommonBulletFire("redBullet", (*m_viBoss)->getBossX(), (*m_viBoss)->getBossY(), ANGLE_30, 5, 20);
			BULLETMANAGER->bossCommonBulletFire("redBullet", (*m_viBoss)->getBossX(), (*m_viBoss)->getBossY(), ANGLE_60, 5, 20);
			BULLETMANAGER->bossCommonBulletFire("redBullet", (*m_viBoss)->getBossX(), (*m_viBoss)->getBossY(), ANGLE_90, 5, 20);
			BULLETMANAGER->bossCommonBulletFire("redBullet", (*m_viBoss)->getBossX(), (*m_viBoss)->getBossY(), ANGLE_120, 5, 20);
			BULLETMANAGER->bossCommonBulletFire("redBullet", (*m_viBoss)->getBossX(), (*m_viBoss)->getBossY(), ANGLE_150, 5, 20);
			BULLETMANAGER->bossCommonBulletFire("redBullet", (*m_viBoss)->getBossX(), (*m_viBoss)->getBossY(), ANGLE_180, 5, 20);
			BULLETMANAGER->bossCommonBulletFire("redBullet", (*m_viBoss)->getBossX(), (*m_viBoss)->getBossY(), ANGLE_210, 5, 20);
			BULLETMANAGER->bossCommonBulletFire("redBullet", (*m_viBoss)->getBossX(), (*m_viBoss)->getBossY(), ANGLE_240, 5, 20);
			BULLETMANAGER->bossCommonBulletFire("redBullet", (*m_viBoss)->getBossX(), (*m_viBoss)->getBossY(), ANGLE_270, 5, 20);
			BULLETMANAGER->bossCommonBulletFire("redBullet", (*m_viBoss)->getBossX(), (*m_viBoss)->getBossY(), ANGLE_300, 5, 20);
			BULLETMANAGER->bossCommonBulletFire("redBullet", (*m_viBoss)->getBossX(), (*m_viBoss)->getBossY(), ANGLE_330, 5, 20);

			BULLETMANAGER->bossCommonBulletFire("purpleBullet", (*m_viBoss)->getBossX(), (*m_viBoss)->getBossY(), ANGLE_0, 5, 40);
			BULLETMANAGER->bossCommonBulletFire("purpleBullet", (*m_viBoss)->getBossX(), (*m_viBoss)->getBossY(), ANGLE_30, 5, 40);
			BULLETMANAGER->bossCommonBulletFire("purpleBullet", (*m_viBoss)->getBossX(), (*m_viBoss)->getBossY(), ANGLE_60, 5, 40);
			BULLETMANAGER->bossCommonBulletFire("purpleBullet", (*m_viBoss)->getBossX(), (*m_viBoss)->getBossY(), ANGLE_90, 5, 40);
			BULLETMANAGER->bossCommonBulletFire("purpleBullet", (*m_viBoss)->getBossX(), (*m_viBoss)->getBossY(), ANGLE_120, 5, 40);
			BULLETMANAGER->bossCommonBulletFire("purpleBullet", (*m_viBoss)->getBossX(), (*m_viBoss)->getBossY(), ANGLE_150, 5, 40);
			BULLETMANAGER->bossCommonBulletFire("purpleBullet", (*m_viBoss)->getBossX(), (*m_viBoss)->getBossY(), ANGLE_180, 5, 40);
			BULLETMANAGER->bossCommonBulletFire("purpleBullet", (*m_viBoss)->getBossX(), (*m_viBoss)->getBossY(), ANGLE_210, 5, 40);
			BULLETMANAGER->bossCommonBulletFire("purpleBullet", (*m_viBoss)->getBossX(), (*m_viBoss)->getBossY(), ANGLE_240, 5, 40);
			BULLETMANAGER->bossCommonBulletFire("purpleBullet", (*m_viBoss)->getBossX(), (*m_viBoss)->getBossY(), ANGLE_270, 5, 40);
			BULLETMANAGER->bossCommonBulletFire("purpleBullet", (*m_viBoss)->getBossX(), (*m_viBoss)->getBossY(), ANGLE_300, 5, 40);
			BULLETMANAGER->bossCommonBulletFire("purpleBullet", (*m_viBoss)->getBossX(), (*m_viBoss)->getBossY(), ANGLE_330, 5, 40);

			BULLETMANAGER->bossCommonBulletFire("yellowBullet", (*m_viBoss)->getBossX(), (*m_viBoss)->getBossY(), ANGLE_0, 5, 80);
			BULLETMANAGER->bossCommonBulletFire("yellowBullet", (*m_viBoss)->getBossX(), (*m_viBoss)->getBossY(), ANGLE_30, 5, 80);
			BULLETMANAGER->bossCommonBulletFire("yellowBullet", (*m_viBoss)->getBossX(), (*m_viBoss)->getBossY(), ANGLE_60, 5, 80);
			BULLETMANAGER->bossCommonBulletFire("yellowBullet", (*m_viBoss)->getBossX(), (*m_viBoss)->getBossY(), ANGLE_90, 5, 80);
			BULLETMANAGER->bossCommonBulletFire("yellowBullet", (*m_viBoss)->getBossX(), (*m_viBoss)->getBossY(), ANGLE_120, 5, 80);
			BULLETMANAGER->bossCommonBulletFire("yellowBullet", (*m_viBoss)->getBossX(), (*m_viBoss)->getBossY(), ANGLE_150, 5, 80);
			BULLETMANAGER->bossCommonBulletFire("yellowBullet", (*m_viBoss)->getBossX(), (*m_viBoss)->getBossY(), ANGLE_180, 5, 80);
			BULLETMANAGER->bossCommonBulletFire("yellowBullet", (*m_viBoss)->getBossX(), (*m_viBoss)->getBossY(), ANGLE_210, 5, 80);
			BULLETMANAGER->bossCommonBulletFire("yellowBullet", (*m_viBoss)->getBossX(), (*m_viBoss)->getBossY(), ANGLE_240, 5, 80);
			BULLETMANAGER->bossCommonBulletFire("yellowBullet", (*m_viBoss)->getBossX(), (*m_viBoss)->getBossY(), ANGLE_270, 5, 80);
			BULLETMANAGER->bossCommonBulletFire("yellowBullet", (*m_viBoss)->getBossX(), (*m_viBoss)->getBossY(), ANGLE_300, 5, 80);
			BULLETMANAGER->bossCommonBulletFire("yellowBullet", (*m_viBoss)->getBossX(), (*m_viBoss)->getBossY(), ANGLE_330, 5, 80);

			BULLETMANAGER->bossCommonBulletFire("greenBullet", (*m_viBoss)->getBossX(), (*m_viBoss)->getBossY(), ANGLE_0, 5, 160);
			BULLETMANAGER->bossCommonBulletFire("greenBullet", (*m_viBoss)->getBossX(), (*m_viBoss)->getBossY(), ANGLE_30, 5, 160);
			BULLETMANAGER->bossCommonBulletFire("greenBullet", (*m_viBoss)->getBossX(), (*m_viBoss)->getBossY(), ANGLE_60, 5, 160);
			BULLETMANAGER->bossCommonBulletFire("greenBullet", (*m_viBoss)->getBossX(), (*m_viBoss)->getBossY(), ANGLE_90, 5, 160);
			BULLETMANAGER->bossCommonBulletFire("greenBullet", (*m_viBoss)->getBossX(), (*m_viBoss)->getBossY(), ANGLE_120, 5, 160);
			BULLETMANAGER->bossCommonBulletFire("greenBullet", (*m_viBoss)->getBossX(), (*m_viBoss)->getBossY(), ANGLE_150, 5, 160);
			BULLETMANAGER->bossCommonBulletFire("greenBullet", (*m_viBoss)->getBossX(), (*m_viBoss)->getBossY(), ANGLE_180, 5, 160);
			BULLETMANAGER->bossCommonBulletFire("greenBullet", (*m_viBoss)->getBossX(), (*m_viBoss)->getBossY(), ANGLE_210, 5, 160);
			BULLETMANAGER->bossCommonBulletFire("greenBullet", (*m_viBoss)->getBossX(), (*m_viBoss)->getBossY(), ANGLE_240, 5, 160);
			BULLETMANAGER->bossCommonBulletFire("greenBullet", (*m_viBoss)->getBossX(), (*m_viBoss)->getBossY(), ANGLE_270, 5, 160);
			BULLETMANAGER->bossCommonBulletFire("greenBullet", (*m_viBoss)->getBossX(), (*m_viBoss)->getBossY(), ANGLE_300, 5, 160);
			BULLETMANAGER->bossCommonBulletFire("greenBullet", (*m_viBoss)->getBossX(), (*m_viBoss)->getBossY(), ANGLE_330, 5, 160);
		}
	}
	break;
	default:
		break;
	}
}

void enemyManager::deleteBoss(int num)
{
}

void enemyManager::bossPatternRain(int countNum)
{
	for (int i = 0; i < 10; i++)
	{
		if (count >= countNum + (i * 40) && count < countNum + 10 + +(i * 40))
		{
			bossBulletFire(3);
		}
		if (count >= countNum + 20 + (i * 40) && count < countNum + 30 + (i * 40))
		{
			bossBulletFire(4);
		}
	}
}
