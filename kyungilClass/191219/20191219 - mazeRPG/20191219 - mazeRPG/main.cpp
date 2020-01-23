#include "mainGame.h"
#include <Windows.h>

string mazeMap[10][10];

int main()
{
	mainGame mg;
	//mg.battle();

	cout << "플레이어 소환" << endl;
	Sleep(1000);

	system("cls");

	while (true)
	{
		mg.movePlayer();
		if (mg.monHp() > 0)
		{
			if (mg.getmazeMap(9, 8) == "♤")
			{
				cout << "보스룸 입장" << endl;
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