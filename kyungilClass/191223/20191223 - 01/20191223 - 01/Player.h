#pragma once
#include "unit.h"
#include "inventory.h"

// ���� ���
class Player : public unit, public inventory
{


public:
	Player();
	~Player();

	// �÷��̾� �ʱⰪ ����
	void initPlayer();
	// �÷��̾� �������ͽ� ���
	void showStatus();
};

