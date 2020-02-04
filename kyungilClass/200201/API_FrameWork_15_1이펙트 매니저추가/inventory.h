#pragma once
#include "player.h"
#include "singletonBase.h"
#include "shop.h"
#include "equipment.h"

class inventory : public player, public singletonBase<inventory>
{
private:

	image* inventoryWindowImage;
	RECT inventoryWindowRect;

	image* equipmentSlotOnImage;
	RECT equipmentSlotOnRect;
	image* 	equipmentSlotOffImage;
	RECT equipmentSlotOffRect;

	image * consumptionSlotOnImage;
	RECT consumptionSlotOnRect;
	image * consumptionSlotOffImage;
	RECT consumptionSlotOffRect;

	RECT inventorySlotRect[24];

	RECT exitWindow;

	bool inventoryOpen;

	bool selectEquip;
	bool selectConsumption;

	char str[128];

	vector<tagItemInfo> vEquip;
	vector<tagItemInfo>::iterator viEquip;

	vector<tagItemInfo> vPotion;
	vector<tagItemInfo>::iterator viPotion;

public:
	inventory();
	~inventory();

	HRESULT init();
	void release();
	void update();
	void render(HDC hdc);

	vector<tagItemInfo> getEquipVector() { return vEquip; }
	vector<tagItemInfo> getPotionVector() { return vPotion; }
	
	void setEquipVector(int itemNum) { vEquip.erase(vEquip.begin() + itemNum); }
	void setPotionVector(int itemNum) { vPotion.erase(vPotion.begin() + itemNum); }

	void getEquip(tagItemInfo item);
	void getPotion(tagItemInfo item);

	void boughtItemGold(int itemPrice) { playerGold -= itemPrice; }
	void sellItemGold(int itemPrice) { playerGold += itemPrice; }
};

