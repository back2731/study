#pragma once
#include "singletonBase.h"
#include "gameNode.h"
#include "bulletManager.h"
#include "player.h"	

#include "redMinion.h"
#include "blueMinion.h"
#include "greenMinion.h"
#include "yellowMinion.h"

#include "boss.h"

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

	typedef vector<boss*> vBoss;
	typedef vector<boss*>::iterator viBoss;

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

	vBoss			m_vBoss;
	viBoss			m_viBoss;
	boss*			m_Boss;

	image*			bossCannonImage;
	RECT			bossCannon;
	int				frameCount;
	int				currentFrameX;
	int				currentFrameY;
	int				alphaValue;

	float rectX;
	float rectY;

	int count;
	char str[256];

	bool change;

public:
	enemyManager();
	~enemyManager();

	HRESULT init();
	void release();
	void update();
	void render();

	bool mapChange();

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

	void bossUpdate(int pattern);
	void bossRender(int pattern);
	void setBoss();
	void bossBulletFire(int pattern);
	void deleteBoss(int num);
	vBoss getVBoss() { return m_vBoss; }
	viBoss getViBoss() { return m_viBoss; }

};

