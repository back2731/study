#include "mainGame.h"

mainGame::mainGame()
{
	_shop = new shop;
	_shop->itemSetup();

	_inven = new inventory;
	money = 10000;

}


mainGame::~mainGame()
{
	delete _shop;
	delete _inven;
}

void mainGame::setLocation(int number)
{
	switch (number)
	{
	case LOCATION_SHOP:
		setshoppage();
		break;
	case LOCATION_INVEN:
		setInvenpage();
		break;
	default:
		break;
	}
}

void mainGame::setMainpage()
{
	cout << "=============================" << endl;
	cout << "1. 상점    2. 인벤토리" << endl;
	cout << "=============================" << endl;
	cin >> _selectNum;
	system("cls");
	setLocation(_selectNum);
}

void mainGame::setshoppage()
{
	while (true)
	{
		cout << "=============================" << endl;
		cout << "1. 무기 2. 방어구 3. 악세서리 4. 포션" << endl;

		cin >> _selectNum;

		_shop->itemOutput(_selectNum);

		cout << "다른 상품을 보고 싶으면 아무거나 누르세요" << endl;
		cin >> _selectNum;

	}
}

void mainGame::setInvenpage()
{
}
