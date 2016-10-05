
// Project1View.cpp : implementation of the CProject1View class
//

#include "stdafx.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "Project1.h"
#endif

#include "Project1Doc.h"
#include "Project1View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CProject1View

IMPLEMENT_DYNCREATE(CProject1View, CView)

BEGIN_MESSAGE_MAP(CProject1View, CView)
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CProject1View::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
END_MESSAGE_MAP()

// CProject1View construction/destruction

CProject1View::CProject1View()
{
	// TODO: add construction code here

}

CProject1View::~CProject1View()
{
}

BOOL CProject1View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

// CProject1View drawing

void CProject1View::OnDraw(CDC* /*pDC*/)
{
	CProject1Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: add draw code for native data here
}


// CProject1View printing


void CProject1View::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL CProject1View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CProject1View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CProject1View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

void CProject1View::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CProject1View::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CProject1View diagnostics

#ifdef _DEBUG
void CProject1View::AssertValid() const
{
	CView::AssertValid();
}

void CProject1View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CProject1Doc* CProject1View::GetDocument() const // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CProject1Doc)));
	return (CProject1Doc*)m_pDocument;
}
#endif //_DEBUG


// CProject1View message handlers
