#pragma once
#include "atlcomtime.h"
#include "afxcmn.h"
#include "afxwin.h"


// MesDLG �Ի���

class MesDLG : public CDialogEx
{
	DECLARE_DYNAMIC(MesDLG)

public:
	MesDLG(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~MesDLG();

// �Ի�������
	enum { IDD = IDD_MESDLG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	int m_id;
	CString m_name;
	COleDateTime m_birth;
	afx_msg void OnBnClickedOk();
	CString m_place;
	virtual BOOL OnInitDialog();
	afx_msg void OnBnClickedWoman();
	int m_gender;
	afx_msg void OnBnClickedMan();
	afx_msg void OnVScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar);
	afx_msg void OnDeltaposSpin(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnDtnDatetimechangeDatetimepicker1(NMHDR *pNMHDR, LRESULT *pResult);
	CStatic m_photo;
	CBitmap m_photo1,m_photo2;
	int change;
	afx_msg void OnBnClickedPhotochange();
};
