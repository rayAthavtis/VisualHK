// SpeedDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "drawLoop.h"
#include "SpeedDlg.h"
#include "afxdialogex.h"


// SpeedDlg �Ի���

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


// SpeedDlg ��Ϣ�������


void SpeedDlg::OnNMCustomdrawSpeedsli(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMCUSTOMDRAW pNMCD = reinterpret_cast<LPNMCUSTOMDRAW>(pNMHDR);
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	*pResult = 0;
}


void SpeedDlg::OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	UpdateData(TRUE);//���ձ༭���е�����
    CSliderCtrl *pSlider=(CSliderCtrl *)GetDlgItem(IDC_SPEEDSLI);//����һ��ָ��ָ�򻬶����ؼ�
    speedFree=pSlider->GetPos();//�༭���ȡ��������ǰλ�õ�ֵ

	CDialogEx::OnHScroll(nSBCode, nPos, pScrollBar);
	UpdateData(FALSE);//���±༭������
}


BOOL SpeedDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  �ڴ���Ӷ���ĳ�ʼ��
	speedCtrl.SetRange(0,30);//���÷�Χ
	speedCtrl.SetTicFreq(1);//���ò���
	speedCtrl.SetPos(0);//���ó�ʼλ��

	return TRUE;  // return TRUE unless you set the focus to a control
	// �쳣: OCX ����ҳӦ���� FALSE
}


void SpeedDlg::OnCbnSelchangeSpeed()
{

	int index = d_ctrlSpeed.GetCurSel();
	d_ctrlSpeed.GetLBText(index,d_speed);//��ȡѡ������
	if(d_speed!="")
		d_sp=_ttoi(d_speed);//CStringתint
	// TODO: �ڴ���ӿؼ�֪ͨ����������
}


void SpeedDlg::OnBnClickedOk()
{
	UpdateData(TRUE);
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CDialogEx::OnOK();
}
