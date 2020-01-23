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
	weapon1.name = "���޶��� �ҵ�";
	weapon1.description = "�ϰ��ʻ�";
	weapon1.ability = 30;
	weapon1.price = 5000;
	_vItem.push_back(weapon1);

	tagItemInfo weapon2;
	weapon2.itemKind = ITEM_WEAPON;
	weapon2.name = "������";
	weapon2.description = "���̾";
	weapon2.ability = 20;
	weapon2.price = 4000;
	_vItem.push_back(weapon2);

	tagItemInfo armor1;
	armor1.itemKind = ITEM_ARMOR;
	armor1.name = "ö����";
	armor1.description = "�ܴ��ϴ�";
	armor1.ability = 800;
	armor1.price = 7000;
	_vItem.push_back(armor1);

	tagItemInfo accersory1;
	accersory1.itemKind = ITEM_ACCERSORY;
	accersory1.name = "�Ͱ���";
	accersory1.description = "�����";
	accersory1.ability = 10;
	accersory1.price = 1000;
	_vItem.push_back(weapon2);
}

void shop::itemOutput(int itemNum)
{
	for (_viItem = _vItem.begin(); _viItem != _vItem.end(); _viItem++)
	{
		if (_viItem->itemKind != itemNum) continue;

		cout << "=============����==============" << endl;
		cout << "�̸� : " << _viItem->name << endl;
		cout << "���� : " << _viItem->ability << endl;
		cout << "���� : " << _viItem->price << endl;
		cout << "���� : " << _viItem->description << endl;
	}
}
