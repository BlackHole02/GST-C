
// MockProject_PEXView.h : interface of the MockProject_PEXView class
//

#pragma once

#include"ImportHeader.h"




class MockProject_PEXView : public CView
{
protected: // create from serialization only
	MockProject_PEXView();
	DECLARE_DYNCREATE(MockProject_PEXView)

// Attributes
public:
	CGroup9_MockProject_PEXDoc* GetDocument() const;

// Operations
public:

// Overrides
public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// Implementation
public:

	
	virtual ~MockProject_PEXView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	DECLARE_MESSAGE_MAP()

private:
	typedef void				(MockProject_PEXView::*PerformFunct)(void);
	//typedef void (*MockProject_PEXView::PerformFunct)();

	static MockProject_PEXView* curObject;
	

	CBitmapEx					_bmContent;
	CBitmapEx					_bmBack;

	HDC							_hdcContent;
	HDC							_hdcBack;

	CRect						_viewRect;
	CShapeEx*					_curShape;

	CMouseMoving				_mouseMoving;

	
	List<CShapeEx*>				_listShape;
	

	PerformFunct _curFunct;

	void OnInitialUpdate();// ham xu ly truoc khi ve
	void Refresh();// lam moi


	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);

	void OnPerformRectButton();
	void OnPerformLineButton();
	void OnPerformEllipseButton();
	void OnPerformCircleButton();
	void OnPerformTriangleButton();
	void OnPerformRhombusButton();
	void OnPerformPentagonButton();
	void OnPerformHexagonButton();

};

#ifndef _DEBUG  // debug version in MockProject_PEXView.cpp
inline CGroup9_MockProject_PEXDoc* MockProject_PEXView::GetDocument() const
   { return reinterpret_cast<CGroup9_MockProject_PEXDoc*>(m_pDocument); }
#endif

