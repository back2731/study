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

	count = 0;

	for (int i = 0; i < 3; i++)
	{
		m_box[i].rc = RectMakeCenter(100 + i * 150, WINSIZEY / 2 - 200, 100, 100);
		m_box[i+3].rc = RectMakeCenter(100 + i * 150, WINSIZEY / 2, 100, 100);
		m_box[i+6].rc = RectMakeCenter(100 + i * 150, WINSIZEY / 2 + 200, 100, 100);

		m_box[i].isCheck = false;
		m_box[i+3].isCheck = false;
		m_box[i+6].isCheck = false;
		m_box[i].isJoker = false;
		m_box[i+3].isJoker = false;
		m_box[i+6].isJoker = false;
	}

	return S_OK;
}

void mainGame::release()
{
	gameNode::release();
}

void mainGame::update()
{
	gameNode::update();
	
	time++;

	if (KEYMANAGER->isOnceKeyDown(VK_LBUTTON))
	{
		for (int i = 0; i < BOX; i++)
		{
			if (PtInRect(&m_box[i].rc, m_ptMouse))
			{
				m_box[i].isJoker = false;
				count++;
			}
		}
	}

	int a = RND->getInt(BOX);
	if (time % 40 == 3)
	{
		m_box[a].isJoker = true;
	}
	if (time % 40 == 10)
	{
		m_box[a].isJoker = false;
	}
}

void mainGame::render(HDC hdc)
{

	wsprintf(str, "point : %d", count);
	TextOut(hdc, 10, 10, str, strlen(str));

	for (int i = 0; i < BOX; i++)
	{
		Rectangle(hdc, m_box[i].rc.left, m_box[i].rc.top, m_box[i].rc.right, m_box[i].rc.bottom);

		if (m_box[i].isJoker) // Á¶Ä¿
		{
			HBRUSH brush = CreateSolidBrush(RGB(255, 0, 0));
			Rectangle(hdc, m_box[i].rc.left, m_box[i].rc.top, m_box[i].rc.right, m_box[i].rc.bottom);
			FillRect(hdc, &m_box[i].rc, brush);
			DeleteObject(brush);
		}
	}
}
