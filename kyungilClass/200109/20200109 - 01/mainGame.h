#pragma once
#include"gameNode.h"
#include "minimap.h"

class mainGame :  public gameNode
{
private:
	minimap* _minimap;

public:
	mainGame();
	~mainGame();

	virtual HRESULT init();	//�ʱ�ȭ
	virtual void release();//����
	virtual void update();//�����ϴ°�
	virtual void render(HDC hdc);//�׸��°�

	
};

