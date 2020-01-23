#pragma once
#include"gameNode.h"

struct tagBullet
{
	image* bulletImage;
	RECT rc;
	float x, y;
	float fireX, fireY;
	float radius;
	float angle;
	float speed;
	bool fire;
	int count;
};

class bullet
{
public:
	bullet();
	~bullet();
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

};
class nuclear : public gameNode
{
private:

	vector<tagBullet> _vBullet;
	vector<tagBullet>::iterator _viBullet; 

	int _missileMax;
	float _range;
public:

	nuclear();
	~nuclear();
	HRESULT init(int bulletMax, float range);
	void release();
	void update();
	void render();

	//발사
	void fire(float x, float y);
	//움직여라
	void move();

	vector <tagBullet> getVBullet() { return _vBullet; }
	vector <tagBullet>::iterator getVIBullet() { return _viBullet; }
	
};
