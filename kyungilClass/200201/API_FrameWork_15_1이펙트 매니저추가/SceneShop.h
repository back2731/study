#pragma once
#include "gameNode.h"
#include "equipment.h"
#include "shop.h"
#include "inventory.h"
#include "status.h"

class SceneShop : public gameNode
{
private:

public:
	SceneShop();
	~SceneShop();

	HRESULT init();
	void release();
	void update();
	void render();
};

