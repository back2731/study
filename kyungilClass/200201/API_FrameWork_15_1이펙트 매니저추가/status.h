#pragma once
#include "player.h"
#include "singletonBase.h"
#include "equipment.h"

class status : public player, public singletonBase<status>
{
private:
	image* statusWindowImage;
	RECT statusWindowRect;

public:
	status();
	~status();

	HRESULT init();
	void release();
	void update();
	void render();
};

