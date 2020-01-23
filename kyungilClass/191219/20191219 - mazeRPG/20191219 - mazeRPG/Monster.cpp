#include "Monster.h"



Monster::Monster()
{
}


Monster::~Monster()
{
}

int Monster::getmonsterHp()
{
	return monsterHp;
}

void Monster::setmonsterHp(int hp)
{
	monsterHp = hp;
}

int Monster::setmonsterAtk()
{
	return monsterAtk;
}

void Monster::showmonsterHp()
{
	cout << monsterHp << endl;
}
