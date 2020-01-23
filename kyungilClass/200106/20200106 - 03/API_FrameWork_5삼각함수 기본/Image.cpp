#include "stdafx.h"
#include "Image.h"

// ��� �̴ϼȶ����� �ʱ�ȭ
// ��ü ������ ���ÿ� �ʱ�ȭ�Ѵ�.
Image::Image() : _imageInfo(NULL), _fileName(NULL), _isTrans(false), _transColor(RGB(0, 0, 0))
{
}

Image::~Image()
{
}

HRESULT Image::Init(int width, int height)
{
	// �̹��� ������ ����ִٸ� �����϶�.
	if (_imageInfo != NULL)Release();
	// DC�������� (���� �����쿡 ���� ȭ�� DC�� �ӽ÷� �����´�.)

	// CreateCompatibleDC		: ��Ʈ���� ����ϱ� ���� �޸�DC�� ����� �ش�.
	// CreateCompatibleBitmap	: ���� DC�� ȣȯ�Ǵ� ��Ʈ���� ������ �ش�.
	// SelectObject				: �⺻�� ��Ʈ�� �ڵ��� ��ȯ�ϰ�, ���ο� ��Ʈ���� �޸� DC�� �����ϰ� �޸� DC�� ��Ʈ���� �׷�����.
	//							  ȭ��DC�� �ƴϹǷ� ����Ϳ� ����� ���� �ʴ´�.
	HDC hdc = GetDC(m_hWnd);
	
	_imageInfo = new IMAGE_INFO;
	_imageInfo->loadType	= LOAD_EMPTY;
	_imageInfo->resID		= 0;
	_imageInfo->hMemDC		= CreateCompatibleDC(hdc);
	_imageInfo->hBit		= (HBITMAP)CreateCompatibleBitmap(hdc, width, height);
	_imageInfo->hOBit		= (HBITMAP)SelectObject(_imageInfo->hMemDC, _imageInfo->hBit);
	_imageInfo->width		= width;
	_imageInfo->height		= height;

	// ���� �̸�
	_fileName				= NULL;

	// ����Ű ����
	_isTrans				= false;
	_transColor				= RGB(0, 0, 0);

	// ���ҽ��� �����µ� �����ߴٸ�.
	if (_imageInfo->hBit == NULL)
	{
		Release();
		return E_FAIL;
	}

	//����
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

	// �����̸�
	int len = strlen(fileName);
	_fileName = new char[len + 1];
	strcpy_s(_fileName, len + 1, fileName);
	_isTrans = isTrans;
	_transColor = transColor;
	
	// ���ҽ��� �����µ� �����ߴٸ�.
	if (_imageInfo->hBit == NULL)
	{
		Release();
		return E_FAIL;
	}

	//����
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
		// GdiTransparentBlt : ��Ʈ���� �ҷ��ö� Ư�������� �����ϰ� �������ִ� �Լ�
		GdiTransparentBlt(
			hdc,					// ����� ����� DC
			0,						// ����� ��ǥ�� ������ X
			0,						// ����� ��ǥ�� ������ Y
			_imageInfo->width,		// ����� �̹��� ����ũ��
			_imageInfo->height,		// ����� �̹��� ����ũ��
			_imageInfo->hMemDC,		// ����� ��� DC
			0,						// ���� �������� X
			0,						// ���� �������� Y
			_imageInfo->width,		// ���翵�� ����ũ��
			_imageInfo->height,		// ���翵�� ����ũ��
			_transColor);			// �����Ҷ� ������ ����
	}
	else
	{
		// SRCCOPY : �������ִ� �Լ� ���� ���θ� �������ؼ� ����
		// DC���� �������� ��Ӻ������ִ� �༮
		BitBlt(hdc, 0, 0, _imageInfo->width, _imageInfo->height, _imageInfo->hMemDC, 0, 0, SRCCOPY);
	}
}

void Image::Render(HDC hdc, int destX, int destY)
{
	if (_isTrans)
	{
		// GdiTransparentBlt : ��Ʈ���� �ҷ��ö� Ư�������� �����ϰ� �������ִ� �Լ�
		GdiTransparentBlt(
			hdc,					// ����� ����� DC
			destX,					// ����� DC������ �ѷ��� X ��ǥ
			destY,					// ����� DC������ �ѷ��� Y ��ǥ
			_imageInfo->width,		// ����� �̹��� ����ũ��
			_imageInfo->height,		// ����� �̹��� ����ũ��
			_imageInfo->hMemDC,		// ����� ��� DC
			0,						// ���� �������� X
			0,						// ���� �������� Y
			_imageInfo->width,		// ���翵�� ����ũ��
			_imageInfo->height,		// ���翵�� ����ũ��
			_transColor);			// �����Ҷ� ������ ����
	}
	else
	{
		// SRCCOPY : �������ִ� �Լ� ���� ���θ� �������ؼ� ����
		// DC���� �������� ��Ӻ������ִ� �༮
		BitBlt(hdc, destX, destY, _imageInfo->width, _imageInfo->height, _imageInfo->hMemDC, 0, 0, SRCCOPY);
	}
}
