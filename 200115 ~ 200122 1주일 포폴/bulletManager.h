#pragma once
#include "gameNode.h"

struct tagCannon
{
	POINT center;
	POINT cannonEnd;
	int cannon;
	float angle;
};
class bulletManager : gameNode
{
private:
	vector<bulletInfo> vPlayerCommonBullet;
	vector<bulletInfo>::iterator viPlayerCommonBullet;

	vector<bulletInfo> vRedMinionBullet;
	vector<bulletInfo>::iterator viRedMinionBullet;

	bulletInfo playerCommonBullet;

	bulletInfo redMinionBullet;
	tagCannon redMinionCannon;

	int bulletSpeed;

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
};

