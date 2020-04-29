
// mouse_kbmesView.cpp : Cmouse_kbmesView 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
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
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &Cmouse_kbmesView::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
	ON_WM_LBUTTONDOWN()
	ON_WM_RBUTTONDOWN()
	ON_WM_CHAR()
	ON_MESSAGE(WM_MY_MESSAGE,OnMyMessage)// //注册自定义WM_MY_MESSAGE消息
	ON_WM_HOTKEY()
	ON_WM_CREATE()
	ON_WM_DESTROY()
END_MESSAGE_MAP()

// Cmouse_kbmesView 构造/析构

Cmouse_kbmesView::Cmouse_kbmesView()
{
	// TODO: 在此处添加构造代码

	m_pos=CPoint(0,0);
	m_str.Empty();

}

Cmouse_kbmesView::~Cmouse_kbmesView()
{
}

BOOL Cmouse_kbmesView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// Cmouse_kbmesView 绘制

void Cmouse_kbmesView::OnDraw(CDC* pDC)
{
	Cmouse_kbmesDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	pDC->TextOutW(m_pos.x,m_pos.y,m_str);

	// TODO: 在此处为本机数据添加绘制代码
}


// Cmouse_kbmesView 打印


void Cmouse_kbmesView::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL Cmouse_kbmesView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void Cmouse_kbmesView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加额外的打印前进行的初始化过程
}

void Cmouse_kbmesView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加打印后进行的清理过程
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


// Cmouse_kbmesView 诊断

#ifdef _DEBUG
void Cmouse_kbmesView::AssertValid() const
{
	CView::AssertValid();
}

void Cmouse_kbmesView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

Cmouse_kbmesDoc* Cmouse_kbmesView::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(Cmouse_kbmesDoc)));
	return (Cmouse_kbmesDoc*)m_pDocument;
}
#endif //_DEBUG


// Cmouse_kbmesView 消息处理程序


void Cmouse_kbmesView::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值

	/*CDC* pDC=GetDC();
	pDC->TextOutW(point.x,point.y,L"Mouse Clicked!");
	ReleaseDC(pDC);
	*/

	m_pos=point;//获取鼠标点击位置
	CString str;
	if(nFlags & MK_CONTROL){//鼠标左键+control替代鼠标右键
	  str.Format(L"(%d,%d) Ctrl + LMouse Clicked!",point.x,point.y);//格式化输出：位置+所按/点击键名
	  MessageBox(str);//对话框显示相关信息
	}
	else{//单击鼠标左键
	  //m_str=L"LMouse Clicked!";
	  str.Format(L"(%d,%d) LMouse Clicked!",point.x,point.y);//格式化显示：位置+所按/点击键名
	  MessageBox(str);//对话框显示相关信息
	}
	//Invalidate(true);

	CView::OnLButtonDown(nFlags, point);
}


void Cmouse_kbmesView::OnRButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值

	CView::OnRButtonDown(nFlags, point);
}


void Cmouse_kbmesView::OnChar(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值

	/*CString str;
	str.Format(L"%c Key Entered!",nChar);
	MessageBox(str);*/

	m_pos.x=410;//设定显示信息位置
	m_pos.y=160;
	CString str;
	str.Format(L"%c Key Entered!",nChar);//格式化显示，所按键名
	m_str=str;//客户区指定位置显示相关信息
	Invalidate(true);//刷新

	CView::OnChar(nChar, nRepCnt, nFlags);
}

BOOL Cmouse_kbmesView::PreTranslateMessage(MSG* pMsg)//特殊按键
{
	// TODO: 在此添加专用代码和/或调用基类

	if(pMsg->message==WM_KEYDOWN)
	{
		m_pos.x=410;//设定显示信息位置
	  	m_pos.y=160;
		switch(pMsg->wParam){
		case VK_F4:
		  //MessageBox(L"F4 Key Entered!");
		  m_str=L"F4 Key Entered!";//客户区指定位置显示相关信息
		  break;
		case VK_UP:  
		  //MessageBox(L"↑ Key Entered!");
		  m_str=L"↑ Key Entered!";//客户区指定位置显示相关信息
		  break;
		case VK_LEFT:  
		  m_str=L"← Key Entered!";//客户区指定位置显示相关信息
		  break;
		case VK_SHIFT:  
		  m_str=L"Shift Key Entered!";//客户区指定位置显示相关信息
		  break;
		case VK_CONTROL:  
		  m_str=L"Ctrl Key Entered!";//客户区指定位置显示相关信息
		  break;
		case VK_MENU:  
		  m_str=L"Menu Key Entered!";//客户区指定位置显示相关信息
		  break;
		  //诸如此类
		}
		Invalidate(true);//刷新
	}

	return CView::PreTranslateMessage(pMsg);
}

LRESULT Cmouse_kbmesView::OnMyMessage(WPARAM wParam, LPARAM lParam)
{
	m_pos.x=360;//设置自定义消息显示位置
	m_pos.y=160;
	CString str;
	str.Format(L"? Key Entered! Message Param is %d and %d", wParam, lParam);//格式化显示
	m_str=str;
	Invalidate(true);//刷新
	return 0;
}

void Cmouse_kbmesView::OnHotKey(UINT nHotKeyId, UINT nKey1, UINT nKey2)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值

	if(nHotKeyId==1001)//触发热键消息
		PostMessage(WM_MY_MESSAGE,50,100);//发送自定义消息

	CView::OnHotKey(nHotKeyId, nKey1, nKey2);
}


int Cmouse_kbmesView::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CView::OnCreate(lpCreateStruct) == -1)
		return -1;

	RegisterHotKey(m_hWnd,1001,MOD_SHIFT,VK_OEM_2);//shift+‘/？’注册快捷键“？”

	// TODO:  在此添加您专用的创建代码

	return 0;
}


void Cmouse_kbmesView::OnDestroy()
{
	CView::OnDestroy();

	UnregisterHotKey(m_hWnd,1001);//取消注册

	// TODO: 在此处添加消息处理程序代码
}
