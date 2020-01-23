#pragma once
#include"gameNode.h"
#define BOXNUM 5
#define MAXSPEED 7
#define PLAYERRECT 50
#define WIDTH 50
#define HEIGHT 300
#define GAP 200
#define GRAVITY 1
#define JUMPPOWER 20
#define RNDNUM 20

struct tagRect
{
	RECT rc;
	bool jump;
	bool air;
};
struct barricadeRect
{
	RECT rc;
	bool touch;
	int speed;
};
class mainGame : public gameNode
{
private:
	//RECT rc;
	tagRect box;
	tagRect Player;

	barricadeRect barriTop[BOXNUM];
	barricadeRect barriUnder[BOXNUM];

	RECT temp;
	char str[128];
	int playerAddGravity;
	int addGravity;
	int rndNum;
	int count;
	bool gameEnd;

	int startLine;

public:
	mainGame();
	~mainGame();

	virtual HRESULT init();				// 초기화
	virtual void release();				// 해제
	virtual void update();				// 연산하는 곳
	virtual void render(HDC hdc);		// 그리는 곳

	void Gravity(tagRect &a);
	void Jump(tagRect &a);
	void CrashBox();

};


