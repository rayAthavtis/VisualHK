
// drewTeView.cpp : CdrewTeView ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "drewTe.h"
#endif

#include "drewTeDoc.h"
#include "drewTeView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CdrewTeView

IMPLEMENT_DYNCREATE(CdrewTeView, CView)

BEGIN_MESSAGE_MAP(CdrewTeView, CView)
	// ��׼��ӡ����
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CdrewTeView::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
	ON_COMMAND(ID_POPUP_LINE, &CdrewTeView::OnPopupLine)
	ON_COMMAND(ID_POPUP_ELLIPSE, &CdrewTeView::OnPopupEllipse)
	ON_COMMAND(ID_POPUP_RECTANGLE, &CdrewTeView::OnPopupRectangle)
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
	ON_WM_MOUSEMOVE()
	ON_WM_RBUTTONDOWN()
END_MESSAGE_MAP()

// CdrewTeView ����/����

CdrewTeView::CdrewTeView()
{
	// TODO: �ڴ˴���ӹ������
	m_poi=CPoint(0,0);
	//m_st.Empty();
	m_draw=0;
	m_cursor=AfxGetApp()->LoadStandardCursor(IDC_CROSS);
	m_old=m_origin=CPoint(0,0);

}

CdrewTeView::~CdrewTeView()
{
}

BOOL CdrewTeView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// CdrewTeView ����

void CdrewTeView::OnDraw(CDC* pDC)
{
	CdrewTeDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	CPoint point;
	CString str;
	pDoc->Get(str,point);//��ȡ��������
	pDC->TextOutW(point.x,point.y,str);//���


	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
}


// CdrewTeView ��ӡ


void CdrewTeView::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL CdrewTeView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// Ĭ��׼��
	return DoPreparePrinting(pInfo);
}

void CdrewTeView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӷ���Ĵ�ӡǰ���еĳ�ʼ������
}

void CdrewTeView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӵ�ӡ����е��������
}

void CdrewTeView::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	m_poi=point;//��ͼ���λ��
	ClientToScreen(&point);
	OnContextMenu(this, point);

}

void CdrewTeView::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
	CMenu menu;//�½��˵�
	menu.LoadMenu(IDR_POPUPMENU);
	CMenu* pMenu=menu.GetSubMenu(0);
	pMenu->TrackPopupMenu(TPM_LEFTALIGN,point.x,point.y,this);//�˵���ʾλ��

/*
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
*/
}


// CdrewTeView ���

#ifdef _DEBUG
void CdrewTeView::AssertValid() const
{
	CView::AssertValid();
}

void CdrewTeView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CdrewTeDoc* CdrewTeView::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CdrewTeDoc)));
	return (CdrewTeDoc*)m_pDocument;
}
#endif //_DEBUG


// CdrewTeView ��Ϣ�������


void CdrewTeView::OnPopupLine()//����
{
	CDC* pDC=GetDC();
	pDC->MoveTo(m_poi.x,m_poi.y);//�������λ�û�һ����
	pDC->LineTo(m_poi.x+200,m_poi.y+200);
	ReleaseDC(pDC);

	CString str1;
	str1.Format(L"Line from(%d,%d)",m_poi.x,m_poi.y);//��ʽ
	CString str2;
	str2.Format(L" to(%d,%d)",m_poi.x+200,m_poi.y+200);
	CString str=str1+str2;
	//m_st.Format(L"Line at(%d,%d)",m_poi.x,m_poi.y)...//Ҳ��ʹ��view.cpp�ı����ķ�ʽ
	CdrewTeDoc* pDoc=GetDocument();
	pDoc->Set(str,m_poi);//�����ͺ���������ĵ�

	// TODO: �ڴ���������������
}


void CdrewTeView::OnPopupEllipse()//��Բ
{
	CDC* pDC=GetDC(); 
	pDC->Ellipse(m_poi.x,m_poi.y,m_poi.x+100,m_poi.y+100);//�������λ�û�Բ 
	ReleaseDC(pDC);

	CString str1;
	str1.Format(L"Ellipse from(%d,%d)",m_poi.x,m_poi.y);//��ʽ
	CString str2;
	str2.Format(L" to(%d,%d)",m_poi.x+100,m_poi.y+100);
	CString str=str1+str2;
	//m_st.Format(L"Ellipse at(%d,%d)",m_poi.x,m_poi.y)...//Ҳ����ʹ��view.cpp�ı����ķ�ʽ
	CdrewTeDoc* pDoc=GetDocument();
	pDoc->Set(str,m_poi);//�����ͺ���������ĵ�

	// TODO: �ڴ���������������
}


void CdrewTeView::OnPopupRectangle()//������
{
	CDC* pDC=GetDC();
	pDC->Rectangle(m_poi.x,m_poi.y,m_poi.x+100,m_poi.y+200);//�������λ�û�����
	ReleaseDC(pDC);
	
	CString str1;
	str1.Format(L"Rectangle from(%d,%d)",m_poi.x,m_poi.y);//��ʽ
	CString str2;
	str2.Format(L" to(%d,%d)",m_poi.x+100,m_poi.y+200);
	CString str=str1+str2;
	//m_st.Format(L"Rectangle at(%d,%d)",m_poi.x,m_poi.y)...//Ҳ����ʹ��view.cpp�ı����ķ�ʽ
	CdrewTeDoc* pDoc=GetDocument();
	pDoc->Set(str,m_poi);//�����ͺ���������ĵ�

	// TODO: �ڴ���������������
}


void CdrewTeView::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	m_poi=point;//��¼���
	m_old=m_origin=point;
	m_draw=1;//���ƻ�ͼ��ֹ
	SetCapture();
	SetCursor(m_cursor);
	CRect rect;
	GetClientRect(&rect);
	ClientToScreen(&rect);
	ClipCursor(&rect);

	CView::OnLButtonDown(nFlags, point);
}


void CdrewTeView::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	m_draw=0;//��ͼֹͣ
	ReleaseCapture();
	ClipCursor(NULL);

	CString str1;
	str1.Format(L"Line from(%d,%d)",m_poi.x,m_poi.y);//��ʽ
	CString str2;
	str2.Format(L" to(%d,%d)",point.x,point.y);
	CString str=str1+str2;
	CdrewTeDoc* pDoc=GetDocument();//��ͼ��Ϣ�������ĵ�
	pDoc->Set(str,m_poi);

	CView::OnLButtonUp(nFlags, point);
}


void CdrewTeView::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	CClientDC dc(this);
	dc.SetROP2(R2_NOT);
	if(m_draw==1){//���ڻ�ͼ
		dc.MoveTo(m_origin);
		dc.LineTo(m_old);
		dc.MoveTo(m_origin);
		dc.LineTo(point);
		m_old=point;
	}
	CView::OnMouseMove(nFlags, point);
}


void CdrewTeView::OnRButtonDown(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	
	CView::OnRButtonDown(nFlags, point);
}
