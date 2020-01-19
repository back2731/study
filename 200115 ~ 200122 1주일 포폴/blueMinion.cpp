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
			rightAnimation();
			enemyRect.left -= 4;
			enemyRect.right -= 4;

			enemyRect.top += 2;
			enemyRect.bottom += 2;
		}
		break;
	case 2:
	{	
		count++;
		if (count >= 0)
		{
			idleAnimation();

			enemyRect.top += 2;
			enemyRect.bottom += 2;
		}
		if (count >= 100 && count < 150)
		{
			enemyRect.left -= 2;
			enemyRect.right -= 2;
		}
		if (count >= 150 && count < 275)
		{
			enemyRect.left += 2;
			enemyRect.right += 2;
		}
		if (count >= 275 && count < 425)
		{
			enemyRect.left -= 2;
			enemyRect.right -= 2;
		}
		if (count >= 425 && count < 575)
		{
			enemyRect.left += 2;
			enemyRect.right += 2;
		}
		if (count >= 575 && count < 725)
		{
			enemyRect.left -= 2;
			enemyRect.right -= 2;
		}
		if (count >= 725 && count < 875)
		{
			enemyRect.left += 2;
			enemyRect.right += 2;
		}
		if (count >= 875 && count < 1025)
		{
			enemyRect.left -= 2;
			enemyRect.right -= 2;
		}
		if (count >= 1025 && count < 1175)
		{
			enemyRect.left += 2;
			enemyRect.right += 2;
		}
		if (count >= 1175 && count < 1325)
		{
			enemyRect.left -= 2;
			enemyRect.right -= 2;
		}
	}
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
