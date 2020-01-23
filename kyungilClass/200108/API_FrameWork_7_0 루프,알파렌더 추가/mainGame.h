#pragma once
#include"gameNode.h"



struct player
{

};
class mainGame :  public gameNode
{
private:
	image * _bgImage;
	image* _rockman;
	int _index;
	int _count;
	bool _isLeft;

	int posX;
	int posY;

	int cameraX;
	int cameraY;

public:
	mainGame();
	~mainGame();

	virtual HRESULT init();	//초기화
	virtual void release();//해제
	virtual void update();//연산하는곳
	virtual void render(HDC hdc);//그리는곳

	
};

