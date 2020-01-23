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

	// 상점, 인벤토리로 이동하는 함수
	void setLocation(int number);
	// 메인페이지 보여주는 함수
	void setMainPage();
	// 상점화면 보여주는 함수
	void setShopPage();
	// 상점 아이템을 보여주는 함수
	void setShopItemPage(int itemKind);
	// 인벤토리 상점 판매 보여주는 함수
	void setSellInventoryPage();
	// 인벤토리 보여주는 함수
	void setInventoryPage();
};

