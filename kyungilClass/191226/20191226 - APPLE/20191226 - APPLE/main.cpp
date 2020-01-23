#include <Windows.h>

// 인스턴스 : 메모리상에 할당되어 실행중인 프로그램
// 즉 OS를 확인하기 위한 값.
HINSTANCE m_hInstance;

// 윈도우 핸들
// 대상끼리 구분하기 위해 사용한다.
HWND m_hWnd;

// 윈도우 클래스 이름(윈도우 창 위에 뜨는 이름)	
LPTSTR m_lpszClass = TEXT("경일 프로그래밍 18기");

//
LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);

// hInstance		: 인스턴스 핸들
// hprevInstance	: 이전에 실행된 인스턴스 핸들
// lpszCmdParm		: 명령으로 입력된 프로그램 인수
// nCmdShow			: 프로그램이 시작될 형태

/*
	WinMain의 역할
	1. 윈도우창 세팅 후 화면에 띄우고
	2. 메시지 루프를 돌아라.
*/
int APIENTRY WinMain(HINSTANCE hInstance, HINSTANCE hprevInstance, LPSTR lpszCmdParm, int nCmdShow)
{
	// 윈도우API는 크게 WinMain과 Wndproc 두 개의 함수로 이루어져 있다.
	// Wndproc - 윈도우 프로시져는 윈도우에서 이루어지는 동작을 이야기 한다. 즉, 메시지를 처리한다.

	m_hInstance = hInstance;

	// WNDCLASS		: 윈도우 창의 정보를 저장하기 위한 구조체.
	// 윈도우창 구조체 선언 후 초기화 하자.
	WNDCLASS wndClass;

	// 윈도우 클래스에서 사용하고자 하는 여분의 메모리양을 byte단위로 지정한다.
	wndClass.cbClsExtra = 0;

	// cbClsExtra와 유사하나 개별 윈도우에서 사용하고자 하는 여분의 메모리양을 지원한다.
	wndClass.cbWndExtra = 0;

	// 윈도우 작업영역에 칠할 배경 브러시
	wndClass.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);

	// 커서지정
	wndClass.hCursor = LoadCursor(NULL, IDC_ARROW);

	// 타이틀바의 좌상단에 보여줄 아이콘과 윈도우가 최소화 되었을때 보여줄 아이콘을 지정한다.
	wndClass.hIcon = LoadIcon(NULL, IDI_APPLICATION);

	// 윈도우 클래스를 등록한 응용프로그램의 인스턴스 핸들
	wndClass.hInstance = hInstance;

	// 메시지를 처리하는 함수를 지정(윈도우 프로시져).
	wndClass.lpfnWndProc = (WNDPROC)WndProc;

	// 등록하고자 하는 윈도우 클래스 이름
	wndClass.lpszClassName = m_lpszClass;

	// 클래스로 부터 만들어진 윈도우가 사용할 메뉴를 지정
	wndClass.lpszMenuName = NULL;

	// 윈도우 클래스의 스타일을 지정
	wndClass.style = CS_HREDRAW | CS_VREDRAW;

	// 윈도우 클래스 등록
	// 등록할 윈도우 클래스의 특성을 지정하는 WNDCLASS구조체 전달
	RegisterClass(&wndClass);

	m_hWnd = CreateWindow
	(
		m_lpszClass,			// 클래스 이름
		m_lpszClass,			// 윈도우 타이틀 이름
		WS_OVERLAPPEDWINDOW,	// 윈도우 스타일
		100,					// 윈도우 화면 X좌표
		100,					// 윈도우 화면 Y좌표
		1024, 768,				// 윈도우 사이즈 (가로, 세로)
		NULL,					// 부모 윈도우
		(HMENU)NULL,			// 메뉴핸들
		hInstance,				// 인스턴스지정
		NULL);

	// 화면에 윈도우 보여주자
	ShowWindow(m_hWnd, nCmdShow);

	// MSG : 운영체제에서 발생하는 메시지 정보를 저장하기 위한 구조체
	MSG message;

	// TranslateMessage : 키보드 입력 메시지 처리를 담당
	// DispatchMessage  : 윈도우 프로시져에 전달된 메시지를 실제 윈도우에 전달한다.
	// getMessage		: 대기상태
	while (GetMessage(&message, 0, 0, 0))
	{
		TranslateMessage(&message);
		DispatchMessage(&message);
	}

	return message.wParam;

}

// 윈도우 프로시져	: 메시지를 운영체제에 전달한다. 강제로 운영체제가 호출한다.
// hWnd				: 윈도우가 발생한 메시지인지 구분한다.
// iMessage			: 메시지 구분번호
// wParam			: unsigned int 마우스 버튼의 상태, 키보드 조합키의 상태를 전달한다.
// lParma			: unsigned long 마우스의 클릭좌표를 전달한다.
LRESULT CALLBACK WndProc(HWND hWnd, UINT iMessage, WPARAM wPram, LPARAM lPram)
{
	/*
		DC : device context(디바이스 컨텍스트)
		-> 출력에 관한 옵션을 디폴트로 설정.
		DC를사용하기 위해 HDC, DC의 핸들을 이용한다.
		GDI모듈에 의해 관리된다.
		GDI화면 처리와 그래픽 출력을 한다.
		HDC : 출력에 필요한 정보를 가지는 데이터 구조체.
		좌표, 굵기, 색 등등 출력에 필요한 모든 정보를 담고있다.
	*/

	// PAINTSTRUCT : 윈도우 클라이언트 영역을 그리기 위한 정보를 담은 구조체

	HDC hdc;
	PAINTSTRUCT ps;

	switch (iMessage)
	{

	case WM_CREATE:		// 윈도우가 시작될 때 단 한번만 실행된다.
		break;
	case WM_PAINT:		// 윈도우의 작업영역이 손실되었을때 실행된다. 그리는곳
		hdc = BeginPaint(hWnd, &ps);

		int x;
		int y;
		// 픽셀단위

		// 잎파리
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
	//case WM_LBUTTONUP:		// 좌클릭
	//	break;
	//	//case WM_TIMER:
	//	//	break;
	//	//case WM_KEYDOWN:
	//	//	break;
	//	//case WM_KEYUP:
	//	//	break;
	//	//case WM_MBUTTONDOWN:	// 휠
	//	//	break;
	//case WM_DESTROY:	// 윈도우가 종료될 때 단 한번만 실행된다.
	//	PostQuitMessage(0);
	//	break;
	//	return 0;
	}
	return(DefWindowProc(hWnd, iMessage, wPram, lPram));
}
