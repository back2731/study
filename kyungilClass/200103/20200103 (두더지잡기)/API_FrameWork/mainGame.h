#pragma once
#include"gameNode.h"
#define BOX 9

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
	int count;
	int time;

	char str[128];

public:
	mainGame();
	~mainGame();

	virtual HRESULT init();				//�ʱ�ȭ
	virtual void release();				//����
	virtual void update();				//�����ϴ°�
	virtual void render(HDC hdc);		//�׸��°�
};

