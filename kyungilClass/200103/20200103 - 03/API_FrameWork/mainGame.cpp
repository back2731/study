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

	_player1 = RectMakeCenter(WINSIZEX / 2 - 400, WINSIZEY / 2, 100, 50);
	_player2 = RectMakeCenter(WINSIZEX / 2 + 400, WINSIZEY / 2, 100, 50);

	_gaugeFront = RectMakeCenter(WINSIZEX / 2 + 300, 100, 400, 50);
	_gaugeBack = RectMakeCenter(WINSIZEX / 2 + 300, 100, 400, 50);

	_r = 0;
	_g = 255;

	for (int i = 0; i < BULLETMAX; i++)
	{
		_bullet[i].speed = 5.0f;
		_bullet[i].isFire = false;
	}


	return S_OK;
}

void mainGame::release()
{
	gameNode::release();
}

void mainGame::update()
{
	gameNode::update();
	PlayerKeyControl();
	BulletMove();
	Collision();
}

void mainGame::render(HDC hdc)
{
	Rectangle(hdc, _player1.left, _player1.top, _player1.right, _player1.bottom);
	Rectangle(hdc, _player2.left, _player2.top, _player2.right, _player2.bottom);
	Rectangle(hdc, _gaugeBack.left, _gaugeBack.top, _gaugeBack.right, _gaugeBack.bottom);

	HBRUSH brush = CreateSolidBrush(RGB(_r, _g, 0));
	Rectangle(hdc, _gaugeFront.left, _gaugeFront.top, _gaugeFront.right, _gaugeFront.bottom);
	FillRect(hdc, &_gaugeFront, brush);
	DeleteObject(brush);

	GaugeDraw();

	for (int i = 0; i < BULLETMAX; i++)
	{
		if (!_bullet[i].isFire)continue;
		Ellipse(hdc, _bullet[i].rc.left, _bullet[i].rc.top, _bullet[i].rc.right, _bullet[i].rc.bottom);
	}

}

void mainGame::BulletFire()
{
	for (int i = 0; i < BULLETMAX; i++)
	{
		// 발사된 총알은 영향을 주지 말자.
		if (_bullet[i].isFire)continue;
		
		_bullet[i].isFire = true;
		_bullet[i].rc = RectMakeCenter(_player1.right + 15, _player1.top + (_player1.bottom - _player1.top) / 2, 20, 20);
		break;
	}
}

void mainGame::BulletMove()
{
	for (int i = 0; i < BULLETMAX; i++)
	{
		if (!_bullet[i].isFire)continue;

		_bullet[i].rc.left += _bullet[i].speed;
		_bullet[i].rc.right += _bullet[i].speed;
	}
}

void mainGame::GaugeDraw()
{
	if (_gaugeFront.right - _gaugeFront.left <= 200)
	{
		_r = 200;
	}
	if (_gaugeFront.right - _gaugeFront.left <= 80)
	{
		_r = 255;
		_g = 0;
	}
}

void mainGame::Collision()
{
	for (int i = 0; i < BULLETMAX; i++)
	{
		RECT temp;

		if (IntersectRect(&temp, &_bullet[i].rc, &_player2))
		{
			_bullet[i].isFire = false;
			_bullet[i].rc = RectMakeCenter(_player1.right + 15, _player1.top + (_player1.bottom - _player1.top) / 2, 20, 20);
			_gaugeFront.left += 20;

			if (_gaugeFront.left >= _gaugeFront.right)
			{
				_gaugeFront.left = _gaugeBack.right;
			}
		}
	}
}

void mainGame::PlayerKeyControl()
{
	if (KEYMANAGER->isStayKeyDown(VK_UP))
	{
		_player1.top -= 5.0f;
		_player1.bottom -= 5.0f;
	}
	if (KEYMANAGER->isStayKeyDown(VK_DOWN))
	{
		_player1.top += 5.0f;
		_player1.bottom += 5.0f;
	}
	if (KEYMANAGER->isOnceKeyDown(VK_SPACE)) 
	{
		BulletFire();
	}
}
