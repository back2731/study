#pragma once
#include"gameNode.h"
#define FLOORMAX 13
#define LADDERMAX 4
#define GRAVITY 1
#define JUMPPOWER 7

class scene2 : public gameNode
{
private:
	
	int		frameCount;
	int		frameIndex;

	int		addGravity;

	char	str[128];

	bool	isCollision;
	bool	isJump;
	bool	isLeft;
	bool	isLadder;

	RECT	player;
	image*	playerImage;

	RECT	floor[FLOORMAX];
	RECT	ladder[LADDERMAX];
	RECT	leftWall;
	RECT	rightWall[2];

public:
	scene2();
	~scene2();

	HRESULT init();
	void release();
	void update();
	void render();

	void CollisionToFloor();
	void CollisionToLadder();
	void Gravity(RECT &a);
	void Jump(RECT &a);
};

