#pragma once
/*

1. bmp : 제약이 많지만 무손실 무압축이므로 속도가 가장 빠르다.
2. jpg : 손실 압축이므로 원래 가진 이미지의 손실이 일어나는 대신 압축이 되어 용량이 작다
3. png : 1, 2번과는 달리 alpha채널이 없다.


*/
class Image
{
public:
	enum IMAGE_LOAD_KIND
	{
		LOAD_RESOURCE = 0,	// 리소스로딩
		LOAD_FILE,			// 파일로딩
		LOAD_EMPTY,			// 빈 비트맵 파일
		LOAD_END
	};

	typedef struct tagImage
	{
		DWORD		resID;		// 리소스 아이디
		HDC			hMemDC;		// 메모리 DC
		HBITMAP		hBit;		// 비트맵(새로운 비트맵 핸들)
		HBITMAP		hOBit;		// 올드 비트맵(기존 비트맵 핸들)
		int			width;		// 이미지 가로크기
		int			height;		// 이미지 세로크기
		BYTE		loadType;	// 로드타입

		tagImage()
		{
			resID		= 0;
			hMemDC		= NULL;
			hBit		= NULL;
			hOBit		= NULL;
			width		= 0;
			height		= 0;
			loadType	= LOAD_RESOURCE;
		}

	}IMAGE_INFO, *LPIMAGE_INFO;
	Image();
	~Image();

private:
	LPIMAGE_INFO	_imageInfo;	// 이미지 정보
	char*			_fileName;	// 이미지 이름
	bool			_isTrans;	// 배경색 날릴건가?
	COLORREF		_transColor;// 배경색 날릴 RGB

public:
	
	// 비트맵 초기화
	HRESULT Init(int width, int height);

	HRESULT Init(const char* filename, int width, int height, bool istrans = false, COLORREF transColor = RGB(255, 0, 255));

	// 투명값 세팅
	void SetTransColor(bool isTrans, COLORREF transColor);

	void Release();

	void Render(HDC hdc);
	void Render(HDC hdc, int destX, int destY);

	// DC를 가져와라
	inline HDC GetMemDC() { return _imageInfo->hMemDC; }
};

