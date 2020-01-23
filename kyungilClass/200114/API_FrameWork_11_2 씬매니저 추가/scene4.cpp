#include "stdafx.h"
#include "scene4.h"
scene4::scene4()
{
}

scene4::~scene4()
{
}

HRESULT scene4::init()
{
	_player = new player;
	if (_player->getMoveDown() == true)
	{
		_player->setPlayerPositionDown();
		_player->setMoveDown(false);
	}
	IMAGEMANAGER->addImage("捞郡府具", "images/捞郡府具.bmp", WINSIZEX, WINSIZEY, true, RGB(255, 0, 255));
	sceneRect = RectMakeCenter(WINSIZEX / 2, 0, 100, 100);

	return S_OK;
}
void scene4::release()
{
}

void scene4::update()
{
	_player->update();
	RECT temp;
	if (IntersectRect(&temp, &_player->getPlayerRect(), &sceneRect))
	{
		_player->setMoveUp(true);
		SCENEMANAGER->changeScene("sceneMain");
	}
}

void scene4::render()
{
	IMAGEMANAGER->render("捞郡府具", getMemDC());
	Rectangle(getMemDC(), sceneRect.left, sceneRect.top, sceneRect.right, sceneRect.bottom);

	_player->render();

}
