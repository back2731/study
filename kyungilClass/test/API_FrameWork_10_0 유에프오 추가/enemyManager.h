#pragma once
#include"gameNode.h"
#include"bullet.h"
#include"minion.h"
class enemyManager :  public gameNode
{
private:

	typedef vector<enemy*> vEnemy;
	typedef vector<enemy*>::iterator viEnemy;

private:

	vEnemy		_vMinion;
	viEnemy		_viMinion;
	bullet*     _bullet;

public:
	enemyManager();
	~enemyManager();

	HRESULT init();
	void release();
	void update();
	void render();


	void setMinion();
	void minionBulletFire();


	vEnemy		getVMinion() { return _vMinion; }
	viEnemy		getViMinion() { return _viMinion; }



};

