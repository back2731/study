#include "stdafx.h"
#include "boss.h"


boss::boss()
{
}


boss::~boss()
{
}

HRESULT boss::init(const char * imageName, POINT position)
{
	enemyImage = IMAGEMANAGER->findImage(imageName);
	enemyRect = RectMakeCenter(position.x, position.y, enemyImage->getFrameWidth(), enemyImage->getFrameHeight());

	count = 0;
	return S_OK;
}

void boss::release()
{
}

void boss::update()
{
	rectX = (bossHitRect.left + (bossHitRect.right - bossHitRect.left) / 2);
	rectY = (bossHitRect.top + (bossHitRect.bottom - bossHitRect.top) / 2);
}

void boss::render()
{
	draw();
}

void boss::draw()
{
	if (KEYMANAGER->isToggleKey(VK_TAB))
	{
		Rectangle(getMemDC(), enemyRect.left, enemyRect.top, enemyRect.right, enemyRect.bottom);
		Rectangle(getMemDC(), bossHitRect.left, bossHitRect.top, bossHitRect.right, bossHitRect.bottom);
	}	
	bossHitRect = RectMakeCenter(enemyRect.left + (enemyRect.right - enemyRect.left) / 2,
		enemyRect.top + (enemyRect.bottom - enemyRect.top) / 2, 125, 150);
	enemyImage->frameRender(getMemDC(), enemyRect.left, enemyRect.top, currentFrameX, currentFrameY);
}

void boss::move(int pattern)
{
	/*
		IDLE,
		WORKRIGHT,
		WORKLEFT,
		FLY,
		MAGICCASTING,
		DRAWCARD,
		THROWSPEAR
		UP,
		DOWN,
		RIGHT,
		LEFT,
		RIGHTUP,
		LEFTUP,
		RIGHTDOWN,
		LEFTDOWN
	*/

	switch (pattern)
	{
	case IDLE:
	{
		idleAnimation();
	}
		break;
	case WORKRIGHT:
		rightMoveAnimation();
		break;
	case WORKLEFT:
		leftMoveAnimation();
		break;
	case FLY:
	{
		addSpeed++;

		flyAnimation();
		enemyRect.left  -= 1;
		enemyRect.right -= 1;
		
		enemyRect.left += addSpeed / 36;
		enemyRect.right += addSpeed / 36;

		enemyRect.top += 10;
		enemyRect.bottom += 10;

		enemyRect.top -= addSpeed / 12;
		enemyRect.bottom -= addSpeed / 12;
	}
		break;
	case SIT:
	{
		sitAnimation();
	}
	break;
	case MAGICCASTING:
		magicAnimation();
		break;
	case DRAWCARD:
		drawCardAnimation();
		break;
	case THROWSPEAR:
	{
		spearAnimation();
	}
		break;
	case UP:
		enemyRect.top -= 2;
		enemyRect.bottom -= 2;
		break;
	case DOWN:
		enemyRect.top += 2;
		enemyRect.bottom += 2;
		break;
	case RIGHT:
		enemyRect.left += 2;
		enemyRect.right += 2;
		break;
	case LEFT:
		enemyRect.left -= 2;
		enemyRect.right -= 2;
		break;
	case RIGHTUP:
		enemyRect.left += 2;
		enemyRect.right += 2;
		enemyRect.top -= 2;
		enemyRect.bottom -= 2;
		break;
	case LEFTUP:
		enemyRect.left -= 2;
		enemyRect.right -= 2;
		enemyRect.top -= 2;
		enemyRect.bottom -= 2;
		break;
	case RIGHTDOWN:
		enemyRect.left += 2;
		enemyRect.right += 2;
		enemyRect.top += 2;
		enemyRect.bottom += 2;
		break;
	case LEFTDOWN:
		enemyRect.left -= 2;
		enemyRect.right -= 2;
		enemyRect.top += 2;
		enemyRect.bottom += 2;
		break;

	default:
		break;
	}
}

void boss::idleAnimation()
{
	frameCount++;
	currentFrameY = 0;
	if (frameCount % FRAMESPEED == 0)
	{
		currentFrameX++;
		if (currentFrameX >= enemyImage->getMaxFrameX()-11)
		{
			currentFrameX = 0;
		}
		enemyImage->setFrameX(currentFrameX);
	}
}

void boss::rightMoveAnimation()
{
	frameCount++;
	currentFrameY = 1;
	if (frameCount % 20 == 0)
	{
		currentFrameX++;
		if (currentFrameX >= enemyImage->getMaxFrameX() - 11)
		{
			currentFrameX = 0;
		}
		enemyImage->setFrameX(currentFrameX);
	}
}

void boss::leftMoveAnimation()
{
	frameCount++;
	currentFrameY = 2;
	if (frameCount % 20 == 0)
	{
		currentFrameX++;
		if (currentFrameX >= enemyImage->getMaxFrameX() - 10)
		{
			currentFrameX = 0;
		}
		enemyImage->setFrameX(currentFrameX);
	}
}

void boss::flyAnimation()
{
	frameCount++;
	currentFrameY = 3;
	if (frameCount % FRAMESPEED == 0)
	{
		currentFrameX++;
		if (currentFrameX >= enemyImage->getMaxFrameX() - 16)
		{
			currentFrameX = 0;
		}
		enemyImage->setFrameX(currentFrameX);
	}
}

void boss::sitAnimation()
{
	frameCount++;
	currentFrameY = 3;
	if (frameCount % FRAMESPEED == 0)
	{
		currentFrameX++;
		if (currentFrameX >= enemyImage->getMaxFrameX() - 11)
		{
			currentFrameX = 11;
		}
		enemyImage->setFrameX(currentFrameX);
	}
}

void boss::magicAnimation()
{
	frameCount++;
	currentFrameY = 4;
	if (frameCount % FRAMESPEED == 0)
	{
		currentFrameX++;
		if (currentFrameX >= enemyImage->getMaxFrameX() - 10)
		{
			currentFrameX = 4;
		}
		enemyImage->setFrameX(currentFrameX);
	}
}

void boss::drawCardAnimation()
{
	frameCount++;
	currentFrameY = 5;
	if (frameCount % 10 == 0)
	{
		currentFrameX++;
		if (currentFrameX >= enemyImage->getMaxFrameX()-5)
		{
			currentFrameX = 0;
		}
		enemyImage->setFrameX(currentFrameX);
	}
}

void boss::spearAnimation()
{
	frameCount++;
	currentFrameY = 6;
	if (frameCount % 10 == 0)
	{
		currentFrameX++;
		if (currentFrameX >= enemyImage->getMaxFrameX())
		{
			currentFrameX = 0;
		}
		enemyImage->setFrameX(currentFrameX);
	}
}
