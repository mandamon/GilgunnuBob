
// prj_crossy_ver_sdi.h : prj_crossy_ver_sdi ���� ���α׷��� ���� �� ��� ����
//
#pragma once

#ifndef __AFXWIN_H__
	#error "PCH�� ���� �� ������ �����ϱ� ���� 'stdafx.h'�� �����մϴ�."
#endif

#include "resource.h"       // �� ��ȣ�Դϴ�.


// Cprj_crossy_ver_sdiApp:
// �� Ŭ������ ������ ���ؼ��� prj_crossy_ver_sdi.cpp�� �����Ͻʽÿ�.
//

class Cprj_crossy_ver_sdiApp : public CWinApp
{
public:
	Cprj_crossy_ver_sdiApp();


// �������Դϴ�.
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// �����Դϴ�.
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern Cprj_crossy_ver_sdiApp theApp;
