
// drawLoopView.h : CdrawLoopView 类的接口
//

#pragma once


class CdrawLoopView : public CView
{
protected: // 仅从序列化创建
	CdrawLoopView();
	DECLARE_DYNCREATE(CdrawLoopView)

// 特性
public:
	CPoint m_poi[10];
	CPoint p;
	int s,n,speed,pause;
	CdrawLoopDoc* GetDocument() const;

// 操作
public:

// 重写
public:
	virtual void OnDraw(CDC* pDC);  // 重写以绘制该视图
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// 实现
public:
	virtual ~CdrawLoopView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	afx_msg void OnFilePrintPreview();
	afx_msg void OnRButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnContextMenu(CWnd* pWnd, CPoint point);
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnPopupLine();
	afx_msg void OnPopupRectangle();
	afx_msg void OnPopupPolygon();
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnDestroy();
	virtual BOOL PreTranslateMessage(MSG* pMsg);
	afx_msg void OnPause();
	afx_msg void OnSpeed();
};

#ifndef _DEBUG  // drawLoopView.cpp 中的调试版本
inline CdrawLoopDoc* CdrawLoopView::GetDocument() const
   { return reinterpret_cast<CdrawLoopDoc*>(m_pDocument); }
#endif

