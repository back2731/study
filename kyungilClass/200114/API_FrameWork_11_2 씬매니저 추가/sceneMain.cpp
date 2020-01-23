#include "stdafx.h"
#include "sceneMain.h"


sceneMain::sceneMain()
{
}


sceneMain::~sceneMain()
{
}

HRESULT sceneMain::init()
{
	_player = new player;
	if (_player->getMoveUp() == true)
	{
		_player->setPlayerPositionUp();
		_player->setMoveDown(false);
	}
	else if (_player->getMoveDown() == true)
	{
		_player->setPlayerPositionDown();
		_player->setMoveDown(false);
	}
	else if (_player->getMoveLeft() == true)
	{
		_player->setPlayerPositionLeft();
		_player->setMoveLeft(false);

	}
	else if (_player->getMoveRight() == true)
	{
		_player->setPlayerPositionRight();
		_player->setMoveRight(false);

	}
	else
	{
		_player->init();
	}

	scene1Rect = RectMakeCenter(0, WINSIZEY / 2, 100, 100);
	scene2Rect = RectMakeCenter(WINSIZEX / 2, 0, 100, 100);
	scene3Rect = RectMakeCenter(WINSIZEX, WINSIZEY / 2, 100, 100);
	scene4Rect = RectMakeCenter(WINSIZEX / 2, WINSIZEY, 100, 100);
	return S_OK;
}

void sceneMain::release()
{

}

void sceneMain::update()
{
	_player->update();
	RECT temp;
	if (IntersectRect(&temp, &_player->getPlayerRect(), &scene1Rect))
	{
		_player->setMoveLeft(true);
		SCENEMANAGER->changeScene("scene1");
	}
	if (IntersectRect(&temp, &_player->getPlayerRect(), &scene2Rect))
	{
		_player->setMoveUp(true);
		SCENEMANAGER->changeScene("scene2");
	}
	if (IntersectRect(&temp, &_player->getPlayerRect(), &scene3Rect))
	{
		_player->setMoveRight(true);
		SCENEMANAGER->changeScene("scene3");
	}
	if (IntersectRect(&temp, &_player->getPlayerRect(), &scene4Rect))
	{
		_player->setMoveDown(true);
		SCENEMANAGER->changeScene("scene4");
	}
}

void sceneMain::render()
{
	Rectangle(getMemDC(), scene1Rect.left, scene1Rect.top, scene1Rect.right, scene1Rect.bottom);
	Rectangle(getMemDC(), scene2Rect.left, scene2Rect.top, scene2Rect.right, scene2Rect.bottom);
	Rectangle(getMemDC(), scene3Rect.left, scene3Rect.top, scene3Rect.right, scene3Rect.bottom);
//	Rectangle(getMemDC(), scene4Rect.left, scene4Rect.top, scene4Rect.right, scene4Rect.bottom);
	_player->render();
}

