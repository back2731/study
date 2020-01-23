#pragma once
#include"gameNode.h"
#define BOXNUM 50
#define MAXSPEED 10
#define PLAYERRECT 25
#define OBSTACLERECT 15
#define RNDNUM 20

struct tagRect
{
	RECT rc;
	bool touch;
	int speed;
};
class mainGame : public gameNode
{
private:
	//RECT rc;
	tagRect box[BOXNUM];
	tagRect Player;
	RECT temp;
	int count;
	int speed;
	char str[128];
	bool gameEnd;

public:
	mainGame();
	~mainGame();

	virtual HRESULT init();				// �ʱ�ȭ
	virtual void release();				// ����
	virtual void update();				// �����ϴ� ��
	virtual void render(HDC hdc);		// �׸��� ��

	void CrashBox();
};


