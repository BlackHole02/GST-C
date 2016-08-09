#include "stdafx.h"
#include "PentagonEx.h"


CPentagonEx::CPentagonEx()
{
}


CPentagonEx::~CPentagonEx()
{
}

//void CPentagonEx::DrawSelected(HDC)
//{
//	
//}

bool CPentagonEx::IsSelected(int x, int y)
{
	return true;
}

bool CPentagonEx::Draw(HDC hdc)
{
	CPoint top, left, right, bot1, bot2;
	top.x = (_nLeft + _nRight) / 2;
	top.y = _nTop;
	left.x = _nLeft;
	left.y = (_nBottom - _nTop) *3 / 8 + _nTop;
	right.x = _nRight;
	right.y = (_nBottom - _nTop) * 3 / 8 + _nTop;
	bot1.y = bot2.y = _nBottom;
	bot1.x = (_nRight - _nLeft) / 5 + _nLeft;
	bot2.x = _nRight - (_nRight - _nLeft) / 5;

	//SelectObject(hdc, GetPen());
	::MoveToEx(hdc, top.x, top.y, 0);
	::LineTo(hdc, left.x, left.y);
	::MoveToEx(hdc, left.x, left.y, 0);
	::LineTo(hdc, bot1.x, bot1.y);
	::MoveToEx(hdc, top.x, top.y, 0);
	::LineTo(hdc, right.x, right.y);
	::MoveToEx(hdc, right.x, right.y, 0);
	::LineTo(hdc, bot2.x, bot2.y);
	::MoveToEx(hdc, bot2.x, bot2.y, 0);
	::LineTo(hdc, bot1.x, bot1.y);
	return true;
}
