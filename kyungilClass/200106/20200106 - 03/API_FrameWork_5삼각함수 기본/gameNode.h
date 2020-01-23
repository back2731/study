#pragma once
#include "Image.h"
class gameNode
{
	/*
		������۸� : ��������� ȭ���� ������ ���� hdc�� �Ѹ��� ����̴�.
		�����̳� ��Ʈ���� Ŀ���� ���ϰ� Ŀ����.
		��, �����Ÿ��� ������ �߻��ȴ�.
		�޸� ������ ���(ȭ�鿡 ������ �ʴ� ���)�� �� �����ٴ� ���� �̿��Ͽ�
		�޸𸮿� ��� ����� ������ �Ѹ� ������ hdc�� �ű�� ����� ��������̴�.
	*/

private:
	Image* _backBuffer;			// �����
	void SetBackBuffer();		// ����� ����

public:
	gameNode();
	~gameNode();

	virtual HRESULT init();
	virtual void release();
	virtual void update();
	virtual void render(HDC hdc);

	// ����� ��������
	Image* GetBackBuffer() { return _backBuffer; }

	LRESULT MainProc(HWND hWnd, UINT iMessage, WPARAM wParam, LPARAM lParam);

};

