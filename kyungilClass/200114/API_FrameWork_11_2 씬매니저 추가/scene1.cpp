#include "stdafx.h"
#include "scene1.h"


scene1::scene1()
{
}


scene1::~scene1()
{
}

HRESULT scene1::init()
{
	_player = new player;
	if (_player->getMoveLeft() == true)
	{
		_player->setPlayerPositionLeft();
		_player->setMoveLeft(false);
	}
	IMAGEMANAGER->addImage("사나1", "images/사나1.bmp", WINSIZEX, WINSIZEY,true, RGB(255,0,255));
	sceneRect = RectMakeCenter(WINSIZEX, WINSIZEY / 2, 100, 100);

	return S_OK;
}

void scene1::release()
{
}

void scene1::update()
{
	_player->update();
	RECT temp;

	if (IntersectRect(&temp, &_player->getPlayerRect(), &sceneRect))
	{
		_player->setMoveRight(true);
		SCENEMANAGER->changeScene("sceneMain");
	}
}

void scene1::render()
{
	IMAGEMANAGER->render("사나1", getMemDC());	
	Rectangle(getMemDC(), sceneRect.left, sceneRect.top, sceneRect.right, sceneRect.bottom);

	_player->render();
}
