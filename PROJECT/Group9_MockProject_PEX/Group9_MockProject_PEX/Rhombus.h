#pragma once
#include"ShapeEx.h"
class Rhombus :public CShapeEx
{
public:
	Rhombus();
	~Rhombus();
	bool Draw(HDC);
	bool IsSelected(int x, int y);
};

