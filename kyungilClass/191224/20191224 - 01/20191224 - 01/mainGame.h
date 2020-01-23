#pragma once
#include <iostream>
#include <string>
#include <map>

using namespace std;
/*
	redblack tree

	key와 value값이 들어가있다.
	관련있는 데이터를 하나의 쌍으로 저장한다.

	맵 : 연관컨테이너중 하나이다.
	맵은 자료구조중 레드블랙트리로 구성되어 있다.
	맵은 자동적으로 정렬을 한다.

	연관컨테이너 : key, value처럼 관련있는 데이터를 하나의 쌍으로 저장하는 컨테이너다.

	요소들에 대한 빠른 접근을 제공한다.

	사용처 : 정렬해야 할때, 많은 자료를 저장하고 검색이 빨라야 할때
	빈번하게 삽입삭제를 필요로하지 않을때

	키와 값을 한 쌍으로 데이터를 저장한다. (한쌍 == pair)
	pair					: 두 객체를 하나의 객체로 취급 해준다.
	make_pair(데이터, 값)	: 데이터와 값을 pari 해준다.
	
	map<keyType, valueType> 변수 이름
*/
class mainGame
{
private:
	
	map<string, int> m_data;
	map<string, int>::iterator mi_data;

public:
	mainGame();
	~mainGame();
};

