#include "shop.h"
shop::shop()
{
}

shop::~shop()
{
}

void shop::itemSetup()
{
	// ��
	tagItemInfo armor1;
	armor1.itemKind = ITEM_ARMOR;
	armor1.itemName = "���� ����";
	armor1.price = 50;
	armor1.attribute = 1;
	armor1.description = "�������� ���� ����";
	armor1.count = 1;
	m_vItem.push_back(armor1);

	tagItemInfo armor2;
	armor2.itemKind = ITEM_ARMOR;
	armor2.itemName = "�� ����";
	armor2.price = 150;
	armor2.attribute = 5;
	armor2.description = "��� ���� ����";
	armor2.count = 1;
	m_vItem.push_back(armor2);

	// ����
	tagItemInfo weapon1;
	weapon1.itemKind = ITEM_WEAPON;
	weapon1.itemName = "�� �հ�";
	weapon1.price = 100;
	weapon1.attribute = 3;
	weapon1.description = "�ٷ�� ���� ��";
	weapon1.count = 1;
	m_vItem.push_back(weapon1);

	tagItemInfo weapon2;
	weapon2.itemKind = ITEM_WEAPON;
	weapon2.itemName = "������";
	weapon2.price = 200;
	weapon2.attribute = 15;
	weapon2.description = "��Ÿ��� ������ �� ��";
	weapon2.count = 3;
	m_vItem.push_back(weapon2);
}

int shop::itemOutput(int num)
{
	int itemCount = 0;

	m_viItem = m_vItem.begin();

	for (m_viItem; m_viItem != m_vItem.end(); ++m_viItem)
	{
		if (m_viItem->itemKind != num) continue;
		{
			cout << "=================================" << endl;
			cout << "������ ��ȣ : " << ++itemCount << endl;
			cout << "�̸� : " << m_viItem->itemName << endl;
			cout << "���� : "<< m_viItem->price << endl;
			cout << "�ɷ�ġ : " << m_viItem->attribute << endl;
			cout << "���� : " << m_viItem->description << endl;
			cout << "���� : ";
			(m_viItem->count > 0) ? cout << m_viItem->count << endl : cout << "����" << endl;
			cout << "=================================" << endl;
		}
	}

	return itemCount;
}

tagItemInfo shop::buyItem(int itemKind, int num, int & gold)
{
	tagItemInfo buyItem;
	buyItem.itemKind = ITME_EMPTY;
	int itemCount = 0;
	m_viItem = m_vItem.begin();

	for (m_viItem; m_viItem != m_vItem.end(); ++m_viItem)
	{
		if (m_viItem->itemKind != itemKind) continue;
		{

		}
		if (++itemCount == num)
		{
			if (gold >= m_viItem->price)
			{
				if (m_viItem->count > 0)
				{
					cout << m_viItem->itemName << "�� " << m_viItem->price << "gold�� �����Ͽ����ϴ�." << endl;
					gold -= m_viItem->price;
					m_viItem->count--;
					buyItem = *m_viItem; // m_viTem �� ���� �����ְ� �ִ� �������� buyItem�� �ִ´�.
				}
				else
				{
					cout << "�� �ȷȽ��ϴ�." << endl;
				}
			}
			else
			{
				cout << "gold�� �����մϴ�." << endl;
			}
			break;
		}
	}

	return buyItem;
}

void shop::addItem(tagItemInfo item)
{
	bool isNewItem = true;
	m_viItem = m_vItem.begin();

	for (m_viItem; m_viItem != m_vItem.end(); ++m_viItem)
	{
		if (m_viItem->itemKind != item.itemKind) continue;
		
		if (m_viItem->itemName.compare(item.itemName) == 0)
		{
			m_viItem->count++;
			isNewItem = false;
			break;
		}
	}
	// ������ ���� �������̸� ���Ϳ� ���� �־��ش�.
	if (isNewItem = true)
	{
		m_vItem.push_back(item);
	}
}
