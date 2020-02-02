#include "stdafx.h"
#include "ItemManager.h"

HRESULT ItemManager::init()
{
	tagItemInfo weapon;
	weapon.itemkind = ITEM_WEAPON;
	weapon.itemImage = IMAGEMANAGER->addImage("�����μ��̵� ���", "images/weapon.bmp", 31, 31, true, RGB(255, 0, 255));
	weapon.itemInfoImage = IMAGEMANAGER->addImage("�����μ��̵� ��� ����", "images/weaponExplanation.bmp", 352, 362, true, RGB(255, 0, 255));
	weapon.name = "�����μ��̵� ���";
	weapon.description = "���� ���ݼӵ��� ���� �����μ��̵� ��Ŵ�.";
	weapon.atk = 276;
	weapon.def = 0;
	weapon.dex = 100;
	weapon.luk = 100;
	weapon.hpPotion = 0;
	weapon.mpPotion = 0;
	weapon.upgrade = 8;
	weapon.price = 1000;
	vEquip.push_back(weapon);

	tagItemInfo armor1;
	armor1.itemkind = ITEM_CAP;
	armor1.itemImage = IMAGEMANAGER->addImage("�����μ��̵� ������", "images/cap.bmp", 33, 30, true, RGB(255, 0, 255));
	armor1.itemInfoImage = IMAGEMANAGER->addImage("�����μ��̵� ������ ����", "images/capExplanation.bmp", 326, 357, true, RGB(255, 0, 255));
	armor1.name = "�����μ��̵� ������";
	armor1.description = "Ǫ�� ���� ������";
	armor1.atk = 7;
	armor1.def = 600;
	armor1.dex = 65;
	armor1.luk = 65;
	armor1.hpPotion = 0;
	armor1.mpPotion = 0;
	armor1.upgrade = 11;
	armor1.price = 1100;
	vEquip.push_back(armor1);

	tagItemInfo armor2;
	armor2.itemkind = ITEM_TOP;
	armor2.itemImage = IMAGEMANAGER->addImage("�̱۾��� ����ż���", "images/top.bmp", 32, 29, true, RGB(255, 0, 255));
	armor2.itemInfoImage = IMAGEMANAGER->addImage("�̱۾��� ����ż��� ����", "images/topExplanation.bmp", 326, 376, true, RGB(255, 0, 255));
	armor2.name = "�̱۾��� ����ż���";
	armor2.description = "����ſ� ����";
	armor2.atk = 2;
	armor2.def = 135;
	armor2.dex = 30;
	armor2.luk = 30;
	armor2.hpPotion = 0;
	armor2.mpPotion = 0;
	armor2.upgrade = 7;
	armor2.price = 1200;
	vEquip.push_back(armor2);

	tagItemInfo armor3;
	armor3.itemkind = ITEM_BOTTOM;
	armor3.itemImage = IMAGEMANAGER->addImage("Ʈ������ ���������", "images/bottom.bmp", 28, 31, true, RGB(255, 0, 255));
	armor3.itemInfoImage = IMAGEMANAGER->addImage("Ʈ������ ��������� ����", "images/bottomExplanation.bmp", 327, 359, true, RGB(255, 0, 255));
	armor3.name = "Ʈ������ ���������";
	armor3.description = "����ſ� ����";
	armor3.atk = 2;
	armor3.def = 135;
	armor3.dex = 30;
	armor3.luk = 30;
	armor3.hpPotion = 0;
	armor3.mpPotion = 0;
	armor3.upgrade = 7;
	armor3.price = 1500;
	vEquip.push_back(armor3);

	tagItemInfo armor4;
	armor4.itemkind = ITEM_GLOVES;
	armor4.itemImage = IMAGEMANAGER->addImage("�����μ��̵� �����۷���", "images/gloves.bmp", 31, 29, true, RGB(255, 0, 255));
	armor4.itemInfoImage = IMAGEMANAGER->addImage("�����μ��̵� �����۷��� ����", "images/glovesExplanation.bmp", 326, 358, true, RGB(255, 0, 255));
	armor4.name = "�����μ��̵� �����۷���";
	armor4.description = "�����۷���";
	armor4.atk = 9;
	armor4.def = 250;
	armor4.dex = 40;
	armor4.luk = 40;
	armor4.hpPotion = 0;
	armor4.mpPotion = 0;
	armor4.upgrade = 7;
	armor4.price = 1500;
	vEquip.push_back(armor4);

	tagItemInfo armor5;
	armor5.itemkind = ITEM_SHOES;
	armor5.itemImage = IMAGEMANAGER->addImage("�����μ��̵� ��������", "images/shoes.bmp", 30, 31, true, RGB(255, 0, 255));
	armor5.itemInfoImage = IMAGEMANAGER->addImage("�����μ��̵� �������� ����", "images/shoesExplanation.bmp", 326, 357, true, RGB(255, 0, 255));
	armor5.name = "�����μ��̵� ��������";
	armor5.description = "��������";
	armor5.atk = 9;
	armor5.def = 250;
	armor5.dex = 40;
	armor5.luk = 40;
	armor5.hpPotion = 0;
	armor5.mpPotion = 0;
	armor5.upgrade = 7;
	armor5.price = 1700;
	vEquip.push_back(armor5);

	tagItemInfo potion1;
	potion1.itemkind = ITEM_POTION;
	potion1.itemImage = IMAGEMANAGER->addImage("mpPotion", "images/mpPotion.bmp", 32, 32, true, RGB(255, 0, 255));
	potion1.itemInfoImage = IMAGEMANAGER->addImage("mpPotion ����", "images/Explanation_mpPotion.bmp", 365, 157, true, RGB(255, 0, 255));
	potion1.name = "mpPotion";
	potion1.description = "������ ����.";
	potion1.atk = 0;
	potion1.def = 0;
	potion1.dex = 0;
	potion1.luk = 0;
	potion1.hpPotion = 0;
	potion1.mpPotion = 300;
	potion1.upgrade = 0;
	potion1.price = 200;
	vPotion.push_back(potion1);

	tagItemInfo potion2;
	potion2.itemkind = ITEM_POTION;
	potion2.itemImage = IMAGEMANAGER->addImage("potion50", "images/potion50.bmp", 32, 32, true, RGB(255, 0, 255));
	potion2.itemInfoImage = IMAGEMANAGER->addImage("potion50 ����", "images/Explanation_potion50.bmp", 364, 156, true, RGB(255, 0, 255));
	potion2.name = "potion50";
	potion2.description = "ü�� ������ ���� ������!";
	potion2.atk = 0;
	potion2.def = 0;
	potion2.dex = 0;
	potion2.luk = 0;
	potion2.hpPotion = 500;
	potion2.mpPotion = 500;
	potion2.upgrade = 0;
	potion2.price = 500;
	vPotion.push_back(potion2);

	tagItemInfo potion3;
	potion3.itemkind = ITEM_POTION;
	potion3.itemImage = IMAGEMANAGER->addImage("redPotion", "images/redPotion.bmp", 27, 30, true, RGB(255, 0, 255));
	potion3.itemInfoImage = IMAGEMANAGER->addImage("redPotion ����", "images/Explanation_redPotion.bmp", 363, 155, true, RGB(255, 0, 255));
	potion3.name = "redPotion";
	potion3.description = "ü�� 50ȸ��!";
	potion3.atk = 0;
	potion3.def = 0;
	potion3.dex = 0;
	potion3.luk = 0;
	potion3.hpPotion = 50;
	potion3.mpPotion = 0;
	potion3.upgrade = 0;
	potion3.price = 100;
	vPotion.push_back(potion3);

	tagItemInfo potion4;
	potion4.itemkind = ITEM_POTION;
	potion4.itemImage = IMAGEMANAGER->addImage("whitePotion", "images/whitePotion.bmp", 27, 30, true, RGB(255, 0, 255));
	potion4.itemInfoImage = IMAGEMANAGER->addImage("whitePotion ����", "images/Explanation_whitePotion.bmp", 363, 155, true, RGB(255, 0, 255));
	potion4.name = "whitePotion";
	potion4.description = "ü�� 300ȸ��!";
	potion4.atk = 0;
	potion4.def = 0;
	potion4.dex = 0;
	potion4.luk = 0;
	potion4.hpPotion = 300;
	potion4.mpPotion = 0;
	potion4.upgrade = 0;
	potion4.price = 300;
	vPotion.push_back(potion4);

	return S_OK;
}

void ItemManager::release()
{
}

void ItemManager::update()
{
}

void ItemManager::render()
{
}
