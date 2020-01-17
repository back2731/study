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
	setRedMinion();
	setBlueMinion();
	return S_OK;
}

void enemyManager::release()
{
	SAFE_DELETE(m_redMinion);
	SAFE_DELETE(m_blueMinion);
}

void enemyManager::update()
{
	redMinionUpdate();
	blueMinionUpdate();
}

void enemyManager::render()
{
	redMinionRender();
	blueMinionRender();
}

void enemyManager::redMinionUpdate()
{
	for (m_viRedMinion = m_vRedMinion.begin(); m_viRedMinion != m_vRedMinion.end(); ++m_viRedMinion)
	{
		(*m_viRedMinion)->update();
	}	
	
	redMinionBulletFire();

	BULLETMANAGER->redMinionBulletMove();
}

void enemyManager::redMinionRender()
{
	BULLETMANAGER->redMinionBulletRender();
	for (m_viRedMinion = m_vRedMinion.begin(); m_viRedMinion != m_vRedMinion.end(); ++m_viRedMinion)
	{
		(*m_viRedMinion)->render();
	}
}

void enemyManager::setRedMinion()
{
	for (int i = 0; i < 3; i++)
	{
		m_redMinion = new redMinion;
		m_redMinion->init("redMinion", PointMake(-400 + (i * 200), 150));
		m_vRedMinion.push_back(m_redMinion);
	}
	for (int i = 3; i < 6; i++)
	{
		m_redMinion = new redMinion;
		m_redMinion->init("redMinion", PointMake(-600 + ((i - 3) * 200), 250));
		m_vRedMinion.push_back(m_redMinion);
	}
}

void enemyManager::redMinionBulletFire()
{
	for (m_viRedMinion = m_vRedMinion.begin(); m_viRedMinion != m_vRedMinion.end(); ++m_viRedMinion)
	{
		BULLETMANAGER->redMinionBulletfire((*m_viRedMinion)->getRedMinionX(), (*m_viRedMinion)->getRedMinionY());
	}
}

void enemyManager::deleteRedEnemy(int num)
{
	m_vRedMinion.erase(m_vRedMinion.begin() + num);
}

void enemyManager::blueMinionUpdate()
{
	for (m_viBlueMinion = m_vBlueMinion.begin(); m_viBlueMinion != m_vBlueMinion.end(); ++m_viBlueMinion)
	{
		(*m_viBlueMinion)->update();
	}

	blueMinionBulletFire();

	BULLETMANAGER->blueMinionBulletMove();
}

void enemyManager::blueMinionRender()
{
	BULLETMANAGER->blueMinionBulletRender();
	for (m_viBlueMinion = m_vBlueMinion.begin(); m_viBlueMinion != m_vBlueMinion.end(); ++m_viBlueMinion)
	{
		(*m_viBlueMinion)->render();
	}
}

void enemyManager::setBlueMinion()
{
	for (int i = 0; i < 3; i++)
	{
		m_blueMinion = new blueMinion;
		m_blueMinion->init("blueMinion", PointMake(WINSIZEX + 400 + (i * 200), 150));
		m_vBlueMinion.push_back(m_blueMinion);
	}
	for (int i = 3; i < 6; i++)
	{
		m_blueMinion = new blueMinion;
		m_blueMinion->init("blueMinion", PointMake(WINSIZEX + 600 + ((i - 3) * 200), 250));
		m_vBlueMinion.push_back(m_blueMinion);
	}
}

void enemyManager::blueMinionBulletFire()
{
	for (m_viBlueMinion = m_vBlueMinion.begin(); m_viBlueMinion != m_vBlueMinion.end(); ++m_viBlueMinion)
	{
		BULLETMANAGER->blueMinionBulletfire((*m_viBlueMinion)->getBlueMinionX(), (*m_viBlueMinion)->getBlueMinionY());
	}
}

void enemyManager::deleteBlueEnemy(int num)
{
	m_vBlueMinion.erase(m_vBlueMinion.begin() + num);

}
