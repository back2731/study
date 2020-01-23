#include <iostream>
#include <Windows.h>
#include <time.h>

using namespace std;

int number[25];
int dest, sour, temp;
int inputNumber;
int bingoCount = 0;

void shuffleNum()
{
	for (int i = 0; i < 200; i++)
	{
		dest = rand() % 25;
		sour = rand() % 25;

		temp = number[dest];
		number[dest] = number[sour];
		number[sour] = temp;
	}
}

int main()
{
	for (int i = 0; i < 25; i++)
	{
		number[i] = i + 1;
	}
	
	shuffleNum();

	for (int i = 0; i < 25; i++)
	{
		cout << number[i] << endl;;
	}

	system("pause");
	return 0;
}