#pragma once
#include "singletonBase.h"
#include "gameNode.h"
#include "enemyManager.h"
#include "player.h"	

#define PLAYERHIT	10
#define ENEMYHIT	80

#define ENEMYPOINT	3
#define BOSSPOINT	20

#define SCOREITEM	500
#define POWERITEM	5
#define LIFEITEM	5

enum bulletCase
{
	MINION_REDBULLET,
	MINION_BLUEBULLET, 
	MINION_GREENBULLET, 
	MINION_YELLOWBULLET,
};
enum itemKind
{
	SCORE,
	POWER,
	LIFE
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

	vector<ItemInfo> vScoreItem;
	vector<ItemInfo>::iterator viScoreItem;
	ItemInfo scoreItem;
	tagCannon scoreItemCannon;
	int scoreItemAddSpeed;

	vector<ItemInfo> vPowerItem;
	vector<ItemInfo>::iterator viPowerItem;
	ItemInfo powerItem;
	tagCannon powerItemCannon;
	int powerItemAddSpeed;

	vector<ItemInfo> vLifeItem;
	vector<ItemInfo>::iterator viLifeItem;
	ItemInfo lifeItem;
	tagCannon lifeItemCannon;
	int lifeItemAddSpeed;

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

	// 보스 총알
	// 보스 버티컬 불릿
	vector<bulletInfo> vBossVerticalBullet;
	vector<bulletInfo>::iterator viBossVerticalBullet;
	bulletInfo bossVerticalBullet;
	tagCannon bossVerticalCannon;
	int bossVerticalBulletSpeed;

	// 보스 호리젠탈 불릿
	vector<bulletInfo> vBossHorizontalBullet;
	vector<bulletInfo>::iterator viBossHorizontalBullet;
	bulletInfo bossHorizontalBullet;
	tagCannon bossHorizontalCannon;
	int bossHorizontalBulletSpeed;
	
	// 보스 라이트 스핀 불릿
	vector<bulletInfo> vBossRightSpinBullet;
	vector<bulletInfo>::iterator viBossRightSpinBullet;
	bulletInfo bossRightSpinBullet;
	tagCannon bossRightSpinCannon;
	int bossRightSpinBulletSpeed;

	// 보스 레프트 스핀 불릿
	vector<bulletInfo> vBossLeftSpinBullet;
	vector<bulletInfo>::iterator viBossLeftSpinBullet;
	bulletInfo bossLeftSpinBullet;
	tagCannon bossLeftSpinCannon;
	int bossLeftSpinBulletSpeed;

	// 보스 커먼 불릿
	vector<bulletInfo> vBossCommonBullet;
	vector<bulletInfo>::iterator viBossCommonBullet;
	bulletInfo bossCommonBullet;
	tagCannon bossCommonCannon;
	int bossCommonBulletSpeed;

	// 보스 호밍 불릿
	vector<bulletInfo> vBossHomingBullet;
	vector<bulletInfo>::iterator viBossHomingBullet;
	bulletInfo bossHomingBullet;
	tagCannon bossHomingCannon;
	int bossHomingBulletSpeed;


	int collisionCheckNum;

public:
	bulletManager();
	~bulletManager();
	
	HRESULT init();
	void release();
	void update();
	void render();

	int collisionCheck() { return collisionCheckNum; }

	vector<bulletInfo> getPlayerCommonBulletVector() { return vPlayerCommonBullet; }

	//
	void itemSet(int itemNum, float x, float y, float angle, float itemSpeed, int interval);
	void itemMove(int itemNum);
	void itemRender(int itemNum);

	void itemCollision();

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
	void playerCommonBulletBossCollision();
	void playerHomingBulletRedMinionCollision();
	void playerHomingBulletBlueMinionCollision();
	void playerHomingBulletGreenMinionCollision();
	void playerHomingBulletYellowMinionCollision();
	void playerHomingBulletBossCollision();


	// 미니언 통상 총알
	void minionCommonBulletFire(int bulletNum, string bulletKind, float x, float y, float angle, float bulletSpeed, int interval);
	void minionCommonBulletMove(int itemNum);
	void minionCommonBulletRender(int bulletNum);

	// 미니언 회전 총알
	void minionSpinBulletFire(int bulletNum, string bulletKind, float x, float y, int interval);
	void minionSpinBulletMove(int bulletNum);
	void minionSpinBulletRender(int bulletNum);

	// 미니언 유도 총알
	void minionHomingBulletFire(int bulletNum, string bulletKind, float x, float y, float playerX, float playerY, float bulletSpeed, int interval);
	void minionHomingBulletMove(int bulletNum);
	void minionHomingBulletRender(int bulletNum);

	// 미니언 총알 충돌(미니언 -> 플레이어)
	void enemyBulletCollision();
	void redBulletPlayerCollision();
	void blueBulletPlayerCollision();
	void greenBulletPlayerCollision();
	void yellowBulletPlayerCollision();
	void bossBulletPlayerCollision();

	// 보스
	void bossVerticalBulletFire(string bulletKind, float x, float y, float angle, float bulletSpeed, int interval);
	void bossVerticalBulletMove();
	void bossVerticalBulletRender();

	void bossHorizontalBulletFire(string bulletKind, float x, float y, float angle, float bulletSpeed, int interval);
	void bossHorizontalBulletMove();
	void bossHorizontalBulletRender();

	void bossRightSpinBulletFire(string bulletKind, float x, float y, int interval);
	void bossRightSpinBulletMove();
	void bossRightSpinBulletRender();

	void bossLeftSpinBulletFire(string bulletKind, float x, float y, int interval);
	void bossLeftSpinBulletMove();
	void bossLeftSpinBulletRender();

	void bossCommonBulletFire(string bulletKind, float x, float y, float angle, float bulletSpeed, int interval);
	void bossCommonBulletMove();
	void bossCommonBulletRender();

	void bossHomingBulletFire(string bulletKind, float x, float y, float playerX, float playerY, float bulletSpeed, int interval);
	void bossHomingBulletMove();
	void bossHomingBulletRender();

};

