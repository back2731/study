#include "mainGame.h"



mainGame::mainGame()
{
	// ��� 1
	m_data.insert(map<string, int>::value_type("�ȳ��ϼ���", 1));

	// ��� 2
	m_data.insert(make_pair("����", 5));
		
	// ��� 3
	m_data.insert(pair<string, int>("����", 10));
	m_data.insert(pair<string, int>("����", 20));
	m_data.insert(pair<string, int>("�嵶��", 30));
	m_data.insert(pair<string, int>("�볪��", 40));
	m_data.insert(pair<string, int>("������", 50));

	// ��� 4
	pair<string, int>pt1("��������", 500);
	m_data.insert(pt1);

	m_data.erase("������");

	mi_data = m_data.begin();
	for (mi_data; mi_data != m_data.end(); ++mi_data)
	{
		cout << mi_data->first << " " << mi_data->second << endl;
	}

	// �����Ͱ� �ִ��� Ȯ��
	if (m_data.find("") != m_data.end())
	{
		cout << "�ִ�." << endl;
	}
	else
	{
		cout << "����." << endl;
	}
}


mainGame::~mainGame()
{
}
