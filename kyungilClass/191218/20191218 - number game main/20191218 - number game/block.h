#pragma once
#include<iostream>
#include <time.h>
#include <conio.h>

using namespace std;

class block
{
private:
	int blockNumber[4][4];
	int X;
	int Y;
	int temp;

public:
	block();
	~block();

	void init();				// 판 초기 세팅 함수 / 초기화 함수
	void printBlock();			// 현재 보드판을 보여주는 함수
	void moveBlock();			// 변수를 받아 0을 움직이는 함수
	void shuffleBoard();		// 초기 시작시 함수판을 자동으로 섞어주는 
};

