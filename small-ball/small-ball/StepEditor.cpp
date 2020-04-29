// StepEditor.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "small-ball.h"
#include "StepEditor.h"
#include "afxdialogex.h"


// StepEditor �Ի���

IMPLEMENT_DYNAMIC(StepEditor, CDialogEx)

StepEditor::StepEditor(CWnd* pParent /*=NULL*/)
	: CDialogEx(StepEditor::IDD, pParent)
	, m_movex(0)
	, m_movey(0)
{

}

StepEditor::~StepEditor()
{
}

void StepEditor::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_Movex_EDIT, m_movex);
	DDV_MinMaxInt(pDX, m_movex, -60, 60);
	DDX_Text(pDX, IDC_Movey_EDIT, m_movey);
	DDV_MinMaxInt(pDX, m_movey, -60, 60);
}


BEGIN_MESSAGE_MAP(StepEditor, CDialogEx)
	ON_BN_CLICKED(IDOK, &StepEditor::OnBnClickedOk)
END_MESSAGE_MAP()


// StepEditor ��Ϣ�������


void StepEditor::OnBnClickedOk()
{
	UpdateData(true);//��ȡ�༭������
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CDialogEx::OnOK();
}
