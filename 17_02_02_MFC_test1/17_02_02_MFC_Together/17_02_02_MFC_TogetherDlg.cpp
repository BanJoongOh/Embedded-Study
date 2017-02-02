
// 17_02_02_MFC_TogetherDlg.cpp : 구현 파일
//

#include "stdafx.h"
#include "17_02_02_MFC_Together.h"
#include "17_02_02_MFC_TogetherDlg.h"
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


// CMy17_02_02_MFC_TogetherDlg 대화 상자



CMy17_02_02_MFC_TogetherDlg::CMy17_02_02_MFC_TogetherDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_MY17_02_02_MFC_TOGETHER_DIALOG, pParent)
	, result(_T(""))
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	num1 = 0;
	num2 = 0;
	op = 0;
}

void CMy17_02_02_MFC_TogetherDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, result);
}

BEGIN_MESSAGE_MAP(CMy17_02_02_MFC_TogetherDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_COMMAND_RANGE(IDC_BUTTON1, IDC_BUTTON10, &CMy17_02_02_MFC_TogetherDlg::OnBnClickedButton1)
	//버튼1~버튼10까지 범위 지정(RANGE), OnButton1을 1-10까지의 핸들러로 쓰겠다는 선언
/*	ON_BN_CLICKED(IDC_BUTTON2, &CMy17_02_02_MFC_TogetherDlg::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON3, &CMy17_02_02_MFC_TogetherDlg::OnBnClickedButton3)
	ON_BN_CLICKED(IDC_BUTTON4, &CMy17_02_02_MFC_TogetherDlg::OnBnClickedButton4)
	ON_BN_CLICKED(IDC_BUTTON5, &CMy17_02_02_MFC_TogetherDlg::OnBnClickedButton5)
	ON_BN_CLICKED(IDC_BUTTON6, &CMy17_02_02_MFC_TogetherDlg::OnBnClickedButton6)
	ON_BN_CLICKED(IDC_BUTTON7, &CMy17_02_02_MFC_TogetherDlg::OnBnClickedButton7)
	ON_BN_CLICKED(IDC_BUTTON8, &CMy17_02_02_MFC_TogetherDlg::OnBnClickedButton8)
	ON_BN_CLICKED(IDC_BUTTON9, &CMy17_02_02_MFC_TogetherDlg::OnBnClickedButton9)
	ON_BN_CLICKED(IDC_BUTTON10, &CMy17_02_02_MFC_TogetherDlg::OnBnClickedButton10)*/
	ON_COMMAND_RANGE(IDC_BUTTON13, IDC_BUTTON16, &CMy17_02_02_MFC_TogetherDlg::OnBnClickedButton13)
/*	ON_BN_CLICKED(IDC_BUTTON14, &CMy17_02_02_MFC_TogetherDlg::OnBnClickedButton14)
	ON_BN_CLICKED(IDC_BUTTON15, &CMy17_02_02_MFC_TogetherDlg::OnBnClickedButton15)
	ON_BN_CLICKED(IDC_BUTTON16, &CMy17_02_02_MFC_TogetherDlg::OnBnClickedButton16)*/
	ON_BN_CLICKED(IDC_BUTTON12, &CMy17_02_02_MFC_TogetherDlg::OnBnClickedButton12)
	ON_BN_CLICKED(IDC_BUTTON11, &CMy17_02_02_MFC_TogetherDlg::OnBnClickedButton11)
END_MESSAGE_MAP()


// CMy17_02_02_MFC_TogetherDlg 메시지 처리기

BOOL CMy17_02_02_MFC_TogetherDlg::OnInitDialog()
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

void CMy17_02_02_MFC_TogetherDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CMy17_02_02_MFC_TogetherDlg::OnPaint()
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
HCURSOR CMy17_02_02_MFC_TogetherDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


void CMy17_02_02_MFC_TogetherDlg::OnBnClickedButton1(UINT id)
{

	CButton *b = (CButton*)GetDlgItem(id);
	CString str = "";
	b->GetWindowText(str);
	UpdateData(true);
	result += str;
	UpdateData(false);
}

/*
void CMy17_02_02_MFC_TogetherDlg::OnBnClickedButton2(UINT id)
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
}


void CMy17_02_02_MFC_TogetherDlg::OnBnClickedButton3(UINT id)
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
}


void CMy17_02_02_MFC_TogetherDlg::OnBnClickedButton4(UINT id)
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
}


void CMy17_02_02_MFC_TogetherDlg::OnBnClickedButton5(UINT id)
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
}


void CMy17_02_02_MFC_TogetherDlg::OnBnClickedButton6(UINT id)
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
}


void CMy17_02_02_MFC_TogetherDlg::OnBnClickedButton7(UINT id)
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
}


void CMy17_02_02_MFC_TogetherDlg::OnBnClickedButton8(UINT id)
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
}


void CMy17_02_02_MFC_TogetherDlg::OnBnClickedButton9(UINT id)
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
}


void CMy17_02_02_MFC_TogetherDlg::OnBnClickedButton10(UINT id)
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
}
*/


void CMy17_02_02_MFC_TogetherDlg::OnBnClickedButton13(UINT id)	// +
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	UpdateData(true);
	num1 = _ttoi(result);
	switch (id)
	{
	case IDC_BUTTON13:
		op = 1;
		break;
	case IDC_BUTTON14:
		op = 2;
		break;
	case IDC_BUTTON15:
		op = 3;
		break;
	case IDC_BUTTON16:
		op = 4;
		break;
	}
	result = "";
	UpdateData(false);
}

/*
void CMy17_02_02_MFC_TogetherDlg::OnBnClickedButton14()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
}


void CMy17_02_02_MFC_TogetherDlg::OnBnClickedButton15()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
}


void CMy17_02_02_MFC_TogetherDlg::OnBnClickedButton16()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
}
*/

void CMy17_02_02_MFC_TogetherDlg::OnBnClickedButton12()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	UpdateData(true);	//true라서 view값을 result로 불러옴
	int x = 0;
	num2 = _ttoi(result);
	switch (op)
	{
	case 1:
		x = num1 + num2;
		break;
	case 2:
		x = num1 - num2;
		break;
	case 3:
		x = num1 * num2;
		break;
	case 4:
		if (num2 == 0)
		{
			MessageBox("계산불가능");
			break;
		}
		else
		{
			x = num1 / num2;
		}
		break;
	}
	result.Format("%d", x);
	UpdateData(false);
}


void CMy17_02_02_MFC_TogetherDlg::OnBnClickedButton11()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	result = "";
	UpdateData(false);	//false라서 변수(result)값을 view에 써줌
}


