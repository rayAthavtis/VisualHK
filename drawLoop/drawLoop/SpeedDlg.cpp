// SpeedDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "drawLoop.h"
#include "SpeedDlg.h"
#include "afxdialogex.h"


// SpeedDlg 对话框

IMPLEMENT_DYNAMIC(SpeedDlg, CDialogEx)

SpeedDlg::SpeedDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(SpeedDlg::IDD, pParent)
	, d_speed(_T(""))
	, speedFree(0)
	, d_sp(0)
{

}

SpeedDlg::~SpeedDlg()
{
}

void SpeedDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_SPEEDSLI, speedCtrl);
	DDX_CBString(pDX, IDC_SPEED, d_speed);
	DDX_Text(pDX, IDC_SPEEDEDI, speedFree);
	DDX_Control(pDX, IDC_SPEED, d_ctrlSpeed);
}


BEGIN_MESSAGE_MAP(SpeedDlg, CDialogEx)
	ON_NOTIFY(NM_CUSTOMDRAW, IDC_SPEEDSLI, &SpeedDlg::OnNMCustomdrawSpeedsli)
	ON_WM_HSCROLL()
	ON_CBN_SELCHANGE(IDC_SPEED, &SpeedDlg::OnCbnSelchangeSpeed)
	ON_BN_CLICKED(IDOK, &SpeedDlg::OnBnClickedOk)
END_MESSAGE_MAP()


// SpeedDlg 消息处理程序


void SpeedDlg::OnNMCustomdrawSpeedsli(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMCUSTOMDRAW pNMCD = reinterpret_cast<LPNMCUSTOMDRAW>(pNMHDR);
	// TODO: 在此添加控件通知处理程序代码
	*pResult = 0;
}


void SpeedDlg::OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	UpdateData(TRUE);//接收编辑框中的数据
    CSliderCtrl *pSlider=(CSliderCtrl *)GetDlgItem(IDC_SPEEDSLI);//定义一个指针指向滑动条控件
    speedFree=pSlider->GetPos();//编辑框获取滑动条当前位置的值

	CDialogEx::OnHScroll(nSBCode, nPos, pScrollBar);
	UpdateData(FALSE);//更新编辑框数据
}


BOOL SpeedDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  在此添加额外的初始化
	speedCtrl.SetRange(0,30);//设置范围
	speedCtrl.SetTicFreq(1);//设置步长
	speedCtrl.SetPos(0);//设置初始位置

	return TRUE;  // return TRUE unless you set the focus to a control
	// 异常: OCX 属性页应返回 FALSE
}


void SpeedDlg::OnCbnSelchangeSpeed()
{

	int index = d_ctrlSpeed.GetCurSel();
	d_ctrlSpeed.GetLBText(index,d_speed);//获取选中数据
	if(d_speed!="")
		d_sp=_ttoi(d_speed);//CString转int
	// TODO: 在此添加控件通知处理程序代码
}


void SpeedDlg::OnBnClickedOk()
{
	UpdateData(TRUE);
	// TODO: 在此添加控件通知处理程序代码
	CDialogEx::OnOK();
}
