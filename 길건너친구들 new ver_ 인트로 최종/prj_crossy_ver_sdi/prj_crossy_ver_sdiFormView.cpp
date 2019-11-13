
// prj_crossy_ver_sdiFormView.cpp : Cprj_crossy_ver_sdiFormView 클래스의 구현
//

#include "stdafx.h"
// SHARED_HANDLERS는 미리 보기, 축소판 그림 및 검색 필터 처리기를 구현하는 ATL 프로젝트에서 정의할 수 있으며
// 해당 프로젝트와 문서 코드를 공유하도록 해 줍니다.
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

// Cprj_crossy_ver_sdiFormView 생성/소멸

Cprj_crossy_ver_sdiFormView::Cprj_crossy_ver_sdiFormView()
	: CFormView(IDD_PRJ_CROSSY_VER_SDI_FORM)
{
	// TODO: 여기에 생성 코드를 추가합니다.

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
	// TODO: CREATESTRUCT cs를 수정하여 여기에서
	//  Window 클래스 또는 스타일을 수정합니다.

	return CFormView::PreCreateWindow(cs);
}

void Cprj_crossy_ver_sdiFormView::OnInitialUpdate()
{
	PlaySound((LPCWSTR)MAKEINTRESOURCE(IDR_INTRO_BGM), NULL, SND_ASYNC | SND_RESOURCE | SND_SYNC);
	CFormView::OnInitialUpdate();
	GetParentFrame()->RecalcLayout();
	ResizeParentToFit();

}


// Cprj_crossy_ver_sdiFormView 진단

#ifdef _DEBUG
void Cprj_crossy_ver_sdiFormView::AssertValid() const
{
	CFormView::AssertValid();
}

void Cprj_crossy_ver_sdiFormView::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}

Cprj_crossy_ver_sdiDoc* Cprj_crossy_ver_sdiFormView::GetDocument() const // 디버그되지 않은 버전은 인라인으로 지정됩니다.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(Cprj_crossy_ver_sdiDoc)));
	return (Cprj_crossy_ver_sdiDoc*)m_pDocument;
}
#endif //_DEBUG


// Cprj_crossy_ver_sdiFormView 메시지 처리기


void Cprj_crossy_ver_sdiFormView::OnPaint()
{
	CPaintDC dc(this); 

	CDC	MemDC;

	BITMAP bmpInfo;

	MemDC.CreateCompatibleDC(&dc);

	CBitmap bmp;						
	bmp.LoadBitmapW(IDB_BACK);	// 비트맵 리소스를 로딩한다.
	
	bmp.GetBitmap(&bmpInfo);			// 로딩된 비트맵의 정보(비트맵 구조체에 저장되어있는)를 알아본다.

	CBitmap *pOldBmp = MemDC.SelectObject(&bmp);	// 메모리 DC에 비트맵을 선택하도록 한다.
	
	dc.BitBlt(0, 0, bmpInfo.bmWidth, bmpInfo.bmHeight, &MemDC, 0, 0, SRCCOPY);	// 메모리 DC에 들어있는 비트맵을 화면 DC로 복사하여 출력한다.

	MemDC.SelectObject(pOldBmp);
}


void Cprj_crossy_ver_sdiFormView::OnBnClickedButtonStart()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
}


void Cprj_crossy_ver_sdiFormView::OnBnClickedButtonExit()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	AfxGetMainWnd()->PostMessage(WM_CLOSE);
}
