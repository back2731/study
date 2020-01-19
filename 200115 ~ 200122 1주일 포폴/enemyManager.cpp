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
	update();		

	return S_OK;
}

void enemyManager::release()
{
	SAFE_DELETE(m_redMinion);
	SAFE_DELETE(m_blueMinion);
	SAFE_DELETE(m_greenMinion);
	SAFE_DELETE(m_yellowMinion);
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
	if (count >= 500)
	{
		greenMinionUpdate(0);
		greenMinionBulletFire(1);
		greenMinionBulletFire(2);
	}

	if (count == 600)
	{
		setYellowMinion(0);
	}
	if (count >= 600 && count <800)
	{
		yellowMinionUpdate(1);
	}
	if (count >= 800 && count < 1500)
	{
		yellowMinionUpdate(0);
	}
	if (count == 1000)
	{
		setBlueMinion(1);
	}
	if (count >= 900)
	{
		blueMinionUpdate(1);
	}
	BULLETMANAGER->minionBulletCollision();
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
	if (count >= 600 && count < 1200)
	{
		yellowMinionRender(0);
	}

	if (count >= 900)
	{
		blueMinionRender(1);
	}

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

	}
	break;
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
			for (int i = 0; i < 4; i++)
			{
				m_redMinion = new redMinion;
				m_redMinion->init("redMinion", PointMake(400, 500 + i));
				m_vRedMinion.push_back(m_redMinion);
			}
			break;
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
			BULLETMANAGER->minionHomingBulletFire(0, (*m_viRedMinion)->getRedMinionX(), (*m_viRedMinion)->getRedMinionY(),
				PLAYER->getPlayerRectX(), PLAYER->getPlayerRectY(), 4.0f, 80);
		}
	}
		break;
	case 1:
	{
		for (m_viRedMinion = m_vRedMinion.begin(); m_viRedMinion != m_vRedMinion.end(); ++m_viRedMinion)
		{
			BULLETMANAGER->minionCommonBulletFire(0, (*m_viRedMinion)->getRedMinionX(), (*m_viRedMinion)->getRedMinionY(), ANGLE_210, 5.0f, 80);
			BULLETMANAGER->minionCommonBulletFire(0, (*m_viRedMinion)->getRedMinionX(), (*m_viRedMinion)->getRedMinionY(), ANGLE_225, 5.0f, 80);
			BULLETMANAGER->minionCommonBulletFire(0, (*m_viRedMinion)->getRedMinionX(), (*m_viRedMinion)->getRedMinionY(), ANGLE_240, 5.0f, 80);
			BULLETMANAGER->minionCommonBulletFire(0, (*m_viRedMinion)->getRedMinionX(), (*m_viRedMinion)->getRedMinionY(), ANGLE_255, 5.0f, 80);
			BULLETMANAGER->minionCommonBulletFire(0, (*m_viRedMinion)->getRedMinionX(), (*m_viRedMinion)->getRedMinionY(), ANGLE_270, 5.0f, 80);
			BULLETMANAGER->minionCommonBulletFire(0, (*m_viRedMinion)->getRedMinionX(), (*m_viRedMinion)->getRedMinionY(), ANGLE_285, 5.0f, 80);
			BULLETMANAGER->minionCommonBulletFire(0, (*m_viRedMinion)->getRedMinionX(), (*m_viRedMinion)->getRedMinionY(), ANGLE_300, 5.0f, 80);
			BULLETMANAGER->minionCommonBulletFire(0, (*m_viRedMinion)->getRedMinionX(), (*m_viRedMinion)->getRedMinionY(), ANGLE_315, 5.0f, 80);
			BULLETMANAGER->minionCommonBulletFire(0, (*m_viRedMinion)->getRedMinionX(), (*m_viRedMinion)->getRedMinionY(), ANGLE_330, 5.0f, 80);
		}
	}
	break;
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
			m_blueMinion->init("blueMinion", PointMake(275 + (i * 250), -150));
			m_vBlueMinion.push_back(m_blueMinion);
		}
		for (int i = 2; i < 5; i++)
		{
			m_blueMinion = new blueMinion;
			m_blueMinion->init("blueMinion", PointMake(150 + ((i - 2) * 250), -50));
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
			BULLETMANAGER->minionHomingBulletFire(1, (*m_viBlueMinion)->getBlueMinionX(), (*m_viBlueMinion)->getBlueMinionY(), 
				PLAYER->getPlayerRectX(), PLAYER->getPlayerRectY(), 4.0f, 80);
		}
	}
		break;
	case 1:		
	{
		for (m_viBlueMinion = m_vBlueMinion.begin(); m_viBlueMinion != m_vBlueMinion.end(); ++m_viBlueMinion)
		{
			BULLETMANAGER->minionCommonBulletFire(1, (*m_viBlueMinion)->getBlueMinionX(), (*m_viBlueMinion)->getBlueMinionY(), ANGLE_0, 5.0f, 10);
			BULLETMANAGER->minionCommonBulletFire(1, (*m_viBlueMinion)->getBlueMinionX(), (*m_viBlueMinion)->getBlueMinionY(), ANGLE_90, 5.0f, 10);
			BULLETMANAGER->minionCommonBulletFire(1, (*m_viBlueMinion)->getBlueMinionX(), (*m_viBlueMinion)->getBlueMinionY(), ANGLE_180, 5.0f, 10);
			BULLETMANAGER->minionCommonBulletFire(1, (*m_viBlueMinion)->getBlueMinionX(), (*m_viBlueMinion)->getBlueMinionY(), ANGLE_270, 5.0f, 10);
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
			m_greenMinion->init("greenMinion", PointMake(200 + (i * 200), -150));
			m_vGreenMinion.push_back(m_greenMinion);
		}
		for (int i = 3; i < 6; i++)
		{
			m_greenMinion = new greenMinion;
			m_greenMinion->init("greenMinion", PointMake(200 + ((i - 3) * 200), -250));
			m_vGreenMinion.push_back(m_greenMinion);
		}
	}
	break;
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
			BULLETMANAGER->minionCommonBulletFire(2, (*m_viGreenMinion)->getGreenMinionX(), (*m_viGreenMinion)->getGreenMinionY(), ANGLE_240, 5.0f, 50);
			BULLETMANAGER->minionCommonBulletFire(2, (*m_viGreenMinion)->getGreenMinionX(), (*m_viGreenMinion)->getGreenMinionY(), ANGLE_270, 5.0f, 50);
			BULLETMANAGER->minionCommonBulletFire(2, (*m_viGreenMinion)->getGreenMinionX(), (*m_viGreenMinion)->getGreenMinionY(), ANGLE_300, 5.0f, 50);
		}
	}
	break;
	case 1:
	{
		for (m_viGreenMinion = m_vGreenMinion.begin(); m_viGreenMinion != m_vGreenMinion.end(); ++m_viGreenMinion)
		{
			BULLETMANAGER->minionSpinBulletFire(2, (*m_viGreenMinion)->getGreenMinionX(), (*m_viGreenMinion)->getGreenMinionY(), 5);
		}
	}
	case 2:
	{
		for (m_viGreenMinion = m_vGreenMinion.begin(); m_viGreenMinion != m_vGreenMinion.end(); ++m_viGreenMinion)
		{
			BULLETMANAGER->minionSpinBulletFire(3, (*m_viGreenMinion)->getGreenMinionX(), (*m_viGreenMinion)->getGreenMinionY(), 5);
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
	case 1:		// 옐로우 미니언 회전 탄
	{
		for (int i = 0; i < m_vYellowMinion.size(); i++)
		{
			m_vYellowMinion[i]->update();
			m_vYellowMinion[i]->move(1);

			if (-WINSIZEX >= m_vYellowMinion[i]->getRect().right || WINSIZEY * 2 <= m_vYellowMinion[i]->getRect().top ||
				WINSIZEX * 2 <= m_vYellowMinion[i]->getRect().left || -WINSIZEY > m_vYellowMinion[i]->getRect().bottom)
			{
				m_vYellowMinion.erase(m_vYellowMinion.begin() + i);
			}
		}
		yellowMinionBulletFire(0);
		BULLETMANAGER->minionCommonBulletMove(3);
	}
	break;
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
			BULLETMANAGER->minionCommonBulletFire(3, (*m_viYellowMinion)->getYellowMinionX(), (*m_viYellowMinion)->getYellowMinionY(), ANGLE_210, 5.0f, 80);
			BULLETMANAGER->minionCommonBulletFire(3, (*m_viYellowMinion)->getYellowMinionX(), (*m_viYellowMinion)->getYellowMinionY(), ANGLE_225, 5.0f, 80);
			BULLETMANAGER->minionCommonBulletFire(3, (*m_viYellowMinion)->getYellowMinionX(), (*m_viYellowMinion)->getYellowMinionY(), ANGLE_240, 5.0f, 80);
			BULLETMANAGER->minionCommonBulletFire(3, (*m_viYellowMinion)->getYellowMinionX(), (*m_viYellowMinion)->getYellowMinionY(), ANGLE_255, 5.0f, 80);
			BULLETMANAGER->minionCommonBulletFire(3, (*m_viYellowMinion)->getYellowMinionX(), (*m_viYellowMinion)->getYellowMinionY(), ANGLE_270, 5.0f, 80);
			BULLETMANAGER->minionCommonBulletFire(3, (*m_viYellowMinion)->getYellowMinionX(), (*m_viYellowMinion)->getYellowMinionY(), ANGLE_285, 5.0f, 80);
			BULLETMANAGER->minionCommonBulletFire(3, (*m_viYellowMinion)->getYellowMinionX(), (*m_viYellowMinion)->getYellowMinionY(), ANGLE_300, 5.0f, 80);
			BULLETMANAGER->minionCommonBulletFire(3, (*m_viYellowMinion)->getYellowMinionX(), (*m_viYellowMinion)->getYellowMinionY(), ANGLE_315, 5.0f, 80);
			BULLETMANAGER->minionCommonBulletFire(3, (*m_viYellowMinion)->getYellowMinionX(), (*m_viYellowMinion)->getYellowMinionY(), ANGLE_330, 5.0f, 80);
		}
	}
	break;
	default:
		break;
	}
}

void enemyManager::deleteYellowEnemy(int num)
{
	m_vYellowMinion.erase(m_vYellowMinion.begin() + num);
}
