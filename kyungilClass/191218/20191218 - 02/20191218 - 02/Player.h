#pragma once
#include "unit.h"

// 유닛 클래스를 상속받는다.
class Player : public unit
{
private:

public:
	Player();
	~Player();

	void init();
};

