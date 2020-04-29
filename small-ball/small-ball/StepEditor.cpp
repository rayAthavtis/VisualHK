// StepEditor.cpp : 实现文件
//

#include "stdafx.h"
#include "small-ball.h"
#include "StepEditor.h"
#include "afxdialogex.h"


// StepEditor 对话框

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


// StepEditor 消息处理程序


void StepEditor::OnBnClickedOk()
{
	UpdateData(true);//获取编辑框数据
	// TODO: 在此添加控件通知处理程序代码
	CDialogEx::OnOK();
}
