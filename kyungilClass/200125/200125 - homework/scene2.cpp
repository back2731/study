#include "stdafx.h"
#include "scene2.h"
scene2::scene2()
{
}

scene2::~scene2()
{
}

HRESULT scene2::init()
{
	IMAGEMANAGER->addImage("stage1", "images/stage1.bmp", WINSIZEX, WINSIZEY, true, RGB(255, 0, 255));
	playerImage = IMAGEMANAGER->addFrameImage("move", "images/move.bmp", 152, 200, 4, 5, true, RGB(255, 0, 255));

	// ÇÃ·¹ÀÌ¾î
	player = RectMakeCenter(800, 668, 20, 40);

	// ¿ÞÂÊ	º®
	leftWall = RectMake(10, 55, 48, 662);

	// ¿À¸¥ÂÊ º®
	rightWall[0] = RectMake(965, 55, 48, 662);
	rightWall[1] = RectMake(854, 55, 23, 550);


	// 5Ãþ
	floor[0] = RectMake(57, 250, 85, 10);
	floor[1] = RectMake(170, 250, 115, 10);
	floor[2] = RectMake(313, 250, 60, 10);
	floor[3] = RectMake(400, 250, 60, 10);
	floor[4] = RectMake(485, 250, 370, 10);

	// 4Ãþ
	floor[5] = RectMake(57, 360, 200, 10);
	floor[6] = RectMake(285, 360, 455, 10);
	floor[7] = RectMake(770, 360, 85, 10);

	// 3Ãþ
	floor[8] = RectMake(57, 470, 170, 10);
	floor[9] = RectMake(255, 470, 600, 10);

	// 2Ãþ
	floor[10] = RectMake(57, 580, 255, 10);
	floor[11] = RectMake(345, 580, 510, 10);

	// 1Ãþ
	floor[12] = RectMake(57, 687, 912, 29);

	// »ç´Ù¸®
	ladder[0] = RectMake(484, 570, 30, 120);
	ladder[1] = RectMake(684, 460, 30, 120);
	ladder[2] = RectMake(541, 350, 30, 120);
	ladder[3] = RectMake(370, 240, 30, 120);


	isCollision = true;
	isJump = false;
	return S_OK;
}
void scene2::release()
{
}

void scene2::update()
{
	if (!isLadder)
	{
		if (KEYMANAGER->isStayKeyDown(VK_LEFT))
		{
			isLeft = true;
			player.left -= 5;
			player.right -= 5;
		}
		if (KEYMANAGER->isStayKeyDown(VK_RIGHT))
		{
			isLeft = false;
			player.left += 5;
			player.right += 5;
		}
		if (KEYMANAGER->isOnceKeyDown(VK_SPACE))
		{
			isCollision = false;
			isJump = true;
		}
	}

	if (isJump && isLeft)
	{
		playerImage->setFrameY(3);
		playerImage->setFrameX(0);
	}
	else if (isJump && !isLeft)
	{
		playerImage->setFrameY(2);
		playerImage->setFrameX(0);
	}
	else if (isLeft)
	{
		frameCount++;
		playerImage->setFrameY(0);
		if (frameCount % 5 == 0)
		{
			frameCount = 0;
			if (frameIndex >= playerImage->getMaxFrameX()-1)
			{
				frameIndex = 0;
			}
			playerImage->setFrameX(frameIndex);
			frameIndex++;
		}
	}
	else
	{
		frameCount++;
		playerImage->setFrameY(1);
		if (frameCount % 5 == 0)
		{
			frameCount = 0;
			if (frameIndex >= playerImage->getMaxFrameX()-1)
			{
				frameIndex = 0;
			}
			playerImage->setFrameX(frameIndex);
			frameIndex++;
		}
	}

	CollisionToFloor();
	CollisionToLadder();
	Jump(player);
	Gravity(player);
}

void scene2::render()
{
	IMAGEMANAGER->render("stage1", getMemDC());

	if (KEYMANAGER->isToggleKey(VK_TAB))
	{
		for (int i = 0; i < FLOORMAX; i++)
		{
			Rectangle(getMemDC(), floor[i].left, floor[i].top, floor[i].right, floor[i].bottom);
		}
		for (int i = 0; i < LADDERMAX; i++)
		{
			Rectangle(getMemDC(), ladder[i].left, ladder[i].top, ladder[i].right, ladder[i].bottom);
		}

		Rectangle(getMemDC(), leftWall.left, leftWall.top, leftWall.right, leftWall.bottom);

		for (int i = 0; i < 2; i++)
		{
			Rectangle(getMemDC(), rightWall[i].left, rightWall[i].top, rightWall[i].right, rightWall[i].bottom);
		}

		Rectangle(getMemDC(), player.left, player.top, player.right, player.bottom);
	}

	IMAGEMANAGER->frameRender("move", getMemDC(), player.left - 10, player.top);

	sprintf_s((str), "x : %d", m_ptMouse.x);
	TextOut(getMemDC(), 10, 10, str, strlen(str));

	sprintf_s((str), "y : %d", m_ptMouse.y);
	TextOut(getMemDC(), 10, 30, str, strlen(str));

}

void scene2::CollisionToFloor()
{
	for (int i = 0; i < FLOORMAX; i++)
	{
		RECT temp;
		if (IntersectRect(&temp, &floor[i], &player))
		{
			addGravity = 0;
			isCollision = true;
			isJump = false;
			isLadder = false;
			player.bottom = floor[i].top;
			player.top = player.bottom - playerImage->getFrameHeight();
		}
	}
}

void scene2::CollisionToLadder()
{
	RECT	temp;
	for (int i = 0; i < LADDERMAX; i++)
	{
		if (IntersectRect(&temp, &ladder[i], &player))
		{
			if (KEYMANAGER->isStayKeyDown(VK_UP))
			{
				player.top -= 2;
				player.bottom -= 2;
			}
			if (KEYMANAGER->isStayKeyDown(VK_DOWN))
			{
				player.top += 2;
				player.bottom += 2;
			}
		}
		if (ladder[i].top >= player.bottom)
		{
			player.bottom = ladder[i].top;
			player.top = player.bottom - playerImage->getFrameHeight();
		}
	}
}

void scene2::Gravity(RECT & a)
{
	if (isCollision == false)
	{
		a.top += GRAVITY;
		a.bottom += GRAVITY;
	}
}

void scene2::Jump(RECT & a)
{
	if (isJump)
	{
		addGravity -= GRAVITY;
		a.top -= JUMPPOWER + addGravity / 2;
		a.bottom -= JUMPPOWER + addGravity / 2;
	}
}