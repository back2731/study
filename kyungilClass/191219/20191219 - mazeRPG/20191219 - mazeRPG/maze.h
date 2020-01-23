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

	int x;			// 맵 위치 확인, 플레이어 움직임 변수
	int y;			// 맵 위치 확인, 플레이어 움직임 변수

	int inputKey;	// 방향키 입력변수
	string temp;		// 스왑

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

