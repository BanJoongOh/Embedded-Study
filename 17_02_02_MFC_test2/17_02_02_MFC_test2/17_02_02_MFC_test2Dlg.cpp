
// 17_02_02_MFC_test2Dlg.cpp : ���� ����
//

#include "stdafx.h"
#include "17_02_02_MFC_test2.h"
#include "17_02_02_MFC_test2Dlg.h"
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


// CMy17_02_02_MFC_test2Dlg ��ȭ ����



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


// CMy17_02_02_MFC_test2Dlg �޽��� ó����

BOOL CMy17_02_02_MFC_test2Dlg::OnInitDialog()
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

// ��ȭ ���ڿ� �ּ�ȭ ���߸� �߰��� ��� �������� �׸�����
//  �Ʒ� �ڵ尡 �ʿ��մϴ�.  ����/�� ���� ����ϴ� MFC ���� ���α׷��� ��쿡��
//  �����ӿ�ũ���� �� �۾��� �ڵ����� �����մϴ�.

void CMy17_02_02_MFC_test2Dlg::OnPaint()
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
HCURSOR CMy17_02_02_MFC_test2Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CMy17_02_02_MFC_test2Dlg::OnBnClickedCheck1()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	UpdateData(true);

}


void CMy17_02_02_MFC_test2Dlg::OnBnClickedCheck2()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	UpdateData(true);
}


void CMy17_02_02_MFC_test2Dlg::OnBnClickedButton1()	//check�ڽ� ��������
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	CString str = "";
	/*
	if (c1)	//////////////////check box�� �׷����Ͽ� ������ ���� �����ϰ�
	{
		str += "check1�� ���õ�\n";
		MessageBox(str);
	}
	if (c2)
	{
		str += "check2�� ���õ�\n";
		MessageBox(str);
	}
	switch (r)/////////////radio box�� �׷������ʰ� �Ѱ��� ���� �����ϰ�
	{
	case 1:
		str += "radio1�� ���õ�\n";
		MessageBox(str);
		break;
	case 2:
		str += "radio2�� ���õ�\n";
		MessageBox(str);
		break;
	}
	*/

	
	switch (r)
	{
	case 1:
		UpdateData(true);
		if (mycombo == "��Ʈ��")
			MessageBox("��Ʈ��");
		else if (mycombo == "�����")
			MessageBox("�����");
		else if (mycombo == "TV")
			MessageBox("TV");
		else if (mycombo == "��ǻ��")
			MessageBox("��ǻ��");
		break;
	case 2:
		UpdateData(true);
		if (mycombo == "������")
			MessageBox("������");
		else if (mycombo == "��ȸ")
			MessageBox("��ȸ");
		else if (mycombo == "����")
			MessageBox("����");
		else if (mycombo == "ī��")
			MessageBox("ī��");
		break;
	case 3:
		UpdateData(true);
		if (mycombo == "����")
			MessageBox("����");
		else if (mycombo == "�޷�")
			MessageBox("�޷�");
		else if (mycombo == "õ����")
			MessageBox("õ����");
		else if (mycombo == "��")
			MessageBox("��");
		break;
	}
	
	
}


void CMy17_02_02_MFC_test2Dlg::OnBnClickedRadio1()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	r = 1;

	CComboBox *c = (CComboBox*)GetDlgItem(IDC_COMBO1);
	int i = 1;
	while (i > 0)
		i = c->DeleteString(0);	//�����׸��� ��ȯ��, ������ ���� �׸��� �Ʒ��׸��� ���� �ö�

	c->AddString("��Ʈ��"); //combo1 data ���ξ���
	c->AddString("�����");
	c->AddString("TV");
	c->AddString("��ǻ��");
}


void CMy17_02_02_MFC_test2Dlg::OnBnClickedRadio2()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	r = 2;

	CComboBox *c = (CComboBox*)GetDlgItem(IDC_COMBO1);
	int i = 1;
	while (i > 0)
		i = c->DeleteString(0);	//�����׸��� ��ȯ��, ������ ���� �׸��� �Ʒ��׸��� ���� �ö�

	c->AddString("������"); //combo1 data ���ξ���
	c->AddString("��ȸ");
	c->AddString("����");
	c->AddString("ī��");
}

void CMy17_02_02_MFC_test2Dlg::OnBnClickedRadio3()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	r = 3;

	CComboBox *c = (CComboBox*)GetDlgItem(IDC_COMBO1);
	int i = 1;
	while (i > 0)
		i = c->DeleteString(0);	//�����׸��� ��ȯ��, ������ ���� �׸��� �Ʒ��׸��� ���� �ö�

	c->AddString("����");	//combo1 data ���ξ���
	c->AddString("�޷�");
	c->AddString("õ����");
	c->AddString("��");
}

void CMy17_02_02_MFC_test2Dlg::OnCbnSelchangeCombo1()
{//1.����;2.�޷�;3.õ����;4.��
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	
}


