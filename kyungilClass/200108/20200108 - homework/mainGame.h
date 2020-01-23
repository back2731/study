#pragma once
#include"gameNode.h"
#define SPEED 0.1
#define MAXADDSPEED 20
#define ENEMY 3
#define MAXFUEL 1000
#define PI 3.141592653



struct tagRect
{
	RECT rc;
	bool touch;
	int speed;
};
struct tagCannon
{
	POINT center;
	POINT cannonEnd;
	int cannon;
	float angle;
};

class mainGame :  public gameNode
{
private:
	image* _bgImage;
	image* _dashboard;
	tagCannon _cannon;

	image* _player;
	tagRect pRect;

	image* _enemy;
	tagRect enemyCar[ENEMY];
	
	tagRect _gaugeFront;
	tagRect _gaugeBack;

	char str[128];

	bool _isMove;
	bool _isGame;

	int score;

	//������ ����
	float _loopX;
	float _loopY;
	float addSpeed;
	float speed;
	float fuel;
	float usedFuel;
	float enemySpeed;


public:
	mainGame();
	~mainGame();

	virtual HRESULT init();	//�ʱ�ȭ
	virtual void release();//����
	virtual void update();//�����ϴ°�
	virtual void render(HDC hdc);//�׸��°�	
};

