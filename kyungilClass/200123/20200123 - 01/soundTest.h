#pragma once
#include"gameNode.h"
#define MUSICBOX 5
#define MUSICMAX 5

class soundTest :  public gameNode
{
private:
	int choiceMusic;
	int currentMusic;

	bool music;
	RECT musicBox[MUSICBOX];
	string musicName[5];

public:
	soundTest();
	~soundTest();

	HRESULT init();
	void release();
	void update();
	void render();

	void ChoiceMusic(string name, float volum);
};

