#include <iostream>
#include <Windows.h>
#include "block.h"

using namespace std;

int main()
{
	block block;

	block.init();
	cout << "���� ��" << endl;
	block.printBlock();

	block.shuffleBoard();
	cout << "���� ��" << endl;

	while(true)
	{
		block.printBlock();
		block.moveBlock();
		Sleep(500);
		system("cls");
	}

	system("pause");
	return 0;
}