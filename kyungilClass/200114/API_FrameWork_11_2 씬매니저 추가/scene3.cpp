#include "stdafx.h"
#include "scene3.h"
scene3::scene3()
{
}

scene3::~scene3()
{
}

HRESULT scene3::init()
{
	_player = new player;
	if (_player->getMoveRight() == true)
	{
		_player->setPlayerPositionRight();
		_player->setMoveRight(false);
	}
	IMAGEMANAGER->addImage("동원이여친", "images/동원이여친.bmp", WINSIZEX, WINSIZEY, true, RGB(255, 0, 255));
	sceneRect = RectMakeCenter(0, WINSIZEY / 2, 100, 100);

	return S_OK;
}
void scene3::release()
{
}

void scene3::update()
{
	_player->update();
	RECT temp;
	if (IntersectRect(&temp, &_player->getPlayerRect(), &sceneRect))
	{
		_player->setMoveLeft(true);
		SCENEMANAGER->changeScene("sceneMain");
	}
}

void scene3::render()
{
	IMAGEMANAGER->render("동원이여친", getMemDC());
	Rectangle(getMemDC(), sceneRect.left, sceneRect.top, sceneRect.right, sceneRect.bottom);

	_player->render();

}
