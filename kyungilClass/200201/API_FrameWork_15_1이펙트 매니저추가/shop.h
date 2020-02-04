#pragma once
#include "gameNode.h"
#include "singletonBase.h"
#include"inventory.h"
class shop : public gameNode, public singletonBase<shop>
{
private:

	image* npcImage;
	RECT npcRect;

	image* shopImage;
	RECT shopRect;

	image* shopExitImage;
	RECT shopExitRect;

	image* buyItemImage;
	RECT buyItemRect;

	image* sellItemImage;
	RECT sellItemRect;

	image* equipmentSlotOnImage;
	RECT equipmentSlotOnRect;
	image* equipmentSlotOffImage;
	RECT equipmentSlotOffRect;

	image* consumptionSlotOnImage;
	RECT consumptionSlotOnRect;
	image* consumptionSlotOffImage;
	RECT consumptionSlotOffRect;

	image* buyOffImage1;
	RECT buyOffRect1;
	image* buyOffImage2;
	RECT buyOffRect2;
	image* buyOffImage3;
	RECT buyOffRect3;	
	image* buyOffImage4;
	RECT buyOffRect4;
	image* buyOffImage5;
	RECT buyOffRect5;
	image* buyOffImage6;
	RECT buyOffRect6;
	image* buyOffImage7;
	RECT buyOffRect7;
	image* buyOffImage8;
	RECT buyOffRect8;

	image* buyOnImage1;
	RECT buyOnRect1;
	image* buyOnImage2;
	RECT buyOnRect2;
	image* buyOnImage3;
	RECT buyOnRect3;
	image* buyOnImage4;
	RECT buyOnRect4;
	image* buyOnImage5;
	RECT buyOnRect5;
	image* buyOnImage6;
	RECT buyOnRect6;
	image* buyOnImage7;
	RECT buyOnRect7;
	image* buyOnImage8;
	RECT buyOnRect8;

	image* sellEquipmentSlotOnImage;
	RECT sellEquipmentSlotOnRect;
	image* sellEquipmentSlotOffImage;
	RECT sellEquipmentSlotOffRect;

	image* sellConsumptionSlotOnImage;
	RECT sellConsumptionSlotOnRect;
	image* sellConsumptionSlotOffImage;
	RECT sellConsumptionSlotOffRect;

	image* sellOffImage1;
	RECT sellOffRect1;
	image* sellOffImage2;
	RECT sellOffRect2;
	image* sellOffImage3;
	RECT sellOffRect3;
	image* sellOffImage4;
	RECT sellOffRect4;
	image* sellOffImage5;
	RECT sellOffRect5;
	image* sellOffImage6;
	RECT sellOffRect6;
	image* sellOffImage7;
	RECT sellOffRect7;
	image* sellOffImage8;
	RECT sellOffRect8;

	image* sellOnImage1;
	RECT sellOnRect1;
	image* sellOnImage2;
	RECT sellOnRect2;
	image* sellOnImage3;
	RECT sellOnRect3;
	image* sellOnImage4;
	RECT sellOnRect4;
	image* sellOnImage5;
	RECT sellOnRect5;
	image* sellOnImage6;
	RECT sellOnRect6;
	image* sellOnImage7;
	RECT sellOnRect7;
	image* sellOnImage8;
	RECT sellOnRect8;

	RECT itemSlot[8];
	RECT sellItemSlot[8];

	int frameCount;
	int frameIndex;

	char str[128];

	bool shopOpen;
	bool selectEquip;
	bool selectConsumption;

	bool sellButton;
	bool sellSelectEquip;
	bool sellSelectConsumption;
	
	bool buyNotChoice;
	bool buyItem1;
	bool buyItem2;
	bool buyItem3;
	bool buyItem4;
	bool buyItem5;
	bool buyItem6;
	bool buyItem7;
	bool buyItem8;

	bool sellNotChoice;
	bool sellItem1;
	bool sellItem2;
	bool sellItem3;
	bool sellItem4;
	bool sellItem5;
	bool sellItem6;
	bool sellItem7;
	bool sellItem8;

	vector<tagItemInfo> vEquip;
	vector<tagItemInfo>::iterator viEquip;

	vector<tagItemInfo> vPotion;
	vector<tagItemInfo>::iterator viPotion;

public:
	shop();
	~shop();

	HRESULT init();
	void release();
	void update();
	void render(HDC hdc);

	void npcRender();
	void itemBuyChoice();
	void itemSellChoice();

	void buyItem();
	void sellItem();
};

