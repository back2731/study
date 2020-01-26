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
	IMAGEMANAGER->addImage("play", "images/play.bmp", 100, 100, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("pause", "images/pause.bmp", 100, 100, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("stop", "images/stop.bmp", 100, 100, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("nextMusic", "images/nextMusic.bmp", 100, 100, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("beforeMusic", "images/beforeMusic.bmp", 100, 100, true, RGB(255, 0, 255));

	IMAGEMANAGER->addImage("Snow Flower", "images/Snow Flower.bmp", 250, 200, false, RGB(0, 0, 0));
	IMAGEMANAGER->addImage("시대를 초월한 마음", "images/시대를 초월한 마음.bmp", 250, 200, false, RGB(0, 0, 0));
	IMAGEMANAGER->addImage("나의 마음을 담아", "images/나의 마음을 담아.bmp", 250, 200, false, RGB(0, 0, 0));
	IMAGEMANAGER->addImage("Flower Dance", "images/Flower Dance.bmp", 250, 200, false, RGB(0, 0, 0));
	IMAGEMANAGER->addImage("Smile", "images/Smile.bmp", 250, 200, true, RGB(0, 0, 0));

	SOUNDMANAGER->addSound("Snow Flower", "sound/Snow Flower.mp3", true, true);
	SOUNDMANAGER->addSound("시대를 초월한 마음", "sound/시대를 초월한 마음.mp3", true, true);
	SOUNDMANAGER->addSound("나의 마음을 담아", "sound/나의 마음을 담아.mp3", true, true);
	SOUNDMANAGER->addSound("Flower Dance", "sound/Flower Dance.mp3", true, true);
	SOUNDMANAGER->addSound("Smile", "sound/Smile.mp3", true, true);

	for (int i = 0; i < MUSICMAX; i++)
	{
		musicBox[i] = RectMake(0, 50 + i * 30, 400, 20);
	}

	play = RectMakeCenter(WINSIZEX / 2, WINSIZEY - 100, 100, 100);
	stop = RectMakeCenter(WINSIZEX / 2, WINSIZEY - 100, 100, 100);
	pause = RectMakeCenter(WINSIZEX / 2, WINSIZEY - 100, 100, 100);
	beforeMusic = RectMakeCenter(WINSIZEX / 2 - 125, WINSIZEY - 100, 100, 100);
	nextMusic = RectMakeCenter(WINSIZEX / 2 + 125, WINSIZEY - 100, 100, 100);
	album = RectMakeCenter(WINSIZEX / 2 - 25, WINSIZEY / 2 - 90, 200, 200);;

	musicName[0] = "Snow Flower";
	musicName[1] = "시대를 초월한 마음";
	musicName[2] = "나의 마음을 담아";
	musicName[3] = "Flower Dance";
	musicName[4] = "Smile";

	musicImage[0] = "Snow Flower";
	musicImage[1] = "시대를 초월한 마음";
	musicImage[2] = "나의 마음을 담아";
	musicImage[3] = "Flower Dance";
	musicImage[4] = "Smile";

	currentMusic = 0;
	checkState = 0;
	volume = 0.5f;
	return S_OK;
}

void soundTest::release()
{
}

void soundTest::update()
{
	if (KEYMANAGER->isOnceKeyDown(VK_LBUTTON))
	{
		if (PtInRect(&play, m_ptMouse) && checkState == 0)
		{
			SOUNDMANAGER->play(musicName[currentMusic], volume);
			checkState = 1;
		}
		else if (PtInRect(&play, m_ptMouse) && checkState == 1)
		{
			SOUNDMANAGER->pause(musicName[currentMusic]);
			checkState = 2;
		}
		else if (PtInRect(&play, m_ptMouse) && checkState == 2)
		{
			SOUNDMANAGER->resume(musicName[currentMusic]);
			checkState = 1;
		}

		if (PtInRect(&beforeMusic, m_ptMouse))
		{
			SOUNDMANAGER->stop(musicName[currentMusic]);
			currentMusic = (currentMusic - 1) % 5;
			if (currentMusic == -1)
			{
				currentMusic = 4;
			}
			checkState = 1;
			SOUNDMANAGER->play(musicName[currentMusic], volume);
		}

		if (PtInRect(&nextMusic, m_ptMouse))
		{
			SOUNDMANAGER->stop(musicName[currentMusic]);
			currentMusic = (currentMusic + 1) % 5;
			checkState = 1;
			SOUNDMANAGER->play(musicName[currentMusic], volume);
		}
	}

	if (KEYMANAGER->isOnceKeyDown(VK_UP))
	{
		if (SOUNDMANAGER->getcurrentVolume() < 0.95f)
		{
			SOUNDMANAGER->sound(0.01f);
		}
	}

	if (KEYMANAGER->isOnceKeyDown(VK_DOWN))
	{
		if (SOUNDMANAGER->getcurrentVolume() > 0.05f)
		{
			SOUNDMANAGER->sound(-0.01);
		}
	}
}

void soundTest::render()
{
	if (KEYMANAGER->isToggleKey(VK_TAB))
	{
		//for (int i = 0; i < MUSICBOX; i++)
		//{
		//	Rectangle(getMemDC(), musicBox[i].left, musicBox[i].top, musicBox[i].right, musicBox[i].bottom);
		//}
		Rectangle(getMemDC(), play.left, play.top, play.right, play.bottom);
		Rectangle(getMemDC(), beforeMusic.left, beforeMusic.top, beforeMusic.right, beforeMusic.bottom);
		Rectangle(getMemDC(), nextMusic.left, nextMusic.top, nextMusic.right, nextMusic.bottom);
		Rectangle(getMemDC(), album.left, album.top, album.right, album.bottom);
	}

	if (checkState == 0)
	{
		IMAGEMANAGER->render("stop", getMemDC(), play.left, play.top);
	}
	else if (checkState == 1)
	{
		IMAGEMANAGER->render("pause", getMemDC(), play.left, play.top);
	}
	else
	{
		IMAGEMANAGER->render("play", getMemDC(), play.left, play.top);
	}

	IMAGEMANAGER->render("beforeMusic", getMemDC(), beforeMusic.left, beforeMusic.top);
	IMAGEMANAGER->render("nextMusic", getMemDC(), nextMusic.left, nextMusic.top);

	IMAGEMANAGER->render(musicImage[currentMusic], getMemDC(), album.left, album.top);

	SetBkColor(getMemDC(), RGB(0, 0, 0));
	SetTextColor(getMemDC(), RGB(255, 255, 255));
	sprintf_s((str), "Volume : %f", SOUNDMANAGER->getcurrentVolume());
	TextOut(getMemDC() , WINSIZEX / 2 - 50, WINSIZEY - 20, str, strlen(str));

}

void soundTest::ChoiceMusic(string name, float volum)
{
	// checkState : 0 == 재생버튼 1 == 일시정지버튼 2 == 재시작 버튼
	if (PtInRect(&play, m_ptMouse) && checkState == 0)
	{
		SOUNDMANAGER->play(name, volum);
		checkState = 1;
	}
	if (PtInRect(&nextMusic, m_ptMouse))
	{
		SOUNDMANAGER->play(name, volum);
	}

	//음량조절

}
