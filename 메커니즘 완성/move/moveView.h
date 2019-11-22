
// moveView.h : CmoveView Ŭ������ �������̽�
//

#pragma once


class CmoveView : public CFormView
{
protected: // serialization������ ��������ϴ�.
	CmoveView();
	DECLARE_DYNCREATE(CmoveView)

public:
#ifdef AFX_DESIGN_TIME
	enum{ IDD = IDD_MOVE_FORM };
#endif

// Ư���Դϴ�.
public:
	CmoveDoc* GetDocument() const;

// �۾��Դϴ�.
public:

// �������Դϴ�.
public:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.
	virtual void OnInitialUpdate(); // ���� �� ó�� ȣ��Ǿ����ϴ�.

// �����Դϴ�.
public:
	virtual ~CmoveView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ������ �޽��� �� �Լ�
protected:
	DECLARE_MESSAGE_MAP()
public:
	virtual void OnDraw(CDC* /*pDC*/);
	void DrawBitmap();
	void DrawMap();
	afx_msg void OnDestroy();
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	afx_msg void OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags);
	int m_nX;
	int m_nY;
	int bobstate=0;
	void EraseBitmap();
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	double dblMapMove;
	int map_num;
};

#ifndef _DEBUG  // moveView.cpp�� ����� ����
inline CmoveDoc* CmoveView::GetDocument() const
   { return reinterpret_cast<CmoveDoc*>(m_pDocument); }
#endif

