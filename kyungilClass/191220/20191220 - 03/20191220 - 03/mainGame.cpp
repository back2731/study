#include "mainGame.h"
/*
	�ݺ��� : iterator
	STL���� �ݺ��ڴ� �����Ϳ� ����ϰ� �����Ѵ�.
	�ݺ��ڴ� �����̳ʿ� ����� ���Ҹ� ��ȸ�ϸ鼭 �����ϴ� ����� �����Ѵ�.
	�������� ���� ���� ���Ұ� �ƴ϶� ���� ǥ���ϴ� �����̴�.
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
	cout << "���� ��" << endl;

	/*
		begin() - �迭�� 0��° �ε���
		insert(�迭�� ��ġ(�ε���), ��)
		insert(�迭�� ��ġ(�ε���), ����, ��)
	*/

	// ����
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
