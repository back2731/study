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
	cout << "1. ����    2. �κ��丮" << endl;
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
		cout << "1. ���� 2. �� 3. �Ǽ����� 4. ����" << endl;

		cin >> _selectNum;

		_shop->itemOutput(_selectNum);

		cout << "�ٸ� ��ǰ�� ���� ������ �ƹ��ų� ��������" << endl;
		cin >> _selectNum;

	}
}

void mainGame::setInvenpage()
{
}
