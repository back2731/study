#pragma once
#include <iostream>

using namespace std;
/*
	getter setter ������ �Լ�
	private ��� ������ ���� �����ϰų� ���� ������ �� �ִ�.
*/

class Player
{
private:
	int m_hp;


public:
	
	Player();
	~Player();

	void init();
	int gethp() { return m_hp; }
	void sethp(int hp){	m_hp = hp; }
};

