#include "shop.h"



shop::shop()
{
}


shop::~shop()
{
}

void shop::itemSetup()
{
	/*ITEM_WEAPON = 1,
		ITEM_ARMOR,
		ITEM_ACCERSORY,
		ITEM_POTION,
		ITEM_END*/

	tagItemInfo weapon1;
	weapon1.itemKind = ITEM_WEAPON;
	weapon1.name = "에메랄드 소드";
	weapon1.description = "일격필살";
	weapon1.ability = 30;
	weapon1.price = 5000;
	_vItem.push_back(weapon1);

	tagItemInfo weapon2;
	weapon2.itemKind = ITEM_WEAPON;
	weapon2.name = "지팡이";
	weapon2.description = "파이어볼";
	weapon2.ability = 20;
	weapon2.price = 4000;
	_vItem.push_back(weapon2);

	tagItemInfo armor1;
	armor1.itemKind = ITEM_ARMOR;
	armor1.name = "철갑옷";
	armor1.description = "단단하다";
	armor1.ability = 800;
	armor1.price = 7000;
	_vItem.push_back(armor1);

	tagItemInfo accersory1;
	accersory1.itemKind = ITEM_ACCERSORY;
	accersory1.name = "귀걸이";
	accersory1.description = "고오급";
	accersory1.ability = 10;
	accersory1.price = 1000;
	_vItem.push_back(weapon2);
}

void shop::itemOutput(int itemNum)
{
	for (_viItem = _vItem.begin(); _viItem != _vItem.end(); _viItem++)
	{
		if (_viItem->itemKind != itemNum) continue;

		cout << "=============상점==============" << endl;
		cout << "이름 : " << _viItem->name << endl;
		cout << "성능 : " << _viItem->ability << endl;
		cout << "가격 : " << _viItem->price << endl;
		cout << "설명 : " << _viItem->description << endl;
	}
}
