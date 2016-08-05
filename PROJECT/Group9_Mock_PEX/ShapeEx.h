#pragma once
class CShapeEx
{
protected:
	int _nLeft;
	int _nTop;
	int _nRight;
	int _nBottom;
	bool _bFilled;
	int _nPenWidth;
	int _PenStyle;
	COLORREF _BrushColor;
	COLORREF _PenColor;
	int _nPatten;
protected:
	CShapeEx();
	virtual bool IsSelected(int x, int y) = 0;
	//virtual bool Rotate(int degree) {};
	HPEN GetPen();
	CRect GetResizeRect(CPoint, int width = 7);
	~CShapeEx();
public:
	void SetPenStyle(int PenWidth, int PenStyle, COLORREF PenColor);
	virtual void SetPoint(CPoint p1, CPoint p2);
	virtual bool Draw(HDC) = 0;
	virtual void DrawSelected(HDC);
};

