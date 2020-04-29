
// contrlUView.cpp : CcontrlUView 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
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
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CcontrlUView::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
	ON_COMMAND(ID_CTRL, &CcontrlUView::OnCtrl)
END_MESSAGE_MAP()

// CcontrlUView 构造/析构

CcontrlUView::CcontrlUView()
{
	// TODO: 在此处添加构造代码
	m_id=17110;
	m_name=_T("安乔");
	m_birth=_T("1999/06/01");
	m_place=_T("天津");
	m_gender=_T("女");
	change=0;
}

CcontrlUView::~CcontrlUView()
{
}

BOOL CcontrlUView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CcontrlUView 绘制

void CcontrlUView::OnDraw(CDC* pDC)
{
	CcontrlUDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	pDoc->Get(m_id,m_name,m_birth,m_place,m_gender,change);
	CString id;
	id.Format(L"%d",m_id);
	pDC->TextOutW(10,10,L"学号："+id);
	pDC->TextOutW(10,40,L"姓名："+m_name);
	pDC->TextOutW(10,70,L"性别："+m_gender);
	pDC->TextOutW(10,100,L"生日："+m_birth);
	pDC->TextOutW(10,130,L"所在地："+m_place);
	pDC->TextOutW(150,10,L"照片：");
	CBitmap bm;  	if (change==0)
		bm.LoadBitmap(IDB_PHOTO2);
	else
		bm.LoadBitmap(IDB_PHOTO1);	CDC memDC;  	memDC.CreateCompatibleDC(pDC);	memDC.SelectObject(&bm);	BITMAP info;  	bm.GetBitmap(&info);	pDC->BitBlt(150,40,info.bmWidth, info.bmHeight,&memDC,0,0,SRCCOPY);	bm.DeleteObject();

	// TODO: 在此处为本机数据添加绘制代码
}


// CcontrlUView 打印


void CcontrlUView::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL CcontrlUView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void CcontrlUView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加额外的打印前进行的初始化过程
}

void CcontrlUView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加打印后进行的清理过程
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


// CcontrlUView 诊断

#ifdef _DEBUG
void CcontrlUView::AssertValid() const
{
	CView::AssertValid();
}

void CcontrlUView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CcontrlUDoc* CcontrlUView::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CcontrlUDoc)));
	return (CcontrlUDoc*)m_pDocument;
}
#endif //_DEBUG


// CcontrlUView 消息处理程序


void CcontrlUView::OnCtrl()
{
	MesDLG dlg;
	if(dlg.DoModal()==IDOK){
		m_id=dlg.m_id;
		m_name=dlg.m_name;
		m_birth=dlg.m_birth.Format(_T("%Y/%m/%d"));
		m_place=dlg.m_place;
		if(dlg.m_gender==0)
			m_gender="女";
		else if(dlg.m_gender==1)
			m_gender="男";
		change=dlg.change;
		Invalidate(true);
	}
	CcontrlUDoc* pDoc = GetDocument();
	pDoc->Set(m_id,m_name,m_birth,m_place,m_gender,change);
	// TODO: 在此添加命令处理程序代码
}
