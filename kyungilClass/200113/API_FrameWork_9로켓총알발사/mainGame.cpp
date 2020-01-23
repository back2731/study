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

	IMAGEMANAGER->addImage("���ȭ��", "images/�����.bmp", WINSIZEX, WINSIZEY, true, RGB(255, 0, 255));

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
	
	//��� ��Ʈ��
	PatBlt(getMemDC(), 0, 0, WINSIZEX, WINSIZEY, WHITENESS);
	//===================================================

	IMAGEMANAGER->render("���ȭ��", getMemDC());
	_rocket->render();

	//=================================================
	//������� ������ HDC�� �׸���.(�ǵ帮������.)
	this->getBackBuffer()->render(getHDC(), 0, 0);
}

