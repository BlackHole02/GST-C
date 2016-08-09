#include "stdafx.h"
#include "RectangleEx.h"

CRectangleEx::CRectangleEx()
{
}

bool CRectangleEx::Draw(HDC hdc)
{
	if (_nLeft == _nRight && _nTop == _nBottom)
		return false;
//	SelectObject(hdc, GetPen());
	Rectangle(hdc, _nLeft, _nTop, _nRight, _nBottom);
	return true;
}
//void CRectangleEx::DrawSelected(HDC hdc)
//{
//	CRect r = GetResizeRect(CPoint(_nLeft, _nTop));
//	Rectangle(hdc, r.left, r.top, r.right, r.bottom);
//	r = GetResizeRect(CPoint(_nRight, _nBottom));
//	Rectangle(hdc, r.left, r.top, r.right, r.bottom);
//}

bool CRectangleEx::IsSelected(int x, int y)
{
	return true;
}
CRectangleEx::~CRectangleEx()
{
}
