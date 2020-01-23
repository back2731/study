#include "mainGame.h"



mainGame::mainGame()
{
}


mainGame::~mainGame()
{
}

void mainGame::setPosition(int x, int y)
{
	m_x = x;
	m_y = y;
}

void mainGame::movePosition()
{
	m_x += 100;
	m_y += 100;
}

void mainGame::showPosition()
{
	cout << "XÁÂÇ¥ : " << m_x << endl;
	cout << "YÁÂÇ¥ : " << m_y << endl;
}
