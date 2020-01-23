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
	/*
		DC : device context(����̽� ���ؽ�Ʈ)
		-> ��¿� ���� �ɼ��� ����Ʈ�� ����.
		DC������ϱ� ���� HDC, DC�� �ڵ��� �̿��Ѵ�.
		GDI��⿡ ���� �����ȴ�.
		GDIȭ�� ó���� �׷��� ����� �Ѵ�.
		HDC : ��¿� �ʿ��� ������ ������ ������ ����ü.
		��ǥ, ����, �� ��� ��¿� �ʿ��� ��� ������ ����ִ�.
	*/

	// PAINTSTRUCT : ������ Ŭ���̾�Ʈ ������ �׸��� ���� ������ ���� ����ü

	HDC hdc;
	PAINTSTRUCT ps;

	switch (iMessage)
	{

	case WM_CREATE:		// �����찡 ���۵� �� �� �ѹ��� ����ȴ�.
		break;
	case WM_PAINT:		// �������� �۾������� �սǵǾ����� ����ȴ�. �׸��°�
		hdc = BeginPaint(hWnd, &ps);

		//// �ȼ�����
		//SetPixel(hdc, 200, 200, RGB(255, 0, 0));
		//SetPixel(hdc, 200, 201, RGB(255, 0, 0));
		//SetPixel(hdc, 200, 202, RGB(255, 0, 0));
		//SetPixel(hdc, 200, 203, RGB(255, 0, 0));
		//SetPixel(hdc, 200, 204, RGB(255, 0, 0));
		//SetPixel(hdc, 200, 205, RGB(255, 0, 0));

		// ���� ������
		// ��
		MoveToEx(hdc, 100, 100, nullptr);
		LineTo(hdc, 100, 200);

		MoveToEx(hdc, 200, 100, nullptr);
		LineTo(hdc, 200, 200);

		MoveToEx(hdc, 100, 150, nullptr);
		LineTo(hdc, 200, 150);

		MoveToEx(hdc, 100, 200, nullptr);
		LineTo(hdc, 200, 200);

		MoveToEx(hdc, 100, 200, nullptr);
		LineTo(hdc, 200, 200);

		// ��
		MoveToEx(hdc, 250, 100, nullptr);
		LineTo(hdc, 250, 200);

		MoveToEx(hdc, 300, 100, nullptr);
		LineTo(hdc, 300, 200);

		MoveToEx(hdc, 250, 150, nullptr);
		LineTo(hdc, 300, 150);

		// ��
		MoveToEx(hdc, 150, 250, nullptr);
		LineTo(hdc, 280, 250);

		MoveToEx(hdc, 280, 250, nullptr);
		LineTo(hdc, 280, 350);

		//��
		MoveToEx(hdc, 350, 100, nullptr);
		LineTo(hdc, 450, 100);

		MoveToEx(hdc, 450, 100, nullptr);
		LineTo(hdc, 350, 200);

		//��
		MoveToEx(hdc, 420, 130, nullptr);
		LineTo(hdc, 500, 130);

		MoveToEx(hdc, 390, 160, nullptr);
		LineTo(hdc, 500, 160);

		MoveToEx(hdc, 500, 100, nullptr);
		LineTo(hdc, 500, 200);

		//��
		Ellipse(hdc, 400, 220, 500, 320);
		// left top right bottom


		//��
		MoveToEx(hdc, 550, 100, nullptr);
		LineTo(hdc, 700, 100);

		MoveToEx(hdc, 700, 100, nullptr);
		LineTo(hdc, 550, 200);

		MoveToEx(hdc, 625, 150, nullptr);
		LineTo(hdc, 700, 200);

		//��

		MoveToEx(hdc, 540, 220, nullptr);
		LineTo(hdc, 710, 220);

		MoveToEx(hdc, 625, 220, nullptr);
		LineTo(hdc, 625, 270);

		// ��
		MoveToEx(hdc, 580, 240, nullptr);
		LineTo(hdc, 580, 330);
		MoveToEx(hdc, 580, 330, nullptr);
		LineTo(hdc, 700, 330);

		//SetTextColor(hdc, RGB(10, 200, 30));
		//TextOut(hdc, 400, 400, "�ȳ��ϼ���.", strlen("�ȳ��ϼ���."));

		//SetTextColor(hdc, RGB(10, 200, 255));
		//TextOut(hdc, 200, 200, "�ȳ�", strlen("�ȳ�"));
		//EndPaint(hWnd, &ps);
		//break;

	//case WM_LBUTTONDOWN:	// ���� ��ư Ŭ������ ��
	//	hdc = GetDC(hWnd);

	//	SetTextColor(hdc, RGB(0, 2, 255));
	//	TextOut(hdc, 100, 100, "����", strlen("����"));


	//	ReleaseDC(hWnd, hdc);
	//	break;
	case WM_LBUTTONUP:		// ��Ŭ��
		break;
		//case WM_TIMER:
		//	break;
		//case WM_KEYDOWN:
		//	break;
		//case WM_KEYUP:
		//	break;
		//case WM_MBUTTONDOWN:	// ��
		//	break;
	case WM_DESTROY:	// �����찡 ����� �� �� �ѹ��� ����ȴ�.
		PostQuitMessage(0);
		break;
		return 0;
	}
	return(DefWindowProc(hWnd, iMessage, wPram, lPram));
}
