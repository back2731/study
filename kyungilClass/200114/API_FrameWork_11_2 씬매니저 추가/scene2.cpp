#include "stdafx.h"
#include "scene2.h"
scene2::scene2()
{
}

scene2::~scene2()
{
}

HRESULT scene2::init()
{
	_player = new player;
	if (_player->getMoveUp() == true)
	{
		_player->setPlayerPositionUp();
		_player->setMoveUp(false);
	}
	IMAGEMANAGER->addImage("사나", "images/사나.bmp", WINSIZEX, WINSIZEY, true, RGB(255, 0, 255));
	sceneRect = RectMakeCenter(WINSIZEX / 2, WINSIZEY, 100, 100);

	return S_OK;
}
void scene2::release()
{
}

void scene2::update()
{
	_player->update();
	RECT temp;
	if (IntersectRect(&temp, &_player->getPlayerRect(), &sceneRect))
	{
		_player->setMoveDown(true);
		SCENEMANAGER->changeScene("sceneMain");
	}
}

void scene2::render()
{
	IMAGEMANAGER->render("사나", getMemDC());
	Rectangle(getMemDC(), sceneRect.left, sceneRect.top, sceneRect.right, sceneRect.bottom);

	_player->render();

}
