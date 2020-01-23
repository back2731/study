#include<string>
#pragma once

using namespace std;

class Card
{
public:
	string shape;
	int number;
	bool IsUsed;

	void Init(string sp, int num)
	{
		shape = sp;
		number = num;
		IsUsed = false;
	}
};

