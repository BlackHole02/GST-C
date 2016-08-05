#include"stdafx.h"
#include "hdc_controller.h"

CHdcController::CHdcController(CBitmapEx &image)
{
	SethDC(image.hGetHDC());
}

CHdcController::CHdcController(HDC hdc)
{
	SethDC(hdc);
}

void CHdcController::SethDC(HDC hdc)
{
	_hDC = hdc;
}
HDC CHdcController::getHDC()
{
	return _hDC;
}
#pragma region Drawing

void CHdcController::DrawImage(CBitmapEx& image, DRAWMODE drawMode, int x, int y, int x1, int y1)
{
	BitBlt(_hDC, x, y, image.iGetWidth(), image.iGetHeight(), image.hGetHDC(), x1, y1, drawMode);
}
void CHdcController::DrawLine(HPEN hpen,int ix, int iy, int ix1, int iy1)
{
	SelectObject(_hDC, hpen);
	::MoveToEx(_hDC, ix, iy, 0);
	::LineTo(_hDC, ix1, iy1);
}
void CHdcController::DrawLine(HPEN hpen,CPoint p1, CPoint p2)
{
	DrawLine(hpen,p1.x, p1.y, p2.x, p2.y);
}

void CHdcController::DrawFromOtherHDC(HDC hdc, int iWdith, int iHeight, DRAWMODE drawMode, int ix, int iy, int ix1, int iy1)
{
	BitBlt(_hDC, ix, iy, iWdith, iHeight, hdc, ix1, iy1, drawMode);
}

void CHdcController::Clear(COLORREF color, int x, int y, int w, int h)
{
	RECT r;
	r.left = x;
	r.right = x + w - 1;
	r.top = y;
	r.bottom = y + h - 1;
	COLORREF cr = RGB(255, 255, 255);
	HBRUSH hbr = CreateSolidBrush(cr);
	FillRect(_hDC, &r, hbr);
}

void CHdcController::DrawString(TCHAR* str, int x, int y)
{
	//DrawText(_hDC,str,)
}

#pragma endregion


CHdcController::~CHdcController()
{
}
