#pragma once
// =================================================
// ## singletonBase(�̱��� ���� - �̱����� �����.) ##
// =================================================

/*
	�̱��� ������ static member�� �ϳ��� �ν��Ͻ��� �����ȴ�.
	���α׷� �ȿ��� ���������� ������ �����ϴ�.
	
	���������� �����ص� �ϳ��� �ν��Ͻ��� �����Ҽ� �ֱ� ������,
	�̱��� ������ ����ϸ� Ŭ���� �ڽ��� �ڱ��� ������ �ν��Ͻ���
	�����ϴ� ����� ĸ��ȭ �Ͽ� ������ �� �ִ�.
	���� ���, ��ü���� �� �Ҹ�, �ν��Ͻ��� ���� ���� ���. Ȱ�뿡 �����ϴ�.
	
	�ڱ� �����ΰ� �ڱ��� ������ �ν��Ͻ��� �����ϴ� �����
	��ü������ �����ϴ� ���� ����.

	�̱����� �ٸ� �ν��Ͻ��� �������� �ʵ��� ó���� �� �ְ�
	���� ��� ���� ������ �Ѽ� �ִ�.
*/

template <typename T>


class singletonBase
{
protected:

	static T* singleton;

	singletonBase() {};
	~singletonBase() {};

public:
	static T* getSingleton();
	void releaseSingleton();

};

// �̱��� �ν��Ͻ� ����
template <typename T>
T* singletonBase<T>::singleton = nullptr;

// �̱��� ��ü�� ��������
template <typename T>
T* singletonBase<T>::getSingleton()
{
	// �̱��� ��ü�� ������ ���� ������.
	if (!singleton) singleton = new T;

	return singleton;
}

template <typename T>
void singletonBase<T>::releaseSingleton()
{
	// �̱����� ������ ����
	if (singleton)
	{
		delete singleton;
		singleton = nullptr;
	}
}

