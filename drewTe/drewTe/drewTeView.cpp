
// drewTeView.cpp : CdrewTeView 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
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
	// 标准打印命令
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

// CdrewTeView 构造/析构

CdrewTeView::CdrewTeView()
{
	// TODO: 在此处添加构造代码
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
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CdrewTeView 绘制

void CdrewTeView::OnDraw(CDC* pDC)
{
	CdrewTeDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	CPoint point;
	CString str;
	pDoc->Get(str,point);//获取所存数据
	pDC->TextOutW(point.x,point.y,str);//输出


	// TODO: 在此处为本机数据添加绘制代码
}


// CdrewTeView 打印


void CdrewTeView::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL CdrewTeView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void CdrewTeView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加额外的打印前进行的初始化过程
}

void CdrewTeView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加打印后进行的清理过程
}

void CdrewTeView::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	m_poi=point;//画图起点位置
	ClientToScreen(&point);
	OnContextMenu(this, point);

}

void CdrewTeView::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
	CMenu menu;//新建菜单
	menu.LoadMenu(IDR_POPUPMENU);
	CMenu* pMenu=menu.GetSubMenu(0);
	pMenu->TrackPopupMenu(TPM_LEFTALIGN,point.x,point.y,this);//菜单显示位置

/*
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
*/
}


// CdrewTeView 诊断

#ifdef _DEBUG
void CdrewTeView::AssertValid() const
{
	CView::AssertValid();
}

void CdrewTeView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CdrewTeDoc* CdrewTeView::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CdrewTeDoc)));
	return (CdrewTeDoc*)m_pDocument;
}
#endif //_DEBUG


// CdrewTeView 消息处理程序


void CdrewTeView::OnPopupLine()//画线
{
	CDC* pDC=GetDC();
	pDC->MoveTo(m_poi.x,m_poi.y);//从鼠标点击位置画一条线
	pDC->LineTo(m_poi.x+200,m_poi.y+200);
	ReleaseDC(pDC);

	CString str1;
	str1.Format(L"Line from(%d,%d)",m_poi.x,m_poi.y);//格式
	CString str2;
	str2.Format(L" to(%d,%d)",m_poi.x+200,m_poi.y+200);
	CString str=str1+str2;
	//m_st.Format(L"Line at(%d,%d)",m_poi.x,m_poi.y)...//也可使用view.cpp的变量的方式
	CdrewTeDoc* pDoc=GetDocument();
	pDoc->Set(str,m_poi);//将类型和坐标存入文档

	// TODO: 在此添加命令处理程序代码
}


void CdrewTeView::OnPopupEllipse()//画圆
{
	CDC* pDC=GetDC(); 
	pDC->Ellipse(m_poi.x,m_poi.y,m_poi.x+100,m_poi.y+100);//从鼠标点击位置画圆 
	ReleaseDC(pDC);

	CString str1;
	str1.Format(L"Ellipse from(%d,%d)",m_poi.x,m_poi.y);//格式
	CString str2;
	str2.Format(L" to(%d,%d)",m_poi.x+100,m_poi.y+100);
	CString str=str1+str2;
	//m_st.Format(L"Ellipse at(%d,%d)",m_poi.x,m_poi.y)...//也可以使用view.cpp的变量的方式
	CdrewTeDoc* pDoc=GetDocument();
	pDoc->Set(str,m_poi);//将类型和坐标存入文档

	// TODO: 在此添加命令处理程序代码
}


void CdrewTeView::OnPopupRectangle()//画矩形
{
	CDC* pDC=GetDC();
	pDC->Rectangle(m_poi.x,m_poi.y,m_poi.x+100,m_poi.y+200);//从鼠标点击位置画矩形
	ReleaseDC(pDC);
	
	CString str1;
	str1.Format(L"Rectangle from(%d,%d)",m_poi.x,m_poi.y);//格式
	CString str2;
	str2.Format(L" to(%d,%d)",m_poi.x+100,m_poi.y+200);
	CString str=str1+str2;
	//m_st.Format(L"Rectangle at(%d,%d)",m_poi.x,m_poi.y)...//也可以使用view.cpp的变量的方式
	CdrewTeDoc* pDoc=GetDocument();
	pDoc->Set(str,m_poi);//将类型和坐标存入文档

	// TODO: 在此添加命令处理程序代码
}


void CdrewTeView::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	m_poi=point;//记录起点
	m_old=m_origin=point;
	m_draw=1;//控制画图起止
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
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	m_draw=0;//画图停止
	ReleaseCapture();
	ClipCursor(NULL);

	CString str1;
	str1.Format(L"Line from(%d,%d)",m_poi.x,m_poi.y);//格式
	CString str2;
	str2.Format(L" to(%d,%d)",point.x,point.y);
	CString str=str1+str2;
	CdrewTeDoc* pDoc=GetDocument();//画图信息保存至文档
	pDoc->Set(str,m_poi);

	CView::OnLButtonUp(nFlags, point);
}


void CdrewTeView::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	CClientDC dc(this);
	dc.SetROP2(R2_NOT);
	if(m_draw==1){//正在画图
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
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	
	CView::OnRButtonDown(nFlags, point);
}
