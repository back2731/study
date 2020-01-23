#include <iostream>
#include <Windows.h>
#include "block.h"

using namespace std;
bool gamePlay = true;

int main()
{
	int input;
	int resetKey;
	block block;

	block.init();
	cout << "���� ��" << endl;
	cout << "==================================================================" << endl;
	block.printBlock();

	block.shuffleBoard();
	cout << "���� ��" << endl;

	while (gamePlay)
	{
		cout << "==================================================================" << endl;
		block.printBlock();
		block.moveBlock();
		Sleep(1000);
		system("cls");

		//Sleep(1000);
		block.resetBoard();
	}

	system("pause");
	return 0;
}