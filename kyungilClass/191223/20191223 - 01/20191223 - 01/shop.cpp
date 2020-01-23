#include "shop.h"
shop::shop()
{
}

shop::~shop()
{
}

void shop::itemSetup()
{
	// 방어구
	tagItemInfo armor1;
	armor1.itemKind = ITEM_ARMOR;
	armor1.itemName = "가죽 바지";
	armor1.price = 50;
	armor1.attribute = 1;
	armor1.description = "가죽으로 만든 바지";
	armor1.count = 1;
	m_vItem.push_back(armor1);

	tagItemInfo armor2;
	armor2.itemKind = ITEM_ARMOR;
	armor2.itemName = "쇠 바지";
	armor2.price = 150;
	armor2.attribute = 5;
	armor2.description = "쇠로 만든 바지";
	armor2.count = 1;
	m_vItem.push_back(armor2);

	// 무기
	tagItemInfo weapon1;
	weapon1.itemKind = ITEM_WEAPON;
	weapon1.itemName = "한 손검";
	weapon1.price = 100;
	weapon1.attribute = 3;
	weapon1.description = "다루기 쉬운 검";
	weapon1.count = 1;
	m_vItem.push_back(weapon1);

	tagItemInfo weapon2;
	weapon2.itemKind = ITEM_WEAPON;
	weapon2.itemName = "광선검";
	weapon2.price = 200;
	weapon2.attribute = 15;
	weapon2.description = "스타워즈에 나오는 그 검";
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
			cout << "아이템 번호 : " << ++itemCount << endl;
			cout << "이름 : " << m_viItem->itemName << endl;
			cout << "가격 : "<< m_viItem->price << endl;
			cout << "능력치 : " << m_viItem->attribute << endl;
			cout << "설명 : " << m_viItem->description << endl;
			cout << "개수 : ";
			(m_viItem->count > 0) ? cout << m_viItem->count << endl : cout << "매진" << endl;
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
					cout << m_viItem->itemName << "을 " << m_viItem->price << "gold에 구매하였습니다." << endl;
					gold -= m_viItem->price;
					m_viItem->count--;
					buyItem = *m_viItem; // m_viTem 의 현재 보여주고 있는 아이템을 buyItem에 넣는다.
				}
				else
				{
					cout << "다 팔렸습니다." << endl;
				}
			}
			else
			{
				cout << "gold가 부족합니다." << endl;
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
	// 상점에 없는 아이템이면 벡터에 새로 넣어준다.
	if (isNewItem = true)
	{
		m_vItem.push_back(item);
	}
}
