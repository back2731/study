#pragma once
#include "singletonBase.h"

enum ITEM
{
	ITEM_WEAPON,
	ITEM_CAP,
	ITEM_TOP,
	ITEM_BOTTOM,
	ITEM_GLOVES,
	ITEM_SHOES,
	ITEM_POTION,
	ITEM_END
};

struct tagItemInfo
{
	ITEM itemkind;
	image* itemImage;
	image* itemInfoImage;
	const char* name;
	string description;
	int atk;
	int def;
	int dex;
	int luk;
	int hpPotion;
	int mpPotion;
	int upgrade;
	int price;
};

class ItemManager : public singletonBase<ItemManager>
{
private:
	vector <tagItemInfo> vEquip;
	vector <tagItemInfo> vPotion;

public:
	HRESULT init();
	void release();
	void update();
	void render();

	vector<tagItemInfo> getEquipInfo() { return vEquip; }
	vector<tagItemInfo> getPotionInfo() { return vPotion; }
	tagItemInfo getEquipItem(int num) { return vEquip[num]; }
	tagItemInfo getPotionItem(int num) { return vPotion[num]; }
};

