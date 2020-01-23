#pragma once
#include "item.h"

class inventory
{
private:

protected:

	vector <tagItemInfo> m_vItem;
	vector <tagItemInfo>::iterator m_viItem;

	tagItemInfo m_equipArmor;
	tagItemInfo m_equipWeapon;


public:
	inventory();
	~inventory();

	// 인벤토리 보여주는 함수
	int showInventory();
	// 아이템 추가 함수
	void addItem(tagItemInfo item);
	// 아이템 판매 함수
	tagItemInfo sellItem(int num, int &gold);
	// 아이템 장착 함수
	void equipItem(int num);

	tagItemInfo getEquipArmor() { return m_equipArmor; }
	void setEquipArmor(tagItemInfo equipArmor) { m_equipArmor = equipArmor; }

	tagItemInfo getEquipWeapon() { return m_equipWeapon; };
	void setEquipWeapon(tagItemInfo equipWeapon) { m_equipWeapon = equipWeapon; };

};

