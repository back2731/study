#pragma once
#include "singletonBase.h"
class randomFunction : public singletonBase<randomFunction>
{
public:
	randomFunction()
	{
		srand(GetTickCount());
	}
	~randomFunction()
	{

	}
	
	// 지정한 숫자 범위 내에서 난수를 받아온다. 0 ~ 지정한 숫자
	inline int GetInt(int num) 
	{
		return rand() % num;
	}
	
	inline int GetFromIntTo(int fromNum, int toNum)
	{
		return rand() % (toNum - fromNum + 1) + fromNum;
	}


};
