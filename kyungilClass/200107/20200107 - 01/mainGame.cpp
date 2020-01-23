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
	_bgImage->init("images/�̿�����.bmp", WINSIZEX, WINSIZEY);

	_hoon = new image;
	_hoon->init("images/1111.bmp", WINSIZEX / 2, WINSIZEY / 2, 360, 130, 10, 2, true,RGB(255,0,255));
	return S_OK;
}

void mainGame::release()
{
	gameNode::release();
	SAFE_DELETE(_bgImage);
	SAFE_DELETE(_hoon);
}

void mainGame::update()
{
	gameNode::update();

	if (KEYMANAGER->isStayKeyDown(VK_LEFT))
	{
		_isLeft = true;
		_hoon->setX(_hoon->getX() - 2.0f);
	}
	if (KEYMANAGER->isStayKeyDown(VK_RIGHT))
	{
		_isLeft = false;
		_hoon->setX(_hoon->getX() + 2.0f);
	}
	if (_isLeft)
	{
		_count++;
		_hoon->setFrameY(1);

		if (_count % 5 == 0)
		{
			_count = 0;
			_index--;

			if (_index < _hoon->getMaxFrameY())
			{
				_index = 9;
			}
			_hoon->setFrameX(_index);
		}
	}
	else
	{
		_count++;
		_hoon->setFrameY(0);
		if (_count % 5 == 0)
		{
			_count = 0;
			_index++;
			if (_index >= _hoon->getMaxFrameX())
			{
				_index= 0;
			}
			_hoon->setFrameX(_index);
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

	_bgImage->render(memDC);
	_hoon->frameRender(memDC, _hoon->getX(), _hoon->getY(), _hoon->getFrameX(), _hoon->getFrameY());
	//=================================================
	//������� ������ HDC�� �׸���.(�ǵ帮������.)
	this->getBackBuffer()->render(hdc, 0, 0);
}

