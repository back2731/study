#include "stdafx.h"
#include "gameScene.h"


gameScene::gameScene()
{
}


gameScene::~gameScene()
{
}

HRESULT gameScene::init()
{
	IMAGEMANAGER->addImage("BG2", "images/BossBackGround2.bmp", WINSIZEX, WINSIZEY, true, RGB(255, 0, 255));
	m_player = new player;
	m_player->init();

	return S_OK;
}

void gameScene::release()
{
	SAFE_DELETE(m_player);
}

void gameScene::update()
{
	m_player->update();
	if (KEYMANAGER->isOnceKeyDown('1'))
	{
		//¾ÀÃ¼ÀÎÁö
		SCENEMANAGER->changeScene("introScene");
	}
	OBJECTPOOL->reloadBullet();
}

void gameScene::render()
{
	IMAGEMANAGER->render("BG2", getMemDC());
	m_player->render();
}
