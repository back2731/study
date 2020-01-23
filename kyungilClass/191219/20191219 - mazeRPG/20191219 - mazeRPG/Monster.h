#include <iostream>
using namespace std;

#pragma once
class Monster
{
private:

protected:

public:
	int monsterHp = 100;
	int monsterAtk = 5;
	Monster();
	~Monster();

	int getmonsterHp();
	void setmonsterHp(int hp);
	int setmonsterAtk();
	void showmonsterHp();
};

