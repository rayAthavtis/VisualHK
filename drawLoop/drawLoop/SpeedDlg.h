#pragma once
#include "afxcmn.h"
#include "afxwin.h"


// SpeedDlg �Ի���

class SpeedDlg : public CDialogEx
{
	DECLARE_DYNAMIC(SpeedDlg)

public:
	SpeedDlg(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~SpeedDlg();

// �Ի�������
	enum { IDD = IDD_DIALOG1 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	CSliderCtrl speedCtrl;
	int speedFree;
	CString d_speed;
	int d_sp;
	afx_msg void OnNMCustomdrawSpeedsli(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar);
	virtual BOOL OnInitDialog();
	afx_msg void OnCbnSelchangeSpeed();
	afx_msg void OnBnClickedOk();
	CComboBox d_ctrlSpeed;
};
