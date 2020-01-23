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

	HRESULT init();	//초기화
	void release();//해제
	void update();//연산하는곳
	void render();//그리는곳

	void Gravity(tagRect &a);
	void Jump(tagRect &a);
	void CrashBox(tagRect &a, tagRect &b);

};

