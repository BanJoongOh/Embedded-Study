
// 17_02_02_MFC_test2.h : PROJECT_NAME ���� ���α׷��� ���� �� ��� �����Դϴ�.
//

#pragma once

#ifndef __AFXWIN_H__
	#error "PCH�� ���� �� ������ �����ϱ� ���� 'stdafx.h'�� �����մϴ�."
#endif

#include "resource.h"		// �� ��ȣ�Դϴ�.


// CMy17_02_02_MFC_test2App:
// �� Ŭ������ ������ ���ؼ��� 17_02_02_MFC_test2.cpp�� �����Ͻʽÿ�.
//

class CMy17_02_02_MFC_test2App : public CWinApp
{
public:
	CMy17_02_02_MFC_test2App();

// �������Դϴ�.
public:
	virtual BOOL InitInstance();

// �����Դϴ�.

	DECLARE_MESSAGE_MAP()
};

extern CMy17_02_02_MFC_test2App theApp;