#pragma once
#include"gameNode.h"
#include"sceneMain.h"
#include"scene1.h"
#include"scene2.h"
#include"scene3.h"
#include"scene4.h"
//#include"player.h"

class mainGame :  public gameNode
{
private:
	//player* _player;
	//sceneMain* _sceneMain;

public:
	mainGame();
	~mainGame();

	virtual HRESULT init();	//�ʱ�ȭ
	virtual void release();//����
	virtual void update();//�����ϴ°�
	virtual void render(/*HDC hdc*/);//�׸��°�

	
};

