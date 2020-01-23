#include "stdafx.h"
#include "introScene.h"


introScene::introScene()
{
}


introScene::~introScene()
{
}

HRESULT introScene::init()
{
	IMAGEMANAGER->addImage("intro", "images/introscene.bmp", WINSIZEX, WINSIZEY, true, RGB(255, 0, 255));

	return S_OK;
}

void introScene::release()
{
}

void introScene::update()
{
	if (KEYMANAGER->isOnceKeyDown('2'))
	{
		//¾ÀÃ¼ÀÎÁö
		SCENEMANAGER->changeScene("gameScene");
	}

}

void introScene::render()
{
	IMAGEMANAGER->render("intro", getMemDC());
}
