#include "stdafx.h"
#include "mainGame.h"
mainGame::mainGame()
{
}
mainGame::~mainGame()
{
}
HRESULT mainGame::init()
{
	gameNode::init();

	m_radian = 1.0f;
	m_degree = 180.0f;
	
	return S_OK;
}

void mainGame::release()
{
	gameNode::release();
}

void mainGame::update()
{
	gameNode::update();
	
	
}

void mainGame::render(HDC hdc)
{
	
	char strRadian[128];
	char strDegree[128];

	//라디안을 디그리로
	sprintf_s(strRadian, "%.2f 라디안 값은 %.2f 디그리 값과 같다.", m_radian, m_radian *(180 / PI));
	TextOut(hdc, 100, 300, strRadian, strlen(strRadian));

	//디그리를 라디안으로
	sprintf_s(strDegree, "%.2f 디그리 값은 %.2f 라디안 값과 같다.", m_degree, m_degree *(PI / 180));
	TextOut(hdc, 100, 500, strDegree, strlen(strDegree));
}

