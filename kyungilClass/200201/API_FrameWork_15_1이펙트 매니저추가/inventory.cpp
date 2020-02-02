#include "stdafx.h"
#include "inventory.h"

inventory::inventory()
{
}

inventory::~inventory()
{
}

HRESULT inventory::init()
{
	inventoryWindowImage = IMAGEMANAGER->addImage("inventoryBackGround", "images/inventoryBackGround.bmp", 216, 418, true, RGB(255, 0, 255));
	inventoryWindowRect = RectMakeCenter(WINSIZEX / 2 + 300, WINSIZEY / 2, inventoryWindowImage->getWidth(), inventoryWindowImage->getHeight());

	equipmentSlotOnImage = IMAGEMANAGER->addImage("shop_equipment_on", "images/shop_equipment_on.bmp", 42, 19, true, RGB(255, 0, 255));
	equipmentSlotOnRect = RectMakeCenter(inventoryWindowRect.left + 33, inventoryWindowRect.top + 47, equipmentSlotOnImage->getWidth(), equipmentSlotOnImage->getHeight());
	equipmentSlotOffImage = IMAGEMANAGER->addImage("shop_equipment_off", "images/shop_equipment_off.bmp", 42, 17, true, RGB(255, 0, 255));
	equipmentSlotOffRect = RectMakeCenter(inventoryWindowRect.left + 33, inventoryWindowRect.top + 47, equipmentSlotOffImage->getWidth(), equipmentSlotOffImage->getHeight());

	consumptionSlotOnImage = IMAGEMANAGER->addImage("shop_consumption_On", "images/shop_consumption_On.bmp", 42, 19, true, RGB(255, 0, 255));
	consumptionSlotOnRect = RectMakeCenter(inventoryWindowRect.left + 75, inventoryWindowRect.top + 47, consumptionSlotOnImage->getWidth(), consumptionSlotOnImage->getHeight());
	consumptionSlotOffImage = IMAGEMANAGER->addImage("shop_consumption_Off", "images/shop_consumption_Off.bmp", 42, 17, true, RGB(255, 0, 255));
	consumptionSlotOffRect = RectMakeCenter(inventoryWindowRect.left + 75, inventoryWindowRect.top + 47, consumptionSlotOffImage->getWidth(), consumptionSlotOffImage->getHeight());

	exitWindow = RectMakeCenter(inventoryWindowRect.left + 195, inventoryWindowRect.top + 15, 20, 20);

	for (int i = 0; i < 6; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			inventorySlotRect[i * 4 + j] = RectMake(inventoryWindowRect.left + 13 + j * 45, inventoryWindowRect.top + 63 + i * 45, 39, 39);
		}
	}

	vPotion = ITEMMANAGER->getPotionInfo();

	playerGold = 1000000000;

	inventoryOpen = false;
	selectEquip = true;
	return S_OK;
}

void inventory::release()
{
}

void inventory::update()
{
	if (!inventoryOpen)
	{
		if (KEYMANAGER->isOnceKeyDown('I'))
		{
			inventoryOpen = true;
		}
	}
	else
	{
		if (KEYMANAGER->isOnceKeyDown('I'))
		{
			inventoryOpen = false;
		}
		if (PtInRect(&exitWindow, m_ptMouse))
		{
			if (KEYMANAGER->isOnceKeyDown(VK_LBUTTON))
			{
				inventoryOpen = false;
			}
		}
		
		for (int i = 0; i < 24; i++)
		{
			if (PtInRect(&inventorySlotRect[i], m_ptMouse))
			{
				if (KEYMANAGER->isOnceKeyDown(VK_RBUTTON))
				{
					for (int j = 0; j < vEquip.size(); j++)
					{
						if (vEquip[j].itemkind == ITEM_WEAPON)
						{
							EQUIPMENT->setWeapon(vEquip[j]);
							vEquip.erase(vEquip.begin() + j);
						}
						else if (vEquip[j].itemkind == ITEM_CAP)
						{

						}
						else if (vEquip[j].itemkind == ITEM_TOP)
						{

						}
						else if (vEquip[j].itemkind == ITEM_BOTTOM)
						{

						}
						else if (vEquip[j].itemkind == ITEM_GLOVES)
						{

						}
						else if (vEquip[j].itemkind == ITEM_SHOES)
						{

						}
					}
				}
			}
		}
	
	}

	if (PtInRect(&consumptionSlotOnRect, m_ptMouse))
	{
		if (KEYMANAGER->isOnceKeyDown(VK_LBUTTON))
		{
			selectEquip = false;
			selectConsumption = true;
		}
	}
	if (PtInRect(&equipmentSlotOnRect, m_ptMouse))
	{
		if (KEYMANAGER->isOnceKeyDown(VK_LBUTTON))
		{
			selectEquip = true;
			selectConsumption = false;
		}
	}
}

void inventory::render()
{
	if (inventoryOpen)
	{	
		if (KEYMANAGER->isToggleKey(VK_TAB))
		{
			Rectangle(getMemDC(), inventoryWindowRect.left, inventoryWindowRect.top, inventoryWindowRect.right, inventoryWindowRect.bottom);
			for (int i = 0; i < 6; i++)
			{
				for (int j = 0; j < 4; j++)
				{
					Rectangle(getMemDC(), inventorySlotRect[i * 4 + j].left, inventorySlotRect[i * 4 + j].top, inventorySlotRect[i * 4 + j].right, inventorySlotRect[i * 4 + j].bottom);
				}
			}
		}
		inventoryWindowImage->render(getMemDC(), inventoryWindowRect.left, inventoryWindowRect.top);

		sprintf_s(str, "%d", playerGold);
		TextOut(getMemDC(), inventoryWindowRect.left + 65, inventoryWindowRect.top + 335, str, strlen(str));


		if (selectEquip)
		{
			equipmentSlotOnImage->render(getMemDC(), equipmentSlotOnRect.left, equipmentSlotOnRect.top);
			consumptionSlotOffImage->render(getMemDC(), consumptionSlotOffRect.left, consumptionSlotOffRect.top);

			for (int i = 0; i < vEquip.size(); i++)
			{
				vEquip[i].itemImage->render(getMemDC(), inventorySlotRect[i].left + 3, inventorySlotRect[i].top + 5);
			}
			for (int i = 0; i < vEquip.size(); i++)
			{
				if (PtInRect(&inventorySlotRect[i], m_ptMouse))
				{
					vEquip[i].itemInfoImage->render(getMemDC(), m_ptMouse.x, m_ptMouse.y);
				}
			}
		}
		else if (selectConsumption)
		{
			consumptionSlotOnImage->render(getMemDC(), consumptionSlotOnRect.left, consumptionSlotOnRect.top);
			equipmentSlotOffImage->render(getMemDC(), equipmentSlotOffRect.left, equipmentSlotOffRect.top);

			for (int i = 0; i < vPotion.size(); i++)
			{
				vPotion[i].itemImage->render(getMemDC(), inventorySlotRect[i].left + 3, inventorySlotRect[i].top + 5);
			}
			for (int i = 0; i < vPotion.size(); i++)
			{
				if (PtInRect(&inventorySlotRect[i], m_ptMouse))
				{
					vPotion[i].itemInfoImage->render(getMemDC(), m_ptMouse.x, m_ptMouse.y);
				}
			}
		}
	}
}

void inventory::getEquip(tagItemInfo item)
{
	vEquip.push_back(item);
}

void inventory::getPotion(tagItemInfo item)
{
	vPotion.push_back(item);
}
