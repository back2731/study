#pragma once
#include <iostream>
#include <time.h>
#include <Windows.h>

using namespace std;

class slidePuzzle
{
private:
	int num[25];			// ������
	int dest, sour, temp;	// ����
	int key;				// Ű�Է�
	int save = 24;			// 0�� ��ġ
	int move;				// 0�� ������

public:
	slidePuzzle();
	~slidePuzzle();

	void init();
	void update();
	void render();
};

