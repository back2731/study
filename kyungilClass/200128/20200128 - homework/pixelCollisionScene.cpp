#include "stdafx.h"
#include "pixelCollisionScene.h"
pixelCollisionScene::pixelCollisionScene()
{
}


pixelCollisionScene::~pixelCollisionScene()
{
}

HRESULT pixelCollisionScene::init()
{
	IMAGEMANAGER->addImage("collision", "images/collision.bmp", WINSIZEX, WINSIZEY, false, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("itemTest", "images/itemTest.bmp", WINSIZEX, WINSIZEY, false, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("map", "images/map.bmp", WINSIZEX, WINSIZEY, true, RGB(255, 0, 255));

	_pacMan = IMAGEMANAGER->addFrameImage("pacMan", "images/pacMan.bmp", 90, 192, 2, 4, true, RGB(0, 0, 0));

	_x = 510;
	_y = 430;

	_rc = RectMakeCenter(_x, _y, _pacMan->getFrameWidth(), _pacMan->getFrameHeight());


	for (int i = 0; i < 30; i++)
	{
		for (int j = 0; j < 26; j++)
		{
			item[i * 26 + j] = RectMakeCenter(95 + j *33 , 70 + 22 * i, 10, 10);
		}
	}

	for (int i = 0; i < 780; i++)
	{
		vItem.push_back(item[i]);
	}

	_probeX = _x + _pacMan->getFrameWidth() / 2;
	_probeY = _y + _pacMan->getFrameHeight() / 2;

	_isUp = false;
	_isDown = false;
	_isLeft = false;
	_isRight = false;

	_isUpMove = false;
	_isDownMove = false;
	_isLeftMove = false;
	_isRightMove = true;

	return S_OK;
}
void pixelCollisionScene::release()
{
}

void pixelCollisionScene::update()
{
	playerMove();
	
	playerAnimation();
	
	playerWallCollision();

	

	if (_rc.left <= 10)
	{
		_x = 950;
		_y = 360;
	}
	if (_rc.right >= WINSIZEX - 5)
	{
		_x = 50;
		_y = 360;

	}
	_rc = RectMakeCenter(_x, _y, _pacMan->getFrameWidth(), _pacMan->getFrameHeight());
}

void pixelCollisionScene::render()
{
	IMAGEMANAGER->findImage("collision")->render(getMemDC());
	IMAGEMANAGER->findImage("map")->render(getMemDC());
	IMAGEMANAGER->findImage("itemTest")->render(getMemDC());
	_pacMan->frameRender(getMemDC(), _rc.left, _rc.top);

	if (KEYMANAGER->isToggleKey(VK_TAB))
	{
		Rectangle(getMemDC(), _rc.left, _rc.top, _rc.right, _rc.bottom);

		for (int i = 0; i < 780; i++)
		{			
			Rectangle(getMemDC(), item[i].left, item[i].top, item[i].right, item[i].bottom);
		}
	}

	sprintf_s(str, "x :  %d", m_ptMouse.x);
	TextOut(getMemDC(), 100, 100, str, strlen(str));

	sprintf_s(str, "y :  %d", m_ptMouse.y);
	TextOut(getMemDC(), 100, 120, str, strlen(str));
}

void pixelCollisionScene::playerWallCollision()
{
	if (_isDown)
	{
		_probeY = _y + _pacMan->getFrameHeight() / 2;
		for (int i = _probeY - CHECKNUM; i < _probeY + CHECKNUM; i++)
		{
			//단점 :  느리다. 끝...
			COLORREF color = GetPixel(IMAGEMANAGER->findImage("collision")->getMemDC(), _x, i);

			//겟픽셀로 가져온 비트맵 정보를 RGB색상요소를 분리한다.
			int r = GetRValue(color);
			int g = GetGValue(color);
			int b = GetBValue(color);

			//요기다가 원하는 색을 넣어라.
			if (!(r == 255 && g == 0 && b == 255))
			{
				_y = i - _pacMan->getFrameHeight() / 2;
				break;
			}
		}

		_probeLeft = _x - _pacMan->getFrameWidth() / 2;
		for (int i = _probeLeft + CHECKNUM; i > _probeLeft - CHECKNUM; i--)
		{
			//단점 :  느리다. 끝...
			COLORREF color = GetPixel(IMAGEMANAGER->findImage("collision")->getMemDC(), i, _y);

			//겟픽셀로 가져온 비트맵 정보를 RGB색상요소를 분리한다.
			int r = GetRValue(color);
			int g = GetGValue(color);
			int b = GetBValue(color);

			//요기다가 원하는 색을 넣어라.
			if (!(r == 255 && g == 0 && b == 255))
			{
				_x = i + _pacMan->getFrameWidth() / 2;
				break;
			}
		}

		_probeRight = _x + _pacMan->getFrameWidth() / 2;
		for (int i = _probeRight - CHECKNUM; i < _probeRight + CHECKNUM; i++)
		{
			//단점 :  느리다. 끝...
			COLORREF color = GetPixel(IMAGEMANAGER->findImage("collision")->getMemDC(), i, _y);

			//겟픽셀로 가져온 비트맵 정보를 RGB색상요소를 분리한다.
			int r = GetRValue(color);
			int g = GetGValue(color);
			int b = GetBValue(color);

			//요기다가 원하는 색을 넣어라.
			if (!(r == 255 && g == 0 && b == 255))
			{
				_x = i - _pacMan->getFrameWidth() / 2;
				break;
			}
		}
	}
	if (_isUp)
	{
		_probeY = _y - _pacMan->getFrameHeight() / 2;
		for (int i = _probeY + CHECKNUM; i > _probeY - CHECKNUM; i--)
		{
			//단점 :  느리다. 끝...
			COLORREF color = GetPixel(IMAGEMANAGER->findImage("collision")->getMemDC(), _x, i);

			//겟픽셀로 가져온 비트맵 정보를 RGB색상요소를 분리한다.
			int r = GetRValue(color);
			int g = GetGValue(color);
			int b = GetBValue(color);

			//요기다가 원하는 색을 넣어라.
			if (!(r == 255 && g == 0 && b == 255))
			{
				_y = i + _pacMan->getFrameHeight() / 2;
				break;
			}
		}

		_probeLeft = _x - _pacMan->getFrameWidth() / 2;
		for (int i = _probeLeft + CHECKNUM; i > _probeLeft - CHECKNUM; i--)
		{
			//단점 :  느리다. 끝...
			COLORREF color = GetPixel(IMAGEMANAGER->findImage("collision")->getMemDC(), i, _y);

			//겟픽셀로 가져온 비트맵 정보를 RGB색상요소를 분리한다.
			int r = GetRValue(color);
			int g = GetGValue(color);
			int b = GetBValue(color);

			//요기다가 원하는 색을 넣어라.
			if (!(r == 255 && g == 0 && b == 255))
			{
				_x = i + _pacMan->getFrameWidth() / 2;
				break;
			}
		}

		_probeRight = _x + _pacMan->getFrameWidth() / 2;
		for (int i = _probeRight - CHECKNUM; i < _probeRight + CHECKNUM; i++)
		{
			//단점 :  느리다. 끝...
			COLORREF color = GetPixel(IMAGEMANAGER->findImage("collision")->getMemDC(), i, _y);

			//겟픽셀로 가져온 비트맵 정보를 RGB색상요소를 분리한다.
			int r = GetRValue(color);
			int g = GetGValue(color);
			int b = GetBValue(color);

			//요기다가 원하는 색을 넣어라.
			if (!(r == 255 && g == 0 && b == 255))
			{
				_x = i - _pacMan->getFrameWidth() / 2;
				break;
			}
		}
	}
	if (_isLeft)
	{
		_probeX = _x - _pacMan->getFrameWidth() / 2;
		for (int i = _probeX + CHECKNUM; i > _probeX - CHECKNUM; i--)
		{
			//단점 :  느리다. 끝...
			COLORREF color = GetPixel(IMAGEMANAGER->findImage("collision")->getMemDC(), i, _y);

			//겟픽셀로 가져온 비트맵 정보를 RGB색상요소를 분리한다.
			int r = GetRValue(color);
			int g = GetGValue(color);
			int b = GetBValue(color);

			//요기다가 원하는 색을 넣어라.
			if (!(r == 255 && g == 0 && b == 255))
			{
				_x = i + _pacMan->getFrameWidth() / 2;
				break;
			}
		}

		_probeTop = _y - _pacMan->getFrameHeight() / 2;
		for (int i = _probeTop + CHECKNUM; i > _probeTop - CHECKNUM; i--)
		{
			//단점 :  느리다. 끝...
			COLORREF color = GetPixel(IMAGEMANAGER->findImage("collision")->getMemDC(), _x, i);

			//겟픽셀로 가져온 비트맵 정보를 RGB색상요소를 분리한다.
			int r = GetRValue(color);
			int g = GetGValue(color);
			int b = GetBValue(color);

			//요기다가 원하는 색을 넣어라.
			if (!(r == 255 && g == 0 && b == 255))
			{
				_y = i + _pacMan->getFrameHeight() / 2;
				break;
			}
		}

		_probeBottom = _y + _pacMan->getFrameHeight() / 2;
		for (int i = _probeBottom - CHECKNUM; i < _probeBottom + CHECKNUM; i++)
		{
			//단점 :  느리다. 끝...
			COLORREF color = GetPixel(IMAGEMANAGER->findImage("collision")->getMemDC(), _x, i);

			//겟픽셀로 가져온 비트맵 정보를 RGB색상요소를 분리한다.
			int r = GetRValue(color);
			int g = GetGValue(color);
			int b = GetBValue(color);

			//요기다가 원하는 색을 넣어라.
			if (!(r == 255 && g == 0 && b == 255))
			{
				_y = i - _pacMan->getFrameHeight() / 2;
				break;
			}
		}
	}
	if (_isRight)
	{
		_probeX = _x + _pacMan->getFrameWidth() / 2;
		for (int i = _probeX - CHECKNUM; i < _probeX + CHECKNUM; i++)
		{
			//단점 :  느리다. 끝...
			COLORREF color = GetPixel(IMAGEMANAGER->findImage("collision")->getMemDC(), i, _y);

			//겟픽셀로 가져온 비트맵 정보를 RGB색상요소를 분리한다.
			int r = GetRValue(color);
			int g = GetGValue(color);
			int b = GetBValue(color);

			//요기다가 원하는 색을 넣어라.
			if (!(r == 255 && g == 0 && b == 255))
			{
				_x = i - _pacMan->getFrameWidth() / 2;
				break;
			}
		}

		_probeTop = _y - _pacMan->getFrameHeight() / 2;
		for (int i = _probeTop + CHECKNUM; i > _probeTop - CHECKNUM; i--)
		{
			//단점 :  느리다. 끝...
			COLORREF color = GetPixel(IMAGEMANAGER->findImage("collision")->getMemDC(), _x, i);

			//겟픽셀로 가져온 비트맵 정보를 RGB색상요소를 분리한다.
			int r = GetRValue(color);
			int g = GetGValue(color);
			int b = GetBValue(color);

			//요기다가 원하는 색을 넣어라.
			if (!(r == 255 && g == 0 && b == 255))
			{
				_y = i + _pacMan->getFrameHeight() / 2;
				break;
			}
		}

		_probeBottom = _y + _pacMan->getFrameHeight() / 2;
		for (int i = _probeBottom - CHECKNUM; i < _probeBottom + CHECKNUM; i++)
		{
			//단점 :  느리다. 끝...
			COLORREF color = GetPixel(IMAGEMANAGER->findImage("collision")->getMemDC(), _x, i);

			//겟픽셀로 가져온 비트맵 정보를 RGB색상요소를 분리한다.
			int r = GetRValue(color);
			int g = GetGValue(color);
			int b = GetBValue(color);

			//요기다가 원하는 색을 넣어라.
			if (!(r == 255 && g == 0 && b == 255))
			{
				_y = i - _pacMan->getFrameHeight() / 2;
				break;
			}
		}
	}
}

void pixelCollisionScene::playerItemCollision()
{
	//RECT temp;
	//
	//for (int i = 0; i < 780; i++)
	//{
	//	if (IntersectRect(&temp, &_rc, &vItem[i]))
	//	{
	//		vItem.erase(vItem[i]);
	//	}
	//}
}

void pixelCollisionScene::playerMove()
{
	if (KEYMANAGER->isStayKeyDown(VK_UP))
	{
		_y -= 2.0f;
		_isUp = true;
	}
	if (KEYMANAGER->isOnceKeyUp(VK_UP))
	{
		_isUp = false;
	}
	if (KEYMANAGER->isOnceKeyDown(VK_UP))
	{
		_isUpMove = true;
		_isDownMove = false;
		_isLeftMove = false;
		_isRightMove = false;
	}

	if (KEYMANAGER->isStayKeyDown(VK_DOWN))
	{
		_y += 2.0f;
		_isDown = true;
	}
	if (KEYMANAGER->isOnceKeyUp(VK_DOWN))
	{
		_isDown = false;
	}
	if (KEYMANAGER->isOnceKeyDown(VK_DOWN))
	{
		_isUpMove = false;
		_isDownMove = true;
		_isLeftMove = false;
		_isRightMove = false;
	}

	if (KEYMANAGER->isStayKeyDown(VK_LEFT))
	{
		_x -= 2.0f;
		_isLeft = true;
	}
	if (KEYMANAGER->isOnceKeyUp(VK_LEFT))
	{
		_isLeft = false;
	}
	if (KEYMANAGER->isOnceKeyDown(VK_LEFT))
	{
		_isUpMove = false;
		_isDownMove = false;
		_isLeftMove = true;
		_isRightMove = false;
	}

	if (KEYMANAGER->isStayKeyDown(VK_RIGHT))
	{
		_x += 2.0f;
		_isRight = true;
	}
	if (KEYMANAGER->isOnceKeyUp(VK_RIGHT))
	{
		_isRight = false;
	}
	if (KEYMANAGER->isOnceKeyDown(VK_RIGHT))
	{
		_isUpMove = false;
		_isDownMove = false;
		_isLeftMove = false;
		_isRightMove = true;
	}
}

void pixelCollisionScene::playerAnimation()
{
	frameCount++;
	if (_isUpMove)
	{
		_pacMan->setFrameY(2);
		if (frameCount % 5 == 0)
		{
			if (frameIndex > _pacMan->getMaxFrameX())
			{
				frameIndex = 0;
			}
			_pacMan->setFrameX(frameIndex);
			frameIndex++;
		}
	}
	if (_isDownMove)
	{
		_pacMan->setFrameY(3);
		if (frameCount % 5 == 0)
		{
			if (frameIndex > _pacMan->getMaxFrameX())
			{
				frameIndex = 0;
			}
			_pacMan->setFrameX(frameIndex);
			frameIndex++;
		}
	}	
	if (_isLeftMove)
	{
		_pacMan->setFrameY(1);
		if (frameCount % 5 == 0)
		{
			if (frameIndex > _pacMan->getMaxFrameX())
			{
				frameIndex = 0;
			}
			_pacMan->setFrameX(frameIndex);
			frameIndex++;
		}
	}
	if (_isRightMove)
	{
		_pacMan->setFrameY(0);
		if (frameCount % 5 == 0)
		{
			if (frameIndex > _pacMan->getMaxFrameX())
			{
				frameIndex = 0;
			}
			_pacMan->setFrameX(frameIndex);
			frameIndex++;
		}
	}

}
