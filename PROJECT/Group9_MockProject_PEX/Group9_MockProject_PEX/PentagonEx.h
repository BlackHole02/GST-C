#pragma once
#include "ShapeEx.h"
class CPentagonEx :
	public CShapeEx
{
public:
	CPentagonEx();
	~CPentagonEx();
	bool Draw(HDC);
	bool IsSelected(int x, int y);
	/*void DrawSelected(HDC);*/
};

