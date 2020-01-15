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
	playerImage = IMAGEMANAGER->addFrameImage("���̹�", "images/reimu.bmp", 256*2, 141*2, 8, 3, true, RGB(255, 0, 255));
	playerRect = RectMakeCenter(WINSIZEX / 2, WINSIZEY / 2, playerImage->getFrameWidth(), playerImage->getFrameHeight());
		
	isMove  = false;
	isLeft  = false;
	isRight = false;

	frameIndex = 0;
	return S_OK;
}

void player::release()
{
}

void player::update()
{
	// ����
	if (KEYMANAGER->isStayKeyDown(VK_LEFT))
	{
		isMove = true;
		isLeft = true;

		playerRect.left -= PLAYERSPEED;
		playerRect.right -= PLAYERSPEED;
	}

	//������
	if (KEYMANAGER->isStayKeyDown(VK_RIGHT))
	{
		isMove = true;
		isLeft = false;

		playerRect.left += PLAYERSPEED;
		playerRect.right += PLAYERSPEED;
	}

	//��
	if (KEYMANAGER->isStayKeyDown(VK_UP))
	{
		playerRect.top -= PLAYERSPEED;
		playerRect.bottom -= PLAYERSPEED;
	}

	//�Ʒ�
	if (KEYMANAGER->isStayKeyDown(VK_DOWN))
	{
		playerRect.top += PLAYERSPEED;
		playerRect.bottom += PLAYERSPEED;
	}

	// �������� ���߸� false 
	if (KEYMANAGER->isOnceKeyUp(VK_LEFT) || KEYMANAGER->isOnceKeyUp(VK_RIGHT) 
	   || KEYMANAGER->isOnceKeyUp(VK_UP) || KEYMANAGER->isOnceKeyUp(VK_DOWN))
	{
		isMove = false;
	}

	if (!isMove)		// �������� �ʴ� ����
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
	else				// �����̴� ����
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
}

void player::render()
{
	if (KEYMANAGER->isToggleKey(VK_TAB))
	{
		Rectangle(getMemDC(), playerRect.left, playerRect.top, playerRect.right, playerRect.bottom);
	}
	IMAGEMANAGER->frameRender("���̹�", getMemDC(), playerRect.left, playerRect.top);
}
