#include "Player.h"



Player::Player()
{
}


Player::~Player()
{
}

void Player::playerInit()
{
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			playerPosition[i][j] = "¢»";
		}
	}
}

string Player::getplayerPosition(int a, int b)
{
	return playerPosition[a][b];
}

int Player::getHp()
{
	return playerHp;
}

void Player::setHp(int hp)
{
	playerHp = hp;
}

int Player::setAtk()
{
	return PlayerAtk;
}

void Player::showHp()
{
	cout << playerHp << endl;
}
