#include <iostream>
#include <vector>

using namespace std;

/*
	vector : STL(standard templete library)에서 자주 사용된다.
	시퀸스 컨테이너(vector, list deque)
	시퀸스 : 데이터를 선형으로 저장하며 가장 일반적인 컨테이너다

	1. 모든 요소가 직선순서대로 배치되어 있어야 한다.
	2. 첫번째 요소와 마지막 요소를 제외한 나머지 요소들은 
	반드시 인접한 요소를 가지고 있어야한다.

	vector 
	장점 : 개별원소들 접근 가능. 원소를 마지막에 삽입하고 빼는 것이 빠르다.
	단점 : 끝이 아닌 곳에서 삽입, 제거 시 속도가 떨어질 수 있다.


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

	// vector v의 size 만큼을 출력한다.  v.size() 원소의 갯수만큼 돌리세요.
	for (int i = 0; i < v.size(); i++)
	{
		cout << v[i] << endl;
	}

	cout << "벡터의 원소 개수 : " << v.size() << endl;

	// 용량이 모자랄 경우 스스로 용량을 늘려준다.
	cout << "벡터의 capactiy(용량) : " << v.capacity() << endl;

	cout << "벡터의 최대 저장 : " << v.max_size() << endl;

	cout << "=================뺀 후 (pop_back)=================" << endl;

	v.pop_back();
	v.pop_back();
	v.pop_back();

	v.clear();
	cout << "=================클리어 후=====================" << endl;

	for (int i = 0; i < v.size(); ++i)
	{
		cout << v[i] << endl;
	}

	//cout << "===========리사이즈 후=====================" << endl;

	//v.resize(3);

	//for (int i = 0; i < v.size(); ++i)
	//{
	//	cout << v[i] << endl;
	//}

	cout << "v의 사이즈 : " << v.size() << " " << "v의 capacity" << v.capacity() << endl;
	system("pause");
	return 0;
}