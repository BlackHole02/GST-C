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
*****/#ifndef HDC_CONTROLLER_H
#define HDC_CONTROLLER_H

#include<Windows.h>
#include"bitmap.h"

enum DRAWMODE
{
	PM_OVERRIDE = SRCCOPY,
	PM_TRANSPARENTSECTION = SRCAND,
	PM_PAINT = SRCPAINT
};

class CHdcController
{
	HDC _hDC;
	void SethDC(HDC hdc);
public:
	CHdcController(HDC hdc);
	CHdcController(CBitmapEx & image);
	HDC getHDC();

#pragma region Drawing

	void DrawImage(CBitmapEx& image, DRAWMODE drawMode = DRAWMODE::PM_OVERRIDE, int ix = 0, int iy = 0, int ix1 = 0, int iy1 = 0);

	void DrawLine(HPEN hpen,int ix, int iy, int ix1, int iy1);
	void DrawLine(HPEN hpen,CPoint p1, CPoint p2);
	
	void DrawFromOtherHDC(HDC hdc,int iWdith,int iHeight, DRAWMODE drawMode = DRAWMODE::PM_OVERRIDE, int ix = 0, int iy = 0, int ix1 = 0, int iy1 = 0);

	void Clear(COLORREF color,int x,int y,int w,int h);

	void DrawString(TCHAR* str,int x,int y);

#pragma endregion


	~CHdcController();
};




#endif // !HDC_CONTROLLER_H
