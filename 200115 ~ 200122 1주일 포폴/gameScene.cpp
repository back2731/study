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

	// enemys
	IMAGEMANAGER->addFrameImage("redMinion", "images/redMinion.bmp", 360, 60, 12, 2, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("redMinionBullet", "images/redMinionBullet.bmp", 16, 16, true, RGB(255, 0, 255));
	
	IMAGEMANAGER->addFrameImage("blueMinion", "images/blueMinion.bmp", 360, 60, 12, 2, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("blueMinionBullet", "images/blueMinionBullet.bmp", 16, 16, true, RGB(255, 0, 255));

	IMAGEMANAGER->addFrameImage("greenMinion", "images/greenMinion.bmp", 360, 60, 12, 2, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("greenMinionBullet", "images/greenMinionBullet.bmp", 16, 16, true, RGB(255, 0, 255));

	IMAGEMANAGER->addFrameImage("yellowMinion", "images/yellowMinion.bmp", 360, 60, 12, 2, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("yellowMinionBullet", "images/yellowMinionBullet.bmp", 16, 16, true, RGB(255, 0, 255));
	//

	IMAGEMANAGER->addImage("UIConsole", "images/UIConsole.bmp", WINSIZEX, WINSIZEY, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("stageBG", "images/stageBG.bmp", WINSIZEX, WINSIZEY, true, RGB(255, 0, 255));
	
	PLAYER->init();
	ENEMYMANAGER->init();
	BULLETMANAGER->init();

	loopY = 0;
	return S_OK;
}

void gameScene::release()
{
}

void gameScene::update()
{
	PLAYER->update();
	ENEMYMANAGER->update();

	loopY -= 2;	
	
	if (KEYMANAGER->isOnceKeyDown('1'))
	{
		//¾ÀÃ¼ÀÎÁö
		SCENEMANAGER->changeScene("introScene");
	}	
}

void gameScene::render()
{
	IMAGEMANAGER->loopRender("stageBG", getMemDC(), &RectMake(0, 0, WINSIZEX, WINSIZEY), loopX, loopY);
	PLAYER->render();
	ENEMYMANAGER->render();
	IMAGEMANAGER->render("UIConsole", getMemDC());
	OBJECTPOOL->render(getMemDC());
}
