#pragma once
#include"gameNode.h"
/*
	삼각함수  : 각도를 이용할때 필요하다.
	-두점을 알고있다면->서로의 거리를 알고있다.
	목표지점에서 시작지점을 뺀다.(end-start = 두점사이의 거리)
	-위 공식을 이용해서 각(x,y)사이의 변이량을 구한다.(deltaX, deltaY)

	-대각선의 거리를 구한다.
	distnace = sqrt또는 sqrtf(deltaX* deltaX+ deltaY* deltaY)

	-각을 구한다.
	 angle =  acos(deltaX /distance)

	 -각도에 대한 변이량을 구한다.

	 deltaX =  cos(radian) * distance(이동량)
	 deltaY =  -sin(radian) * distance(이동량)

	 x축 좌표 구하기
	 x= cos(각도 * PI/180)*속도

	 Y축 좌표 구하기
	 Y= -sin(각도 * PI/180)*속도

	 PI의 라디안 값은180도

	 180 degree =  PI radian

	 1 degree =  PI/180 radian

	 x degree =  180 / PI degree

	 1 radian =  57.3도


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

	virtual HRESULT init();	//초기화
	virtual void release();//해제
	virtual void update();//연산하는곳
	virtual void render(HDC hdc);//그리는곳



};

