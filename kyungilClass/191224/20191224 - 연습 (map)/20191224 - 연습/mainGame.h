#pragma once
#include <iostream>
#include <string>
#include <map>

using namespace std;

class mainGame
{
private:
	int num;
	int kyungil_num;
	char kyungil_data[64];
	string kyungil_text, find_text;

	map<string, int> m_data;
	map<string, int>::iterator mi_data;

public:
	mainGame();
	~mainGame();
};

