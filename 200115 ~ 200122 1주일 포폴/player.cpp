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
	
	playerHitRect = RectMakeCenter((playerRect.left + (playerRect.right - playerRect.left) / 2),
		(playerRect.top + (playerRect.bottom - playerRect.top) / 2), 8, 8);

	isMove  = false;
	isLeft  = false;

	scoreUi = IMAGEMANAGER->findImage("UIScore");
	powerUi = IMAGEMANAGER->findImage("UIPower");
	hpUi  = IMAGEMANAGER->findImage("UIHP");

	indexOne = IMAGEMANAGER->findImage("score");
	indexTen = IMAGEMANAGER->findImage("score");
	indexHundred = IMAGEMANAGER->findImage("score");
	indexThousand = IMAGEMANAGER->findImage("score");
	indexTenThousand = IMAGEMANAGER->findImage("score");
	indexHundredThousand = IMAGEMANAGER->findImage("score");
	indexMillion = IMAGEMANAGER->findImage("score");	
	
	score = 0;
	power = 0;
	life = 100;

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
		if (power >= 0 && power < 20)
		{
			if (count % 6 == 0)
			{
				BULLETMANAGER->playerCommonBulletFire(playerRect.right - (playerRect.right - playerRect.left) / 2, playerRect.top - 20);
			}
		}
		else if (power >= 20 && power < 50)
		{
			if (count % 6 == 0)
			{
				BULLETMANAGER->playerCommonBulletFire(playerRect.right - (playerRect.right - playerRect.left) / 2, playerRect.top - 20);
			}
			if (count % 15 == 0)
			{
				BULLETMANAGER->playerHomingBulletFire(playerLeftCannon.right - (playerLeftCannon.right - playerLeftCannon.left) / 2,
					playerLeftCannon.top + (playerLeftCannon.bottom - playerLeftCannon.top) / 2);
			}
			if (count % 15 == 0)
			{
				BULLETMANAGER->playerHomingBulletFire(playerRightCannon.right - (playerRightCannon.right - playerRightCannon.left) / 2,
					playerRightCannon.top + (playerRightCannon.bottom - playerRightCannon.top) / 2);
			}
		}
		else
		{
			if (count % 5 == 0)
			{
				BULLETMANAGER->playerCommonBulletFire(playerRect.right - (playerRect.right - playerRect.left) / 2 - 20, playerRect.top - 20);
			}
			if (count % 5 == 0)
			{
				BULLETMANAGER->playerCommonBulletFire(playerRect.right - (playerRect.right - playerRect.left) / 2 + 20, playerRect.top - 20);
			}
			if (count % 16 == 0)
			{
				BULLETMANAGER->playerHomingBulletFire(playerLeftCannon.right - (playerLeftCannon.right - playerLeftCannon.left) / 2,
					playerLeftCannon.top + (playerLeftCannon.bottom - playerLeftCannon.top) / 2);
			}
			if (count % 16 == 0)
			{
				BULLETMANAGER->playerHomingBulletFire(playerRightCannon.right - (playerRightCannon.right - playerRightCannon.left) / 2,
					playerRightCannon.top + (playerRightCannon.bottom - playerRightCannon.top) / 2);
			}
		}
	}

	BULLETMANAGER->playerBulletCollision();
	BULLETMANAGER->playerCommonBulletMove();
	BULLETMANAGER->playerHomingBulletMove();	
	BULLETMANAGER->itemSet(SCORE, RND->getFromIntTo(200, 700) , 50, ANGLE_270, 3.0f, 400);
	BULLETMANAGER->itemSet(POWER, RND->getFromIntTo(200, 700) , 50, ANGLE_270, 4.0f, 400);
	BULLETMANAGER->itemSet(LIFE, RND->getFromIntTo(200, 700), 50,  ANGLE_270, 5.0f, 400);

	BULLETMANAGER->itemMove(SCORE);
	BULLETMANAGER->itemMove(POWER);
	BULLETMANAGER->itemMove(LIFE);
	BULLETMANAGER->itemCollision();


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
	
	// 캐논 박스 업데이트
	playerLeftCannon = RectMakeCenter(getPlayerRectX() - 50, getPlayerRectY() + 10, 15, 15);
	playerRightCannon = RectMakeCenter(getPlayerRectX() + 50, getPlayerRectY() + 10, 15, 15);

}

void player::render()
{
	if (KEYMANAGER->isToggleKey(VK_TAB))
	{
		//Rectangle(getMemDC(), testRect.left, testRect.top, testRect.right, testRect.bottom);
		Rectangle(getMemDC(), playerRect.left, playerRect.top, playerRect.right, playerRect.bottom);
		Rectangle(getMemDC(), playerLeftCannon.left, playerLeftCannon.top, playerLeftCannon.right, playerLeftCannon.bottom);
		Rectangle(getMemDC(), playerRightCannon.left, playerRightCannon.top, playerRightCannon.right, playerRightCannon.bottom);
	}

	IMAGEMANAGER->frameRender("레이무", getMemDC(), playerRect.left, playerRect.top);
	if (KEYMANAGER->isStayKeyDown(VK_SHIFT))
	{
		IMAGEMANAGER->render("playerHitImage", getMemDC(), playerHitRect.left - 2, playerHitRect.top - 2);
	}

	IMAGEMANAGER->render("playerCannon", getMemDC(), playerLeftCannon.left, playerLeftCannon.top);
	IMAGEMANAGER->render("playerCannon", getMemDC(), playerRightCannon.left, playerRightCannon.top);

	BULLETMANAGER->playerCommonBulletRender();
	BULLETMANAGER->playerHomingBulletRender();
	BULLETMANAGER->itemRender(SCORE);
	BULLETMANAGER->itemRender(POWER);
	BULLETMANAGER->itemRender(LIFE);

	//sprintf_s(str, "count :  %d", count);
	//TextOut(getMemDC(), 400, 50, str, strlen(str));
	//
	//sprintf_s(str, "총알 히트 :  %d", BULLETMANAGER->collisionCheck());
	//TextOut(getMemDC(), 400, 100, str, strlen(str));
}

void player::scoreRender()
{
	scoreUi->render(getMemDC(), 750, 150);
	indexMillion->frameRender(getMemDC(), 820, 150, score % 10000000 / 1000000, 0);
	indexHundredThousand->frameRender(getMemDC(), 838, 150, score % 1000000 / 100000, 0);
	indexTenThousand->frameRender(getMemDC(), 856, 150, score % 100000 / 10000, 0);
	indexThousand->frameRender(getMemDC(), 874, 150, score % 10000 / 1000, 0);
	indexHundred->frameRender(getMemDC(), 892, 150, score % 1000 / 100, 0);
	indexTen->frameRender(getMemDC(), 910, 150, score % 100 / 10, 0);
	indexOne->frameRender(getMemDC(), 928, 150, score % 10, 0);

	powerUi->render(getMemDC(), 750, 200);
	indexHundred->frameRender(getMemDC(), 820, 200, 0, 0);
	indexTen->frameRender(getMemDC(), 838, 200, power % 100 / 10 , 0);
	indexOne->frameRender(getMemDC(), 856, 200, power % 10 , 0);

	hpUi->render(getMemDC(), 750, 250);
	indexThousand->frameRender(getMemDC(), 820, 250, life % 10000 / 1000, 0);
	indexHundred->frameRender(getMemDC(), 838, 250, life % 1000 / 100, 0);
	indexTen->frameRender(getMemDC(), 856, 250, life % 100 / 10, 0);
	indexOne->frameRender(getMemDC(), 874, 250, life % 10, 0);


}
