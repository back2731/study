#pragma once
#include <iostream>
#include <string>
#include <map>

using namespace std;
/*
	redblack tree

	key�� value���� ���ִ�.
	�����ִ� �����͸� �ϳ��� ������ �����Ѵ�.

	�� : ���������̳��� �ϳ��̴�.
	���� �ڷᱸ���� �����Ʈ���� �����Ǿ� �ִ�.
	���� �ڵ������� ������ �Ѵ�.

	���������̳� : key, valueó�� �����ִ� �����͸� �ϳ��� ������ �����ϴ� �����̳ʴ�.

	��ҵ鿡 ���� ���� ������ �����Ѵ�.

	���ó : �����ؾ� �Ҷ�, ���� �ڷḦ �����ϰ� �˻��� ����� �Ҷ�
	����ϰ� ���Ի����� �ʿ������ ������

	Ű�� ���� �� ������ �����͸� �����Ѵ�. (�ѽ� == pair)
	pair					: �� ��ü�� �ϳ��� ��ü�� ��� ���ش�.
	make_pair(������, ��)	: �����Ϳ� ���� pari ���ش�.
	
	map<keyType, valueType> ���� �̸�
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

