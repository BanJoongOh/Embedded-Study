
// 17_02_02_MFC_TogetherDlg.h : 헤더 파일
//

#pragma once


// CMy17_02_02_MFC_TogetherDlg 대화 상자
class CMy17_02_02_MFC_TogetherDlg : public CDialogEx
{
// 생성입니다.
public:
	CMy17_02_02_MFC_TogetherDlg(CWnd* pParent = NULL);	// 표준 생성자입니다.

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MY17_02_02_MFC_TOGETHER_DIALOG };
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
	CString result;
	afx_msg void OnBnClickedButton1(UINT id);
	/*afx_msg void OnBnClickedButton2(UINT id);
	afx_msg void OnBnClickedButton3(UINT id);
	afx_msg void OnBnClickedButton4(UINT id);
	afx_msg void OnBnClickedButton5(UINT id);
	afx_msg void OnBnClickedButton6(UINT id);
	afx_msg void OnBnClickedButton7(UINT id);
	afx_msg void OnBnClickedButton8(UINT id);
	afx_msg void OnBnClickedButton9(UINT id);
	afx_msg void OnBnClickedButton10(UINT id);*/
	int num1;
	int num2;
	int op;
	afx_msg void OnBnClickedButton13(UINT id);
	/*afx_msg void OnBnClickedButton14();
	afx_msg void OnBnClickedButton15();
	afx_msg void OnBnClickedButton16();*/
	afx_msg void OnBnClickedButton12();
	afx_msg void OnBnClickedButton11();
};
