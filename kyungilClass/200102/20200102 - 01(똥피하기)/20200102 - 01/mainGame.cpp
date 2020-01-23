#include "stdafx.h"
#include "mainGame.h"
mainGame::mainGame()
{
	count = 0;
	gameEnd = true;
}
mainGame::~mainGame()
{
}
HRESULT mainGame::init()
{
	gameNode::init();

	//rc = RectMakeCenter(WINSIZEX / 2, WINSIZEY / 2, 100, 100);
	
	for (int i = 0; i < BOXNUM; i++)
	{
		box[i].touch = false;
		box[i].rc = RectMakeCenter(10 + i * 40+RND->GetInt(RNDNUM), -OBSTACLERECT - RND->GetInt(RNDNUM), OBSTACLERECT, OBSTACLERECT);
	}
	for (int i = 0; i < BOXNUM; i += 2)
	{
		box[i].speed = RND->GetInt(MAXSPEED) + RND->GetInt(10);
	}
	for (int i = 1; i < BOXNUM; i += 2)
	{
		box[i].speed = RND->GetInt(MAXSPEED) + RND->GetInt(8);
	}
	Player.rc = RectMakeCenter(WINSIZEX / 2, WINSIZEY - (PLAYERRECT / 2), PLAYERRECT, PLAYERRECT);
	
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
		CrashBox();
	}
	if (KEYMANAGER->isStayKeyDown(VK_RIGHT))
	{
		Player.rc.left += 5.0f;
		Player.rc.right += 5.0f;
		CrashBox();
	}

	if (KEYMANAGER->isOnceKeyDown(VK_SPACE))
	{
		for (int i = 0; i < BOXNUM; i++)
		{
			box[i].touch = true;
		}
		gameEnd = true;
		count = 0;
	}

	for (int i = 0; i < BOXNUM; i++)
	{
		// 박스가 트루이면 움직여라
		if (box[i].touch)
		{
			box[i].rc.top += box[i].speed;
			box[i].rc.bottom += box[i].speed;
		}
		if (box[i].rc.bottom > WINSIZEY)
		{
			box[i].rc = RectMakeCenter(10 + i * 40 + RND->GetInt(RNDNUM), -OBSTACLERECT - RND->GetInt(RNDNUM), OBSTACLERECT, OBSTACLERECT);
			count++;
		}
	}

	CrashBox();

}

void mainGame::render(HDC hdc)
{
	//Rectangle(hdc, rc.left, rc.top, rc.right, rc.bottom);

	for (int i = 0; i < BOXNUM; i++)
	{
		Rectangle(hdc, box[i].rc.left, box[i].rc.top, box[i].rc.right, box[i].rc.bottom);
	}

	Rectangle(hdc, Player.rc.left, Player.rc.top, Player.rc.right, Player.rc.bottom);
	

	if(gameEnd == true)
	{
		wsprintf(str, "point : %d", count);
		TextOut(hdc, 10, 10, str, strlen(str));
	}
	else
	{
		wsprintf(str, "point : %d", count);
		TextOut(hdc, WINSIZEX / 2 - 30, WINSIZEY / 2 - 30, str, strlen(str));

		wsprintf(str, "restart? Push Space bar");
		TextOut(hdc, WINSIZEX / 2 - 70, WINSIZEY / 2, str, strlen(str));
	}
}

void mainGame::CrashBox()
{
	for (int i = 0; i < BOXNUM; i++)
	{
		if (IntersectRect(&temp, &Player.rc, &box[i].rc))
		{
			for (int i = 0; i < BOXNUM; i++)
			{
				box[i].touch = false;
				box[i].rc = RectMakeCenter(10 + i * 40 + RND->GetInt(RNDNUM), -OBSTACLERECT - RND->GetInt(RNDNUM), OBSTACLERECT, OBSTACLERECT);
				gameEnd = false;
			}
		}
	}
}
