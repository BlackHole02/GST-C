#include "stdafx.h"
#include "TriangleEx.h"


CTriangleEx::CTriangleEx(void)
{
	_isDrawLine=true;
}


CTriangleEx::~CTriangleEx(void)
{
}

void CTriangleEx::SetPoint(CPoint p1, CPoint p2)
{
	_nLeft = p1.x;
	_nTop = p1.y;
	_nRight = p2.x;
	_nBottom = p2.y;
}
bool CTriangleEx::IsSelected(int x, int y)
{
	return true;
}

bool CTriangleEx::Draw(HDC hdc)
{
	if(_isDrawLine)
	{

		::MoveToEx(hdc,_nLeft,_nTop,0);
		::LineTo(hdc,_nRight,_nBottom);
		return false;
	}

	_point3 = CPoint(_nRight,_nBottom);
	::MoveToEx(hdc,_point2.x,_point2.y,0);
	::LineTo(hdc,_point3.x,_point3.y);
	::LineTo(hdc,_point1.x,_point1.y);

	return true;
}

void CTriangleEx::OnLButtonUp(UINT nFlags, CPoint point)
{
	if(_isDrawLine)
	{
		_point1 = CPoint(_nLeft,_nTop);
		_point2 = CPoint(_nRight,_nBottom);
		_isDrawLine=false;
	}
}

void CTriangleEx::DrawSelected(HDC hdc)
{
	if(_isDrawLine)
	{
		CRect r = GetResizeRect(CPoint(_nLeft, _nTop));
		Rectangle(hdc, r.left,r.top,r.right,r.bottom);
		r = GetResizeRect(CPoint(_nRight, _nBottom));
		Rectangle(hdc, r.left, r.top, r.right, r.bottom);
	}
	else
	{
		_nLeft = min(_point1.x,_point2.x);
		_nLeft = min(_nLeft,_point3.x);
	}
}