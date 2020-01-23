#include "stdafx.h"
#include "player.h"

bool player::up = false;
bool player::down = false;
bool player::left = false;
bool player::right = false;


player::player()
{
}


player::~player()
{
}

HRESULT player::init()
{
	playerRect = RectMakeCenter(WINSIZEX / 2, WINSIZEY / 2, 50, 50);

	return S_OK;
}

void player::release()
{
}

void player::update()
{
	if (KEYMANAGER->isStayKeyDown(VK_LEFT))
	{
		playerRect.left -= PLAYERSPEED;
		playerRect.right -= PLAYERSPEED;
	}

	//오른쪽
	if (KEYMANAGER->isStayKeyDown(VK_RIGHT))
	{
		playerRect.left += PLAYERSPEED;
		playerRect.right += PLAYERSPEED;
	}

	//위
	if (KEYMANAGER->isStayKeyDown(VK_UP))
	{
		playerRect.top -= PLAYERSPEED;
		playerRect.bottom -= PLAYERSPEED;
	}

	//아래
	if (KEYMANAGER->isStayKeyDown(VK_DOWN))
	{
		playerRect.top += PLAYERSPEED;
		playerRect.bottom += PLAYERSPEED;
	}
}

void player::render()
{
	Rectangle(getMemDC(), playerRect.left, playerRect.top, playerRect.right, playerRect.bottom);
}

void player::setPlayerPositionUp()
{
	playerRect = RectMakeCenter(WINSIZEX / 2, WINSIZEY - 100, 50, 50);
}

void player::setPlayerPositionDown()
{
	playerRect = RectMakeCenter(WINSIZEX / 2, 100, 50, 50);
}

void player::setPlayerPositionLeft()
{
	playerRect = RectMakeCenter(WINSIZEX - 100, WINSIZEY / 2, 50, 50);
}

void player::setPlayerPositionRight()
{
	playerRect = RectMakeCenter(100, WINSIZEY / 2, 50, 50);
}

