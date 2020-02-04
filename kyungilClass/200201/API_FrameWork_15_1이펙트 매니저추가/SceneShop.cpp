#include "stdafx.h"
#include "SceneShop.h"

SceneShop::SceneShop()
{
}

SceneShop::~SceneShop()
{
}

HRESULT SceneShop::init()
{
	IMAGEMANAGER->addImage("map", "images/¸Ê2.bmp", WINSIZEX, WINSIZEY, true, RGB(255, 0, 255));
	SHOP->init();
	INVENTORY->init();
	EQUIPMENT->init();
	STATUS->init();
	return S_OK;
}

void SceneShop::release()
{
}

void SceneShop::update()
{
	SHOP->update();
	INVENTORY->update();
	EQUIPMENT->update();
	STATUS->update();
}

void SceneShop::render()
{
	IMAGEMANAGER->render("map", getMemDC());
	SHOP->render(getMemDC());
	INVENTORY->render(getMemDC());
	EQUIPMENT->render(getMemDC());
	STATUS->render(getMemDC());
}
