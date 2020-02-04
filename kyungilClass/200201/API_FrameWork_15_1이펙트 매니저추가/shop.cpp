#include "stdafx.h"
#include "shop.h"

shop::shop()
{
}

shop::~shop()
{
}

HRESULT shop::init()
{
	npcImage = IMAGEMANAGER->addFrameImage("NPC", "images/shopNpc.bmp", 1000, 125, 8, 1, true, RGB(255, 0, 255));
	npcRect = RectMakeCenter(800, 580, npcImage->getFrameWidth(), npcImage->getFrameHeight());
	
	shopImage = IMAGEMANAGER->addImage("shopBackGround", "images/shopBackGround.bmp", 509, 505, true, RGB(255, 0, 255));
	shopRect = RectMakeCenter(WINSIZEX / 2, WINSIZEY / 2, shopImage->getWidth(), shopImage->getHeight());

	shopExitImage = IMAGEMANAGER->addImage("shopExit", "images/shopExit.bmp", 64, 16, true, RGB(255, 0, 255));
	shopExitRect = RectMakeCenter(490, 190, shopExitImage->getWidth(), shopExitImage->getHeight());

	buyItemImage = IMAGEMANAGER->addImage("buyItem", "images/buyItem.bmp", 64, 16, true, RGB(255, 0, 255));
	buyItemRect = RectMakeCenter(490, 210, buyItemImage->getWidth(), buyItemImage->getHeight());

	equipmentSlotOnImage = IMAGEMANAGER->addImage("shop_equipment_on", "images/shop_equipment_on.bmp", 42, 19, true, RGB(255, 0, 255));
	equipmentSlotOnRect = RectMakeCenter(290, 240, equipmentSlotOnImage->getWidth(), equipmentSlotOnImage->getHeight());
	equipmentSlotOffImage = IMAGEMANAGER->addImage("shop_equipment_off", "images/shop_equipment_off.bmp", 42, 17, true, RGB(255, 0, 255));
	equipmentSlotOffRect = RectMakeCenter(290, 240, equipmentSlotOffImage->getWidth(), equipmentSlotOffImage->getHeight());

	consumptionSlotOnImage = IMAGEMANAGER->addImage("shop_consumption_On", "images/shop_consumption_On.bmp", 42, 19, true, RGB(255, 0, 255));
	consumptionSlotOnRect = RectMakeCenter(332, 240, consumptionSlotOnImage->getWidth(), consumptionSlotOnImage->getHeight());
	consumptionSlotOffImage = IMAGEMANAGER->addImage("shop_consumption_Off", "images/shop_consumption_Off.bmp", 42, 17, true, RGB(255, 0, 255));
	consumptionSlotOffRect = RectMakeCenter(332, 240, consumptionSlotOffImage->getWidth(), consumptionSlotOffImage->getHeight());

	buyOffImage1 = IMAGEMANAGER->addImage("buyOff", "images/buyOff.bmp", 245, 39, true, RGB(255, 0, 255));
	buyOffRect1 = RectMake(270, 260, buyOffImage1->getWidth(), buyOffImage1->getHeight());
	buyOnImage1 = IMAGEMANAGER->addImage("buyOn", "images/buyOn.bmp", 245, 39, true, RGB(255, 0, 255));
	buyOnRect1 = RectMake(270, 260, buyOnImage1->getWidth(), buyOnImage1->getHeight());

	buyOffImage2 = IMAGEMANAGER->addImage("buyOff", "images/buyOff.bmp", 245, 39, true, RGB(255, 0, 255));
	buyOffRect2 = RectMake(270, 305, buyOffImage2->getWidth(), buyOffImage2->getHeight());
	buyOnImage2 = IMAGEMANAGER->addImage("buyOn", "images/buyOn.bmp", 245, 39, true, RGB(255, 0, 255));
	buyOnRect2 = RectMake(270, 305, buyOnImage2->getWidth(), buyOnImage2->getHeight());

	buyOffImage3 = IMAGEMANAGER->addImage("buyOff", "images/buyOff.bmp", 245, 39, true, RGB(255, 0, 255));
	buyOffRect3 = RectMake(270, 350, buyOffImage3->getWidth(), buyOffImage3->getHeight());
	buyOnImage3 = IMAGEMANAGER->addImage("buyOn", "images/buyOn.bmp", 245, 39, true, RGB(255, 0, 255));
	buyOnRect3 = RectMake(270, 350, buyOnImage3->getWidth(), buyOnImage3->getHeight());

	buyOffImage4 = IMAGEMANAGER->addImage("buyOff", "images/buyOff.bmp", 245, 39, true, RGB(255, 0, 255));
	buyOffRect4 = RectMake(270, 395, buyOffImage4->getWidth(), buyOffImage4->getHeight());
	buyOnImage4 = IMAGEMANAGER->addImage("buyOn", "images/buyOn.bmp", 245, 39, true, RGB(255, 0, 255));
	buyOnRect4 = RectMake(270, 395, buyOnImage4->getWidth(), buyOnImage4->getHeight());

	buyOffImage5 = IMAGEMANAGER->addImage("buyOff", "images/buyOff.bmp", 245, 39, true, RGB(255, 0, 255));
	buyOffRect5 = RectMake(270, 440, buyOffImage5->getWidth(), buyOffImage5->getHeight());
	buyOnImage5 = IMAGEMANAGER->addImage("buyOn", "images/buyOn.bmp", 245, 39, true, RGB(255, 0, 255));
	buyOnRect5 = RectMake(270, 440, buyOnImage5->getWidth(), buyOnImage5->getHeight());

	buyOffImage6 = IMAGEMANAGER->addImage("buyOff", "images/buyOff.bmp", 245, 39, true, RGB(255, 0, 255));
	buyOffRect6 = RectMake(270, 485, buyOffImage6->getWidth(), buyOffImage6->getHeight());
	buyOnImage6 = IMAGEMANAGER->addImage("buyOn", "images/buyOn.bmp", 245, 39, true, RGB(255, 0, 255));
	buyOnRect6 = RectMake(270, 485, buyOnImage6->getWidth(), buyOnImage6->getHeight());

	buyOffImage7 = IMAGEMANAGER->addImage("buyOff", "images/buyOff.bmp", 245, 39, true, RGB(255, 0, 255));
	buyOffRect7 = RectMake(270, 530, buyOffImage7->getWidth(), buyOffImage7->getHeight());
	buyOnImage7 = IMAGEMANAGER->addImage("buyOn", "images/buyOn.bmp", 245, 39, true, RGB(255, 0, 255));
	buyOnRect7 = RectMake(270, 530, buyOnImage7->getWidth(), buyOnImage7->getHeight());

	buyOffImage8 = IMAGEMANAGER->addImage("buyOff", "images/buyOff.bmp", 245, 39, true, RGB(255, 0, 255));
	buyOffRect8 = RectMake(270, 575, buyOffImage8->getWidth(), buyOffImage8->getHeight());
	buyOnImage8 = IMAGEMANAGER->addImage("buyOn", "images/buyOn.bmp", 245, 39, true, RGB(255, 0, 255));
	buyOnRect8 = RectMake(270, 575, buyOnImage8->getWidth(), buyOnImage8->getHeight());

	//毒古遂

	sellEquipmentSlotOnImage = IMAGEMANAGER->addImage("shop_equipment_on", "images/shop_equipment_on.bmp", 42, 19, true, RGB(255, 0, 255));
	sellEquipmentSlotOnRect = RectMakeCenter(565, 240, sellEquipmentSlotOnImage->getWidth(), sellEquipmentSlotOnImage->getHeight());
	sellEquipmentSlotOffImage = IMAGEMANAGER->addImage("shop_equipment_off", "images/shop_equipment_off.bmp", 42, 17, true, RGB(255, 0, 255));
	sellEquipmentSlotOffRect = RectMakeCenter(565, 240, sellEquipmentSlotOffImage->getWidth(), sellEquipmentSlotOffImage->getHeight());

	sellConsumptionSlotOnImage = IMAGEMANAGER->addImage("shop_consumption_On", "images/shop_consumption_On.bmp", 42, 19, true, RGB(255, 0, 255));
	sellConsumptionSlotOnRect = RectMakeCenter(610, 240, sellConsumptionSlotOnImage->getWidth(), sellConsumptionSlotOnImage->getHeight());
	sellConsumptionSlotOffImage = IMAGEMANAGER->addImage("shop_consumption_Off", "images/shop_consumption_Off.bmp", 42, 17, true, RGB(255, 0, 255));
	sellConsumptionSlotOffRect = RectMakeCenter(610, 240, sellConsumptionSlotOnImage->getWidth(), sellConsumptionSlotOnImage->getHeight());

	sellItemImage = IMAGEMANAGER->addImage("sellItem", "images/sellItem.bmp", 64, 16, true, RGB(255, 0, 255));
	sellItemRect = RectMakeCenter(720, 210, sellItemImage->getWidth(), sellItemImage->getHeight());

	sellOffImage1 = IMAGEMANAGER->addImage("sellOff", "images/sellOff.bmp", 202, 39, true, RGB(255, 0, 255));
	sellOffRect1 = RectMake(543, 260, sellOffImage1->getWidth(), sellOffImage1->getHeight());
	sellOnImage1 = IMAGEMANAGER->addImage("sellOn", "images/sellOn.bmp", 202, 39, true, RGB(255, 0, 255));
	sellOnRect1 = RectMake(543, 260, sellOnImage1->getWidth(), sellOnImage1->getHeight());

	sellOffImage2 = IMAGEMANAGER->addImage("sellOff", "images/sellOff.bmp", 202, 39, true, RGB(255, 0, 255));
	sellOffRect2 = RectMake(543, 305, sellOffImage2->getWidth(), sellOffImage2->getHeight());
	sellOnImage2 = IMAGEMANAGER->addImage("sellOn", "images/sellOn.bmp", 202, 39, true, RGB(255, 0, 255));
	sellOnRect2 = RectMake(543, 305, sellOnImage2->getWidth(), sellOnImage2->getHeight());

	sellOffImage3 = IMAGEMANAGER->addImage("sellOff", "images/sellOff.bmp", 202, 39, true, RGB(255, 0, 255));
	sellOffRect3 = RectMake(543, 350, sellOffImage3->getWidth(), sellOffImage3->getHeight());
	sellOnImage3 = IMAGEMANAGER->addImage("sellOn", "images/sellOn.bmp", 202, 39, true, RGB(255, 0, 255));
	sellOnRect3 = RectMake(543, 350, sellOnImage3->getWidth(), sellOnImage3->getHeight());

	sellOffImage4 = IMAGEMANAGER->addImage("sellOff", "images/sellOff.bmp", 202, 39, true, RGB(255, 0, 255));
	sellOffRect4 = RectMake(543, 395, sellOffImage4->getWidth(), sellOffImage4->getHeight());
	sellOnImage4 = IMAGEMANAGER->addImage("sellOn", "images/sellOn.bmp", 202, 39, true, RGB(255, 0, 255));
	sellOnRect4 = RectMake(543, 395, sellOnImage4->getWidth(), sellOnImage4->getHeight());

	sellOffImage5 = IMAGEMANAGER->addImage("sellOff", "images/sellOff.bmp", 202, 39, true, RGB(255, 0, 255));
	sellOffRect5 = RectMake(543, 440, sellOffImage5->getWidth(), sellOffImage5->getHeight());
	sellOnImage5 = IMAGEMANAGER->addImage("sellOn", "images/sellOn.bmp", 202, 39, true, RGB(255, 0, 255));
	sellOnRect5 = RectMake(543, 440, sellOnImage5->getWidth(), sellOnImage5->getHeight());

	sellOffImage6 = IMAGEMANAGER->addImage("sellOff", "images/sellOff.bmp", 202, 39, true, RGB(255, 0, 255));
	sellOffRect6 = RectMake(543, 485, sellOffImage6->getWidth(), sellOffImage6->getHeight());
	sellOnImage6 = IMAGEMANAGER->addImage("sellOn", "images/sellOn.bmp", 202, 39, true, RGB(255, 0, 255));
	sellOnRect6 = RectMake(543, 485, sellOnImage6->getWidth(), sellOnImage6->getHeight());

	sellOffImage7 = IMAGEMANAGER->addImage("sellOff", "images/sellOff.bmp", 202, 39, true, RGB(255, 0, 255));
	sellOffRect7 = RectMake(543, 530, sellOffImage7->getWidth(), sellOffImage7->getHeight());
	sellOnImage7 = IMAGEMANAGER->addImage("sellOn", "images/sellOn.bmp", 202, 39, true, RGB(255, 0, 255));
	sellOnRect7 = RectMake(543, 530, sellOnImage7->getWidth(), sellOnImage7->getHeight());

	sellOffImage8 = IMAGEMANAGER->addImage("sellOff", "images/sellOff.bmp", 202, 39, true, RGB(255, 0, 255));
	sellOffRect8 = RectMake(543, 575, sellOffImage8->getWidth(), sellOffImage8->getHeight());
	sellOnImage8 = IMAGEMANAGER->addImage("sellOn", "images/sellOn.bmp", 202, 39, true, RGB(255, 0, 255));
	sellOnRect8 = RectMake(543, 575, sellOnImage8->getWidth(), sellOnImage8->getHeight());

	for (int i = 0; i < 8; i++)
	{
		itemSlot[i] = RectMake(270, 260 + i * 45, 35, 35);
	}

	for (int i = 0; i < 8; i++)
	{
		sellItemSlot[i] = RectMake(543, 260 + i * 45, 35, 35);
	}

	vEquip = ITEMMANAGER->getEquipInfo();
	vPotion = ITEMMANAGER->getPotionInfo();

	frameCount = 0;
	frameIndex = 0;

	buyNotChoice = true;
	sellNotChoice = true;
	shopOpen = false;
	selectEquip = true;
	sellSelectEquip = true;
	buyItem1 = true;
	return S_OK;
}

void shop::release()
{
}

void shop::update()
{
	if (PtInRect(&npcRect, m_ptMouse))
	{
		if (KEYMANAGER->isOnceKeyDown(VK_LBUTTON))
		{
			shopOpen = true;
		}
	}

	if (shopOpen)
	{
		if (PtInRect(&shopExitRect, m_ptMouse))
		{
			if (KEYMANAGER->isOnceKeyDown(VK_LBUTTON))
			{
				shopOpen = false;
				buyNotChoice = true;
				buyItem1 = false;
				buyItem2 = false;
				buyItem3 = false;
				buyItem4 = false;
				buyItem5 = false;
				buyItem6 = false;
				buyItem7 = false;
				buyItem8 = false;
			}
		}

		if (PtInRect(&equipmentSlotOnRect, m_ptMouse))
		{
			if (KEYMANAGER->isOnceKeyDown(VK_LBUTTON))
			{
				selectEquip = true;
				selectConsumption = false;
				buyNotChoice = true;
			}
		}
		if (PtInRect(&consumptionSlotOnRect, m_ptMouse))
		{
			if (KEYMANAGER->isOnceKeyDown(VK_LBUTTON))
			{
				selectEquip = false;
				selectConsumption = true;
				buyNotChoice = true;
			}
		}
		if (PtInRect(&buyItemRect, m_ptMouse))
		{
			if (KEYMANAGER->isOnceKeyDown(VK_LBUTTON))
			{
				buyItem();
			}
		}
		itemBuyChoice();

		if (PtInRect(&sellEquipmentSlotOnRect, m_ptMouse))
		{
			if (KEYMANAGER->isOnceKeyDown(VK_LBUTTON))
			{
				sellSelectEquip = true;
				sellSelectConsumption = false;
				sellNotChoice = true;
			}
		}
		if (PtInRect(&sellConsumptionSlotOnRect, m_ptMouse))
		{
			if (KEYMANAGER->isOnceKeyDown(VK_LBUTTON))
			{
				sellSelectEquip = false;
				sellSelectConsumption = true;
				sellNotChoice = true;
			}
		}
		if (PtInRect(&sellItemRect, m_ptMouse))
		{
			if (KEYMANAGER->isOnceKeyDown(VK_LBUTTON))
			{
				sellItem();
			}
		}
		itemSellChoice();
	}
}

void shop::render(HDC hdc)
{
	if (KEYMANAGER->isToggleKey(VK_TAB))
	{
		Rectangle(hdc, npcRect.left, npcRect.top, npcRect.right, npcRect.bottom);
		Rectangle(hdc, shopRect.left, shopRect.top, shopRect.right, shopRect.bottom);
		Rectangle(hdc, shopExitRect.left, shopExitRect.top, shopExitRect.right, shopExitRect.bottom);
		Rectangle(hdc, buyItemRect.left, buyItemRect.top, buyItemRect.right, buyItemRect.bottom);
		Rectangle(hdc, sellItemRect.left, sellItemRect.top, sellItemRect.right, sellItemRect.bottom);
		Rectangle(hdc, buyOffRect1.left, buyOffRect1.top, buyOffRect1.right, buyOffRect1.bottom);
		Rectangle(hdc, buyOffRect2.left, buyOffRect2.top, buyOffRect2.right, buyOffRect2.bottom);
		Rectangle(hdc, buyOffRect3.left, buyOffRect3.top, buyOffRect3.right, buyOffRect3.bottom);
		Rectangle(hdc, buyOffRect4.left, buyOffRect4.top, buyOffRect4.right, buyOffRect4.bottom);
		Rectangle(hdc, buyOffRect5.left, buyOffRect5.top, buyOffRect5.right, buyOffRect5.bottom);
		Rectangle(hdc, buyOffRect6.left, buyOffRect6.top, buyOffRect6.right, buyOffRect6.bottom);
		Rectangle(hdc, buyOffRect7.left, buyOffRect7.top, buyOffRect7.right, buyOffRect7.bottom);
		Rectangle(hdc, buyOffRect8.left, buyOffRect8.top, buyOffRect8.right, buyOffRect8.bottom);

		Rectangle(hdc, sellEquipmentSlotOnRect.left, sellEquipmentSlotOnRect.top, sellEquipmentSlotOnRect.right, sellEquipmentSlotOnRect.bottom);

		for (int i = 0; i < 8; i++)
		{
			Rectangle(hdc, itemSlot[i].left, itemSlot[i].top, itemSlot[i].right, itemSlot[i].bottom);
		}

		for (int i = 0; i < 8; i++)
		{
			Rectangle(hdc, sellItemSlot[i].left, sellItemSlot[i].top, sellItemSlot[i].right, sellItemSlot[i].bottom);
		}
	}

	npcImage->frameRender(hdc, npcRect.left, npcRect.top);
	npcRender();
	
	if (shopOpen)
	{
		shopImage->render(hdc, shopRect.left, shopRect.top);
		shopExitImage->render(hdc, shopExitRect.left, shopExitRect.top);
		buyItemImage->render(hdc, buyItemRect.left, buyItemRect.top);
		sellItemImage->render(hdc, sellItemRect.left, sellItemRect.top);

		if (buyNotChoice)
		{
			buyOffImage1->render(hdc, buyOffRect1.left, buyOffRect1.top);
			buyOffImage2->render(hdc, buyOffRect2.left, buyOffRect2.top);
			buyOffImage3->render(hdc, buyOffRect3.left, buyOffRect3.top);
			buyOffImage4->render(hdc, buyOffRect4.left, buyOffRect4.top);
			buyOffImage5->render(hdc, buyOffRect5.left, buyOffRect5.top);
			buyOffImage6->render(hdc, buyOffRect6.left, buyOffRect6.top);
			buyOffImage7->render(hdc, buyOffRect7.left, buyOffRect7.top);
			buyOffImage8->render(hdc, buyOffRect8.left, buyOffRect8.top);
		}
		else if(buyItem1)
		{
			buyOnImage1->render(hdc, buyOnRect1.left, buyOnRect1.top);
			buyOffImage2->render(hdc, buyOffRect2.left, buyOffRect2.top);
			buyOffImage3->render(hdc, buyOffRect3.left, buyOffRect3.top);
			buyOffImage4->render(hdc, buyOffRect4.left, buyOffRect4.top);
			buyOffImage5->render(hdc, buyOffRect5.left, buyOffRect5.top);
			buyOffImage6->render(hdc, buyOffRect6.left, buyOffRect6.top);
			buyOffImage7->render(hdc, buyOffRect7.left, buyOffRect7.top);
			buyOffImage8->render(hdc, buyOffRect8.left, buyOffRect8.top);
		}
		else if (buyItem2)
		{
			buyOffImage1->render(hdc, buyOffRect1.left, buyOffRect1.top);
			buyOnImage2->render(hdc, buyOnRect2.left, buyOnRect2.top);
			buyOffImage3->render(hdc, buyOffRect3.left, buyOffRect3.top);
			buyOffImage4->render(hdc, buyOffRect4.left, buyOffRect4.top);
			buyOffImage5->render(hdc, buyOffRect5.left, buyOffRect5.top);
			buyOffImage6->render(hdc, buyOffRect6.left, buyOffRect6.top);
			buyOffImage7->render(hdc, buyOffRect7.left, buyOffRect7.top);
			buyOffImage8->render(hdc, buyOffRect8.left, buyOffRect8.top);
		}
		else if (buyItem3)
		{
			buyOffImage1->render(hdc, buyOffRect1.left, buyOffRect1.top);
			buyOffImage2->render(hdc, buyOffRect2.left, buyOffRect2.top);
			buyOnImage3->render(hdc, buyOnRect3.left, buyOnRect3.top);
			buyOffImage4->render(hdc, buyOffRect4.left, buyOffRect4.top);
			buyOffImage5->render(hdc, buyOffRect5.left, buyOffRect5.top);
			buyOffImage6->render(hdc, buyOffRect6.left, buyOffRect6.top);
			buyOffImage7->render(hdc, buyOffRect7.left, buyOffRect7.top);
			buyOffImage8->render(hdc, buyOffRect8.left, buyOffRect8.top);
		}
		else if (buyItem4)
		{
			buyOffImage1->render(hdc, buyOffRect1.left, buyOffRect1.top);
			buyOffImage2->render(hdc, buyOffRect2.left, buyOffRect2.top);
			buyOffImage3->render(hdc, buyOffRect3.left, buyOffRect3.top);
			buyOnImage4->render(hdc, buyOnRect4.left, buyOnRect4.top);
			buyOffImage5->render(hdc, buyOffRect5.left, buyOffRect5.top);
			buyOffImage6->render(hdc, buyOffRect6.left, buyOffRect6.top);
			buyOffImage7->render(hdc, buyOffRect7.left, buyOffRect7.top);
			buyOffImage8->render(hdc, buyOffRect8.left, buyOffRect8.top);
		}
		else if (buyItem5)
		{
			buyOffImage1->render(hdc, buyOffRect1.left, buyOffRect1.top);
			buyOffImage2->render(hdc, buyOffRect2.left, buyOffRect2.top);
			buyOffImage3->render(hdc, buyOffRect3.left, buyOffRect3.top);
			buyOffImage4->render(hdc, buyOffRect4.left, buyOffRect4.top);
			buyOnImage5->render(hdc, buyOnRect5.left, buyOnRect5.top);
			buyOffImage6->render(hdc, buyOffRect6.left, buyOffRect6.top);
			buyOffImage7->render(hdc, buyOffRect7.left, buyOffRect7.top);
			buyOffImage8->render(hdc, buyOffRect8.left, buyOffRect8.top);
		}
		else if (buyItem6)
		{
			buyOffImage1->render(hdc, buyOffRect1.left, buyOffRect1.top);
			buyOffImage2->render(hdc, buyOffRect2.left, buyOffRect2.top);
			buyOffImage3->render(hdc, buyOffRect3.left, buyOffRect3.top);
			buyOffImage4->render(hdc, buyOffRect4.left, buyOffRect4.top);
			buyOffImage5->render(hdc, buyOffRect5.left, buyOffRect5.top);
			buyOnImage6->render(hdc, buyOnRect6.left, buyOnRect6.top);
			buyOffImage7->render(hdc, buyOffRect7.left, buyOffRect7.top);
			buyOffImage8->render(hdc, buyOffRect8.left, buyOffRect8.top);
		}
		else if (buyItem7)
		{
			buyOffImage1->render(hdc, buyOffRect1.left, buyOffRect1.top);
			buyOffImage2->render(hdc, buyOffRect2.left, buyOffRect2.top);
			buyOffImage3->render(hdc, buyOffRect3.left, buyOffRect3.top);
			buyOffImage4->render(hdc, buyOffRect4.left, buyOffRect4.top);
			buyOffImage5->render(hdc, buyOffRect5.left, buyOffRect5.top);
			buyOffImage6->render(hdc, buyOffRect6.left, buyOffRect6.top);
			buyOnImage7->render(hdc, buyOnRect7.left, buyOnRect7.top);
			buyOffImage8->render(hdc, buyOffRect8.left, buyOffRect8.top);
		}
		else if (buyItem8)
		{
			buyOffImage1->render(hdc, buyOffRect1.left, buyOffRect1.top);
			buyOffImage2->render(hdc, buyOffRect2.left, buyOffRect2.top);
			buyOffImage3->render(hdc, buyOffRect3.left, buyOffRect3.top);
			buyOffImage4->render(hdc, buyOffRect4.left, buyOffRect4.top);
			buyOffImage5->render(hdc, buyOffRect5.left, buyOffRect5.top);
			buyOffImage6->render(hdc, buyOffRect6.left, buyOffRect6.top);
			buyOffImage7->render(hdc, buyOffRect7.left, buyOffRect7.top);
			buyOnImage8->render(hdc, buyOnRect8.left, buyOnRect8.top);
		}

		if (selectEquip)
		{
			equipmentSlotOnImage->render(hdc, equipmentSlotOnRect.left, equipmentSlotOnRect.top);
			consumptionSlotOffImage->render(hdc, consumptionSlotOffRect.left, consumptionSlotOffRect.top);

			for (int i = 0; i < vEquip.size(); i++)
			{
				vEquip[i].itemImage->render(hdc, itemSlot[i].left, itemSlot[i].top);
			}
			for (int i = 0; i < vEquip.size(); i++)
			{
				sprintf_s(str, "%s", vEquip[i].name);
				TextOut(hdc, 310, 260 + i * 45, str, strlen(str));
				sprintf_s(str, "%d 五社", vEquip[i].price);
				TextOut(hdc, 310, 280 + i * 45, str, strlen(str));
			}
		}
		else if (selectConsumption)
		{
			consumptionSlotOnImage->render(hdc, consumptionSlotOnRect.left, consumptionSlotOnRect.top);
			equipmentSlotOffImage->render(hdc, equipmentSlotOffRect.left, equipmentSlotOffRect.top);

			for (int i = 0; i < vPotion.size(); i++)
			{
				vPotion[i].itemImage->render(hdc, itemSlot[i].left, itemSlot[i].top);
			}
			for (int i = 0; i < vPotion.size(); i++)
			{
				sprintf_s(str, "%s", vPotion[i].name);
				TextOut(hdc, 310, 260 + i * 45, str, strlen(str));
				sprintf_s(str, "%d 五社", vPotion[i].price);
				TextOut(hdc, 310, 280 + i * 45, str, strlen(str));
			}
		}

		if (sellNotChoice)
		{
			sellOffImage1->render(hdc, sellOffRect1.left, sellOffRect1.top);
			sellOffImage2->render(hdc, sellOffRect2.left, sellOffRect2.top);
			sellOffImage3->render(hdc, sellOffRect3.left, sellOffRect3.top);
			sellOffImage4->render(hdc, sellOffRect4.left, sellOffRect4.top);
			sellOffImage5->render(hdc, sellOffRect5.left, sellOffRect5.top);
			sellOffImage6->render(hdc, sellOffRect6.left, sellOffRect6.top);
			sellOffImage7->render(hdc, sellOffRect7.left, sellOffRect7.top);
			sellOffImage8->render(hdc, sellOffRect8.left, sellOffRect8.top);
		}
		else if (sellItem1)
		{
			sellOnImage1->render(hdc, sellOnRect1.left, sellOnRect1.top);
			sellOffImage2->render(hdc, sellOffRect2.left, sellOffRect2.top);
			sellOffImage3->render(hdc, sellOffRect3.left, sellOffRect3.top);
			sellOffImage4->render(hdc, sellOffRect4.left, sellOffRect4.top);
			sellOffImage5->render(hdc, sellOffRect5.left, sellOffRect5.top);
			sellOffImage6->render(hdc, sellOffRect6.left, sellOffRect6.top);
			sellOffImage7->render(hdc, sellOffRect7.left, sellOffRect7.top);
			sellOffImage8->render(hdc, sellOffRect8.left, sellOffRect8.top);
		}
		else if (sellItem2)
		{
			sellOffImage1->render(hdc, sellOffRect1.left, sellOffRect1.top);
			sellOnImage2->render(hdc, sellOnRect2.left, sellOnRect2.top);
			sellOffImage3->render(hdc, sellOffRect3.left, sellOffRect3.top);
			sellOffImage4->render(hdc, sellOffRect4.left, sellOffRect4.top);
			sellOffImage5->render(hdc, sellOffRect5.left, sellOffRect5.top);
			sellOffImage6->render(hdc, sellOffRect6.left, sellOffRect6.top);
			sellOffImage7->render(hdc, sellOffRect7.left, sellOffRect7.top);
			sellOffImage8->render(hdc, sellOffRect8.left, sellOffRect8.top);
		}
		else if (sellItem3)
		{
			sellOffImage1->render(hdc, sellOffRect1.left, sellOffRect1.top);
			sellOffImage2->render(hdc, sellOffRect2.left, sellOffRect2.top);
			sellOnImage3->render(hdc, sellOnRect3.left, sellOnRect3.top);
			sellOffImage4->render(hdc, sellOffRect4.left, sellOffRect4.top);
			sellOffImage5->render(hdc, sellOffRect5.left, sellOffRect5.top);
			sellOffImage6->render(hdc, sellOffRect6.left, sellOffRect6.top);
			sellOffImage7->render(hdc, sellOffRect7.left, sellOffRect7.top);
			sellOffImage8->render(hdc, sellOffRect8.left, sellOffRect8.top);
		}
		else if (sellItem4)
		{
			sellOffImage1->render(hdc, sellOffRect1.left, sellOffRect1.top);
			sellOffImage2->render(hdc, sellOffRect2.left, sellOffRect2.top);
			sellOffImage3->render(hdc, sellOffRect3.left, sellOffRect3.top);
			sellOnImage4->render(hdc, sellOnRect4.left, sellOnRect4.top);
			sellOffImage5->render(hdc, sellOffRect5.left, sellOffRect5.top);
			sellOffImage6->render(hdc, sellOffRect6.left, sellOffRect6.top);
			sellOffImage7->render(hdc, sellOffRect7.left, sellOffRect7.top);
			sellOffImage8->render(hdc, sellOffRect8.left, sellOffRect8.top);
		}
		else if (sellItem5)
		{
			sellOffImage1->render(hdc, sellOffRect1.left, sellOffRect1.top);
			sellOffImage2->render(hdc, sellOffRect2.left, sellOffRect2.top);
			sellOffImage3->render(hdc, sellOffRect3.left, sellOffRect3.top);
			sellOffImage4->render(hdc, sellOffRect4.left, sellOffRect4.top);
			sellOnImage5->render(hdc, sellOnRect5.left, sellOnRect5.top);
			sellOffImage6->render(hdc, sellOffRect6.left, sellOffRect6.top);
			sellOffImage7->render(hdc, sellOffRect7.left, sellOffRect7.top);
			sellOffImage8->render(hdc, sellOffRect8.left, sellOffRect8.top);
		}
		else if (sellItem6)
		{
			sellOffImage1->render(hdc, sellOffRect1.left, sellOffRect1.top);
			sellOffImage2->render(hdc, sellOffRect2.left, sellOffRect2.top);
			sellOffImage3->render(hdc, sellOffRect3.left, sellOffRect3.top);
			sellOffImage4->render(hdc, sellOffRect4.left, sellOffRect4.top);
			sellOffImage5->render(hdc, sellOffRect5.left, sellOffRect5.top);
			sellOnImage6->render(hdc, sellOnRect6.left, sellOnRect6.top);
			sellOffImage7->render(hdc, sellOffRect7.left, sellOffRect7.top);
			sellOffImage8->render(hdc, sellOffRect8.left, sellOffRect8.top);
		}
		else if (sellItem7)
		{
			sellOffImage1->render(hdc, sellOffRect1.left, sellOffRect1.top);
			sellOffImage2->render(hdc, sellOffRect2.left, sellOffRect2.top);
			sellOffImage3->render(hdc, sellOffRect3.left, sellOffRect3.top);
			sellOffImage4->render(hdc, sellOffRect4.left, sellOffRect4.top);
			sellOffImage5->render(hdc, sellOffRect5.left, sellOffRect5.top);
			sellOffImage6->render(hdc, sellOffRect6.left, sellOffRect6.top);
			sellOnImage7->render(hdc, sellOnRect7.left, sellOnRect7.top);
			sellOffImage8->render(hdc, sellOffRect8.left, sellOffRect8.top);
		}
		else if (sellItem8)
		{
			sellOffImage1->render(hdc, sellOffRect1.left, sellOffRect1.top);
			sellOffImage2->render(hdc, sellOffRect2.left, sellOffRect2.top);
			sellOffImage3->render(hdc, sellOffRect3.left, sellOffRect3.top);
			sellOffImage4->render(hdc, sellOffRect4.left, sellOffRect4.top);
			sellOffImage5->render(hdc, sellOffRect5.left, sellOffRect5.top);
			sellOffImage6->render(hdc, sellOffRect6.left, sellOffRect6.top);
			sellOffImage7->render(hdc, sellOffRect7.left, sellOffRect7.top);
			sellOnImage8->render(hdc, sellOnRect8.left, sellOnRect8.top);
		}

		if (sellSelectEquip)
		{
			sellEquipmentSlotOnImage->render(hdc, sellEquipmentSlotOnRect.left, sellEquipmentSlotOnRect.top);
			sellConsumptionSlotOffImage->render(hdc, sellConsumptionSlotOffRect.left, sellConsumptionSlotOffRect.top);
			
			for (int i = 0; i < INVENTORY->getEquipVector().size(); i++)
			{
				INVENTORY->getEquipVector()[i].itemImage->render(hdc, sellItemSlot[i].left, sellItemSlot[i].top);
				if (i > 6) break;
			}
			for (int i = 0; i < INVENTORY->getEquipVector().size(); i++)
			{
				sprintf_s(str, "%s", INVENTORY->getEquipVector()[i].name);
				TextOut(hdc, 580, 260 + i * 45, str, strlen(str));
				sprintf_s(str, "%d 五社", INVENTORY->getEquipVector()[i].price / 2);
				TextOut(hdc, 580, 280 + i * 45, str, strlen(str));
				if (i > 6) break;
			}
		}
		else if (sellSelectConsumption)
		{
			sellConsumptionSlotOnImage->render(hdc, sellConsumptionSlotOnRect.left, sellConsumptionSlotOnRect.top);
			sellEquipmentSlotOffImage->render(hdc, sellEquipmentSlotOffRect.left, sellEquipmentSlotOffRect.top);

			for (int i = 0; i < INVENTORY->getPotionVector().size(); i++)
			{
				INVENTORY->getPotionVector()[i].itemImage->render(hdc, sellItemSlot[i].left, sellItemSlot[i].top);
				if (i > 6) break;
			}
			for (int i = 0; i < INVENTORY->getPotionVector().size(); i++)
			{
				sprintf_s(str, "%s", INVENTORY->getPotionVector()[i].name);
				TextOut(hdc, 580, 260 + i * 45, str, strlen(str));
				sprintf_s(str, "%d 五社", INVENTORY->getPotionVector()[i].price / 2);
				TextOut(hdc, 580, 280 + i * 45, str, strlen(str));
				if (i > 6) break;
			}
		}
	}

	sprintf_s(str, "x :  %d", m_ptMouse.x);
	TextOut(hdc, 400, 100, str, strlen(str));

	sprintf_s(str, "y :  %d", m_ptMouse.y);
	TextOut(hdc, 400, 120, str, strlen(str));

	sprintf_s(str, "buyItem1 :  %d", buyItem1);
	TextOut(hdc, 600, 100, str, strlen(str));
}

void shop::npcRender()
{
	frameCount++;
	npcImage->setFrameY(0);
	if (frameCount % 20 == 0)
	{
		frameIndex++;
		if (frameIndex >= npcImage->getMaxFrameX())
		{
			frameIndex = 0;
		}
		npcImage->setFrameX(frameIndex);
	}

}

void shop::itemBuyChoice()
{
	if (PtInRect(&buyOffRect1, m_ptMouse))
	{
		if (KEYMANAGER->isOnceKeyDown(VK_LBUTTON))
		{
			buyNotChoice = false;
			buyItem1 = true;
			buyItem2 = false;
			buyItem3 = false;
			buyItem4 = false;
			buyItem5 = false;
			buyItem6 = false;
			buyItem7 = false;
			buyItem8 = false;
		}
	}

	if (PtInRect(&buyOffRect2, m_ptMouse))
	{
		if (KEYMANAGER->isOnceKeyDown(VK_LBUTTON))
		{
			buyNotChoice = false;
			buyItem1 = false;
			buyItem2 = true;
			buyItem3 = false;
			buyItem4 = false;
			buyItem5 = false;
			buyItem6 = false;
			buyItem7 = false;
			buyItem8 = false;
		}
	}

	if (PtInRect(&buyOffRect3, m_ptMouse))
	{
		if (KEYMANAGER->isOnceKeyDown(VK_LBUTTON))
		{
			buyNotChoice = false;
			buyItem1 = false;
			buyItem2 = false;
			buyItem3 = true;
			buyItem4 = false;
			buyItem5 = false;
			buyItem6 = false;
			buyItem7 = false;
			buyItem8 = false;
		}
	}

	if (PtInRect(&buyOffRect4, m_ptMouse))
	{
		if (KEYMANAGER->isOnceKeyDown(VK_LBUTTON))
		{
			buyNotChoice = false;
			buyItem1 = false;
			buyItem2 = false;
			buyItem3 = false;
			buyItem4 = true;
			buyItem5 = false;
			buyItem6 = false;
			buyItem7 = false;
			buyItem8 = false;
		}
	}

	if (PtInRect(&buyOffRect5, m_ptMouse))
	{
		if (KEYMANAGER->isOnceKeyDown(VK_LBUTTON))
		{
			buyNotChoice = false;
			buyItem1 = false;
			buyItem2 = false;
			buyItem3 = false;
			buyItem4 = false;
			buyItem5 = true;
			buyItem6 = false;
			buyItem7 = false;
			buyItem8 = false;
		}
	}

	if (PtInRect(&buyOffRect6, m_ptMouse))
	{
		if (KEYMANAGER->isOnceKeyDown(VK_LBUTTON))
		{
			buyNotChoice = false;
			buyItem1 = false;
			buyItem2 = false;
			buyItem3 = false;
			buyItem4 = false;
			buyItem5 = false;
			buyItem6 = true;
			buyItem7 = false;
			buyItem8 = false;
		}
	}

	if (PtInRect(&buyOffRect7, m_ptMouse))
	{
		if (KEYMANAGER->isOnceKeyDown(VK_LBUTTON))
		{
			buyNotChoice = false;
			buyItem1 = false;
			buyItem2 = false;
			buyItem3 = false;
			buyItem4 = false;
			buyItem5 = false;
			buyItem6 = false;
			buyItem7 = true;
			buyItem8 = false;
		}
	}

	if (PtInRect(&buyOffRect8, m_ptMouse))
	{
		if (KEYMANAGER->isOnceKeyDown(VK_LBUTTON))
		{
			buyNotChoice = false;
			buyItem1 = false;
			buyItem2 = false;
			buyItem3 = false;
			buyItem4 = false;
			buyItem5 = false;
			buyItem6 = false;
			buyItem7 = false;
			buyItem8 = true;
		}
	}
}

void shop::itemSellChoice()
{
	if (PtInRect(&sellOffRect1, m_ptMouse))
	{
		if (KEYMANAGER->isOnceKeyDown(VK_LBUTTON))
		{
			sellNotChoice = false;
			sellItem1 = true;
			sellItem2 = false;
			sellItem3 = false;
			sellItem4 = false;
			sellItem5 = false;
			sellItem6 = false;
			sellItem7 = false;
			sellItem8 = false;
		}
	}

	if (PtInRect(&sellOffRect2, m_ptMouse))
	{
		if (KEYMANAGER->isOnceKeyDown(VK_LBUTTON))
		{
			sellNotChoice = false;
			sellItem1 = false;
			sellItem2 = true;
			sellItem3 = false;
			sellItem4 = false;
			sellItem5 = false;
			sellItem6 = false;
			sellItem7 = false;
			sellItem8 = false;
		}
	}

	if (PtInRect(&sellOffRect3, m_ptMouse))
	{
		if (KEYMANAGER->isOnceKeyDown(VK_LBUTTON))
		{
			sellNotChoice = false;
			sellItem1 = false;
			sellItem2 = false;
			sellItem3 = true;
			sellItem4 = false;
			sellItem5 = false;
			sellItem6 = false;
			sellItem7 = false;
			sellItem8 = false;
		}
	}

	if (PtInRect(&sellOffRect4, m_ptMouse))
	{
		if (KEYMANAGER->isOnceKeyDown(VK_LBUTTON))
		{
			sellNotChoice = false;
			sellItem1 = false;
			sellItem2 = false;
			sellItem3 = false;
			sellItem4 = true;
			sellItem5 = false;
			sellItem6 = false;
			sellItem7 = false;
			sellItem8 = false;
		}
	}

	if (PtInRect(&sellOffRect5, m_ptMouse))
	{
		if (KEYMANAGER->isOnceKeyDown(VK_LBUTTON))
		{
			sellNotChoice = false;
			sellItem1 = false;
			sellItem2 = false;
			sellItem3 = false;
			sellItem4 = false;
			sellItem5 = true;
			sellItem6 = false;
			sellItem7 = false;
			sellItem8 = false;
		}
	}

	if (PtInRect(&sellOffRect6, m_ptMouse))
	{
		if (KEYMANAGER->isOnceKeyDown(VK_LBUTTON))
		{
			sellNotChoice = false;
			sellItem1 = false;
			sellItem2 = false;
			sellItem3 = false;
			sellItem4 = false;
			sellItem5 = false;
			sellItem6 = true;
			sellItem7 = false;
			sellItem8 = false;
		}
	}

	if (PtInRect(&sellOffRect7, m_ptMouse))
	{
		if (KEYMANAGER->isOnceKeyDown(VK_LBUTTON))
		{
			sellNotChoice = false;
			sellItem1 = false;
			sellItem2 = false;
			sellItem3 = false;
			sellItem4 = false;
			sellItem5 = false;
			sellItem6 = false;
			sellItem7 = true;
			sellItem8 = false;
		}
	}

	if (PtInRect(&sellOffRect8, m_ptMouse))
	{
		if (KEYMANAGER->isOnceKeyDown(VK_LBUTTON))
		{
			sellNotChoice = false;
			sellItem1 = false;
			sellItem2 = false;
			sellItem3 = false;
			sellItem4 = false;
			sellItem5 = false;
			sellItem6 = false;
			sellItem7 = false;
			sellItem8 = true;
		}
	}
}

void shop::buyItem()
{
	if (selectEquip)
	{
		if (buyItem1)
		{
			INVENTORY->getEquip(vEquip[0]);
			INVENTORY->boughtItemGold(vEquip[0].price);
		}
		else if (buyItem2)
		{
			INVENTORY->getEquip(vEquip[1]);
			INVENTORY->boughtItemGold(vEquip[1].price);
		}
		else if (buyItem3)
		{
			INVENTORY->getEquip(vEquip[2]);
			INVENTORY->boughtItemGold(vEquip[2].price);
		}
		else if (buyItem4)
		{
			INVENTORY->getEquip(vEquip[3]);
			INVENTORY->boughtItemGold(vEquip[3].price);
		}
		else if (buyItem5)
		{
			INVENTORY->getEquip(vEquip[4]);
			INVENTORY->boughtItemGold(vEquip[4].price);
		}
		else if (buyItem6)
		{
			INVENTORY->getEquip(vEquip[5]);
			INVENTORY->boughtItemGold(vEquip[5].price);
		}
	}
	else if (selectConsumption)
	{
		if (buyItem1)
		{
			INVENTORY->getPotion(vPotion[0]);
			INVENTORY->boughtItemGold(vPotion[0].price);
		}
		else if (buyItem2)
		{
			INVENTORY->getPotion(vPotion[1]);
			INVENTORY->boughtItemGold(vPotion[1].price);
		}
		else if (buyItem3)
		{
			INVENTORY->getPotion(vPotion[2]);
			INVENTORY->boughtItemGold(vPotion[2].price);
		}
		else if (buyItem4)
		{
			INVENTORY->getPotion(vPotion[3]);
			INVENTORY->boughtItemGold(vPotion[3].price);
		}
	}
}

void shop::sellItem()
{
	if (sellSelectEquip)
	{
		if (INVENTORY->getEquipVector().size() > 0)
		{
			if (sellItem1)
			{
				INVENTORY->sellItemGold(INVENTORY->getEquipVector()[0].price / 2);
				INVENTORY->setEquipVector(0);
			}
			else if (sellItem2)
			{
				INVENTORY->sellItemGold(INVENTORY->getEquipVector()[1].price / 2);
				INVENTORY->setEquipVector(1);
			}
			else if (sellItem3)
			{
				INVENTORY->sellItemGold(INVENTORY->getEquipVector()[2].price / 2);
				INVENTORY->setEquipVector(2);
			}
			else if (sellItem4)
			{
				INVENTORY->sellItemGold(INVENTORY->getEquipVector()[3].price / 2);
				INVENTORY->setEquipVector(3);
			}
			else if (sellItem5)
			{
				INVENTORY->sellItemGold(INVENTORY->getEquipVector()[4].price / 2);
				INVENTORY->setEquipVector(4);
			}
			else if (sellItem6)
			{
				INVENTORY->sellItemGold(INVENTORY->getEquipVector()[5].price / 2);
				INVENTORY->setEquipVector(5);
			}
			else if (sellItem7)
			{
				INVENTORY->sellItemGold(INVENTORY->getEquipVector()[6].price / 2);
				INVENTORY->setEquipVector(6);
			}
			else if (sellItem8)
			{
				INVENTORY->sellItemGold(INVENTORY->getEquipVector()[7].price / 2);
				INVENTORY->setEquipVector(7);
			}
		}
	}
	else if (sellSelectConsumption)
	{
		if (INVENTORY->getPotionVector().size() > 0)
		{
			if (sellItem1)
			{
				INVENTORY->sellItemGold(INVENTORY->getPotionVector()[0].price / 2);
				INVENTORY->setPotionVector(0);
			}
			else if (sellItem2)
			{
				INVENTORY->sellItemGold(INVENTORY->getPotionVector()[1].price / 2);
				INVENTORY->setPotionVector(1);
			}
			else if (sellItem3)
			{
				INVENTORY->sellItemGold(INVENTORY->getPotionVector()[2].price / 2);
				INVENTORY->setPotionVector(2);
			}
			else if (sellItem4)
			{
				INVENTORY->sellItemGold(INVENTORY->getPotionVector()[3].price / 2);
				INVENTORY->setPotionVector(3);
			}
			else if (sellItem5)
			{
				INVENTORY->sellItemGold(INVENTORY->getPotionVector()[4].price / 2);
				INVENTORY->setPotionVector(4);
			}
			else if (sellItem6)
			{
				INVENTORY->sellItemGold(INVENTORY->getPotionVector()[5].price / 2);
				INVENTORY->setPotionVector(5);
			}
			else if (sellItem7)
			{
				INVENTORY->sellItemGold(INVENTORY->getPotionVector()[6].price / 2);
				INVENTORY->setPotionVector(6);
			}
			else if (sellItem8)
			{
				INVENTORY->sellItemGold(INVENTORY->getPotionVector()[7].price / 2);
				INVENTORY->setPotionVector(7);
			}
		}
	}

}
