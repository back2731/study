#pragma once
#include"gameNode.h"
#include"rocket.h"
class mainGame :  public gameNode
{
private:

	rocket * _rocket;

public:
	mainGame();
	~mainGame();

	virtual HRESULT init();	//�ʱ�ȭ
	virtual void release();//����
	virtual void update();//�����ϴ°�
	virtual void render(HDC hdc);//�׸��°�

	
};

