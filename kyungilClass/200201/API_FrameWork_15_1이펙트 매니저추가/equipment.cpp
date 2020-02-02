#include "stdafx.h"
#include "equipment.h"

equipment::equipment()
{
}

equipment::~equipment()
{
}

HRESULT equipment::init()
{
	equipmentWindowImage = IMAGEMANAGER->addImage("currentEquipment", "images/currentEquipment.bmp", 231, 364, true, RGB(255, 0, 255));
	equipmentWindowRect = RectMakeCenter(WINSIZEX / 2, WINSIZEY / 2, equipmentWindowImage->getWidth(), equipmentWindowImage->getHeight());
	
	weaponRect = RectMake(534, 361, 38, 38);
	capRect = RectMake(452,237,38,38);
	topRect = RectMake(450,360,38,38);
	bottomRect = RectMake(450, 400, 38, 38);
	glovesRect = RectMake(410, 400, 38, 38);
	shoesRect = RectMake(491, 445, 38, 38);

	equipmentOpen = false;
	return S_OK;
}

void equipment::release()
{
}

void equipment::update()
{
	if (!equipmentOpen)
	{
		if (KEYMANAGER->isOnceKeyDown('E'))
		{
			equipmentOpen = true;
		}
	}
	else
	{
		if (KEYMANAGER->isOnceKeyDown('E'))
		{
			equipmentOpen = false;
		}
		if (PtInRect(&weaponRect, m_ptMouse))
		{
			if (KEYMANAGER->isOnceKeyDown(VK_RBUTTON))
			{
				INVENTORY->getEquip(vWeapon[0]);
				vWeapon.clear();
			}
		}
	}
}

void equipment::render()
{
	if (KEYMANAGER->isToggleKey(VK_TAB))
	{
		Rectangle(getMemDC(), equipmentWindowRect.left, equipmentWindowRect.top, equipmentWindowRect.right, equipmentWindowRect.bottom);
		
	}

	if (equipmentOpen)
	{
		equipmentWindowImage->render(getMemDC(), equipmentWindowRect.left, equipmentWindowRect.top);
		if (KEYMANAGER->isToggleKey(VK_TAB))
		{
			Rectangle(getMemDC(), weaponRect.left, weaponRect.top, weaponRect.right, weaponRect.bottom);
			Rectangle(getMemDC(), capRect.left, capRect.top, capRect.right, capRect.bottom);
			Rectangle(getMemDC(), topRect.left, topRect.top, topRect.right, topRect.bottom);
			Rectangle(getMemDC(), bottomRect.left, bottomRect.top, bottomRect.right, bottomRect.bottom);
			Rectangle(getMemDC(), glovesRect.left, glovesRect.top, glovesRect.right, glovesRect.bottom);
			Rectangle(getMemDC(), shoesRect.left, shoesRect.top, shoesRect.right, shoesRect.bottom);
		}

		if (vWeapon.size() > 0)
		{
			vWeapon[0].itemImage->render(getMemDC(), weaponRect.left, weaponRect.top);
			if (PtInRect(&weaponRect, m_ptMouse))
			{
				vWeapon[0].itemInfoImage->render(getMemDC(), m_ptMouse.x, m_ptMouse.y);
			}
		}
	}
}
