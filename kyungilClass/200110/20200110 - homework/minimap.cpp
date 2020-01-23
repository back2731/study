#include "stdafx.h"
#include "minimap.h"
minimap::minimap()
{
}


minimap::~minimap()
{
}

HRESULT minimap::init()
{

	IMAGEMANAGER->addImage("배경화면", "images/map.bmp", 12224, 958, true, RGB(255, 0, 255));

	_rockman = IMAGEMANAGER->addFrameImage("플레이어", "images/player.bmp", 600/2, 1200/2, 2, 3, true, RGB(255, 0, 255));
	_rockman->setX(WINSIZEX / 2);
	_rockman->setY(WINSIZEY / 2);


	 _index = 0;
	 _count = 0;
	 _camera = 0;
	 _isLeft =  false;

	return S_OK;
}

void minimap::release()
{
}

void minimap::update()
{
	if (KEYMANAGER->isStayKeyDown(VK_LEFT) && _rockman->getX() > 0)
	{
		_isLeft = true;

		if (_rockman->getX() >= WINSIZEX / 2)
		{
			_rockman->setX(_rockman->getX() - PLAYERSPEED);
		}
		else if (_camera < 0)
		{
			_camera += CAMERASPEED;
		}
		else
		{
			_rockman->setX(_rockman->getX() - PLAYERSPEED);
		}

	}
	if (KEYMANAGER->isStayKeyDown(VK_RIGHT) && _rockman->getX()+80 < 12224)
	{
		_isLeft = false;

		if (_rockman->getX() <= WINSIZEX / 2)
		{
			_rockman->setX(_rockman->getX() + PLAYERSPEED);
		}
		else if (_camera > -11200)
		{
			_camera -= CAMERASPEED;
		}
		else
		{
			_rockman->setX(_rockman->getX() + PLAYERSPEED);
		}
	}

	_rockman->setFrameY(1);
	_rockman->setFrameX(0);

	if (_isLeft)
	{
		_count++;
		_rockman->setFrameY(1);
		if (_count % 20 == 0)
		{
			_count = 0;
			_index++;
			if (_index > _rockman->getMaxFrameX())
			{
				_index = 0;
			}
			_rockman->setFrameX(_index);
		}
	}
	else
	{
		_count++;
		_rockman->setFrameY(0);
		if (_count % 20 == 0)
		{
			_count = 0;
			_index++;
			if (_index > _rockman->getMaxFrameX())
			{
				_index = 0;
			}
			_rockman->setFrameX(_index);
		}
	}
}

void minimap::render()
{
	IMAGEMANAGER->render("배경화면", getMemDC(), _camera, 0);
	IMAGEMANAGER->frameRender("플레이어", getMemDC(), _rockman->getX(), _rockman->getY(), _rockman->getFrameX(), _rockman->getFrameY());
}
