#include "stdafx.h"
#include "soundTest.h"


soundTest::soundTest()
{
}


soundTest::~soundTest()
{
}

HRESULT soundTest::init()
{
	SOUNDMANAGER->addSound("snow_flower", "sound/snow_flower.mp3", true, true);
	SOUNDMANAGER->addSound("체리", "sound/체리.mp3", true, true);
	SOUNDMANAGER->addSound("A", "sound/A.mp3", true, true);
	SOUNDMANAGER->addSound("B", "sound/B.mp3", true, true);
	SOUNDMANAGER->addSound("C", "sound/C.mp3", true, true);

	for (int i = 0; i < MUSICMAX; i++)
	{
		musicBox[i] = RectMake(200 , 100 + i * 30, 200, 20);
	}

	musicName[0] = "snow_flower";
	musicName[1] = "체리";
	musicName[2] = "A";
	musicName[3] = "B";
	musicName[4] = "C";
	
	return S_OK;
}

void soundTest::release()
{
}

void soundTest::update()
{
	for (int i = 0; i < MUSICBOX; i++)
	{	
		if (PtInRect(&musicBox[i], m_ptMouse))
		{
			if (KEYMANAGER->isOnceKeyDown(VK_LBUTTON))
			{
				choiceMusic = i;
				for (int j = 0; j < MUSICMAX; j++)
				{
					SOUNDMANAGER->stop(musicName[j]);
				}
			}
		}
	}

	ChoiceMusic(musicName[choiceMusic], 0.5f);			
}

void soundTest::render()
{
	for (int i = 0; i < MUSICBOX; i++)
	{
		Rectangle(getMemDC(), musicBox[i].left, musicBox[i].top, musicBox[i].right, musicBox[i].bottom);
	}
}

void soundTest::ChoiceMusic(string name, float volum)
{
	if (KEYMANAGER->isOnceKeyDown(VK_SPACE))
	{
		SOUNDMANAGER->play(name, volum);
	}
	if (KEYMANAGER->isOnceKeyDown(VK_UP))
	{
		SOUNDMANAGER->sound(0.1f);
	}
	if (KEYMANAGER->isOnceKeyDown(VK_DOWN))
	{
		SOUNDMANAGER->sound(-0.1f);
	}
	if (KEYMANAGER->isOnceKeyDown('S'))
	{
		SOUNDMANAGER->stop(name);
	}
	if (KEYMANAGER->isOnceKeyDown('T'))
	{
		SOUNDMANAGER->resume(name);
	}
	if (KEYMANAGER->isOnceKeyDown('P'))
	{
		SOUNDMANAGER->pause(name);
	}
}
