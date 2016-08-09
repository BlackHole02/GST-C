#pragma once
class CMouseMoving
{
private:
	CPoint _ptBegin;
	CPoint _ptEnd;
	bool _isActive;
public:
	void SetMouseBegin(CPoint ptBegin);
	void SetMouseEnd(CPoint ptEnd);
	CPoint GetMouseBegin();
	CPoint GetMouseEnd();
	CRect GetRect();
	bool IsActive();
	void InActive();
	CMouseMoving();
	~CMouseMoving();
};

