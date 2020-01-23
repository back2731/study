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
	/*
		InvaildateRect
		�������� �Ϻκ��� ��ȿȭ �����ش�
		����ڰ� InvaildateRect�� ���ؼ� ��������
		�Ϻκ��� ��ȿȭ ���״ٸ�, �����쿡 �߻��Ǵ�
		WM_PAINT�޽����� ���� ��ȿȭ�� �κ��� 
		�ٽ� �׷��ش�.
	*/

	HDC hdc;
	PAINTSTRUCT ps;

	char str[128];
	static int num = 0;

	switch (iMessage)
	{

	case WM_CREATE:		// �����찡 ���۵� �� �� �ѹ��� ����ȴ�.
		break;
	case WM_PAINT:		// �������� �۾������� �սǵǾ����� ����ȴ�. �׸��°�
		hdc = BeginPaint(hWnd, &ps);

		for (int i = 1; i < 10; i += 3)
		{
			for (int j = 1; j < 10; j++)
			{
				if (num >= i) // 1, 4, 7
				{
					wsprintf(str, "%d * %d = %d", i, j, i * j);

					// j * 20 = ���� Y�� ����, 250 = �� ���� Y�� ����
					TextOut(hdc, 100, 10 + j * 20 + ((i - 1) / 3) * 250, str, strlen(str));
				}
				if (num >= i + 1) // 2, 5, 8
				{
					wsprintf(str, "%d * %d = %d", (i + 1), j, (i + 1) * j);
					TextOut(hdc, 300, 10 + j * 20 + ((i - 1) / 3) * 250, str, strlen(str));
				}
				if (num >= i + 2) // 3, 6, 9
				{
					wsprintf(str, "%d * %d = %d", (i + 2), j, (i + 2) * j);
					TextOut(hdc, 500, 10 + j * 20 + ((i - 1) / 3) * 250, str, strlen(str));
				}
			}
		}
		EndPaint(hWnd, &ps);
		break;
	case WM_LBUTTONDOWN:		// ��Ŭ��
		num++;
		if (num > 9) num = 9;
		InvalidateRect(hWnd, NULL, true);
		break;
	case WM_RBUTTONDOWN:
		num--;
		if (num < 0)num = 0;
		InvalidateRect(hWnd, NULL, true);
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
