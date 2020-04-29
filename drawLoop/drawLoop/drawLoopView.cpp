
// drawLoopView.cpp : CdrawLoopView 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
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
	// 标准打印命令
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

// CdrawLoopView 构造/析构

CdrawLoopView::CdrawLoopView()
{
	//初始化
	for(int i=0;i<10;i++){
		m_poi[i]=CPoint(0,0);
	}
	p=CPoint(0,0);
	speed=10;
	pause=0;
	s=0;
	n=1;
	// TODO: 在此处添加构造代码

}

CdrawLoopView::~CdrawLoopView()
{
}

BOOL CdrawLoopView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CdrawLoopView 绘制

void CdrawLoopView::OnDraw(CDC* pDC)
{
	CdrawLoopDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	
	CString str;
	CPoint point;
	pDoc->Get(str,point);//获取保存内容
	pDC->TextOutW(point.x,point.y,str);//输出

	// TODO: 在此处为本机数据添加绘制代码
}


// CdrawLoopView 打印


void CdrawLoopView::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL CdrawLoopView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void CdrawLoopView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加额外的打印前进行的初始化过程
}

void CdrawLoopView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加打印后进行的清理过程
}

void CdrawLoopView::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	p=m_poi[0]=point;//储存画图初始位置
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CdrawLoopView::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
	CMenu menu;//新建菜单
	menu.LoadMenu(IDR_MENU1);
	CMenu* pMenu=menu.GetSubMenu(0);
	pMenu->TrackPopupMenu(TPM_LEFTALIGN,point.x,point.y,this);//菜单显示位置

/*
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
*/
}


// CdrawLoopView 诊断

#ifdef _DEBUG
void CdrawLoopView::AssertValid() const
{
	CView::AssertValid();
}

void CdrawLoopView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CdrawLoopDoc* CdrawLoopView::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CdrawLoopDoc)));
	return (CdrawLoopDoc*)m_pDocument;
}
#endif //_DEBUG


// CdrawLoopView 消息处理程序


void CdrawLoopView::OnPopupLine()//画线
{
	CDC* pDC=GetDC();
	pDC->MoveTo(m_poi[0].x,m_poi[0].y);//从右键点击位置（菜单位置）画起
	m_poi[1].x=m_poi[0].x+200;
	m_poi[1].y=m_poi[0].y+200;
	pDC->LineTo(m_poi[1].x,m_poi[1].y);
	ReleaseDC(pDC);

	CString str1;
	str1.Format(L"Line from(%d,%d)",m_poi[0].x,m_poi[0].y);//格式
	CString str2;
	str2.Format(L" to(%d,%d)",m_poi[1].x,m_poi[1].y);
	CString str=str1+str2;
	//m_st.Format(L"Line at(%d,%d)",m_poi[0].x,m_poi[0].y)...//也可使用view.cpp的变量的方式
	CdrawLoopDoc* pDoc=GetDocument();
	pDoc->Set(str,m_poi[0]);//将类型和坐标存入文档
	//Invalidate(true);

	// TODO: 在此添加命令处理程序代码
}


void CdrawLoopView::OnPopupRectangle()
{
	CDC* pDC=GetDC();
	m_poi[1].x=m_poi[0].x+100;//四点坐标
	m_poi[1].y=m_poi[0].y;
	m_poi[2].x=m_poi[0].x+100;
	m_poi[2].y=m_poi[0].y+200;
	m_poi[3].x=m_poi[0].x;
	m_poi[3].y=m_poi[0].y+200;
	pDC->Rectangle(m_poi[0].x,m_poi[0].y,m_poi[2].x,m_poi[2].y);//从鼠标点击位置画矩形
	ReleaseDC(pDC);
	
	CString str1;
	str1.Format(L"Rectangle ABCD：A(%d,%d)",m_poi[0].x,m_poi[0].y);//格式
	CString str2;
	str2.Format(L" B(%d,%d)",m_poi[1].x,m_poi[1].y);
	CString str3;
	str3.Format(L" C(%d,%d)",m_poi[2].x,m_poi[2].y);
	CString str4;
	str4.Format(L" D(%d,%d)",m_poi[3].x,m_poi[3].y);
	CString str=str1+str2+str3+str4;
	//m_st.Format(L"Rectangle at(%d,%d)",m_poi[0].x,m_poi[0].y)...//也可以使用view.cpp的变量的方式
	CdrawLoopDoc* pDoc=GetDocument();
	pDoc->Set(str,m_poi[0]);//将类型和坐标存入文档

	// TODO: 在此添加命令处理程序代码
}


void CdrawLoopView::OnPopupPolygon()
{
	CDC* pDC=GetDC();
	m_poi[1].x=m_poi[0].x+100;//多点坐标
	m_poi[1].y=m_poi[0].y-100;
	m_poi[2].x=m_poi[0].x+200;
	m_poi[2].y=m_poi[0].y;
	m_poi[3].x=m_poi[0].x+150;
	m_poi[3].y=m_poi[0].y+100;
	m_poi[4].x=m_poi[0].x+50;
	m_poi[4].y=m_poi[0].y+100;
	pDC->Polygon(m_poi,5);//画多边形
	ReleaseDC(pDC);

	CString str1;
	str1.Format(L"Polygon ABCDE：A(%d,%d)",m_poi[0].x,m_poi[0].y);//格式
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
	//m_st.Format(L"Polygon at(%d,%d)",m_poi[0].x,m_poi[0].y)...//也可以使用view.cpp的变量的方式
	CdrawLoopDoc* pDoc=GetDocument();
	pDoc->Set(str,m_poi[0]);//将类型和坐标存入文档


	// TODO: 在此添加命令处理程序代码
}


void CdrawLoopView::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	if(nIDEvent==1&&pause==0)
	{
		CDC* pDC=GetDC();
		CBitmap bm;  
		bm.LoadBitmap(IDB_BITMAP1);//加载位图
		CDC memDC;  
		memDC.CreateCompatibleDC(pDC);
		memDC.SelectObject(&bm);
		BITMAP info;  
		bm.GetBitmap(&info);
		int xr=(m_poi[n].x-m_poi[s].x)*speed/150;//设置速度
		int yr=(m_poi[n].y-m_poi[s].y)*speed/150;
		pDC->BitBlt(p.x-17,p.y-15,info.bmWidth, info.bmHeight,&memDC,0,0,SRCINVERT);//位图按位置输出
		p.x+=xr;//速度
		p.y+=yr;
		int rc1=(p.x-m_poi[n].x)*xr;//调整参数
		int rc2=(p.y-m_poi[n].y)*yr;
		if(rc1>=0&&rc2>=0)//过界调整
		{
			p.x=m_poi[n].x;
			p.y=m_poi[n].y;
			s=n;
			if(m_poi[n+1].x==0&&m_poi[n+1].y==0)//循环一周回到初始点
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
	
	// TODO:  在此添加您专用的创建代码

	return 0;
}


void CdrawLoopView::OnDestroy()
{
	CView::OnDestroy();
	KillTimer(1);//结束定时器

	// TODO: 在此处添加消息处理程序代码
}


BOOL CdrawLoopView::PreTranslateMessage(MSG* pMsg)
{
	// TODO: 在此添加专用代码和/或调用基类
	if(pMsg->message==WM_KEYDOWN)
	{
		if(pMsg->wParam=='M'||pMsg->wParam=='m')//按下'm'键开始循环
		{
			//消除初始位图
			CDC* pDC=GetDC();
			CBitmap bm;  
			bm.LoadBitmap(IDB_BITMAP1);//加载位图
			CDC memDC;  
			memDC.CreateCompatibleDC(pDC);
			memDC.SelectObject(&bm);
			BITMAP info;  
			bm.GetBitmap(&info);
			pDC->BitBlt(p.x-17,p.y-15,info.bmWidth, info.bmHeight,&memDC,0,0,SRCINVERT);//位图按位置输出
			bm.DeleteObject();

			SetTimer(1,200,NULL);//设置定时器
			return TRUE;
		}
	}

	return CView::PreTranslateMessage(pMsg);
}


void CdrawLoopView::OnPause()
{
	if(pause==0)//改变起止状态
		pause=1;
	else
		pause=0;
	// TODO: 在此添加命令处理程序代码
}


void CdrawLoopView::OnSpeed()
{
	SpeedDlg dlg;
	if(dlg.DoModal()==IDOK){//对话框设置更新速度值
		if(dlg.d_sp!=0)
			speed=dlg.d_sp;
		else if(dlg.speedFree!=0)
			speed=dlg.speedFree;
	}
	// TODO: 在此添加命令处理程序代码
}
