
// 17_02_02_MFC_test2Dlg.h : ��� ����
//

#pragma once


// CMy17_02_02_MFC_test2Dlg ��ȭ ����
class CMy17_02_02_MFC_test2Dlg : public CDialogEx
{
// �����Դϴ�.
public:
	CMy17_02_02_MFC_test2Dlg(CWnd* pParent = NULL);	// ǥ�� �������Դϴ�.

// ��ȭ ���� �������Դϴ�.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MY17_02_02_MFC_TEST2_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV �����Դϴ�.


// �����Դϴ�.
protected:
	HICON m_hIcon;

	// ������ �޽��� �� �Լ�
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	BOOL c1;
	BOOL c2;
	afx_msg void OnBnClickedCheck1();
	afx_msg void OnBnClickedCheck2();
	afx_msg void OnBnClickedButton1();
	int r;
	afx_msg void OnBnClickedRadio1();
	afx_msg void OnBnClickedRadio2();
	CString mycombo;
	afx_msg void OnCbnSelchangeCombo1();
	afx_msg void OnBnClickedRadio3();
};
