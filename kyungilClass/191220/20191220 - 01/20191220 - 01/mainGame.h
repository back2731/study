#pragma once
#include <iostream>

using namespace std;

/*
	템플릿 : 
	여러가지 함수 및 클래스를 찍어낼 수 있는 일종의 모형자다.
	함수나 클래스를 개별적으로 다시 작성하지 않아도 
	여러 자료형으로 사용할 수 있도록 만들어 놓은 녀석이다.

	ex) STL
*/

class mainGame
{
public:
	mainGame();
	~mainGame();

	template <typename T> // T 는 템플릿의 T
	// 아래에 있는 녀석을 템플릿화 하겠다. (여기서는 아웃풋 함수)
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
	인라인 함수
	실행은 일반 함수와 다르지 않다. 
	단, 함수의 코드를 그 자리에서 바로 실행한다.
	컴파일러가 함수를 사용하는 부분에 함수의 코드를 복제한다.
	속도가 좀 더 빠르기 때문에 자주 호출되거나 속도가 중요한 부분에 사용한다.

	단!!! 무분별하게 사용하면 실행파일 크기가 커진다.
*/

template<typename T>
inline void mainGame::output(T data)
{
	cout << "데이터 : " << data << endl;
}

// typename이 1개인 경우 : 데이터형이 동일하지 않은 경우 오류를 발생시킨다.
template<typename T>
inline void mainGame::output1(T a, T b)
{
	cout << "데이터 a : " << a << endl;
	cout << "데이터 b : " << b << endl;
}

template<typename T1, typename T2>
inline void mainGame::output2(T1 data1, T2 data2)
{
	cout << "데이터 1 : " << data1 << endl;
	cout << "데이터 2 : " << data2 << endl;
}

template<typename T1, typename T2>
inline void mainGame::output3(T1 data1, T2 data2)
{
	cout << data1 << data2 << endl;
}
