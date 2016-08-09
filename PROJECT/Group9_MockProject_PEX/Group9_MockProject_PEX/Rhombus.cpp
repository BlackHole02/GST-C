#include "stdafx.h"
#include "Rhombus.h"


Rhombus::Rhombus()
{

}
bool Rhombus::Draw(HDC hdc)
{
	if (_nLeft == _nRight && _nTop == _nBottom)
		return false;
	//SelectObject(hdc, GetPen());
	::MoveToEx(hdc, _nLeft, (_nTop + _nBottom) / 2, 0);
	::LineTo(hdc, (_nLeft + _nRight) / 2, _nTop);

	::MoveToEx(hdc, (_nLeft + _nRight) / 2, _nTop, 0);
	::LineTo(hdc, _nRight, (_nTop + _nBottom) / 2);

	::MoveToEx(hdc, _nRight, (_nTop + _nBottom) / 2, 0);
	::LineTo(hdc, (_nLeft + _nRight) / 2, _nBottom);

	::MoveToEx(hdc, (_nLeft + _nRight) / 2, _nBottom, 0);
	::LineTo(hdc, _nLeft, (_nTop + _nBottom) / 2);
	return true;
}
bool Rhombus::IsSelected(int x, int y)
{
	return true;
}

Rhombus::~Rhombus()
{
}
