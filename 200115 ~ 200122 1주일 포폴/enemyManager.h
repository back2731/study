#pragma once
#include "singletonBase.h"
#include "gameNode.h"
#include "bulletManager.h"
#include "player.h"	

#include "redMinion.h"
#include "blueMinion.h"
#include "greenMinion.h"
#include "yellowMinion.h"

class enemyManager : public gameNode, public singletonBase<enemyManager>
{
private:

	typedef vector<redMinion*> vRedMinion;
	typedef vector<redMinion*>::iterator viRedMinion;

	typedef vector<blueMinion*> vBlueMinion;
	typedef vector<blueMinion*>::iterator viBlueMinion;

	typedef vector<greenMinion*> vGreenMinion;
	typedef vector<greenMinion*>::iterator viGreenMinion;

	typedef vector<yellowMinion*> vYellowMinion;
	typedef vector<yellowMinion*>::iterator viYellowMinion;

private:

	vRedMinion		m_vRedMinion;
	viRedMinion		m_viRedMinion;
	redMinion*		m_redMinion;

	vBlueMinion		m_vBlueMinion;
	viBlueMinion	m_viBlueMinion;
	blueMinion*		m_blueMinion;

	vGreenMinion	m_vGreenMinion;
	viGreenMinion	m_viGreenMinion;
	greenMinion*	m_greenMinion;

	vYellowMinion	m_vYellowMinion;
	viYellowMinion	m_viYellowMinion;
	yellowMinion*	m_yellowMinion;
	
	float rectX;
	float rectY;

	int count;
	char str[256];

public:
	enemyManager();
	~enemyManager();

	HRESULT init();
	void release();
	void update();
	void render();

	void redMinionUpdate(int pattern);
	void redMinionRender(int pattern);
	void setRedMinion(int pattern);
	void redMinionBulletFire(int pattern);
	void deleteRedEnemy(int num);
	vRedMinion getVRedMinion() { return m_vRedMinion; }
	viRedMinion	getViRedMinion() { return m_viRedMinion; }

	void blueMinionUpdate(int pattern);
	void blueMinionRender(int pattern);
	void setBlueMinion(int pattern);
	void blueMinionBulletFire(int pattern);
	void deleteBlueEnemy(int num);
	vBlueMinion getVBlueMinion() { return m_vBlueMinion; }
	viBlueMinion getViBlueMinion() { return m_viBlueMinion; }

	void greenMinionUpdate(int pattern);
	void greenMinionRender(int pattern);
	void setGreenMinion(int pattern);
	void greenMinionBulletFire(int pattern);
	void deleteGreenEnemy(int num);
	vGreenMinion getVGreenMinion() { return m_vGreenMinion; }
	viGreenMinion getViGreenMinion() { return m_viGreenMinion; }

	void yellowMinionUpdate(int pattern);
	void yellowMinionRender(int pattern);
	void setYellowMinion(int pattern);
	void yellowMinionBulletFire(int pattern);
	void deleteYellowEnemy(int num);
	vYellowMinion getVYellowMinion() { return m_vYellowMinion; }
	viYellowMinion getViYellowMinion() { return m_viYellowMinion; }
};

