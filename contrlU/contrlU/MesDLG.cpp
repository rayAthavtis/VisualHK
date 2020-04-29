// MesDLG.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "contrlU.h"
#include "MesDLG.h"
#include "afxdialogex.h"


// MesDLG �Ի���

IMPLEMENT_DYNAMIC(MesDLG, CDialogEx)

MesDLG::MesDLG(CWnd* pParent /*=NULL*/)
	: CDialogEx(MesDLG::IDD, pParent)
	, m_id(17110)
	, m_name(_T("����"))
	, m_place(_T("���"))
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


// MesDLG ��Ϣ�������


void MesDLG::OnBnClickedOk()
{
	UpdateData(true);
	

	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CDialogEx::OnOK();
}




BOOL MesDLG::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	
	CButton* radio=(CButton*)GetDlgItem(IDC_WOMAN);//����Ĭ���Ա�ѡ��Ů��
	radio->SetCheck(1);

	CScrollBar* pScrollBar;
	pScrollBar = (CScrollBar*)GetDlgItem(IDC_SCROLLBAR);
	pScrollBar->SetScrollRange(0,100);		//���÷�Χ��1-100

	CSpinButtonCtrl* pSpin = (CSpinButtonCtrl*)GetDlgItem(IDC_SPINC);
	pSpin->SetRange32(17110,17120);    //����ѧ�ŵķ�Χ��17110-17120	
	pSpin->SetBase(10);    //���û�����ʮ����

	GetDlgItem(IDC_EDIT2)->SetWindowText(L"17110");

	m_photo1.LoadBitmap(IDB_PHOTO1);
	m_photo2.LoadBitmap(IDB_PHOTO2);
	m_photo.SetBitmap((HBITMAP)m_photo2);//Ĭ���ô���Ƭ

	// TODO:  �ڴ���Ӷ���ĳ�ʼ��
	return TRUE;  // return TRUE unless you set the focus to a control
	// �쳣: OCX ����ҳӦ���� FALSE
}


void MesDLG::OnBnClickedWoman()
{
	m_gender=0;
	UpdateData(true);
	// TODO: �ڴ���ӿؼ�֪ͨ����������
}


void MesDLG::OnBnClickedMan()
{
	m_gender=1;
	UpdateData(true);
	// TODO: �ڴ���ӿؼ�֪ͨ����������
}



void MesDLG::OnVScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	int TempPos = pScrollBar->GetScrollPos();
	switch(nSBCode){
	case SB_THUMBPOSITION://�϶�����
		pScrollBar->SetScrollPos(nPos);
		break;
	case SB_LINELEFT://�����ߵļ�ͷ
		if(TempPos > 1){
			TempPos--;
		}
		pScrollBar->SetScrollPos(TempPos);
		break;
	case SB_LINERIGHT://����ұߵļ�ͷ
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
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	UpdateData(true);
	*pResult = 0;
}


void MesDLG::OnBnClickedPhotochange()
{
	if (change==0){
		change=1;
		m_photo.SetBitmap((HBITMAP)m_photo1);//�л���Ƭ
	}
	else{
		change=0;
		m_photo.SetBitmap((HBITMAP)m_photo2);
	}
	m_photo.InvalidateRect(NULL);
	// TODO: �ڴ���ӿؼ�֪ͨ����������
}
