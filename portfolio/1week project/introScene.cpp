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
	IMAGEMANAGER->addFrameImage("introText", "images/introText.bmp", WINSIZEX / 2, WINSIZEY / 2 + 100, 200*3, 12*3, 3, 1, true, RGB(255, 0, 255));
	introText = IMAGEMANAGER->findImage("introText");
	return S_OK;
}

void introScene::release()
{
}

void introScene::update()
{
	frameCount++;
	introText->setFrameY(0);
	if (frameCount % 50 == 0)
	{
		frameCount = 0;
		frameIndex++;
		if (frameIndex > introText->getMaxFrameX())
		{
			frameIndex = 0;
		}
		introText->setFrameX(frameIndex);
	}

	if (KEYMANAGER->isOnceKeyDown(VK_RETURN))
	{
		//¾ÀÃ¼ÀÎÁö
		SCENEMANAGER->changeScene("gameScene");
	}

}

void introScene::render()
{
	IMAGEMANAGER->render("intro", getMemDC());
	IMAGEMANAGER->frameRender("introText", getMemDC(), WINSIZEX / 2-75, WINSIZEY / 2 + 200);
}
