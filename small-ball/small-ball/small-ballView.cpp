
// small-ballView.cpp : CsmallballView 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
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
	// 标准打印命令
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

// CsmallballView 构造/析构

CsmallballView::CsmallballView()
	: x(0), y(0), movex(0), movey(0), myr(15), pause(0)//横/纵坐标、横/纵向移动幅度、半径、移动/停止
{
	// TODO: 在此处添加构造代码
	movex=movey=5;//移动幅度初始化为5，横纵向相同以成45°角
}

CsmallballView::~CsmallballView()
{
}

BOOL CsmallballView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CsmallballView 绘制

void CsmallballView::OnDraw(CDC* pDC)
{
	CsmallballDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	// TODO: 在此处为本机数据添加绘制代码
}


// CsmallballView 打印


void CsmallballView::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL CsmallballView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void CsmallballView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加额外的打印前进行的初始化过程
}

void CsmallballView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加打印后进行的清理过程
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


// CsmallballView 诊断

#ifdef _DEBUG
void CsmallballView::AssertValid() const
{
	CView::AssertValid();
}

void CsmallballView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CsmallballDoc* CsmallballView::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CsmallballDoc)));
	return (CsmallballDoc*)m_pDocument;
}
#endif //_DEBUG


// CsmallballView 消息处理程序


void CsmallballView::OnTimer(UINT_PTR nIDEvent)//计时器消息，周期性处理
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	if(nIDEvent==1&&pause==0)
	{
		CDC* pDC=GetDC();
		CRect rect;
		GetClientRect(&rect);
		pDC->SetROP2(R2_XORPEN);
		pDC->Ellipse(x,y,x+myr,y+myr);//画小球
		x+=movex;//移动
		y+=movey;
		if(x<0||x>rect.right-myr)//遇边界反弹
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
	// TODO: 在此处添加消息处理程序代码
}


int CsmallballView::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CView::OnCreate(lpCreateStruct) == -1)
		return -1;
	SetTimer(1,20,NULL);//设置计时器控制周期
	// TODO:  在此添加您专用的创建代码

	return 0;
}


void CsmallballView::OnRadius()//半径调整
{
	CRect rect;
	GetClientRect(&rect);
	RadiusEditor dlg;//半径对话框
	if(dlg.DoModal()==IDOK){//对话框输入确认
		if(x>rect.right-dlg.m_myR)//修正
			x=rect.right-dlg.m_myR;
		if(y>rect.bottom-dlg.m_myR)
			y=rect.bottom-dlg.m_myR;
		myr=dlg.m_myR;//更新半径值
		Invalidate(true);//刷新
	}

	// TODO: 在此添加命令处理程序代码
}


void CsmallballView::OnPause_Start()//菜单栏控制移动/停止
{
	if(pause==0)//改变移动/暂停状态
		pause=1;
	else
		pause=0;
	// TODO: 在此添加命令处理程序代码
}


void CsmallballView::OnIncrease()
{
	if(movex>=0)//以5为幅度增大横向步幅
		movex+=5;
	else
		movex-=5;
	// TODO: 在此添加命令处理程序代码
}


void CsmallballView::OnDecrease()
{
	if(movex>=0)//以5为幅度减小横向步幅
		movex-=5;
	else
		movex+=5;
	// TODO: 在此添加命令处理程序代码
}


void CsmallballView::OnIncreaseN()
{
	if(movey>=0)//以5为幅度增大纵向步幅
		movey+=5;
	else
		movey-=5;
	// TODO: 在此添加命令处理程序代码
}


void CsmallballView::OnDecreaseN()
{
	if(movey>=0)//以5为幅度减小纵向步幅
		movey-=5;
	else
		movey+=5;
	// TODO: 在此添加命令处理程序代码
}





void CsmallballView::OnSetStep()
{
	StepEditor dlg;//步幅调整对话框
	if(dlg.DoModal()==IDOK){//对话框输入确认
		movex=dlg.m_movex;//更新横纵步幅
		movey=dlg.m_movey;
		Invalidate(true);//刷新
	}

	// TODO: 在此添加命令处理程序代码
}


void CsmallballView::OnPauseorstart()//工具栏图标按钮控制移动/暂停
{
	if(pause==0)
		pause=1;
	else
		pause=0;
	// TODO: 在此添加命令处理程序代码
}
