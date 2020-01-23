#include <iostream>
#include <vector>

using namespace std;

/*
	vector : STL(standard templete library)���� ���� ���ȴ�.
	������ �����̳�(vector, list deque)
	������ : �����͸� �������� �����ϸ� ���� �Ϲ����� �����̳ʴ�

	1. ��� ��Ұ� ����������� ��ġ�Ǿ� �־�� �Ѵ�.
	2. ù��° ��ҿ� ������ ��Ҹ� ������ ������ ��ҵ��� 
	�ݵ�� ������ ��Ҹ� ������ �־���Ѵ�.

	vector 
	���� : �������ҵ� ���� ����. ���Ҹ� �������� �����ϰ� ���� ���� ������.
	���� : ���� �ƴ� ������ ����, ���� �� �ӵ��� ������ �� �ִ�.


*/

int main()
{
	vector <int> v;

	v.push_back(10);
	v.push_back(20);
	v.push_back(30);
	v.push_back(40);
	v.push_back(50);
	v.push_back(60);
	v.push_back(70);
	v.push_back(80);
	v.push_back(90);

	// vector v�� size ��ŭ�� ����Ѵ�.  v.size() ������ ������ŭ ��������.
	for (int i = 0; i < v.size(); i++)
	{
		cout << v[i] << endl;
	}

	cout << "������ ���� ���� : " << v.size() << endl;

	// �뷮�� ���ڶ� ��� ������ �뷮�� �÷��ش�.
	cout << "������ capactiy(�뷮) : " << v.capacity() << endl;

	cout << "������ �ִ� ���� : " << v.max_size() << endl;

	cout << "=================�� �� (pop_back)=================" << endl;

	v.pop_back();
	v.pop_back();
	v.pop_back();

	v.clear();
	cout << "=================Ŭ���� ��=====================" << endl;

	for (int i = 0; i < v.size(); ++i)
	{
		cout << v[i] << endl;
	}

	//cout << "===========�������� ��=====================" << endl;

	//v.resize(3);

	//for (int i = 0; i < v.size(); ++i)
	//{
	//	cout << v[i] << endl;
	//}

	cout << "v�� ������ : " << v.size() << " " << "v�� capacity" << v.capacity() << endl;
	system("pause");
	return 0;
}