#pragma once
#include"ShapeEx.h"
class CTriangleEx:
	public CShapeEx
{
private:
	bool _isDrawLine;
	CPoint _point1;
	CPoint _point2;
	CPoint _point3;
public:
	CTriangleEx(void);
	~CTriangleEx(void);

	void SetPoint(CPoint p1, CPoint p2);
	bool IsSelected(int x, int y);
	bool Draw(HDC hdc);
	void DrawSelected(HDC hdc);
	void OnLButtonUp(UINT nFlags, CPoint point);
};

