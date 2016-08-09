#pragma once
#include "ellipseex.h"
class CCircleEx :
	public CEllipseEx
{
private:
	bool ResizeFollowX;
public:
	void SetPoint(CPoint p1, CPoint p2);
	CCircleEx(void);
	~CCircleEx(void);
};

