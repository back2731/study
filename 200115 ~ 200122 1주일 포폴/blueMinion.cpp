#include "stdafx.h"
#include "blueMinion.h"

blueMinion::blueMinion()
{
}

blueMinion::~blueMinion()
{
}

HRESULT blueMinion::init(const char * imageName, POINT position)
{
	enemyImage = IMAGEMANAGER->findImage(imageName);
	enemyRect = RectMakeCenter(position.x, position.y, enemyImage->getFrameWidth(), enemyImage->getFrameHeight());


	count = 0;
	return S_OK;
}

void blueMinion::release()
{

}

void blueMinion::update()
{
	move(0);
	rectX = (enemyRect.left + (enemyRect.right - enemyRect.left) / 2);
	rectY = (enemyRect.top + (enemyRect.bottom - enemyRect.top) / 2);
}

void blueMinion::render()
{
	draw();
}

void blueMinion::draw()
{
	if (KEYMANAGER->isToggleKey(VK_TAB))
	{
		Rectangle(getMemDC(), enemyRect.left, enemyRect.top, enemyRect.right, enemyRect.bottom);
	}
	enemyImage->frameRender(getMemDC(), enemyRect.left, enemyRect.top, currentFrameX, currentFrameY);
}

void blueMinion::move(int pattern)
{
	switch (pattern)
	{
	case 0:
		if ((enemyRect.left + (enemyRect.right - enemyRect.left) / 2) >= WINSIZEX / 2 - 300)
		{
			leftAnimation();

			enemyRect.left -= 4;

			enemyRect.right -= 4;
		}
		if ((enemyRect.left + (enemyRect.right - enemyRect.left) / 2) < WINSIZEX / 2 - 300)
		{
			idleAnimation();
			enemyRect.left -= 4;
			enemyRect.right -= 4;

			enemyRect.top -= 2;
			enemyRect.bottom -= 2;
		}
		break;
	default:
		break;
	}
}

void blueMinion::leftAnimation()
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

void blueMinion::rightAnimation()
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

void blueMinion::idleAnimation()
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
