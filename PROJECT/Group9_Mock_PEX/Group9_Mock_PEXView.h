
// Group9_Mock_PEXView.h : interface of the ViewClass class
//

#pragma once

#include"header.h"
#include<iostream>
#include<string>
#include<vector>
class DocClass;
class ViewClass : public CView
{
protected: // create from serialization only
	ViewClass();
	DECLARE_DYNCREATE(ViewClass)

// Attributes
public:
	DocClass* GetDocument() const;

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
	virtual ~ViewClass();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	DECLARE_MESSAGE_MAP()
public:
	static HDC hdcView;
	static HDC hdcSubView;
	static void Referesh(bool withSubHDC=true);
	static RECT rectView;
private:
	static HDC curHdc;
	CShapeEx *_shapeEx;
	List<CShapeEx*> listShape;
	CMouseMoving _mouseMoving;
	CShapeEx *GetShapeEx();
	MYSHAPETYPE _CurrentType;
	void AddToListShape();
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	void DrawLine();
	void DrawRectangle();
};

#ifndef _DEBUG  // debug version in Group9_Mock_PEXView.cpp
inline DocClass* ViewClass::GetDocument() const
   { return reinterpret_cast<DocClass*>(m_pDocument); }
#endif

