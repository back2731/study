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

	// 플레이어 통상 불릿
	vector<bulletInfo> vPlayerCommonBullet;
	vector<bulletInfo>::iterator viPlayerCommonBullet;
	bulletInfo playerCommonBullet;

	// 플레이어 호밍 불릿
	vector<bulletInfo> vPlayerHomingBullet;
	vector<bulletInfo>::iterator viPlayerHomingBullet;
	bulletInfo playerHomingBullet;

	// 통상 레드 불릿
	vector<bulletInfo> vCommonRedBullet;
	vector<bulletInfo>::iterator viCommonRedBullet;
	bulletInfo commonRedBullet;
	tagCannon commonRedCannon;
	int commonRedBulletSpeed;

	// 스핀 레드 불릿
	vector<bulletInfo> vSpinRedBullet;
	vector<bulletInfo>::iterator viSpinRedBullet;
	bulletInfo spinRedBullet;
	tagCannon spinRedCannon;
	int spinRedBulletSpeed;

	// 호밍 레드 불릿
	vector<bulletInfo> vHomingRedBullet;
	vector<bulletInfo>::iterator viHomingRedBullet;
	bulletInfo homingRedBullet;
	tagCannon homingRedCannon;
	int homingRedBulletSpeed;

	// 통상 블루 불릿
	vector<bulletInfo> vCommonBlueBullet;
	vector<bulletInfo>::iterator viCommonBlueBullet;
	bulletInfo commonBlueBullet;
	tagCannon commonBlueCannon;
	int commonBlueBulletSpeed;

	// 스핀 블루 불릿
	vector<bulletInfo> vSpinBlueBullet;
	vector<bulletInfo>::iterator viSpinBlueBullet;
	bulletInfo spinBlueBullet;
	tagCannon spinBlueCannon;
	int spinBlueBulletSpeed;

	// 호밍 블루 불릿
	vector<bulletInfo> vHomingBlueBullet;
	vector<bulletInfo>::iterator viHomingBlueBullet;
	bulletInfo homingBlueBullet;
	tagCannon homingBlueCannon;
	int homingBlueBulletSpeed;

	// 통상 그린 불릿
	vector<bulletInfo> vCommonGreenBullet;
	vector<bulletInfo>::iterator viCommonGreenBullet;
	bulletInfo commonGreenBullet;
	tagCannon commonGreenCannon;
	int commonGreenBulletSpeed;

	// 스핀 그린 불릿
	vector<bulletInfo> vSpinGreenBullet;
	vector<bulletInfo>::iterator viSpinGreenBullet;
	bulletInfo spinGreenBullet;
	tagCannon spinGreenCannon;
	int spinGreenBulletSpeed;

	// 통상 옐로우 불릿
	vector<bulletInfo> vCommonYellowBullet;
	vector<bulletInfo>::iterator viCommonYellowBullet;
	bulletInfo commonYellowBullet;
	tagCannon commonYellowCannon;
	int commonYellowBulletSpeed;

	// 스핀 옐로우 불릿
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

	// 플레이어 통상 총알
	void playerCommonBulletFire(float x, float y);
	void playerCommonBulletMove();
	void playerCommonBulletRender();

	// 플레이어 유도 총알
	void playerHomingBulletFire(float playerBulletX, float playerBulletY);
	void playerHomingBulletMove();
	void playerHomingBulletRender();

	// 플레이어 총알 충돌(플레이어 -> 미니언)
	void playerBulletCollision();
	void playerCommonBulletRedMinionCollision();
	void playerCommonBulletBlueMinionCollision();
	void playerCommonBulletGreenMinionCollision();
	void playerCommonBulletYellowMinionCollision();
	void playerHomingBulletRedMinionCollision();
	void playerHomingBulletBlueMinionCollision();
	void playerHomingBulletGreenMinionCollision();
	void playerHomingBulletYellowMinionCollision();


	// 미니언 통상 총알
	void minionCommonBulletFire(int bulletKind, float x, float y, float angle, float bulletSpeed, int interval);
	void minionCommonBulletMove(int bulletKind);
	void minionCommonBulletRender(int bulletKind);

	// 미니언 회전 총알
	void minionSpinBulletFire(int bulletKind, float x, float y, int interval);
	void minionSpinBulletMove(int bulletKind);
	void minionSpinBulletRender(int bulletKind);

	// 미니언 유도 총알
	void minionHomingBulletFire(int bulletKind, float x, float y, float playerX, float playerY, float bulletSpeed, int interval);
	void minionHomingBulletMove(int bulletKind);
	void minionHomingBulletRender(int bulletKind);

	// 미니언 총알 충돌(미니언 -> 플레이어)
	void minionBulletCollision();
	void redBulletPlayerCollision();
	void blueBulletPlayerCollision();
	void greenBulletPlayerCollision();
	void yellowBulletPlayerCollision();

};

