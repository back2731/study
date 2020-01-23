#pragma once
#include"gameNode.h"
#include"bullet.h"
#include"progressBar.h"
#define PLAYERSPEED 5

/*
	���� : ��������� ���� ������ ������ �ӵ��� ���ϵȴ�.
	class A�� a.h�� �ְ� class B�� b.h�� �ִµ�
	B�� A�� ����ϰ� A�� B�� ����� ��� ���谡 �߸��Ǿ��ٰ� �� �� �ִ�.
	�̷��� �ϸ� �����ϱ⵵ ����� ������ �����.

	A�� B�� �����͸� �˱� ���ؼ� �翬�� B�� ������ �˾ƾ� �ϰ�
	��, b.h�� ��Ŭ��� �ؾ��Ѵ�.
	������ B���� �̹� a.h�� ��Ŭ��� �ϰ� �ֱ⿡ B�� ����� A�� ��Ŭ����ϸ� ��ȣ ���� ������ �ȴ�.
	������ �ٲ��� ������ ��Ŭ��� �� �� ����.

	A���� B�� ��Ŭ��� �Ѵٰ� �� ��, ���� b.h�� �����Ǹ� ��Ŭ��� �κе� �� ������ �ޱ� ������
	������ ���� ������ ������ �ӵ��� ���ϵȴ�.
	�̰��� �ذ��ϱ� ���� ����� Ŭ���� ���漱���̴�.
	
	����
	�����Ϸ��� ������Ͽ� ������ ���ܵ� �����ϴ� ������Ͽ����� ���������� �̷������ �ʴ´�.
	��, ���� �ؾ� ���� : ���漱���� ����� ��� �� Ŭ���� ���� ��ü�� ������������ �����ؾ� �Ѵ�.
	���� ���������� �ƴ� ��ü�� ������ ��� ���漱���� Ư¡�� �� ��ü�� ũ�⸦ ��Ȯ�� �ľ��Ͽ� �Ҵ��� �����ش�.
	(�ش� Ŭ������ �ִٴ� ������ �˰� ����� �𸥴�.)
*/
// ��ȣ������ �� �Ŵ��� Ŭ���� ���漱��
class enemyManager;

class rocket :public gameNode
{
private:

	image * _player;
	
	missile* _missile;
	nuclear* _nuclear;
	RECT rc;

	// ���α׷�����
	progressBar* _hpBar;
	float _maxHp;
	float _currentHp;

	enemyManager* _em;		// �� �Ŵ��� Ŭ���� ����

public:
	rocket();
	~rocket();

	HRESULT init();
	void release();
	void update();
	void render();

	// �ҷ� ����
	void removeBullet(int arrNum);
	
	// �浹
	void collision();

	// �Ǳ�� �Լ�
	void hitDamage(float damage);

	// ��Ŭ���� ��������
	nuclear* getNuclear() { return _nuclear; }
	image* getRocketImage() { return _player; }


	void setEnemyMemoryLink(enemyManager* em) { _em = em; }
};

