#include "inventory.h"

inventory::inventory()
{
	tagItemInfo itemEmpty = {ITME_EMPTY, "", "", 0, 0, 0};
	m_equipArmor = itemEmpty;
	m_equipWeapon = itemEmpty;

}


inventory::~inventory()
{
}

int inventory::showInventory()
{
	int itemCount = 0;

	m_viItem = m_vItem.begin();

	for (m_viItem; m_viItem != m_vItem.end(); m_viItem++)
	{
		cout << "==================================" << endl;
		cout << "������ ��ȣ : " << ++itemCount << endl;
		cout << "�̸� : " << m_viItem->itemName << endl;
		cout << "���� : " << m_viItem->price << endl;
		cout << "�ɷ�ġ : " << m_viItem->attribute << endl;
		cout << "���� : " << m_viItem->description << endl;
		cout << "==================================" << endl;
	}
	return itemCount;
}

void inventory::addItem(tagItemInfo item)
{
	if (item.itemKind != ITME_EMPTY)
	{
		m_vItem.push_back(item);
	}
}

tagItemInfo inventory::sellItem(int num, int & gold)
{
	tagItemInfo sellItem;
	
	m_viItem = m_vItem.begin() + (num - 1);
	sellItem = *m_viItem;
	m_vItem.erase(m_viItem);
	
	// ������ �Ǹ� gold���
	int sellPrice = sellItem.price * 0.5;

	cout << sellItem.itemName << "�� " << sellPrice << "gold�� �Ǹ��Ͽ����ϴ�." << endl;
	gold += sellPrice;

	return sellItem;
}

void inventory::equipItem(int num)
{
	tagItemInfo beforItem;

	m_viItem = m_vItem.begin() + (num - 1);

	switch (m_viItem->itemKind)
	{
	case ITEM_ARMOR:
		beforItem = getEquipArmor();
		setEquipArmor(*m_viItem);
		m_vItem.erase(m_viItem);
		if (beforItem.itemKind == ITEM_ARMOR)
		{
			m_vItem.push_back(beforItem);
		}
		break;

	case ITEM_WEAPON:
		beforItem = getEquipWeapon();
		setEquipWeapon(*m_viItem);
		m_vItem.erase(m_viItem);
		if (beforItem.itemKind == ITEM_WEAPON)
		{
			m_vItem.push_back(beforItem);
		}
		break;
		
		break;
	}
}
