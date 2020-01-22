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

	// ���� �Ѿ�
	// ���� ��Ƽ�� �Ҹ�
	vector<bulletInfo> vBossVerticalBullet;
	vector<bulletInfo>::iterator viBossVerticalBullet;
	bulletInfo bossVerticalBullet;
	tagCannon bossVerticalCannon;
	int bossVerticalBulletSpeed;

	// ���� ȣ����Ż �Ҹ�
	vector<bulletInfo> vBossHorizontalBullet;
	vector<bulletInfo>::iterator viBossHorizontalBullet;
	bulletInfo bossHorizontalBullet;
	tagCannon bossHorizontalCannon;
	int bossHorizontalBulletSpeed;
	
	// ���� ����Ʈ ���� �Ҹ�
	vector<bulletInfo> vBossRightSpinBullet;
	vector<bulletInfo>::iterator viBossRightSpinBullet;
	bulletInfo bossRightSpinBullet;
	tagCannon bossRightSpinCannon;
	int bossRightSpinBulletSpeed;

	// ���� ����Ʈ ���� �Ҹ�
	vector<bulletInfo> vBossLeftSpinBullet;
	vector<bulletInfo>::iterator viBossLeftSpinBullet;
	bulletInfo bossLeftSpinBullet;
	tagCannon bossLeftSpinCannon;
	int bossLeftSpinBulletSpeed;

	// ���� Ŀ�� �Ҹ�
	vector<bulletInfo> vBossCommonBullet;
	vector<bulletInfo>::iterator viBossCommonBullet;
	bulletInfo bossCommonBullet;
	tagCannon bossCommonCannon;
	int bossCommonBulletSpeed;

	// ���� ȣ�� �Ҹ�
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
	void playerCommonBulletBossCollision();
	void playerHomingBulletRedMinionCollision();
	void playerHomingBulletBlueMinionCollision();
	void playerHomingBulletGreenMinionCollision();
	void playerHomingBulletYellowMinionCollision();
	void playerHomingBulletBossCollision();


	// �̴Ͼ� ��� �Ѿ�
	void minionCommonBulletFire(int bulletNum, string bulletKind, float x, float y, float angle, float bulletSpeed, int interval);
	void minionCommonBulletMove(int itemNum);
	void minionCommonBulletRender(int bulletNum);

	// �̴Ͼ� ȸ�� �Ѿ�
	void minionSpinBulletFire(int bulletNum, string bulletKind, float x, float y, int interval);
	void minionSpinBulletMove(int bulletNum);
	void minionSpinBulletRender(int bulletNum);

	// �̴Ͼ� ���� �Ѿ�
	void minionHomingBulletFire(int bulletNum, string bulletKind, float x, float y, float playerX, float playerY, float bulletSpeed, int interval);
	void minionHomingBulletMove(int bulletNum);
	void minionHomingBulletRender(int bulletNum);

	// �̴Ͼ� �Ѿ� �浹(�̴Ͼ� -> �÷��̾�)
	void enemyBulletCollision();
	void redBulletPlayerCollision();
	void blueBulletPlayerCollision();
	void greenBulletPlayerCollision();
	void yellowBulletPlayerCollision();
	void bossBulletPlayerCollision();

	// ����
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

