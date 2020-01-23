#pragma once
#include"gameNode.h"
/*
	�ﰢ�Լ�  : ������ �̿��Ҷ� �ʿ��ϴ�.
	-������ �˰��ִٸ�->������ �Ÿ��� �˰��ִ�.
	��ǥ�������� ���������� ����.(end-start = ���������� �Ÿ�)
	-�� ������ �̿��ؼ� ��(x,y)������ ���̷��� ���Ѵ�.(deltaX, deltaY)

	-�밢���� �Ÿ��� ���Ѵ�.
	distnace = sqrt�Ǵ� sqrtf(deltaX* deltaX+ deltaY* deltaY)

	-���� ���Ѵ�.
	 angle =  acos(deltaX /distance)

	 -������ ���� ���̷��� ���Ѵ�.

	 deltaX =  cos(radian) * distance(�̵���)
	 deltaY =  -sin(radian) * distance(�̵���)

	 x�� ��ǥ ���ϱ�
	 x= cos(���� * PI/180)*�ӵ�

	 Y�� ��ǥ ���ϱ�
	 Y= -sin(���� * PI/180)*�ӵ�

	 PI�� ���� ����180��

	 180 degree =  PI radian

	 1 degree =  PI/180 radian

	 x degree =  180 / PI degree

	 1 radian =  57.3��


*/
#define PI 3.141592653
class mainGame :  public gameNode
{
private:

	float m_radian;
	float m_degree;

public:
	mainGame();
	~mainGame();

	virtual HRESULT init();	//�ʱ�ȭ
	virtual void release();//����
	virtual void update();//�����ϴ°�
	virtual void render(HDC hdc);//�׸��°�



};

