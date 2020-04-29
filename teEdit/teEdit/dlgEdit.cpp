// dlgEdit.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "teEdit.h"
#include "dlgEdit.h"
#include "afxdialogex.h"


// dlgEdit �Ի���

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


// dlgEdit ��Ϣ�������


void dlgEdit::OnBnClickedOk()
{
	UpdateData(true);

	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CDialogEx::OnOK();
}
