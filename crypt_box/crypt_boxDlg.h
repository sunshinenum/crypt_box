
// crypt_boxDlg.h : 头文件
//

#pragma once


// Ccrypt_boxDlg 对话框
class Ccrypt_boxDlg : public CDialogEx
{
// 构造
public:
	Ccrypt_boxDlg(CWnd* pParent = NULL);	// 标准构造函数

// 对话框数据
	enum { IDD = IDD_CRYPT_BOX_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持


// 实现
protected:
	HICON m_hIcon;

	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButtonEn();
	afx_msg void OnBnClickedRadioMd5();
	int g_radio_select;
	afx_msg void OnBnClickedRadioRsa();
	afx_msg void OnBnClickedRadioDes();
	afx_msg void OnBnClickedRadioSha1();
	afx_msg void OnBnClickedRadioHill();
	afx_msg void OnBnClickedRadioDeSha1();
	afx_msg void OnBnClickedRadioCrMd5();
	afx_msg void OnBnClickedRadioMfcHill();
	afx_msg void OnBnClickedRadioMfcDes();
};
