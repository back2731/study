#include "stdafx.h"
#include "mainGame.h"
mainGame::mainGame()
{
	addGravity = 0;
	count = 0;
	startLine = 1080;
	gameEnd = true;
}
mainGame::~mainGame()
{
}
HRESULT mainGame::init()
{
	gameNode::init();

	Player.rc = RectMakeCenter(WINSIZEX / 2 - 300, WINSIZEY - 500, PLAYERRECT, PLAYERRECT);
	for (int i = 0; i < BOXNUM; i++)
	{
		rndNum = RND->GetFromIntTo(0, 200);
		barriTop[i].rc		= RectMake(startLine, 0, WIDTH, HEIGHT - rndNum);
		barriUnder[i].rc	= RectMake(startLine, WINSIZEY - (WINSIZEY - HEIGHT - rndNum - GAP), WIDTH, WINSIZEY - HEIGHT - rndNum - GAP);
		startLine += 500;
		barriTop[i].speed = MAXSPEED;
		barriUnder[i].speed = MAXSPEED;
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
		for (int i = 0; i < BOXNUM; i++)
		{
			barriTop[i].touch = true;
			barriUnder[i].touch = true;
		}
		Player.jump = true;
		gameEnd = true;
		playerAddGravity = 0;
		addGravity = 0;	
	}

	Jump(Player);
	Gravity(Player);

	for (int i = 0; i < BOXNUM; i++)
	{
		// 박스가 트루이면 움직여라
		if (barriTop[i].touch &&barriUnder[i].touch)
		{
			barriTop[i].rc.left -= barriTop[i].speed;
			barriTop[i].rc.right -= barriTop[i].speed;
			barriUnder[i].rc.left -= barriUnder[i].speed;
			barriUnder[i].rc.right -= barriUnder[i].speed;
		}
		if (barriTop[i].rc.right < 0 && barriUnder[i].rc.right)
		{
			rndNum = RND->GetFromIntTo(0, 200);
			barriTop[i].rc = RectMake(startLine, 0, WIDTH, HEIGHT - rndNum);
			barriUnder[i].rc = RectMake(startLine, WINSIZEY - (WINSIZEY - HEIGHT - rndNum - GAP), WIDTH, WINSIZEY - HEIGHT - rndNum - GAP);
			startLine += 500;
			count++;
		}
	}
	CrashBox();
}

void mainGame::render(HDC hdc)
{
	Rectangle(hdc, Player.rc.left, Player.rc.top, Player.rc.right, Player.rc.bottom);
	for (int i = 0; i < BOXNUM; i++)
	{
		Rectangle(hdc, barriTop[i].rc.left, barriTop[i].rc.top, barriTop[i].rc.right, barriTop[i].rc.bottom);
		Rectangle(hdc, barriUnder[i].rc.left, barriUnder[i].rc.top, barriUnder[i].rc.right, barriUnder[i].rc.bottom);
	}

	wsprintf(str, "point : %d", count);
	TextOut(hdc, 10, 10, str, strlen(str));
}

void mainGame::CrashBox()
{
	startLine = 1080;
	for (int i = 0; i < BOXNUM; i++)
	{
		if (IntersectRect(&temp, &Player.rc, &barriTop[i].rc))
		{
			for (int i = 0; i < BOXNUM; i++)
			{			
				Player.rc = RectMakeCenter(WINSIZEX / 2 - 300, WINSIZEY - 500, PLAYERRECT, PLAYERRECT);

				rndNum = RND->GetFromIntTo(0, 200);
				barriTop[i].rc = RectMake(startLine, 0, WIDTH, HEIGHT - rndNum);
				barriUnder[i].rc = RectMake(startLine, WINSIZEY - (WINSIZEY - HEIGHT - rndNum - GAP), WIDTH, WINSIZEY - HEIGHT - rndNum - GAP);
				startLine += 500;

				barriTop[i].touch = false;
				barriUnder[i].touch = false;
				gameEnd = false;
				Player.jump = false;
				count = 0;

			} 
		}
		if (IntersectRect(&temp, &Player.rc, &barriUnder[i].rc))
		{
  			for (int i = 0; i < BOXNUM; i++)
			{
				Player.rc = RectMakeCenter(WINSIZEX / 2 - 300, WINSIZEY - 500, PLAYERRECT, PLAYERRECT);
				
				startLine = 1080;
				rndNum = RND->GetFromIntTo(0, 200);
				barriTop[i].rc = RectMake(startLine, 0, WIDTH, HEIGHT - rndNum);
				barriUnder[i].rc = RectMake(startLine, WINSIZEY - (WINSIZEY - HEIGHT - rndNum - GAP), WIDTH, WINSIZEY - HEIGHT - rndNum - GAP);
				startLine += 500;

				barriTop[i].touch = false;
				barriUnder[i].touch = false;
				gameEnd = false;
				Player.jump = false;
				count = 0;

			}
		}
	}
}

void mainGame::Gravity(tagRect & a)		// 플레이어의 환경에 주어지는 중력값
{
	if (gameEnd)
	{
		addGravity += GRAVITY;
		a.rc.top += addGravity / 4;
		a.rc.bottom += addGravity / 4;
	}
	else
	{
		addGravity = 0;
	}
}

void mainGame::Jump(tagRect & a)
{
	if (a.jump)
	{
		playerAddGravity -= GRAVITY;	// 플레이어의 감속을 시켜주는 중력값
		a.rc.top -= JUMPPOWER + playerAddGravity;
		a.rc.bottom -= JUMPPOWER + playerAddGravity;
		if (playerAddGravity <= -JUMPPOWER)
		{
			Player.jump = false;
		}
	}
}

