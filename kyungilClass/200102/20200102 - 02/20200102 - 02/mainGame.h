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

	virtual HRESULT init();				// �ʱ�ȭ
	virtual void release();				// ����
	virtual void update();				// �����ϴ� ��
	virtual void render(HDC hdc);		// �׸��� ��

	void CrashBox();
};


