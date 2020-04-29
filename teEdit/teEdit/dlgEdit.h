#pragma once


// dlgEdit 对话框

class dlgEdit : public CDialogEx
{
	DECLARE_DYNAMIC(dlgEdit)

public:
	dlgEdit(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~dlgEdit();

// 对话框数据
	enum { IDD = IDD_DIALOG1 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	CString m_str;
	afx_msg void OnBnClickedOk();
};
