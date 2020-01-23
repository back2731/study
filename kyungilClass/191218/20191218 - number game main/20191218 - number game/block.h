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

	void init();				// �� �ʱ� ���� �Լ� / �ʱ�ȭ �Լ�
	void printBlock();			// ���� �������� �����ִ� �Լ�
	void moveBlock();			// ������ �޾� 0�� �����̴� �Լ�
	void shuffleBoard();		// �ʱ� ���۽� �Լ����� �ڵ����� �����ִ� 
};

