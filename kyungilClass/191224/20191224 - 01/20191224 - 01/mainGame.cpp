#include "mainGame.h"



mainGame::mainGame()
{
	// 방법 1
	m_data.insert(map<string, int>::value_type("안녕하세요", 1));

	// 방법 2
	m_data.insert(make_pair("ㅎㅇ", 5));
		
	// 방법 3
	m_data.insert(pair<string, int>("오우", 10));
	m_data.insert(pair<string, int>("반장", 20));
	m_data.insert(pair<string, int>("장독대", 30));
	m_data.insert(pair<string, int>("대나무", 40));
	m_data.insert(pair<string, int>("무지개", 50));

	// 방법 4
	pair<string, int>pt1("히히히히", 500);
	m_data.insert(pt1);

	m_data.erase("무지개");

	mi_data = m_data.begin();
	for (mi_data; mi_data != m_data.end(); ++mi_data)
	{
		cout << mi_data->first << " " << mi_data->second << endl;
	}

	// 데이터가 있는지 확인
	if (m_data.find("") != m_data.end())
	{
		cout << "있다." << endl;
	}
	else
	{
		cout << "없다." << endl;
	}
}


mainGame::~mainGame()
{
}
