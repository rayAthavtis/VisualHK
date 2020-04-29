
// small-ballView.cpp : CsmallballView ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "small-ball.h"
#endif

#include "small-ballDoc.h"
#include "small-ballView.h"
#include "RadiusEditor.h"
#include "StepEditor.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CsmallballView

IMPLEMENT_DYNCREATE(CsmallballView, CView)

BEGIN_MESSAGE_MAP(CsmallballView, CView)
	// ��׼��ӡ����
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CsmallballView::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
	ON_WM_TIMER()
	ON_WM_DESTROY()
	ON_WM_CREATE()
	ON_COMMAND(ID_32774, &CsmallballView::OnRadius)
	ON_COMMAND(ID_32776, &CsmallballView::OnPause_Start)
	ON_COMMAND(ID_32777, &CsmallballView::OnIncrease)
	ON_COMMAND(ID_32778, &CsmallballView::OnDecrease)
	ON_COMMAND(ID_32780, &CsmallballView::OnIncreaseN)
	ON_COMMAND(ID_32781, &CsmallballView::OnDecreaseN)
	ON_COMMAND(ID_32783, &CsmallballView::OnSetStep)
	ON_COMMAND(ID_PauseOrStart, &CsmallballView::OnPauseorstart)
END_MESSAGE_MAP()

// CsmallballView ����/����

CsmallballView::CsmallballView()
	: x(0), y(0), movex(0), movey(0), myr(15), pause(0)//��/�����ꡢ��/�����ƶ����ȡ��뾶���ƶ�/ֹͣ
{
	// TODO: �ڴ˴���ӹ������
	movex=movey=5;//�ƶ����ȳ�ʼ��Ϊ5����������ͬ�Գ�45���
}

CsmallballView::~CsmallballView()
{
}

BOOL CsmallballView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// CsmallballView ����

void CsmallballView::OnDraw(CDC* pDC)
{
	CsmallballDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
}


// CsmallballView ��ӡ


void CsmallballView::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL CsmallballView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// Ĭ��׼��
	return DoPreparePrinting(pInfo);
}

void CsmallballView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӷ���Ĵ�ӡǰ���еĳ�ʼ������
}

void CsmallballView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӵ�ӡ����е��������
}

void CsmallballView::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CsmallballView::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CsmallballView ���

#ifdef _DEBUG
void CsmallballView::AssertValid() const
{
	CView::AssertValid();
}

void CsmallballView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CsmallballDoc* CsmallballView::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CsmallballDoc)));
	return (CsmallballDoc*)m_pDocument;
}
#endif //_DEBUG


// CsmallballView ��Ϣ�������


void CsmallballView::OnTimer(UINT_PTR nIDEvent)//��ʱ����Ϣ�������Դ���
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	if(nIDEvent==1&&pause==0)
	{
		CDC* pDC=GetDC();
		CRect rect;
		GetClientRect(&rect);
		pDC->SetROP2(R2_XORPEN);
		pDC->Ellipse(x,y,x+myr,y+myr);//��С��
		x+=movex;//�ƶ�
		y+=movey;
		if(x<0||x>rect.right-myr)//���߽練��
			movex=0-movex;
		if(y<0||y>rect.bottom-myr)
			movey=0-movey;
		pDC->Ellipse(x,y,x+myr,y+myr);
	}
	CView::OnTimer(nIDEvent);
}


void CsmallballView::OnDestroy()
{
	CView::OnDestroy();
	KillTimer(1);
	// TODO: �ڴ˴������Ϣ����������
}


int CsmallballView::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CView::OnCreate(lpCreateStruct) == -1)
		return -1;
	SetTimer(1,20,NULL);//���ü�ʱ����������
	// TODO:  �ڴ������ר�õĴ�������

	return 0;
}


void CsmallballView::OnRadius()//�뾶����
{
	CRect rect;
	GetClientRect(&rect);
	RadiusEditor dlg;//�뾶�Ի���
	if(dlg.DoModal()==IDOK){//�Ի�������ȷ��
		if(x>rect.right-dlg.m_myR)//����
			x=rect.right-dlg.m_myR;
		if(y>rect.bottom-dlg.m_myR)
			y=rect.bottom-dlg.m_myR;
		myr=dlg.m_myR;//���°뾶ֵ
		Invalidate(true);//ˢ��
	}

	// TODO: �ڴ���������������
}


void CsmallballView::OnPause_Start()//�˵��������ƶ�/ֹͣ
{
	if(pause==0)//�ı��ƶ�/��ͣ״̬
		pause=1;
	else
		pause=0;
	// TODO: �ڴ���������������
}


void CsmallballView::OnIncrease()
{
	if(movex>=0)//��5Ϊ����������򲽷�
		movex+=5;
	else
		movex-=5;
	// TODO: �ڴ���������������
}


void CsmallballView::OnDecrease()
{
	if(movex>=0)//��5Ϊ���ȼ�С���򲽷�
		movex-=5;
	else
		movex+=5;
	// TODO: �ڴ���������������
}


void CsmallballView::OnIncreaseN()
{
	if(movey>=0)//��5Ϊ�����������򲽷�
		movey+=5;
	else
		movey-=5;
	// TODO: �ڴ���������������
}


void CsmallballView::OnDecreaseN()
{
	if(movey>=0)//��5Ϊ���ȼ�С���򲽷�
		movey-=5;
	else
		movey+=5;
	// TODO: �ڴ���������������
}





void CsmallballView::OnSetStep()
{
	StepEditor dlg;//���������Ի���
	if(dlg.DoModal()==IDOK){//�Ի�������ȷ��
		movex=dlg.m_movex;//���º��ݲ���
		movey=dlg.m_movey;
		Invalidate(true);//ˢ��
	}

	// TODO: �ڴ���������������
}


void CsmallballView::OnPauseorstart()//������ͼ�갴ť�����ƶ�/��ͣ
{
	if(pause==0)
		pause=1;
	else
		pause=0;
	// TODO: �ڴ���������������
}
