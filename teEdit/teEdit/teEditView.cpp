
// teEditView.cpp : CteEditView 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
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
	// 标准打印命令
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

// CteEditView 构造/析构

CteEditView::CteEditView()
{
	// TODO: 在此处添加构造代码
	m_font=0;
}

CteEditView::~CteEditView()
{
}

BOOL CteEditView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CteEditView 绘制

void CteEditView::OnDraw(CDC* pDC)
{
	CteEditDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	if(m_font==1)//设置为系统字体
		pDC->SelectStockObject(SYSTEM_FONT);
	else if(m_font==2)//设置为ANSI字体
		pDC->SelectStockObject(ANSI_FIXED_FONT);
	pDC->TextOutW(0,0,str);
	// TODO: 在此处为本机数据添加绘制代码
}


// CteEditView 打印


void CteEditView::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL CteEditView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void CteEditView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加额外的打印前进行的初始化过程
}

void CteEditView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加打印后进行的清理过程
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


// CteEditView 诊断

#ifdef _DEBUG
void CteEditView::AssertValid() const
{
	CView::AssertValid();
}

void CteEditView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CteEditDoc* CteEditView::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CteEditDoc)));
	return (CteEditDoc*)m_pDocument;
}
#endif //_DEBUG


// CteEditView 消息处理程序


void CteEditView::OnteEdit()
{

	dlgEdit dlg;
	if(dlg.DoModal()==IDOK){//对话框输入确认
		str=dlg.m_str;
		Invalidate(true);//刷新
	}
	// TODO: 在此添加命令处理程序代码
}

void CteEditView::OnSetDFont()
{
	m_font=0;
	// TODO: 在此添加命令处理程序代码
}


void CteEditView::OnSetSFont()
{
	m_font=1;
	// TODO: 在此添加命令处理程序代码
}


void CteEditView::OnSetAFont()
{
	m_font=2;
	// TODO: 在此添加命令处理程序代码
}


