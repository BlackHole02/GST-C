
// Group9_Mock_PEXView.cpp : implementation of the ViewClass class
//

#include "stdafx.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "Group9_Mock_PEX.h"
#endif

#include "Group9_Mock_PEXDoc.h"
#include "Group9_Mock_PEXView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// ViewClass

IMPLEMENT_DYNCREATE(ViewClass, CView)

BEGIN_MESSAGE_MAP(ViewClass, CView)
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_COMMAND(ID_BUTTON32771, &ViewClass::DrawLine)
	ON_COMMAND(ID_BUTTON32772, &ViewClass::DrawRectangle)
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
	ON_WM_MOUSEMOVE()
END_MESSAGE_MAP()

// ViewClass construction/destruction


void ViewClass::DrawLine()
{
	_CurrentType = LINE;
}
void ViewClass::DrawRectangle()
{
	_CurrentType = RECTANGLE;
}

HDC ViewClass::hdcView = 0;
HDC ViewClass::hdcSubView = 0;
HDC ViewClass::curHdc = 0;
RECT ViewClass::rectView;

void ViewClass::Referesh(bool withSubHDC)
{
	int w, h;
	w = rectView.right - rectView.left;
	h = rectView.bottom - rectView.top;
	static CBitmapEx bmView(w, h);
	static CBitmapEx bmSubView(w, h);
	static CBitmapEx curBm(w, h);

	static bool LoadDrawing = false;
	if (!LoadDrawing)
	{
		hdcView = bmView.hGetHDC();
		hdcSubView = bmSubView.hGetHDC();
		LoadDrawing = true;
	}
	static CHdcController ctrView(hdcView);
	static CHdcController ctrSubView(hdcSubView);
	static CHdcController ctrCur(curHdc);
	static CHdcController ctrBm(curBm);
	ctrBm.Clear(RGB(255, 255, 255), 0, 0, w, h);
	ctrBm.DrawFromOtherHDC(hdcView,
		w,
		h,
		PM_TRANSPARENTSECTION
		);
	if (withSubHDC)
	{
		ctrView.DrawImage(bmSubView, PM_TRANSPARENTSECTION);
	}
	ctrBm.DrawFromOtherHDC(ctrSubView.getHDC(),
		w,
		h,
		PM_TRANSPARENTSECTION);
	ctrSubView.Clear(RGB(255, 255, 255), 0, 0, w, h);
	ctrCur.DrawImage(curBm);
}

ViewClass::ViewClass()
{
	// TODO: add construction code here
	_CurrentType = ARROW;
}

ViewClass::~ViewClass()
{
}


BOOL ViewClass::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

// ViewClass drawing

void ViewClass::OnDraw(CDC* /*pDC*/)
{
	DocClass* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	GetClientRect(&rectView);
	static bool LoadDrawing = false;
	if (!LoadDrawing)
	{
		curHdc = ::GetDC(this->GetSafeHwnd());
		LoadDrawing = true;


	}
	
	Referesh(false);
}


// ViewClass printing

BOOL ViewClass::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void ViewClass::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void ViewClass::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}


// ViewClass diagnostics

#ifdef _DEBUG
void ViewClass::AssertValid() const
{
	CView::AssertValid();
}

void ViewClass::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

DocClass* ViewClass::GetDocument() const // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(DocClass)));
	return (DocClass*)m_pDocument;
}

#endif //_DEBUG
void ViewClass::AddToListShape()
{
	switch (_CurrentType)
	{
	case ARROW:
		break;
	case LINE:	
		_shapeEx = new CLineEx();
		break;
	case RECTANGLE:
		_shapeEx = new CRectangleEx();
		break;
	default:
		break;
	}
	_shapeEx->SetPenStyle(1, PS_SOLID, RGB(0, 0, 0));
}
CShapeEx *ViewClass::GetShapeEx()
{
	return _shapeEx;
}
void ViewClass::OnLButtonDown(UINT nFlags, CPoint point) // bat dau lick chuot
{
	AddToListShape();
	_mouseMoving.SetMouseBegin(point);
	
}
void ViewClass::OnLButtonUp(UINT nFlags, CPoint point) // ket thuc
{
//	Referesh(true);
	if (_shapeEx->Draw(hdcView))
	{
		listShape._Add(_shapeEx);
		_shapeEx->DrawSelected(hdcView);
	}
	Referesh(false);
	_mouseMoving.InActive();
}
void ViewClass::OnMouseMove(UINT nFlags, CPoint point) // xu ly ve, di chuyen chuot
{
	if (_mouseMoving.IsActive())
	{
		_mouseMoving.SetMouseEnd(point);
		_shapeEx->SetPoint(_mouseMoving.GetMouseBegin(), _mouseMoving.GetMouseEnd());
		_shapeEx->Draw(hdcSubView);
		Referesh(false);
	}
}

// ViewClass message handlers
