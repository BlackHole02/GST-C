#pragma once
#include "shapeex.h"
#include <iostream>
#include <math.h>

#define ROUND(x) ((x)-(int)(x))>0.5? ((int)x+1): ((int)x)

class CEllipseEx :
	public CShapeEx
{
public:
	CEllipseEx(void);
	~CEllipseEx(void);
	virtual void SetPoint(CPoint p1, CPoint p2);

	void Put4Pixel(HDC hdc,int x, int y, int x0, int y0, COLORREF color);

	virtual bool IsSelected(int x, int y);
	virtual bool Draw(HDC hdc);

};

