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
	CBitmapEx(const TCHAR* szFileName,HWND hwnd=0);
	CBitmapEx(int iWidth, int iHeight,HWND hwnd = 0);
	HDC hGetHDC();
	short int iGetWidth();
	short int iGetHeight();
	~CBitmapEx();
};


#endif // !BITMAP_H
