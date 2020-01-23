#include "stdafx.h"
#include "enemy.h"


enemy::enemy()
{
}


enemy::~enemy()
{
}

HRESULT enemy::init()
{
	return S_OK;
}

HRESULT enemy::init(const char* imageName, POINT position)
{
	// ������ �ʱ�ȭ
	_count = 0;
	_currentFrameX = 0;
	_currentFrameY = 0;

	// ����
	_fireCount = 0;
	_rndFireCount = RND->getFromIntTo(1, 1000);

	// �̹���, ��Ʈ
	_image = IMAGEMANAGER->findImage(imageName);
	_rc = RectMakeCenter(position.x, position.y, _image->getFrameWidth, _image->getFrameHeight);

	return S_OK;
}

void enemy::release()
{
}

void enemy::update()
{
	animation();
}

void enemy::render()
{
	draw();
}

void enemy::draw()
{

}

void enemy::animation()
{
}

bool enemy::bulletCountFire()
{
	return false;
}
