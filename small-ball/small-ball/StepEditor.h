#pragma once


// StepEditor 对话框

class StepEditor : public CDialogEx
{
	DECLARE_DYNAMIC(StepEditor)

public:
	StepEditor(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~StepEditor();

// 对话框数据
	enum { IDD = IDD_DIALOG1 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	int m_movex;
	int m_movey;
	afx_msg void OnBnClickedOk();
};
