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

	//_player = new player;
	//_player->init();

	SCENEMANAGER->addScene("scene1", new scene1);
	SCENEMANAGER->addScene("scene2", new scene2);
	SCENEMANAGER->addScene("scene3", new scene3);
	SCENEMANAGER->addScene("scene4", new scene4);
	SCENEMANAGER->addScene("sceneMain", new sceneMain);

	SCENEMANAGER->changeScene("sceneMain");
	

	return S_OK;
}

void mainGame::release()
{
	gameNode::release();
	//SAFE_DELETE(_player);
}
void mainGame::update()
{
	gameNode::update();
	
	//_player->update();
	SCENEMANAGER->update();

}

void mainGame::render(/*HDC hdc*/)
{
	
	//��� ��Ʈ��
	PatBlt(getMemDC(), 0, 0, WINSIZEX, WINSIZEY, WHITENESS);
	//===================================================

	SCENEMANAGER->render();
	//_player->render()
	
	TIMEMANAGER->render(getMemDC());
	//=================================================
	//������� ������ HDC�� �׸���.(�ǵ帮������.)
	this->getBackBuffer()->render(getHDC(), 0, 0);
}


