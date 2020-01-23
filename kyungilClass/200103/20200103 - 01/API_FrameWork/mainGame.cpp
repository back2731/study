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

	for (int i = 0; i < BOX; i++)
	{
		m_box[i].rc = RectMakeCenter(100 + i * 150, WINSIZEY / 2 - 200, 100, 150);
		m_box[i].isCheck = false;
		m_box[i].isJoker = false;
	}
	m_box[RND->getInt(BOX)].isJoker = true;


	return S_OK;
}

void mainGame::release()
{
	gameNode::release();
}

void mainGame::update()
{
	gameNode::update();

	if (KEYMANAGER->isOnceKeyDown(VK_LBUTTON))
	{
		for (int i = 0; i < BOX; i++)
		{
			if (PtInRect(&m_box[i].rc, m_ptMouse))
			{
				m_box[i].isCheck = true;
			}
		}
	}

	for (int i = 0; i < BOX; i++)
	{
		if (m_box[i].isCheck && m_box[i].isJoker)
		{
			m_box[i].rc.top += 5;
			m_box[i].rc.bottom += 5;

			if (m_box[i].rc.top > WINSIZEY)
			{
				init();
			}
		}
	}

}

void mainGame::render(HDC hdc)
{
	for (int i = 0; i < BOX; i++)
	{
		Rectangle(hdc, m_box[i].rc.left, m_box[i].rc.top, m_box[i].rc.right, m_box[i].rc.bottom);

		if (m_box[i].isCheck && m_box[i].isJoker)		// 조커
		{
			HBRUSH brush = CreateSolidBrush(RGB(255, 0, 0));
			Rectangle(hdc, m_box[i].rc.left, m_box[i].rc.top, m_box[i].rc.right, m_box[i].rc.bottom);
			FillRect(hdc, &m_box[i].rc, brush);
			DeleteObject(brush);
		}
		else if (m_box[i].isCheck && !m_box[i].isJoker)		// 조커
		{
			HBRUSH brush = CreateSolidBrush(RGB(0, 0, 255));
			Rectangle(hdc, m_box[i].rc.left, m_box[i].rc.top, m_box[i].rc.right, m_box[i].rc.bottom);
			FillRect(hdc, &m_box[i].rc, brush);
			DeleteObject(brush);
		}
	}
}
