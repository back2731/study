#include "mainGame.h"
#pragma warning(disable:4996)

mainGame::mainGame()
{
	//m_data.insert(map<string, int>::value_type("À¯Àç¼®", 50));

	//m_data.insert(make_pair("¤·¤·", 5));

	//m_data.insert(pair<string, int>("¤¾¤¾¤¾¤¾", 555));

	//pair<string, int> data1("È÷ÆR", 555005);
	//m_data.insert(data1);

	//mi_data = m_data.begin();

	//for (mi_data; mi_data != m_data.end(); ++mi_data)
	//{
	//	cout << mi_data->first << " " << mi_data->second << endl;
	//}

	cout << "¸î °³ÀÇ ÀÚ·á¸¦ ÀÔ·ÂÇÒ °Í ÀÔ´Ï±î?" << endl;
	cin >> num;

	for (int i = 0; i < num; i++)
	{
		cout << "ÀÚ·á¸¦ ÀÔ·ÂÇÏ½Ã¿À. (ÀÌ¸§ / ¼öÄ¡)" << endl;
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
		cout << "Ã£À» ÀÚ·á¸¦ ÀÔ·ÂÇÏ½Ã¿À." << endl;
		cin >> find_text;

		mi_data = m_data.begin();
		mi_data = m_data.find(find_text);

		if (mi_data != m_data.end())
		{
			cout << find_text << "ÀÇ ÀÚ·á°ª : " << mi_data->second << endl;
		}
	}
}


mainGame::~mainGame()
{
}
