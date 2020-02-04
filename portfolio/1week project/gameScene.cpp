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
	// player
	IMAGEMANAGER->addImage("playerCommonBullet", "images/PlayerNormalBullet.bmp", 30, 64, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("playerHomingBullet", "images/playerHomingBullet.bmp", 13, 12, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("playerHitImage", "images/playerHitImage.bmp", 12, 12, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("playerCannon", "images/playerCannon.bmp", 15, 15, true, RGB(255, 0, 255));
	
	IMAGEMANAGER->addFrameImage("score", "images/score.bmp", 180, 18, 10, 1, true, RGB(255, 0, 255));

	IMAGEMANAGER->addImage("UIplayer", "images/UIplayer.bmp", 53, 19, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("UIHP", "images/UIHP.bmp", 25, 17, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("UIPower", "images/UIPower.bmp", 53, 19, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("UIScore", "images/UIScore.bmp", 49, 19, true, RGB(255, 0, 255));
	
	// enemys
	IMAGEMANAGER->addFrameImage("redEnemy", "images/redEnemy.bmp", 1320 / 2, 200 / 2, 12, 2, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("greenEnemy", "images/greenEnemy.bmp", 1320 / 2, 200 / 2, 12, 2, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("blueEnemy", "images/blueEnemy.bmp", 1320 / 2, 200 / 2, 12, 2, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("yellowEnemy", "images/yellowEnemy.bmp", 1320 / 2, 200 / 2, 12, 2, true, RGB(255, 0, 255));

	IMAGEMANAGER->addFrameImage("redMinion", "images/redMinion.bmp", 360, 60, 12, 2, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("redMinionBullet", "images/redMinionBullet.bmp", 16, 16, true, RGB(255, 0, 255));
	
	IMAGEMANAGER->addFrameImage("blueMinion", "images/blueMinion.bmp", 360, 60, 12, 2, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("blueMinionBullet", "images/blueMinionBullet.bmp", 16, 16, true, RGB(255, 0, 255));

	IMAGEMANAGER->addFrameImage("greenMinion", "images/greenMinion.bmp", 360, 60, 12, 2, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("greenMinionBullet", "images/greenMinionBullet.bmp", 16, 16, true, RGB(255, 0, 255));

	IMAGEMANAGER->addFrameImage("yellowMinion", "images/yellowMinion.bmp", 360, 60, 12, 2, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("yellowMinionBullet", "images/yellowMinionBullet.bmp", 16, 16, true, RGB(255, 0, 255));

	IMAGEMANAGER->addImage("minionHomingRedBullet", "images/minionHomingRedBullet.bmp", 27, 31, true, RGB(255, 0, 0));
	IMAGEMANAGER->addImage("minionHomingBlueBullet", "images/minionHomingBlueBullet.bmp", 27, 31, true, RGB(0, 0, 255));
	
	IMAGEMANAGER->addImage("redBullet", "images/redBullet.bmp", 28, 26, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("blueBullet", "images/blueBullet.bmp", 28, 26, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("greenBullet", "images/greenBullet.bmp", 28, 26, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("yellowBullet", "images/yellowBullet.bmp", 28, 26, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("purpleBullet", "images/purpleBullet.bmp", 28, 26, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("skyBullet", "images/skyBullet.bmp", 28, 26, true, RGB(255, 0, 255));

	IMAGEMANAGER->addImage("redStarBullet", "images/redStarBullet.bmp", 31, 30, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("blueStarBullet", "images/blueStarBullet.bmp", 31, 30, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("greenStarBullet", "images/greenStarBullet.bmp", 31, 30, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("yellowStarBullet", "images/yellowStarBullet.bmp", 31, 30, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("skyStarBullet", "images/skyStarBullet.bmp", 31, 30, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("grayStarBullet", "images/grayStarBullet.bmp", 31, 30, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("orangeStarBullet", "images/orangeStarBullet.bmp", 31, 30, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("purpleStarBullet", "images/purpleStarBullet.bmp", 31, 30, true, RGB(255, 0, 255));
	
	IMAGEMANAGER->addImage("redDoubleCircleBullet", "images/redDoubleCircleBullet.bmp", 16, 16, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("blueDoubleCircleBullet", "images/blueDoubleCircleBullet.bmp", 16, 16, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("greenDoubleCircleBullet", "images/greenDoubleCircleBullet.bmp", 16, 16, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("yellowDoubleCircleBullet", "images/yellowDoubleCircleBullet.bmp", 16, 16, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("skyDoubleCircleBullet", "images/skyDoubleCircleBullet.bmp", 16, 16, true, RGB(255, 0, 255));

	IMAGEMANAGER->addImage("redSmallBullet", "images/redSmallBullet.bmp", 8, 8, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("blueSmallBullet", "images/blueSmallBullet.bmp", 8, 8, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("greenSmallBullet", "images/greenSmallBullet.bmp", 8, 8, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("yellowSmallBullet", "images/yellowSmallBullet.bmp", 8, 8, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("skySmallBullet", "images/skySmallBullet.bmp", 8, 8, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("purpleSmallBullet", "images/purpleSmallBullet.bmp", 8, 8, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("graySmallBullet", "images/graySmallBullet.bmp", 8, 8, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("whiteSmallBullet", "images/whiteSmallBullet.bmp", 8, 8, true, RGB(255, 0, 255));

	//BOSS

	IMAGEMANAGER->addFrameImage("remilia", "images/remilia.bmp", 4351, 1134, 19, 7, true, RGB(255, 0, 255));

	//BOSS BULLET

	IMAGEMANAGER->addFrameImage("spBullet", "images/spBullet.bmp", 2432, 128, 19, 1, true, RGB(0, 0, 0));
	IMAGEMANAGER->addImage("redVerticalBullet", "images/redVerticalBullet.bmp", 16, 128, true, RGB(0, 0, 0));
	IMAGEMANAGER->addImage("redHorizontalBullet", "images/redHorizontalBullet.bmp", 128, 16, true, RGB(0, 0, 0));
	IMAGEMANAGER->addImage("spBullet2", "images/spBullet2.bmp", 32, 32, true, RGB(0, 0, 0));
	IMAGEMANAGER->addImage("spBullet3", "images/spBullet3.bmp", 32, 32, true, RGB(0, 0, 0));
	IMAGEMANAGER->addImage("spBullet4", "images/spBullet4.bmp", 256, 256, true, RGB(0, 0, 0));
	IMAGEMANAGER->addImage("spBullet4", "images/spBullet4.bmp", 256, 256, true, RGB(0, 0, 0));
	IMAGEMANAGER->addImage("spbulletSmall1", "images/spbulletSmall1.bmp", 32, 32, true, RGB(0, 0, 0));
	IMAGEMANAGER->addImage("spbulletSmall2", "images/spbulletSmall2.bmp", 32, 32, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("bulletCanon", "images/bulletCanon.bmp", 128, 128, true, RGB(0, 0, 0));

	// Item

	IMAGEMANAGER->addImage("powerItem", "images/powerItem.bmp", 16, 16, true, RGB(0, 0, 0));
	IMAGEMANAGER->addImage("scoreItem", "images/scoreItem.bmp", 16, 16, true, RGB(0, 0, 0));
	IMAGEMANAGER->addImage("playerLifeItem", "images/playerLifeItem.bmp", 16, 16, true, RGB(0, 0, 0));



	IMAGEMANAGER->addImage("UIConsole", "images/UIConsole.bmp", WINSIZEX, WINSIZEY, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("stageBG", "images/stageBG.bmp", WINSIZEX, WINSIZEY, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("bossBackGround", "images/bossBackGround.bmp", WINSIZEX, WINSIZEY, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("black", "images/black.bmp", WINSIZEX, WINSIZEY, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("gameovertext", "images/gameovertext.bmp", 95*3, 65*3, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("clearText", "images/clearText.bmp", 100*3, 50*3, true, RGB(255, 0, 255));
	
	PLAYER->init();
	ENEMYMANAGER->init();
	BULLETMANAGER->init();

	loopY = 0;
	change = true;

	stageBG = 255;
	bossBG = 0;
	black = 0;

	return S_OK;
}

void gameScene::release()
{
}

void gameScene::update()
{

	PLAYER->update();

	ENEMYMANAGER->update();

	if (ENEMYMANAGER->mapChange())
	{
		loopY -= 10;
	}
	else
	{
		change = false;
		addSpeed++;
		if (addSpeed <= 100)
		{
			loopY -= 10 - (addSpeed / 10);
		}
	}
	if (addSpeed >= 300)
	{
		if (stageBG != 0)
		{
			stageBG--;
			bossBG++;
		}
	}

	if (ENEMYMANAGER->gameOver())
	{
		black++;
		if (black >= 255)
		{
			black = 255;
			gameOver++;
			if (gameOver >= 255)
			{
				gameOver = 255;
			}
		}
	}


	if (ENEMYMANAGER->clear())
	{
		black++;
		if (black >= 255)
		{
			black = 255;
			clear++;
			if (clear >= 255)
			{
				clear = 255;
			}
		}
	}

	if (KEYMANAGER->isOnceKeyDown('1'))
	{
		//¾ÀÃ¼ÀÎÁö
		SCENEMANAGER->changeScene("introScene");
	}	
}

void gameScene::render()
{
	//IMAGEMANAGER->loopRender("stageBG", getMemDC(), &RectMake(0, 0, WINSIZEX, WINSIZEY), loopX, loopY);
	IMAGEMANAGER->loopAlphaRender("bossBackGround", getMemDC(), &RectMake(0, 0, WINSIZEX, WINSIZEY), 0, 0, bossBG);
	IMAGEMANAGER->loopAlphaRender("stageBG", getMemDC(), &RectMake(0, 0, WINSIZEX, WINSIZEY), loopX, loopY, stageBG);
	PLAYER->render();
	ENEMYMANAGER->render();

	IMAGEMANAGER->loopAlphaRender("black", getMemDC(), &RectMake(0, 0, WINSIZEX, WINSIZEY), 0, 0, black);
	IMAGEMANAGER->loopAlphaRender("gameovertext", getMemDC(), &RectMake(275, 300, 95 * 3, 65 * 3), 0, 0, gameOver);
	IMAGEMANAGER->loopAlphaRender("clearText", getMemDC(), &RectMake(275, 300, 100 * 3, 50 * 3), 0, 0, clear);


	IMAGEMANAGER->render("UIConsole", getMemDC());
	
	PLAYER->scoreRender();
	
	if (KEYMANAGER->isToggleKey(VK_F3))
	{
		statusWindow = RectMake(735, 300, 250, 300);
		Rectangle(getMemDC(), statusWindow.left, statusWindow.top, statusWindow.right, statusWindow.bottom);

		PLAYER->statusRender();

		OBJECTPOOL->statusRender(getMemDC());

		ENEMYMANAGER->statusRender();
	}
	
	//sprintf_s(str, "x :  %d", m_ptMouse.x);
	//TextOut(getMemDC(), 740, 560, str, strlen(str));

	//sprintf_s(str, "y :  %d", m_ptMouse.y);
	//TextOut(getMemDC(), 740, 580, str, strlen(str));
}
