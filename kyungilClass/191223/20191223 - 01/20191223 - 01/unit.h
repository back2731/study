#pragma once
class unit
{

protected:
	int m_atk;
	int m_def;

public:
	unit();
	~unit();

	int getAtk() { return m_atk; }
	void setAtk(int atk) { m_atk = atk; }

	int getDef() { return m_def; }
	void setDef(int def) { m_def = def; }
};

