
// crypt_boxDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "crypt_box.h"
#include "crypt_boxDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// ����Ӧ�ó��򡰹��ڡ��˵���� CAboutDlg �Ի���

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// �Ի�������
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

// ʵ��
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


// Ccrypt_boxDlg �Ի���



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


// Ccrypt_boxDlg ��Ϣ�������

BOOL Ccrypt_boxDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// ��������...���˵�����ӵ�ϵͳ�˵��С�

	// IDM_ABOUTBOX ������ϵͳ���Χ�ڡ�
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

	// ���ô˶Ի����ͼ�ꡣ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��

	// TODO: �ڴ���Ӷ���ĳ�ʼ������

	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
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

// �����Ի��������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void Ccrypt_boxDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // ���ڻ��Ƶ��豸������

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// ʹͼ���ڹ����������о���
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// ����ͼ��
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//���û��϶���С������ʱϵͳ���ô˺���ȡ�ù��
//��ʾ��
HCURSOR Ccrypt_boxDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void Ccrypt_boxDlg::OnBnClickedButtonEn()
{
	// TODO: �򿪼��ܳ���
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
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	g_radio_select=1;
}


void Ccrypt_boxDlg::OnBnClickedRadioRsa()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	g_radio_select=2;
}


void Ccrypt_boxDlg::OnBnClickedRadioDes()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	g_radio_select=3;
}


void Ccrypt_boxDlg::OnBnClickedRadioSha1()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	g_radio_select=4;
}


void Ccrypt_boxDlg::OnBnClickedRadioHill()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	g_radio_select=5;
}


void Ccrypt_boxDlg::OnBnClickedRadioDeSha1()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	g_radio_select=6;
}


void Ccrypt_boxDlg::OnBnClickedRadioCrMd5()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	g_radio_select=7;
}


void Ccrypt_boxDlg::OnBnClickedRadioMfcHill()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	g_radio_select=8;
}


void Ccrypt_boxDlg::OnBnClickedRadioMfcDes()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	g_radio_select=9;
}
