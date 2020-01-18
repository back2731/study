#include "stdafx.h"
#include "greenMinion.h"

greenMinion::greenMinion()
{
}

greenMinion::~greenMinion()
{
}

HRESULT greenMinion::init(const char * imageName, POINT position)
{
	enemyImage = IMAGEMANAGER->findImage(imageName);
	enemyRect = RectMakeCenter(position.x, position.y, enemyImage->getFrameWidth(), enemyImage->getFrameHeight());


	count = 0;
	return S_OK;
}

void greenMinion::release()
{
}

void greenMinion::update()
{	
	//move(0);	
	rectX = (enemyRect.left + (enemyRect.right - enemyRect.left) / 2);
	rectY = (enemyRect.top + (enemyRect.bottom - enemyRect.top) / 2);
}

void greenMinion::render()
{
	draw();
}

void greenMinion::draw()
{
	if (KEYMANAGER->isToggleKey(VK_TAB))
	{
		Rectangle(getMemDC(), enemyRect.left, enemyRect.top, enemyRect.right, enemyRect.bottom);
	}
	enemyImage->frameRender(getMemDC(), enemyRect.left, enemyRect.top, currentFrameX, currentFrameY);
}

void greenMinion::move(int pattern)
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

void greenMinion::leftAnimation()
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

void greenMinion::rightAnimation()
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

void greenMinion::idleAnimation()
{
	count++;
	currentFrameY = 0;
	if (count % FRAMESPEED == 0)
	{
		currentFrameX++;
		if (currentFrameX >= enemyImage->getMaxFrameX() - 6)
		{
			currentFrameX = 0;
		}
		enemyImage->setFrameX(currentFrameX);
	}
}

