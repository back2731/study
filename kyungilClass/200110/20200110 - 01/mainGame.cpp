#include "stdafx.h"
#include "mainGame.h"
mainGame::mainGame()
{
}
mainGame::~mainGame()
{
}
HRESULT mainGame::init()
{
	gameNode::init(true);

	IMAGEMANAGER->addImage("배경화면", "images/고양이.bmp", WINSIZEX, WINSIZEY, true, RGB(255, 0, 255));

	_rocket = new rocket;
	_rocket->init();


	return S_OK;
}

void mainGame::release()
{
	gameNode::release();
	SAFE_DELETE(_rocket);

	
}

void mainGame::update()
{
	gameNode::update();
	
	_rocket->update();
	
}

void mainGame::render(HDC hdc)
{
	
	//흰색 비트맵
	PatBlt(getMemDC(), 0, 0, WINSIZEX, WINSIZEY, WHITENESS);
	//===================================================

	IMAGEMANAGER->render("배경화면", getMemDC());
	_rocket->render();

	//=================================================
	//백버퍼의 내용을 HDC에 그린다.(건드리지말것.)
	this->getBackBuffer()->render(getHDC(), 0, 0);
}

