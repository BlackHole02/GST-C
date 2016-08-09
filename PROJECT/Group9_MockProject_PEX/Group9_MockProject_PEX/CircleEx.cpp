#include "stdafx.h"
#include "CircleEx.h"


CCircleEx::CCircleEx(void)
{
	ResizeFollowX=true;
}

void CCircleEx::SetPoint(CPoint p1, CPoint p2)
{
	CEllipseEx::SetPoint(p1,p2);

	ResizeFollowX = (_nRight-_nLeft > _nBottom-_nTop);


	if(ResizeFollowX)
	{
		_nBottom = _nTop + (_nRight-_nLeft);
	}
	else
	{
		_nRight = _nLeft + (_nBottom-_nTop);
	}
}

CCircleEx::~CCircleEx(void)
{
}
