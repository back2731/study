#pragma once
#include"gameNode.h"
#include"circus.h"
class mainGame :  public gameNode
{
private:

	circus * _circus;


public:
	mainGame();
	~mainGame();

	virtual HRESULT init();	//�ʱ�ȭ
	virtual void release();//����
	virtual void update();//�����ϴ°�
	virtual void render(HDC hdc);//�׸��°�

	
};

