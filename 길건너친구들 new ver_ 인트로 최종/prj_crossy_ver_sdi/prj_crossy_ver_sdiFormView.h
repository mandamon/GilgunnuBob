
// prj_crossy_ver_sdiFormView.h : Cprj_crossy_ver_sdiFormView Ŭ������ �������̽�
//

#pragma once


class Cprj_crossy_ver_sdiFormView : public CFormView
{
protected: // serialization������ ��������ϴ�.
	Cprj_crossy_ver_sdiFormView();
	DECLARE_DYNCREATE(Cprj_crossy_ver_sdiFormView)

public:
#ifdef AFX_DESIGN_TIME
	enum{ IDD = IDD_PRJ_CROSSY_VER_SDI_FORM };
#endif

// Ư���Դϴ�.
public:
	Cprj_crossy_ver_sdiDoc* GetDocument() const;

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
	virtual ~Cprj_crossy_ver_sdiFormView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ������ �޽��� �� �Լ�
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnPaint();
	afx_msg void OnBnClickedButtonStart();
	afx_msg void OnBnClickedButtonExit();
};

#ifndef _DEBUG  // prj_crossy_ver_sdiFormView.cpp�� ����� ����
inline Cprj_crossy_ver_sdiDoc* Cprj_crossy_ver_sdiFormView::GetDocument() const
   { return reinterpret_cast<Cprj_crossy_ver_sdiDoc*>(m_pDocument); }
#endif

