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
		TextOut(hdc, WINSIZEX / 2, 100, "�浹", strlen("�浹"));

		HBRUSH brush = CreateSolidBrush(RGB(255, 0, 0));
		FillRect(hdc, &_rectangle, brush);
		DeleteObject(brush);
	}
}

bool mainGame::IsCollision(RECT & rc1, RECT & rc2)
{
	/*
		���� ������ ��ŭ �浹���(�簢��)�� �ø� �� ���� �߽����� �� �ȿ� �ִٸ� �浹�̶�� �����Ѵ�.
		��, ���������� �밢�� �浹�̶�� �簢���� �������� �� �ȿ� �ִ��� �Ǵ��Ͽ� �浹ó���� �Ѵ�.
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
		// �𼭸� ó�� �κ�
		// �»��
		if (GetDistance(rc1, rc2.left, rc2.top)) return true;
		// ����
		if (GetDistance(rc1, rc2.right, rc2.top)) return true;
		// ���ϴ�
		if (GetDistance(rc1, rc2.left, rc2.bottom)) return true;
		// ���ϴ�
		if (GetDistance(rc1, rc2.right, rc2.bottom)) return true;
	}
	return false;
}

bool mainGame::GetDistance(RECT & rc, float x, float y)
{
	// Rect ������ Ư����ǥ�� ���� �Ÿ� X, Y
	float lenghX = x - (rc.left + (rc.right - rc.left) / 2);
	float lenghY = y - (rc.top + (rc.bottom - rc.top) / 2);

	float distance = lenghX * lenghX + lenghY * lenghY;

	float radius = (rc.right - rc.left) / 2;

	float radiusSqure = radius * radius;

	if (radiusSqure < distance)return false;
	
	return true;
}

