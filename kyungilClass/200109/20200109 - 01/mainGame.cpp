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
	_minimap = new minimap;
	_minimap->init();

	return S_OK;
}

void mainGame::release()
{
	gameNode::release();
	SAFE_DELETE(_minimap);
	
}

void mainGame::update()
{
	gameNode::update();
	_minimap->update();
}

void mainGame::render(HDC hdc)
{
	//��� ��Ʈ��
	PatBlt(getMemDC(), 0, 0, WINSIZEX, WINSIZEY, WHITENESS);
	//===================================================
	_minimap->render(getMemDC());



	//=================================================
	//������� ������ HDC�� �׸���.(�ǵ帮������.)
	this->getBackBuffer()->render(hdc, 0, 0);
}

