
// prj_crossy_ver_sdiFormView.cpp : Cprj_crossy_ver_sdiFormView Ŭ������ ����
//

#include "stdafx.h"
// SHARED_HANDLERS�� �̸� ����, ����� �׸� �� �˻� ���� ó���⸦ �����ϴ� ATL ������Ʈ���� ������ �� ������
// �ش� ������Ʈ�� ���� �ڵ带 �����ϵ��� �� �ݴϴ�.
#ifndef SHARED_HANDLERS
#include "prj_crossy_ver_sdi.h"
#endif

#include "prj_crossy_ver_sdiDoc.h"
#include "prj_crossy_ver_sdiFormView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

#include <mmsystem.h> 


#pragma comment(lib, "winmm")


// Cprj_crossy_ver_sdiFormView

IMPLEMENT_DYNCREATE(Cprj_crossy_ver_sdiFormView, CFormView)

BEGIN_MESSAGE_MAP(Cprj_crossy_ver_sdiFormView, CFormView)
	ON_WM_GETMINMAXINFO()
	ON_WM_PAINT()
	ON_BN_CLICKED(IDC_BUTTON_START, &Cprj_crossy_ver_sdiFormView::OnBnClickedButtonStart)
	ON_BN_CLICKED(IDC_BUTTON_EXIT, &Cprj_crossy_ver_sdiFormView::OnBnClickedButtonExit)
END_MESSAGE_MAP()

// Cprj_crossy_ver_sdiFormView ����/�Ҹ�

Cprj_crossy_ver_sdiFormView::Cprj_crossy_ver_sdiFormView()
	: CFormView(IDD_PRJ_CROSSY_VER_SDI_FORM)
{
	// TODO: ���⿡ ���� �ڵ带 �߰��մϴ�.

}

Cprj_crossy_ver_sdiFormView::~Cprj_crossy_ver_sdiFormView()
{
}

void Cprj_crossy_ver_sdiFormView::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
}

BOOL Cprj_crossy_ver_sdiFormView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs�� �����Ͽ� ���⿡��
	//  Window Ŭ���� �Ǵ� ��Ÿ���� �����մϴ�.

	return CFormView::PreCreateWindow(cs);
}

void Cprj_crossy_ver_sdiFormView::OnInitialUpdate()
{
	PlaySound((LPCWSTR)MAKEINTRESOURCE(IDR_INTRO_BGM), NULL, SND_ASYNC | SND_RESOURCE | SND_SYNC);
	CFormView::OnInitialUpdate();
	GetParentFrame()->RecalcLayout();
	ResizeParentToFit();

}


// Cprj_crossy_ver_sdiFormView ����

#ifdef _DEBUG
void Cprj_crossy_ver_sdiFormView::AssertValid() const
{
	CFormView::AssertValid();
}

void Cprj_crossy_ver_sdiFormView::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}

Cprj_crossy_ver_sdiDoc* Cprj_crossy_ver_sdiFormView::GetDocument() const // ����׵��� ���� ������ �ζ������� �����˴ϴ�.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(Cprj_crossy_ver_sdiDoc)));
	return (Cprj_crossy_ver_sdiDoc*)m_pDocument;
}
#endif //_DEBUG


// Cprj_crossy_ver_sdiFormView �޽��� ó����


void Cprj_crossy_ver_sdiFormView::OnPaint()
{
	CPaintDC dc(this); 

	CDC	MemDC;

	BITMAP bmpInfo;

	MemDC.CreateCompatibleDC(&dc);

	CBitmap bmp;						
	bmp.LoadBitmapW(IDB_BACK);	// ��Ʈ�� ���ҽ��� �ε��Ѵ�.
	
	bmp.GetBitmap(&bmpInfo);			// �ε��� ��Ʈ���� ����(��Ʈ�� ����ü�� ����Ǿ��ִ�)�� �˾ƺ���.

	CBitmap *pOldBmp = MemDC.SelectObject(&bmp);	// �޸� DC�� ��Ʈ���� �����ϵ��� �Ѵ�.
	
	dc.BitBlt(0, 0, bmpInfo.bmWidth, bmpInfo.bmHeight, &MemDC, 0, 0, SRCCOPY);	// �޸� DC�� ����ִ� ��Ʈ���� ȭ�� DC�� �����Ͽ� ����Ѵ�.

	MemDC.SelectObject(pOldBmp);
}


void Cprj_crossy_ver_sdiFormView::OnBnClickedButtonStart()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
}


void Cprj_crossy_ver_sdiFormView::OnBnClickedButtonExit()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	AfxGetMainWnd()->PostMessage(WM_CLOSE);
}
