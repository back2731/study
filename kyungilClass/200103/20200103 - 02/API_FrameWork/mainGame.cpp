#include "stdafx.h"
#include "mainGame.h"
mainGame::mainGame()
{
	_isFire = false;
}
mainGame::~mainGame()
{
}
HRESULT mainGame::init()
{
	gameNode::init();
	_body = RectMakeCenter(WINSIZEX / 2, WINSIZEY - 150, 50, 100);

	_bullet = RectMakeCenter(_body.left + (_body.right - _body.left) / 2, _body.top - 15, 30, 30);

	return S_OK;
}

void mainGame::release()
{
	gameNode::release();
}

void mainGame::update()
{
	gameNode::update();

	if (KEYMANAGER->isStayKeyDown(VK_RIGHT))
	{
		OffsetRect(&_body, 5, 0);
		
	}
	if (KEYMANAGER->isStayKeyDown(VK_LEFT))
	{
		OffsetRect(&_body, -5, 0);
	}

	if (KEYMANAGER->isOnceKeyDown(VK_SPACE));
	{
		_isFire = true;
	}

	if (!_isFire)
	{
		_bullet = RectMakeCenter(_body.left + (_body.right - _body.left) / 2, _body.top - 15, 30, 30);
	}
	else
	{
		_bullet.top -= 5;
		_bullet.bottom -= 5;

		if (_bullet.bottom < 0)
		{
			_isFire = false;
		}

	}
}

void mainGame::render(HDC hdc)
{
	Rectangle(hdc, _body.left, _body.top, _body.right, _body.bottom);

	if (_isFire)
	{
		Ellipse(hdc, _bullet.left, _bullet.top, _bullet.right, _bullet.bottom);
	}
}
