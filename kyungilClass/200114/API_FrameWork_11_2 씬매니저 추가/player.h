#pragma once
#include "gameNode.h"
#define PLAYERSPEED 5

class player : public gameNode
{
private:
	RECT playerRect;
	static bool up;
	static bool down;
	static bool left;
	static bool right;
	
public:
	player();
	~player();

	HRESULT init();
	void release();
	void update();
	void render();

	RECT getPlayerRect() { return playerRect; }

	void setPlayerPositionUp();
	void setPlayerPositionDown();
	void setPlayerPositionLeft();
	void setPlayerPositionRight();

	bool getMoveUp() { return up; }
	void setMoveUp(bool a) { up = a; }

	bool getMoveDown() { return down; }
	void setMoveDown(bool a) { down = a; }

	bool getMoveLeft() { return left; }
	void setMoveLeft(bool a) { left = a; }

	bool getMoveRight() { return right; }
	void setMoveRight(bool a) { right = a; }
};

