#pragma once
#include <iostream>
#include <vector>

using namespace std;

class mainGame
{
private:
	// ������ ���͸� ����
	vector<int> m_vNumber;

	// ������ ���� �ݺ��� ����
	// (int ���� vector�� ����Ű�� iterator)
	vector<int>::iterator m_viNumber;





public:
	mainGame();
	~mainGame();
};

