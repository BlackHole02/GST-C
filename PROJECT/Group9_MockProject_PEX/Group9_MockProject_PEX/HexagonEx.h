#pragma once
#include "ShapeEx.h"
class CHexagonEx :
	public CShapeEx
{
public:
	CHexagonEx();
	~CHexagonEx();
	bool Draw(HDC);
	bool IsSelected(int x, int y);
	//void DrawSelected(HDC);
};

