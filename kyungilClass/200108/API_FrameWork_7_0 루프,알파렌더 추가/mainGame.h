#pragma once
#include"gameNode.h"



struct player
{

};
class mainGame :  public gameNode
{
private:
	image * _bgImage;
	image* _rockman;
	int _index;
	int _count;
	bool _isLeft;

	int posX;
	int posY;

	int cameraX;
	int cameraY;

public:
	mainGame();
	~mainGame();

	virtual HRESULT init();	//�ʱ�ȭ
	virtual void release();//����
	virtual void update();//�����ϴ°�
	virtual void render(HDC hdc);//�׸��°�

	
};

