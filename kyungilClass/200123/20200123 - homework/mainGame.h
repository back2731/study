#pragma once
#include"gameNode.h"
#include"scene1.h"
#include"scene2.h"
#include"soundTest.h"
class mainGame :  public gameNode
{
private:
	RECT rc;
public:
	mainGame();
	~mainGame();

	virtual HRESULT init();	//�ʱ�ȭ
	virtual void release();//����
	virtual void update();//�����ϴ°�
	virtual void render(/*HDC hdc*/);//�׸��°�

	
};

