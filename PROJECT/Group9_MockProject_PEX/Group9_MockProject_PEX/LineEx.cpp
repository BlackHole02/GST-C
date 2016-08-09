#include "stdafx.h"
#include "LineEx.h"


CLineEx::CLineEx()
{
}

bool CLineEx::Draw(HDC hdc)
{
	if (_nLeft == _nRight && _nTop == _nBottom)
		return false;
//	SelectObject(hdc, GetPen());
	::MoveToEx(hdc, _nLeft, _nTop, 0);
	::LineTo(hdc, _nRight, _nBottom);
	return true;
}

void CLineEx::SetPoint(CPoint p1, CPoint p2)
{
	_nLeft = p1.x;
	_nTop = p1.y;
	_nRight = p2.x;
	_nBottom = p2.y;
}
void CLineEx::DrawSelected(HDC hdc)
{
	CRect r = GetResizeRect(CPoint(_nLeft, _nTop));
	Rectangle(hdc, r.left,r.top,r.right,r.bottom);
	r = GetResizeRect(CPoint(_nRight, _nBottom));
	Rectangle(hdc, r.left, r.top, r.right, r.bottom);
}

bool CLineEx::IsSelected(int x, int y)
{
	return true;
}
CLineEx::~CLineEx()
{
}
