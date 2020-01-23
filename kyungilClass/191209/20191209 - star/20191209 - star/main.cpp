#include <iostream>

using namespace std;

int main()
{
		char j = '*';

	for (int i = 0; i < 5; i++)
	{
		for (int k = 0; k < 5; k++)
		{
			if (i == k)
				cout << j;
			else if (i < k)
				cout << j;
		}
		cout << endl;
	}
	cout << endl;

	for (int i = 0; i < 5; i++)
	{
		for (int k = 0; k < 5; k++)
		{
			if (i == k)
				cout << j;
			else if (i > k)
				cout << j;
		}
		cout << endl;
	}
	cout << endl;

	for (int i = 0; i < 5; i++)
	{
		for (int k = 0; k < 5; k++)
		{
			if (i == 0)
				cout << j;
			else if (i > k)
				cout << " ";
			else if (i == k)
				cout << j;
			else if (i < k)
				cout << j;
		}
		cout << endl;
	}
	cout << endl;

	for (int i = 0; i < 5; i++)
	{
		for (int k = 0; k < 5; k++)
		{
			if (k >= 4 - i)
				cout << j;
			if (k < 4 - i)
				cout << " ";
		}
		cout << endl;
	}
	cout << endl;



	system("pause");
	return 0;
}