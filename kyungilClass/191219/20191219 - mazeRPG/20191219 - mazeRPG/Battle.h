#include "Player.h"
#include "Monster.h"

#pragma once
class Battle
{
private:
	Player* m_player;
	Monster* m_monster;
	
public:
	Battle();
	~Battle();

	void battleSet();
	void doBattle();

};

