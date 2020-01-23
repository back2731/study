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

	_player = IMAGEMANAGER->addFrameImage("플레이어", "images/player.bmp", 600 / 3, 1600 / 3, 2, 4, true, RGB(255, 0, 255));
	playerRect.rc = RectMakeCenter(200, 800, _player->getFrameWidth() - 40, _player->getFrameHeight());
	bottomRect.rc = RectMakeCenter(WINSIZEX / 2, WINSIZEY, WINSIZEX, 205);
	
	_bigFireRingBack = IMAGEMANAGER->addFrameImage("bigFireRingBack", "images/bigFireRing.bmp", 240 / 2, 1600 / 2, 2, 2, true, RGB(255, 0, 255));
	_bigFireRingFront = IMAGEMANAGER->addFrameImage("bigFireRingFront", "images/bigFireRing.bmp", 240 / 2, 1600 / 2, 2, 2, true, RGB(255, 0, 255));

	_smallFireRingBack = IMAGEMANAGER->addFrameImage("smallFireRingBack", "images/smallFireRing.bmp", 240 / 2, 1280 / 2, 2, 2, true, RGB(255, 0, 255));
	_smallFireRingFront = IMAGEMANAGER->addFrameImage("smallFireRingFront", "images/smallFireRing.bmp", 240 / 2, 1280 / 2, 2, 2, true, RGB(255, 0, 255));
	
	for (int i = 0; i < 2; i++)
	{
		fireRing[i].rc = RectMakeCenter(WINSIZEX + WINSIZEX/2, 350 + i * 360 , 20, 40);
		fireRingImage[i].rc = RectMakeCenter(WINSIZEX + WINSIZEX / 2 + 20 - i * 35, 525, 35, 350);
		fireRing[i].isTouch = false;
	}
	for (int i = 2; i < 4; i++)
	{
		fireRing[i].rc = RectMakeCenter(WINSIZEX + WINSIZEX, 350 + (i - 2) * 280, 20, 30);
		fireRingImage[i].rc = RectMakeCenter(WINSIZEX + WINSIZEX + 25 - (i-2) * 35, 490, 35, 275);
	}

	lampRect.rc = RectMakeCenter(WINSIZEX + 100, WINSIZEY - 175, 100, 100);
	_lamp = IMAGEMANAGER->addFrameImage("lamp", "images/lamp.bmp", 580 / 3, 410 / 3, 2, 1, true, RGB(255, 0, 255));

	goalRect.rc = RectMakeCenter(WINSIZEX - 265, WINSIZEY - 130, 250, 150);
	gardRect.rc = RectMakeCenter(WINSIZEX - 395, WINSIZEY - 132, 10, 148);

	_index = 0;
	_count = 0;
	_camera = -11110;
	_score = 0;

	addGravity = 0;

	_isLeft = false;
	_isMove = false;
	_isGoal = false;
	_isTouch = false;
	playerRect.isTouch = true;
	playerRect.isJump = false;


	return S_OK;
}

void circus::release()
{
}

void circus::update()
{


	if (KEYMANAGER->isStayKeyDown(VK_LEFT) && playerRect.rc.left > 0)	// 왼쪽 이동
	{
		_isMove = true;
		_isLeft = true;

		if (playerRect.rc.left >= WINSIZEX / 2 -250) 
		{			  
			playerRect.rc.left	-= PLAYERSPEED;
			playerRect.rc.right -= PLAYERSPEED;
		}
		// 플레이어의 레프트가 위의 수치보다 작을때는 카메라스피드를 계속 더해준다.(앞으로따라감)
		else if (_camera < 0) // 카메라 == 배경화면의 x값
		{
			_camera += CAMERASPEED;
		}
		else
		{
			playerRect.rc.left	-= PLAYERSPEED;
			playerRect.rc.right -= PLAYERSPEED;
		}
	}
	if (KEYMANAGER->isStayKeyDown(VK_RIGHT) && playerRect.rc.left + 200 < 11000)
	{
		_isMove = true;
		_isLeft = false;

		if (playerRect.rc.left <= 200)
		{
			playerRect.rc.left	+= PLAYERSPEED;
			playerRect.rc.right += PLAYERSPEED;
		}
		// 플레이어의 레프트가 위의 수치보다 작을때는 카메라스피드를 계속 빼준다.(뒤로따라감)
		else if (_camera > -11200) // 카메라 == 배경화면의 x값
		{
			_camera -= CAMERASPEED;
		}
		else
		{
			playerRect.rc.left	+= PLAYERSPEED;
			playerRect.rc.right += PLAYERSPEED;
		}
	}

	if (!_isMove) // 움직이는 상태가 아닐때 IDLE
	{
		// 장애물 이동
		lampRect.rc.left  -= OBSTACLE;
		lampRect.rc.right -= OBSTACLE;

		// 장애물이 끝까지 오면 재생성
		if (lampRect.rc.right < 0)
		{
			lampRect.rc = RectMakeCenter(WINSIZEX + 100, WINSIZEY - 175, 100, 100);
			_score += 2;
		}
		
		// 장애물 이동
		for (int i = 0; i < 2; i++)	
		{
			fireRing[i].rc.left			-= OBSTACLE;
			fireRing[i].rc.right		-= OBSTACLE;
			fireRingImage[i].rc.left	-= OBSTACLE;
			fireRingImage[i].rc.right	-= OBSTACLE;

			// 장애물이 끝까지 오면 재생성
			if (fireRing[i].rc.right < 0) 
			{
				fireRing[i].rc = RectMakeCenter(WINSIZEX + WINSIZEX / 2, 350 + i * 360, 20, 40);
				fireRingImage[i].rc = RectMakeCenter(WINSIZEX + WINSIZEX / 2 + 20 - i * 35, 525, 35, 350);
				_score += 5;
			}
		}
		for (int i = 2; i < 4; i++)
		{
			fireRing[i].rc.left -= OBSTACLE;
			fireRing[i].rc.right -= OBSTACLE;
			fireRingImage[i].rc.left -= OBSTACLE;
			fireRingImage[i].rc.right -= OBSTACLE;

			// 장애물이 끝까지 오면 재생성
			if (fireRing[i].rc.right < 0)
			{
				fireRing[i].rc = RectMakeCenter(WINSIZEX + WINSIZEX, 350 + (i - 2) * 280, 20, 30);
				fireRingImage[i].rc = RectMakeCenter(WINSIZEX + WINSIZEX + 25 - (i - 2) * 35, 490, 35, 275);
				_score += 10;
			}

		}
	}
	else if (_isLeft) // 왼쪽으로 움직일때
	{	
		// 장애물 이동 속도를 줄여준다.
		//lampRect.rc.left  -= OBSTACLE/3; // 램프는 뒤로갈때 정지.
		//lampRect.rc.right -= OBSTACLE/3;
		
		// 장애물이 끝까지 오면 재생성
		if (lampRect.rc.right < 0)
		{
			lampRect.rc = RectMakeCenter(WINSIZEX + 100, WINSIZEY - 175, 100, 100);
			_score += 2;
		}
		
		// 장애물 이동 속도를 줄여준다.
		for (int i = 0; i < 2; i++) 
		{
			fireRing[i].rc.left			+= OBSTACLE / 5;
			fireRing[i].rc.right		+= OBSTACLE / 5;
			fireRingImage[i].rc.left	+= OBSTACLE / 5;
			fireRingImage[i].rc.right	+= OBSTACLE / 5;

			// 장애물이 끝까지 오면 재생성
			if (fireRing[i].rc.right < 0) 
			{
				fireRing[i].rc = RectMakeCenter(WINSIZEX + WINSIZEX / 2, 350 + i * 360, 20, 40);
				fireRingImage[i].rc = RectMakeCenter(WINSIZEX + WINSIZEX / 2 + 20 - i * 35, 525, 35, 350);
				_score += 5;
			}
		}
		for (int i = 2; i < 4; i++)
		{
			fireRing[i].rc.left += OBSTACLE / 5;
			fireRing[i].rc.right += OBSTACLE / 5;
			fireRingImage[i].rc.left += OBSTACLE / 5;
			fireRingImage[i].rc.right += OBSTACLE / 5;

			// 장애물이 끝까지 오면 재생성
			if (fireRing[i].rc.right < 0)
			{
				fireRing[i].rc = RectMakeCenter(WINSIZEX + WINSIZEX, 350 + (i - 2) * 280, 20, 30);
				fireRingImage[i].rc = RectMakeCenter(WINSIZEX + WINSIZEX + 25 - (i - 2) * 35, 490, 35, 275);
				_score += 10;
			}
		}
	}
	else // 오른쪽으로 이동
	{
		// 장애물 이동
		lampRect.rc.left  -= OBSTACLE;
		lampRect.rc.right -= OBSTACLE;
		
		// 장애물이 끝까지 오면 재생성
		if (lampRect.rc.right < 0)
		{
			lampRect.rc = RectMakeCenter(WINSIZEX + 100, WINSIZEY - 175, 100, 100);
			_score += 2;
		}

		// 장애물 이동
		for (int i = 0; i < 2; i++) 
		{
			fireRing[i].rc.left			-= OBSTACLE;
			fireRing[i].rc.right		-= OBSTACLE;
			fireRingImage[i].rc.left	-= OBSTACLE;
			fireRingImage[i].rc.right	-= OBSTACLE;

			// 장애물이 끝까지 오면 재생성
			if (fireRing[i].rc.right < 0) 
			{
				fireRing[i].rc = RectMakeCenter(WINSIZEX + WINSIZEX / 2, 350 + i * 360, 20, 40);
				fireRingImage[i].rc = RectMakeCenter(WINSIZEX + WINSIZEX / 2 + 20 - i * 35, 525, 35, 350);
				_score += 5;
			}
		}
		for (int i = 2; i < 4; i++)
		{
			fireRing[i].rc.left -= OBSTACLE;
			fireRing[i].rc.right -= OBSTACLE;
			fireRingImage[i].rc.left -= OBSTACLE;
			fireRingImage[i].rc.right -= OBSTACLE;

			// 장애물이 끝까지 오면 재생성
			if (fireRing[i].rc.right < 0)
			{
				fireRing[i].rc = RectMakeCenter(WINSIZEX + WINSIZEX, 350 + (i - 2) * 280, 20, 30);
				fireRingImage[i].rc = RectMakeCenter(WINSIZEX + WINSIZEX + 25 - (i - 2) * 35, 490, 35, 275);
				_score += 10;
			}
		}
	}

	// 움직임을 멈추면 false 
	if (KEYMANAGER->isOnceKeyUp(VK_LEFT) || KEYMANAGER->isOnceKeyUp(VK_RIGHT))
	{
		_isMove = false;
	}

	// 점프
	if (KEYMANAGER->isOnceKeyDown(VK_SPACE))
	{
		playerRect.isJump  = true;
		playerRect.isTouch = false;
	}

	// 움직이는 상태가 아니면 출력하는 이미지 IDLE
	if (!_isMove)
	{
		_player->setFrameY(1);
		_player->setFrameX(0);
	}
	// 움직이는 상태에서 출력하는 이미지
	else
	{
		_isMove = true;
		if (_isLeft) // 왼쪽
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
		else // 오른쪽
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

	// 점프 상태에서 출력되는 이미지
	if (playerRect.isJump)
	{
		_player->setFrameY(0);
		_player->setFrameX(1);
	}

	// 장애물에 닿았을때 이미지
	if (_isTouch)
	{
		_player->setFrameY(2);
		_player->setFrameX(0);
		gameOver();
		if (KEYMANAGER->isOnceKeyDown(VK_UP))
		{
			init();
		}
	}

	// 장애물과 플레이어 충돌
	if (IntersectRect(&temp.rc, &playerRect.rc, &lampRect.rc))
	{
		_isTouch = true;
	}
	for (int i = 0; i < 2; i++)
	{
		if (IntersectRect(&temp.rc, &playerRect.rc, &fireRing[i].rc))
		{
			_isTouch = true;
		}
	}
	for (int i = 2; i < 4; i++)
	{
		if (IntersectRect(&temp.rc, &playerRect.rc, &fireRing[i].rc))
		{
			_isTouch = true;
		}
	}
	if (IntersectRect(&temp.rc, &playerRect.rc, &gardRect.rc))
	{
		_isTouch = true;
	}
	if (!_isTouch)
	{
		Gravity(playerRect);			// 플레이어의 중력판정
	}
	Jump(playerRect);					// 플레이어의 점프
	CrashBox(playerRect, bottomRect);	// 바닥판정
	
	// 골 판정
	if(IntersectRect(&temp.rc, &playerRect.rc, &goalRect.rc))
	{
		_isGoal = true;
		playerRect.isJump = false;

		addGravity = 0;
		playerRect.rc.bottom = goalRect.rc.top;
		playerRect.rc.top = playerRect.rc.bottom - _player->getFrameHeight();
		gameOver();
		if (KEYMANAGER->isOnceKeyDown(VK_UP))
		{
			init();
		}
	}

	if (_isGoal)
	{
		_count++;
		_player->setFrameY(3);
		_player->setFrameX(0);
	}

	_backRingCount++;
	_bigFireRingBack->setFrameY(0);
	if (_backRingCount % 20 == 0)
	{
		_backRingCount = 0;
		_backRingindex++;
		if (_backRingindex > _bigFireRingBack->getMaxFrameX())
		{
			_backRingindex = 0;
		}
		_bigFireRingBack->setFrameX(_backRingindex);
	}
	_frontRingCount++;
	_bigFireRingFront->setFrameY(1);
	if (_frontRingCount % 20 == 0)
	{
		_frontRingCount = 0;
		_frontRingindex++;
		if (_frontRingindex > _bigFireRingFront->getMaxFrameX())
		{
			_frontRingindex = 0;
		}
		_bigFireRingFront->setFrameX(_frontRingindex);
	}

	_sBackRingCount++;
	_smallFireRingBack->setFrameY(0);
	if (_sBackRingCount % 20 == 0)
	{
		_sBackRingCount = 0;
		_sBackRingindex++;
		if (_sBackRingindex > _smallFireRingBack->getMaxFrameX())
		{
			_sBackRingindex = 0;
		}
		_smallFireRingBack->setFrameX(_sBackRingindex);
	}

	_sFrontRingCount++;
	_smallFireRingFront->setFrameY(1);
	if (_sFrontRingCount % 20 == 0)
	{
		_sFrontRingCount = 0;
		_sFrontRingindex++;
		if (_sFrontRingindex > _smallFireRingFront->getMaxFrameX())
		{
			_sFrontRingindex = 0;
		}
		_smallFireRingFront->setFrameX(_sFrontRingindex);
	}
	
	_lampCount++;
	_lamp->setFrameY(0);
	if (_lampCount % 20 == 0)
	{
		_lampCount = 0;
		_lampindex++;
		if (_lampindex > _lamp->getMaxFrameX())
		{
			_lampindex = 0;
		}
		_lamp->setFrameX(_lampindex);
	}

}

void circus::render()
{	IMAGEMANAGER->render("배경화면", getMemDC(), _camera, 0);
	
	if (KEYMANAGER->isToggleKey(VK_TAB))
	{
		Rectangle(getMemDC(), playerRect.rc.left, playerRect.rc.top, playerRect.rc.right, playerRect.rc.bottom);
		Rectangle(getMemDC(), bottomRect.rc.left, bottomRect.rc.top, bottomRect.rc.right, bottomRect.rc.bottom);
		for (int i = 0; i < 2; i++)
		{
			Rectangle(getMemDC(), fireRingImage[i].rc.left, fireRingImage[i].rc.top, fireRingImage[i].rc.right, fireRingImage[i].rc.bottom);
		}
		for (int i = 0; i < 2; i++)
		{
			Rectangle(getMemDC(), fireRing[i].rc.left, fireRing[i].rc.top, fireRing[i].rc.right, fireRing[i].rc.bottom);
		}
		for (int i = 2; i < 4; i++)
		{
			Rectangle(getMemDC(), fireRingImage[i].rc.left, fireRingImage[i].rc.top, fireRingImage[i].rc.right, fireRingImage[i].rc.bottom);
		}
		for (int i = 2; i < 4; i++)
		{
			Rectangle(getMemDC(), fireRing[i].rc.left, fireRing[i].rc.top, fireRing[i].rc.right, fireRing[i].rc.bottom);
		}
		Rectangle(getMemDC(), lampRect.rc.left, lampRect.rc.top, lampRect.rc.right, lampRect.rc.bottom);
		Rectangle(getMemDC(), goalRect.rc.left, goalRect.rc.top, goalRect.rc.right, goalRect.rc.bottom);
		Rectangle(getMemDC(), gardRect.rc.left, gardRect.rc.top, gardRect.rc.right, gardRect.rc.bottom);
	}

	IMAGEMANAGER->frameRender("smallFireRingBack", getMemDC(), fireRingImage[3].rc.left, fireRingImage[3].rc.top);
	IMAGEMANAGER->frameRender("bigFireRingBack", getMemDC(), fireRingImage[1].rc.left, fireRingImage[1].rc.top);
	IMAGEMANAGER->frameRender("플레이어", getMemDC(), playerRect.rc.left -20 , playerRect.rc.top);
	IMAGEMANAGER->frameRender("bigFireRingFront", getMemDC(), fireRingImage[0].rc.left, fireRingImage[0].rc.top);
	IMAGEMANAGER->frameRender("smallFireRingFront", getMemDC(), fireRingImage[2].rc.left, fireRingImage[2].rc.top);
	IMAGEMANAGER->frameRender("lamp", getMemDC(), lampRect.rc.left, lampRect.rc.top);

	wsprintf(str, "점수 : %d ", _score);
	TextOut(getMemDC(), 10, 10, str, strlen(str));

	if (_isTouch)
	{
		wsprintf(str, "점수 : %d, restart push up key ", _score);
		TextOut(getMemDC(), WINSIZEX/2, WINSIZEY/2, str, strlen(str));
	}
	if (_isGoal)
	{
		wsprintf(str, "점수 : %d, restart push up key ", _score);
		TextOut(getMemDC(), WINSIZEX / 2, WINSIZEY / 2, str, strlen(str));
	}
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

void circus::gameOver()
{

	addGravity = 0;
	playerRect.rc.top += JUMPPOWER;
	playerRect.rc.bottom += JUMPPOWER;
	if (KEYMANAGER->isStayKeyDown(VK_LEFT))	// 왼쪽 이동
	{
		if (playerRect.rc.left >= WINSIZEX / 2 - 250)
		{
			playerRect.rc.left += PLAYERSPEED;
			playerRect.rc.right += PLAYERSPEED;
		}
		// 플레이어의 레프트가 위의 수치보다 작을때는 카메라스피드를 계속 더해준다.(앞으로따라감)
		else if (_camera < 0) // 카메라 == 배경화면의 x값
		{
			_camera -= CAMERASPEED;
		}
		else
		{
			playerRect.rc.left += PLAYERSPEED;
			playerRect.rc.right += PLAYERSPEED;
		}
	}
	if (KEYMANAGER->isStayKeyDown(VK_RIGHT))
	{
		_isMove = true;
		_isLeft = false;

		if (playerRect.rc.left <= 200)
		{
			playerRect.rc.left -= PLAYERSPEED;
			playerRect.rc.right -= PLAYERSPEED;
		}
		// 플레이어의 레프트가 위의 수치보다 작을때는 카메라스피드를 계속 빼준다.(뒤로따라감)
		else if (_camera > -11200) // 카메라 == 배경화면의 x값
		{
			_camera += CAMERASPEED;
		}
		else
		{
			playerRect.rc.left -= PLAYERSPEED;
			playerRect.rc.right -= PLAYERSPEED;
		}
	}
	for (int i = 0; i < 2; i++)
	{
		fireRing[i].rc = RectMakeCenter(WINSIZEX + WINSIZEX / 2, 350 + i * 360, 20, 40);
		fireRingImage[i].rc = RectMakeCenter(WINSIZEX + WINSIZEX / 2 + 20 - i * 35, 525, 35, 350);
		fireRing[i].isTouch = false;
	}
	for (int i = 2; i < 4; i++)
	{
		fireRing[i].rc = RectMakeCenter(WINSIZEX + WINSIZEX, 350 + (i - 2) * 280, 20, 30);
		fireRingImage[i].rc = RectMakeCenter(WINSIZEX + WINSIZEX + 25 - (i - 2) * 35, 490, 35, 275);
	}
	lampRect.rc = RectMakeCenter(WINSIZEX + 100, WINSIZEY - 175, 100, 100);
}

