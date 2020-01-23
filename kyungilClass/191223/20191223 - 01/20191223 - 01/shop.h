#pragma once
#include "item.h"

class shop
{
private:

	// ������ ����ü ����
	vector<tagItemInfo> m_vItem;
	vector<tagItemInfo>::iterator m_viItem;

public:
	shop();
	~shop();
	
	// ������ ����
	void itemSetup();
	// ������ ���
	int itemOutput(int num);
	// ���� ������ ����
	tagItemInfo buyItem(int itemKind, int num, int &gold);
	// ������ ������ �߰�
	void addItem(tagItemInfo item);

};

