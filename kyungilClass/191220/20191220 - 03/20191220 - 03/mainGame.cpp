#include "mainGame.h"
/*
	반복자 : iterator
	STL에서 반복자는 포인터와 비슷하게 동작한다.
	반복자는 컨테이너에 저장된 원소를 순회하면서 접근하는 방법을 제공한다.
	순차열의 뜻은 실제 원소가 아니라 끝을 표시하는 원소이다.
*/


mainGame::mainGame()
{
	for (int i = 0; i < 10; i++)
	{
		m_vNumber.push_back(i + 1);
	}

	for (int i = 0; i < m_vNumber.size(); i++)
	{
		cout << m_vNumber[i] << endl;
	}

	cout << "=======================================================" << endl;
	cout << "삽입 후" << endl;

	/*
		begin() - 배열의 0번째 인덱스
		insert(배열의 위치(인덱스), 값)
		insert(배열의 위치(인덱스), 갯수, 값)
	*/

	// 삽입
	m_vNumber.insert(m_vNumber.begin(), 20);

	m_vNumber.insert(m_vNumber.end() - 1, 3, 100);

	for (int i = 0; i < m_vNumber.size(); i++)
	{
		cout << m_vNumber[i] << endl;
	}
	cout << "=======================================================" << endl;
	
	for (m_viNumber = m_vNumber.begin(); m_viNumber != m_vNumber.end(); ++m_viNumber)
	{
		cout << *m_viNumber << endl;
	}
}

mainGame::~mainGame()
{
}
