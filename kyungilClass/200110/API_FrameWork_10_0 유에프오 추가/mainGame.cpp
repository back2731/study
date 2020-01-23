#include "stdafx.h"
#include "mainGame.h"
mainGame::mainGame()
{
}
mainGame::~mainGame()
{
}
HRESULT mainGame::init()
{
	gameNode::init(true);

	IMAGEMANAGER->addImage("배경화면", "images/사나.bmp", WINSIZEX, WINSIZEY, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("bullet", "images/bullet.bmp", 21, 21, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("ufo", "images/ufo.bmp", 530, 32, 10, 1, true, RGB(255, 0, 255));
	_rocket = new rocket;
	_rocket->init();


	_enemyManager = new enemyManager;
	_enemyManager->init();


	return S_OK;
}

void mainGame::release()
{
	gameNode::release();
	SAFE_DELETE(_rocket);
	SAFE_DELETE(_enemyManager);	
}

void mainGame::update()
{
	gameNode::update();
	
	_rocket->update();
	_enemyManager->update();

}

void mainGame::render(/*HDC hdc*/)
{
	
	//흰색 비트맵
	PatBlt(getMemDC(), 0, 0, WINSIZEX, WINSIZEY, WHITENESS);
	//===================================================

	IMAGEMANAGER->render("배경화면", getMemDC());
	_rocket->render();
	_enemyManager->render();
	if (isCollision())
	{
		wsprintf(str, "충돌쓰 ");
		TextOut(getMemDC(), WINSIZEX / 2, WINSIZEY / 2, str, strlen(str));
	}
	TIMEMANAGER->render(getMemDC());
	//=================================================
	//백버퍼의 내용을 HDC에 그린다.(건드리지말것.)
	this->getBackBuffer()->render(getHDC(), 0, 0);
}

bool mainGame::isCollision()
{
	_vEnemyManager = _enemyManager->getVMinion();
	_vRocket = _rocket->getMissileVBullet();

	_viEnemyManager = _vEnemyManager.begin();
	_viRocket = _vRocket.begin();

	for (_viEnemyManager; _viEnemyManager != _vEnemyManager.end(); ++_viEnemyManager)
	{
		for (_viRocket; _viRocket != _vRocket.end(); ++_viRocket)
		{
			if (IntersectRect(&_temp, &((*_enemyManager->getViMinion())->getRect()), &(_rocket->getNuclearVIBullet()->rc)))
			{
				return true;
			}
		}
	}


		//_enemyManager->getViMinion() = _enemyManager->getVMinion().begin();
	//_rocket->getNuclearVIBullet() = _rocket->getNuclearVBullet().begin();
	//for (_enemyManager->getViMinion(); _enemyManager->getViMinion() != _enemyManager->getVMinion().end(); ++_enemyManager->getViMinion())
	//{
	//	for (_rocket->getNuclearVIBullet(); _rocket->getNuclearVIBullet() != _rocket->getNuclearVBullet().end(); ++_rocket->getNuclearVIBullet())
	//	{
	//		if (IntersectRect(&_temp, &((*_enemyManager->getViMinion())->getRect()), &(_rocket->getNuclearVIBullet()->rc)))
	//		{
	//			return true;
	//		}
	//	}
	//}
}

