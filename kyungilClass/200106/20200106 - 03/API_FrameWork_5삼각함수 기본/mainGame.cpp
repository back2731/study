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
	gameNode::init();

	_bgImage = new Image;
	_bgImage->Init("image/asdf.bmp", WINSIZEX, WINSIZEY);

	return S_OK;
}

void mainGame::release()
{
	gameNode::release();
	SAFE_DELETE(_bgImage);
}

void mainGame::update()
{
	gameNode::update();

}

void mainGame::render(HDC hdc)
{
	// 백버퍼에 뿌리자.
	HDC memDC = this->GetBackBuffer()->GetMemDC();
	//흰색 비트맵
	PatBlt(memDC, 0, 0, WINSIZEX, WINSIZEY, WHITENESS);
	//============================================================

	_bgImage->Render(memDC);


	//============================================================
	// 백버퍼의 내용을 HDC에 그린다.(건드리지 말것)
	this->GetBackBuffer()->Render(hdc, 0, 0);

}


