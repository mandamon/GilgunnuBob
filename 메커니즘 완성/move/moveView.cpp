
// moveView.cpp : CmoveView Ŭ������ ����
//

#include "stdafx.h"
// SHARED_HANDLERS�� �̸� ����, ����� �׸� �� �˻� ���� ó���⸦ �����ϴ� ATL ������Ʈ���� ������ �� ������
// �ش� ������Ʈ�� ���� �ڵ带 �����ϵ��� �� �ݴϴ�.
#ifndef SHARED_HANDLERS
#include "move.h"
#endif

#include "moveDoc.h"
#include "moveView.h"
#include "Resource.h"

#include <mmsystem.h> 
#pragma comment(lib, "winmm")

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CmoveView

IMPLEMENT_DYNCREATE(CmoveView, CFormView)

BEGIN_MESSAGE_MAP(CmoveView, CFormView)
//	ON_WM_PAINT()
ON_WM_DESTROY()
ON_WM_TIMER()
ON_WM_KEYDOWN()
ON_WM_CTLCOLOR()
END_MESSAGE_MAP()

// CmoveView ����/�Ҹ�

CmoveView::CmoveView()
	: CFormView(IDD_MOVE_FORM)
{
	// TODO: ���⿡ ���� �ڵ带 �߰��մϴ�.

	m_nX = 300;
	m_nY = 600;
	dblMapMove = 4000;
	map_num = 0;
	PlaySound((LPCWSTR)MAKEINTRESOURCE(IDR_GAME_BGM), NULL, SND_ASYNC | SND_RESOURCE | SND_SYNC);
}

CmoveView::~CmoveView()
{
}

void CmoveView::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
}

BOOL CmoveView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs�� �����Ͽ� ���⿡��
	//  Window Ŭ���� �Ǵ� ��Ÿ���� �����մϴ�.

	return CFormView::PreCreateWindow(cs);
}


// CmoveView ����

#ifdef _DEBUG
void CmoveView::AssertValid() const
{
	CFormView::AssertValid();
}

void CmoveView::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}

CmoveDoc* CmoveView::GetDocument() const // ����׵��� ���� ������ �ζ������� �����˴ϴ�.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CmoveDoc)));
	return (CmoveDoc*)m_pDocument;
}
#endif //_DEBUG


// CmoveView �޽��� ó����

void CmoveView::OnDraw(CDC* pDC)
{
	// TODO: ���⿡ Ư��ȭ�� �ڵ带 �߰� ��/�Ǵ� �⺻ Ŭ������ ȣ���մϴ�.

	CmoveDoc* pDoc = GetDocument();

	ASSERT_VALID(pDoc);

	if (!pDoc)
		return;
	// TODO: ���⿡ ���� �����Ϳ� ���� �׸��� �ڵ带 �߰��մϴ�.

	CDC MemDC;

	CBitmap bmpMAP;

	if (!MemDC.CreateCompatibleDC(pDC)) return;

	if (map_num == 0) {
		if (!bmpMAP.LoadBitmap(IDB_MAP1))
			return;
	}
	else if (map_num == 1) {
		if (!bmpMAP.LoadBitmap(IDB_MAP2))
			return;
	}
	else if (map_num == 2) {
		if (!bmpMAP.LoadBitmap(IDB_MAP3))
			return;
	}
	else if (map_num == 3) {
		if (!bmpMAP.LoadBitmap(IDB_MAP4))
			return;
	}
	else if (map_num == 4) {
		if (!bmpMAP.LoadBitmap(IDB_MAP5))
			return;
	}




	MemDC.SelectObject(&bmpMAP);

	pDC->BitBlt(0, 0, 700, 1000, &MemDC, 0, 0, SRCCOPY);
	DrawMap();
	DrawBitmap();
}

void CmoveView::DrawBitmap()

{

	CClientDC dc(this);
	
	CDC MemDC;
	CBitmap bmpMan, bmpMask, bmpBack;


	if (!MemDC.CreateCompatibleDC(&dc)) 
		return;

	if (!bmpMan.LoadBitmap(IDB_BOB)) 
		return;
	if (!bmpMask.LoadBitmap(IDB_MASK)) 
		return;
	//if (!bmpBack.LoadBitmap(IDB_BACK)) 
	//	return;


	//MemDC.SelectObject(&bmpBack);

	//dc.BitBlt(m_nX, m_nY, 100, 100, &MemDC, m_nX, m_nY, SRCCOPY);

	MemDC.SelectObject(&bmpMask);

	dc.BitBlt(m_nX, m_nY, 100, 100, &MemDC, 100 * bobstate, 0, SRCAND);

	MemDC.SelectObject(&bmpMan);

	dc.BitBlt(m_nX, m_nY, 100, 100, &MemDC, 100 * bobstate, 0, SRCPAINT);


}

void CmoveView::DrawMap()
{
	CBitmap bmpMAP;
	CmoveDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	CClientDC dc(this);

	CDC MemDC, BufferDC;
	MemDC.CreateCompatibleDC(&dc);
	BufferDC.CreateCompatibleDC(&dc);

	CBitmap bmpBuffer;
	bmpBuffer.CreateCompatibleBitmap(&dc, 700, 5000);

	//	dblMapMove-=100;
	if (map_num == 0) {
		if (!bmpMAP.LoadBitmap(IDB_MAP1))
			return;
	}else if (map_num == 1) {
		if (!bmpMAP.LoadBitmap(IDB_MAP2))
			return;
	}else if (map_num == 2) {
		if (!bmpMAP.LoadBitmap(IDB_MAP3))
			return;
	}else if (map_num == 3) {
		if (!bmpMAP.LoadBitmap(IDB_MAP4))
			return;
	}else if (map_num == 4) {
		if (!bmpMAP.LoadBitmap(IDB_MAP5))
			return;
	}

	CBitmap *pOldBitmap1 = (CBitmap*)BufferDC.SelectObject(&bmpBuffer);

	CBitmap *pOldBitmap2 = (CBitmap*)MemDC.SelectObject(&bmpMAP);

	BufferDC.BitBlt(0, 0, 700, 5000, &MemDC, 0, dblMapMove, SRCCOPY);

	dc.BitBlt(0, 0, 700, 1000, &BufferDC, 0, 0, SRCCOPY);

	BufferDC.SelectObject(pOldBitmap1);
	MemDC.SelectObject(pOldBitmap2);
}



void CmoveView::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();
	
//	SetTimer(0, 100, NULL);
}

void CmoveView::OnDestroy()
{
	CFormView::OnDestroy();
//	KillTimer(0);
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰��մϴ�.
}


void CmoveView::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰� ��/�Ǵ� �⺻���� ȣ���մϴ�.
	DrawBitmap();
//	CFormView::OnTimer(nIDEvent);
}


void CmoveView::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	EraseBitmap();
	switch (nChar)
	{
	case VK_LEFT:		
		bobstate = 1;												//bobstate
		if (m_nX < 100)
			m_nX = 0;
		else
			m_nX -= 100;
		break;

	case VK_RIGHT:
		bobstate = 3;
		if (m_nX <= 700 - 100 - 100)
			m_nX += 100;
		break;

	case VK_UP:
		bobstate = 2;
		if (dblMapMove >= 400 && m_nY >= 700) {
			m_nY -= 100;
		}
		else if (dblMapMove <= 0) {													// ���� ���� �� ����
			dblMapMove = 0;	
			if (m_nY < 100) {														// �̴Ͼ� ���� ����
				m_nX = 300;
				m_nY = 600;															// �̴Ͼ� ��ġ �ʱ�ȭ
				
				if (map_num < 4)													// �� �ѹ� ����
					map_num++;
				else
					map_num = 0;
				dblMapMove = 4000;													// �� �����ġ �ʱ�ȭ
			}	
			else
				m_nY -= 100;
		}
		else
			dblMapMove -= 100;
		break;

	case VK_DOWN:
		bobstate = 0;
		if (dblMapMove >= 4000 && 800 >= m_nY) {
			dblMapMove = 4000;
			m_nY += 100;
		}
		if (dblMapMove >= 4000) {
			dblMapMove = 4000;
		}
		else if (m_nY <= 500)
				m_nY += 100;
		else
			dblMapMove += 100;
		break;
	}
	DrawMap();
	DrawBitmap();
}


void CmoveView::EraseBitmap()
{
	CClientDC dc(this);
	CDC MemDC;
	CBitmap bmpMAP;
	if (!MemDC.CreateCompatibleDC(&dc))  return;
	if (map_num == 0) {
		if (!bmpMAP.LoadBitmap(IDB_MAP1))
			return;
	}
	else if (map_num == 1) {
		if (!bmpMAP.LoadBitmap(IDB_MAP2))
			return;
	}
	else if (map_num == 2) {
		if (!bmpMAP.LoadBitmap(IDB_MAP3))
			return;
	}
	else if (map_num == 3) {
		if (!bmpMAP.LoadBitmap(IDB_MAP4))
			return;
	}
	else if (map_num == 4) {
		if (!bmpMAP.LoadBitmap(IDB_MAP5))
			return;
	}

	MemDC.SelectObject(&bmpMAP);
	dc.BitBlt(m_nX, m_nY, 100, 100, &MemDC, m_nX, m_nY, SRCCOPY);
}


HBRUSH CmoveView::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
{
//	HBRUSH hbr = CFormView::OnCtlColor(pDC, pWnd, nCtlColor);
	HBRUSH hbr = CreateSolidBrush(RGB(255, 255, 255));

	return hbr;
}
