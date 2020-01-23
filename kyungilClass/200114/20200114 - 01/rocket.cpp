#include "stdafx.h"
#include "rocket.h"
#include "enemyManager.h"
//CPP에 인클루드 해야 상호참조가 된다.

rocket::rocket()
{
}

rocket::~rocket()
{
}

HRESULT rocket::init()
{

	_player = IMAGEMANAGER->addImage("rocket", "images/rocket.bmp", WINSIZEX / 2, WINSIZEY - 200, 52, 64, true, RGB(255, 0, 255));

	rc = RectMakeCenter(WINSIZEX / 2, WINSIZEY / 2, _player->getWidth(), _player->getHeight());


	_missile = new missile;
	_missile->init(30, 1000);

	_nuclear = new nuclear;
	_nuclear->init(30, 1000);

	_maxHp = 100;
	_currentHp = 100;

	_hpBar = new progressBar;
	_hpBar->init("images/progressBarFront.bmp", "images/progressBarBack.bmp", 0, 0, 50, 10);
	_hpBar->setGauge(_currentHp, _maxHp);
	return S_OK;
}

void rocket::release()
{
	SAFE_DELETE(_missile);
	SAFE_DELETE(_nuclear);
	SAFE_DELETE(_hpBar);
}

void rocket::update()
{
	//왼쪽
	if (KEYMANAGER->isStayKeyDown(VK_LEFT) && _player->getX() > 0)
	{
		_player->setX(_player->getX() - PLAYERSPEED);
	}

	//오른쪽
	if (KEYMANAGER->isStayKeyDown(VK_RIGHT) && _player->getX() + _player->getWidth() < WINSIZEX)
	{
		_player->setX(_player->getX() + PLAYERSPEED);
	}

	//위
	if (KEYMANAGER->isStayKeyDown(VK_UP) && _player->getY() > 0)
	{
		_player->setY(_player->getY() - PLAYERSPEED);
	}

	//아래
	if (KEYMANAGER->isStayKeyDown(VK_DOWN) && _player->getY() + _player->getHeight() < WINSIZEY)
	{
		_player->setY(_player->getY() + PLAYERSPEED);
	}

	//if (KEYMANAGER->isStayKeyDown(VK_LEFT) )
	//{
	//	rc.left -= PLAYERSPEED;
	//	rc.right -= PLAYERSPEED;
	//}

	////오른쪽
	//if (KEYMANAGER->isStayKeyDown(VK_RIGHT) )
	//{
	//	rc.left += PLAYERSPEED;
	//	rc.right += PLAYERSPEED;
	//}

	////위
	//if (KEYMANAGER->isStayKeyDown(VK_UP))
	//{
	//	rc.top -= PLAYERSPEED;
	//	rc.bottom -= PLAYERSPEED;
	//}

	////아래
	//if (KEYMANAGER->isStayKeyDown(VK_DOWN))
	//{
	//	rc.top += PLAYERSPEED;
	//	rc.bottom += PLAYERSPEED;
	//}

	if (KEYMANAGER->isOnceKeyDown(VK_SPACE))
	{
		//_missile->fire(rc.right - (rc.right - rc.left) / 2, rc.top - 50);
		_missile->fire(_player->getX() + _player->getWidth() / 2, _player->getY() - 50);
	}
	if (KEYMANAGER->isOnceKeyDown('Z'))
	{
		//_nuclear->fire(rc.right - (rc.right - rc.left) / 2, rc.top - 50);
		_nuclear->fire(_player->getX() + _player->getWidth() / 2, _player->getY() - 50);


	}
	_missile->update();
	_nuclear->update();

	collision();

	// 프로그레스
	// 렉트에 하려면 X값에 렉트의 좌표값을 넣어준다.
	_hpBar->setX(_player->getX());
	_hpBar->setY(_player->getY() - 15);
	_hpBar->setGauge(_currentHp, _maxHp);
	_hpBar->update();
}

void rocket::render()
{
	_player->render(getMemDC(), _player->getX(), _player->getY());
	//_player->render(getMemDC(), rc.left, rc.top);

	_missile->render();
	_nuclear->render();

	_hpBar->render();
}

void rocket::removeBullet(int arrNum)
{
	_nuclear->removeNuclear(arrNum);
}

void rocket::collision()
{
}

void rocket::hitDamage(float damage)
{
	_currentHp -= damage;
}

