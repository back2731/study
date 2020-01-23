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

	_ball.speed = 5.0f;
	_ball.radius = 30.0f;
	_ball.x = WINSIZEX / 2;
	_ball.y= WINSIZEY / 2;
	_ball.collision = false;

	checkCollision = RectMakeCenter(_ball.x, _ball.y, 60, 60);

	_player.speed = 5.0f;
	_player.radius = 30.0f;

	enemyGoal = RectMakeCenter(25, WINSIZEY/2, 50, 300);
	myGoal = RectMakeCenter(WINSIZEX - 25, WINSIZEY / 2, 50, 300);
	field = RectMakeCenter(WINSIZEX / 2, WINSIZEY / 2, 100, 100);

	return S_OK;
}

void mainGame::release()
{
	gameNode::release();
}

void mainGame::update()
{
	gameNode::update();
	_player.x = m_ptMouse.x;
	_player.y = m_ptMouse.y;

	BulletMove();
	if (IsCollision(checkCollision, enemyGoal))
	{
		_ball.collision = false;
		_ball.x = WINSIZEX / 2;
		_ball.y = WINSIZEY / 2;
		myscore++;
	}
	if (IsCollision(checkCollision, myGoal))
	{
		_ball.collision = false;
		_ball.x = WINSIZEX / 2;
		_ball.y = WINSIZEY / 2;
		enemyscore++;
	}
	checkCollision = RectMakeCenter(_ball.x, _ball.y, 60, 60);
}

void mainGame::render(HDC hdc)
{
	Rectangle(hdc, field.left, field.top, field.right, field.bottom);
	EllipseMakeCenter(hdc, _ball.x, _ball.y, _ball.radius * 2, _ball.radius * 2);

	EllipseMakeCenter(hdc, _player.x, _player.y, _player.radius * 2, _player.radius * 2);

	Rectangle(hdc, enemyGoal.left, enemyGoal.top, enemyGoal.right, enemyGoal.bottom);
	Rectangle(hdc, myGoal.left, myGoal.top, myGoal.right, myGoal.bottom);

	if (KEYMANAGER->isToggleKey(VK_TAB))
	{
		Rectangle(hdc, checkCollision.left, checkCollision.top, checkCollision.right, checkCollision.bottom);
	}
	wsprintf(str, "���� ���� : %d \ ���� ���� : %d", myscore, enemyscore);
	TextOut(hdc, 10, 10, str, strlen(str));


}

void mainGame::BulletMove()
{
	if (_ball.radius + _player.radius > GetDistance(_ball.x, _ball.y, _player.x, _player.y))
	{
		_ball.collision = true;
		_ball.x += cosf(_ball.angle) * _ball.speed;
		_ball.y += -sinf(_ball.angle) * _ball.speed;

		_ball.angle = GetAngle(_player.x, _player.y, _ball.x, _ball.y);
	}	
	
	if (_ball.collision)
	{
		_ball.x += cosf(_ball.angle) * (_ball.speed);
		_ball.y += -sinf(_ball.angle) * (_ball.speed);
	}

	// ����
	if (_ball.x - _ball.radius < 0)
	{
		_ball.angle = PI - _ball.angle;
	}

	// ������
	if (_ball.x + _ball.radius > WINSIZEX)
	{
		_ball.angle = PI - _ball.angle;
	}
	// ��
	if (_ball.y - _ball.radius < 0)
	{
		_ball.angle = 2*PI - _ball.angle;
	}
	// �Ʒ�
	if (_ball.y + _ball.radius > WINSIZEY)
	{
		_ball.angle = 2 * PI - _ball.angle;
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
		if (RectGetDistance(rc1, rc2.left, rc2.top)) return true;
		// ����
		if (RectGetDistance(rc1, rc2.right, rc2.top)) return true;
		// ���ϴ�
		if (RectGetDistance(rc1, rc2.left, rc2.bottom)) return true;
		// ���ϴ�
		if (RectGetDistance(rc1, rc2.right, rc2.bottom)) return true;
	}
	return false;
}

bool mainGame::RectGetDistance(RECT & rc, float x, float y)
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



