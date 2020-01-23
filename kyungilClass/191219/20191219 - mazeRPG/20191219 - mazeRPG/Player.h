#include <string>
#include <iostream>
using namespace std;
#pragma once

class Player
{
private:
	string playerPosition[10][10];

public:
	int playerHp = 100;
	int PlayerAtk = 10;
	Player();
	~Player();
	
	void playerInit();
	string getplayerPosition(int a, int b);
	int getHp();
	void setHp(int hp);
	int setAtk();
	void showHp();

};

