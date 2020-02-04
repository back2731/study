#pragma once
#include "player.h"
#include "singletonBase.h"
#include "inventory.h"
#include "status.h"

class equipment : public player, public singletonBase<equipment>
{
private:
	image* equipmentWindowImage;
	RECT equipmentWindowRect;

	RECT weaponRect;
	vector<tagItemInfo> vWeapon;

	RECT capRect;
	vector<tagItemInfo> vCapRect;

	RECT topRect;
	vector<tagItemInfo> vTopRect;

	RECT bottomRect;
	vector<tagItemInfo> vBottomRect;

	RECT glovesRect;
	vector<tagItemInfo> vGlovesRect;

	RECT shoesRect;
	vector<tagItemInfo> vShoesRect;

	bool equipmentOpen;

public:
	equipment();
	~equipment();

	HRESULT init();
	void release();
	void update();
	void render(HDC hdc);

	void setWeapon(tagItemInfo weaponVector) { vWeapon.push_back(weaponVector); }
	tagItemInfo getWeapon() { return vWeapon[0]; }
};

