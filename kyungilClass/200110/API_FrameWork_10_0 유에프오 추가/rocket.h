#pragma once
#include"gameNode.h"
#include"bullet.h"

#define PLAYERSPEED 5

class rocket :public gameNode
{
private:

	image * _player;

	missile* _missile;

	nuclear* _nuclear;

	RECT rc;
	RECT _temp;

public:
	rocket();
	~rocket();

	HRESULT init();
	void release();
	void update();
	void render();

	//vector<tagBullet> getNuclearVBullet() { return _nuclear->getVBullet(); }
	//안되면 써보기
	vector<tagBullet>& getNuclearVBullet() { return _nuclear->getVBullet(); }
	vector<tagBullet>::iterator getNuclearVIBullet() { return _nuclear->getVIBullet(); }

	vector<tagBullet>& getMissileVBullet() { return _missile->getVBullet(); }
	vector<tagBullet>::iterator getMissileVIBullet() { return _missile->getVIBullet(); }
};

