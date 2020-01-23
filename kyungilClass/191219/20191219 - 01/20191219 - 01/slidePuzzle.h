#pragma once
#include <iostream>
#include <time.h>
#include <Windows.h>

using namespace std;

class slidePuzzle
{
private:
	int num[25];			// 숫자판
	int dest, sour, temp;	// 셔플
	int key;				// 키입력
	int save = 24;			// 0의 위치
	int move;				// 0의 움직임

public:
	slidePuzzle();
	~slidePuzzle();

	void init();
	void update();
	void render();
};

