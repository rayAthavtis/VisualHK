
// teEditView.cpp : CteEditView ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "teEdit.h"
#endif

#include "teEditDoc.h"
#include "teEditView.h"
#include "dlgEdit.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CteEditView

IMPLEMENT_DYNCREATE(CteEditView, CView)

BEGIN_MESSAGE_MAP(CteEditView, CView)
	// ��׼��ӡ����
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CteEditView::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
	ON_COMMAND(ID_32771, &CteEditView::OnteEdit)
	ON_COMMAND(ID_32775, &CteEditView::OnSetDFont)
	ON_COMMAND(ID_32776, &CteEditView::OnSetSFont)
	ON_COMMAND(ID_32777, &CteEditView::OnSetAFont)
END_MESSAGE_MAP()

// CteEditView ����/����

CteEditView::CteEditView()
{
	// TODO: �ڴ˴���ӹ������
	m_font=0;
}

CteEditView::~CteEditView()
{
}

BOOL CteEditView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// CteEditView ����

void CteEditView::OnDraw(CDC* pDC)
{
	CteEditDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	if(m_font==1)//����Ϊϵͳ����
		pDC->SelectStockObject(SYSTEM_FONT);
	else if(m_font==2)//����ΪANSI����
		pDC->SelectStockObject(ANSI_FIXED_FONT);
	pDC->TextOutW(0,0,str);
	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
}


// CteEditView ��ӡ


void CteEditView::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL CteEditView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// Ĭ��׼��
	return DoPreparePrinting(pInfo);
}

void CteEditView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӷ���Ĵ�ӡǰ���еĳ�ʼ������
}

void CteEditView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӵ�ӡ����е��������
}

void CteEditView::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CteEditView::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CteEditView ���

#ifdef _DEBUG
void CteEditView::AssertValid() const
{
	CView::AssertValid();
}

void CteEditView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CteEditDoc* CteEditView::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CteEditDoc)));
	return (CteEditDoc*)m_pDocument;
}
#endif //_DEBUG


// CteEditView ��Ϣ�������


void CteEditView::OnteEdit()
{

	dlgEdit dlg;
	if(dlg.DoModal()==IDOK){//�Ի�������ȷ��
		str=dlg.m_str;
		Invalidate(true);//ˢ��
	}
	// TODO: �ڴ���������������
}

void CteEditView::OnSetDFont()
{
	m_font=0;
	// TODO: �ڴ���������������
}


void CteEditView::OnSetSFont()
{
	m_font=1;
	// TODO: �ڴ���������������
}


void CteEditView::OnSetAFont()
{
	m_font=2;
	// TODO: �ڴ���������������
}


