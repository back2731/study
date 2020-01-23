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

	virtual HRESULT init();				//초기화
	virtual void release();				//해제
	virtual void update();				//연산하는곳
	virtual void render(HDC hdc);		//그리는곳
};

