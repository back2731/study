#include "stdafx.h"
#include "circus.h"


circus::circus()
{
}


circus::~circus()
{
}

HRESULT circus::init()
{

	IMAGEMANAGER->addImage("배경화면", "images/map.bmp", 12224, 958, true, RGB(255, 0, 255));

	_player = IMAGEMANAGER->addFrameImage("플레이어", "images/player.bmp", 600 / 2, 1200 / 2, 2, 3, true, RGB(255, 0, 255));
	playerRect.rc = RectMakeCenter(200, 755, _player->getFrameWidth(), _player->getFrameHeight());
	bottomRect.rc = RectMakeCenter(WINSIZEX / 2, WINSIZEY, WINSIZEX, 205);


	for (int i = 0; i < 2; i++)
	{
		fireRing[i].rc = RectMakeCenter(WINSIZEX + 100, 350 + i * 350 , 70, 30);
		fireRingImage[i].rc = RectMakeCenter(WINSIZEX + 100 + 35 - (i*70 / 2), 525, 35, 350);
	}

	_index = 0;
	_count = 0;
	_camera = 0;
	addGravity = 0;
	_isLeft = false;
	_isMove = false;
	playerRect.isTouch = true;
	return S_OK;
}

void circus::release()
{
}

void circus::update()
{
	if (KEYMANAGER->isStayKeyDown(VK_LEFT) && playerRect.rc.left > 0)
	{
		_isMove = true;
		_isLeft = true;

		if (playerRect.rc.left >= WINSIZEX / 2)
		{			  
			playerRect.rc.left -= PLAYERSPEED;
			playerRect.rc.right -= PLAYERSPEED;
		}
		else if (_camera < 0)
		{
			_camera += CAMERASPEED;
		}
		else
		{
			playerRect.rc.left -= PLAYERSPEED;
			playerRect.rc.right -= PLAYERSPEED;
		}
	}
	if (KEYMANAGER->isStayKeyDown(VK_RIGHT) && playerRect.rc.left + 200 < 11000)
	{
		_isMove = true;
		_isLeft = false;

		if (playerRect.rc.left <= 200)
		{
			playerRect.rc.left += PLAYERSPEED;
			playerRect.rc.right += PLAYERSPEED;
		}
		else if (_camera > -11200)
		{
			_camera -= CAMERASPEED;
		}
		else
		{
			playerRect.rc.left += PLAYERSPEED;
			playerRect.rc.right += PLAYERSPEED;
		}

	}

	if (!_isMove)
	{
		for (int i = 0; i < 2; i++)
		{
			fireRing[i].rc.left -= OBSTACLE;
			fireRing[i].rc.right -= OBSTACLE;
			fireRingImage[i].rc.left -= OBSTACLE;
			fireRingImage[i].rc.right -= OBSTACLE;

			if (fireRing[i].rc.right < 0)
			{
				for (int i = 0; i < 2; i++)
				{
					fireRing[i].rc = RectMakeCenter(WINSIZEX + 100, 350 + i * 350, 70, 30);
					fireRingImage[i].rc = RectMakeCenter(WINSIZEX, 525, 35, 350);
				}
			}
		}
	}
	else if (_isLeft)
	{
		for (int i = 0; i < 2; i++)
		{
			fireRing[i].rc.left -= OBSTACLE;
			fireRing[i].rc.right -= OBSTACLE;
			fireRingImage[i].rc.left -= OBSTACLE;
			fireRingImage[i].rc.right -= OBSTACLE;

			if (fireRing[i].rc.right < 0)
			{
				for (int i = 0; i < 2; i++)
				{
					fireRing[i].rc = RectMakeCenter(WINSIZEX + 100, 350 + i * 350, 70, 30);
				//	fireRingImage[i].rc = RectMakeCenter(WINSIZEX + 100 + 35 - (i * 70 / 2), 525, 35, 350);
				}
			}
		}
	}
	else
	{
		for (int i = 0; i < 2; i++)
		{
			fireRing[i].rc.left -= OBSTACLE;
			fireRing[i].rc.right -= OBSTACLE;
			fireRingImage[i].rc.left -= OBSTACLE;
			fireRingImage[i].rc.right -= OBSTACLE;

			if (fireRing[i].rc.right < 0)
			{
				for (int i = 0; i < 2; i++)
				{
					fireRing[i].rc = RectMakeCenter(WINSIZEX + 100, 350 + i * 350, 70, 30);
				//	fireRingImage[i].rc = RectMakeCenter(WINSIZEX + 100 + 35 - (i * 70 / 2), 525, 35, 350);
				}
			}
		}
	}

	if (KEYMANAGER->isOnceKeyUp(VK_LEFT) || KEYMANAGER->isOnceKeyUp(VK_RIGHT))
	{
		_isMove = false;
	}

	if (KEYMANAGER->isOnceKeyDown(VK_SPACE))
	{
		playerRect.isJump  = true;
		playerRect.isTouch = false;
	}

	if (!_isMove)
	{
		_player->setFrameY(1);
		_player->setFrameX(0);
	}
	else
	{
		_isMove = true;
		if (_isLeft)
		{
			_count++;
			_player->setFrameY(1);
			if (_count % 20 == 0)
			{
				_count = 0;
				_index++;
				if (_index > _player->getMaxFrameX())
				{
					_index = 0;
				}
				_player->setFrameX(_index);
			}
		}
		else
		{
			_count++;
			_player->setFrameY(0);
			if (_count % 20 == 0)
			{
				_count = 0;
				_index++;
				if (_index > _player->getMaxFrameX())
				{
					_index = 0;
				}
				_player->setFrameX(_index);
			}
		}
	}

	if (playerRect.isJump)
	{
		_player->setFrameY(0);
		_player->setFrameX(1);
	}
	Gravity(playerRect);
	Jump(playerRect);
	CrashBox(playerRect, bottomRect);
}

void circus::render()
{	IMAGEMANAGER->render("배경화면", getMemDC(), _camera, 0);
	
	if (KEYMANAGER->isToggleKey(VK_TAB))
	{
		Rectangle(getMemDC(), playerRect.rc.left, playerRect.rc.top, playerRect.rc.right, playerRect.rc.bottom);
		Rectangle(getMemDC(), bottomRect.rc.left, bottomRect.rc.top, bottomRect.rc.right, bottomRect.rc.bottom);
		for (int i = 0; i < 2; i++)
		{
			Rectangle(getMemDC(), fireRing[i].rc.left, fireRing[i].rc.top, fireRing[i].rc.right, fireRing[i].rc.bottom);
			Rectangle(getMemDC(), fireRingImage[i].rc.left, fireRingImage[i].rc.top, fireRingImage[i].rc.right, fireRingImage[i].rc.bottom);
		}
	}

	IMAGEMANAGER->frameRender("플레이어", getMemDC(), playerRect.rc.left, playerRect.rc.top);
	

	wsprintf(str, "위치 : %d ", _camera);
	TextOut(getMemDC(), 10, 10, str, strlen(str));
}

void circus::Gravity(tagRect & a)
{
	if (a.isTouch == false)
	{
		a.rc.top += GRAVITY;
		a.rc.bottom += GRAVITY;
	}
}

void circus::Jump(tagRect & a)
{
	if (a.isJump)
	{
		addGravity -= GRAVITY;
		a.rc.top -= JUMPPOWER + addGravity/2;
		a.rc.bottom -= JUMPPOWER + addGravity/2;
	}
}

void circus::CrashBox(tagRect &a, tagRect &b)
{
	
	if (IntersectRect(&temp.rc, &a.rc, &b.rc))
	{
		addGravity = 0;
		a.rc.bottom = b.rc.top;
		a.rc.top = a.rc.bottom - _player->getFrameHeight();
		a.isTouch = true;
		a.isJump = false;
	}
	else
	{
		a.isTouch = false;
	}
}

