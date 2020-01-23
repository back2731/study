#pragma once
#include"gameNode.h"
#include"bullet.h"

#define PLAYERSPEED 5

class rocket :public gameNode
{
private:

	image * _player;


	nuclear* _nuclear;
	missile* _missile;

	RECT rc;
	RECT _temp;
	int count;
	char str[256];
	int a;
public:
	rocket();
	~rocket();


	HRESULT init();
	void release();
	void update();
	void render();

	vector<tagBullet> getNuclearVBullet() { return _nuclear->getVBullet(); }
	vector<tagBullet>::iterator getNuclearVIBullet() { return _nuclear->getVIBullet(); }

	vector<tagBullet> getMissileVBullet() { return _missile->getVBullet(); }
	vector<tagBullet>::iterator getMissileVIBullet() { return _missile->getVIBullet(); }

	void deleteMissile(int num) { _missile->deleteMissile(num); }		
	void deleteNuclear(int num) { _nuclear->deleteNuclear(num); }		
	
};

