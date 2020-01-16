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
	IMAGEMANAGER->addImage("playerCommonBullet", "images/PlayerNormalBullet.bmp", 30, 64, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("redMinionBullet", "images/redMinionBullet.bmp", 16, 16, true, RGB(255, 0, 255));

	IMAGEMANAGER->addFrameImage("redMinion", "images/redMinion.bmp", 360, 60, 12, 2, true, RGB(255, 0, 255));

	IMAGEMANAGER->addImage("UIConsole", "images/UIConsole.bmp", WINSIZEX, WINSIZEY, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("stageBG", "images/stageBG.bmp", WINSIZEX, WINSIZEY, true, RGB(255, 0, 255));

	m_player = new player;
	m_player->init();

	m_enemyManager = new enemyManager;
	m_enemyManager->init();

	loopY = 0;
	return S_OK;
}

void gameScene::release()
{
	SAFE_DELETE(m_player);
	SAFE_DELETE(m_enemyManager);
}

void gameScene::update()
{
	m_player->update();
	m_enemyManager->update();
	if (KEYMANAGER->isOnceKeyDown('1'))
	{
		//¾ÀÃ¼ÀÎÁö
		SCENEMANAGER->changeScene("introScene");
	}
	
	loopY -= 2;
}

void gameScene::render()
{
	IMAGEMANAGER->loopRender("stageBG", getMemDC(), &RectMake(0, 0, WINSIZEX, WINSIZEY), loopX, loopY);
	m_player->render();
	m_enemyManager->render();
	IMAGEMANAGER->render("UIConsole", getMemDC());
}
