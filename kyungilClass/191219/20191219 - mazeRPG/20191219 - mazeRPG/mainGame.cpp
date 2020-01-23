#include "mainGame.h"

mainGame::mainGame()
{
	m_maze = new maze;
	m_player = new Player;
	m_monster = new Monster;
	m_battle = new Battle;

	m_maze->boardTruefalse();
	m_maze->setBoard();
	m_maze->firstprintBoard();
	m_maze->setPlayer();
}


mainGame::~mainGame()
{
	delete m_maze;
	delete m_player;
	delete m_monster;
	delete m_battle;
}

string mainGame::getmazeMap(int x, int y)
{
	return m_maze->mazeMap[x][y];	
}

void mainGame::movePlayer()
{
	m_maze->movePlayer();
}

void mainGame::battleResult()
{
	m_battle->doBattle();
}

int mainGame::monHp()
{
	return m_monster->monsterHp;
}
