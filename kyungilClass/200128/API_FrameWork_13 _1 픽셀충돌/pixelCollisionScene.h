#pragma once
#include"gameNode.h"
#define CHECKNUM 3
class pixelCollisionScene : public gameNode
{

private:

	image * _pacMan;
	RECT _rc;

	image* _enemy;
	RECT _enemyRect;

	RECT item[800];

	float _x, _y;
	int _probeX;	//ÇÈ¼¿°Ë»ç¿ë
	int _probeY;	//ÇÈ¼¿°Ë»ç¿ë

	int _probeTop;
	int _probeLeft;
	int _probeRight;
	int _probeBottom;

	int currentFrameX;
	int currentFrameY;

	int frameIndex;
	int frameCount;

	bool _isUp;
	bool _isDown;
	bool _isLeft;
	bool _isRight;

	bool _isUpMove;
	bool _isDownMove;
	bool _isLeftMove;
	bool _isRightMove;

	char str[128];

public:
	pixelCollisionScene();
	~pixelCollisionScene();

	HRESULT init();
	void release();
	void update();
	void render();

	void playerCollision();
	void playerMove();
	void playerAnimation();
};

