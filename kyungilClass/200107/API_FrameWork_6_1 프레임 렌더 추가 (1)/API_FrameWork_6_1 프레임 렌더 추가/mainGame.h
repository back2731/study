#pragma once
#include"gameNode.h"

class mainGame :  public gameNode
{
struct tagBox
{
	RECT rc;
	bool isTouch;
};

private:
	image * _bgImage;
	image* _character;
	image* _jump;

	tagBox _box;

	int _index;		//������ �ε���
	int _idleIndex = 0;
	int _count;		//������ ���� ī��Ʈ
	int _mapCount;
	bool _isLeft;	//������?
	bool _isIdle;
	bool _isJump;


public:
	mainGame();
	~mainGame();

	virtual HRESULT init();	//�ʱ�ȭ
	virtual void release();//����
	virtual void update();//�����ϴ°�
	virtual void render(HDC hdc);//�׸��°�

	
};

