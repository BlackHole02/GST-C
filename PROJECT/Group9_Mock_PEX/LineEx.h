#pragma once
#include"ShapeEx.h"
class CLineEx : public CShapeEx
{
public:
	CLineEx();
	~CLineEx();
	void SetPoint(CPoint p1, CPoint p2);
	bool Draw(HDC);
	void DrawSelected(HDC);
	bool IsSelected(int x, int y);
};

