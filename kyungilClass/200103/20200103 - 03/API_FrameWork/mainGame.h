#pragma once
#include"gameNode.h"
#define BULLETMAX 30

struct tagBullet
{
	RECT rc;
	bool isFire;
	float speed;
};
class mainGame :  public gameNode
{
private:
	
	tagBullet _bullet[BULLETMAX];

	RECT _player1;
	RECT _player2;

	RECT _gaugeFront;
	RECT _gaugeBack;

	int _r;
	int _g;


public:
	mainGame();
	~mainGame();

	virtual HRESULT init();				//�ʱ�ȭ
	virtual void release();				//����
	virtual void update();				//�����ϴ°�
	virtual void render(HDC hdc);		//�׸��°�

	void BulletFire();					// �߻�
	void BulletMove();					// ������
	void GaugeDraw();					// ������ �׸���
	void Collision();					// �浹
	void PlayerKeyControl();			// ��Ʈ��
};

