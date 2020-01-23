#pragma once
#include <Windows.h>
#include "shop.h"
#include "Player.h"

enum LOCATION
{
	LOCATION_SHOP = 1,
	LOCATION_SELL_INVENTORY,
	LOCATION_INVENTORY,
};

class mainGame
{
private:
	shop* m_shop;
	Player* m_player;
	LOCATION m_loc;

	int m_gold;
	int m_selectNum;

public:
	mainGame();
	~mainGame();

	// ����, �κ��丮�� �̵��ϴ� �Լ�
	void setLocation(int number);
	// ���������� �����ִ� �Լ�
	void setMainPage();
	// ����ȭ�� �����ִ� �Լ�
	void setShopPage();
	// ���� �������� �����ִ� �Լ�
	void setShopItemPage(int itemKind);
	// �κ��丮 ���� �Ǹ� �����ִ� �Լ�
	void setSellInventoryPage();
	// �κ��丮 �����ִ� �Լ�
	void setInventoryPage();
};

