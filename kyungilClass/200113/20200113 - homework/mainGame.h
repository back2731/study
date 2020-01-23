#pragma once
#include"gameNode.h"
#include"rocket.h"
#include"enemyManager.h"
class mainGame :  public gameNode
{
private:

	rocket*			_rocket;
	enemyManager*	_enemyManager;

private:

public:
	mainGame();
	~mainGame();

	virtual HRESULT init();	//초기화
	virtual void release();//해제
	virtual void update();//연산하는곳
	virtual void render(/*HDC hdc*/);//그리는곳

	void isCollision();
};

