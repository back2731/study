#include "mainGame.h"
#include <Windows.h>

string mazeMap[10][10];

int main()
{
	mainGame mg;
	//mg.battle();

	cout << "�÷��̾� ��ȯ" << endl;
	Sleep(1000);

	system("cls");

	while (true)
	{
		mg.movePlayer();
		if (mg.monHp() > 0)
		{
			if (mg.getmazeMap(9, 8) == "��")
			{
				cout << "������ ����" << endl;
				mg.battleResult();
			
				system("pause");
			}
		}
		
		//Sleep(500);
		system("cls");
	}


	system("pause");
	return 0;
}