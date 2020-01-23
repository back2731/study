#include "stdafx.h"
#include "mainGame.h"
mainGame::mainGame()
{
	addGravity = 0;
	onFunc = true;
}
mainGame::~mainGame()
{
}
HRESULT mainGame::init()
{
	gameNode::init();

	Player.rc = RectMakeCenter(WINSIZEX / 2+ 300, WINSIZEY - PLAYERRECT*2, PLAYERRECT, PLAYERRECT);
	box.rc = RectMakeCenter(WINSIZEX / 2, WINSIZEY- OBSTACLERECT/2, WINSIZEX, OBSTACLERECT);
	barricadeA.rc = RectMakeCenter(WINSIZEX - 200, WINSIZEY - 150, 80, OBSTACLERECT);
	barricadeB.rc = RectMakeCenter(WINSIZEX - 400, WINSIZEY - 200, 80, OBSTACLERECT);
	barricadeC.rc = RectMakeCenter(WINSIZEX - 600, WINSIZEY - 250, 80, OBSTACLERECT);
	barricadeD.rc = RectMakeCenter(WINSIZEX - 800, WINSIZEY - 300, 80, OBSTACLERECT);
	barricadeE.rc = RectMakeCenter(WINSIZEX - 1000, WINSIZEY - 150, 80, OBSTACLERECT);

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

		if (Player.rc.left < 0)
		{
			Player.rc.left += 5.0f;
			Player.rc.right += 5.0f;
		}
	}

	if (KEYMANAGER->isStayKeyDown(VK_RIGHT))
	{
		Player.rc.left += 5.0f;
		Player.rc.right += 5.0f;
		if (Player.rc.right > WINSIZEX)
		{
			Player.rc.left -= 5.0f;
			Player.rc.right -= 5.0f;
		}
	}

	if (KEYMANAGER->isOnceKeyDown(VK_SPACE))
	{
		Player.jump = true;
		Player.border = false;
	}
	Jump(Player);
	Gravity(Player);

	CrashBox(Player, box);
	CrashBox(Player, barricadeA);
	CrashBox(Player, barricadeB);
	CrashBox(Player, barricadeC);
	CrashBox(Player, barricadeD);
	CrashBox(Player, barricadeE);
}

void mainGame::render(HDC hdc)
{
	Rectangle(hdc, box.rc.left, box.rc.top, box.rc.right, box.rc.bottom);
	Rectangle(hdc, Player.rc.left, Player.rc.top, Player.rc.right, Player.rc.bottom);
	Rectangle(hdc, barricadeA.rc.left, barricadeA.rc.top, barricadeA.rc.right, barricadeA.rc.bottom);
	Rectangle(hdc, barricadeB.rc.left, barricadeB.rc.top, barricadeB.rc.right, barricadeB.rc.bottom);
	Rectangle(hdc, barricadeC.rc.left, barricadeC.rc.top, barricadeC.rc.right, barricadeC.rc.bottom);
	Rectangle(hdc, barricadeD.rc.left, barricadeD.rc.top, barricadeD.rc.right, barricadeD.rc.bottom);
	Rectangle(hdc, barricadeE.rc.left, barricadeE.rc.top, barricadeE.rc.right, barricadeE.rc.bottom);
}

void mainGame::CrashBox(tagRect &a, tagRect &b)
{	
	if (IntersectRect(&temp, &a.rc, &b.rc))
	{
		addGravity = 0;
		a.rc.bottom = b.rc.top;
		a.rc.top = a.rc.bottom - PLAYERRECT;
		a.jump = false;
		a.border = true;
	}
	else
	{
		a.border = false;
	}
}

void mainGame::Gravity(tagRect & a)
{
	if (a.border == false)
	{
		a.rc.top += GRAVITY;
		a.rc.bottom += GRAVITY;
	}
}

void mainGame::Jump(tagRect & a)
{
	if (a.jump)
	{
		addGravity -= GRAVITY;
		a.rc.top -= JUMPPOWER + addGravity;
		a.rc.bottom -= JUMPPOWER + addGravity;
	}
}

