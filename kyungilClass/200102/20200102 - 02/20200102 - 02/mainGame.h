#pragma once
#include"gameNode.h"
#define BOXNUM 50
#define PLAYERRECT 50
#define OBSTACLERECT 30
#define GRAVITY 1
#define JUMPPOWER 20

struct tagRect
{
	RECT rc;
	bool jump;
};
class mainGame : public gameNode
{
private:
	//RECT rc;
	tagRect box;
	tagRect Player;
	RECT temp;
	char str[128];
	bool jump;
	int a;

public:
	mainGame();
	~mainGame();

	virtual HRESULT init();				// 초기화
	virtual void release();				// 해제
	virtual void update();				// 연산하는 곳
	virtual void render(HDC hdc);		// 그리는 곳

	void CrashBox();
};


