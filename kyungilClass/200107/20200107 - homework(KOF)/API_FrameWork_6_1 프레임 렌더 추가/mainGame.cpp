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
	_isIdle = true;
	_box.isJump = false;
	_box.isTouch = true;

	_bgImage = new image;
	_bgImage->init("images/stage.bmp", 0, 0, 9024 * 2, 168 * 2, 16, 1, true, RGB(255, 0, 255));

	_character = new image;
	_character->init("images/motion.bmp", 5070, 752, 39, 4, true,RGB(248,0,248));

	_box.rc = RectMakeCenter(WINSIZEX / 2 / 2, WINSIZEY / 2 + 200, _character->getFrameWidth(), _character->getFrameHeight());
	_floor.rc = RectMakeCenter(WINSIZEX / 2, WINSIZEY / 2 + 300, WINSIZEX, WINSIZEY);
	_barrigate.rc = RectMakeCenter(WINSIZEX / 2, WINSIZEY / 2+120, 200, 20);
	_gard[0].rc = RectMakeCenter(WINSIZEX / 2 - 91, WINSIZEY / 2 + 120, 20, 10);
	_gard[1].rc = RectMakeCenter(WINSIZEX / 2 + 91, WINSIZEY / 2 + 120, 20, 10);

	_mapIndex = 0;
	_idleIndex = 0;
	_moveIndex = 0;
	_jumpIndex = 0;
	_ultimateIndex = 0;
	addGravity = 0;
	return S_OK;
}

void mainGame::release()
{
	gameNode::release();
	SAFE_DELETE(_bgImage);
	SAFE_DELETE(_character);
}

void mainGame::update()
{
	gameNode::update();

	if (KEYMANAGER->isStayKeyDown(VK_LEFT))
	{
		_isLeft = true;
		_box.rc.left -= 2.0f;
		_box.rc.right -= 2.0f;
	}
	if (KEYMANAGER->isOnceKeyUp(VK_LEFT))
	{
		_isLeft = false;
		_isIdle = true;
	}
	if (KEYMANAGER->isStayKeyDown(VK_RIGHT))
	{
		_isRight = true;
		_box.rc.left += 2.0f;
		_box.rc.right += 2.0f;
	}
	if (KEYMANAGER->isOnceKeyUp(VK_RIGHT))
	{
		_isRight = false;
		_isIdle = true;
	}
	if (KEYMANAGER->isOnceKeyDown(VK_SPACE))
	{
		_box.isJump = true;
		_box.isTouch = false;
	}

	if (KEYMANAGER->isOnceKeyDown(VK_UP))
	{
		_isUltimate = true;
	}

	Jump(_box);
	Gravity(_box);

	_mapCount++;
	_bgImage->setFrameY(0);

	if (_mapCount % 5 == 0)
	{
		_mapIndex++;

		if (_mapIndex > _bgImage->getMaxFrameX())
		{
			_mapIndex = 0;
		}
		_bgImage->setFrameX(_mapIndex);
	}

	if (_isIdle)
	{
		_idleCount++;
		_character->setFrameY(0);// 필살기 입력했을때 초기화하는방법

		if (_idleCount % 10 == 0)
		{
			_idleIndex++;
			if (_idleIndex > _character->getMaxFrameX()-33)
			{
				_idleIndex = 0;
			}
			_character->setFrameX(_idleIndex);
		}

	}
	if (_isLeft || _isRight)
	{
		_isIdle = false;
		_moveCount++;
		_character->setFrameY(2);// 필살기 입력했을때 초기화하는방법

		if (_moveCount % 10 == 0)
		{
			_moveIndex++;
			if (_moveIndex > _character->getMaxFrameX() - 33)
			{
				_moveIndex = 0;
			}
			_character->setFrameX(_moveIndex);
		}
		if (IntersectRect(&_temp.rc, &_box.rc, &_gard[0].rc))
		{
			_box.rc.left -= 2.0f;
			_box.rc.right -= 2.0f;
		}
		if (IntersectRect(&_temp.rc, &_box.rc, &_gard[1].rc))
		{
			_box.rc.left += 2.0f;
			_box.rc.right += 2.0f;
		}

	}
	if (_box.isJump && _box.isTouch == false)
	{		
		_isIdle = false;
		_isLeft = false;
		_isRight = false;
		_jumpCount++;
		_character->setFrameY(1);

		if (_jumpCount % 15 == 0)
		{
			_jumpIndex++;
			_character->setFrameX(_jumpIndex);
			if (_jumpIndex > _character->getMaxFrameX() - 33)
			{
				_jumpIndex = 0;
			}
			_character->setFrameX(_jumpIndex);
		}
		
		if (IntersectRect(&_temp.rc, &_box.rc, &_floor.rc))
		{
			_isIdle = true;
			_box.isJump = false;
		}
		if (IntersectRect(&_temp.rc, &_box.rc, &_barrigate.rc))
		{
			_isIdle = true;
			_box.isJump = false;
		}
	}
	if (_isUltimate)
	{
		_isIdle = false;
		_isLeft = false;
		_isRight = false;
		_ultimateCount++;
		_character->setFrameY(3);// 필살기 입력했을때 초기화하는방법

		if (_ultimateCount % 3 == 0)
		{
			_ultimateIndex++;
			if (_ultimateIndex >= _character->getMaxFrameX())
			{
				_isUltimate = false;
				_isIdle = true;
				_ultimateIndex = 0;
			}
			_character->setFrameX(_ultimateIndex);
		}
	}

	CrashBox(_box, _floor);
	CrashBox(_box, _barrigate);

}

void mainGame::render(HDC hdc)
{
	//백버퍼에 뿌리자.
	HDC memDC = this->getBackBuffer()->getMemDC();
	//흰색 비트맵
	PatBlt(memDC, 0, 0, WINSIZEX, WINSIZEY, WHITENESS);
	//===================================================


	_bgImage->frameRender(memDC, _bgImage->getX(), _bgImage->getY(), _bgImage->getFrameX(), _bgImage->getFrameY());
	Rectangle(memDC, _box.rc.left, _box.rc.top, _box.rc.right, _box.rc.bottom);
	Rectangle(memDC, _floor.rc.left, _floor.rc.top, _floor.rc.right, _floor.rc.bottom);
	Rectangle(memDC, _barrigate.rc.left, _barrigate.rc.top, _barrigate.rc.right, _barrigate.rc.bottom);
	Rectangle(memDC, _gard[0].rc.left, _gard[0].rc.top, _gard[0].rc.right, _gard[0].rc.bottom);
	Rectangle(memDC, _gard[1].rc.left, _gard[1].rc.top, _gard[1].rc.right, _gard[1].rc.bottom);

	
	_character->frameRender(memDC, _box.rc.left, _box.rc.top-10);

	//=================================================
	//백버퍼의 내용을 HDC에 그린다.(건드리지말것.)
	this->getBackBuffer()->render(hdc, 0, 0);
}


void mainGame::Gravity(tagRect & a)
{
	if (a.isTouch == false)
	{
		a.rc.top += GRAVITY;
		a.rc.bottom += GRAVITY;
	}
}

void mainGame::Jump(tagRect & a)
{
	if (a.isJump)
	{
		addGravity -= GRAVITY;
		a.rc.top -= JUMPPOWER + addGravity;
		a.rc.bottom -= JUMPPOWER + addGravity;
	}
}

void mainGame::CrashBox(tagRect &a, tagRect &b)
{
	if (IntersectRect(&_temp.rc, &a.rc, &b.rc))
	{
		addGravity = 0;
		a.rc.bottom = b.rc.top;
		a.rc.top = a.rc.bottom - _character->getFrameHeight();
		a.isTouch = true;
	}
	else
	{
		a.isTouch = false;
	}
}
