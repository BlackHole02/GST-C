
// Group9_MockProject_PEXDoc.cpp : implementation of the CGroup9_MockProject_PEXDoc class
//

#include "stdafx.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "Group9_MockProject_PEX.h"
#endif

#include "Group9_MockProject_PEXDoc.h"

#include <propkey.h>

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// CGroup9_MockProject_PEXDoc

IMPLEMENT_DYNCREATE(CGroup9_MockProject_PEXDoc, CDocument)

BEGIN_MESSAGE_MAP(CGroup9_MockProject_PEXDoc, CDocument)
END_MESSAGE_MAP()


// CGroup9_MockProject_PEXDoc construction/destruction

CGroup9_MockProject_PEXDoc::CGroup9_MockProject_PEXDoc()
{
	// TODO: add one-time construction code here

}

CGroup9_MockProject_PEXDoc::~CGroup9_MockProject_PEXDoc()
{
}

BOOL CGroup9_MockProject_PEXDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}




// CGroup9_MockProject_PEXDoc serialization

void CGroup9_MockProject_PEXDoc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: add storing code here
	}
	else
	{
		// TODO: add loading code here
	}
}

#ifdef SHARED_HANDLERS

// Support for thumbnails
void CGroup9_MockProject_PEXDoc::OnDrawThumbnail(CDC& dc, LPRECT lprcBounds)
{
	// Modify this code to draw the document's data
	dc.FillSolidRect(lprcBounds, RGB(255, 255, 255));

	CString strText = _T("TODO: implement thumbnail drawing here");
	LOGFONT lf;

	CFont* pDefaultGUIFont = CFont::FromHandle((HFONT) GetStockObject(DEFAULT_GUI_FONT));
	pDefaultGUIFont->GetLogFont(&lf);
	lf.lfHeight = 36;

	CFont fontDraw;
	fontDraw.CreateFontIndirect(&lf);

	CFont* pOldFont = dc.SelectObject(&fontDraw);
	dc.DrawText(strText, lprcBounds, DT_CENTER | DT_WORDBREAK);
	dc.SelectObject(pOldFont);
}

// Support for Search Handlers
void CGroup9_MockProject_PEXDoc::InitializeSearchContent()
{
	CString strSearchContent;
	// Set search contents from document's data. 
	// The content parts should be separated by ";"

	// For example:  strSearchContent = _T("point;rectangle;circle;ole object;");
	SetSearchContent(strSearchContent);
}

void CGroup9_MockProject_PEXDoc::SetSearchContent(const CString& value)
{
	if (value.IsEmpty())
	{
		RemoveChunk(PKEY_Search_Contents.fmtid, PKEY_Search_Contents.pid);
	}
	else
	{
		CMFCFilterChunkValueImpl *pChunk = NULL;
		ATLTRY(pChunk = new CMFCFilterChunkValueImpl);
		if (pChunk != NULL)
		{
			pChunk->SetTextValue(PKEY_Search_Contents, value, CHUNK_TEXT);
			SetChunkValue(pChunk);
		}
	}
}

#endif // SHARED_HANDLERS

// CGroup9_MockProject_PEXDoc diagnostics

#ifdef _DEBUG
void CGroup9_MockProject_PEXDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CGroup9_MockProject_PEXDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// CGroup9_MockProject_PEXDoc commands
