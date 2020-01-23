#pragma once
/*

1. bmp : ������ ������ ���ս� �������̹Ƿ� �ӵ��� ���� ������.
2. jpg : �ս� �����̹Ƿ� ���� ���� �̹����� �ս��� �Ͼ�� ��� ������ �Ǿ� �뷮�� �۴�
3. png : 1, 2������ �޸� alphaä���� ����.


*/
class Image
{
public:
	enum IMAGE_LOAD_KIND
	{
		LOAD_RESOURCE = 0,	// ���ҽ��ε�
		LOAD_FILE,			// ���Ϸε�
		LOAD_EMPTY,			// �� ��Ʈ�� ����
		LOAD_END
	};

	typedef struct tagImage
	{
		DWORD		resID;		// ���ҽ� ���̵�
		HDC			hMemDC;		// �޸� DC
		HBITMAP		hBit;		// ��Ʈ��(���ο� ��Ʈ�� �ڵ�)
		HBITMAP		hOBit;		// �õ� ��Ʈ��(���� ��Ʈ�� �ڵ�)
		int			width;		// �̹��� ����ũ��
		int			height;		// �̹��� ����ũ��
		BYTE		loadType;	// �ε�Ÿ��

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
	LPIMAGE_INFO	_imageInfo;	// �̹��� ����
	char*			_fileName;	// �̹��� �̸�
	bool			_isTrans;	// ���� �����ǰ�?
	COLORREF		_transColor;// ���� ���� RGB

public:
	
	// ��Ʈ�� �ʱ�ȭ
	HRESULT Init(int width, int height);

	HRESULT Init(const char* filename, int width, int height, bool istrans = false, COLORREF transColor = RGB(255, 0, 255));

	// ���� ����
	void SetTransColor(bool isTrans, COLORREF transColor);

	void Release();

	void Render(HDC hdc);
	void Render(HDC hdc, int destX, int destY);

	// DC�� �����Ͷ�
	inline HDC GetMemDC() { return _imageInfo->hMemDC; }
};

