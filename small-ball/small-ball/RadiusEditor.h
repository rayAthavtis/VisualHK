#pragma once


// RadiusEditor �Ի���

class RadiusEditor : public CDialogEx
{
	DECLARE_DYNAMIC(RadiusEditor)

public:
	RadiusEditor(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~RadiusEditor();

// �Ի�������
	enum { IDD = IDD_DIALOG2 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	int m_myR;
	afx_msg void OnBnClickedOk();
};
