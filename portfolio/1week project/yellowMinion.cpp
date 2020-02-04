#include "stdafx.h"
#include "yellowMinion.h"

yellowMinion::yellowMinion()
{
}

yellowMinion::~yellowMinion()
{
}

HRESULT yellowMinion::init(const char * imageName, POINT position)
{
	enemyImage = IMAGEMANAGER->findImage(imageName);
	enemyRect = RectMakeCenter(position.x, position.y, enemyImage->getFrameWidth(), enemyImage->getFrameHeight());

	hp = 5;

	count = 0;
	return S_OK;
}

void yellowMinion::release()
{
}

void yellowMinion::update()
{	
	//move(0);	
	rectX = (enemyRect.left + (enemyRect.right - enemyRect.left) / 2);
	rectY = (enemyRect.top + (enemyRect.bottom - enemyRect.top) / 2);
}

void yellowMinion::render()
{
	draw();
}

void yellowMinion::draw()
{
	if (KEYMANAGER->isToggleKey(VK_TAB))
	{
		Rectangle(getMemDC(), enemyRect.left, enemyRect.top, enemyRect.right, enemyRect.bottom);
	}
	enemyImage->frameRender(getMemDC(), enemyRect.left, enemyRect.top, currentFrameX, currentFrameY);
}

void yellowMinion::move(int pattern)
{
	switch (pattern)
	{
	case 0:
	{		
		addSpeed++;
		count++;

		if (count >= 0)
		{
			leftAnimation();

			enemyRect.left -= addSpeed / 7;

			enemyRect.right -= addSpeed / 7;
		}
	}
	break;
	case 1:
	{
		addSpeed++;
		count++;

		if (count >= 0)
		{
			leftAnimation();

			enemyRect.left -= addSpeed / 10;

			enemyRect.right -= addSpeed / 10;
		}
	}
	default:
		break;
	}
}

void yellowMinion::leftAnimation()
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

void yellowMinion::rightAnimation()
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

void yellowMinion::idleAnimation()
{
	frameCount++;
	currentFrameY = 0;
	if (frameCount % FRAMESPEED == 0)
	{
		currentFrameX++;
		if (currentFrameX >= enemyImage->getMaxFrameX() - 6)
		{
			currentFrameX = 0;
		}
		enemyImage->setFrameX(currentFrameX);
	}
}
