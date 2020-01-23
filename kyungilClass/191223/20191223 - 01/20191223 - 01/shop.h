#pragma once
#include "item.h"

class shop
{
private:

	// 아이템 구조체 벡터
	vector<tagItemInfo> m_vItem;
	vector<tagItemInfo>::iterator m_viItem;

public:
	shop();
	~shop();
	
	// 아이템 세팅
	void itemSetup();
	// 아이템 출력
	int itemOutput(int num);
	// 상점 아이템 구입
	tagItemInfo buyItem(int itemKind, int num, int &gold);
	// 상점에 아이템 추가
	void addItem(tagItemInfo item);

};

