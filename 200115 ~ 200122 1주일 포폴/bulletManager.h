#pragma once
#include "singletonBase.h"
#include "gameNode.h"
#include "enemyManager.h"
#include "player.h"	

enum bulletCase
{
	MINION_REDBULLET,
	MINION_BLUEBULLET, 
	MINION_GREENBULLET, 
	MINION_YELLOWBULLET
};

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

	vector<bulletInfo> vGreenMinionBullet;
	vector<bulletInfo>::iterator viGreenMinionBullet;
	bulletInfo greenMinionBullet;
	tagCannon greenMinionCannon;
	int greenMinionBulletSpeed;

	vector<bulletInfo> vYellowMinionBullet;
	vector<bulletInfo>::iterator viYellowMinionBullet;
	bulletInfo yellowMinionBullet;
	tagCannon yellowMinionCannon;
	int yellowMinionBulletSpeed;

	int collisionCheckNum;

public:
	bulletManager();
	~bulletManager();

	HRESULT init();
	void release();
	void update();
	void render();

	int collisionCheck() { return collisionCheckNum; }

	void playerCommonBulletFire(float x, float y);
	void playerCommonBulletMove();
	void playerCommonBulletRender();
	void playerBulletCollision();
	
	void minionSpinBulletFire(int bulletKind, float x, float y);
	void minionSpinBulletMove(int bulletKind);
	void minionSpinBulletRender(int bulletKind);

	void minionCommonBulletFire(int bulletKind, float x, float y, float angle);
	void minionCommonBulletMove(int bulletKind);
	void minionCommonBulletRender(int bulletKind);

	//void minionHomingBulletFire(int bulletKind, float x, float y);
	//void minionHomingBulletMove(int bulletKind);
	//void minionHomingBulletRender(int bulletKind);

	void minionBulletCollision();
	void redBulletPlayerCollision();
	void blueBulletPlayerCollision();
	void greenBulletPlayerCollision();
	void yellowBulletPlayerCollision();

	void playerCommonBulletRedMinionCollision();
	void playerCommonBulletBlueMinionCollision();	
	void playerCommonBulletGreenMinionCollision();
	void playerCommonBulletYellowMinionCollision();
};

