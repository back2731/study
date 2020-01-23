#pragma once
#include"gameNode.h"
#define PLAYERSPEED 5
#define CAMERASPEED 5
#define OBSTACLE 5
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
	image* _bigFireRingBack;
	image* _bigFireRingFront;
	image* _smallFireRingBack;
	image* _smallFireRingFront;
	image* _lamp;

	int _index;
	int _count;
	int _camera;
	int _score;

	int _backRingCount;
	int _backRingindex;
	int _frontRingCount;
	int _frontRingindex;

	int _sBackRingCount;
	int _sBackRingindex;
	int _sFrontRingCount;
	int _sFrontRingindex;

	int _lampCount;
	int _lampindex;

	int addGravity;

	bool _isLeft;
	bool _isMove;
	bool _isTouch;
	bool _isGoal;

	tagRect playerRect;
	tagRect bottomRect;
	tagRect lampRect;
	tagRect goalRect;
	tagRect gardRect;

	tagRect temp;

	tagRect fireRing[4];
	tagRect fireRingImage[4];

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
	void gameOver();

};

