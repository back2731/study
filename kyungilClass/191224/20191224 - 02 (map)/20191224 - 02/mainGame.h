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
	char kyungil_data[32];
	string kyungil_text, find_text;

	map<string, int> kyungil;
	map<string, int>::iterator I_kyungil;

public:
	mainGame();
	~mainGame();
};

