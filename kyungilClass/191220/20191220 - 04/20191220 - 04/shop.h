#pragma once
#include <iostream>
#include <vector>
#include <string>

using namespace std;

enum ITEM
{
	ITEM_WEAPON = 1,
	ITEM_ARMOR,
	ITEM_ACCERSORY,
	ITEM_POTION,
	ITEM_END
};

struct tagItemInfo
{
	ITEM itemKind;
	string name;
	string description;
	int ability;
	int price;
};

class shop
{
private:
	vector <tagItemInfo> _vItem;
	vector <tagItemInfo>::iterator _viItem;
	
public:
	shop();
	~shop();

	void itemSetup();
	void itemOutput(int itemNum);
};

