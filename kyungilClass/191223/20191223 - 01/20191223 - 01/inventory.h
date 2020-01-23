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

	// �κ��丮 �����ִ� �Լ�
	int showInventory();
	// ������ �߰� �Լ�
	void addItem(tagItemInfo item);
	// ������ �Ǹ� �Լ�
	tagItemInfo sellItem(int num, int &gold);
	// ������ ���� �Լ�
	void equipItem(int num);

	tagItemInfo getEquipArmor() { return m_equipArmor; }
	void setEquipArmor(tagItemInfo equipArmor) { m_equipArmor = equipArmor; }

	tagItemInfo getEquipWeapon() { return m_equipWeapon; };
	void setEquipWeapon(tagItemInfo equipWeapon) { m_equipWeapon = equipWeapon; };

};

