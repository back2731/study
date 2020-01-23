#pragma once
#include"gameNode.h"
#define BOX 5

struct tagBox
{
	RECT rc;
	bool isCheck;
	bool isJoker;
};

class mainGame :  public gameNode
{
private:
	
	tagBox m_box[BOX];

public:
	mainGame();
	~mainGame();

	virtual HRESULT init();				//�ʱ�ȭ
	virtual void release();				//����
	virtual void update();				//�����ϴ°�
	virtual void render(HDC hdc);		//�׸��°�
};

