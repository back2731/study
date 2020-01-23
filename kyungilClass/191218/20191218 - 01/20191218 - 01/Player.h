#pragma once
#include <iostream>

using namespace std;
/*
	getter setter 엑세스 함수
	private 멤버 변수의 값을 리턴하거나 값을 대입할 수 있다.
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

