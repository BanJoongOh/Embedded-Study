
// 17_02_02_MFC_test2Dlg.cpp : 구현 파일
//

#include "stdafx.h"
#include "17_02_02_MFC_test2.h"
#include "17_02_02_MFC_test2Dlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 응용 프로그램 정보에 사용되는 CAboutDlg 대화 상자입니다.

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

// 구현입니다.
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CMy17_02_02_MFC_test2Dlg 대화 상자



CMy17_02_02_MFC_test2Dlg::CMy17_02_02_MFC_test2Dlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_MY17_02_02_MFC_TEST2_DIALOG, pParent)
	, c1(FALSE)
	, c2(FALSE)
	, r(0)
	, mycombo(_T(""))
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMy17_02_02_MFC_test2Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Check(pDX, IDC_CHECK1, c1);
	DDX_Check(pDX, IDC_CHECK2, c2);
	DDX_CBString(pDX, IDC_COMBO1, mycombo);
}

BEGIN_MESSAGE_MAP(CMy17_02_02_MFC_test2Dlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_CHECK1, &CMy17_02_02_MFC_test2Dlg::OnBnClickedCheck1)
	ON_BN_CLICKED(IDC_CHECK2, &CMy17_02_02_MFC_test2Dlg::OnBnClickedCheck2)
	ON_BN_CLICKED(IDC_BUTTON1, &CMy17_02_02_MFC_test2Dlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_RADIO1, &CMy17_02_02_MFC_test2Dlg::OnBnClickedRadio1)
	ON_BN_CLICKED(IDC_RADIO2, &CMy17_02_02_MFC_test2Dlg::OnBnClickedRadio2)
	ON_CBN_SELCHANGE(IDC_COMBO1, &CMy17_02_02_MFC_test2Dlg::OnCbnSelchangeCombo1)
	ON_BN_CLICKED(IDC_RADIO3, &CMy17_02_02_MFC_test2Dlg::OnBnClickedRadio3)
END_MESSAGE_MAP()


// CMy17_02_02_MFC_test2Dlg 메시지 처리기

BOOL CMy17_02_02_MFC_test2Dlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 시스템 메뉴에 "정보..." 메뉴 항목을 추가합니다.

	// IDM_ABOUTBOX는 시스템 명령 범위에 있어야 합니다.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// 이 대화 상자의 아이콘을 설정합니다.  응용 프로그램의 주 창이 대화 상자가 아닐 경우에는
	//  프레임워크가 이 작업을 자동으로 수행합니다.
	SetIcon(m_hIcon, TRUE);			// 큰 아이콘을 설정합니다.
	SetIcon(m_hIcon, FALSE);		// 작은 아이콘을 설정합니다.

	// TODO: 여기에 추가 초기화 작업을 추가합니다.

	return TRUE;  // 포커스를 컨트롤에 설정하지 않으면 TRUE를 반환합니다.
}

void CMy17_02_02_MFC_test2Dlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// 대화 상자에 최소화 단추를 추가할 경우 아이콘을 그리려면
//  아래 코드가 필요합니다.  문서/뷰 모델을 사용하는 MFC 응용 프로그램의 경우에는
//  프레임워크에서 이 작업을 자동으로 수행합니다.

void CMy17_02_02_MFC_test2Dlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 그리기를 위한 디바이스 컨텍스트입니다.

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 클라이언트 사각형에서 아이콘을 가운데에 맞춥니다.
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 아이콘을 그립니다.
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// 사용자가 최소화된 창을 끄는 동안에 커서가 표시되도록 시스템에서
//  이 함수를 호출합니다.
HCURSOR CMy17_02_02_MFC_test2Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CMy17_02_02_MFC_test2Dlg::OnBnClickedCheck1()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	UpdateData(true);

}


void CMy17_02_02_MFC_test2Dlg::OnBnClickedCheck2()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	UpdateData(true);
}


void CMy17_02_02_MFC_test2Dlg::OnBnClickedButton1()	//check박스 선택유무
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	CString str = "";
	/*
	if (c1)	//////////////////check box는 그룹을하여 여러개 선택 가능하게
	{
		str += "check1이 선택됨\n";
		MessageBox(str);
	}
	if (c2)
	{
		str += "check2가 선택됨\n";
		MessageBox(str);
	}
	switch (r)/////////////radio box는 그룹하지않고 한개만 선택 가능하게
	{
	case 1:
		str += "radio1이 선택됨\n";
		MessageBox(str);
		break;
	case 2:
		str += "radio2이 선택됨\n";
		MessageBox(str);
		break;
	}
	*/

	
	switch (r)
	{
	case 1:
		UpdateData(true);
		if (mycombo == "노트북")
			MessageBox("노트북");
		else if (mycombo == "냉장고")
			MessageBox("냉장고");
		else if (mycombo == "TV")
			MessageBox("TV");
		else if (mycombo == "컴퓨터")
			MessageBox("컴퓨터");
		break;
	case 2:
		UpdateData(true);
		if (mycombo == "보리밥")
			MessageBox("보리밥");
		else if (mycombo == "육회")
			MessageBox("육회");
		else if (mycombo == "고등어")
			MessageBox("고등어");
		else if (mycombo == "카레")
			MessageBox("카레");
		break;
	case 3:
		UpdateData(true);
		if (mycombo == "딸기")
			MessageBox("딸기");
		else if (mycombo == "메론")
			MessageBox("메론");
		else if (mycombo == "천혜향")
			MessageBox("천혜향");
		else if (mycombo == "귤")
			MessageBox("귤");
		break;
	}
	
	
}


void CMy17_02_02_MFC_test2Dlg::OnBnClickedRadio1()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	r = 1;

	CComboBox *c = (CComboBox*)GetDlgItem(IDC_COMBO1);
	int i = 1;
	while (i > 0)
		i = c->DeleteString(0);	//남은항목이 반환됨, 삭제는 맨위 그리고 아래항목이 위로 올라감

	c->AddString("노트북"); //combo1 data 새로쓰기
	c->AddString("냉장고");
	c->AddString("TV");
	c->AddString("컴퓨터");
}


void CMy17_02_02_MFC_test2Dlg::OnBnClickedRadio2()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	r = 2;

	CComboBox *c = (CComboBox*)GetDlgItem(IDC_COMBO1);
	int i = 1;
	while (i > 0)
		i = c->DeleteString(0);	//남은항목이 반환됨, 삭제는 맨위 그리고 아래항목이 위로 올라감

	c->AddString("보리밥"); //combo1 data 새로쓰기
	c->AddString("육회");
	c->AddString("고등어");
	c->AddString("카레");
}

void CMy17_02_02_MFC_test2Dlg::OnBnClickedRadio3()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	r = 3;

	CComboBox *c = (CComboBox*)GetDlgItem(IDC_COMBO1);
	int i = 1;
	while (i > 0)
		i = c->DeleteString(0);	//남은항목이 반환됨, 삭제는 맨위 그리고 아래항목이 위로 올라감

	c->AddString("딸기");	//combo1 data 새로쓰기
	c->AddString("메론");
	c->AddString("천혜향");
	c->AddString("귤");
}

void CMy17_02_02_MFC_test2Dlg::OnCbnSelchangeCombo1()
{//1.딸기;2.메론;3.천혜향;4.귤
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	
}


