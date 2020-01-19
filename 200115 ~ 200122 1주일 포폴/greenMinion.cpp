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
	case 0:	
		count++;
		if (count >= 0 && count < 100)
		{
			idleAnimation();

			enemyRect.top += 4;

			enemyRect.bottom += 4;
		}
		else if (count >= 100 && count < 500)
		{
			idleAnimation();
			enemyRect.top += 2;
			enemyRect.bottom += 2;
		}
		else
		{
			idleAnimation();

			enemyRect.top -= 6;
			enemyRect.bottom -= 6;
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

