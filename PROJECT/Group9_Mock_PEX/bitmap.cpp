#include"stdafx.h"
#include "bitmap.h"

void CBitmapEx::InitHDC(HDC wndHDC)
{
	_hDC = CreateCompatibleDC(wndHDC);
	SelectObject(hGetHDC(), _hBitmap);
}

CBitmapEx::CBitmapEx(const TCHAR* szFileName, HWND hwnd)
{
	HDC wndHDC = ::GetDC(hwnd);// get hdc tu cua so
	SethBitmap(szFileName);//tao hbitmap
	InitHDC(wndHDC);			// tao hdc tuong thich voi bitmap
	DeleteObject(wndHDC);
}
CBitmapEx::CBitmapEx(int iWidth, int iHeight, HWND hwnd)
{
	HDC wndHDC = ::GetDC(hwnd);
	SethBitmap(iWidth, iHeight, wndHDC);
	InitHDC(wndHDC);

	COLORREF cr = RGB(255, 255, 255);
	HBRUSH hbr = CreateSolidBrush(cr);
	RECT r;
	r.left = 0;
	r.right = r.left + iWidth;
	r.top = 0;
	r.bottom = r.top + iHeight;
	FillRect(hGetHDC(), &r, hbr);
	DeleteObject(hbr);

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

BITMAP& CBitmapEx::GetBitmap()
{
	return _Bitmap;
}
short int CBitmapEx::iGetWidth()
{
	return GetBitmap().bmWidth;
}
short int CBitmapEx::iGetHeight()
{
	return GetBitmap().bmHeight;
}

CBitmapEx::~CBitmapEx()
{
	DeleteObject(hGethBitmap());
	DeleteObject(hGetHDC());
}
