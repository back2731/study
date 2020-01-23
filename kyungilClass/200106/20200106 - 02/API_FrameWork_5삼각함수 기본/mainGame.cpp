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
	a = 0;
	// 캐논 초기화
	_cannon.angle = 0;					// 90도
	_cannon.cannon = 10;					// 
	_cannon.center.x = WINSIZEX / 2;		// 
	_cannon.center.y = WINSIZEY / 2;			// 

	_cannon2.angle = 0.3;					// 90도
	_cannon2.cannon = 10;					// 
	_cannon2.center.x = WINSIZEX / 2;		// 
	_cannon2.center.y = WINSIZEY / 2;			// 

	_cannon3.angle = 0.6;					// 90도
	_cannon3.cannon = 10;					// 
	_cannon3.center.x = WINSIZEX / 2;		// 
	_cannon3.center.y = WINSIZEY / 2;			// 

	_cannon4.angle = 0.9;					// 90도
	_cannon4.cannon = 10;					// 
	_cannon4.center.x = WINSIZEX / 2;		// 
	_cannon4.center.y = WINSIZEY / 2;			// 

	// 총알 구조체 초기화
	memset(_bullet, 0, sizeof(_bullet));
	memset(_bullet2, 0, sizeof(_bullet2));
	memset(_bullet3, 0, sizeof(_bullet3));
	memset(_bullet4, 0, sizeof(_bullet4));

	for (int i = 0; i < BULLETMAX; i++)
	{
		_bullet[i].speed = 5.0f;
		_bullet[i].radius = 5.0f;
		_bullet[i].isFire = false;
		_bullet[i].garavity = 0.0f;
	}
	for (int i = 0; i < BULLETMAX; i++)
	{
		_bullet2[i].speed = 5.0f;
		_bullet2[i].radius = 5.0f;
		_bullet2[i].isFire = false;
		_bullet2[i].garavity = 0.0f;
	}
	for (int i = 0; i < BULLETMAX; i++)
	{
		_bullet3[i].speed = 5.0f;
		_bullet3[i].radius = 5.0f;
		_bullet3[i].isFire = false;
		_bullet3[i].garavity = 0.0f;
	}
	for (int i = 0; i < BULLETMAX; i++)
	{
		_bullet4[i].speed = 5.0f;
		_bullet4[i].radius = 5.0f;
		_bullet4[i].isFire = false;
		_bullet4[i].garavity = 0.0f;
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
	
	if (KEYMANAGER->isStayKeyDown(VK_LEFT))
	{
		_cannon.center.x -= 1;
		_cannon2.center.x -= 1;

	}
	if (KEYMANAGER->isStayKeyDown(VK_RIGHT))
	{
		_cannon.center.x += 1;
		_cannon2.center.x += 1;

	}

	a++;
	if (a < 200)
	{
		if (a % 4 == 0)
		{
			_cannon.angle -= 0.05f;
			_cannon2.angle -= 0.05f;
			_cannon3.angle -= 0.05f;
			_cannon4.angle -= 0.05f;
		}
	}
	else if(a > 200)
	{
		if (a % 4 == 0)
		{
			_cannon.angle += 0.05f;
			_cannon2.angle += 0.05f;
			_cannon3.angle += 0.05f;
			_cannon4.angle += 0.05f;
		}
	}

	if (a % 2 == 0)
	{
	}
	BulletFire();

	// 포신 움직이는 각도 갱신

	_cannon.cannonEnd.x = cosf(_cannon.angle) * _cannon.cannon + _cannon.center.x;
	_cannon.cannonEnd.y = -sinf(_cannon.angle) * _cannon.cannon + _cannon.center.y;
	
	_cannon2.cannonEnd.x = cosf(_cannon2.angle) * _cannon2.cannon + _cannon2.center.x;
	_cannon2.cannonEnd.y = -sinf(_cannon2.angle) * _cannon2.cannon + _cannon2.center.y;

	_cannon3.cannonEnd.x = cosf(_cannon3.angle) * _cannon3.cannon + _cannon3.center.x;
	_cannon3.cannonEnd.y = -sinf(_cannon3.angle) * _cannon3.cannon + _cannon3.center.y;

	_cannon4.cannonEnd.x = cosf(_cannon4.angle) * _cannon4.cannon + _cannon4.center.x;
	_cannon4.cannonEnd.y = -sinf(_cannon4.angle) * _cannon4.cannon + _cannon4.center.y;

	BulletMove();

}

void mainGame::render(HDC hdc)
{
	EllipseMakeCenter(hdc, _cannon.center.x, _cannon.center.y, 100, 100);
	EllipseMakeCenter(hdc, _cannon2.center.x, _cannon2.center.y, 100, 100);
	EllipseMakeCenter(hdc, _cannon3.center.x, _cannon3.center.y, 100, 100);
	EllipseMakeCenter(hdc, _cannon4.center.x, _cannon4.center.y, 100, 100);

	LineMake(hdc, _cannon.center.x, _cannon.center.y, _cannon.cannonEnd.x, _cannon.cannonEnd.y);
	LineMake(hdc, _cannon2.center.x, _cannon2.center.y, _cannon2.cannonEnd.x, _cannon2.cannonEnd.y);
	LineMake(hdc, _cannon3.center.x, _cannon3.center.y, _cannon3.cannonEnd.x, _cannon3.cannonEnd.y);
	LineMake(hdc, _cannon4.center.x, _cannon4.center.y, _cannon4.cannonEnd.x, _cannon4.cannonEnd.y);

	for (int i = 0; i < BULLETMAX; i++)
	{
		if (!_bullet[i].isFire)continue;

		EllipseMakeCenter(hdc, _bullet[i].x, _bullet[i].y, _bullet[i].radius * 2, _bullet[i].radius * 2);
	}

	for (int i = 0; i < BULLETMAX; i++)
	{
		if (!_bullet2[i].isFire)continue;

	//	EllipseMakeCenter(hdc, _bullet2[i].x, _bullet2[i].y, _bullet2[i].radius * 2, _bullet2[i].radius * 2);
	}

	for (int i = 0; i < BULLETMAX; i++)
	{
		if (!_bullet3[i].isFire)continue;

	//	EllipseMakeCenter(hdc, _bullet3[i].x, _bullet3[i].y, _bullet3[i].radius * 2, _bullet3[i].radius * 2);
	}

	for (int i = 0; i < BULLETMAX; i++)
	{
		if (!_bullet4[i].isFire)continue;

	//	EllipseMakeCenter(hdc, _bullet4[i].x, _bullet4[i].y, _bullet4[i].radius * 2, _bullet4[i].radius * 2);
	}
	char str[128];

	sprintf_s((str), "앵글 : %.2f", _cannon.angle);
	TextOut(hdc, 100, 100, str, strlen(str));
	sprintf_s((str), "a : %d", a);
	TextOut(hdc, 100, 130, str, strlen(str));
}

void mainGame::BulletFire()
{
	for (int i = 0; i < BULLETMAX; i++)
	{
		if (_bullet[i].isFire)continue;
		_bullet[i].isFire = true;
		_bullet[i].x = _cannon.center.x;
		_bullet[i].y = _cannon.center.y;
		_bullet[i].angle = _cannon.angle; 
		break;
	}
	for (int i = 0; i < BULLETMAX; i++)
	{
		if (_bullet2[i].isFire)continue;
		_bullet2[i].isFire = true;
		_bullet2[i].x = _cannon2.center.x;
		_bullet2[i].y =_cannon2.center.y;
		_bullet2[i].angle = _cannon2.angle;
		break;
	}
	for (int i = 0; i < BULLETMAX; i++)
	{
		if (_bullet2[i].isFire)continue;
		_bullet3[i].isFire = true;
		_bullet3[i].x = _cannon3.center.x;
		_bullet3[i].y = _cannon3.center.y;
		_bullet3[i].angle = _cannon3.angle;
		break;
	}
	for (int i = 0; i < BULLETMAX; i++)
	{
		if (_bullet2[i].isFire)continue;
		_bullet4[i].isFire = true;
		_bullet4[i].x = _cannon4.center.x;
		_bullet4[i].y = _cannon4.center.y;
		_bullet4[i].angle = _cannon4.angle;
		break;
	}
}

void mainGame::BulletMove()
{
	for (int i = 0; i < BULLETMAX; i++)
	{
		if (!_bullet[i].isFire)continue;

		_bullet[i].x += cosf(_bullet[i].angle) * _bullet[i].speed;
		_bullet[i].y += -sinf(_bullet[i].angle) * _bullet[i].speed;

		//for (int j = i + 1; j < BULLETMAX; j++)
		//{
		//	if (_bullet[i].radius * 2 < GetDistance(_bullet[i].x, _bullet[i].y, _bullet[j].x, _bullet[j].y)) continue;

		//	_bullet[i].angle = GetAngle(_bullet[j].x, _bullet[j].y, _bullet[i].x, _bullet[i].y);
		//	_bullet[j].angle = GetAngle(_bullet[i].x, _bullet[i].y, _bullet[j].x, _bullet[j].y);
		//}

		//// 왼쪽
		//if (_bullet[i].x - _bullet[i].radius < 0)
		//{
		//	_bullet[i].angle = PI - _bullet[i].angle;
		//}

		//// 오른쪽
		//if (_bullet[i].x + _bullet[i].radius > WINSIZEX)
		//{
		//	_bullet[i].angle = PI - _bullet[i].angle;
		//}
		//// 위
		//if (_bullet[i].y - _bullet[i].radius < 0)
		//{
		//	_bullet[i].angle = 2*PI - _bullet[i].angle;
		//}
		//// 아래
		//if (_bullet[i].y + _bullet[i].radius > WINSIZEY)
		//{
		//	_bullet[i].angle = 2 * PI - _bullet[i].angle;
		//}
	}
	for (int i = 0; i < BULLETMAX; i++)
	{
		if (!_bullet2[i].isFire)continue;

		_bullet2[i].x += cosf(_bullet2[i].angle) * _bullet2[i].speed;
		_bullet2[i].y += -sinf(_bullet2[i].angle) * _bullet2[i].speed;

	}
	for (int i = 0; i < BULLETMAX; i++)
	{
		if (!_bullet3[i].isFire)continue;

		_bullet3[i].x += cosf(_bullet3[i].angle) * _bullet3[i].speed;
		_bullet3[i].y += -sinf(_bullet3[i].angle) * _bullet3[i].speed;

	}
	for (int i = 0; i < BULLETMAX; i++)
	{
		if (!_bullet4[i].isFire)continue;

		_bullet4[i].x += cosf(_bullet4[i].angle) * _bullet4[i].speed;
		_bullet4[i].y += -sinf(_bullet4[i].angle) * _bullet4[i].speed;

	}
}

