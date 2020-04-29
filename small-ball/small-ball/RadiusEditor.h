#pragma once


// RadiusEditor 对话框

class RadiusEditor : public CDialogEx
{
	DECLARE_DYNAMIC(RadiusEditor)

public:
	RadiusEditor(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~RadiusEditor();

// 对话框数据
	enum { IDD = IDD_DIALOG2 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	int m_myR;
	afx_msg void OnBnClickedOk();
};
