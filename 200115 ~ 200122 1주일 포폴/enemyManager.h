#pragma once
#include "singletonBase.h"
#include "gameNode.h"
#include "bulletManager.h"
#include "player.h"	

#include "redMinion.h"
#include "blueMinion.h"

class enemyManager : public gameNode, public singletonBase<enemyManager>
{
private:

	typedef vector<redMinion*> vRedMinion;
	typedef vector<redMinion*>::iterator viRedMinion;

	typedef vector<blueMinion*> vBlueMinion;
	typedef vector<blueMinion*>::iterator viBlueMinion;

private:

	vRedMinion		m_vRedMinion;
	viRedMinion		m_viRedMinion;
	redMinion*		m_redMinion;

	vBlueMinion		m_vBlueMinion;
	viBlueMinion	m_viBlueMinion;
	blueMinion*		m_blueMinion;

	float rectX;
	float rectY;

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
	void deleteRedEnemy(int num);
	vRedMinion getVRedMinion() { return m_vRedMinion; }
	viRedMinion	getViRedMinion() { return m_viRedMinion; }

	void blueMinionUpdate();
	void blueMinionRender();
	void setBlueMinion();
	void blueMinionBulletFire();
	void deleteBlueEnemy(int num);
	vBlueMinion getVBlueMinion() { return m_vBlueMinion; }
	viBlueMinion getViBlueMinion() { return m_viBlueMinion; }

};

