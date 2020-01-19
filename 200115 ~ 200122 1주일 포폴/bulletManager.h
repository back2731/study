#pragma once
#include "singletonBase.h"
#include "gameNode.h"
#include "enemyManager.h"
#include "player.h"	

#define PLAYERHIT	50
#define ENEMYHIT	30

enum bulletCase
{
	MINION_REDBULLET,
	MINION_BLUEBULLET, 
	MINION_GREENBULLET, 
	MINION_YELLOWBULLET,
};
struct tagCannon
{
	POINT center;
	POINT cannonEnd;
	int cannon;
	float angle;
};
class bulletManager : public gameNode, public singletonBase<bulletManager>
{
private:

	// �÷��̾� ��� �Ҹ�
	vector<bulletInfo> vPlayerCommonBullet;
	vector<bulletInfo>::iterator viPlayerCommonBullet;
	bulletInfo playerCommonBullet;

	// �÷��̾� ȣ�� �Ҹ�
	vector<bulletInfo> vPlayerHomingBullet;
	vector<bulletInfo>::iterator viPlayerHomingBullet;
	bulletInfo playerHomingBullet;

	// ��� ���� �Ҹ�
	vector<bulletInfo> vCommonRedBullet;
	vector<bulletInfo>::iterator viCommonRedBullet;
	bulletInfo commonRedBullet;
	tagCannon commonRedCannon;
	int commonRedBulletSpeed;

	// ���� ���� �Ҹ�
	vector<bulletInfo> vSpinRedBullet;
	vector<bulletInfo>::iterator viSpinRedBullet;
	bulletInfo spinRedBullet;
	tagCannon spinRedCannon;
	int spinRedBulletSpeed;

	// ȣ�� ���� �Ҹ�
	vector<bulletInfo> vHomingRedBullet;
	vector<bulletInfo>::iterator viHomingRedBullet;
	bulletInfo homingRedBullet;
	tagCannon homingRedCannon;
	int homingRedBulletSpeed;

	// ��� ��� �Ҹ�
	vector<bulletInfo> vCommonBlueBullet;
	vector<bulletInfo>::iterator viCommonBlueBullet;
	bulletInfo commonBlueBullet;
	tagCannon commonBlueCannon;
	int commonBlueBulletSpeed;

	// ���� ��� �Ҹ�
	vector<bulletInfo> vSpinBlueBullet;
	vector<bulletInfo>::iterator viSpinBlueBullet;
	bulletInfo spinBlueBullet;
	tagCannon spinBlueCannon;
	int spinBlueBulletSpeed;

	// ȣ�� ��� �Ҹ�
	vector<bulletInfo> vHomingBlueBullet;
	vector<bulletInfo>::iterator viHomingBlueBullet;
	bulletInfo homingBlueBullet;
	tagCannon homingBlueCannon;
	int homingBlueBulletSpeed;

	// ��� �׸� �Ҹ�
	vector<bulletInfo> vCommonGreenBullet;
	vector<bulletInfo>::iterator viCommonGreenBullet;
	bulletInfo commonGreenBullet;
	tagCannon commonGreenCannon;
	int commonGreenBulletSpeed;

	// ���� �׸� �Ҹ�
	vector<bulletInfo> vSpinGreenBullet;
	vector<bulletInfo>::iterator viSpinGreenBullet;
	bulletInfo spinGreenBullet;
	tagCannon spinGreenCannon;
	int spinGreenBulletSpeed;

	// ��� ���ο� �Ҹ�
	vector<bulletInfo> vCommonYellowBullet;
	vector<bulletInfo>::iterator viCommonYellowBullet;
	bulletInfo commonYellowBullet;
	tagCannon commonYellowCannon;
	int commonYellowBulletSpeed;

	// ���� ���ο� �Ҹ�
	vector<bulletInfo> vSpinYellowBullet;
	vector<bulletInfo>::iterator viSpinYellowBullet;
	bulletInfo spinYellowBullet;
	tagCannon spinYellowCannon;
	int spinYellowBulletSpeed;

	int collisionCheckNum;

public:
	bulletManager();
	~bulletManager();

	HRESULT init();
	void release();
	void update();
	void render();

	int collisionCheck() { return collisionCheckNum; }

	// �÷��̾� ��� �Ѿ�
	void playerCommonBulletFire(float x, float y);
	void playerCommonBulletMove();
	void playerCommonBulletRender();

	// �÷��̾� ���� �Ѿ�
	void playerHomingBulletFire(float playerBulletX, float playerBulletY);
	void playerHomingBulletMove();
	void playerHomingBulletRender();

	// �÷��̾� �Ѿ� �浹(�÷��̾� -> �̴Ͼ�)
	void playerBulletCollision();
	void playerCommonBulletRedMinionCollision();
	void playerCommonBulletBlueMinionCollision();
	void playerCommonBulletGreenMinionCollision();
	void playerCommonBulletYellowMinionCollision();
	void playerHomingBulletRedMinionCollision();
	void playerHomingBulletBlueMinionCollision();
	void playerHomingBulletGreenMinionCollision();
	void playerHomingBulletYellowMinionCollision();


	// �̴Ͼ� ��� �Ѿ�
	void minionCommonBulletFire(int bulletKind, float x, float y, float angle, float bulletSpeed, int interval);
	void minionCommonBulletMove(int bulletKind);
	void minionCommonBulletRender(int bulletKind);

	// �̴Ͼ� ȸ�� �Ѿ�
	void minionSpinBulletFire(int bulletKind, float x, float y, int interval);
	void minionSpinBulletMove(int bulletKind);
	void minionSpinBulletRender(int bulletKind);

	// �̴Ͼ� ���� �Ѿ�
	void minionHomingBulletFire(int bulletKind, float x, float y, float playerX, float playerY, float bulletSpeed, int interval);
	void minionHomingBulletMove(int bulletKind);
	void minionHomingBulletRender(int bulletKind);

	// �̴Ͼ� �Ѿ� �浹(�̴Ͼ� -> �÷��̾�)
	void minionBulletCollision();
	void redBulletPlayerCollision();
	void blueBulletPlayerCollision();
	void greenBulletPlayerCollision();
	void yellowBulletPlayerCollision();

};

