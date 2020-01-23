#include "mainGame.h"

mainGame::mainGame()
{
	m_shop = new shop;
	m_shop->itemSetup();

	m_player = new Player;	

	m_gold = 10000;
	m_selectNum = 0;

	setMainPage();

}

mainGame::~mainGame()
{
	delete m_shop;
	delete m_player;
}

void mainGame::setMainPage()
{
	system("cls");
	cout << "==================위치==================" << endl;
	cout << "1. 상점 2. 인벤토리[판매] 3. 인벤토리[장착]" << endl;
	cin >> m_selectNum;
	setLocation(m_selectNum);	
}

void mainGame::setLocation(int number)
{
	/*
	LOCATION_SHOP = 1,
	LOCATION_SELL_INVENTORY,
	LOCATION_INVENTORY,
	*/

	switch (number)
	{
	case LOCATION_SHOP:
		setShopPage();
		break;
	case LOCATION_SELL_INVENTORY:
		setSellInventoryPage();
		break;
	case LOCATION_INVENTORY:
		setInventoryPage();
		break;
	default:
		setMainPage();
		break;
	}
}

void mainGame::setShopPage()
{
	while (true)
	{
		system("cls");
		cout << "======================상점======================" << endl;
		cout << "1. 방어구 2. 무기 3. 악세서리 4. 포션 " << endl;
		cout << "==========메인화면으로 나가길 원하면 0번==========" << endl;
		cin >> m_selectNum;

		if (m_selectNum == 0)
		{
			setMainPage();
			break;
		}
		else
		{
			setShopItemPage(m_selectNum);
		}
	}
}

void mainGame::setShopItemPage(int itemKind)
{
	int itemCount = 0;
	while (true)
	{
		system("cls");
		itemCount = m_shop->itemOutput(itemKind);

		cout << "현재 gold : " << m_gold << endl;
		cout << "구매 할 아이템의 번호를 입력하세요." << endl;
		cout << "itemCount : " << itemCount << endl;
		cout << "==========상점 메뉴로로 나가길 원하면 0번==========" << endl;
		cin >> m_selectNum;

		if (m_selectNum == 0)
		{
			break;
		}
		else if ((m_selectNum < 0) || (m_selectNum > itemCount))
		{
			cout << "잘못된 입력입니다." << endl;
		}
		else
		{
			m_player->addItem(m_shop->buyItem(itemKind, m_selectNum, m_gold));
			Sleep(1000);
		}
	}
}

void mainGame::setSellInventoryPage()
{
	int itemCount = 0;

	while (true)
	{
		system("cls");
		cout << "=====================인벤토리=====================" << endl;
		cout << "현재 gold : " << m_gold << endl;
		cout << "판매할 아이템의 번호를 입력하세요." << endl;
		cout << "===========메인화면으로 나가길 원하면 0번===========" << endl;
		
		itemCount = m_player->showInventory();
		cin >> m_selectNum;
		if (m_selectNum == 0)
		{
			setMainPage();
			break;
		}
		else if ((m_selectNum < 0) || (m_selectNum > itemCount))
		{
			cout << "잘못된 입력입니다." << endl;
		}
		else
		{
			m_shop->addItem(m_player->sellItem(m_selectNum, m_gold));
			Sleep(1000);
		}
	}
}

void mainGame::setInventoryPage()
{
	int itemCount = 0;
	while (true)
	{
		system("cls");
		m_player->showStatus();
		cout << "=====================인벤토리=====================" << endl;
		cout << "장착할 아이템의 번호를 입력하세요." << endl;
		cout << "===========메인화면으로 나가길 원하면 0번===========" << endl;

		itemCount = m_player->showInventory();
		cin >> m_selectNum;
		if (m_selectNum == 0)
		{
			setMainPage();
			break;
		}
		else if ((m_selectNum < 0) || (m_selectNum > itemCount))
		{
			cout << "잘못된 입력입니다." << endl;
		}
		else
		{
			m_player->equipItem(m_selectNum);
			Sleep(1000);
		}
	}
}
