// RadiusEditor.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "small-ball.h"
#include "RadiusEditor.h"
#include "afxdialogex.h"


// RadiusEditor �Ի���

IMPLEMENT_DYNAMIC(RadiusEditor, CDialogEx)

RadiusEditor::RadiusEditor(CWnd* pParent /*=NULL*/)
	: CDialogEx(RadiusEditor::IDD, pParent)
	, m_myR(0)
{

}

RadiusEditor::~RadiusEditor()
{
}

void RadiusEditor::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_Radius_Edit, m_myR);
	DDV_MinMaxInt(pDX, m_myR, 1, 60);
}


BEGIN_MESSAGE_MAP(RadiusEditor, CDialogEx)
	ON_BN_CLICKED(IDOK, &RadiusEditor::OnBnClickedOk)
END_MESSAGE_MAP()


// RadiusEditor ��Ϣ�������


void RadiusEditor::OnBnClickedOk()
{

	UpdateData(TRUE); //��ȡ�༭������
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CDialogEx::OnOK();
}
