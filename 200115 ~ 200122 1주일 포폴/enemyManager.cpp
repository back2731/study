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
	return S_OK;
}

void enemyManager::release()
{
	SAFE_DELETE(m_redMinion);
	SAFE_DELETE(m_blueMinion);
}

void enemyManager::update()
{
	count++;
	if (count == 1)
	{
		setRedMinion(0);
		setBlueMinion(0);
		setGreenMinion(0);
		setYellowMinion(0);
	}
	if (count >= 0/* && count < 500*/)
	{
		redMinionUpdate(0);
		blueMinionUpdate(0);
		greenMinionUpdate(0);
		yellowMinionUpdate(0);
	}
	//if (count == 500)
	//{
	//	setRedMinion(0);
	//	setBlueMinion(0);		
	//	setGreenMinion(0);
	//	setYellowMinion(0);
	//}
	//if (count >= 500)
	//{
	//	redMinionUpdate(0);
	//	blueMinionUpdate(0);
	//	greenMinionUpdate(0);
	//	yellowMinionUpdate(0);
	//}
	BULLETMANAGER->minionBulletCollision();
}

void enemyManager::render()
{
	redMinionRender(0);
	blueMinionRender(0);
	greenMinionRender(0);
	yellowMinionRender(0);
}

void enemyManager::redMinionUpdate(int pattern)
{
	switch (pattern)
	{
	case 0:		// 레드 미니언 회전 탄
	{
		for (m_viRedMinion = m_vRedMinion.begin(); m_viRedMinion != m_vRedMinion.end(); ++m_viRedMinion)
		{
			(*m_viRedMinion)->update();
		}
		redMinionBulletFire(0);
		BULLETMANAGER->minionSpinBulletMove(0);
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
		BULLETMANAGER->minionSpinBulletRender(0);

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
	case 0:		// 레드 미니언 회전 탄
	{
		for (int i = 0; i < 3; i++)
		{
			m_redMinion = new redMinion;
			m_redMinion->init("redMinion", PointMake(200 + (i * 200), 150));
			m_vRedMinion.push_back(m_redMinion);
		}
		for (int i = 3; i < 6; i++)
		{
			m_redMinion = new redMinion;
			m_redMinion->init("redMinion", PointMake(200 + ((i - 3) * 200), 250));
			m_vRedMinion.push_back(m_redMinion);
		}
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
			BULLETMANAGER->minionSpinBulletFire(0, (*m_viRedMinion)->getRedMinionX(), (*m_viRedMinion)->getRedMinionY());
			/*BULLETMANAGER->minionCommonBulletFire(0, (*m_viRedMinion)->getRedMinionX(), (*m_viRedMinion)->getRedMinionY(), ANGLE_0);
			BULLETMANAGER->minionCommonBulletFire(0, (*m_viRedMinion)->getRedMinionX(), (*m_viRedMinion)->getRedMinionY(), ANGLE_30);
			BULLETMANAGER->minionCommonBulletFire(0, (*m_viRedMinion)->getRedMinionX(), (*m_viRedMinion)->getRedMinionY(), ANGLE_60);
			BULLETMANAGER->minionCommonBulletFire(0, (*m_viRedMinion)->getRedMinionX(), (*m_viRedMinion)->getRedMinionY(), ANGLE_90);
			BULLETMANAGER->minionCommonBulletFire(0, (*m_viRedMinion)->getRedMinionX(), (*m_viRedMinion)->getRedMinionY(), ANGLE_120);
			BULLETMANAGER->minionCommonBulletFire(0, (*m_viRedMinion)->getRedMinionX(), (*m_viRedMinion)->getRedMinionY(), ANGLE_150);
			BULLETMANAGER->minionCommonBulletFire(0, (*m_viRedMinion)->getRedMinionX(), (*m_viRedMinion)->getRedMinionY(), ANGLE_180);
			BULLETMANAGER->minionCommonBulletFire(0, (*m_viRedMinion)->getRedMinionX(), (*m_viRedMinion)->getRedMinionY(), ANGLE_210);
			BULLETMANAGER->minionCommonBulletFire(0, (*m_viRedMinion)->getRedMinionX(), (*m_viRedMinion)->getRedMinionY(), ANGLE_240);
			BULLETMANAGER->minionCommonBulletFire(0, (*m_viRedMinion)->getRedMinionX(), (*m_viRedMinion)->getRedMinionY(), ANGLE_270);
			BULLETMANAGER->minionCommonBulletFire(0, (*m_viRedMinion)->getRedMinionX(), (*m_viRedMinion)->getRedMinionY(), ANGLE_300);
			BULLETMANAGER->minionCommonBulletFire(0, (*m_viRedMinion)->getRedMinionX(), (*m_viRedMinion)->getRedMinionY(), ANGLE_330);		*/	
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
		for (m_viBlueMinion = m_vBlueMinion.begin(); m_viBlueMinion != m_vBlueMinion.end(); ++m_viBlueMinion)
		{
			(*m_viBlueMinion)->update();
		}

		blueMinionBulletFire(0);

		BULLETMANAGER->minionSpinBulletMove(1);
	}
		break;
	default:
		break;
	}
}

void enemyManager::blueMinionRender(int pattern)
{
	switch (pattern)
	{
	case 0:		// 블루 미니언 회전 탄
	{
		BULLETMANAGER->minionSpinBulletRender(1);
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
		for (int i = 0; i < 3; i++)
		{
			m_blueMinion = new blueMinion;
			m_blueMinion->init("blueMinion", PointMake(250 + (i * 200), 150));
			m_vBlueMinion.push_back(m_blueMinion);
		}
		for (int i = 3; i < 6; i++)
		{
			m_blueMinion = new blueMinion;
			m_blueMinion->init("blueMinion", PointMake(250 + ((i - 3) * 200), 250));
			m_vBlueMinion.push_back(m_blueMinion);
		}
	}
		break;
	default:
		break;
	}
}

void enemyManager::blueMinionBulletFire(int pattern)
{
	switch (pattern)
	{
	case 0:		// 블루 미니언 회전 탄
	{
		for (m_viBlueMinion = m_vBlueMinion.begin(); m_viBlueMinion != m_vBlueMinion.end(); ++m_viBlueMinion)
		{
			BULLETMANAGER->minionSpinBulletFire(1, (*m_viBlueMinion)->getBlueMinionX(), (*m_viBlueMinion)->getBlueMinionY());
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
	case 0:		// 그린 미니언 회전 탄
	{
		for (m_viGreenMinion = m_vGreenMinion.begin(); m_viGreenMinion != m_vGreenMinion.end(); ++m_viGreenMinion)
		{
			(*m_viGreenMinion)->update();
		}

		greenMinionBulletFire(0);

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
			m_greenMinion->init("greenMinion", PointMake(250 + (i * 200), 350));
			m_vGreenMinion.push_back(m_greenMinion);
		}
		for (int i = 3; i < 6; i++)
		{
			m_greenMinion = new greenMinion;
			m_greenMinion->init("greenMinion", PointMake(250 + ((i - 3) * 200), 450));
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
	case 0:		// 그린 미니언 회전 탄
	{
		for (m_viGreenMinion = m_vGreenMinion.begin(); m_viGreenMinion != m_vGreenMinion.end(); ++m_viGreenMinion)
		{
			BULLETMANAGER->minionSpinBulletFire(2, (*m_viGreenMinion)->getGreenMinionX(), (*m_viGreenMinion)->getGreenMinionY());
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
		for (m_viYellowMinion = m_vYellowMinion.begin(); m_viYellowMinion != m_vYellowMinion.end(); ++m_viYellowMinion)
		{
			(*m_viYellowMinion)->update();
		}
		yellowMinionBulletFire(0);
		BULLETMANAGER->minionSpinBulletMove(3);
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
		BULLETMANAGER->minionSpinBulletRender(3);
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
	case 0:		// 레드 미니언 회전 탄
	{
		for (int i = 0; i < 3; i++)
		{
			m_yellowMinion = new yellowMinion;
			m_yellowMinion->init("yellowMinion", PointMake(200 + (i * 200), 350));
			m_vYellowMinion.push_back(m_yellowMinion);
		}
		for (int i = 3; i < 6; i++)
		{
			m_yellowMinion = new yellowMinion;
			m_yellowMinion->init("yellowMinion", PointMake(200 + ((i - 3) * 200), 450));
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
			BULLETMANAGER->minionSpinBulletFire(3, (*m_viYellowMinion)->getYellowMinionX(), (*m_viYellowMinion)->getYellowMinionY());
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
