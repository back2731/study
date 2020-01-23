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
	
	// ������ ���� ���� ������ ������ �޾ƿ´�. 0 ~ ������ ����
	inline int GetInt(int num) 
	{
		return rand() % num;
	}
	
	inline int GetFromIntTo(int fromNum, int toNum)
	{
		return rand() % (toNum - fromNum + 1) + fromNum;
	}


};
