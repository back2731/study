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

	IMAGEMANAGER->addImage("���ȭ��", "images/�糪.bmp", WINSIZEX, WINSIZEY, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("bullet", "images/bullet.bmp", 21, 21, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("ufo", "images/ufo.bmp", 530, 32, 10, 1, true, RGB(255, 0, 255));
	_rocket = new rocket;
	_rocket->init();


	_enemyManager = new enemyManager;
	_enemyManager->init();

	IMAGEMANAGER->addFrameImage("�̻���", "images/missile1.bmp", 0, 0, 416, 64, 13, 1, true, RGB(255, 0, 255));

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
	isCollision();
	if (KEYMANAGER->isOnceKeyDown(VK_F1))
	{
		init();
	}
}

void mainGame::render(/*HDC hdc*/)
{
	
	//��� ��Ʈ��
	PatBlt(getMemDC(), 0, 0, WINSIZEX, WINSIZEY, WHITENESS);
	//===================================================

	IMAGEMANAGER->render("���ȭ��", getMemDC());
	_rocket->render();
	_enemyManager->render();
	TIMEMANAGER->render(getMemDC());
	//=================================================
	//������� ������ HDC�� �׸���.(�ǵ帮������.)
	this->getBackBuffer()->render(getHDC(), 0, 0);
}

void mainGame::isCollision()
{
	//for (int i = 0; i < _rocket->_missile->getVBullet().size(); i++)
	for(int i = 0; i < _rocket->getMissileVBullet().size(); i++)
	{
		RECT temp;
		for (int j = 0; j < _enemyManager->getVMinion().size(); j++)
		{
			if (IntersectRect(&temp, &_rocket->getMissileVBullet()[i].rc, &_enemyManager->getVMinion()[j]->getRect()))
			{
				_enemyManager->deleteEnemy(j);
				_rocket->deleteMissile(i);
				break;
			}
		}
	}

	for (int i = 0; i < _rocket->getNuclearVBullet().size(); i++)
	{
		RECT temp;
		for (int j = 0; j < _enemyManager->getVMinion().size(); j++)
		{
			if (IntersectRect(&temp, &_rocket->getNuclearVBullet()[i].rc, &_enemyManager->getVMinion()[j]->getRect()))
			{
				_enemyManager->deleteEnemy(j);
				_rocket->deleteNuclear(i);
				break;
			}
		}
	}
}

