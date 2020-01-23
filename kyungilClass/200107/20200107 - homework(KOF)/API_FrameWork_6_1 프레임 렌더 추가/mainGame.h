#pragma once
#include"gameNode.h"

#define GRAVITY 0.1
#define JUMPPOWER 3

class mainGame :  public gameNode
{
struct tagRect
{
	RECT rc;
	bool isTouch;	
	bool isJump;
};

private:
	image * _bgImage;
	image* _character;
	image* _jump;

	tagRect _box;
	tagRect _floor;
	tagRect _barrigate;
	tagRect _gard[2];

	tagRect _temp;

	int _mapIndex;		//������ �ε���
	int _idleIndex;
	int _moveIndex;
	int _jumpIndex;
	int _ultimateIndex;

	int _mapCount;
	int _idleCount = 0;
	int _moveCount = 0;
	int _jumpCount = 0;
	int _ultimateCount = 0;

	float addGravity;

	bool _isLeft;	//������?
	bool _isRight;
	bool _isIdle;
	bool _isUltimate;


public:
	mainGame();
	~mainGame();

	virtual HRESULT init();	//�ʱ�ȭ
	virtual void release();//����
	virtual void update();//�����ϴ°�
	virtual void render(HDC hdc);//�׸��°�

	void Gravity(tagRect &a);
	void Jump(tagRect &a);
	void CrashBox(tagRect &a, tagRect &b);

	
};

