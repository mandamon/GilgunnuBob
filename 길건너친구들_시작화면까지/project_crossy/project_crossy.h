
// project_crossy.h : PROJECT_NAME ���� ���α׷��� ���� �� ��� �����Դϴ�.
//

#pragma once

#ifndef __AFXWIN_H__
	#error "PCH�� ���� �� ������ �����ϱ� ���� 'stdafx.h'�� �����մϴ�."
#endif

#include "resource.h"		// �� ��ȣ�Դϴ�.


// Cproject_crossyApp:
// �� Ŭ������ ������ ���ؼ��� project_crossy.cpp�� �����Ͻʽÿ�.
//

class Cproject_crossyApp : public CWinApp
{
public:
	Cproject_crossyApp();

// �������Դϴ�.
public:
	virtual BOOL InitInstance();

// �����Դϴ�.

	DECLARE_MESSAGE_MAP()
};

extern Cproject_crossyApp theApp;