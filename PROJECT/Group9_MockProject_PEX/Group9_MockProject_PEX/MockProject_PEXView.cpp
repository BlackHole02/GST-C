
// MockProject_PEXView.cpp : implementation of the MockProject_PEXView class
//

#include "stdafx.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "Group9_MockProject_PEX.h"
#endif

#include "Group9_MockProject_PEXDoc.h"
#include "MockProject_PEXView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// MockProject_PEXView

IMPLEMENT_DYNCREATE(MockProject_PEXView, CView)

BEGIN_MESSAGE_MAP(MockProject_PEXView, CView)
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_COMMAND(ID_BUTTONRECT,&MockProject_PEXView::OnPerformRectButton)
	ON_COMMAND(ID_BUTTONLINE,&MockProject_PEXView::OnPerformLineButton)
	ON_COMMAND(ID_BUTTONELLIPSE,&MockProject_PEXView::OnPerformEllipseButton)
	ON_COMMAND(ID_BUTTONCIRCLE,&MockProject_PEXView::OnPerformCircleButton)
	ON_COMMAND(ID_BUTTONTRIANGLE,&MockProject_PEXView::OnPerformTriangleButton)
	ON_COMMAND(ID_BUTTONRHOMBUS, &MockProject_PEXView::OnPerformRhombusButton)
	ON_COMMAND(ID_PENTAGON, &MockProject_PEXView::OnPerformPentagonButton)
	ON_COMMAND(ID_HEXGON, &MockProject_PEXView::OnPerformHexagonButton)

	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
	ON_WM_MOUSEMOVE()
END_MESSAGE_MAP()

// MockProject_PEXView construction/destruction

MockProject_PEXView::MockProject_PEXView()
{
	// TODO: add construction code here
	

}

MockProject_PEXView::~MockProject_PEXView()
{
}

BOOL MockProject_PEXView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

// MockProject_PEXView drawing



// MockProject_PEXView printing

BOOL MockProject_PEXView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void MockProject_PEXView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void MockProject_PEXView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}


// MockProject_PEXView diagnostics

#pragma region My Coding


void MockProject_PEXView::OnDraw(CDC* pDC)
{
	CGroup9_MockProject_PEXDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	_bmBack.DrawTo(pDC->GetSafeHdc(),0,0);
	
	// TODO: add draw code for native data here
}


void MockProject_PEXView::OnInitialUpdate()
{
	CView::OnInitialUpdate();
	GetClientRect(&_viewRect);

	_bmBack.init(_viewRect.Width(),_viewRect.Height());
	_bmContent.init(_viewRect.Width(),_viewRect.Height());

	_hdcBack = _bmBack.hGetHDC();
	_hdcContent = _bmContent.hGetHDC();

	_curShape=0;
	_curFunct=0;

}

void MockProject_PEXView::Refresh()
{
	Invalidate(false);
}
			


void MockProject_PEXView::OnLButtonDown(UINT nFlags, CPoint point)
{
	if(_curShape==0)
		return;
	_mouseMoving.SetMouseBegin(point);
}
void MockProject_PEXView::OnLButtonUp(UINT nFlags, CPoint point)
{
	if(!_mouseMoving.IsActive() || _curShape==0)
		return;
	
	_mouseMoving.InActive();
	

	if(_curShape->Draw(_hdcContent))
	{
		_listShape._Add(_curShape);
		(this->*_curFunct)();
	}
	_curShape->OnLButtonUp(nFlags,point);
}
void MockProject_PEXView::OnMouseMove(UINT nFlags, CPoint point)
{
	if(!_mouseMoving.IsActive() || _curShape==0)
		return;
	_bmContent.DrawTo(_hdcBack);
	_mouseMoving.SetMouseEnd(point);
	RECT r = _mouseMoving.GetRect();

	_curShape->SetPoint(_mouseMoving.GetMouseBegin(),_mouseMoving.GetMouseEnd());

	_curShape->Draw(_hdcBack);

	_curShape->DrawSelected(_hdcBack);



	Refresh();
}


void MockProject_PEXView::OnPerformRectButton()
{
	_curShape = new CRectangleEx();
	_curFunct = (PerformFunct)(&MockProject_PEXView::OnPerformRectButton);
}
void MockProject_PEXView::OnPerformLineButton()
{
	_curShape = new CLineEx();
	_curFunct = (PerformFunct)(&MockProject_PEXView::OnPerformLineButton);
}

void MockProject_PEXView::OnPerformEllipseButton()
{
	_curShape = new CEllipseEx();
	_curFunct = (PerformFunct)(&MockProject_PEXView::OnPerformEllipseButton);
}

void MockProject_PEXView::OnPerformCircleButton()
{
	_curShape = new CCircleEx();
	_curFunct = (PerformFunct)(&MockProject_PEXView::OnPerformCircleButton);
}

void MockProject_PEXView::OnPerformTriangleButton()
{
	_curShape = new CTriangleEx();
	_curFunct = (PerformFunct)(&MockProject_PEXView::OnPerformTriangleButton);
}

void MockProject_PEXView::OnPerformRhombusButton()
{
	_curShape = new Rhombus();
	_curFunct = (PerformFunct)(&MockProject_PEXView::OnPerformRhombusButton);
}

void MockProject_PEXView::OnPerformPentagonButton()
{
	_curShape = new CPentagonEx();
	_curFunct = (PerformFunct)(&MockProject_PEXView::OnPerformPentagonButton);
}
void MockProject_PEXView::OnPerformHexagonButton()
{
	_curShape = new CHexagonEx();
	_curFunct = (PerformFunct)(&MockProject_PEXView::OnPerformHexagonButton);
}

#pragma endregion




#ifdef _DEBUG
void MockProject_PEXView::AssertValid() const
{
	CView::AssertValid();
}

void MockProject_PEXView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CGroup9_MockProject_PEXDoc* MockProject_PEXView::GetDocument() const // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CGroup9_MockProject_PEXDoc)));
	return (CGroup9_MockProject_PEXDoc*)m_pDocument;
}
#endif //_DEBUG


// MockProject_PEXView message handlers
