#include <string>
#include <iostream>
#include <conio.h>
#include "Player.h"
#pragma once

using namespace std;
class maze
{
private:
	bool boardCheck[10][10];

	Player* m_player;

	int x;			// �� ��ġ Ȯ��, �÷��̾� ������ ����
	int y;			// �� ��ġ Ȯ��, �÷��̾� ������ ����

	int inputKey;	// ����Ű �Էº���
	string temp;		// ����

public:
	string mazeMap[10][10];
	maze();
	~maze();

	//void test();
	void boardTruefalse();
	void setBoard();
	void printBoard();
	void firstprintBoard();
	void setPlayer();
	void movePlayer();
};

