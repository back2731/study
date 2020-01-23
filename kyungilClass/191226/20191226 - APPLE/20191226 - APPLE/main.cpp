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

		int x;
		int y;
		// �ȼ�����

		// ���ĸ�
		y = 16;
		for (int x = 109; x < 112; x++)
		{
			SetPixel(hdc, x, y, RGB(98, 187, 71));
		}
		y++;
		for (int x = 106; x < 113; x++)
		{
			SetPixel(hdc, x, y, RGB(98, 187, 71));
		}
		y++;
		for (int x = 103; x < 114; x++)
		{
			SetPixel(hdc, x, y, RGB(98, 187, 71));
		}

		y++;
		for (int x = 101; x < 115; x++)
		{
			SetPixel(hdc, x, y, RGB(98, 187, 71));
		}
		y++;
		for (int x = 99; x < 115; x++)
		{
			SetPixel(hdc, x, y, RGB(98, 187, 71));
		}
		y++;
		for (int x = 97; x < 115; x++)
		{
			SetPixel(hdc, x, y, RGB(98, 187, 71));
		}

		y++;
		for (int x = 96; x < 115; x++)
		{
			SetPixel(hdc, x, y, RGB(98, 187, 71));
		}
		y++;
		for (int x = 95; x < 115; x++)
		{
			SetPixel(hdc, x, y, RGB(98, 187, 71));
		}
		y++;
		for (int x = 92; x < 115; x++)
		{
			SetPixel(hdc, x, y, RGB(98, 187, 71));
		}

		y++;
		for (int x = 91; x < 115; x++)
		{
			SetPixel(hdc, x, y, RGB(98, 187, 71));
		}
		y++;
		for (int x = 90; x < 115; x++)
		{
			SetPixel(hdc, x, y, RGB(98, 187, 71));
		}
		y++;
		for (int x = 89; x < 114; x++)
		{
			SetPixel(hdc, x, y, RGB(98, 187, 71));
		}

		y++;
		for (int x = 89; x < 113; x++)
		{
			SetPixel(hdc, x, y, RGB(98, 187, 71));
		}
		y++;
		for (int x = 88; x < 113; x++)
		{
			SetPixel(hdc, x, y, RGB(98, 187, 71));
		}
		y++;
		for (int x = 87; x < 113; x++)
		{
			SetPixel(hdc, x, y, RGB(98, 187, 71));
		}

		y++;
		for (int x = 86; x < 112; x++)
		{
			SetPixel(hdc, x, y, RGB(98, 187, 71));
		}
		y++;
		for (int x = 85; x < 112; x++)
		{
			SetPixel(hdc, x, y, RGB(98, 187, 71));
		}
		y++;
		for (int x = 84; x < 112; x++)
		{
			SetPixel(hdc, x, y, RGB(98, 187, 71));
		}

		y++;
		for (int x = 85; x < 111; x++)
		{
			SetPixel(hdc, x, y, RGB(98, 187, 71));
		}
		y++;
		for (int x = 84; x < 111; x++)
		{
			SetPixel(hdc, x, y, RGB(98, 187, 71));
		}
		y++;
		for (int x = 84; x < 110; x++)
		{
			SetPixel(hdc, x, y, RGB(98, 187, 71));
		}

		y++;
		for (int x = 83; x < 110; x++)
		{
			SetPixel(hdc, x, y, RGB(98, 187, 71));
		}
		y++;
		for (int x = 83; x < 109; x++)
		{
			SetPixel(hdc, x, y, RGB(98, 187, 71));
		}
		y++;
		for (int x = 82; x < 109; x++)
		{
			SetPixel(hdc, x, y, RGB(98, 187, 71));
		}

		y++;
		for (int x = 82; x < 109; x++)
		{
			SetPixel(hdc, x, y, RGB(98, 187, 71));
		}
		y++;
		for (int x = 82; x < 108; x++)
		{
			SetPixel(hdc, x, y, RGB(98, 187, 71));
		}
		y++;
		for (int x = 81; x < 107; x++)
		{
			SetPixel(hdc, x, y, RGB(98, 187, 71));
		}

		y++;
		for (int x = 81; x < 107; x++)
		{
			SetPixel(hdc, x, y, RGB(98, 187, 71));
		}
		y++;
		for (int x = 81; x < 106; x++)
		{
			SetPixel(hdc, x, y, RGB(98, 187, 71));
		}
		y++;
		for (int x = 80; x < 105; x++)
		{
			SetPixel(hdc, x, y, RGB(98, 187, 71));
		}

		y++;
		for (int x = 80; x < 104; x++)
		{
			SetPixel(hdc, x, y, RGB(98, 187, 71));
		}
		y++;
		for (int x = 80; x < 103; x++)
		{
			SetPixel(hdc, x, y, RGB(98, 187, 71));
		}
		y++;
		for (int x = 80; x < 102; x++)
		{
			SetPixel(hdc, x, y, RGB(98, 187, 71));
		}

		y++;
		for (int x = 80; x < 101; x++)
		{
			SetPixel(hdc, x, y, RGB(98, 187, 71));
		}
		y++;
		for (int x = 80; x < 100; x++)
		{
			SetPixel(hdc, x, y, RGB(98, 187, 71));
		}
		y++;
		for (int x = 80; x < 99; x++)
		{
			SetPixel(hdc, x, y, RGB(98, 187, 71));
		}

		y++;
		for (int x = 80; x < 97; x++)
		{
			SetPixel(hdc, x, y, RGB(98, 187, 71));
		}
		y++;
		for (int x = 80; x < 95; x++)
		{
			SetPixel(hdc, x, y, RGB(98, 187, 71));
		}
		y++;
		for (int x = 80; x < 93; x++)
		{
			SetPixel(hdc, x, y, RGB(98, 187, 71));
		}

		y++;
		for (int x = 80; x < 91; x++)
		{
			SetPixel(hdc, x, y, RGB(98, 187, 71));
		}
		y++;
		for (int x = 80; x < 88; x++)
		{
			SetPixel(hdc, x, y, RGB(98, 187, 71));
		}
		for (int x = 46; x < 60; x++)
		{
			SetPixel(hdc, x, y, RGB(98, 187, 71));
		}
		for (int x = 111; x < 125; x++)
		{
			SetPixel(hdc, x, y, RGB(98, 187, 71));
		}
		y++;
		for (int x = 80; x < 85; x++)
		{
			SetPixel(hdc, x, y, RGB(98, 187, 71));
		}
		for (int x = 42; x < 64; x++)
		{
			SetPixel(hdc, x, y, RGB(98, 187, 71));
		}
		for (int x = 106; x < 128; x++)
		{
			SetPixel(hdc, x, y, RGB(98, 187, 71));
		}

		y++;
		for (int x = 39; x < 68; x++)
		{
			SetPixel(hdc, x, y, RGB(98, 187, 71));
		}
		for (int x = 104; x < 131; x++)
		{
			SetPixel(hdc, x, y, RGB(98, 187, 71));
		}

		y++;
		for (int x = 37; x < 73; x++)
		{
			SetPixel(hdc, x, y, RGB(98, 187, 71));
		}
		for (int x = 101; x < 133; x++)
		{
			SetPixel(hdc, x, y, RGB(98, 187, 71));
		}

		y++;
		for (int x = 35; x < 75; x++)
		{
			SetPixel(hdc, x, y, RGB(98, 187, 71));
		}
		for (int x = 98; x < 137; x++)
		{
			SetPixel(hdc, x, y, RGB(98, 187, 71));
		}

		y++;
		for (int x = 33; x < 77; x++)
		{
			SetPixel(hdc, x, y, RGB(98, 187, 71));
		}
		for (int x = 96; x < 137; x++)
		{
			SetPixel(hdc, x, y, RGB(98, 187, 71));
		}

		y++;
		for (int x = 31; x < 80; x++)
		{
			SetPixel(hdc, x, y, RGB(98, 187, 71));
		}
		for (int x = 93; x < 139; x++)
		{
			SetPixel(hdc, x, y, RGB(98, 187, 71));
		}

		y++;
		for (int x = 30; x < 140; x++)
		{
			SetPixel(hdc, x, y, RGB(98, 187, 71));
		}

		y++;
		for (int x = 29; x < 142; x++)
		{
			SetPixel(hdc, x, y, RGB(98, 187, 71));
		}
		
		y++;
		for (int x = 28; x < 143; x++)
		{
			SetPixel(hdc, x, y, RGB(98, 187, 71));
		}

		y++;
		for (int x = 27; x < 144; x++)
		{
			SetPixel(hdc, x, y, RGB(98, 187, 71));
		}

		y++;
		for (int x = 26; x < 146; x++)
		{
			SetPixel(hdc, x, y, RGB(98, 187, 71));
		}

		y++;
		for (int x = 25; x < 147; x++)
		{
			SetPixel(hdc, x, y, RGB(98, 187, 71));
		}

		y++;
		for (int x = 24; x < 148; x++)
		{
			SetPixel(hdc, x, y, RGB(98, 187, 71));
		}

		y++;
		for (int x = 23; x < 149; x++)
		{
			SetPixel(hdc, x, y, RGB(98, 187, 71));
		}

		y++;
		for (int x = 22; x < 149; x++)
		{
			SetPixel(hdc, x, y, RGB(98, 187, 71));
		}

		y++;
		for (int x = 21; x < 147; x++)
		{
			SetPixel(hdc, x, y, RGB(98, 187, 71));
		}

		y++;
		for (int x = 20; x < 145; x++)
		{
			SetPixel(hdc, x, y, RGB(98, 187, 71));
		}

		y++;
		for (int x = 19; x < 144; x++)
		{
			SetPixel(hdc, x, y, RGB(120, 185, 65));
		}

		//////////////////////////

		y++;
		for (int x = 19; x < 143; x++)
		{
			SetPixel(hdc, x, y, RGB(252, 184, 39));
		}

		y++;
		for (int x = 19; x < 141; x++)
		{
			SetPixel(hdc, x, y, RGB(252, 184, 39));
		}

		y++;
		for (int x = 18; x < 140; x++)
		{
			SetPixel(hdc, x, y, RGB(252, 184, 39));
		}

		y++;
		for (int x = 18; x < 140; x++)
		{
			SetPixel(hdc, x, y, RGB(252, 184, 39));
		}

		y++;
		for (int x = 18; x < 139; x++)
		{
			SetPixel(hdc, x, y, RGB(252, 184, 39));
		}

		y++;
		for (int x = 17; x < 138; x++)
		{
			SetPixel(hdc, x, y, RGB(252, 184, 39));
		}

		y++;
		for (int x = 16; x < 137; x++)
		{
			SetPixel(hdc, x, y, RGB(252, 184, 39));
		}

		y++;
		for (int x = 15; x < 136; x++)
		{
			SetPixel(hdc, x, y, RGB(252, 184, 39));
		}

		y++;
		for (int x = 15; x < 135; x++)
		{
			SetPixel(hdc, x, y, RGB(252, 184, 39));
		}	

		y++;
		for (int x = 14; x < 134; x++)
		{
			SetPixel(hdc, x, y, RGB(252, 184, 39));
		}

		y++;
		for (int x = 14; x < 134; x++)
		{
			SetPixel(hdc, x, y, RGB(252, 184, 39));
		}

		y++;
		for (int x = 13; x < 133; x++)
		{
			SetPixel(hdc, x, y, RGB(252, 184, 39));
		}

		y++;
		for (int x = 13; x < 133; x++)
		{
			SetPixel(hdc, x, y, RGB(252, 184, 39));
		}

		y++;
		for (int x = 13; x < 133; x++)
		{
			SetPixel(hdc, x, y, RGB(252, 184, 39));
		}

		y++;
		for (int x = 12; x < 132; x++)
		{
			SetPixel(hdc, x, y, RGB(252, 184, 39));
		}

		y++;
		for (int x = 12; x < 132; x++)
		{
			SetPixel(hdc, x, y, RGB(252, 184, 39));
		}

		y++;
		for (int x = 12; x < 132; x++)
		{
			SetPixel(hdc, x, y, RGB(252, 184, 39));
		}

		y++;
		for (int x = 12; x < 132; x++)
		{
			SetPixel(hdc, x, y, RGB(252, 184, 39));
		}

		y++;
		for (int x = 12; x < 132; x++)
		{
			SetPixel(hdc, x, y, RGB(252, 184, 39));
		}

		y++;
		for (int x = 12; x < 132; x++)
		{
			SetPixel(hdc, x, y, RGB(252, 184, 39));
		}

		//////////////////////////////////////////////
		y++;
		for (int x = 12; x < 132; x++)
		{
			SetPixel(hdc, x, y, RGB(247, 148, 40));
		}

		y++;
		for (int x = 11; x < 132; x++)
		{
			SetPixel(hdc, x, y, RGB(244, 121, 30));
		}


		y++;
		for (int x = 11; x < 131; x++)
		{
			SetPixel(hdc, x, y, RGB(244, 121, 30));
		}
		
		y++;
		for (int x = 11; x < 131; x++)
		{
			SetPixel(hdc, x, y, RGB(244, 121, 30));
		}

		y++;
		for (int x = 11; x < 131; x++)
		{
			SetPixel(hdc, x, y, RGB(244, 121, 30));
		}

		y++;
		for (int x = 11; x < 131; x++)
		{
			SetPixel(hdc, x, y, RGB(244, 121, 30));
		}

		y++;
		for (int x = 11; x < 131; x++)
		{
			SetPixel(hdc, x, y, RGB(244, 121, 30));
		}

		y++;
		for (int x = 11; x < 131; x++)
		{
			SetPixel(hdc, x, y, RGB(244, 121, 30));
		}

		y++;
		for (int x = 11; x < 131; x++)
		{
			SetPixel(hdc, x, y, RGB(244, 121, 30));
		}	

		y++;
		for (int x = 11; x < 131; x++)
		{
			SetPixel(hdc, x, y, RGB(244, 121, 30));
		}

		y++;
		for (int x = 11; x < 131; x++)
		{
			SetPixel(hdc, x, y, RGB(244, 121, 30));
		}

		y++;
		for (int x = 11; x < 131; x++)
		{
			SetPixel(hdc, x, y, RGB(244, 121, 30));
		}

		y++;
		for (int x = 11; x < 132; x++)
		{
			SetPixel(hdc, x, y, RGB(244, 121, 30));
		}

		y++;
		for (int x = 11; x < 132; x++)
		{
			SetPixel(hdc, x, y, RGB(244, 121, 30));
		}

		y++;
		for (int x = 11; x < 132; x++)
		{
			SetPixel(hdc, x, y, RGB(244, 121, 30));
		}

		y++;
		for (int x = 11; x < 132; x++)
		{
			SetPixel(hdc, x, y, RGB(244, 121, 30));
		}

		y++;
		for (int x = 11; x < 132; x++)
		{
			SetPixel(hdc, x, y, RGB(244, 121, 30));
		}


		y++;
		for (int x = 11; x < 133; x++)
		{
			SetPixel(hdc, x, y, RGB(244, 121, 30));
		}

		y++;
		for (int x = 12; x < 133; x++)
		{
			SetPixel(hdc, x, y, RGB(244, 121, 30));
		}

		y++;
		for (int x = 12; x < 134; x++)
		{
			SetPixel(hdc, x, y, RGB(244, 121, 30));
		}

		y++;
		for (int x = 12; x < 134; x++)
		{
			SetPixel(hdc, x, y, RGB(248, 142, 28));
		}

		y++;
		for (int x = 12; x < 134; x++)
		{
			SetPixel(hdc, x, y, RGB(233, 90, 47));
		}
		
		//////////////////////////////

		y++;
		for (int x = 12; x < 135; x++)
		{
			SetPixel(hdc, x, y, RGB(220, 46, 65));
		}

		y++;
		for (int x = 12; x < 136; x++)
		{
			SetPixel(hdc, x, y, RGB(220, 46, 65));
		}

		y++;
		for (int x = 12; x < 136; x++)
		{
			SetPixel(hdc, x, y, RGB(220, 46, 65));
		}

		y++;
		for (int x = 13; x < 137; x++)
		{
			SetPixel(hdc, x, y, RGB(220, 46, 65));
		}

		y++;
		for (int x = 13; x < 137; x++)
		{
			SetPixel(hdc, x, y, RGB(220, 46, 65));
		}

		y++;
		for (int x = 13; x < 138; x++)
		{
			SetPixel(hdc, x, y, RGB(220, 46, 65));
		}

		y++;
		for (int x = 13; x < 139; x++)
		{
			SetPixel(hdc, x, y, RGB(220, 46, 65));
		}

		y++;
		for (int x = 13; x < 139; x++)
		{
			SetPixel(hdc, x, y, RGB(220, 46, 65));
		}

		y++;
		for (int x = 14; x < 140; x++)
		{
			SetPixel(hdc, x, y, RGB(220, 46, 65));
		}

		y++;
		for (int x = 15; x < 142; x++)
		{
			SetPixel(hdc, x, y, RGB(220, 46, 65));
		}

		y++;
		for (int x = 15; x < 143; x++)
		{
			SetPixel(hdc, x, y, RGB(220, 46, 65));
		}

		y++;
		for (int x = 15; x < 144; x++)
		{
			SetPixel(hdc, x, y, RGB(220, 46, 65));
		}

		y++;
		for (int x = 16; x < 145; x++)
		{
			SetPixel(hdc, x, y, RGB(220, 46, 65));
		}

		y++;
		for (int x = 16; x < 146; x++)
		{
			SetPixel(hdc, x, y, RGB(220, 46, 65));
		}

		y++;
		for (int x = 16; x < 148; x++)
		{
			SetPixel(hdc, x, y, RGB(220, 46, 65));
		}

		y++;
		for (int x = 17; x < 149; x++)
		{
			SetPixel(hdc, x, y, RGB(220, 46, 65));
		}

		y++;
		for (int x = 17; x < 151; x++)
		{
			SetPixel(hdc, x, y, RGB(220, 46, 65));
		}

		y++;
		for (int x = 17; x < 153; x++)
		{
			SetPixel(hdc, x, y, RGB(220, 46, 65));
		}

		y++;
		for (int x = 18; x < 155; x++)
		{
			SetPixel(hdc, x, y, RGB(237, 57, 45));
		}

		y++;
		for (int x = 18; x < 155; x++)
		{
			SetPixel(hdc, x, y, RGB(194, 59, 97));
		}

		y++;
		for (int x = 19; x < 154; x++)
		{
			SetPixel(hdc, x, y, RGB(138, 62, 166));
		}

		y++;
		for (int x = 19; x < 153; x++)
		{
			SetPixel(hdc, x, y, RGB(149, 61, 149));
		}

		y++;
		for (int x = 19; x < 153; x++)
		{
			SetPixel(hdc, x, y, RGB(149, 61, 149));
		}

		y++;
		for (int x = 20; x < 152; x++)
		{
			SetPixel(hdc, x, y, RGB(149, 61, 149));
		}

		y++;
		for (int x = 20; x < 152; x++)
		{
			SetPixel(hdc, x, y, RGB(149, 61, 149));
		}

		y++;
		for (int x = 20; x < 152; x++)
		{
			SetPixel(hdc, x, y, RGB(149, 61, 149));
		}

		y++;
		for (int x = 21; x < 151; x++)
		{
			SetPixel(hdc, x, y, RGB(149, 61, 149));
		}

		y++;
		for (int x = 21; x < 151; x++)
		{
			SetPixel(hdc, x, y, RGB(149, 61, 149));
		}

		y++;
		for (int x = 22; x < 150; x++)
		{
			SetPixel(hdc, x, y, RGB(149, 61, 149));
		}

		y++;
		for (int x = 22; x < 150; x++)
		{
			SetPixel(hdc, x, y, RGB(149, 61, 149));
		}

		y++;
		for (int x = 22; x < 149; x++)
		{
			SetPixel(hdc, x, y, RGB(149, 61, 149));
		}

		y++;
		for (int x = 23; x < 149; x++)
		{
			SetPixel(hdc, x, y, RGB(149, 61, 149));
		}

		y++;
		for (int x = 23; x < 148; x++)
		{
			SetPixel(hdc, x, y, RGB(149, 61, 149));
		}

		y++;
		for (int x = 24; x < 148; x++)
		{
			SetPixel(hdc, x, y, RGB(149, 61, 149));
		}

		y++;
		for (int x = 24; x < 147; x++)
		{
			SetPixel(hdc, x, y, RGB(149, 61, 149));
		}
		
		y++;
		for (int x = 24; x < 147; x++)
		{
			SetPixel(hdc, x, y, RGB(149, 61, 149));
		}

		y++;
		for (int x = 26	; x < 146; x++)
		{
			SetPixel(hdc, x, y, RGB(149, 61, 149));
		}

		y++;
		for (int x = 27; x < 145; x++)
		{
			SetPixel(hdc, x, y, RGB(149, 61, 149));
		}

		y++;
		for (int x = 27; x < 144; x++)
		{
			SetPixel(hdc, x, y, RGB(149, 61, 149));
		}

		y++;
		for (int x = 28; x < 144; x++)
		{
			SetPixel(hdc, x, y, RGB(168, 48, 140));
		}

		y++;
		for (int x = 29; x < 143; x++)
		{
			SetPixel(hdc, x, y, RGB(125, 79, 164));
		}

		y++;
		for (int x = 29; x < 143; x++)
		{
			SetPixel(hdc, x, y, RGB(0, 158, 221));
		}

		y++;
		for (int x = 30; x < 142; x++)
		{
			SetPixel(hdc, x, y, RGB(0, 158, 221));
		}
		
		y++;
		for (int x = 30; x < 141; x++)
		{
			SetPixel(hdc, x, y, RGB(0, 158, 221));
		}

		y++;
		for (int x = 31; x < 141; x++)
		{
			SetPixel(hdc, x, y, RGB(0, 158, 221));
		}
		
		y++;
		for (int x = 32; x < 140; x++)
		{
			SetPixel(hdc, x, y, RGB(0, 158, 221));
		}

		y++;
		for (int x = 33; x < 139; x++)
		{
			SetPixel(hdc, x, y, RGB(0, 158, 221));
		}

		y++;
		for (int x = 34; x < 138; x++)
		{
			SetPixel(hdc, x, y, RGB(0, 158, 221));
		}

		y++;
		for (int x = 34; x < 137; x++)
		{
			SetPixel(hdc, x, y, RGB(0, 158, 221));
		}

		y++;
		for (int x = 35; x < 137; x++)
		{
			SetPixel(hdc, x, y, RGB(0, 158, 221));
		}
		
		y++;
		for (int x = 36; x < 136; x++)
		{
			SetPixel(hdc, x, y, RGB(0, 158, 221));
		}

		y++;
		for (int x = 37; x < 135; x++)
		{
			SetPixel(hdc, x, y, RGB(0, 158, 221));
		}

		y++;
		for (int x = 38; x < 134; x++)
		{
			SetPixel(hdc, x, y, RGB(0, 158, 221));
		}

		y++;
		for (int x = 39; x < 133; x++)
		{
			SetPixel(hdc, x, y, RGB(0, 158, 221));
		}

		y++;
		for (int x = 40; x < 132; x++)
		{
			SetPixel(hdc, x, y, RGB(0, 158, 221));
		}

		y++;
		for (int x = 41; x < 83; x++)
		{
			SetPixel(hdc, x, y, RGB(0, 158, 221));
		}
		for (int x = 89; x < 131; x++)
		{
			SetPixel(hdc, x, y, RGB(0, 158, 221));
		}

		y++;
		for (int x = 42; x < 77; x++)
		{
			SetPixel(hdc, x, y, RGB(0, 158, 221));
		}
		for (int x = 94; x < 130; x++)
		{
			SetPixel(hdc, x, y, RGB(0, 158, 221));
		}

		y++;
		for (int x = 44; x < 75; x++)
		{
			SetPixel(hdc, x, y, RGB(0, 158, 221));
		}
		for (int x = 96; x < 128; x++)
		{
			SetPixel(hdc, x, y, RGB(0, 158, 221));
		}

		y++;
		for (int x = 45; x < 72; x++)
		{
			SetPixel(hdc, x, y, RGB(0, 158, 221));
		}
		for (int x = 99; x < 127; x++)
		{
			SetPixel(hdc, x, y, RGB(0, 158, 221));
		}

		y++;
		for (int x = 47; x < 70; x++)
		{
			SetPixel(hdc, x, y, RGB(0, 158, 221));
		}
		for (int x = 102; x < 125; x++)
		{
			SetPixel(hdc, x, y, RGB(0, 158, 221));
		}

		y++;
		for (int x = 48; x < 67; x++)
		{
			SetPixel(hdc, x, y, RGB(0, 158, 221));
		}
		for (int x = 104; x < 123; x++)
		{
			SetPixel(hdc, x, y, RGB(0, 158, 221));
		}

		y++;
		y++;
		y++;
		y++;
		y++;
		y++;
		for (int x = 58; x < 60; x++)
		{
			SetPixel(hdc, x, y, RGB(0, 0, 0));
		}

		y++;
		for (int x = 56; x < 60; x++)
		{
			SetPixel(hdc, x, y, RGB(0, 0, 0));
		}

		y++;
		for (int x = 53; x < 55; x++)
		{
			SetPixel(hdc, x, y, RGB(0, 0, 0));
		}

		y++;
		for (int x = 40; x < 49; x++)
		{
			SetPixel(hdc, x, y, RGB(0, 0, 0));
		}
		for (int x = 52; x < 54; x++)
		{
			SetPixel(hdc, x, y, RGB(0, 0, 0));
		}

		y++;
		for (int x = 39; x < 42; x++)
		{
			SetPixel(hdc, x, y, RGB(0, 0, 0));
		}
		for (int x = 47; x < 58; x++)
		{
			SetPixel(hdc, x, y, RGB(0, 0, 0));
		}
		for (int x = 66; x < 74; x++)
		{
			SetPixel(hdc, x, y, RGB(0, 0, 0));
		}

		y++;
		for (int x = 38; x < 40; x++)
		{
			SetPixel(hdc, x, y, RGB(0, 0, 0));
		}
		for (int x = 48; x < 51; x++)
		{
			SetPixel(hdc, x, y, RGB(0, 0, 0));
		}
		for (int x = 56; x < 73; x++)
		{
			SetPixel(hdc, x, y, RGB(0, 0, 0));
		}

		y++;
		for (int x = 38; x < 39; x++)
		{
			SetPixel(hdc, x, y, RGB(0, 0, 0));
		}
		for (int x = 46; x < 49; x++)
		{
			SetPixel(hdc, x, y, RGB(0, 0, 0));
		}
		for (int x = 67; x < 71; x++)
		{
			SetPixel(hdc, x, y, RGB(0, 0, 0));
		}

		y++;
		for (int x = 38; x < 40; x++)
		{
			SetPixel(hdc, x, y, RGB(0, 0, 0));
		}
		for (int x = 44; x < 48; x++)
		{
			SetPixel(hdc, x, y, RGB(0, 0, 0));
		}
		for (int x = 64; x < 69; x++)
		{
			SetPixel(hdc, x, y, RGB(0, 0, 0));
		}

		y++;
		for (int x = 38; x < 44; x++)
		{
			SetPixel(hdc, x, y, RGB(0, 0, 0));
		}
		for (int x = 62; x < 65; x++)
		{
			SetPixel(hdc, x, y, RGB(0, 0, 0));
		}
		for (int x = 67; x < 69; x++)
		{
			SetPixel(hdc, x, y, RGB(0, 0, 0));
		}

		y++;
		for (int x = 40; x < 43; x++)
		{
			SetPixel(hdc, x, y, RGB(0, 0, 0));
		}
		for (int x = 60; x < 64; x++)
		{
			SetPixel(hdc, x, y, RGB(0, 0, 0));
		}
		for (int x = 66; x < 68; x++)
		{
			SetPixel(hdc, x, y, RGB(0, 0, 0));
		}
		for (int x = 127; x < 131; x++)
		{
			SetPixel(hdc, x, y, RGB(0, 0, 0));
		}

		y++;
		for (int x = 60; x < 63; x++)
		{
			SetPixel(hdc, x, y, RGB(0, 0, 0));
		}

		for (int x = 65; x < 67; x++)
		{
			SetPixel(hdc, x, y, RGB(0, 0, 0));
		}
		for (int x = 125; x < 131; x++)
		{
			SetPixel(hdc, x, y, RGB(0, 0, 0));
		}

		y++;
		for (int x = 58; x < 60; x++)
		{
			SetPixel(hdc, x, y, RGB(0, 0, 0));
		}

		for (int x = 64; x < 66; x++)
		{
			SetPixel(hdc, x, y, RGB(0, 0, 0));
		}
		for (int x = 124; x < 127; x++)
		{
			SetPixel(hdc, x, y, RGB(0, 0, 0));
		}

		y++;
		for (int x = 57; x < 58; x++)
		{
			SetPixel(hdc, x, y, RGB(0, 0, 0));
		}

		for (int x = 63; x < 65; x++)
		{
			SetPixel(hdc, x, y, RGB(0, 0, 0));
		}
		for (int x = 123; x < 125; x++)
		{
			SetPixel(hdc, x, y, RGB(0, 0, 0));
		}

		y++;
		for (int x = 56; x < 57; x++)
		{
			SetPixel(hdc, x, y, RGB(0, 0, 0));
		}

		for (int x = 63; x < 65; x++)
		{
			SetPixel(hdc, x, y, RGB(0, 0, 0));
		}
		for (int x = 123; x < 125; x++)
		{
			SetPixel(hdc, x, y, RGB(0, 0, 0));
		}

		y++;
		for (int x = 56; x < 57; x++)
		{
			SetPixel(hdc, x, y, RGB(0, 0, 0));
		}

		for (int x = 63; x < 65; x++)
		{
			SetPixel(hdc, x, y, RGB(0, 0, 0));
		}
		for (int x = 122; x < 125; x++)
		{
			SetPixel(hdc, x, y, RGB(0, 0, 0));
		}

		y++;
		for (int x = 54; x < 55; x++)
		{
			SetPixel(hdc, x, y, RGB(0, 0, 0));
		}
		for (int x = 62; x < 64; x++)
		{
			SetPixel(hdc, x, y, RGB(0, 0, 0));
		}
		for (int x = 121; x < 124; x++)
		{
			SetPixel(hdc, x, y, RGB(0, 0, 0));
		}	

		y++;
		for (int x = 53; x < 54; x++)
		{
			SetPixel(hdc, x, y, RGB(0, 0, 0));
		}
		for (int x = 60; x < 63; x++)
		{
			SetPixel(hdc, x, y, RGB(0, 0, 0));
		}
		for (int x = 68; x < 71; x++)
		{
			SetPixel(hdc, x, y, RGB(0, 0, 0));
		}
		for (int x = 121; x < 124; x++)
		{
			SetPixel(hdc, x, y, RGB(0, 0, 0));
		}

		y++;
		for (int x = 47; x < 64; x++)
		{
			SetPixel(hdc, x, y, RGB(0, 0, 0));
		}

		for (int x = 67; x < 71; x++)
		{
			SetPixel(hdc, x, y, RGB(0, 0, 0));
		}
		for (int x = 121; x < 124; x++)
		{
			SetPixel(hdc, x, y, RGB(0, 0, 0));
		}

		y++;
		for (int x = 44; x < 48; x++)
		{
			SetPixel(hdc, x, y, RGB(0, 0, 0));
		}

		for (int x = 51; x < 69; x++)
		{
			SetPixel(hdc, x, y, RGB(0, 0, 0));
		}
		for (int x = 120; x < 124; x++)
		{
			SetPixel(hdc, x, y, RGB(0, 0, 0));
		}

		y++;
		for (int x = 43; x < 45; x++)
		{
			SetPixel(hdc, x, y, RGB(0, 0, 0));
		}
		for (int x = 50; x < 52; x++)
		{
			SetPixel(hdc, x, y, RGB(0, 0, 0));
		}
		for (int x = 59; x < 63; x++)
		{
			SetPixel(hdc, x, y, RGB(0, 0, 0));
		}
		for (int x = 120; x < 123; x++)
		{
			SetPixel(hdc, x, y, RGB(0, 0, 0));
		}

		y++;
		for (int x = 44; x < 46; x++)
		{
			SetPixel(hdc, x, y, RGB(0, 0, 0));
		}
		for (int x = 38; x < 39; x++)
		{
			SetPixel(hdc, x, y, RGB(0, 0, 0));
		}
		for (int x = 49; x < 50; x++)
		{
			SetPixel(hdc, x, y, RGB(0, 0, 0));
		}
		for (int x = 58; x < 61; x++)
		{
			SetPixel(hdc, x, y, RGB(0, 0, 0));
		}
		for (int x = 119; x < 123; x++)
		{
			SetPixel(hdc, x, y, RGB(0, 0, 0));
		}

		y++;
		for (int x = 36; x < 39; x++)
		{
			SetPixel(hdc, x, y, RGB(0, 0, 0));
		}
		for (int x = 49; x < 50; x++)
		{
			SetPixel(hdc, x, y, RGB(0, 0, 0));
		}
		for (int x = 49; x < 50; x++)
		{
			SetPixel(hdc, x, y, RGB(0, 0, 0));
		}
		for (int x = 58; x < 61; x++)
		{
			SetPixel(hdc, x, y, RGB(0, 0, 0));
		}
		for (int x = 119; x < 123; x++)
		{
			SetPixel(hdc, x, y, RGB(0, 0, 0));
		}



		ReleaseDC(hWnd, hdc);
		break;
	//case WM_LBUTTONUP:		// ��Ŭ��
	//	break;
	//	//case WM_TIMER:
	//	//	break;
	//	//case WM_KEYDOWN:
	//	//	break;
	//	//case WM_KEYUP:
	//	//	break;
	//	//case WM_MBUTTONDOWN:	// ��
	//	//	break;
	//case WM_DESTROY:	// �����찡 ����� �� �� �ѹ��� ����ȴ�.
	//	PostQuitMessage(0);
	//	break;
	//	return 0;
	}
	return(DefWindowProc(hWnd, iMessage, wPram, lPram));
}
