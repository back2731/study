#pragma once
#include"gameNode.h"
#include"rocket.h"
#include"enemyManager.h"
class mainGame :  public gameNode
{
private:

	rocket * _rocket;
	enemyManager* _enemyManager;
public:
	mainGame();
	~mainGame();

	virtual HRESULT init();	//�ʱ�ȭ
	virtual void release();//����
	virtual void update();//�����ϴ°�
	virtual void render(/*HDC hdc*/);//�׸��°�

	
};

