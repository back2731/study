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

	


	_bgImage = new image;
	_bgImage->init("images/�����.bmp", WINSIZEX, WINSIZEY);
	_rockman = new image;
	_rockman->init("images/�ϸ�.bmp", WINSIZEX / 2, WINSIZEY / 2, 480, 100, 10, 2, true, RGB(255, 0, 255));
	_count = 0;
	_index = 0;
	_isLeft = false;
	
	posX = WINSIZEX / 2;
	posY = WINSIZEY / 2;

	cameraX = 100;
	cameraY = 100;
	return S_OK;
}

void mainGame::release()
{
	gameNode::release();
	SAFE_DELETE(_bgImage);
	SAFE_DELETE(_rockman);
	
}

void mainGame::update()
{
	gameNode::update();
	if (KEYMANAGER->isStayKeyDown(VK_LEFT))
	{
		_isLeft = true;
		//_rockman->setX(_rockman->getX() - 2.0f);
		posX -= 5;

		if (posX < 48)
		{
			posX = WINSIZEX;
		}
	}
	if (KEYMANAGER->isStayKeyDown(VK_RIGHT))
	{
		_isLeft = false;
		//_rockman->setX(_rockman->getX() + 2.0f);
		posX += 5;
		if (posX > WINSIZEX)
		{
			posX = -48;
		}
	}
	if (KEYMANAGER->isStayKeyDown('A'))cameraX -= 5;
	if (KEYMANAGER->isStayKeyDown('D'))cameraX += 5;
	if (KEYMANAGER->isStayKeyDown('W'))cameraY -= 5;
	if (KEYMANAGER->isStayKeyDown('S'))cameraY += 5;


	if (_isLeft)
	{
		_count++;
		_rockman->setFrameY(1);
		if (_count % 5 == 0)
		{
			_count = 0;
			_index--;
			if (_index < _rockman->getMaxFrameY())
			{
				_index = 9;
			}
			_rockman->setFrameX(_index);
		}
	}
	else
	{
		_count++;
		_rockman->setFrameY(0);
		if (_count % 5 == 0)
		{
			_count = 0;
			_index++;
			if (_index >= _rockman->getMaxFrameX())
			{
				_index = 0;
			}
			_rockman->setFrameX(_index);
		}
	}
}

void mainGame::render(HDC hdc)
{
	//����ۿ� �Ѹ���.
	HDC memDC = this->getBackBuffer()->getMemDC();
	//��� ��Ʈ��
	PatBlt(memDC, 0, 0, WINSIZEX, WINSIZEY, WHITENESS);
	//===================================================

	// ����̹���
	_bgImage->render(memDC);

	//
	_bgImage->render(memDC, 100, 100, cameraX, cameraY, 150, 150);
	
	_rockman->frameRender(memDC, posX, _rockman->getY(), _rockman->getFrameX(), _rockman->getFrameY());


	//=================================================
	//������� ������ HDC�� �׸���.(�ǵ帮������.)
	this->getBackBuffer()->render(hdc, 0, 0);
}

