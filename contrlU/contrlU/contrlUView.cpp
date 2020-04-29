
// contrlUView.cpp : CcontrlUView ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "contrlU.h"
#endif

#include "contrlUDoc.h"
#include "contrlUView.h"
#include "MesDLG.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// CcontrlUView

IMPLEMENT_DYNCREATE(CcontrlUView, CView)

BEGIN_MESSAGE_MAP(CcontrlUView, CView)
	// ��׼��ӡ����
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CcontrlUView::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
	ON_COMMAND(ID_CTRL, &CcontrlUView::OnCtrl)
END_MESSAGE_MAP()

// CcontrlUView ����/����

CcontrlUView::CcontrlUView()
{
	// TODO: �ڴ˴���ӹ������
	m_id=17110;
	m_name=_T("����");
	m_birth=_T("1999/06/01");
	m_place=_T("���");
	m_gender=_T("Ů");
	change=0;
}

CcontrlUView::~CcontrlUView()
{
}

BOOL CcontrlUView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// CcontrlUView ����

void CcontrlUView::OnDraw(CDC* pDC)
{
	CcontrlUDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	pDoc->Get(m_id,m_name,m_birth,m_place,m_gender,change);
	CString id;
	id.Format(L"%d",m_id);
	pDC->TextOutW(10,10,L"ѧ�ţ�"+id);
	pDC->TextOutW(10,40,L"������"+m_name);
	pDC->TextOutW(10,70,L"�Ա�"+m_gender);
	pDC->TextOutW(10,100,L"���գ�"+m_birth);
	pDC->TextOutW(10,130,L"���ڵأ�"+m_place);
	pDC->TextOutW(150,10,L"��Ƭ��");
	CBitmap bm;  	if (change==0)
		bm.LoadBitmap(IDB_PHOTO2);
	else
		bm.LoadBitmap(IDB_PHOTO1);	CDC memDC;  	memDC.CreateCompatibleDC(pDC);	memDC.SelectObject(&bm);	BITMAP info;  	bm.GetBitmap(&info);	pDC->BitBlt(150,40,info.bmWidth, info.bmHeight,&memDC,0,0,SRCCOPY);	bm.DeleteObject();

	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
}


// CcontrlUView ��ӡ


void CcontrlUView::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL CcontrlUView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// Ĭ��׼��
	return DoPreparePrinting(pInfo);
}

void CcontrlUView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӷ���Ĵ�ӡǰ���еĳ�ʼ������
}

void CcontrlUView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӵ�ӡ����е��������
}

void CcontrlUView::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CcontrlUView::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CcontrlUView ���

#ifdef _DEBUG
void CcontrlUView::AssertValid() const
{
	CView::AssertValid();
}

void CcontrlUView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CcontrlUDoc* CcontrlUView::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CcontrlUDoc)));
	return (CcontrlUDoc*)m_pDocument;
}
#endif //_DEBUG


// CcontrlUView ��Ϣ�������


void CcontrlUView::OnCtrl()
{
	MesDLG dlg;
	if(dlg.DoModal()==IDOK){
		m_id=dlg.m_id;
		m_name=dlg.m_name;
		m_birth=dlg.m_birth.Format(_T("%Y/%m/%d"));
		m_place=dlg.m_place;
		if(dlg.m_gender==0)
			m_gender="Ů";
		else if(dlg.m_gender==1)
			m_gender="��";
		change=dlg.change;
		Invalidate(true);
	}
	CcontrlUDoc* pDoc = GetDocument();
	pDoc->Set(m_id,m_name,m_birth,m_place,m_gender,change);
	// TODO: �ڴ���������������
}
