#pragma once


// dlgEdit �Ի���

class dlgEdit : public CDialogEx
{
	DECLARE_DYNAMIC(dlgEdit)

public:
	dlgEdit(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~dlgEdit();

// �Ի�������
	enum { IDD = IDD_DIALOG1 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	CString m_str;
	afx_msg void OnBnClickedOk();
};
