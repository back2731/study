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
	change = true;
	update();

	setBoss();

	alphaValue1 = 0;
	alphaValue2 = 0;
	alphaValue3 = 0;
	alphaValue4 = 0;
	alphaValue5 = 0;
	alphaValue6 = 0;
	alphaValue7 = 0;
	alphaValue8 = 0;

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
	if (count >= 1700 && m_vBoss.size() > 0)
	{
		bossUpdate(0);

		if (count >= 2150 && count < 2350)
		{
			m_vBoss[0]->move(FLY);
		}
		if (count >= 2350 && count < 2550)
		{
			m_vBoss[0]->move(IDLE);
		}
		if (count >= 2550 && count < 2670)
		{
			m_vBoss[0]->move(THROWSPEAR);
		}
		if (count >= 2520 && count < 2620)
		{
			bossBulletFire(2);
		}
		if (count >= 2670 && count < 3250)
		{
			m_vBoss[0]->move(IDLE);
		}

		bossPatternRain(2750);

		if (count >= 3250 && count < 3300)
		{
			m_vBoss[0]->move(UP);
			m_vBoss[0]->move(WORKLEFT);
		}
		if (count >= 3300 && count < 3350)
		{
			m_vBoss[0]->move(IDLE);
		}
		if (count >= 3350 && count < 3400)
		{
			m_vBoss[0]->move(LEFT);
			m_vBoss[0]->move(WORKLEFT);
		}
		if (count >= 3400 && count < 3450)
		{
			m_vBoss[0]->move(IDLE);
			alphaValue1 += 2;
		}
		if (count >= 3450 && count < 3500)
		{
			m_vBoss[0]->move(LEFTDOWN);
			m_vBoss[0]->move(WORKLEFT);
		}
		if (count >= 3500 && count < 3550)
		{
			m_vBoss[0]->move(IDLE);
			alphaValue2 += 2;
		}
		if (count >= 3550 && count < 3650)
		{
			m_vBoss[0]->move(DOWN);
			m_vBoss[0]->move(IDLE);
		}
		if (count >= 3650 && count < 3700)
		{
			m_vBoss[0]->move(IDLE);
			alphaValue3 += 2;
		}
		if (count >= 3700 && count < 3750)
		{
			m_vBoss[0]->move(RIGHTDOWN);
			m_vBoss[0]->move(WORKRIGHT);
		}
		if (count >= 3750 && count < 3800)
		{
			m_vBoss[0]->move(IDLE);
			alphaValue4 += 2;
		}
		if (count >= 3800 && count < 3900)
		{
			m_vBoss[0]->move(RIGHT);
			m_vBoss[0]->move(WORKRIGHT);
		}
		if (count >= 3900 && count < 3950)
		{
			m_vBoss[0]->move(IDLE);
			alphaValue5 += 2;
		}
		if (count >= 3950 && count < 4000)
		{
			m_vBoss[0]->move(RIGHTUP);
			m_vBoss[0]->move(WORKRIGHT);
		}
		if (count >= 4000 && count < 4050)
		{
			m_vBoss[0]->move(IDLE);
			alphaValue6 += 2;
		}
		if (count >= 4050 && count < 4150)
		{
			m_vBoss[0]->move(UP);
			m_vBoss[0]->move(IDLE);
		}
		if (count >= 4150 && count < 4200)
		{
			m_vBoss[0]->move(IDLE);
			alphaValue7 += 2;
		}
		if (count >= 4200 && count < 4250)
		{
			m_vBoss[0]->move(LEFTUP);
			m_vBoss[0]->move(WORKLEFT);
		}
		if (count >= 4250 && count < 4300)
		{
			m_vBoss[0]->move(IDLE);
			alphaValue8 += 2;
		}
		if (count >= 4300 && count < 4350)
		{
			m_vBoss[0]->move(LEFT);
			m_vBoss[0]->move(WORKLEFT);
		}
		if (count >= 4350 && count < 4400)
		{
			m_vBoss[0]->move(IDLE);
		}
		if (count >= 4400 && count < 4500)
		{
			m_vBoss[0]->move(DOWN);
			m_vBoss[0]->move(IDLE);
		}
		if (count >= 4500 && count < 4650)
		{
			m_vBoss[0]->move(IDLE);
		}
		if (count >= 4700 && count < 6400)
		{
			m_vBoss[0]->move(MAGICCASTING);
		}
		if (count >= 3250 && count < 4500)
		{
			bossBulletFire(5);
			bossBulletFire(0);
			bossBulletFire(1);
		}
		if (count >= 4700 && count < 5700)
		{
			bossBulletFire(6);
		}
		if (count >= 4700 && count < 4750)
		{
			alphaValue1 += 2;
		}
		if (count >= 4800 && count < 5800)
		{
			bossBulletFire(7);
		}
		if (count >= 4800 && count < 4850)
		{
			alphaValue8 += 2;
		}
		if (count >= 4900 && count < 5900)
		{
			bossBulletFire(8);
		}
		if (count >= 4900 && count < 4950)
		{
			alphaValue4 += 2;
		}
		if (count >= 5000 && count < 6000)
		{
			bossBulletFire(9);
		}
		if (count >= 5000 && count < 5050)
		{
			alphaValue5 += 2;
		}
		if (count >= 5100 && count < 6100)
		{
			bossBulletFire(10);
		}
		if (count >= 5100 && count < 5150)
		{
			alphaValue2 += 2;
		}
		if (count >= 5200 && count < 6200)
		{
			bossBulletFire(11);
		}
		if (count >= 5200 && count < 5250)
		{
			alphaValue3 += 2;
		}
		if (count >= 5300 && count < 6300)
		{
			bossBulletFire(12);
		}
		if (count >= 5300 && count < 5350)
		{
			alphaValue7 += 2;
		}
		if (count >= 5400 && count < 6400)
		{
			bossBulletFire(13);
		}
		if (count >= 5400 && count < 5450)
		{
			alphaValue6 += 2;
		}
		if (count >= 6400 && count < 6500)
		{
			m_vBoss[0]->move(IDLE);
		}
		if (count >= 6500 && count < 6640)
		{
			m_vBoss[0]->move(DRAWCARD);
		}
		if (count >= 6620 && count < 6670)
		{
			if (alphaValue3 != 30)
			{
				alphaValue2--;
				alphaValue3--;
				alphaValue4--;
				alphaValue5--;
				alphaValue6--;
				alphaValue7--;				
			}

			if (alphaValue1 != 15)
			{
				alphaValue1--;
				alphaValue8--;
			}
			bossCannon2.top -= 2;
			bossCannon2.bottom -= 2;
			bossCannon7.top -= 2;
			bossCannon7.bottom -= 2;

			bossCannon3.top -= 4;
			bossCannon3.bottom -= 4;
			bossCannon6.top -= 4;
			bossCannon6.bottom -= 4;

			bossCannon1.left  += 2;
			bossCannon1.right += 2;
			bossCannon2.left += 1;
			bossCannon2.right += 1;
								 
			bossCannon8.left  -= 2;
			bossCannon8.right -= 2;
			bossCannon7.left -= 1;
			bossCannon7.right -= 1;

			bossCannon4.top    -= 4;
			bossCannon4.bottom -= 4;
			bossCannon5.top    -= 4;
			bossCannon5.bottom -= 4;
		}
		if (count >= 6640 && count < 8230)
		{
			m_vBoss[0]->move(IDLE);
		}
		if (count >= 6720 && count < 6770)
		{
			alphaValue1 += 2;
		}
		if (count >= 6800 && count < 8000)
		{
			bossBulletFire(14);
		}
		if (count >= 6900 && count < 6950)
		{
			alphaValue2 += 2;
		}
		if (count >= 6950 && count < 8000)
		{
			bossBulletFire(15);
		}
		if (count >= 7050 && count < 7100)
		{
			alphaValue7 += 2;
		}
		if (count >= 7130 && count < 8000)
		{
			bossBulletFire(16);
		}
		if (count >= 7200 && count < 7250)
		{
			alphaValue3 += 2;
			alphaValue6 += 2;
		}
		if (count >= 7300 && count < 8000)
		{
			bossBulletFire(17);
		}
		if (count >= 7350 && count < 7400)
		{
			alphaValue4 += 2;
			alphaValue5 += 2;
		}
		if (count >= 7450 && count < 8000)
		{
			bossBulletFire(18);
		}
		if (count >= 8050 && count < 8230)
		{
			bossCannon1.top		+= 1;
			bossCannon1.bottom	+= 1;
			bossCannon8.top		+= 1;
			bossCannon8.bottom	+= 1;
		}
		if (count >= 8000)
		{
			if (alphaValue2 != 0)
			{
				alphaValue2 -= 2;
			}
			if (alphaValue3 != 0)
			{
				alphaValue3 -= 2;
			}
			if (alphaValue4 != 0)
			{
				alphaValue4 -= 2;
			}
			if (alphaValue5 != 0)
			{
				alphaValue5 -= 2;
			}	
			if (alphaValue6 != 0)
			{
				alphaValue6 -= 2;
			}	
			if (alphaValue7 != 0)
			{
				alphaValue7 -= 2;
			}
		}
		if (count >= 8230 && count < 9500)
		{
			m_vBoss[0]->move(MAGICCASTING);
		}
		if (count >= 8250 && count < 9450)
		{
			bossBulletFire(19);
			bossBulletFire(0);
			bossBulletFire(1);
		}
		if (count >= 9500 && count < 15000)
		{
			m_vBoss[0]->move(IDLE);
		}
	}	
	else
	{

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
			BULLETMANAGER->bossHomingBulletMove();
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
	BULLETMANAGER->bossHomingBulletRender();

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
	case 6:
	{
		BULLETMANAGER->bossCommonBulletFire("redStarBullet", bossCannon1.left + (bossCannon1.right - bossCannon1.left) / 2, bossCannon1.top + (bossCannon1.bottom - bossCannon1.top) / 2,   ANGLE_0, 5, 20);
		BULLETMANAGER->bossCommonBulletFire("redStarBullet", bossCannon1.left + (bossCannon1.right - bossCannon1.left) / 2, bossCannon1.top + (bossCannon1.bottom - bossCannon1.top) / 2,  ANGLE_30, 5, 20);
		BULLETMANAGER->bossCommonBulletFire("redStarBullet", bossCannon1.left + (bossCannon1.right - bossCannon1.left) / 2, bossCannon1.top + (bossCannon1.bottom - bossCannon1.top) / 2,  ANGLE_60, 5, 20);
		BULLETMANAGER->bossCommonBulletFire("redStarBullet", bossCannon1.left + (bossCannon1.right - bossCannon1.left) / 2, bossCannon1.top + (bossCannon1.bottom - bossCannon1.top) / 2,  ANGLE_90, 5, 20);
		BULLETMANAGER->bossCommonBulletFire("redStarBullet", bossCannon1.left + (bossCannon1.right - bossCannon1.left) / 2, bossCannon1.top + (bossCannon1.bottom - bossCannon1.top) / 2, ANGLE_120, 5, 20);
		BULLETMANAGER->bossCommonBulletFire("redStarBullet", bossCannon1.left + (bossCannon1.right - bossCannon1.left) / 2, bossCannon1.top + (bossCannon1.bottom - bossCannon1.top) / 2, ANGLE_150, 5, 20);
		BULLETMANAGER->bossCommonBulletFire("redStarBullet", bossCannon1.left + (bossCannon1.right - bossCannon1.left) / 2, bossCannon1.top + (bossCannon1.bottom - bossCannon1.top) / 2, ANGLE_180, 5, 20);
		BULLETMANAGER->bossCommonBulletFire("redStarBullet", bossCannon1.left + (bossCannon1.right - bossCannon1.left) / 2, bossCannon1.top + (bossCannon1.bottom - bossCannon1.top) / 2, ANGLE_210, 5, 20);
		BULLETMANAGER->bossCommonBulletFire("redStarBullet", bossCannon1.left + (bossCannon1.right - bossCannon1.left) / 2, bossCannon1.top + (bossCannon1.bottom - bossCannon1.top) / 2, ANGLE_240, 5, 20);
		BULLETMANAGER->bossCommonBulletFire("redStarBullet", bossCannon1.left + (bossCannon1.right - bossCannon1.left) / 2, bossCannon1.top + (bossCannon1.bottom - bossCannon1.top) / 2, ANGLE_270, 5, 20);
		BULLETMANAGER->bossCommonBulletFire("redStarBullet", bossCannon1.left + (bossCannon1.right - bossCannon1.left) / 2, bossCannon1.top + (bossCannon1.bottom - bossCannon1.top) / 2, ANGLE_300, 5, 20);
		BULLETMANAGER->bossCommonBulletFire("redStarBullet", bossCannon1.left + (bossCannon1.right - bossCannon1.left) / 2, bossCannon1.top + (bossCannon1.bottom - bossCannon1.top) / 2, ANGLE_330, 5, 20);
	}
		break;
	case 7:
	{
		BULLETMANAGER->bossCommonBulletFire("blueStarBullet", bossCannon8.left + (bossCannon8.right - bossCannon8.left) / 2, bossCannon8.top + (bossCannon8.bottom - bossCannon8.top) / 2, ANGLE_0, 5, 20);
		BULLETMANAGER->bossCommonBulletFire("blueStarBullet", bossCannon8.left + (bossCannon8.right - bossCannon8.left) / 2, bossCannon8.top + (bossCannon8.bottom - bossCannon8.top) / 2, ANGLE_30, 5, 20);
		BULLETMANAGER->bossCommonBulletFire("blueStarBullet", bossCannon8.left + (bossCannon8.right - bossCannon8.left) / 2, bossCannon8.top + (bossCannon8.bottom - bossCannon8.top) / 2, ANGLE_60, 5, 20);
		BULLETMANAGER->bossCommonBulletFire("blueStarBullet", bossCannon8.left + (bossCannon8.right - bossCannon8.left) / 2, bossCannon8.top + (bossCannon8.bottom - bossCannon8.top) / 2, ANGLE_90, 5, 20);
		BULLETMANAGER->bossCommonBulletFire("blueStarBullet", bossCannon8.left + (bossCannon8.right - bossCannon8.left) / 2, bossCannon8.top + (bossCannon8.bottom - bossCannon8.top) / 2, ANGLE_120, 5, 20);
		BULLETMANAGER->bossCommonBulletFire("blueStarBullet", bossCannon8.left + (bossCannon8.right - bossCannon8.left) / 2, bossCannon8.top + (bossCannon8.bottom - bossCannon8.top) / 2, ANGLE_150, 5, 20);
		BULLETMANAGER->bossCommonBulletFire("blueStarBullet", bossCannon8.left + (bossCannon8.right - bossCannon8.left) / 2, bossCannon8.top + (bossCannon8.bottom - bossCannon8.top) / 2, ANGLE_180, 5, 20);
		BULLETMANAGER->bossCommonBulletFire("blueStarBullet", bossCannon8.left + (bossCannon8.right - bossCannon8.left) / 2, bossCannon8.top + (bossCannon8.bottom - bossCannon8.top) / 2, ANGLE_210, 5, 20);
		BULLETMANAGER->bossCommonBulletFire("blueStarBullet", bossCannon8.left + (bossCannon8.right - bossCannon8.left) / 2, bossCannon8.top + (bossCannon8.bottom - bossCannon8.top) / 2, ANGLE_240, 5, 20);
		BULLETMANAGER->bossCommonBulletFire("blueStarBullet", bossCannon8.left + (bossCannon8.right - bossCannon8.left) / 2, bossCannon8.top + (bossCannon8.bottom - bossCannon8.top) / 2, ANGLE_270, 5, 20);
		BULLETMANAGER->bossCommonBulletFire("blueStarBullet", bossCannon8.left + (bossCannon8.right - bossCannon8.left) / 2, bossCannon8.top + (bossCannon8.bottom - bossCannon8.top) / 2, ANGLE_300, 5, 20);
		BULLETMANAGER->bossCommonBulletFire("blueStarBullet", bossCannon8.left + (bossCannon8.right - bossCannon8.left) / 2, bossCannon8.top + (bossCannon8.bottom - bossCannon8.top) / 2, ANGLE_330, 5, 20);
	}
	break;
	case 8:
	{
		BULLETMANAGER->bossCommonBulletFire("yellowStarBullet", bossCannon4.left + (bossCannon4.right - bossCannon4.left) / 2, bossCannon4.top + (bossCannon4.bottom - bossCannon4.top) / 2, ANGLE_0, 5, 20);
		BULLETMANAGER->bossCommonBulletFire("yellowStarBullet", bossCannon4.left + (bossCannon4.right - bossCannon4.left) / 2, bossCannon4.top + (bossCannon4.bottom - bossCannon4.top) / 2, ANGLE_30, 5, 20);
		BULLETMANAGER->bossCommonBulletFire("yellowStarBullet", bossCannon4.left + (bossCannon4.right - bossCannon4.left) / 2, bossCannon4.top + (bossCannon4.bottom - bossCannon4.top) / 2, ANGLE_60, 5, 20);
		BULLETMANAGER->bossCommonBulletFire("yellowStarBullet", bossCannon4.left + (bossCannon4.right - bossCannon4.left) / 2, bossCannon4.top + (bossCannon4.bottom - bossCannon4.top) / 2, ANGLE_90, 5, 20);
		BULLETMANAGER->bossCommonBulletFire("yellowStarBullet", bossCannon4.left + (bossCannon4.right - bossCannon4.left) / 2, bossCannon4.top + (bossCannon4.bottom - bossCannon4.top) / 2, ANGLE_120, 5, 20);
		BULLETMANAGER->bossCommonBulletFire("yellowStarBullet", bossCannon4.left + (bossCannon4.right - bossCannon4.left) / 2, bossCannon4.top + (bossCannon4.bottom - bossCannon4.top) / 2, ANGLE_150, 5, 20);
		BULLETMANAGER->bossCommonBulletFire("yellowStarBullet", bossCannon4.left + (bossCannon4.right - bossCannon4.left) / 2, bossCannon4.top + (bossCannon4.bottom - bossCannon4.top) / 2, ANGLE_180, 5, 20);
		BULLETMANAGER->bossCommonBulletFire("yellowStarBullet", bossCannon4.left + (bossCannon4.right - bossCannon4.left) / 2, bossCannon4.top + (bossCannon4.bottom - bossCannon4.top) / 2, ANGLE_210, 5, 20);
		BULLETMANAGER->bossCommonBulletFire("yellowStarBullet", bossCannon4.left + (bossCannon4.right - bossCannon4.left) / 2, bossCannon4.top + (bossCannon4.bottom - bossCannon4.top) / 2, ANGLE_240, 5, 20);
		BULLETMANAGER->bossCommonBulletFire("yellowStarBullet", bossCannon4.left + (bossCannon4.right - bossCannon4.left) / 2, bossCannon4.top + (bossCannon4.bottom - bossCannon4.top) / 2, ANGLE_270, 5, 20);
		BULLETMANAGER->bossCommonBulletFire("yellowStarBullet", bossCannon4.left + (bossCannon4.right - bossCannon4.left) / 2, bossCannon4.top + (bossCannon4.bottom - bossCannon4.top) / 2, ANGLE_300, 5, 20);
		BULLETMANAGER->bossCommonBulletFire("yellowStarBullet", bossCannon4.left + (bossCannon4.right - bossCannon4.left) / 2, bossCannon4.top + (bossCannon4.bottom - bossCannon4.top) / 2, ANGLE_330, 5, 20);
	}
	break;
	case 9:
	{
		BULLETMANAGER->bossCommonBulletFire("skyStarBullet", bossCannon5.left + (bossCannon5.right - bossCannon5.left) / 2, bossCannon5.top + (bossCannon5.bottom - bossCannon5.top) / 2, ANGLE_0, 5, 20);
		BULLETMANAGER->bossCommonBulletFire("skyStarBullet", bossCannon5.left + (bossCannon5.right - bossCannon5.left) / 2, bossCannon5.top + (bossCannon5.bottom - bossCannon5.top) / 2, ANGLE_30, 5, 20);
		BULLETMANAGER->bossCommonBulletFire("skyStarBullet", bossCannon5.left + (bossCannon5.right - bossCannon5.left) / 2, bossCannon5.top + (bossCannon5.bottom - bossCannon5.top) / 2, ANGLE_60, 5, 20);
		BULLETMANAGER->bossCommonBulletFire("skyStarBullet", bossCannon5.left + (bossCannon5.right - bossCannon5.left) / 2, bossCannon5.top + (bossCannon5.bottom - bossCannon5.top) / 2, ANGLE_90, 5, 20);
		BULLETMANAGER->bossCommonBulletFire("skyStarBullet", bossCannon5.left + (bossCannon5.right - bossCannon5.left) / 2, bossCannon5.top + (bossCannon5.bottom - bossCannon5.top) / 2, ANGLE_120, 5, 20);
		BULLETMANAGER->bossCommonBulletFire("skyStarBullet", bossCannon5.left + (bossCannon5.right - bossCannon5.left) / 2, bossCannon5.top + (bossCannon5.bottom - bossCannon5.top) / 2, ANGLE_150, 5, 20);
		BULLETMANAGER->bossCommonBulletFire("skyStarBullet", bossCannon5.left + (bossCannon5.right - bossCannon5.left) / 2, bossCannon5.top + (bossCannon5.bottom - bossCannon5.top) / 2, ANGLE_180, 5, 20);
		BULLETMANAGER->bossCommonBulletFire("skyStarBullet", bossCannon5.left + (bossCannon5.right - bossCannon5.left) / 2, bossCannon5.top + (bossCannon5.bottom - bossCannon5.top) / 2, ANGLE_210, 5, 20);
		BULLETMANAGER->bossCommonBulletFire("skyStarBullet", bossCannon5.left + (bossCannon5.right - bossCannon5.left) / 2, bossCannon5.top + (bossCannon5.bottom - bossCannon5.top) / 2, ANGLE_240, 5, 20);
		BULLETMANAGER->bossCommonBulletFire("skyStarBullet", bossCannon5.left + (bossCannon5.right - bossCannon5.left) / 2, bossCannon5.top + (bossCannon5.bottom - bossCannon5.top) / 2, ANGLE_270, 5, 20);
		BULLETMANAGER->bossCommonBulletFire("skyStarBullet", bossCannon5.left + (bossCannon5.right - bossCannon5.left) / 2, bossCannon5.top + (bossCannon5.bottom - bossCannon5.top) / 2, ANGLE_300, 5, 20);
		BULLETMANAGER->bossCommonBulletFire("skyStarBullet", bossCannon5.left + (bossCannon5.right - bossCannon5.left) / 2, bossCannon5.top + (bossCannon5.bottom - bossCannon5.top) / 2, ANGLE_330, 5, 20);
	}
	break;
	case 10:
	{
		BULLETMANAGER->bossCommonBulletFire("greenStarBullet", bossCannon2.left + (bossCannon2.right - bossCannon2.left) / 2, bossCannon2.top + (bossCannon2.bottom - bossCannon2.top) / 2, ANGLE_0, 5, 20);
		BULLETMANAGER->bossCommonBulletFire("greenStarBullet", bossCannon2.left + (bossCannon2.right - bossCannon2.left) / 2, bossCannon2.top + (bossCannon2.bottom - bossCannon2.top) / 2, ANGLE_30, 5, 20);
		BULLETMANAGER->bossCommonBulletFire("greenStarBullet", bossCannon2.left + (bossCannon2.right - bossCannon2.left) / 2, bossCannon2.top + (bossCannon2.bottom - bossCannon2.top) / 2, ANGLE_60, 5, 20);
		BULLETMANAGER->bossCommonBulletFire("greenStarBullet", bossCannon2.left + (bossCannon2.right - bossCannon2.left) / 2, bossCannon2.top + (bossCannon2.bottom - bossCannon2.top) / 2, ANGLE_90, 5, 20);
		BULLETMANAGER->bossCommonBulletFire("greenStarBullet", bossCannon2.left + (bossCannon2.right - bossCannon2.left) / 2, bossCannon2.top + (bossCannon2.bottom - bossCannon2.top) / 2, ANGLE_120, 5, 20);
		BULLETMANAGER->bossCommonBulletFire("greenStarBullet", bossCannon2.left + (bossCannon2.right - bossCannon2.left) / 2, bossCannon2.top + (bossCannon2.bottom - bossCannon2.top) / 2, ANGLE_150, 5, 20);
		BULLETMANAGER->bossCommonBulletFire("greenStarBullet", bossCannon2.left + (bossCannon2.right - bossCannon2.left) / 2, bossCannon2.top + (bossCannon2.bottom - bossCannon2.top) / 2, ANGLE_180, 5, 20);
		BULLETMANAGER->bossCommonBulletFire("greenStarBullet", bossCannon2.left + (bossCannon2.right - bossCannon2.left) / 2, bossCannon2.top + (bossCannon2.bottom - bossCannon2.top) / 2, ANGLE_210, 5, 20);
		BULLETMANAGER->bossCommonBulletFire("greenStarBullet", bossCannon2.left + (bossCannon2.right - bossCannon2.left) / 2, bossCannon2.top + (bossCannon2.bottom - bossCannon2.top) / 2, ANGLE_240, 5, 20);
		BULLETMANAGER->bossCommonBulletFire("greenStarBullet", bossCannon2.left + (bossCannon2.right - bossCannon2.left) / 2, bossCannon2.top + (bossCannon2.bottom - bossCannon2.top) / 2, ANGLE_270, 5, 20);
		BULLETMANAGER->bossCommonBulletFire("greenStarBullet", bossCannon2.left + (bossCannon2.right - bossCannon2.left) / 2, bossCannon2.top + (bossCannon2.bottom - bossCannon2.top) / 2, ANGLE_300, 5, 20);
		BULLETMANAGER->bossCommonBulletFire("greenStarBullet", bossCannon2.left + (bossCannon2.right - bossCannon2.left) / 2, bossCannon2.top + (bossCannon2.bottom - bossCannon2.top) / 2, ANGLE_330, 5, 20);
	}
	break;
	case 11:
	{
		BULLETMANAGER->bossCommonBulletFire("grayStarBullet", bossCannon3.left + (bossCannon3.right - bossCannon3.left) / 2, bossCannon3.top + (bossCannon3.bottom - bossCannon3.top) / 2, ANGLE_0, 5, 20);
		BULLETMANAGER->bossCommonBulletFire("grayStarBullet", bossCannon3.left + (bossCannon3.right - bossCannon3.left) / 2, bossCannon3.top + (bossCannon3.bottom - bossCannon3.top) / 2, ANGLE_30, 5, 20);
		BULLETMANAGER->bossCommonBulletFire("grayStarBullet", bossCannon3.left + (bossCannon3.right - bossCannon3.left) / 2, bossCannon3.top + (bossCannon3.bottom - bossCannon3.top) / 2, ANGLE_60, 5, 20);
		BULLETMANAGER->bossCommonBulletFire("grayStarBullet", bossCannon3.left + (bossCannon3.right - bossCannon3.left) / 2, bossCannon3.top + (bossCannon3.bottom - bossCannon3.top) / 2, ANGLE_90, 5, 20);
		BULLETMANAGER->bossCommonBulletFire("grayStarBullet", bossCannon3.left + (bossCannon3.right - bossCannon3.left) / 2, bossCannon3.top + (bossCannon3.bottom - bossCannon3.top) / 2, ANGLE_120, 5, 20);
		BULLETMANAGER->bossCommonBulletFire("grayStarBullet", bossCannon3.left + (bossCannon3.right - bossCannon3.left) / 2, bossCannon3.top + (bossCannon3.bottom - bossCannon3.top) / 2, ANGLE_150, 5, 20);
		BULLETMANAGER->bossCommonBulletFire("grayStarBullet", bossCannon3.left + (bossCannon3.right - bossCannon3.left) / 2, bossCannon3.top + (bossCannon3.bottom - bossCannon3.top) / 2, ANGLE_180, 5, 20);
		BULLETMANAGER->bossCommonBulletFire("grayStarBullet", bossCannon3.left + (bossCannon3.right - bossCannon3.left) / 2, bossCannon3.top + (bossCannon3.bottom - bossCannon3.top) / 2, ANGLE_210, 5, 20);
		BULLETMANAGER->bossCommonBulletFire("grayStarBullet", bossCannon3.left + (bossCannon3.right - bossCannon3.left) / 2, bossCannon3.top + (bossCannon3.bottom - bossCannon3.top) / 2, ANGLE_240, 5, 20);
		BULLETMANAGER->bossCommonBulletFire("grayStarBullet", bossCannon3.left + (bossCannon3.right - bossCannon3.left) / 2, bossCannon3.top + (bossCannon3.bottom - bossCannon3.top) / 2, ANGLE_270, 5, 20);
		BULLETMANAGER->bossCommonBulletFire("grayStarBullet", bossCannon3.left + (bossCannon3.right - bossCannon3.left) / 2, bossCannon3.top + (bossCannon3.bottom - bossCannon3.top) / 2, ANGLE_300, 5, 20);
		BULLETMANAGER->bossCommonBulletFire("grayStarBullet", bossCannon3.left + (bossCannon3.right - bossCannon3.left) / 2, bossCannon3.top + (bossCannon3.bottom - bossCannon3.top) / 2, ANGLE_330, 5, 20);
	}
	break;
	case 12:
	{
		BULLETMANAGER->bossCommonBulletFire("purpleStarBullet", bossCannon7.left + (bossCannon7.right - bossCannon7.left) / 2, bossCannon7.top + (bossCannon7.bottom - bossCannon7.top) / 2, ANGLE_0, 5, 20);
		BULLETMANAGER->bossCommonBulletFire("purpleStarBullet", bossCannon7.left + (bossCannon7.right - bossCannon7.left) / 2, bossCannon7.top + (bossCannon7.bottom - bossCannon7.top) / 2, ANGLE_30, 5, 20);
		BULLETMANAGER->bossCommonBulletFire("purpleStarBullet", bossCannon7.left + (bossCannon7.right - bossCannon7.left) / 2, bossCannon7.top + (bossCannon7.bottom - bossCannon7.top) / 2, ANGLE_60, 5, 20);
		BULLETMANAGER->bossCommonBulletFire("purpleStarBullet", bossCannon7.left + (bossCannon7.right - bossCannon7.left) / 2, bossCannon7.top + (bossCannon7.bottom - bossCannon7.top) / 2, ANGLE_90, 5, 20);
		BULLETMANAGER->bossCommonBulletFire("purpleStarBullet", bossCannon7.left + (bossCannon7.right - bossCannon7.left) / 2, bossCannon7.top + (bossCannon7.bottom - bossCannon7.top) / 2, ANGLE_120, 5, 20);
		BULLETMANAGER->bossCommonBulletFire("purpleStarBullet", bossCannon7.left + (bossCannon7.right - bossCannon7.left) / 2, bossCannon7.top + (bossCannon7.bottom - bossCannon7.top) / 2, ANGLE_150, 5, 20);
		BULLETMANAGER->bossCommonBulletFire("purpleStarBullet", bossCannon7.left + (bossCannon7.right - bossCannon7.left) / 2, bossCannon7.top + (bossCannon7.bottom - bossCannon7.top) / 2, ANGLE_180, 5, 20);
		BULLETMANAGER->bossCommonBulletFire("purpleStarBullet", bossCannon7.left + (bossCannon7.right - bossCannon7.left) / 2, bossCannon7.top + (bossCannon7.bottom - bossCannon7.top) / 2, ANGLE_210, 5, 20);
		BULLETMANAGER->bossCommonBulletFire("purpleStarBullet", bossCannon7.left + (bossCannon7.right - bossCannon7.left) / 2, bossCannon7.top + (bossCannon7.bottom - bossCannon7.top) / 2, ANGLE_240, 5, 20);
		BULLETMANAGER->bossCommonBulletFire("purpleStarBullet", bossCannon7.left + (bossCannon7.right - bossCannon7.left) / 2, bossCannon7.top + (bossCannon7.bottom - bossCannon7.top) / 2, ANGLE_270, 5, 20);
		BULLETMANAGER->bossCommonBulletFire("purpleStarBullet", bossCannon7.left + (bossCannon7.right - bossCannon7.left) / 2, bossCannon7.top + (bossCannon7.bottom - bossCannon7.top) / 2, ANGLE_300, 5, 20);
		BULLETMANAGER->bossCommonBulletFire("purpleStarBullet", bossCannon7.left + (bossCannon7.right - bossCannon7.left) / 2, bossCannon7.top + (bossCannon7.bottom - bossCannon7.top) / 2, ANGLE_330, 5, 20);
	}
	break;
	case 13:
	{
		BULLETMANAGER->bossCommonBulletFire("orangeStarBullet", bossCannon6.left + (bossCannon6.right - bossCannon6.left) / 2, bossCannon6.top + (bossCannon6.bottom - bossCannon6.top) / 2, ANGLE_0, 5, 20);
		BULLETMANAGER->bossCommonBulletFire("orangeStarBullet", bossCannon6.left + (bossCannon6.right - bossCannon6.left) / 2, bossCannon6.top + (bossCannon6.bottom - bossCannon6.top) / 2, ANGLE_30, 5, 20);
		BULLETMANAGER->bossCommonBulletFire("orangeStarBullet", bossCannon6.left + (bossCannon6.right - bossCannon6.left) / 2, bossCannon6.top + (bossCannon6.bottom - bossCannon6.top) / 2, ANGLE_60, 5, 20);
		BULLETMANAGER->bossCommonBulletFire("orangeStarBullet", bossCannon6.left + (bossCannon6.right - bossCannon6.left) / 2, bossCannon6.top + (bossCannon6.bottom - bossCannon6.top) / 2, ANGLE_90, 5, 20);
		BULLETMANAGER->bossCommonBulletFire("orangeStarBullet", bossCannon6.left + (bossCannon6.right - bossCannon6.left) / 2, bossCannon6.top + (bossCannon6.bottom - bossCannon6.top) / 2, ANGLE_120, 5, 20);
		BULLETMANAGER->bossCommonBulletFire("orangeStarBullet", bossCannon6.left + (bossCannon6.right - bossCannon6.left) / 2, bossCannon6.top + (bossCannon6.bottom - bossCannon6.top) / 2, ANGLE_150, 5, 20);
		BULLETMANAGER->bossCommonBulletFire("orangeStarBullet", bossCannon6.left + (bossCannon6.right - bossCannon6.left) / 2, bossCannon6.top + (bossCannon6.bottom - bossCannon6.top) / 2, ANGLE_180, 5, 20);
		BULLETMANAGER->bossCommonBulletFire("orangeStarBullet", bossCannon6.left + (bossCannon6.right - bossCannon6.left) / 2, bossCannon6.top + (bossCannon6.bottom - bossCannon6.top) / 2, ANGLE_210, 5, 20);
		BULLETMANAGER->bossCommonBulletFire("orangeStarBullet", bossCannon6.left + (bossCannon6.right - bossCannon6.left) / 2, bossCannon6.top + (bossCannon6.bottom - bossCannon6.top) / 2, ANGLE_240, 5, 20);
		BULLETMANAGER->bossCommonBulletFire("orangeStarBullet", bossCannon6.left + (bossCannon6.right - bossCannon6.left) / 2, bossCannon6.top + (bossCannon6.bottom - bossCannon6.top) / 2, ANGLE_270, 5, 20);
		BULLETMANAGER->bossCommonBulletFire("orangeStarBullet", bossCannon6.left + (bossCannon6.right - bossCannon6.left) / 2, bossCannon6.top + (bossCannon6.bottom - bossCannon6.top) / 2, ANGLE_300, 5, 20);
		BULLETMANAGER->bossCommonBulletFire("orangeStarBullet", bossCannon6.left + (bossCannon6.right - bossCannon6.left) / 2, bossCannon6.top + (bossCannon6.bottom - bossCannon6.top) / 2, ANGLE_330, 5, 20);
	}
	break;
	case 14:
	{
		BULLETMANAGER->bossLeftSpinBulletFire("spBullet3", bossCannon1.left + (bossCannon1.right - bossCannon1.left) / 2, bossCannon1.top + (bossCannon1.bottom - bossCannon1.top) / 2, 5);
		BULLETMANAGER->bossRightSpinBulletFire("spBullet3", bossCannon8.left + (bossCannon8.right - bossCannon8.left) / 2, bossCannon8.top + (bossCannon8.bottom - bossCannon8.top) / 2, 5);
	}
	break;
	case 15:
	{
		BULLETMANAGER->bossCommonBulletFire("spbulletSmall1", bossCannon2.left + (bossCannon2.right - bossCannon2.left) / 2, bossCannon2.top + (bossCannon2.bottom - bossCannon2.top) / 2,   ANGLE_0, 5, 60);
		BULLETMANAGER->bossCommonBulletFire("spbulletSmall1", bossCannon2.left + (bossCannon2.right - bossCannon2.left) / 2, bossCannon2.top + (bossCannon2.bottom - bossCannon2.top) / 2,  ANGLE_30, 5, 60);
		BULLETMANAGER->bossCommonBulletFire("spbulletSmall1", bossCannon2.left + (bossCannon2.right - bossCannon2.left) / 2, bossCannon2.top + (bossCannon2.bottom - bossCannon2.top) / 2,  ANGLE_60, 5, 60);
		BULLETMANAGER->bossCommonBulletFire("spbulletSmall1", bossCannon2.left + (bossCannon2.right - bossCannon2.left) / 2, bossCannon2.top + (bossCannon2.bottom - bossCannon2.top) / 2,  ANGLE_90, 5, 60);
		BULLETMANAGER->bossCommonBulletFire("spbulletSmall1", bossCannon2.left + (bossCannon2.right - bossCannon2.left) / 2, bossCannon2.top + (bossCannon2.bottom - bossCannon2.top) / 2, ANGLE_120, 5, 60);
		BULLETMANAGER->bossCommonBulletFire("spbulletSmall1", bossCannon2.left + (bossCannon2.right - bossCannon2.left) / 2, bossCannon2.top + (bossCannon2.bottom - bossCannon2.top) / 2, ANGLE_150, 5, 60);
		BULLETMANAGER->bossCommonBulletFire("spbulletSmall1", bossCannon2.left + (bossCannon2.right - bossCannon2.left) / 2, bossCannon2.top + (bossCannon2.bottom - bossCannon2.top) / 2, ANGLE_180, 5, 60);
		BULLETMANAGER->bossCommonBulletFire("spbulletSmall1", bossCannon2.left + (bossCannon2.right - bossCannon2.left) / 2, bossCannon2.top + (bossCannon2.bottom - bossCannon2.top) / 2, ANGLE_210, 5, 60);
		BULLETMANAGER->bossCommonBulletFire("spbulletSmall1", bossCannon2.left + (bossCannon2.right - bossCannon2.left) / 2, bossCannon2.top + (bossCannon2.bottom - bossCannon2.top) / 2, ANGLE_240, 5, 60);
		BULLETMANAGER->bossCommonBulletFire("spbulletSmall1", bossCannon2.left + (bossCannon2.right - bossCannon2.left) / 2, bossCannon2.top + (bossCannon2.bottom - bossCannon2.top) / 2, ANGLE_270, 5, 60);
		BULLETMANAGER->bossCommonBulletFire("spbulletSmall1", bossCannon2.left + (bossCannon2.right - bossCannon2.left) / 2, bossCannon2.top + (bossCannon2.bottom - bossCannon2.top) / 2, ANGLE_300, 5, 60);
		BULLETMANAGER->bossCommonBulletFire("spbulletSmall1", bossCannon2.left + (bossCannon2.right - bossCannon2.left) / 2, bossCannon2.top + (bossCannon2.bottom - bossCannon2.top) / 2, ANGLE_330, 5, 60);
	}
	break;
	case 16:
	{
		BULLETMANAGER->bossCommonBulletFire("spbulletSmall1", bossCannon7.left + (bossCannon7.right - bossCannon7.left) / 2, bossCannon7.top + (bossCannon7.bottom - bossCannon7.top) / 2,   ANGLE_0, 5, 40);
		BULLETMANAGER->bossCommonBulletFire("spbulletSmall1", bossCannon7.left + (bossCannon7.right - bossCannon7.left) / 2, bossCannon7.top + (bossCannon7.bottom - bossCannon7.top) / 2,  ANGLE_30, 5, 40);
		BULLETMANAGER->bossCommonBulletFire("spbulletSmall1", bossCannon7.left + (bossCannon7.right - bossCannon7.left) / 2, bossCannon7.top + (bossCannon7.bottom - bossCannon7.top) / 2,  ANGLE_60, 5, 40);
		BULLETMANAGER->bossCommonBulletFire("spbulletSmall1", bossCannon7.left + (bossCannon7.right - bossCannon7.left) / 2, bossCannon7.top + (bossCannon7.bottom - bossCannon7.top) / 2,  ANGLE_90, 5, 40);
		BULLETMANAGER->bossCommonBulletFire("spbulletSmall1", bossCannon7.left + (bossCannon7.right - bossCannon7.left) / 2, bossCannon7.top + (bossCannon7.bottom - bossCannon7.top) / 2, ANGLE_120, 5, 40);
		BULLETMANAGER->bossCommonBulletFire("spbulletSmall1", bossCannon7.left + (bossCannon7.right - bossCannon7.left) / 2, bossCannon7.top + (bossCannon7.bottom - bossCannon7.top) / 2, ANGLE_150, 5, 40);
		BULLETMANAGER->bossCommonBulletFire("spbulletSmall1", bossCannon7.left + (bossCannon7.right - bossCannon7.left) / 2, bossCannon7.top + (bossCannon7.bottom - bossCannon7.top) / 2, ANGLE_180, 5, 40);
		BULLETMANAGER->bossCommonBulletFire("spbulletSmall1", bossCannon7.left + (bossCannon7.right - bossCannon7.left) / 2, bossCannon7.top + (bossCannon7.bottom - bossCannon7.top) / 2, ANGLE_210, 5, 40);
		BULLETMANAGER->bossCommonBulletFire("spbulletSmall1", bossCannon7.left + (bossCannon7.right - bossCannon7.left) / 2, bossCannon7.top + (bossCannon7.bottom - bossCannon7.top) / 2, ANGLE_240, 5, 40);
		BULLETMANAGER->bossCommonBulletFire("spbulletSmall1", bossCannon7.left + (bossCannon7.right - bossCannon7.left) / 2, bossCannon7.top + (bossCannon7.bottom - bossCannon7.top) / 2, ANGLE_270, 5, 40);
		BULLETMANAGER->bossCommonBulletFire("spbulletSmall1", bossCannon7.left + (bossCannon7.right - bossCannon7.left) / 2, bossCannon7.top + (bossCannon7.bottom - bossCannon7.top) / 2, ANGLE_300, 5, 40);
		BULLETMANAGER->bossCommonBulletFire("spbulletSmall1", bossCannon7.left + (bossCannon7.right - bossCannon7.left) / 2, bossCannon7.top + (bossCannon7.bottom - bossCannon7.top) / 2, ANGLE_330, 5, 40);
	}
	break;
	case 17:
	{
		BULLETMANAGER->bossHomingBulletFire("spBullet2", bossCannon3.left + (bossCannon3.right - bossCannon3.left) / 2, bossCannon3.top + (bossCannon3.bottom - bossCannon3.top) / 2,
			PLAYER->getPlayerRectX(), PLAYER->getPlayerRectY(), 3.0f, 50);
		BULLETMANAGER->bossHomingBulletFire("spBullet2", bossCannon6.left + (bossCannon6.right - bossCannon6.left) / 2, bossCannon6.top + (bossCannon6.bottom - bossCannon6.top) / 2,
			PLAYER->getPlayerRectX(), PLAYER->getPlayerRectY(), 3.0f, 50);
	}
	break;
	case 18:
	{
		BULLETMANAGER->bossCommonBulletFire("redMinionBullet", bossCannon4.left + (bossCannon4.right - bossCannon4.left) / 2, bossCannon4.top + (bossCannon4.bottom - bossCannon4.top) / 2, ANGLE_210, 5, 50);
		BULLETMANAGER->bossCommonBulletFire("redMinionBullet", bossCannon4.left + (bossCannon4.right - bossCannon4.left) / 2, bossCannon4.top + (bossCannon4.bottom - bossCannon4.top) / 2, ANGLE_240, 5, 50);
		BULLETMANAGER->bossCommonBulletFire("redMinionBullet", bossCannon4.left + (bossCannon4.right - bossCannon4.left) / 2, bossCannon4.top + (bossCannon4.bottom - bossCannon4.top) / 2, ANGLE_255, 5, 50);
		BULLETMANAGER->bossCommonBulletFire("redMinionBullet", bossCannon4.left + (bossCannon4.right - bossCannon4.left) / 2, bossCannon4.top + (bossCannon4.bottom - bossCannon4.top) / 2, ANGLE_270, 5, 50);
		BULLETMANAGER->bossCommonBulletFire("redMinionBullet", bossCannon4.left + (bossCannon4.right - bossCannon4.left) / 2, bossCannon4.top + (bossCannon4.bottom - bossCannon4.top) / 2, ANGLE_285, 5, 50);
		BULLETMANAGER->bossCommonBulletFire("redMinionBullet", bossCannon4.left + (bossCannon4.right - bossCannon4.left) / 2, bossCannon4.top + (bossCannon4.bottom - bossCannon4.top) / 2, ANGLE_300, 5, 50);
		BULLETMANAGER->bossCommonBulletFire("redMinionBullet", bossCannon4.left + (bossCannon4.right - bossCannon4.left) / 2, bossCannon4.top + (bossCannon4.bottom - bossCannon4.top) / 2, ANGLE_330, 5, 50);


		BULLETMANAGER->bossCommonBulletFire("redMinionBullet", bossCannon5.left + (bossCannon5.right - bossCannon5.left) / 2, bossCannon5.top + (bossCannon5.bottom - bossCannon5.top) / 2, ANGLE_210, 5, 50);
		BULLETMANAGER->bossCommonBulletFire("redMinionBullet", bossCannon5.left + (bossCannon5.right - bossCannon5.left) / 2, bossCannon5.top + (bossCannon5.bottom - bossCannon5.top) / 2, ANGLE_240, 5, 50);
		BULLETMANAGER->bossCommonBulletFire("redMinionBullet", bossCannon5.left + (bossCannon5.right - bossCannon5.left) / 2, bossCannon5.top + (bossCannon5.bottom - bossCannon5.top) / 2, ANGLE_255, 5, 50);
		BULLETMANAGER->bossCommonBulletFire("redMinionBullet", bossCannon5.left + (bossCannon5.right - bossCannon5.left) / 2, bossCannon5.top + (bossCannon5.bottom - bossCannon5.top) / 2, ANGLE_270, 5, 50);
		BULLETMANAGER->bossCommonBulletFire("redMinionBullet", bossCannon5.left + (bossCannon5.right - bossCannon5.left) / 2, bossCannon5.top + (bossCannon5.bottom - bossCannon5.top) / 2, ANGLE_285, 5, 50);
		BULLETMANAGER->bossCommonBulletFire("redMinionBullet", bossCannon5.left + (bossCannon5.right - bossCannon5.left) / 2, bossCannon5.top + (bossCannon5.bottom - bossCannon5.top) / 2, ANGLE_300, 5, 50);
		BULLETMANAGER->bossCommonBulletFire("redMinionBullet", bossCannon5.left + (bossCannon5.right - bossCannon5.left) / 2, bossCannon5.top + (bossCannon5.bottom - bossCannon5.top) / 2, ANGLE_330, 5, 50);
	}
	break;
	case 19:
	{
		for (m_viBoss = m_vBoss.begin(); m_viBoss != m_vBoss.end(); ++m_viBoss)
		{
			BULLETMANAGER->bossCommonBulletFire("blueBullet", (*m_viBoss)->getBossX(), (*m_viBoss)->getBossY(), ANGLE_15, 5, 10);
			BULLETMANAGER->bossCommonBulletFire("blueBullet", (*m_viBoss)->getBossX(), (*m_viBoss)->getBossY(), ANGLE_45, 5, 10);
			BULLETMANAGER->bossCommonBulletFire("blueBullet", (*m_viBoss)->getBossX(), (*m_viBoss)->getBossY(), ANGLE_75, 5, 10);
			BULLETMANAGER->bossCommonBulletFire("blueBullet", (*m_viBoss)->getBossX(), (*m_viBoss)->getBossY(), ANGLE_105, 5, 10);
			BULLETMANAGER->bossCommonBulletFire("blueBullet", (*m_viBoss)->getBossX(), (*m_viBoss)->getBossY(), ANGLE_135, 5, 10);
			BULLETMANAGER->bossCommonBulletFire("blueBullet", (*m_viBoss)->getBossX(), (*m_viBoss)->getBossY(), ANGLE_165, 5, 10);
			BULLETMANAGER->bossCommonBulletFire("blueBullet", (*m_viBoss)->getBossX(), (*m_viBoss)->getBossY(), ANGLE_195, 5, 10);
			BULLETMANAGER->bossCommonBulletFire("blueBullet", (*m_viBoss)->getBossX(), (*m_viBoss)->getBossY(), ANGLE_225, 5, 10);
			BULLETMANAGER->bossCommonBulletFire("blueBullet", (*m_viBoss)->getBossX(), (*m_viBoss)->getBossY(), ANGLE_255, 5, 10);
			BULLETMANAGER->bossCommonBulletFire("blueBullet", (*m_viBoss)->getBossX(), (*m_viBoss)->getBossY(), ANGLE_285, 5, 10);
			BULLETMANAGER->bossCommonBulletFire("blueBullet", (*m_viBoss)->getBossX(), (*m_viBoss)->getBossY(), ANGLE_315, 5, 10);
			BULLETMANAGER->bossCommonBulletFire("blueBullet", (*m_viBoss)->getBossX(), (*m_viBoss)->getBossY(), ANGLE_345, 5, 10);
		}

		BULLETMANAGER->bossCommonBulletFire("redBullet", bossCannon1.left + (bossCannon1.right - bossCannon1.left) / 2, bossCannon1.top + (bossCannon1.bottom - bossCannon1.top) / 2,   ANGLE_0, 5, 10);
		BULLETMANAGER->bossCommonBulletFire("redBullet", bossCannon1.left + (bossCannon1.right - bossCannon1.left) / 2, bossCannon1.top + (bossCannon1.bottom - bossCannon1.top) / 2,  ANGLE_30, 5, 10);
		BULLETMANAGER->bossCommonBulletFire("redBullet", bossCannon1.left + (bossCannon1.right - bossCannon1.left) / 2, bossCannon1.top + (bossCannon1.bottom - bossCannon1.top) / 2,  ANGLE_60, 5, 10);
		BULLETMANAGER->bossCommonBulletFire("redBullet", bossCannon1.left + (bossCannon1.right - bossCannon1.left) / 2, bossCannon1.top + (bossCannon1.bottom - bossCannon1.top) / 2,  ANGLE_90, 5, 10);
		BULLETMANAGER->bossCommonBulletFire("redBullet", bossCannon1.left + (bossCannon1.right - bossCannon1.left) / 2, bossCannon1.top + (bossCannon1.bottom - bossCannon1.top) / 2, ANGLE_120, 5, 10);
		BULLETMANAGER->bossCommonBulletFire("redBullet", bossCannon1.left + (bossCannon1.right - bossCannon1.left) / 2, bossCannon1.top + (bossCannon1.bottom - bossCannon1.top) / 2, ANGLE_150, 5, 10);
		BULLETMANAGER->bossCommonBulletFire("redBullet", bossCannon1.left + (bossCannon1.right - bossCannon1.left) / 2, bossCannon1.top + (bossCannon1.bottom - bossCannon1.top) / 2, ANGLE_180, 5, 10);
		BULLETMANAGER->bossCommonBulletFire("redBullet", bossCannon1.left + (bossCannon1.right - bossCannon1.left) / 2, bossCannon1.top + (bossCannon1.bottom - bossCannon1.top) / 2, ANGLE_210, 5, 10);
		BULLETMANAGER->bossCommonBulletFire("redBullet", bossCannon1.left + (bossCannon1.right - bossCannon1.left) / 2, bossCannon1.top + (bossCannon1.bottom - bossCannon1.top) / 2, ANGLE_240, 5, 10);
		BULLETMANAGER->bossCommonBulletFire("redBullet", bossCannon1.left + (bossCannon1.right - bossCannon1.left) / 2, bossCannon1.top + (bossCannon1.bottom - bossCannon1.top) / 2, ANGLE_270, 5, 10);
		BULLETMANAGER->bossCommonBulletFire("redBullet", bossCannon1.left + (bossCannon1.right - bossCannon1.left) / 2, bossCannon1.top + (bossCannon1.bottom - bossCannon1.top) / 2, ANGLE_300, 5, 10);
		BULLETMANAGER->bossCommonBulletFire("redBullet", bossCannon1.left + (bossCannon1.right - bossCannon1.left) / 2, bossCannon1.top + (bossCannon1.bottom - bossCannon1.top) / 2, ANGLE_330, 5, 10);

		BULLETMANAGER->bossLeftSpinBulletFire("greenBullet", bossCannon1.left + (bossCannon1.right - bossCannon1.left) / 2, bossCannon1.top + (bossCannon1.bottom - bossCannon1.top) / 2, 5);
		BULLETMANAGER->bossRightSpinBulletFire("purpleBullet", bossCannon8.left + (bossCannon8.right - bossCannon8.left) / 2, bossCannon8.top + (bossCannon8.bottom - bossCannon8.top) / 2, 5);

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
