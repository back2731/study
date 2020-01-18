#pragma once

#define PI			3.141592653
#define PI2			PI*2

#define PI_4		PI / 4
#define PI_8		PI / 8
#define PI_16		PI / 16
#define PI_32		PI / 32

#define ANGLE_0		0
#define ANGLE_30	PI / 6
#define ANGLE_60	PI / 3
#define ANGLE_90	PI / 2
#define ANGLE_120	PI / 3 * 2
#define ANGLE_150	PI / 6 * 5
#define ANGLE_180	PI
#define ANGLE_210	PI / 6 * 7
#define ANGLE_240	PI / 3 * 4
#define ANGLE_270	PI / 2 * 3
#define ANGLE_300	PI / 3 * 5
#define ANGLE_330	PI / 6 * 11

namespace UTIL
{
	//�Ÿ�
	float getDistance(float startX, float startY, float endX, float endY);

	float getAngle(float x1, float y1, float x2, float y2);
}