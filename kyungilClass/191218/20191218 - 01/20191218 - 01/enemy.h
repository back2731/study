#pragma once
class enemy
{
private:

	int m_hp;

public:
	enemy();
	~enemy();

	void init();
	
	int gethp() { return m_hp; }
	void sethp(int hp) { m_hp = hp; }
};

