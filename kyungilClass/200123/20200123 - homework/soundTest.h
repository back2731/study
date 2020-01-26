#pragma once
#include"gameNode.h"
#define MUSICBOX 5
#define MUSICMAX 5

class soundTest : public gameNode
{
private:
	int currentMusic;

	int checkState;
	float volume;

	RECT musicBox[MUSICBOX];
	string musicName[MUSICMAX];
	string musicImage[MUSICMAX];

	RECT play;
	RECT stop;
	RECT pause;
	RECT beforeMusic;
	RECT nextMusic;
	RECT album;

	char str[256];


public:
	soundTest();
	~soundTest();

	HRESULT init();
	void release();
	void update();
	void render();

	void ChoiceMusic(string name, float volum);
};

