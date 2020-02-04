#pragma once
#include "singletonBase.h"

class itemManager : public singletonBase<itemManager>
{
private:
	vector<int> vScoreItem;
	vector<int>::iterator viScoreItem;
	
	vector<int> vPowerUpItem;
	vector<int>::iterator viPowerUpItem;
	
	vector<int> vLifeUpItem;
	vector<int>::iterator viLifeUpItem;


public:
	itemManager();
	~itemManager();

	void outPutItem();
	void playerCommonBulletRedMinionCollision();
	void playerCommonBulletBlueMinionCollision();
	void playerCommonBulletGreenMinionCollision();
	void playerCommonBulletYellowMinionCollision();
	void playerCommonBulletBossCollision();
	void playerHomingBulletRedMinionCollision();
	void playerHomingBulletBlueMinionCollision();
	void playerHomingBulletGreenMinionCollision();
	void playerHomingBulletYellowMinionCollision();
	void playerHomingBulletBossCollision();

};

