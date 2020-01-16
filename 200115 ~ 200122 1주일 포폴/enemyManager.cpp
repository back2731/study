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
	enemyBullet = new bulletManager;
	return S_OK;
}

void enemyManager::release()
{
	SAFE_DELETE(m_redMinion);
	SAFE_DELETE(enemyBullet);
}

void enemyManager::update()
{
	redMinionUpdate();
}

void enemyManager::render()
{
	redMinionRender();
}

void enemyManager::redMinionUpdate()
{

	m_viRedMinion = m_vRedMinion.begin();

	for (m_viRedMinion; m_viRedMinion != m_vRedMinion.end(); ++m_viRedMinion)
	{
		(*m_viRedMinion)->update();
	}	

	redMinionBulletFire();

	enemyBullet->redMinionBulletMove();
}

void enemyManager::redMinionRender()
{
	m_viRedMinion = m_vRedMinion.begin();

	for (m_viRedMinion; m_viRedMinion != m_vRedMinion.end(); ++m_viRedMinion)
	{
		(*m_viRedMinion)->render();
	}
	enemyBullet->redMinionBulletRender();
}

void enemyManager::setRedMinion()
{
	for (int i = 0; i < 4; i++)
	{
		m_redMinion = new redMinion;
		m_redMinion->init("redMinion", PointMake(300 + i*50, 250));
		m_vRedMinion.push_back(m_redMinion);
	}
}

void enemyManager::redMinionBulletFire()
{
	m_viRedMinion = m_vRedMinion.begin();

	for (m_viRedMinion; m_viRedMinion != m_vRedMinion.end(); ++m_viRedMinion)
	{
		enemyBullet->redMinionBulletfire((*m_viRedMinion)->getRedMinionX(), (*m_viRedMinion)->getRedMinionY());
	}
}

void enemyManager::deleteEnemy(int num)
{
}
