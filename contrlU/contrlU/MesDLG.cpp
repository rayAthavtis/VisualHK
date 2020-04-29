// MesDLG.cpp : 实现文件
//

#include "stdafx.h"
#include "contrlU.h"
#include "MesDLG.h"
#include "afxdialogex.h"


// MesDLG 对话框

IMPLEMENT_DYNAMIC(MesDLG, CDialogEx)

MesDLG::MesDLG(CWnd* pParent /*=NULL*/)
	: CDialogEx(MesDLG::IDD, pParent)
	, m_id(17110)
	, m_name(_T("安乔"))
	, m_place(_T("天津"))
	, m_gender(0)
{
	CString birth=_T("1999/06/01");
	m_birth.ParseDateTime(birth);
	change=0;
}

MesDLG::~MesDLG()
{
}

void MesDLG::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT2, m_id);
	DDX_Text(pDX, IDC_EDIT1, m_name);
	DDX_DateTimeCtrl(pDX, IDC_DATETIMEPICKER1, m_birth);
	DDX_CBString(pDX, IDC_PLACE, m_place);
	DDX_Control(pDX, IDC_PHOTOC, m_photo);
}


BEGIN_MESSAGE_MAP(MesDLG, CDialogEx)
	ON_BN_CLICKED(IDOK, &MesDLG::OnBnClickedOk)
	ON_BN_CLICKED(IDC_WOMAN, &MesDLG::OnBnClickedWoman)
	ON_BN_CLICKED(IDC_MAN, &MesDLG::OnBnClickedMan)
	ON_WM_VSCROLL()
	ON_NOTIFY(DTN_DATETIMECHANGE, IDC_DATETIMEPICKER1, &MesDLG::OnDtnDatetimechangeDatetimepicker1)
	ON_BN_CLICKED(IDC_PHOTOCHANGE, &MesDLG::OnBnClickedPhotochange)
END_MESSAGE_MAP()


// MesDLG 消息处理程序


void MesDLG::OnBnClickedOk()
{
	UpdateData(true);
	

	// TODO: 在此添加控件通知处理程序代码
	CDialogEx::OnOK();
}




BOOL MesDLG::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	
	CButton* radio=(CButton*)GetDlgItem(IDC_WOMAN);//设置默认性别选择“女”
	radio->SetCheck(1);

	CScrollBar* pScrollBar;
	pScrollBar = (CScrollBar*)GetDlgItem(IDC_SCROLLBAR);
	pScrollBar->SetScrollRange(0,100);		//设置范围：1-100

	CSpinButtonCtrl* pSpin = (CSpinButtonCtrl*)GetDlgItem(IDC_SPINC);
	pSpin->SetRange32(17110,17120);    //设置学号的范围：17110-17120	
	pSpin->SetBase(10);    //设置基数：十进制

	GetDlgItem(IDC_EDIT2)->SetWindowText(L"17110");

	m_photo1.LoadBitmap(IDB_PHOTO1);
	m_photo2.LoadBitmap(IDB_PHOTO2);
	m_photo.SetBitmap((HBITMAP)m_photo2);//默认用此照片

	// TODO:  在此添加额外的初始化
	return TRUE;  // return TRUE unless you set the focus to a control
	// 异常: OCX 属性页应返回 FALSE
}


void MesDLG::OnBnClickedWoman()
{
	m_gender=0;
	UpdateData(true);
	// TODO: 在此添加控件通知处理程序代码
}


void MesDLG::OnBnClickedMan()
{
	m_gender=1;
	UpdateData(true);
	// TODO: 在此添加控件通知处理程序代码
}



void MesDLG::OnVScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	int TempPos = pScrollBar->GetScrollPos();
	switch(nSBCode){
	case SB_THUMBPOSITION://拖动滑块
		pScrollBar->SetScrollPos(nPos);
		break;
	case SB_LINELEFT://点击左边的箭头
		if(TempPos > 1){
			TempPos--;
		}
		pScrollBar->SetScrollPos(TempPos);
		break;
	case SB_LINERIGHT://点击右边的箭头
		if(TempPos<100){
			TempPos++;
		}
		pScrollBar->SetScrollPos(TempPos);
		break;
	}

	CDialogEx::OnVScroll(nSBCode, nPos, pScrollBar);
}



void MesDLG::OnDtnDatetimechangeDatetimepicker1(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMDATETIMECHANGE pDTChange = reinterpret_cast<LPNMDATETIMECHANGE>(pNMHDR);
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(true);
	*pResult = 0;
}


void MesDLG::OnBnClickedPhotochange()
{
	if (change==0){
		change=1;
		m_photo.SetBitmap((HBITMAP)m_photo1);//切换照片
	}
	else{
		change=0;
		m_photo.SetBitmap((HBITMAP)m_photo2);
	}
	m_photo.InvalidateRect(NULL);
	// TODO: 在此添加控件通知处理程序代码
}
