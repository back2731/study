#pragma once
#include <iostream>
#include <vector>

using namespace std;

class mainGame
{
private:
	// 정수형 벡터를 선언
	vector<int> m_vNumber;

	// 정수형 벡터 반복자 선언
	// (int 형식 vector를 가리키는 iterator)
	vector<int>::iterator m_viNumber;





public:
	mainGame();
	~mainGame();
};

