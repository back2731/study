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
	_isJump = false;
	_bgImage = new image;
	_bgImage->init("images/stage.bmp", 0, 0, 9024, 168, 16, 1, true, RGB(255, 0, 255));

	_character = new image;
	_character->init("images/motion.bmp", 5070, 752, 39, 4, true,RGB(248,0,248));

	_box.rc = RectMakeCenter(WINSIZEX/2,WINSIZEY/2,_character->getFrameWidth(),_character->getFrameHeight());

	_index = 0;
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
	if (KEYMANAGER->isStayKeyDown(VK_RIGHT))
	{
		_isLeft = false;
		_box.rc.left += 2.0f;
		_box.rc.right += 2.0f;
	}
	if (KEYMANAGER->isOnceKeyDown(VK_SPACE))
	{
		_isJump = true;
	}

	_mapCount++;
	_bgImage->setFrameY(0);

	if (_mapCount % 10 == 0)
	{
		_index--;

		if (_index < _bgImage->getMaxFrameY())
		{
			_index = 15;
		}
		_bgImage->setFrameX(_index);
	}

	if (_isIdle )
	{
		_count++;
		_character->setFrameY(3);// 필살기 입력했을때 초기화하는방법


		if (_count % 3 == 0)
		{
			_idleIndex++;
			if (_idleIndex > _character->getMaxFrameX())
			{
				_idleIndex = 0;
			}
			_character->setFrameX(_idleIndex);
		}

	}
	if (_isJump)
	{		
		_isIdle = false;
		_count++;
		_character->setFrameY(0);

		if (_count % 10 == 0)
		{
			_index--;

			if (_index < _character->getMaxFrameY())
			{
				_index = 7;
			}
			_character->setFrameX(_index);
		}
	}
	/*{
		_count++;
		_character->setFrameY(1);

		if (_count % 20 == 0)
		{
			_count = 0;
			_index--;

			if (_index < _character->getMaxFrameY())
			{
				_index = 9;
			}
			_character->setFrameX(_index);
		}
	}
	else
	{
		_count++;
		_character->setFrameY(0);
		if (_count % 20 == 0)
		{
			_count = 0;
			_index++;
			if (_index >= _character->getMaxFrameX())
			{
				_index= 0;
			}
			_character->setFrameX(_index);
		}
	}*/
	
}

void mainGame::render(HDC hdc)
{
	//백버퍼에 뿌리자.
	HDC memDC = this->getBackBuffer()->getMemDC();
	//흰색 비트맵
	PatBlt(memDC, 0, 0, WINSIZEX, WINSIZEY, WHITENESS);
	//===================================================


	_bgImage->frameRender(memDC, _bgImage->getX(), _bgImage->getY(), _bgImage->getFrameX(), _bgImage->getFrameY());
	//Rectangle(memDC, _box.rc.left, _box.rc.top, _box.rc.right, _box.rc.bottom);
	_character->frameRender(memDC, _box.rc.left, _box.rc.top-10);

	//=================================================
	//백버퍼의 내용을 HDC에 그린다.(건드리지말것.)
	this->getBackBuffer()->render(hdc, 0, 0);
}

