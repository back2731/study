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
	ITEM itemKind;		// 아이템 종류
	string itemName;	// 아이템 이름
	string description;	// 아이템 설명
	int attribute;		// 아이템 특성
	int price;			// 아이템 가격
	int count;			// 아이템 갯수
};