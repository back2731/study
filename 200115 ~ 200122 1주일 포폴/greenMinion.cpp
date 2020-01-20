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
		addSpeed = 0;
	case 0:	
		count++;
		idleAnimation();
		if (count >= 0 && count < 100)
		{

			enemyRect.top += 4;
			enemyRect.bottom += 4;
		}
		if (count >= 100 && count < 150)
		{

			enemyRect.top += 2;
			enemyRect.bottom += 2;
		}
		if (count >=  250)
		{
			addSpeed++;
			enemyRect.top -= addSpeed / 2;
			enemyRect.bottom -= addSpeed / 2;

		}
		break;
	case 1:
		count++;
		addSpeed++;

		if (count >= 0)
		{
			rightAnimation();
			enemyRect.left += addSpeed / 5;

			enemyRect.right += addSpeed / 5;
		}
		break;
	case 2:
		count++;
		addSpeed++;
		if (count >= 0)
		{
			rightAnimation();
			enemyRect.left += addSpeed / 10;

			enemyRect.right += addSpeed / 10;
		}
		break;
	default:
		break;
	}
}

void greenMinion::leftAnimation()
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

void greenMinion::rightAnimation()
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

void greenMinion::idleAnimation()
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

