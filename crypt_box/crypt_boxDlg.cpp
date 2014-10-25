
// crypt_boxDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "crypt_box.h"
#include "crypt_boxDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 用于应用程序“关于”菜单项的 CAboutDlg 对话框

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 对话框数据
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

// 实现
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// Ccrypt_boxDlg 对话框



Ccrypt_boxDlg::Ccrypt_boxDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(Ccrypt_boxDlg::IDD, pParent)
	, g_radio_select(0)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void Ccrypt_boxDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(Ccrypt_boxDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON_EN, &Ccrypt_boxDlg::OnBnClickedButtonEn)
	ON_BN_CLICKED(IDC_RADIO_MD5, &Ccrypt_boxDlg::OnBnClickedRadioMd5)
	ON_BN_CLICKED(IDC_RADIO_RSA, &Ccrypt_boxDlg::OnBnClickedRadioRsa)
	ON_BN_CLICKED(IDC_RADIO_DES, &Ccrypt_boxDlg::OnBnClickedRadioDes)
	ON_BN_CLICKED(IDC_RADIO_SHA1, &Ccrypt_boxDlg::OnBnClickedRadioSha1)
	ON_BN_CLICKED(IDC_RADIO_HILL, &Ccrypt_boxDlg::OnBnClickedRadioHill)
	ON_BN_CLICKED(IDC_RADIO_DE_SHA1, &Ccrypt_boxDlg::OnBnClickedRadioDeSha1)
	ON_BN_CLICKED(IDC_RADIO_CR_MD5, &Ccrypt_boxDlg::OnBnClickedRadioCrMd5)
	ON_BN_CLICKED(IDC_RADIO_MFC_HILL, &Ccrypt_boxDlg::OnBnClickedRadioMfcHill)
	ON_BN_CLICKED(IDC_RADIO_MFC_DES, &Ccrypt_boxDlg::OnBnClickedRadioMfcDes)
END_MESSAGE_MAP()


// Ccrypt_boxDlg 消息处理程序

BOOL Ccrypt_boxDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 将“关于...”菜单项添加到系统菜单中。

	// IDM_ABOUTBOX 必须在系统命令范围内。
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

	// 设置此对话框的图标。当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO: 在此添加额外的初始化代码

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void Ccrypt_boxDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void Ccrypt_boxDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作区矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR Ccrypt_boxDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void Ccrypt_boxDlg::OnBnClickedButtonEn()
{
	// TODO: 打开加密程序
	switch (g_radio_select)
	{
	case 1:ShellExecute(NULL,_T("open"),_T("tools\\md5_mfc.exe"),NULL,NULL,SW_SHOW);break;
	case 2:ShellExecute(NULL,_T("open"),_T("tools\\rsa.exe"),NULL,NULL,SW_SHOW);break;
	case 3:ShellExecute(NULL,_T("open"),_T("tools\\des.exe"),NULL,NULL,SW_SHOW);break;
	case 4:ShellExecute(NULL,_T("open"),_T("tools\\sha.exe"),NULL,NULL,SW_SHOW);break;
	case 5:ShellExecute(NULL,_T("open"),_T("tools\\hill.exe"),NULL,NULL,SW_SHOW);break;
	case 6:ShellExecute(NULL,_T("open"),_T("tools\\de_sha.exe"),NULL,NULL,SW_SHOW);break;
	case 7:ShellExecute(NULL,_T("open"),_T("tools\\de_md5.exe"),NULL,NULL,SW_SHOW);break;
	case 8:ShellExecute(NULL,_T("open"),_T("tools\\hill_mfc.exe"),NULL,NULL,SW_SHOW);break;
	case 9:ShellExecute(NULL,_T("open"),_T("tools\\des_mfc.exe"),NULL,NULL,SW_SHOW);break;
	default:break;
	}
}


void Ccrypt_boxDlg::OnBnClickedRadioMd5()
{
	// TODO: 在此添加控件通知处理程序代码
	g_radio_select=1;
}


void Ccrypt_boxDlg::OnBnClickedRadioRsa()
{
	// TODO: 在此添加控件通知处理程序代码
	g_radio_select=2;
}


void Ccrypt_boxDlg::OnBnClickedRadioDes()
{
	// TODO: 在此添加控件通知处理程序代码
	g_radio_select=3;
}


void Ccrypt_boxDlg::OnBnClickedRadioSha1()
{
	// TODO: 在此添加控件通知处理程序代码
	g_radio_select=4;
}


void Ccrypt_boxDlg::OnBnClickedRadioHill()
{
	// TODO: 在此添加控件通知处理程序代码
	g_radio_select=5;
}


void Ccrypt_boxDlg::OnBnClickedRadioDeSha1()
{
	// TODO: 在此添加控件通知处理程序代码
	g_radio_select=6;
}


void Ccrypt_boxDlg::OnBnClickedRadioCrMd5()
{
	// TODO: 在此添加控件通知处理程序代码
	g_radio_select=7;
}


void Ccrypt_boxDlg::OnBnClickedRadioMfcHill()
{
	// TODO: 在此添加控件通知处理程序代码
	g_radio_select=8;
}


void Ccrypt_boxDlg::OnBnClickedRadioMfcDes()
{
	// TODO: 在此添加控件通知处理程序代码
	g_radio_select=9;
}
