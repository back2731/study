#include "mainGame.h"
#pragma warning(disable:4996)
mainGame::mainGame()
{
	cout << "�� ���� �ڷḦ �Է��Ұ� �Դϱ�?" << endl;
	cin >> num;

	for (int i = 0; i < num; i++)
	{
		cout << "�ڷḦ �Է��Ͻÿ�.(�̸�, ��ġ)" << endl;
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
		cout << "\nã�� �ڷ��� �̸��� �Է��Ͻÿ�.";
		cin >> find_text;

		I_kyungil = kyungil.begin();
		I_kyungil = kyungil.find(find_text);

		if (I_kyungil != kyungil.end())
		{
			cout << find_text << "�� �ڷᰪ : " << I_kyungil->second << endl;
		}
	}
	/*
		������ �̸� ����

	*/
}


mainGame::~mainGame()
{
}
