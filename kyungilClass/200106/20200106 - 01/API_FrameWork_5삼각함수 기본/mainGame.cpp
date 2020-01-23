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

	_rectangle = RectMakeCenter(WINSIZEX / 2, WINSIZEY / 2, 100, 100);
	_isCollision = false;

	return S_OK;
}

void mainGame::release()
{
	gameNode::release();
}

void mainGame::update()
{
	gameNode::update();
	
	_ellipse = RectMakeCenter(m_ptMouse.x, m_ptMouse.y, 100, 100);

	if (IsCollision(_rectangle, _ellipse))
	{
		_isCollision = true;
	}
	else
	{
		_isCollision = false;
	}

	
}

void mainGame::render(HDC hdc)
{
	Rectangle(hdc, _rectangle.left, _rectangle.top, _rectangle.right, _rectangle.bottom);
	Ellipse(hdc, _ellipse.left, _ellipse.top, _ellipse.right, _ellipse.bottom);


	if (_isCollision)
	{
		TextOut(hdc, WINSIZEX / 2, 100, "충돌", strlen("충돌"));

		HBRUSH brush = CreateSolidBrush(RGB(255, 0, 0));
		FillRect(hdc, &_rectangle, brush);
		DeleteObject(brush);
	}
}

bool mainGame::IsCollision(RECT & rc1, RECT & rc2)
{
	/*
		원의 반지름 만큼 충돌대상(사각형)을 늘린 후 원의 중심점이 그 안에 있다면 충돌이라고 판정한다.
		단, 예외적으로 대각선 충돌이라면 사각형의 꼭지점이 원 안에 있는지 판단하여 충돌처리를 한다.
	*/
	
	int X = rc1.left + (rc1.right - rc1.left) / 2;
	int Y = rc1.top + (rc1.bottom - rc1.top) / 2;

	int radius = (rc1.right - rc1.left) / 2;

	if ((rc2.left <= X && X <= rc2.right) || (rc2.top <= Y && Y <= rc2.bottom))
	{
		RECT rcTemp;
		rcTemp.left = rc2.left - radius;
		rcTemp.top = rc2.top - radius;
		rcTemp.right = rc2.right + radius;
		rcTemp.bottom = rc2.bottom + radius;

		if ((rcTemp.left <= X && X <= rcTemp.right) && (rcTemp.top <= Y && Y <= rcTemp.bottom))
		{
			return true;
		}
	}
	else
	{
		// 모서리 처리 부분
		// 좌상단
		if (GetDistance(rc1, rc2.left, rc2.top)) return true;
		// 우상단
		if (GetDistance(rc1, rc2.right, rc2.top)) return true;
		// 좌하단
		if (GetDistance(rc1, rc2.left, rc2.bottom)) return true;
		// 우하단
		if (GetDistance(rc1, rc2.right, rc2.bottom)) return true;
	}
	return false;
}

bool mainGame::GetDistance(RECT & rc, float x, float y)
{
	// Rect 중점과 특정좌표로 부터 거리 X, Y
	float lenghX = x - (rc.left + (rc.right - rc.left) / 2);
	float lenghY = y - (rc.top + (rc.bottom - rc.top) / 2);

	float distance = lenghX * lenghX + lenghY * lenghY;

	float radius = (rc.right - rc.left) / 2;

	float radiusSqure = radius * radius;

	if (radiusSqure < distance)return false;
	
	return true;
}

