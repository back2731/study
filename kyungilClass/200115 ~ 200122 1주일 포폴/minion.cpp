#include "stdafx.h"
#include "minion.h"


minion::minion()
{
}


minion::~minion()
{
}

HRESULT minion::init(const char * imageName, POINT position)
{
	enemyImage = IMAGEMANAGER->addFrameImage("redMinion", "images/redMinion.bmp", 360, 60, 12, 2, true, RGB(255, 0, 255));
	enemyRect = RectMakeCenter(position.x, position.y, enemyImage->getFrameWidth(), enemyImage->getFrameHeight());
	
	count = 0;
	return S_OK;
}

void minion::release()
{
}

void minion::update()
{
	move(0);
}

void minion::render()
{
	draw();
}

void minion::draw()
{
	if (KEYMANAGER->isToggleKey(VK_TAB))
	{
		Rectangle(getMemDC(), enemyRect.left, enemyRect.top, enemyRect.right, enemyRect.bottom);
	}
	enemyImage->frameRender(getMemDC(), enemyRect.left, enemyRect.top, currentFrameX, currentFrameY);
}

void minion::move(int pattern)
{
	switch (pattern)
	{
	case 0:
		if ((enemyRect.left + (enemyRect.right - enemyRect.left) / 2) < WINSIZEX / 2)
		{
			rightAnimation();

			enemyRect.left += 4;

			enemyRect.right += 4;
		}
		if ((enemyRect.left + (enemyRect.right - enemyRect.left) / 2) >= WINSIZEX / 2)
		{
			idleAnimation();
			enemyRect.left += 4;
			enemyRect.right += 4;

			enemyRect.top -= 2;
			enemyRect.bottom -= 2;
		}
		break;
	default:
		break;
	}
}

void minion::leftAnimation()
{
	count++;
	currentFrameY = 0;
	if (count % FRAMESPEED == 0)
	{
		currentFrameX++;
		if (currentFrameX >= enemyImage->getMaxFrameX())
		{
			currentFrameX = 8;
		}
		enemyImage->setFrameX(currentFrameX);
	}
}

void minion::rightAnimation()
{
	count++;
	currentFrameY = 1;
	if (count % FRAMESPEED == 0)
	{
		currentFrameX++;
		if (currentFrameX >= enemyImage->getMaxFrameX())
		{
			currentFrameX = 8;
		}
		enemyImage->setFrameX(currentFrameX);
	}
}

void minion::idleAnimation()
{
	count++;
	currentFrameY = 0;
	if (count % FRAMESPEED == 0)
	{
		currentFrameX++;
		if (currentFrameX >= enemyImage->getMaxFrameX()- 6)
		{
			currentFrameX = 0;
		}
		enemyImage->setFrameX(currentFrameX);
	}
}
