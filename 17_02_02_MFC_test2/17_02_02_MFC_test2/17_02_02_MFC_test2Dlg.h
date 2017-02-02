
// 17_02_02_MFC_test2Dlg.h : 헤더 파일
//

#pragma once


// CMy17_02_02_MFC_test2Dlg 대화 상자
class CMy17_02_02_MFC_test2Dlg : public CDialogEx
{
// 생성입니다.
public:
	CMy17_02_02_MFC_test2Dlg(CWnd* pParent = NULL);	// 표준 생성자입니다.

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MY17_02_02_MFC_TEST2_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 지원입니다.


// 구현입니다.
protected:
	HICON m_hIcon;

	// 생성된 메시지 맵 함수
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
