#include "stdafx.h"
#include "player.h"

player::player()
{
}


player::~player()
{
}

HRESULT player::init()
{
	playerImage = IMAGEMANAGER->addFrameImage("레이무", "images/reimu.bmp", 560, 300, 8, 3, true, RGB(255, 0, 255));
	playerRect = RectMakeCenter(400, 650, playerImage->getFrameWidth(), playerImage->getFrameHeight());
	
	isMove  = false;
	isLeft  = false;
	
	frameIndex = 0;
	return S_OK;
}

void player::release()
{
}

void player::update()
{
	// 왼쪽
	if (KEYMANAGER->isStayKeyDown(VK_LEFT))
	{
		isMove = true;
		isLeft = true;
		if (KEYMANAGER->isStayKeyDown(VK_SHIFT))
		{
			playerRect.left		-= PUSHSHIFTSPEED;
			playerRect.right	-= PUSHSHIFTSPEED;
			if (playerRect.left <= 85)
			{
				playerRect.left		+= PUSHSHIFTSPEED;
				playerRect.right	+= PUSHSHIFTSPEED;
			}
		}
		else
		{
			playerRect.left		-= PLAYERSPEED;
			playerRect.right	-= PLAYERSPEED;
			if (playerRect.left <= 85)
			{
				playerRect.left		+= PLAYERSPEED;
				playerRect.right	+= PLAYERSPEED;
			}
		}
	}

	//오른쪽
	if (KEYMANAGER->isStayKeyDown(VK_RIGHT))
	{
		isMove = true;
		isLeft = false;
		if (KEYMANAGER->isStayKeyDown(VK_SHIFT))
		{
			playerRect.left		+= PUSHSHIFTSPEED;
			playerRect.right	+= PUSHSHIFTSPEED;
			if (playerRect.right >= 720)
			{
				playerRect.left		-= PUSHSHIFTSPEED;
				playerRect.right	-= PUSHSHIFTSPEED;
			}
		}
		else
		{
			playerRect.left		+= PLAYERSPEED;
			playerRect.right	+= PLAYERSPEED;
			if (playerRect.right >= 720)
			{
				playerRect.left		-= PLAYERSPEED;
				playerRect.right	-= PLAYERSPEED;
			}
		}
	}

	//위
	if (KEYMANAGER->isStayKeyDown(VK_UP))
	{
		if (KEYMANAGER->isStayKeyDown(VK_SHIFT))
		{
			playerRect.top		-= PUSHSHIFTSPEED;
			playerRect.bottom	-= PUSHSHIFTSPEED;
			if (playerRect.top <= 42)
			{
				playerRect.top += PUSHSHIFTSPEED;
				playerRect.bottom += PUSHSHIFTSPEED;
			}
		}
		else
		{
			playerRect.top		-= PLAYERSPEED;
			playerRect.bottom	-= PLAYERSPEED;
			if (playerRect.top <= 42)
			{
				playerRect.top		+= PLAYERSPEED;
				playerRect.bottom	+= PLAYERSPEED;
			}
		}
	}

	//아래
	if (KEYMANAGER->isStayKeyDown(VK_DOWN))
	{
		if (KEYMANAGER->isStayKeyDown(VK_SHIFT))
		{
			playerRect.top		+= PUSHSHIFTSPEED;
			playerRect.bottom	+= PUSHSHIFTSPEED;
			if (playerRect.top >= 670)
			{
				playerRect.top		-= PUSHSHIFTSPEED;
				playerRect.bottom	-= PUSHSHIFTSPEED;
			}
		}
		else
		{
			playerRect.top		+= PLAYERSPEED;
			playerRect.bottom	+= PLAYERSPEED;
			if (playerRect.top >= 670)
			{
				playerRect.top		-= PLAYERSPEED;
				playerRect.bottom	-= PLAYERSPEED;
			}
		}
	}

	// 움직임을 멈추면 false 
	if (KEYMANAGER->isOnceKeyUp(VK_LEFT) || KEYMANAGER->isOnceKeyUp(VK_RIGHT) 
	   || KEYMANAGER->isOnceKeyUp(VK_UP) || KEYMANAGER->isOnceKeyUp(VK_DOWN))
	{
		isMove = false;
	}
	if (KEYMANAGER->isStayKeyDown('Z'))
	{
		count++;
		//if (count % 6 == 0)
		//{
		//	BULLETMANAGER->playerCommonBulletFire(playerRect.right - (playerRect.right - playerRect.left) / 2, playerRect.top - 50);
		//}
		//if (count % 15 == 0)
		//{
		//	BULLETMANAGER->playerHomingBulletFire(playerRect.right - (playerRect.right - playerRect.left) / 2 - 50, playerRect.top - 50);
		//}
		if (count % 15 == 0)
		{
			BULLETMANAGER->playerHomingBulletFire(playerRect.right - (playerRect.right - playerRect.left) / 2 + 50, playerRect.top - 50);
		}
	}
	BULLETMANAGER->playerBulletCollision();
	BULLETMANAGER->playerCommonBulletMove();
	BULLETMANAGER->playerHomingBulletMove();

	if (!isMove)		// 움직이지 않는 상태
	{
		frameCount++;
		playerImage->setFrameY(0);
		if (frameCount % FRAMESPEED == 0)
		{
			frameCount = 0;
			if (frameIndex >= playerImage->getMaxFrameX())
			{
				frameIndex = 0;
			}
			playerImage->setFrameX(frameIndex);
			frameIndex++;
		}
	}
	else				// 움직이는 상태
	{
		if (isLeft)
		{
			frameCount++;
			playerImage->setFrameY(1);
			if (frameCount % FRAMESPEED == 0)
			{
				frameCount = 0;
				if (frameIndex >= playerImage->getMaxFrameX())
				{
					frameIndex = 4;
				}
				playerImage->setFrameX(frameIndex);
				frameIndex++;
			}
		}
		else
		{
			frameCount++;
			playerImage->setFrameY(2);
			if (frameCount % FRAMESPEED == 0)
			{
				frameCount = 0;
				if (frameIndex >= playerImage->getMaxFrameX())
				{
					frameIndex = 4;
				}
				playerImage->setFrameX(frameIndex);
				frameIndex++;
			}
		}
	}

	// 플레이어 히트박스 업데이트
	playerHitRect = RectMakeCenter((playerRect.left + (playerRect.right - playerRect.left) / 2),
		(playerRect.top + (playerRect.bottom - playerRect.top) / 2), 8, 8);
}

void player::render()
{

	if (KEYMANAGER->isToggleKey(VK_TAB))
	{
		//Rectangle(getMemDC(), testRect.left, testRect.top, testRect.right, testRect.bottom);
		Rectangle(getMemDC(), playerRect.left, playerRect.top, playerRect.right, playerRect.bottom);
	}

	IMAGEMANAGER->frameRender("레이무", getMemDC(), playerRect.left, playerRect.top);

	if (KEYMANAGER->isToggleKey(VK_F2))
	{
		Rectangle(getMemDC(), playerHitRect.left, playerHitRect.top, playerHitRect.right, playerHitRect.bottom);
	}

	BULLETMANAGER->playerCommonBulletRender();
	BULLETMANAGER->playerHomingBulletRender();

	sprintf_s(str, "count :  %d", count);
	TextOut(getMemDC(), 400, 50, str, strlen(str));
	
	sprintf_s(str, "총알 히트 :  %d", BULLETMANAGER->collisionCheck());
	TextOut(getMemDC(), 400, 100, str, strlen(str));
}
