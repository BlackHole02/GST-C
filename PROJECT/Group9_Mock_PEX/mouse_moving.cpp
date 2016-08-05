#include "stdafx.h"
#include "mouse_moving.h"


CMouseMoving::CMouseMoving()
{
	_isActive = false;
}

void CMouseMoving::SetMouseBegin(CPoint ptBegin)
{
	_isActive = true;
	_ptBegin = ptBegin;
	_ptEnd = ptBegin;
}
void CMouseMoving::SetMouseEnd(CPoint ptEnd)
{
	_ptEnd = ptEnd;
}
CPoint CMouseMoving::GetMouseBegin()
{
	return _ptBegin;
}
CPoint CMouseMoving::GetMouseEnd()
{
	return _ptEnd;
}
CRect CMouseMoving::GetRect()
{
	if (IsActive())
	{
		CRect r;
		r.SetRect(_ptBegin, _ptEnd);
		r.NormalizeRect();
		return r;
	}
	return CRect(0, 0, 0, 0);
}
bool CMouseMoving::IsActive()
{
	return _isActive;
}
void CMouseMoving::InActive()
{
	_isActive = false;
}
CMouseMoving::~CMouseMoving()
{
}
