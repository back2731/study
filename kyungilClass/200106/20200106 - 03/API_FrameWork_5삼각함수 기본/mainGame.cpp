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
	// ����ۿ� �Ѹ���.
	HDC memDC = this->GetBackBuffer()->GetMemDC();
	//��� ��Ʈ��
	PatBlt(memDC, 0, 0, WINSIZEX, WINSIZEY, WHITENESS);
	//============================================================

	_bgImage->Render(memDC);


	//============================================================
	// ������� ������ HDC�� �׸���.(�ǵ帮�� ����)
	this->GetBackBuffer()->Render(hdc, 0, 0);

}


