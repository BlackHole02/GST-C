#pragma once
/******************************************************************
********
* ++
* Author: American Management Systems
* Module Name : xxxxxxxx.cpp
*
* Description :
xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
*
xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
*
* Mod. History : DD.MMM.YY - Full Name
* File first created
* CR# PROJECT
* Description
*
* --
*******************************************************************
*****/

#ifndef BITMAP_H
#define BITMAP_H
#include<Windows.h>

class CBitmapEx
{
private:
	BITMAP _Bitmap;
	HBITMAP _hBitmap;
	HDC _hDC;
	

	void InitHDC(HDC wndHDC);
	HBITMAP hGethBitmap();

	void SethBitmap(const TCHAR* szFileName);
	void SethBitmap(int iWidth, int iHeight, HDC hdc = 0);


	BITMAP& GetBitmap();
public:

	CBitmapEx(){}

	CBitmapEx(const TCHAR* szFileName,HWND hwnd=0);
	CBitmapEx(int iWidth, int iHeight,HWND hwnd = 0);

	void init(const TCHAR* szFileName,HWND hwnd=0);
	void init(int iWidth, int iHeight,HWND hwnd = 0);

	void DrawTo(HDC hdc,int x=0,int y=0,int drawMode = SRCCOPY);
	void Clear(COLORREF color = RGB(255,255,255));

	HDC hGetHDC();
	int iGetWidth();
	int iGetHeight();
	~CBitmapEx();
};


#endif // !BITMAP_H
