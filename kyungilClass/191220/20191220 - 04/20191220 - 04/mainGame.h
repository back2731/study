#pragma once
#include "shop.h"
#include "inventory.h"
#include <iostream>

using namespace std;

enum LOCATION
{
	LOCATION_SHOP = 1,
	LOCATION_INVEN
};

class mainGame
{
	shop* _shop;
	inventory* _inven;
	LOCATION _location;

	int money;
	int _selectNum;


public:
	mainGame();
	~mainGame();
	
	void setLocation(int number);
	void setMainpage();
	void setshoppage();
	void setInvenpage();

};

