
// moveView.h : CmoveView 클래스의 인터페이스
//

#pragma once


class CmoveView : public CFormView
{
protected: // serialization에서만 만들어집니다.
	CmoveView();
	DECLARE_DYNCREATE(CmoveView)

public:
#ifdef AFX_DESIGN_TIME
	enum{ IDD = IDD_MOVE_FORM };
#endif

// 특성입니다.
public:
	CmoveDoc* GetDocument() const;

// 작업입니다.
public:

// 재정의입니다.
public:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.
	virtual void OnInitialUpdate(); // 생성 후 처음 호출되었습니다.

// 구현입니다.
public:
	virtual ~CmoveView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 생성된 메시지 맵 함수
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

#ifndef _DEBUG  // moveView.cpp의 디버그 버전
inline CmoveDoc* CmoveView::GetDocument() const
   { return reinterpret_cast<CmoveDoc*>(m_pDocument); }
#endif

