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
	//move(0);
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
	case 0: // 직선 하강 후 우하단으로 사라지는 움직임
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
		break;
	case 1: // 직선 하강 후 우하단으로 사라지는 움직임
		if ((enemyRect.top + (enemyRect.bottom - enemyRect.top) / 2) < WINSIZEY / 2)
		{
			idleAnimation();

			enemyRect.top += 4;

			enemyRect.bottom += 4;
		}
		if ((enemyRect.top + (enemyRect.bottom - enemyRect.top) / 2) >= WINSIZEY / 2)
		{
			leftAnimation();
			enemyRect.left -= 4;
			enemyRect.right -= 4;

			enemyRect.top += 2;
			enemyRect.bottom += 2;
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
			enemyRect.left -= 7;
			enemyRect.right -= 7;
		}
		if (count >= 50 && count < 300)
		{
			addSpeed += 1;
			enemyRect.left += addSpeed / 5;
			enemyRect.right += addSpeed / 5;
		}
	}
	default:
		break;
	}
}

void blueMinion::leftAnimation()
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

void blueMinion::rightAnimation()
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

void blueMinion::idleAnimation()
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
