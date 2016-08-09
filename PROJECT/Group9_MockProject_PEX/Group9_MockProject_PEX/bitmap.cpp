#include"stdafx.h"
#include "bitmap.h"

void CBitmapEx::InitHDC(HDC wndHDC)
{
	_hDC = CreateCompatibleDC(wndHDC);
	SelectObject(hGetHDC(), _hBitmap);
}

CBitmapEx::CBitmapEx(const TCHAR* szFileName, HWND hwnd)
{
	init(szFileName,hwnd);
}


void CBitmapEx::init(const TCHAR* szFileName,HWND hwnd)
{
	HDC wndHDC = ::GetDC(hwnd);// get hdc tu cua so
	SethBitmap(szFileName);//tao hbitmap
	InitHDC(wndHDC);			// tao hdc tuong thich voi bitmap
	DeleteObject(wndHDC);
}


CBitmapEx::CBitmapEx(int iWidth, int iHeight, HWND hwnd)
{
	init(iWidth,iHeight,hwnd);
}

void CBitmapEx::init(int iWidth, int iHeight,HWND hwnd)
{
	HDC wndHDC = ::GetDC(hwnd);
	SethBitmap(iWidth, iHeight, wndHDC);
	InitHDC(wndHDC);


	Clear();


	DeleteObject(wndHDC);
}


HDC CBitmapEx::hGetHDC()
{
	return _hDC;
}
HBITMAP CBitmapEx::hGethBitmap()
{
	return _hBitmap;
}
void CBitmapEx::SethBitmap(const TCHAR* szFileName)
{
	_hBitmap = (HBITMAP)LoadImage(
		NULL,			//hInstance=NULL lay cua so hien tai
		szFileName,		//File can lay hinh
		IMAGE_BITMAP,	//loai la bitmap
		0,
		0,
		LR_LOADFROMFILE | LR_CREATEDIBSECTION | LR_DEFAULTSIZE
		);
	GetObject(hGethBitmap(), sizeof(BITMAP), &GetBitmap());
}

void CBitmapEx::SethBitmap(int iWidth, int iHeight, HDC hdc)
{
	_hBitmap = CreateCompatibleBitmap(
		hdc, iWidth, iHeight);

	GetObject(hGethBitmap(), sizeof(BITMAP), &GetBitmap());


}

void CBitmapEx::DrawTo(HDC hdc,int ix,int iy,int drawMode)
{
	BitBlt(hdc, 0, 0, iGetWidth(), iGetHeight(),_hDC , ix, iy, drawMode);
}
void CBitmapEx::Clear(COLORREF color)
{
	COLORREF cr = RGB(255, 255, 255);
	HBRUSH hbr = CreateSolidBrush(cr);
	CRect r(0,0,iGetWidth(),iGetHeight());
	FillRect(hGetHDC(), &r, hbr);
}



BITMAP& CBitmapEx::GetBitmap()
{
	return _Bitmap;
}
int CBitmapEx::iGetWidth()
{
	return GetBitmap().bmWidth;
}
int CBitmapEx::iGetHeight()
{
	return GetBitmap().bmHeight;
}

CBitmapEx::~CBitmapEx()
{
	DeleteObject(hGethBitmap());
	DeleteObject(hGetHDC());
}
