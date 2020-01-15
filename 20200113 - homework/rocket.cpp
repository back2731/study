#include "stdafx.h"
#include "rocket.h"

rocket::rocket()
{
}

rocket::~rocket()
{
}

HRESULT rocket::init()
{

	_player = IMAGEMANAGER->addFrameImage("레이무", "images/test.bmp", 256, 141, 8, 3, true, RGB(255, 0, 255));

	rc = RectMakeCenter(WINSIZEX / 2, WINSIZEY / 2, _player->getWidth(), _player->getHeight());


	_missile = new missile;
	_missile->init(30, 1000);

	_nuclear = new nuclear;
	_nuclear->init();

	return S_OK;
}

void rocket::release()
{
	SAFE_DELETE(_missile);
	SAFE_DELETE(_nuclear);
}

void rocket::update()
{
	// 왼쪽
	if (KEYMANAGER->isStayKeyDown(VK_LEFT) )
	{
		rc.left -= PLAYERSPEED;
		rc.right -= PLAYERSPEED;
	}

	//오른쪽
	if (KEYMANAGER->isStayKeyDown(VK_RIGHT) )
	{
		rc.left += PLAYERSPEED;
		rc.right += PLAYERSPEED;
	}

	//위
	if (KEYMANAGER->isStayKeyDown(VK_UP))
	{
		rc.top -= PLAYERSPEED;
		rc.bottom -= PLAYERSPEED;
	}

	//아래
	if (KEYMANAGER->isStayKeyDown(VK_DOWN))
	{
		rc.top += PLAYERSPEED;
		rc.bottom += PLAYERSPEED;
	}

	if (KEYMANAGER->isOnceKeyDown(VK_SPACE))
	{
		_missile->fire(rc.right - (rc.right - rc.left) / 2, rc.top - 50);
		_missile->fire(1, 1);
	}
	if (KEYMANAGER->isStayKeyDown('Z'))
	{
		count++;
		//if (count % 5 == 0)
		//{
			_nuclear->fire(rc.right - (rc.right - rc.left) / 2, rc.top - 50);
		//}
	}
	if (KEYMANAGER->isOnceKeyDown('Z'))
	{
		count++;
		_nuclear->fire(rc.right - (rc.right - rc.left) / 2, rc.top - 50);
	}
	_missile->update();
	_nuclear->update();
}

void rocket::render()
{
	//_player->render(getMemDC(), _player->getX(), _player->getY());
	if (KEYMANAGER->isToggleKey(VK_TAB))
	{
		Rectangle(getMemDC(), rc.left, rc.top, rc.right, rc.bottom);
	}
	_player->render(getMemDC(), rc.left, rc.top);
	_missile->render();
	_nuclear->render();

	wsprintf(str, "count :  %d", count);
	TextOut(getMemDC(), 500, 0, str, strlen(str));
}


