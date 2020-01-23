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

	virtual HRESULT init();				//초기화
	virtual void release();				//해제
	virtual void update();				//연산하는곳
	virtual void render(HDC hdc);		//그리는곳
};

