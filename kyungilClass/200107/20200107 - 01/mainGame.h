#pragma once
#include"gameNode.h"

class mainGame :  public gameNode
{
private:
	image * _bgImage;
	image* _hoon;


	int _index;		//프레임 인덱스
	int _count;		//프레임 돌릴 카운트
	bool _isLeft;	//왼쪽임?
public:
	mainGame();
	~mainGame();

	virtual HRESULT init();	//초기화
	virtual void release();//해제
	virtual void update();//연산하는곳
	virtual void render(HDC hdc);//그리는곳

	
};

