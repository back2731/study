#pragma once
#include "maze.h"
#include "Player.h"
#include "Monster.h"
#include "Battle.h"

class mainGame
{
private:
	maze* m_maze;
	Player* m_player;
	Monster* m_monster;
	Battle* m_battle;
	

public:
	mainGame();
	~mainGame();

	string getmazeMap(int x, int y);
	void movePlayer();
	void battleResult();
	int monHp();
};

