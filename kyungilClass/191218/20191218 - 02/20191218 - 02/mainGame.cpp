#include "mainGame.h"



mainGame::mainGame()
{
	m_unit = new unit;
	m_unit->init();

	m_player = new Player;
	m_player->init();
}
mainGame::~mainGame()
{
	delete m_unit;
	delete m_player;
}
