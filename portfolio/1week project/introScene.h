#pragma once
#include"gameNode.h"
class introScene : public gameNode
{
private:
	image*	introText;
	int		frameCount;
	int		frameIndex;
public:
	introScene();
	~introScene();

	HRESULT init();
	void release();
	void update();
	void render();

};

