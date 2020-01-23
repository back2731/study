#pragma once
#include"gameNode.h"

class mainGame :  public gameNode
{
struct tagBox
{
	RECT rc;
	bool isTouch;
};

private:
	image * _bgImage;
	image* _character;
	image* _jump;

	tagBox _box;

	int _index;		//프레임 인덱스
	int _idleIndex = 0;
	int _count;		//프레임 돌릴 카운트
	int _mapCount;
	bool _isLeft;	//왼쪽임?
	bool _isIdle;
	bool _isJump;


public:
	mainGame();
	~mainGame();

	virtual HRESULT init();	//초기화
	virtual void release();//해제
	virtual void update();//연산하는곳
	virtual void render(HDC hdc);//그리는곳

	
};

