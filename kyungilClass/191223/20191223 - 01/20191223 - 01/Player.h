#pragma once
#include "unit.h"
#include "inventory.h"

// 다중 상속
class Player : public unit, public inventory
{


public:
	Player();
	~Player();

	// 플레이어 초기값 설정
	void initPlayer();
	// 플레이어 스테이터스 출력
	void showStatus();
};

