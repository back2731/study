#include <Windows.h>

// �ν��Ͻ� : �޸𸮻� �Ҵ�Ǿ� �������� ���α׷�
// �� OS�� Ȯ���ϱ� ���� ��.
HINSTANCE m_hInstance;

// ������ �ڵ�
// ��󳢸� �����ϱ� ���� ����Ѵ�.
HWND m_hWnd;

// ������ Ŭ���� �̸�(������ â ���� �ߴ� �̸�)	
LPTSTR m_lpszClass = TEXT("���� ���α׷��� 18��");

//
LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);

// hInstance		: �ν��Ͻ� �ڵ�
// hprevInstance	: ������ ����� �ν��Ͻ� �ڵ�
// lpszCmdParm		: ������� �Էµ� ���α׷� �μ�
// nCmdShow			: ���α׷��� ���۵� ����

/*
	WinMain�� ����
	1. ������â ���� �� ȭ�鿡 ����
	2. �޽��� ������ ���ƶ�.
*/ 
int APIENTRY WinMain(HINSTANCE hInstance, HINSTANCE hprevInstance, LPSTR lpszCmdParm, int nCmdShow)
{
	// ������API�� ũ�� WinMain�� Wndproc �� ���� �Լ��� �̷���� �ִ�.
	// Wndproc - ������ ���ν����� �����쿡�� �̷������ ������ �̾߱� �Ѵ�. ��, �޽����� ó���Ѵ�.

	m_hInstance = hInstance;

	// WNDCLASS		: ������ â�� ������ �����ϱ� ���� ����ü.
	// ������â ����ü ���� �� �ʱ�ȭ ����.
	WNDCLASS wndClass;

	// ������ Ŭ�������� ����ϰ��� �ϴ� ������ �޸𸮾��� byte������ �����Ѵ�.
	wndClass.cbClsExtra = 0;

	// cbClsExtra�� �����ϳ� ���� �����쿡�� ����ϰ��� �ϴ� ������ �޸𸮾��� �����Ѵ�.
	wndClass.cbWndExtra = 0;

	// ������ �۾������� ĥ�� ��� �귯��
	wndClass.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);

	// Ŀ������
	wndClass.hCursor = LoadCursor(NULL, IDC_ARROW);

	// Ÿ��Ʋ���� �»�ܿ� ������ �����ܰ� �����찡 �ּ�ȭ �Ǿ����� ������ �������� �����Ѵ�.
	wndClass.hIcon = LoadIcon(NULL, IDI_APPLICATION);

	// ������ Ŭ������ ����� �������α׷��� �ν��Ͻ� �ڵ�
	wndClass.hInstance = hInstance;

	// �޽����� ó���ϴ� �Լ��� ����(������ ���ν���).
	wndClass.lpfnWndProc = (WNDPROC)WndProc;

	// ����ϰ��� �ϴ� ������ Ŭ���� �̸�
	wndClass.lpszClassName = m_lpszClass;

	// Ŭ������ ���� ������� �����찡 ����� �޴��� ����
	wndClass.lpszMenuName = NULL;

	// ������ Ŭ������ ��Ÿ���� ����
	wndClass.style = CS_HREDRAW | CS_VREDRAW;

	// ������ Ŭ���� ���
	// ����� ������ Ŭ������ Ư���� �����ϴ� WNDCLASS����ü ����
	RegisterClass(&wndClass);

	m_hWnd = CreateWindow
	(
		m_lpszClass,			// Ŭ���� �̸�
		m_lpszClass,			// ������ Ÿ��Ʋ �̸�
		WS_OVERLAPPEDWINDOW,	// ������ ��Ÿ��
		100,					// ������ ȭ�� X��ǥ
		100,					// ������ ȭ�� Y��ǥ
		1024, 768,				// ������ ������ (����, ����)
		NULL,					// �θ� ������
		(HMENU)NULL,			// �޴��ڵ�
		hInstance,				// �ν��Ͻ�����
		NULL);
	
	// ȭ�鿡 ������ ��������
	ShowWindow(m_hWnd, nCmdShow);

	// MSG : �ü������ �߻��ϴ� �޽��� ������ �����ϱ� ���� ����ü
	MSG message;

	// TranslateMessage : Ű���� �Է� �޽��� ó���� ���
	// DispatchMessage  : ������ ���ν����� ���޵� �޽����� ���� �����쿡 �����Ѵ�.
	// getMessage		: ������
	while (GetMessage(&message, 0, 0, 0))
	{
		TranslateMessage(&message);
		DispatchMessage(&message);
	}

	return message.wParam;

}

// ������ ���ν���	: �޽����� �ü���� �����Ѵ�. ������ �ü���� ȣ���Ѵ�.
// hWnd				: �����찡 �߻��� �޽������� �����Ѵ�.
// iMessage			: �޽��� ���й�ȣ
// wParam			: unsigned int ���콺 ��ư�� ����, Ű���� ����Ű�� ���¸� �����Ѵ�.
// lParma			: unsigned long ���콺�� Ŭ����ǥ�� �����Ѵ�.
LRESULT CALLBACK WndProc(HWND hWnd, UINT iMessage, WPARAM wPram, LPARAM lPram)
{
	switch (iMessage)
	{
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
		return 0;
	}
	return(DefWindowProc(hWnd, iMessage, wPram, lPram));
}
