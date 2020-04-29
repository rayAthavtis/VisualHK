
// drawLoopView.cpp : CdrawLoopView ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "drawLoop.h"
#endif

#include "drawLoopDoc.h"
#include "drawLoopView.h"
#include "SpeedDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CdrawLoopView

IMPLEMENT_DYNCREATE(CdrawLoopView, CView)

BEGIN_MESSAGE_MAP(CdrawLoopView, CView)
	// ��׼��ӡ����
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CdrawLoopView::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
	ON_COMMAND(ID_POPUP_LINE, &CdrawLoopView::OnPopupLine)
	ON_COMMAND(ID_POPUP_RECTANGLE, &CdrawLoopView::OnPopupRectangle)
	ON_COMMAND(ID_POPUP_POLYGON, &CdrawLoopView::OnPopupPolygon)
	ON_WM_TIMER()
	ON_WM_CREATE()
	ON_WM_DESTROY()
	ON_COMMAND(ID_32775, &CdrawLoopView::OnPause)
	ON_COMMAND(ID_32774, &CdrawLoopView::OnSpeed)
END_MESSAGE_MAP()

// CdrawLoopView ����/����

CdrawLoopView::CdrawLoopView()
{
	//��ʼ��
	for(int i=0;i<10;i++){
		m_poi[i]=CPoint(0,0);
	}
	p=CPoint(0,0);
	speed=10;
	pause=0;
	s=0;
	n=1;
	// TODO: �ڴ˴���ӹ������

}

CdrawLoopView::~CdrawLoopView()
{
}

BOOL CdrawLoopView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// CdrawLoopView ����

void CdrawLoopView::OnDraw(CDC* pDC)
{
	CdrawLoopDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	
	CString str;
	CPoint point;
	pDoc->Get(str,point);//��ȡ��������
	pDC->TextOutW(point.x,point.y,str);//���

	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
}


// CdrawLoopView ��ӡ


void CdrawLoopView::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL CdrawLoopView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// Ĭ��׼��
	return DoPreparePrinting(pInfo);
}

void CdrawLoopView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӷ���Ĵ�ӡǰ���еĳ�ʼ������
}

void CdrawLoopView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӵ�ӡ����е��������
}

void CdrawLoopView::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	p=m_poi[0]=point;//���滭ͼ��ʼλ��
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CdrawLoopView::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
	CMenu menu;//�½��˵�
	menu.LoadMenu(IDR_MENU1);
	CMenu* pMenu=menu.GetSubMenu(0);
	pMenu->TrackPopupMenu(TPM_LEFTALIGN,point.x,point.y,this);//�˵���ʾλ��

/*
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
*/
}


// CdrawLoopView ���

#ifdef _DEBUG
void CdrawLoopView::AssertValid() const
{
	CView::AssertValid();
}

void CdrawLoopView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CdrawLoopDoc* CdrawLoopView::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CdrawLoopDoc)));
	return (CdrawLoopDoc*)m_pDocument;
}
#endif //_DEBUG


// CdrawLoopView ��Ϣ�������


void CdrawLoopView::OnPopupLine()//����
{
	CDC* pDC=GetDC();
	pDC->MoveTo(m_poi[0].x,m_poi[0].y);//���Ҽ����λ�ã��˵�λ�ã�����
	m_poi[1].x=m_poi[0].x+200;
	m_poi[1].y=m_poi[0].y+200;
	pDC->LineTo(m_poi[1].x,m_poi[1].y);
	ReleaseDC(pDC);

	CString str1;
	str1.Format(L"Line from(%d,%d)",m_poi[0].x,m_poi[0].y);//��ʽ
	CString str2;
	str2.Format(L" to(%d,%d)",m_poi[1].x,m_poi[1].y);
	CString str=str1+str2;
	//m_st.Format(L"Line at(%d,%d)",m_poi[0].x,m_poi[0].y)...//Ҳ��ʹ��view.cpp�ı����ķ�ʽ
	CdrawLoopDoc* pDoc=GetDocument();
	pDoc->Set(str,m_poi[0]);//�����ͺ���������ĵ�
	//Invalidate(true);

	// TODO: �ڴ���������������
}


void CdrawLoopView::OnPopupRectangle()
{
	CDC* pDC=GetDC();
	m_poi[1].x=m_poi[0].x+100;//�ĵ�����
	m_poi[1].y=m_poi[0].y;
	m_poi[2].x=m_poi[0].x+100;
	m_poi[2].y=m_poi[0].y+200;
	m_poi[3].x=m_poi[0].x;
	m_poi[3].y=m_poi[0].y+200;
	pDC->Rectangle(m_poi[0].x,m_poi[0].y,m_poi[2].x,m_poi[2].y);//�������λ�û�����
	ReleaseDC(pDC);
	
	CString str1;
	str1.Format(L"Rectangle ABCD��A(%d,%d)",m_poi[0].x,m_poi[0].y);//��ʽ
	CString str2;
	str2.Format(L" B(%d,%d)",m_poi[1].x,m_poi[1].y);
	CString str3;
	str3.Format(L" C(%d,%d)",m_poi[2].x,m_poi[2].y);
	CString str4;
	str4.Format(L" D(%d,%d)",m_poi[3].x,m_poi[3].y);
	CString str=str1+str2+str3+str4;
	//m_st.Format(L"Rectangle at(%d,%d)",m_poi[0].x,m_poi[0].y)...//Ҳ����ʹ��view.cpp�ı����ķ�ʽ
	CdrawLoopDoc* pDoc=GetDocument();
	pDoc->Set(str,m_poi[0]);//�����ͺ���������ĵ�

	// TODO: �ڴ���������������
}


void CdrawLoopView::OnPopupPolygon()
{
	CDC* pDC=GetDC();
	m_poi[1].x=m_poi[0].x+100;//�������
	m_poi[1].y=m_poi[0].y-100;
	m_poi[2].x=m_poi[0].x+200;
	m_poi[2].y=m_poi[0].y;
	m_poi[3].x=m_poi[0].x+150;
	m_poi[3].y=m_poi[0].y+100;
	m_poi[4].x=m_poi[0].x+50;
	m_poi[4].y=m_poi[0].y+100;
	pDC->Polygon(m_poi,5);//�������
	ReleaseDC(pDC);

	CString str1;
	str1.Format(L"Polygon ABCDE��A(%d,%d)",m_poi[0].x,m_poi[0].y);//��ʽ
	CString str2;
	str2.Format(L" B(%d,%d)",m_poi[1].x,m_poi[1].y);
	CString str3;
	str3.Format(L" C(%d,%d)",m_poi[2].x,m_poi[2].y);
	CString str4;
	str4.Format(L" D(%d,%d)",m_poi[3].x,m_poi[3].y);
	CString str5;
	str5.Format(L" E(%d,%d)",m_poi[4].x,m_poi[4].y);
	CString str;
	str=str1+str2+str3+str4+str5;
	//m_st.Format(L"Polygon at(%d,%d)",m_poi[0].x,m_poi[0].y)...//Ҳ����ʹ��view.cpp�ı����ķ�ʽ
	CdrawLoopDoc* pDoc=GetDocument();
	pDoc->Set(str,m_poi[0]);//�����ͺ���������ĵ�


	// TODO: �ڴ���������������
}


void CdrawLoopView::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	if(nIDEvent==1&&pause==0)
	{
		CDC* pDC=GetDC();
		CBitmap bm;  
		bm.LoadBitmap(IDB_BITMAP1);//����λͼ
		CDC memDC;  
		memDC.CreateCompatibleDC(pDC);
		memDC.SelectObject(&bm);
		BITMAP info;  
		bm.GetBitmap(&info);
		int xr=(m_poi[n].x-m_poi[s].x)*speed/150;//�����ٶ�
		int yr=(m_poi[n].y-m_poi[s].y)*speed/150;
		pDC->BitBlt(p.x-17,p.y-15,info.bmWidth, info.bmHeight,&memDC,0,0,SRCINVERT);//λͼ��λ�����
		p.x+=xr;//�ٶ�
		p.y+=yr;
		int rc1=(p.x-m_poi[n].x)*xr;//��������
		int rc2=(p.y-m_poi[n].y)*yr;
		if(rc1>=0&&rc2>=0)//�������
		{
			p.x=m_poi[n].x;
			p.y=m_poi[n].y;
			s=n;
			if(m_poi[n+1].x==0&&m_poi[n+1].y==0)//ѭ��һ�ܻص���ʼ��
				n=0;
			else
				n+=1;
		}
		pDC->BitBlt(p.x-17,p.y-15,info.bmWidth, info.bmHeight,&memDC,0,0,SRCINVERT);
		bm.DeleteObject();
	}
	CView::OnTimer(nIDEvent);
}


int CdrawLoopView::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CView::OnCreate(lpCreateStruct) == -1)
		return -1;
	
	// TODO:  �ڴ������ר�õĴ�������

	return 0;
}


void CdrawLoopView::OnDestroy()
{
	CView::OnDestroy();
	KillTimer(1);//������ʱ��

	// TODO: �ڴ˴������Ϣ����������
}


BOOL CdrawLoopView::PreTranslateMessage(MSG* pMsg)
{
	// TODO: �ڴ����ר�ô����/����û���
	if(pMsg->message==WM_KEYDOWN)
	{
		if(pMsg->wParam=='M'||pMsg->wParam=='m')//����'m'����ʼѭ��
		{
			//������ʼλͼ
			CDC* pDC=GetDC();
			CBitmap bm;  
			bm.LoadBitmap(IDB_BITMAP1);//����λͼ
			CDC memDC;  
			memDC.CreateCompatibleDC(pDC);
			memDC.SelectObject(&bm);
			BITMAP info;  
			bm.GetBitmap(&info);
			pDC->BitBlt(p.x-17,p.y-15,info.bmWidth, info.bmHeight,&memDC,0,0,SRCINVERT);//λͼ��λ�����
			bm.DeleteObject();

			SetTimer(1,200,NULL);//���ö�ʱ��
			return TRUE;
		}
	}

	return CView::PreTranslateMessage(pMsg);
}


void CdrawLoopView::OnPause()
{
	if(pause==0)//�ı���ֹ״̬
		pause=1;
	else
		pause=0;
	// TODO: �ڴ���������������
}


void CdrawLoopView::OnSpeed()
{
	SpeedDlg dlg;
	if(dlg.DoModal()==IDOK){//�Ի������ø����ٶ�ֵ
		if(dlg.d_sp!=0)
			speed=dlg.d_sp;
		else if(dlg.speedFree!=0)
			speed=dlg.speedFree;
	}
	// TODO: �ڴ���������������
}
