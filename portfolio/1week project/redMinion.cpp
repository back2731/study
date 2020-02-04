#include "stdafx.h"
#include "redMinion.h"


redMinion::redMinion()
{
}


redMinion::~redMinion()
{
}

HRESULT redMinion::init(const char * imageName, POINT position)
{
	enemyImage = IMAGEMANAGER->findImage(imageName);
	enemyRect = RectMakeCenter(position.x, position.y, enemyImage->getFrameWidth(), enemyImage->getFrameHeight());
	
	hp = 5;

	count = 0;
	return S_OK;
}

void redMinion::release()
{
}

void redMinion::update()
{
	//move(0);	

	rectX = (enemyRect.left + (enemyRect.right - enemyRect.left) / 2);
	rectY = (enemyRect.top + (enemyRect.bottom - enemyRect.top) / 2);
}

void redMinion::render()
{
	draw();
}

void redMinion::draw()
{
	if (KEYMANAGER->isToggleKey(VK_TAB))
	{
		Rectangle(getMemDC(), enemyRect.left, enemyRect.top, enemyRect.right, enemyRect.bottom);
	}
	enemyImage->frameRender(getMemDC(), enemyRect.left, enemyRect.top, currentFrameX, currentFrameY);
}

void redMinion::move(int pattern)
{
	switch (pattern)
	{
	case 0:	// 직선 하강 후 우하단으로 사라지는 움직임
	{
		count++;

		if ((enemyRect.top + (enemyRect.bottom - enemyRect.top) / 2) < WINSIZEY / 2)
		{
			idleAnimation();

			enemyRect.top += 4;

			enemyRect.bottom += 4;
		}
		if ((enemyRect.top + (enemyRect.bottom - enemyRect.top) / 2) >= WINSIZEY / 2)
		{
			rightAnimation();

			enemyRect.left += 4;
			enemyRect.right += 4;

			enemyRect.top += 2;
			enemyRect.bottom += 2;
		}
	}
		break;
	case 1:
	{
		count++;
		if (count >= 1)
		{
			rightAnimation();

			enemyRect.left += 4;
			enemyRect.right += 4;
		}
	}
		break;
	case 2:
	{			
		idleAnimation();

		count++;
		if (count >= 0)
		{
			enemyRect.top += 5;
			enemyRect.bottom += 5;
		}
		if (count >= 0 && count < 300)
		{
			enemyRect.left += 7;
			enemyRect.right += 7;
		}
		if (count >= 50 && count < 300)
		{
			addSpeed += 1;
			enemyRect.left -= addSpeed / 5;
			enemyRect.right -= addSpeed / 5;
		}
	}
	break;
	default:
		break;
	}

}

void redMinion::leftAnimation()
{
	frameCount++;
	currentFrameY = 0;
	if (frameCount % FRAMESPEED == 0)
	{
		currentFrameX++;
		if (currentFrameX >= enemyImage->getMaxFrameX())
		{
			currentFrameX = 8;
		}
		enemyImage->setFrameX(currentFrameX);
	}
}

void redMinion::rightAnimation()
{
	frameCount++;
	currentFrameY = 1;
	if (frameCount % FRAMESPEED == 0)
	{
		currentFrameX++;
		if (currentFrameX >= enemyImage->getMaxFrameX())
		{
			currentFrameX = 8;
		}
		enemyImage->setFrameX(currentFrameX);
	}
}

void redMinion::idleAnimation()
{
	frameCount++;
	currentFrameY = 0;
	if (frameCount % FRAMESPEED == 0)
	{
		currentFrameX++;
		if (currentFrameX >= enemyImage->getMaxFrameX()- 6)
		{
			currentFrameX = 0;
		}
		enemyImage->setFrameX(currentFrameX);
	}
}



