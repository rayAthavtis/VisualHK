#pragma once


// StepEditor �Ի���

class StepEditor : public CDialogEx
{
	DECLARE_DYNAMIC(StepEditor)

public:
	StepEditor(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~StepEditor();

// �Ի�������
	enum { IDD = IDD_DIALOG1 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	int m_movex;
	int m_movey;
	afx_msg void OnBnClickedOk();
};
