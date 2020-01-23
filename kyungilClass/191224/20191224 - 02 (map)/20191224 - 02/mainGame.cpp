#include "mainGame.h"
#pragma warning(disable:4996)
mainGame::mainGame()
{
	cout << "몇 개의 자료를 입력할것 입니까?" << endl;
	cin >> num;

	for (int i = 0; i < num; i++)
	{
		cout << "자료를 입력하시오.(이름, 수치)" << endl;
		cin >> kyungil_data;

		kyungil_text = strtok(kyungil_data, "/");
		
		kyungil_num = atoi(strtok(NULL, "/"));

		kyungil.insert(pair<string, int>(kyungil_text, kyungil_num));
	}

	for (I_kyungil = kyungil.begin(); I_kyungil != kyungil.end(); ++I_kyungil)
	{
		cout << I_kyungil->first << ", " << I_kyungil->second << endl;
	}

	while (true)
	{
		cout << "\n찾을 자료의 이름을 입력하시오.";
		cin >> find_text;

		I_kyungil = kyungil.begin();
		I_kyungil = kyungil.find(find_text);

		if (I_kyungil != kyungil.end())
		{
			cout << find_text << "의 자료값 : " << I_kyungil->second << endl;
		}
	}
	/*
		연예인 이름 고르기

	*/
}


mainGame::~mainGame()
{
}
