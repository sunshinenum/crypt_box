
// crypt_boxDlg.h : ͷ�ļ�
//

#pragma once


// Ccrypt_boxDlg �Ի���
class Ccrypt_boxDlg : public CDialogEx
{
// ����
public:
	Ccrypt_boxDlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
	enum { IDD = IDD_CRYPT_BOX_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��


// ʵ��
protected:
	HICON m_hIcon;

	// ���ɵ���Ϣӳ�亯��
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
