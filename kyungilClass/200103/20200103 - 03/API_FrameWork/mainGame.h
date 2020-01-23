#pragma once
#include"gameNode.h"
#define BULLETMAX 30

struct tagBullet
{
	RECT rc;
	bool isFire;
	float speed;
};
class mainGame :  public gameNode
{
private:
	
	tagBullet _bullet[BULLETMAX];

	RECT _player1;
	RECT _player2;

	RECT _gaugeFront;
	RECT _gaugeBack;

	int _r;
	int _g;


public:
	mainGame();
	~mainGame();

	virtual HRESULT init();				//초기화
	virtual void release();				//해제
	virtual void update();				//연산하는곳
	virtual void render(HDC hdc);		//그리는곳

	void BulletFire();					// 발사
	void BulletMove();					// 움직임
	void GaugeDraw();					// 게이지 그리기
	void Collision();					// 충돌
	void PlayerKeyControl();			// 컨트롤
};

