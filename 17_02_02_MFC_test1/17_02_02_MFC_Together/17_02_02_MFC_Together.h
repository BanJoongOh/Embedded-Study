
// 17_02_02_MFC_Together.h : PROJECT_NAME ���� ���α׷��� ���� �� ��� �����Դϴ�.
//

#pragma once

#ifndef __AFXWIN_H__
	#error "PCH�� ���� �� ������ �����ϱ� ���� 'stdafx.h'�� �����մϴ�."
#endif

#include "resource.h"		// �� ��ȣ�Դϴ�.


// CMy17_02_02_MFC_TogetherApp:
// �� Ŭ������ ������ ���ؼ��� 17_02_02_MFC_Together.cpp�� �����Ͻʽÿ�.
//

class CMy17_02_02_MFC_TogetherApp : public CWinApp
{
public:
	CMy17_02_02_MFC_TogetherApp();

// �������Դϴ�.
public:
	virtual BOOL InitInstance();

// �����Դϴ�.

	DECLARE_MESSAGE_MAP()
};

extern CMy17_02_02_MFC_TogetherApp theApp;