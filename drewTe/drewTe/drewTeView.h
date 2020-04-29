
// drewTeView.h : CdrewTeView 类的接口
//

#pragma once


class CdrewTeView : public CView
{
protected: // 仅从序列化创建
	CdrewTeView();
	DECLARE_DYNCREATE(CdrewTeView)

// 特性
public:
	CdrewTeDoc* GetDocument() const;

private:
	int m_draw;
	HCURSOR m_cursor;
	CPoint m_old,m_origin;

// 操作
public:
	CPoint m_poi;//记录鼠标位置
	//CString m_st;//图形类型

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
	virtual ~CdrewTeView();
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
	afx_msg void OnPopupEllipse();
	afx_msg void OnPopupRectangle();
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnRButtonDown(UINT nFlags, CPoint point);
};

#ifndef _DEBUG  // drewTeView.cpp 中的调试版本
inline CdrewTeDoc* CdrewTeView::GetDocument() const
   { return reinterpret_cast<CdrewTeDoc*>(m_pDocument); }
#endif

