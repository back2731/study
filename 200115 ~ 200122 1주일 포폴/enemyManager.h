#pragma once
#include "gameNode.h"
#include "bulletManager.h"
#include "redMinion.h"

class enemyManager : public gameNode
{
private:

	typedef vector<redMinion*> vRedMinion;
	typedef vector<redMinion*>::iterator viRedMinion;

private:

	bulletManager* enemyBullet;

	vRedMinion	m_vRedMinion;
	viRedMinion	m_viRedMinion;

	redMinion* m_redMinion;

public:
	enemyManager();
	~enemyManager();

	HRESULT init();
	void release();
	void update();
	void render();


	void redMinionUpdate();
	void redMinionRender();
	void setRedMinion();
	void redMinionBulletFire();

	vRedMinion getVMinion() { return m_vRedMinion; }
	viRedMinion	getViMinion() { return m_viRedMinion; }

	void deleteEnemy(int num);
};

