#pragma once
#include"gameNode.h"
#define BOX 5

class mainGame :  public gameNode
{
private:
	
	RECT _body;
	RECT _bullet;

	bool _isFire;

public:
	mainGame();
	~mainGame();

	virtual HRESULT init();				//�ʱ�ȭ
	virtual void release();				//����
	virtual void update();				//�����ϴ°�
	virtual void render(HDC hdc);		//�׸��°�
};

