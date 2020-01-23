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
	_cannon.angle = 3.75f;		
	_cannon.cannon = 100;		
	_cannon.center.x = 868;		
	_cannon.center.y = 150;		

	_bgImage = new image;
	_bgImage->init("images/map.bmp", WINSIZEX+50, WINSIZEY);
	_dashboard = new image;
	_dashboard->init("images/dashboard.bmp", 500, 100, 255, 255, 1, 1, true, RGB(255, 0, 255));

	_player = new image;
	_player->init("images/playercar.bmp", 315, 600, 90, 100, 1, 1, true, RGB(255, 0, 255));
	pRect.rc = RectMakeCenter(355, 620, _player->getFrameWidth(), _player->getFrameHeight());

	_gaugeBack.rc = RectMake(900, 330, 50, 400);
	_gaugeFront.rc = RectMake(900, 330, 50, 400);

	_enemy = new image;
	_enemy->init("images/enemycar.bmp", 315, 600, 90, 100, 1, 1, true, RGB(255, 0, 255));
	for (int i = 0; i < ENEMY; i++)
	{
		enemyCar[i].touch = false;
		enemyCar[i].rc = RectMakeCenter(245 + i * 110, -100 * RND->getInt(20), _enemy->getFrameWidth(), _enemy->getFrameHeight());
		enemyCar[i].speed = 5;
	}

	_loopX = 0;
	_loopY = 0;

	speed = 0;
	addSpeed = 0;
	score = 0;

	return S_OK;
}

void mainGame::release()
{
	gameNode::release();
	SAFE_DELETE(_bgImage);
	SAFE_DELETE(_dashboard);

	SAFE_DELETE(_player);
	SAFE_DELETE(_enemy);
}

void mainGame::update()
{
	gameNode::update();
	if (KEYMANAGER->isOnceKeyDown(VK_SPACE))
	{
		_isGame = true;
		init();
	}


	if (_isGame)
	{
		usedFuel = abs(_loopY / 100);
		fuel = MAXFUEL - usedFuel;

		if (KEYMANAGER->isStayKeyDown(VK_UP))
		{
			for (int i = 0; i < ENEMY; i++)
			{
				enemyCar[i].touch = true;
			}

			_isMove = true;
			if (addSpeed < MAXADDSPEED)
			{
				addSpeed += SPEED;
				speed -= addSpeed;
				_loopY = speed;
			}
			else
			{
				speed -= addSpeed;
				_loopY = speed;
			}
		}
		if (KEYMANAGER->isOnceKeyUp(VK_UP))
		{
			_isMove = false;
		}

		if (KEYMANAGER->isOnceKeyDown(VK_LEFT))
		{
			pRect.rc.left -= 110.f;
			pRect.rc.right -= 110.f;
			if (pRect.rc.left <= 135)
			{
				pRect.rc.left += 110.f;
				pRect.rc.right += 110.f;
			}
		}

		if (KEYMANAGER->isOnceKeyDown(VK_RIGHT))
		{
			pRect.rc.left += 110.f;
			pRect.rc.right += 110.f;

			if (pRect.rc.left >= 465)
			{
				pRect.rc.left -= 110.f;
				pRect.rc.right -= 110.f;
			}
		}

		if (_cannon.angle <= 3.75f && _cannon.angle >= -0.6f)
		{
			_cannon.angle -= addSpeed / 500;
			if (!_isMove)
			{
				_cannon.angle += addSpeed / 240;
			}
			if (_cannon.angle <= -0.55f)
			{
				_cannon.angle = -0.55f;
			}

		}
		// 포신 움직이는 각도 갱신

		_cannon.cannonEnd.x = cosf(_cannon.angle) * _cannon.cannon + _cannon.center.x;
		_cannon.cannonEnd.y = -sinf(_cannon.angle) * _cannon.cannon + _cannon.center.y;

		if (!_isMove)
		{
			if (addSpeed > 0)
			{
				addSpeed -= SPEED;
				speed -= addSpeed;
				_loopY = speed;
				enemySpeed = 0;
			}
			else
			{
				addSpeed = 0;
				_cannon.angle = 3.75f;
			}
		}

		for (int i = 0; i < ENEMY; i++)
		{
			if (enemyCar[i].touch)
			{
				enemyCar[i].rc.top += enemyCar[i].speed;
				enemyCar[i].rc.bottom += enemyCar[i].speed;

				if (enemyCar[i].rc.top > WINSIZEY)
				{
					enemyCar[i].rc = RectMakeCenter(245 + i * 110, -100 + -100 * RND->getInt(15), _enemy->getFrameWidth(), _enemy->getFrameHeight());
					score++;

				}
				if (addSpeed == 0)
				{
					enemySpeed += SPEED;
					enemyCar[i].rc.top -= enemySpeed;
					enemyCar[i].rc.bottom -= enemySpeed;
				}
			}
		}
		_player->setFrameY(0);
		_player->setFrameX(0);

		_gaugeFront.rc.top = 330 + usedFuel / 3;

		if (_gaugeFront.rc.top >= _gaugeFront.rc.bottom)
		{
			_gaugeFront.rc.top = _gaugeBack.rc.bottom;
		}

		for (int i = 0; i < ENEMY; i++)
		{
			RECT temp;

			if (IntersectRect(&temp, &pRect.rc, &enemyCar[i].rc))
			{
				_isGame = false;
			}
		}

		if (fuel <= 0)
		{
			_isGame = false;
		}
	}
}

void mainGame::render(HDC hdc)
{
	//백버퍼에 뿌리자.
	HDC memDC = this->getBackBuffer()->getMemDC();
	//흰색 비트맵
	PatBlt(memDC, 0, 0, WINSIZEX, WINSIZEY, WHITENESS);
	//===================================================

	//_bgImage->render(memDC);
	_bgImage->loopRender(memDC,&RectMake(0,0,WINSIZEX,WINSIZEY),_loopX,_loopY);
	//_bgImage->loopAlphaRender(memDC,&RectMake(0,0,WINSIZEX,WINSIZEY),_loopX,_loopY, 255);
	if (!_isGame)
	{
		wsprintf(str, "game satart? push space", (int)addSpeed);
		TextOut(memDC, WINSIZEX/2-50, WINSIZEY/2, str, strlen(str));
		wsprintf(str, "점수 : %d", score);
		TextOut(memDC, WINSIZEX / 2 - 50, WINSIZEY / 2 + 20, str, strlen(str));

	}

	if (_isGame)
		{
		_dashboard->frameRender(memDC, 740, 20);
			LineMake(memDC, _cannon.center.x, _cannon.center.y, _cannon.cannonEnd.x, _cannon.cannonEnd.y);

		wsprintf(str, "속도 : %d", (int)addSpeed);
		TextOut(memDC, 20, 20, str, strlen(str));
		wsprintf(str, "점수 : %d", score);
		TextOut(memDC, 20, 40, str, strlen(str));
		wsprintf(str, "연료 : %d", (int)fuel);
		TextOut(memDC, 20, 60, str, strlen(str));

		if (fuel <= 0)
		{
			wsprintf(str, "게임 종료 : %d", (int)fuel);
			TextOut(memDC, 20, 60, str, strlen(str));
		}
	
		Rectangle(memDC, pRect.rc.left, pRect.rc.top, pRect.rc.right, pRect.rc.bottom);
		_player->frameRender(memDC, pRect.rc.left, pRect.rc.top);	
	
		HBRUSH brush1 = CreateSolidBrush(RGB(100, 0, 0));
		Rectangle(memDC, _gaugeBack.rc.left, _gaugeBack.rc.top, _gaugeBack.rc.right, _gaugeBack.rc.bottom);
		FillRect(memDC, &_gaugeBack.rc, brush1);
		DeleteObject(brush1);

		HBRUSH brush2 = CreateSolidBrush(RGB(220, 0, 0));
		Rectangle(memDC, _gaugeFront.rc.left, _gaugeFront.rc.top, _gaugeFront.rc.right, _gaugeFront.rc.bottom);
		FillRect(memDC, &_gaugeFront.rc, brush2);
		DeleteObject(brush2);



		for (int i = 0; i < ENEMY; i++)
		{
			Rectangle(memDC, enemyCar[i].rc.left, enemyCar[i].rc.top, enemyCar[i].rc.right, enemyCar[i].rc.bottom);
			_enemy->frameRender(memDC, enemyCar[i].rc.left, enemyCar[i].rc.top);
		}
	}
	//=================================================
	//백버퍼의 내용을 HDC에 그린다.(건드리지말것.)
	this->getBackBuffer()->render(hdc, 0, 0);
}

