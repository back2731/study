#include "stdafx.h"
#include "airHockey.h"
airHockey::airHockey()
{
}


airHockey::~airHockey()
{
}

HRESULT airHockey::init()
{
	_coat[0] = RectMakeCenter(WINSIZEX / 2, WINSIZEY / 2 + (WINSIZEY / 2 / 2), WINSIZEX, WINSIZEY / 2);
	_coat[1] = RectMakeCenter(WINSIZEX / 2, WINSIZEY / 2 / 2, WINSIZEX, WINSIZEY / 2);
	_goal[0] = RectMakeCenter(WINSIZEX / 2, WINSIZEY, WINSIZEX / 3, 10);
	_goal[1] = RectMakeCenter(WINSIZEX / 2, 0, WINSIZEX / 3, 10);

	_pacMan.speed = 0.0f;
	_pacMan.smash = false;
	_pacMan.radius = WINSIZEX / 20;
	_pacMan.x = WINSIZEX / 2;
	_pacMan.y = WINSIZEY / 2;
	_pacMan.rc = RectMakeCenter(_pacMan.x, _pacMan.y, _pacMan.radius * 2, _pacMan.radius * 2);


	_racket[0].radius = WINSIZEX / 15;
	_racket[0].x = WINSIZEX / 2;
	_racket[0].y = WINSIZEY / 2 + (WINSIZEY / 2 / 2);
	_racket[0].rc = RectMakeCenter(_racket[0].x, _racket[0].y, _racket[0].radius * 2, _racket[0].radius * 2);

	_racket[1].radius = WINSIZEX / 15;
	_racket[1].x = WINSIZEX / 2;
	_racket[1].y = WINSIZEY / 2 / 2;
	_racket[1].rc = RectMakeCenter(_racket[0].x, _racket[0].y, _racket[0].radius * 2, _racket[0].radius * 2);
	
	return S_OK;
}

void airHockey::release()
{
}

void airHockey::update()
{
	if (KEYMANAGER->isStayKeyDown(VK_RIGHT))_racket[0].x += RACKET_SPEED;
	if (KEYMANAGER->isStayKeyDown(VK_LEFT))_racket[0].x -= RACKET_SPEED;
	if (KEYMANAGER->isStayKeyDown(VK_UP))_racket[0].y -= RACKET_SPEED;
	if (KEYMANAGER->isStayKeyDown(VK_DOWN))_racket[0].y += RACKET_SPEED;

	if (KEYMANAGER->isStayKeyDown('D'))_racket[1].x += RACKET_SPEED;
	if (KEYMANAGER->isStayKeyDown('A'))_racket[1].x -= RACKET_SPEED;
	if (KEYMANAGER->isStayKeyDown('W'))_racket[1].y -= RACKET_SPEED;
	if (KEYMANAGER->isStayKeyDown('S'))_racket[1].y += RACKET_SPEED;


	//라켓 가두자
	for (int i = 0; i < 2; i++)
	{
		//왼쪽
		if (_racket[i].x - _racket[i].radius < 0)
		{
			_racket[i].x = _racket[i].radius;
		}
		//오른쪽
		else if (_racket[i].x + _racket[i].radius > WINSIZEX)
		{
			_racket[i].x = WINSIZEX - _racket[i].radius;
		}
		//위
		if (_racket[i].y - _racket[i].radius < _coat[i].top)
		{
			_racket[i].y = _coat[i].top + _racket[i].radius;
			_racket[i].angle = 2 * PI - _racket[i].angle;
		}
		//아래
		else if (_racket[i].y + _racket[i].radius > _coat[i].bottom)
		{
			_racket[i].y = _coat[i].bottom - _racket[i].radius;
			_racket[i].angle = 2 * PI - _racket[i].angle;
		}
	}

	smash();
	ballMove();

	//골인되면 점수 올리고 상태 초기화
	if (_goal[0].top <= _pacMan.y + _pacMan.radius && _goal[1].left <= _pacMan.x && _pacMan.x <= _goal[1].right)
	{
		score[1]++;
		_pacMan.x = WINSIZEX / 2;
		_pacMan.y = WINSIZEY / 2;
		_racket[0].x = WINSIZEX / 2;
		_racket[0].y = WINSIZEY / 2 + (WINSIZEY / 2 / 2);
		_racket[1].x = WINSIZEX / 2;
		_racket[1].y = WINSIZEY / 2 / 2;
		_pacMan.smash = false;
	}
	if (_goal[1].bottom >= _pacMan.y - _pacMan.radius && _goal[1].left <= _pacMan.x && _pacMan.x <= _goal[1].right)
	{
		score[0]++;
		_pacMan.x = WINSIZEX / 2;
		_pacMan.y = WINSIZEY / 2;
		_racket[0].x = WINSIZEX / 2;
		_racket[0].y = WINSIZEY / 2 + (WINSIZEY / 2 / 2);
		_racket[1].x = WINSIZEX / 2;
		_racket[1].y = WINSIZEY / 2 / 2;
		_pacMan.smash = false;
	}
}

void airHockey::render(HDC hdc)
{
	for (int i = 0; i < 2; i++)
	{
		Rectangle(hdc, _coat[i].left, _coat[i].top, _coat[i].right, _coat[i].bottom);
		Rectangle(hdc, _goal[i].left, _goal[i].top, _goal[i].right, _goal[i].bottom);
	}

	for (int i = 0; i < 2; i++)
	{
		EllipseMakeCenter(hdc, _racket[i].x, _racket[i].y, _racket[i].radius * 2, _racket[i].radius * 2);
		
	}
	EllipseMakeCenter(hdc, _pacMan.x, _pacMan.y, _pacMan.radius * 2, _pacMan.radius * 2);
	

	sprintf_s(score1, "1P 점수 : %d", score[0]);
	TextOut(hdc, 20, WINSIZEY - 40, score1, strlen(score1));
	sprintf_s(score2, "2P 점수 : %d", score[1]);
	TextOut(hdc, 20, 20, score2, strlen(score2));
}

void airHockey::ballMove()
{
	for (int i = 0; i < 2; i++)
	{
		float length = sqrt((_racket[i].x - _pacMan.x)*
			(_racket[i].x - _pacMan.x) +
			(_racket[i].y - _pacMan.y)*
			(_racket[i].y - _pacMan.y));

		if (_racket[i].radius + _pacMan.radius < length)continue;

		_pacMan.angle = getAngle(_racket[i].x, _racket[i].y, _pacMan.x, _pacMan.y);

		_pacMan.speed = 10;

		_pacMan.smash = true;
	}
}

void airHockey::smash()
{
	if (_pacMan.smash)
	{
		_pacMan.x += cosf(_pacMan.angle)* _pacMan.speed;
		_pacMan.y += -sinf(_pacMan.angle)* _pacMan.speed;

		_pacMan.rc = RectMakeCenter(_pacMan.x, _pacMan.y, _pacMan.radius * 2, _pacMan.radius * 2);

		_pacMan.speed -= 0.02f;

		if (_pacMan.x - _pacMan.radius < 0)
		{
			_pacMan.x = _pacMan.radius;
			_pacMan.angle = PI - _pacMan.angle;
		}
		else if (_pacMan.x + _pacMan.radius > WINSIZEX)
		{
			_pacMan.x = WINSIZEX-_pacMan.radius;
			_pacMan.angle = PI - _pacMan.angle;
		}
		//위
		else if (_pacMan.y - _pacMan.radius <0)
		{
			_pacMan.y = _pacMan.radius;
			_pacMan.angle = 2*PI - _pacMan.angle;
		}
		//아래
		else if (_pacMan.y + _pacMan.radius > WINSIZEY)
		{
			_pacMan.y = WINSIZEY - _pacMan.radius;
			_pacMan.angle = 2 * PI - _pacMan.angle;
		}

		if (_pacMan.speed <= 0)_pacMan.smash = false;
	}
}
