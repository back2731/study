#include "mainGame.h"
#pragma warning(disable:4996)

mainGame::mainGame()
{
	//m_data.insert(map<string, int>::value_type("���缮", 50));

	//m_data.insert(make_pair("����", 5));

	//m_data.insert(pair<string, int>("��������", 555));

	//pair<string, int> data1("���R", 555005);
	//m_data.insert(data1);

	//mi_data = m_data.begin();

	//for (mi_data; mi_data != m_data.end(); ++mi_data)
	//{
	//	cout << mi_data->first << " " << mi_data->second << endl;
	//}

	cout << "�� ���� �ڷḦ �Է��� �� �Դϱ�?" << endl;
	cin >> num;

	for (int i = 0; i < num; i++)
	{
		cout << "�ڷḦ �Է��Ͻÿ�. (�̸� / ��ġ)" << endl;
		cin >> kyungil_data;
		
		kyungil_text = strtok(kyungil_data, "/");
		
		kyungil_num = atoi(strtok(NULL, "/"));

		m_data.insert(map<string, int>::value_type(kyungil_text, kyungil_num));
	}

	for (mi_data = m_data.begin(); mi_data != m_data.end(); ++mi_data)
	{
		cout << mi_data->first << ", " << mi_data->second << endl;
	}

	while (true)
	{
		cout << "ã�� �ڷḦ �Է��Ͻÿ�." << endl;
		cin >> find_text;

		mi_data = m_data.begin();
		mi_data = m_data.find(find_text);

		if (mi_data != m_data.end())
		{
			cout << find_text << "�� �ڷᰪ : " << mi_data->second << endl;
		}
	}
}


mainGame::~mainGame()
{
}
