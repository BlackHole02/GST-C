#include "stdafx.h"
#include "ShapeEx.h"


CShapeEx::CShapeEx()
{
}

void CShapeEx::SetPenStyle(int PenWidth, int PenStyle, COLORREF PenColor)
{
	_nPenWidth = PenWidth;
	_PenStyle = PenStyle;
	_PenColor = PenColor;
}
HPEN CShapeEx::GetPen()
{
	return CreatePen(_PenStyle, _nPenWidth, _PenColor);
}
CRect CShapeEx::GetResizeRect(CPoint point, int width )
{
	int t = width / 2;
	return CRect(point.x - t, point.y - t, point.x + t, point.y + t);
}
void CShapeEx::SetPoint(CPoint p1, CPoint p2)
{
	_nLeft = min(p1.x, p2.x);
	_nRight = max(p1.x, p2.x);
	_nTop = min(p1.y, p2.y);
	_nBottom = max(p1.y, p2.y);
}
void CShapeEx::DrawSelected(HDC hdc)
{
	HPEN hpen = CreatePen(PS_DASHDOT, 1, RGB(0, 0, 0));
	SelectObject(hdc, hpen);
	Rectangle(hdc, _nLeft, _nTop, _nRight, _nBottom);

	hpen = CreatePen(PS_SOLID, 1, RGB(0, 0, 0));
	SelectObject(hdc, hpen);

	CRect r = GetResizeRect(CPoint(_nLeft, _nTop));
	Rectangle(hdc, r.left, r.top, r.right, r.bottom);

	r = GetResizeRect(CPoint(_nRight, _nBottom));
	Rectangle(hdc, r.left, r.top, r.right, r.bottom);

	r = GetResizeRect(CPoint(_nRight, _nTop));
	Rectangle(hdc, r.left, r.top, r.right, r.bottom);

	r = GetResizeRect(CPoint(_nLeft, _nBottom));
	Rectangle(hdc, r.left, r.top, r.right, r.bottom);

	r = GetResizeRect(CPoint((_nRight + _nLeft) / 2, _nBottom));
	Rectangle(hdc, r.left, r.top, r.right, r.bottom);

	r = GetResizeRect(CPoint(_nRight, (_nBottom + _nTop)/2));
	Rectangle(hdc, r.left, r.top, r.right, r.bottom);

	r = GetResizeRect(CPoint(_nLeft, (_nBottom + _nTop) / 2));
	Rectangle(hdc, r.left, r.top, r.right, r.bottom);

	r = GetResizeRect(CPoint((_nRight + _nLeft) / 2, _nTop));
	Rectangle(hdc, r.left, r.top, r.right, r.bottom);
}

CShapeEx::~CShapeEx()
{
}
