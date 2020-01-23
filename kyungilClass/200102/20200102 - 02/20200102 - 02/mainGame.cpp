#include "stdafx.h"
#include "mainGame.h"
mainGame::mainGame()
{
	jump = true;
	a = 0;

}
mainGame::~mainGame()
{
}
HRESULT mainGame::init()
{
	gameNode::init();

	//rc = RectMakeCenter(WINSIZEX / 2, WINSIZEY / 2, 100, 100);
	Player.rc = RectMakeCenter(WINSIZEX / 2+ 300, 400, PLAYERRECT, PLAYERRECT);
	box.rc = RectMakeCenter(WINSIZEX / 2 + 100, WINSIZEY - (OBSTACLERECT / 2), OBSTACLERECT, OBSTACLERECT);


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
		Player.rc.left -= 5.0f;
		Player.rc.right -= 5.0f;
	}

	if (KEYMANAGER->isStayKeyDown(VK_RIGHT))
	{
		Player.rc.left += 5.0f;
		Player.rc.right += 5.0f;
	}
	if (KEYMANAGER->isOnceKeyDown(VK_SPACE))
	{
		Player.jump = true;
	}
	
	if (Player.jump)
	{
		a -= GRAVITY;
		Player.rc.top -= JUMPPOWER + a;
		Player.rc.bottom -= JUMPPOWER + a;
	}
	else
	{

	}

}

void mainGame::render(HDC hdc)
{
	Rectangle(hdc, box.rc.left, box.rc.top, box.rc.right, box.rc.bottom);
	Rectangle(hdc, Player.rc.left, Player.rc.top, Player.rc.right, Player.rc.bottom);
}

void mainGame::CrashBox()
{
	for (int i = 0; i < BOXNUM; i++)
	{
		if (IntersectRect(&temp, &Player.rc, &box.rc))
		{
			
		}
	}
}
