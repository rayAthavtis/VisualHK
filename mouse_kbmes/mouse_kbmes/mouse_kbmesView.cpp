
// mouse_kbmesView.cpp : Cmouse_kbmesView ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "mouse_kbmes.h"
#endif

#include "mouse_kbmesDoc.h"
#include "mouse_kbmesView.h"


#define WM_MY_MESSAGE WM_USER+100

#ifdef _DEBUG
#define new DEBUG_NEW
#endif



// Cmouse_kbmesView

IMPLEMENT_DYNCREATE(Cmouse_kbmesView, CView)

BEGIN_MESSAGE_MAP(Cmouse_kbmesView, CView)
	// ��׼��ӡ����
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &Cmouse_kbmesView::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
	ON_WM_LBUTTONDOWN()
	ON_WM_RBUTTONDOWN()
	ON_WM_CHAR()
	ON_MESSAGE(WM_MY_MESSAGE,OnMyMessage)// //ע���Զ���WM_MY_MESSAGE��Ϣ
	ON_WM_HOTKEY()
	ON_WM_CREATE()
	ON_WM_DESTROY()
END_MESSAGE_MAP()

// Cmouse_kbmesView ����/����

Cmouse_kbmesView::Cmouse_kbmesView()
{
	// TODO: �ڴ˴���ӹ������

	m_pos=CPoint(0,0);
	m_str.Empty();

}

Cmouse_kbmesView::~Cmouse_kbmesView()
{
}

BOOL Cmouse_kbmesView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// Cmouse_kbmesView ����

void Cmouse_kbmesView::OnDraw(CDC* pDC)
{
	Cmouse_kbmesDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	pDC->TextOutW(m_pos.x,m_pos.y,m_str);

	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
}


// Cmouse_kbmesView ��ӡ


void Cmouse_kbmesView::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL Cmouse_kbmesView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// Ĭ��׼��
	return DoPreparePrinting(pInfo);
}

void Cmouse_kbmesView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӷ���Ĵ�ӡǰ���еĳ�ʼ������
}

void Cmouse_kbmesView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӵ�ӡ����е��������
}

void Cmouse_kbmesView::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void Cmouse_kbmesView::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// Cmouse_kbmesView ���

#ifdef _DEBUG
void Cmouse_kbmesView::AssertValid() const
{
	CView::AssertValid();
}

void Cmouse_kbmesView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

Cmouse_kbmesDoc* Cmouse_kbmesView::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(Cmouse_kbmesDoc)));
	return (Cmouse_kbmesDoc*)m_pDocument;
}
#endif //_DEBUG


// Cmouse_kbmesView ��Ϣ�������


void Cmouse_kbmesView::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ

	/*CDC* pDC=GetDC();
	pDC->TextOutW(point.x,point.y,L"Mouse Clicked!");
	ReleaseDC(pDC);
	*/

	m_pos=point;//��ȡ�����λ��
	CString str;
	if(nFlags & MK_CONTROL){//������+control�������Ҽ�
	  str.Format(L"(%d,%d) Ctrl + LMouse Clicked!",point.x,point.y);//��ʽ�������λ��+����/�������
	  MessageBox(str);//�Ի�����ʾ�����Ϣ
	}
	else{//����������
	  //m_str=L"LMouse Clicked!";
	  str.Format(L"(%d,%d) LMouse Clicked!",point.x,point.y);//��ʽ����ʾ��λ��+����/�������
	  MessageBox(str);//�Ի�����ʾ�����Ϣ
	}
	//Invalidate(true);

	CView::OnLButtonDown(nFlags, point);
}


void Cmouse_kbmesView::OnRButtonDown(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ

	CView::OnRButtonDown(nFlags, point);
}


void Cmouse_kbmesView::OnChar(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ

	/*CString str;
	str.Format(L"%c Key Entered!",nChar);
	MessageBox(str);*/

	m_pos.x=410;//�趨��ʾ��Ϣλ��
	m_pos.y=160;
	CString str;
	str.Format(L"%c Key Entered!",nChar);//��ʽ����ʾ����������
	m_str=str;//�ͻ���ָ��λ����ʾ�����Ϣ
	Invalidate(true);//ˢ��

	CView::OnChar(nChar, nRepCnt, nFlags);
}

BOOL Cmouse_kbmesView::PreTranslateMessage(MSG* pMsg)//���ⰴ��
{
	// TODO: �ڴ����ר�ô����/����û���

	if(pMsg->message==WM_KEYDOWN)
	{
		m_pos.x=410;//�趨��ʾ��Ϣλ��
	  	m_pos.y=160;
		switch(pMsg->wParam){
		case VK_F4:
		  //MessageBox(L"F4 Key Entered!");
		  m_str=L"F4 Key Entered!";//�ͻ���ָ��λ����ʾ�����Ϣ
		  break;
		case VK_UP:  
		  //MessageBox(L"�� Key Entered!");
		  m_str=L"�� Key Entered!";//�ͻ���ָ��λ����ʾ�����Ϣ
		  break;
		case VK_LEFT:  
		  m_str=L"�� Key Entered!";//�ͻ���ָ��λ����ʾ�����Ϣ
		  break;
		case VK_SHIFT:  
		  m_str=L"Shift Key Entered!";//�ͻ���ָ��λ����ʾ�����Ϣ
		  break;
		case VK_CONTROL:  
		  m_str=L"Ctrl Key Entered!";//�ͻ���ָ��λ����ʾ�����Ϣ
		  break;
		case VK_MENU:  
		  m_str=L"Menu Key Entered!";//�ͻ���ָ��λ����ʾ�����Ϣ
		  break;
		  //�������
		}
		Invalidate(true);//ˢ��
	}

	return CView::PreTranslateMessage(pMsg);
}

LRESULT Cmouse_kbmesView::OnMyMessage(WPARAM wParam, LPARAM lParam)
{
	m_pos.x=360;//�����Զ�����Ϣ��ʾλ��
	m_pos.y=160;
	CString str;
	str.Format(L"? Key Entered! Message Param is %d and %d", wParam, lParam);//��ʽ����ʾ
	m_str=str;
	Invalidate(true);//ˢ��
	return 0;
}

void Cmouse_kbmesView::OnHotKey(UINT nHotKeyId, UINT nKey1, UINT nKey2)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ

	if(nHotKeyId==1001)//�����ȼ���Ϣ
		PostMessage(WM_MY_MESSAGE,50,100);//�����Զ�����Ϣ

	CView::OnHotKey(nHotKeyId, nKey1, nKey2);
}


int Cmouse_kbmesView::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CView::OnCreate(lpCreateStruct) == -1)
		return -1;

	RegisterHotKey(m_hWnd,1001,MOD_SHIFT,VK_OEM_2);//shift+��/����ע���ݼ�������

	// TODO:  �ڴ������ר�õĴ�������

	return 0;
}


void Cmouse_kbmesView::OnDestroy()
{
	CView::OnDestroy();

	UnregisterHotKey(m_hWnd,1001);//ȡ��ע��

	// TODO: �ڴ˴������Ϣ����������
}
