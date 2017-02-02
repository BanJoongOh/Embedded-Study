
// 17_02_02_MFC_TogetherDlg.cpp : ���� ����
//

#include "stdafx.h"
#include "17_02_02_MFC_Together.h"
#include "17_02_02_MFC_TogetherDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// ���� ���α׷� ������ ���Ǵ� CAboutDlg ��ȭ �����Դϴ�.

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// ��ȭ ���� �������Դϴ�.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

// �����Դϴ�.
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


// CMy17_02_02_MFC_TogetherDlg ��ȭ ����



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
	//��ư1~��ư10���� ���� ����(RANGE), OnButton1�� 1-10������ �ڵ鷯�� ���ڴٴ� ����
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


// CMy17_02_02_MFC_TogetherDlg �޽��� ó����

BOOL CMy17_02_02_MFC_TogetherDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// �ý��� �޴��� "����..." �޴� �׸��� �߰��մϴ�.

	// IDM_ABOUTBOX�� �ý��� ��� ������ �־�� �մϴ�.
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

	// �� ��ȭ ������ �������� �����մϴ�.  ���� ���α׷��� �� â�� ��ȭ ���ڰ� �ƴ� ��쿡��
	//  �����ӿ�ũ�� �� �۾��� �ڵ����� �����մϴ�.
	SetIcon(m_hIcon, TRUE);			// ū �������� �����մϴ�.
	SetIcon(m_hIcon, FALSE);		// ���� �������� �����մϴ�.

	// TODO: ���⿡ �߰� �ʱ�ȭ �۾��� �߰��մϴ�.

	return TRUE;  // ��Ŀ���� ��Ʈ�ѿ� �������� ������ TRUE�� ��ȯ�մϴ�.
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

// ��ȭ ���ڿ� �ּ�ȭ ���߸� �߰��� ��� �������� �׸�����
//  �Ʒ� �ڵ尡 �ʿ��մϴ�.  ����/�� ���� ����ϴ� MFC ���� ���α׷��� ��쿡��
//  �����ӿ�ũ���� �� �۾��� �ڵ����� �����մϴ�.

void CMy17_02_02_MFC_TogetherDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // �׸��⸦ ���� ����̽� ���ؽ�Ʈ�Դϴ�.

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Ŭ���̾�Ʈ �簢������ �������� ����� ����ϴ�.
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// �������� �׸��ϴ�.
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// ����ڰ� �ּ�ȭ�� â�� ���� ���ȿ� Ŀ���� ǥ�õǵ��� �ý��ۿ���
//  �� �Լ��� ȣ���մϴ�.
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
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
}


void CMy17_02_02_MFC_TogetherDlg::OnBnClickedButton3(UINT id)
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
}


void CMy17_02_02_MFC_TogetherDlg::OnBnClickedButton4(UINT id)
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
}


void CMy17_02_02_MFC_TogetherDlg::OnBnClickedButton5(UINT id)
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
}


void CMy17_02_02_MFC_TogetherDlg::OnBnClickedButton6(UINT id)
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
}


void CMy17_02_02_MFC_TogetherDlg::OnBnClickedButton7(UINT id)
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
}


void CMy17_02_02_MFC_TogetherDlg::OnBnClickedButton8(UINT id)
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
}


void CMy17_02_02_MFC_TogetherDlg::OnBnClickedButton9(UINT id)
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
}


void CMy17_02_02_MFC_TogetherDlg::OnBnClickedButton10(UINT id)
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
}
*/


void CMy17_02_02_MFC_TogetherDlg::OnBnClickedButton13(UINT id)	// +
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
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
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
}


void CMy17_02_02_MFC_TogetherDlg::OnBnClickedButton15()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
}


void CMy17_02_02_MFC_TogetherDlg::OnBnClickedButton16()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
}
*/

void CMy17_02_02_MFC_TogetherDlg::OnBnClickedButton12()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	UpdateData(true);	//true�� view���� result�� �ҷ���
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
			MessageBox("���Ұ���");
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
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	result = "";
	UpdateData(false);	//false�� ����(result)���� view�� ����
}


