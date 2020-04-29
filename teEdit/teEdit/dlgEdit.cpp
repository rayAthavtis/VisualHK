// dlgEdit.cpp : 实现文件
//

#include "stdafx.h"
#include "teEdit.h"
#include "dlgEdit.h"
#include "afxdialogex.h"


// dlgEdit 对话框

IMPLEMENT_DYNAMIC(dlgEdit, CDialogEx)

dlgEdit::dlgEdit(CWnd* pParent /*=NULL*/)
	: CDialogEx(dlgEdit::IDD, pParent)
	, m_str(_T(""))
{

}

dlgEdit::~dlgEdit()
{
}

void dlgEdit::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, m_str);
}


BEGIN_MESSAGE_MAP(dlgEdit, CDialogEx)
	ON_BN_CLICKED(IDOK, &dlgEdit::OnBnClickedOk)
END_MESSAGE_MAP()


// dlgEdit 消息处理程序


void dlgEdit::OnBnClickedOk()
{
	UpdateData(true);

	// TODO: 在此添加控件通知处理程序代码
	CDialogEx::OnOK();
}
