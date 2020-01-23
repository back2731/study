#pragma once
#include "gameNode.h"
class progressBar : public gameNode
{
private:

	RECT _rcProgress;			// 체력바 렉트
	int _x;
	int _y;
	int _width;					// 가로 길이(이녀석으로 조정한다)

	image* _progressBarFront;	// 체력바 앞 이미지
	image* _progressBarBack;	// 체력바 뒤 이미지

public:
	progressBar();
	~progressBar();

	HRESULT init(char* frontImage, char* backImage, float x, float y, int width, int height);
	void release();
	void update();
	void render();

	// 게이지 셋팅
	void setGauge(float currentGauge, float maxGauge);

	void setX(int x) { _x = x; }
	void setY(int y) { _y = y; }

	RECT getRect() { return _rcProgress; }

};

