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

public:
	rocket();
	~rocket();

	HRESULT init();
	void release();
	void update();
	void render();

};

