#pragma once
#include"gameNode.h"
#define PLAYERSPEED 5
#define CAMERASPEED 5
#define OBSTACLE 10
#define GRAVITY 1
#define JUMPPOWER 18

struct tagRect
{
	RECT rc;
	bool isTouch;
	bool isJump;
};

class circus : public gameNode
{
private:

	image* _player;
	int _index;
	int _count;
	int _camera;

	int addGravity;

	bool _isLeft;
	bool _isMove;

	tagRect playerRect;
	tagRect bottomRect;
	tagRect temp;

	tagRect fireRing[2];
	tagRect fireRingImage[2];

	char str[128];
public:
	circus();
	~circus();

	HRESULT init();	//�ʱ�ȭ
	void release();//����
	void update();//�����ϴ°�
	void render();//�׸��°�

	void Gravity(tagRect &a);
	void Jump(tagRect &a);
	void CrashBox(tagRect &a, tagRect &b);

};

