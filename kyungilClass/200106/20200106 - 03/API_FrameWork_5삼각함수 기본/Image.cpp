#include "stdafx.h"
#include "Image.h"

// 멤버 이니셜라이즈 초기화
// 객체 생성과 동시에 초기화한다.
Image::Image() : _imageInfo(NULL), _fileName(NULL), _isTrans(false), _transColor(RGB(0, 0, 0))
{
}

Image::~Image()
{
}

HRESULT Image::Init(int width, int height)
{
	// 이미지 정보가 들어있다면 해제하라.
	if (_imageInfo != NULL)Release();
	// DC가져오기 (현재 윈도우에 대한 화면 DC를 임시로 가져온다.)

	// CreateCompatibleDC		: 비트맵을 출력하기 위해 메모리DC를 만들어 준다.
	// CreateCompatibleBitmap	: 원본 DC와 호환되는 비트맵을 생성해 준다.
	// SelectObject				: 기본의 비트맵 핸들을 반환하고, 새로운 비트맵을 메모리 DC가 선택하고 메모리 DC에 비트맵이 그려진다.
	//							  화면DC가 아니므로 모니터에 출력은 되지 않는다.
	HDC hdc = GetDC(m_hWnd);
	
	_imageInfo = new IMAGE_INFO;
	_imageInfo->loadType	= LOAD_EMPTY;
	_imageInfo->resID		= 0;
	_imageInfo->hMemDC		= CreateCompatibleDC(hdc);
	_imageInfo->hBit		= (HBITMAP)CreateCompatibleBitmap(hdc, width, height);
	_imageInfo->hOBit		= (HBITMAP)SelectObject(_imageInfo->hMemDC, _imageInfo->hBit);
	_imageInfo->width		= width;
	_imageInfo->height		= height;

	// 파일 이름
	_fileName				= NULL;

	// 투명키 세팅
	_isTrans				= false;
	_transColor				= RGB(0, 0, 0);

	// 리소스를 얻어오는데 실패했다면.
	if (_imageInfo->hBit == NULL)
	{
		Release();
		return E_FAIL;
	}

	//해제
	ReleaseDC(m_hWnd, hdc);
	return S_OK;
}

HRESULT Image::Init(const char * fileName, int width, int height, bool isTrans, COLORREF transColor)
{
	if (fileName != NULL) return E_FAIL;
	if (_imageInfo != NULL) Release();

	HDC hdc = GetDC(m_hWnd);

	_imageInfo = new IMAGE_INFO;
	_imageInfo->loadType = LOAD_EMPTY;
	_imageInfo->resID = 0;
	_imageInfo->hMemDC = CreateCompatibleDC(hdc);
	_imageInfo->hBit = (HBITMAP)LoadImage(m_hInstance, fileName, IMAGE_BITMAP, width, height, LR_LOADFROMFILE);

	_imageInfo->hOBit = (HBITMAP)SelectObject(_imageInfo->hMemDC, _imageInfo->hBit);
	_imageInfo->width = width;
	_imageInfo->height = height;

	// 파일이름
	int len = strlen(fileName);
	_fileName = new char[len + 1];
	strcpy_s(_fileName, len + 1, fileName);
	_isTrans = isTrans;
	_transColor = transColor;
	
	// 리소스를 얻어오는데 실패했다면.
	if (_imageInfo->hBit == NULL)
	{
		Release();
		return E_FAIL;
	}

	//해제
	ReleaseDC(m_hWnd, hdc);

	return S_OK;
}

void Image::SetTransColor(bool isTrans, COLORREF transColor)
{
	_isTrans = isTrans;
	_transColor = transColor;
}

void Image::Release()
{
	if (_imageInfo)
	{
		SelectObject(_imageInfo->hMemDC, _imageInfo->hOBit);
		DeleteObject(_imageInfo->hBit);
		DeleteDC(_imageInfo->hMemDC);

		SAFE_DELETE(_imageInfo);
		SAFE_DELETE(_fileName);

		_isTrans = false;
		_transColor = RGB(0, 0, 0);
	}
}

void Image::Render(HDC hdc)
{
	if (_isTrans)
	{
		// GdiTransparentBlt : 비트맵을 불러올때 특정색상을 제외하고 복사해주는 함수
		GdiTransparentBlt(
			hdc,					// 복사될 장소의 DC
			0,						// 복사될 좌표의 시작점 X
			0,						// 복사될 좌표의 시작점 Y
			_imageInfo->width,		// 복사될 이미지 가로크기
			_imageInfo->height,		// 복사될 이미지 세로크기
			_imageInfo->hMemDC,		// 복사될 대상 DC
			0,						// 복사 시작지점 X
			0,						// 복사 시작지점 Y
			_imageInfo->width,		// 복사영역 가로크기
			_imageInfo->height,		// 복사영역 세로크기
			_transColor);			// 복사할때 제외할 색상
	}
	else
	{
		// SRCCOPY : 복사해주는 함수 가로 세로를 재정의해서 복사
		// DC간의 영역끼리 고속복사해주는 녀석
		BitBlt(hdc, 0, 0, _imageInfo->width, _imageInfo->height, _imageInfo->hMemDC, 0, 0, SRCCOPY);
	}
}

void Image::Render(HDC hdc, int destX, int destY)
{
	if (_isTrans)
	{
		// GdiTransparentBlt : 비트맵을 불러올때 특정색상을 제외하고 복사해주는 함수
		GdiTransparentBlt(
			hdc,					// 복사될 장소의 DC
			destX,					// 복사될 DC영역에 뿌려줄 X 좌표
			destY,					// 복사될 DC영역에 뿌려줄 Y 좌표
			_imageInfo->width,		// 복사될 이미지 가로크기
			_imageInfo->height,		// 복사될 이미지 세로크기
			_imageInfo->hMemDC,		// 복사될 대상 DC
			0,						// 복사 시작지점 X
			0,						// 복사 시작지점 Y
			_imageInfo->width,		// 복사영역 가로크기
			_imageInfo->height,		// 복사영역 세로크기
			_transColor);			// 복사할때 제외할 색상
	}
	else
	{
		// SRCCOPY : 복사해주는 함수 가로 세로를 재정의해서 복사
		// DC간의 영역끼리 고속복사해주는 녀석
		BitBlt(hdc, destX, destY, _imageInfo->width, _imageInfo->height, _imageInfo->hMemDC, 0, 0, SRCCOPY);
	}
}
