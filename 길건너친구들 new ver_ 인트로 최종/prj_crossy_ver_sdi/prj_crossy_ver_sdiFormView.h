
// prj_crossy_ver_sdiFormView.h : Cprj_crossy_ver_sdiFormView 클래스의 인터페이스
//

#pragma once


class Cprj_crossy_ver_sdiFormView : public CFormView
{
protected: // serialization에서만 만들어집니다.
	Cprj_crossy_ver_sdiFormView();
	DECLARE_DYNCREATE(Cprj_crossy_ver_sdiFormView)

public:
#ifdef AFX_DESIGN_TIME
	enum{ IDD = IDD_PRJ_CROSSY_VER_SDI_FORM };
#endif

// 특성입니다.
public:
	Cprj_crossy_ver_sdiDoc* GetDocument() const;

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
	virtual ~Cprj_crossy_ver_sdiFormView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 생성된 메시지 맵 함수
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnPaint();
	afx_msg void OnBnClickedButtonStart();
	afx_msg void OnBnClickedButtonExit();
};

#ifndef _DEBUG  // prj_crossy_ver_sdiFormView.cpp의 디버그 버전
inline Cprj_crossy_ver_sdiDoc* Cprj_crossy_ver_sdiFormView::GetDocument() const
   { return reinterpret_cast<Cprj_crossy_ver_sdiDoc*>(m_pDocument); }
#endif

