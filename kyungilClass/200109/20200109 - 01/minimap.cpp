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
	IMAGEMANAGER->addImage("���ȭ��", "images/���.bmp", WINSIZEX * 2, WINSIZEY * 2, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("ī�޶�", "images/ī�޶�.bmp", WINSIZEX / 10, WINSIZEY / 10, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("�̴ϸ�", "images/���.bmp", WINSIZEX * 2 / 10, WINSIZEY * 2 / 10, true, RGB(255, 0, 255));
	_rockman = IMAGEMANAGER->addFrameImage("�ϸ�", "images/�ϸ�.bmp", 960, 200, 10, 2, true, RGB(255, 0, 255));
	mini_rc = RectMakeCenter(100 + _rockman->getX() / 10 - _camera / 10, 50 + _rockman->getY() / 10, 10, 10);
	_rockman->setX(WINSIZEX / 2);
	_rockman->setY(WINSIZEY / 2);
	
	_index = 0;
	_count = 0;
	_camera = 0;
	_isLeft = false;

	return S_OK;
}

void minimap::release()
{
}

void minimap::update()
{
}

void minimap::render(HDC hdc)
{
	IMAGEMANAGER->render("���ȭ��", getMemDC(), _camera, 0);
	IMAGEMANAGER->render("�̴ϸ�", getMemDC(), 100, 50);
	IMAGEMANAGER->frameRender("�ϸ�", getMemDC(), _rockman->getX(), _rockman->getY(), _rockman->getFrameX(), _rockman->getFrameY());
	Rectangle(getMemDC(), mini_rc.left, mini_rc.top, mini_rc.right, mini_rc.bottom);
	IMAGEMANAGER->render("ī�޶�", getMemDC(), 100 - _camera / 10, 50);
}
