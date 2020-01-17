#pragma once
#include "singletonBase.h"
#include "gameNode.h"
#include "enemyManager.h"
#include "player.h"	

struct tagCannon
{
	POINT center;
	POINT cannonEnd;
	int cannon;
	float angle;
};

class bulletManager : public gameNode, public singletonBase<bulletManager>
{
private:
	vector<bulletInfo> vPlayerCommonBullet;
	vector<bulletInfo>::iterator viPlayerCommonBullet;
	bulletInfo playerCommonBullet;

	vector<bulletInfo> vRedMinionBullet;
	vector<bulletInfo>::iterator viRedMinionBullet;
	bulletInfo redMinionBullet;
	tagCannon redMinionCannon;
	int redMinionBulletSpeed;

	vector<bulletInfo> vBlueMinionBullet;
	vector<bulletInfo>::iterator viBlueMinionBullet;
	bulletInfo blueMinionBullet;
	tagCannon blueMinionCannon;
	int blueMinionBulletSpeed;	

public:
	bulletManager();
	~bulletManager();

	HRESULT init();
	void release();
	void update();
	void render();

	void playerCommonBulletfire(float x, float y);
	void playerCommonBulletMove();
	void playerCommonBulletRender();
	
	void redMinionBulletfire(float x, float y);
	void redMinionBulletMove();
	void redMinionBulletRender();
	void playerCommonBulletRedMinionCollision();

	void blueMinionBulletfire(float x, float y);
	void blueMinionBulletMove();
	void blueMinionBulletRender();
	void playerCommonBulletBlueMinionCollision();
};

