#pragma once
#include"ShapeEx.h"
class CRectangleEx: public CShapeEx
{
public:
	CRectangleEx();
	~CRectangleEx();
	bool Draw(HDC);
	//void DrawSelected(HDC);
	bool IsSelected(int x, int y);
};

