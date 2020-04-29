// RadiusEditor.cpp : 实现文件
//

#include "stdafx.h"
#include "small-ball.h"
#include "RadiusEditor.h"
#include "afxdialogex.h"


// RadiusEditor 对话框

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


// RadiusEditor 消息处理程序


void RadiusEditor::OnBnClickedOk()
{

	UpdateData(TRUE); //获取编辑框数据
	// TODO: 在此添加控件通知处理程序代码
	CDialogEx::OnOK();
}
