#pragma once
#include <iostream>

using namespace std;

/*
	���ø� : 
	�������� �Լ� �� Ŭ������ �� �� �ִ� ������ �����ڴ�.
	�Լ��� Ŭ������ ���������� �ٽ� �ۼ����� �ʾƵ� 
	���� �ڷ������� ����� �� �ֵ��� ����� ���� �༮�̴�.

	ex) STL
*/

class mainGame
{
public:
	mainGame();
	~mainGame();

	template <typename T> // T �� ���ø��� T
	// �Ʒ��� �ִ� �༮�� ���ø�ȭ �ϰڴ�. (���⼭�� �ƿ�ǲ �Լ�)
	void output(T data);

	template <typename T>
	void output1(T a, T b);

	template <typename T1, typename T2>
	void output2(T1 data1, T2 data2);

	template <typename T1, typename T2>
	void output3(T1 data1, T2 data2);

};

/*
	inline :
	�ζ��� �Լ�
	������ �Ϲ� �Լ��� �ٸ��� �ʴ�. 
	��, �Լ��� �ڵ带 �� �ڸ����� �ٷ� �����Ѵ�.
	�����Ϸ��� �Լ��� ����ϴ� �κп� �Լ��� �ڵ带 �����Ѵ�.
	�ӵ��� �� �� ������ ������ ���� ȣ��ǰų� �ӵ��� �߿��� �κп� ����Ѵ�.

	��!!! ���к��ϰ� ����ϸ� �������� ũ�Ⱑ Ŀ����.
*/

template<typename T>
inline void mainGame::output(T data)
{
	cout << "������ : " << data << endl;
}

// typename�� 1���� ��� : ���������� �������� ���� ��� ������ �߻���Ų��.
template<typename T>
inline void mainGame::output1(T a, T b)
{
	cout << "������ a : " << a << endl;
	cout << "������ b : " << b << endl;
}

template<typename T1, typename T2>
inline void mainGame::output2(T1 data1, T2 data2)
{
	cout << "������ 1 : " << data1 << endl;
	cout << "������ 2 : " << data2 << endl;
}

template<typename T1, typename T2>
inline void mainGame::output3(T1 data1, T2 data2)
{
	cout << data1 << data2 << endl;
}
