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

	_circus = new circus;
	_circus->init();
	return S_OK;
}

void mainGame::release()
{
	gameNode::release();

	SAFE_DELETE(_circus);
}

void mainGame::update()
{
	gameNode::update();
	
	_circus->update();
}

void mainGame::render(HDC hdc)
{
	
	//��� ��Ʈ��
	PatBlt(getMemDC(), 0, 0, WINSIZEX, WINSIZEY, WHITENESS);
	//===================================================

	_circus->render();

	//=================================================
	//������� ������ HDC�� �׸���.(�ǵ帮������.)
	this->getBackBuffer()->render(hdc, 0, 0);
}

