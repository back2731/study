#pragma once
#include <iostream>
#include <string>
#include <vector>

using namespace std;

enum ITEM
{
	ITME_EMPTY,
	ITEM_ARMOR,
	ITEM_WEAPON,
	ITEM_RING,
	ITEM_POSTION,
	ITEM_SOLDOUT
};

struct tagItemInfo
{
	ITEM itemKind;		// ������ ����
	string itemName;	// ������ �̸�
	string description;	// ������ ����
	int attribute;		// ������ Ư��
	int price;			// ������ ����
	int count;			// ������ ����
};