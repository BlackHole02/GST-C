#include "stdafx.h"
#include "HexagonEx.h"


CHexagonEx::CHexagonEx()
{
}


CHexagonEx::~CHexagonEx()
{
}

//void CHexagonEx::DrawSelected(HDC)
//{
//
//}

bool CHexagonEx::IsSelected(int x, int y)
{
	return false;
}

bool CHexagonEx::Draw(HDC hdc)
{
	CPoint top, left1, left2, right1, right2, bot;
	top.x = bot.x = (_nLeft + _nRight) / 2;
	top.y = _nTop;
	bot.y = _nBottom;
	left1.y = right1.y = (_nBottom - _nTop) / 4 + _nTop;
	left2.y = right2.y = _nBottom - (_nBottom - _nTop) / 4;
	left1.x = left2.x = _nLeft;
	right1.x = right2.x = _nRight;

	

	//SelectObject(hdc, GetPen());
	::MoveToEx(hdc, top.x, top.y, 0);
	::LineTo(hdc, left1.x, left1.y);
	::MoveToEx(hdc, left1.x, left1.y, 0);
	::LineTo(hdc, left2.x, left2.y);
	::MoveToEx(hdc, left2.x, left2.y, 0);
	::LineTo(hdc, bot.x, bot.y);
	::MoveToEx(hdc, bot.x, bot.y, 0);
	::LineTo(hdc, right2.x, right2.y);
	::MoveToEx(hdc, right2.x, right2.y, 0);
	::LineTo(hdc, right1.x, right1.y);
	::MoveToEx(hdc, right1.x, right1.y, 0);
	::LineTo(hdc, top.x, top.y);
	return true;
}
