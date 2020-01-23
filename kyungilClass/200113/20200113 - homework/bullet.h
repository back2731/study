#pragma once
#include"gameNode.h"

class bullet  :public gameNode
{
private:

	vector<tagBullet> _vBullet;
	vector<tagBullet>::iterator _viBullet;


	const char* _imageName;
	float _range;
	int _bulletMax;

public:
	bullet();
	~bullet();

	HRESULT init(char* imageName,int bulletMax, float range);
	void release();
	void update();
	void render();

	void fire(float x, float y, float angle, float speed);
	void move();
};
class missile : public gameNode
{
private:
	vector<tagBullet> _vBullet;
	vector<tagBullet>::iterator _viBullet;

private:

	float _range;

public:


	missile();
	~missile();

	HRESULT init(int bulletMax, float range);
	void release();
	void update();
	void render();

	//발사
	void fire(float x, float y);
	//움직여라
	void move();

	void deleteMissile(int num);

	vector<tagBullet> getVBullet() { return _vBullet; }
	vector<tagBullet>::iterator getVIBullet() { return _viBullet; }
};
class nuclear : public gameNode
{

private:

	vector<tagBullet> _vBullet;
	vector<tagBullet>::iterator _viBullet;

	int _missileMax;
	float _range;
	tagBullet bullet;

public:

	nuclear();
	~nuclear();

	HRESULT init();
	void release();
	void update();
	void render();

	void fire(float x, float y, float angle);
	void move();

	void deleteNuclear(int num);

	vector<tagBullet> getVBullet() { return _vBullet; }
	vector<tagBullet>::iterator getVIBullet() { return _viBullet; }

};
