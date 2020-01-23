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

		//// 픽셀단위
		//SetPixel(hdc, 200, 200, RGB(255, 0, 0));
		//SetPixel(hdc, 200, 201, RGB(255, 0, 0));
		//SetPixel(hdc, 200, 202, RGB(255, 0, 0));
		//SetPixel(hdc, 200, 203, RGB(255, 0, 0));
		//SetPixel(hdc, 200, 204, RGB(255, 0, 0));
		//SetPixel(hdc, 200, 205, RGB(255, 0, 0));

		// 선의 시작점
		// ㅂ
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

		// ㅐ
		MoveToEx(hdc, 250, 100, nullptr);
		LineTo(hdc, 250, 200);

		MoveToEx(hdc, 300, 100, nullptr);
		LineTo(hdc, 300, 200);

		MoveToEx(hdc, 250, 150, nullptr);
		LineTo(hdc, 300, 150);

		// ㄱ
		MoveToEx(hdc, 150, 250, nullptr);
		LineTo(hdc, 280, 250);

		MoveToEx(hdc, 280, 250, nullptr);
		LineTo(hdc, 280, 350);

		//ㄱ
		MoveToEx(hdc, 350, 100, nullptr);
		LineTo(hdc, 450, 100);

		MoveToEx(hdc, 450, 100, nullptr);
		LineTo(hdc, 350, 200);

		//ㅕ
		MoveToEx(hdc, 420, 130, nullptr);
		LineTo(hdc, 500, 130);

		MoveToEx(hdc, 390, 160, nullptr);
		LineTo(hdc, 500, 160);

		MoveToEx(hdc, 500, 100, nullptr);
		LineTo(hdc, 500, 200);

		//ㅇ
		Ellipse(hdc, 400, 220, 500, 320);
		// left top right bottom


		//ㅈ
		MoveToEx(hdc, 550, 100, nullptr);
		LineTo(hdc, 700, 100);

		MoveToEx(hdc, 700, 100, nullptr);
		LineTo(hdc, 550, 200);

		MoveToEx(hdc, 625, 150, nullptr);
		LineTo(hdc, 700, 200);

		//ㅜ

		MoveToEx(hdc, 540, 220, nullptr);
		LineTo(hdc, 710, 220);

		MoveToEx(hdc, 625, 220, nullptr);
		LineTo(hdc, 625, 270);

		// ㄴ
		MoveToEx(hdc, 580, 240, nullptr);
		LineTo(hdc, 580, 330);
		MoveToEx(hdc, 580, 330, nullptr);
		LineTo(hdc, 700, 330);

		//SetTextColor(hdc, RGB(10, 200, 30));
		//TextOut(hdc, 400, 400, "안녕하세요.", strlen("안녕하세요."));

		//SetTextColor(hdc, RGB(10, 200, 255));
		//TextOut(hdc, 200, 200, "안녕", strlen("안녕"));
		//EndPaint(hWnd, &ps);
		//break;

	//case WM_LBUTTONDOWN:	// 왼쪽 버튼 클릭했을 때
	//	hdc = GetDC(hWnd);

	//	SetTextColor(hdc, RGB(0, 2, 255));
	//	TextOut(hdc, 100, 100, "ㅎㅇ", strlen("ㅎㅇ"));


	//	ReleaseDC(hWnd, hdc);
	//	break;
	case WM_LBUTTONUP:		// 좌클릭
		break;
		//case WM_TIMER:
		//	break;
		//case WM_KEYDOWN:
		//	break;
		//case WM_KEYUP:
		//	break;
		//case WM_MBUTTONDOWN:	// 휠
		//	break;
	case WM_DESTROY:	// 윈도우가 종료될 때 단 한번만 실행된다.
		PostQuitMessage(0);
		break;
		return 0;
	}
	return(DefWindowProc(hWnd, iMessage, wPram, lPram));
}
