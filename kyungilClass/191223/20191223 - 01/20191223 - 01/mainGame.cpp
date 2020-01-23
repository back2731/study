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
	cout << "==================��ġ==================" << endl;
	cout << "1. ���� 2. �κ��丮[�Ǹ�] 3. �κ��丮[����]" << endl;
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
		cout << "======================����======================" << endl;
		cout << "1. �� 2. ���� 3. �Ǽ����� 4. ���� " << endl;
		cout << "==========����ȭ������ ������ ���ϸ� 0��==========" << endl;
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

		cout << "���� gold : " << m_gold << endl;
		cout << "���� �� �������� ��ȣ�� �Է��ϼ���." << endl;
		cout << "itemCount : " << itemCount << endl;
		cout << "==========���� �޴��η� ������ ���ϸ� 0��==========" << endl;
		cin >> m_selectNum;

		if (m_selectNum == 0)
		{
			break;
		}
		else if ((m_selectNum < 0) || (m_selectNum > itemCount))
		{
			cout << "�߸��� �Է��Դϴ�." << endl;
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
		cout << "=====================�κ��丮=====================" << endl;
		cout << "���� gold : " << m_gold << endl;
		cout << "�Ǹ��� �������� ��ȣ�� �Է��ϼ���." << endl;
		cout << "===========����ȭ������ ������ ���ϸ� 0��===========" << endl;
		
		itemCount = m_player->showInventory();
		cin >> m_selectNum;
		if (m_selectNum == 0)
		{
			setMainPage();
			break;
		}
		else if ((m_selectNum < 0) || (m_selectNum > itemCount))
		{
			cout << "�߸��� �Է��Դϴ�." << endl;
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
		cout << "=====================�κ��丮=====================" << endl;
		cout << "������ �������� ��ȣ�� �Է��ϼ���." << endl;
		cout << "===========����ȭ������ ������ ���ϸ� 0��===========" << endl;

		itemCount = m_player->showInventory();
		cin >> m_selectNum;
		if (m_selectNum == 0)
		{
			setMainPage();
			break;
		}
		else if ((m_selectNum < 0) || (m_selectNum > itemCount))
		{
			cout << "�߸��� �Է��Դϴ�." << endl;
		}
		else
		{
			m_player->equipItem(m_selectNum);
			Sleep(1000);
		}
	}
}
