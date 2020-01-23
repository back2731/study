#pragma once
#include "gameNode.h"
class minimap : public gameNode
{
private:
	image* _rockman;
	
	int _index;
	int _count;

	int _camera;

	bool _isLeft;

	RECT mini_rc;

public:
	minimap();
	~minimap();

	HRESULT init();	//�ʱ�ȭ
	void release();//����
	void update();//�����ϴ°�
	void render(HDC hdc);//�׸��°�
};

