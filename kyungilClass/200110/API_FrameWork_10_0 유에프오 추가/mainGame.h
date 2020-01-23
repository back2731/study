#pragma once
#include"gameNode.h"
#include"rocket.h"
#include"enemyManager.h"
class mainGame :  public gameNode
{
private:

	rocket*			_rocket;
	enemyManager*	_enemyManager;
	RECT			_temp;
	char			str[128];

private:
	vector<tagBullet> _vRocket;
	vector<tagBullet>::iterator _viRocket;

	vector<enemy*> _vEnemyManager;
	vector<enemy*>::iterator _viEnemyManager;

public:
	mainGame();
	~mainGame();

	virtual HRESULT init();	//�ʱ�ȭ
	virtual void release();//����
	virtual void update();//�����ϴ°�
	virtual void render(/*HDC hdc*/);//�׸��°�

	bool isCollision();
};

