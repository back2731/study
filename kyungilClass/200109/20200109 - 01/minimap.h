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

	HRESULT init();	//초기화
	void release();//해제
	void update();//연산하는곳
	void render(HDC hdc);//그리는곳
};

