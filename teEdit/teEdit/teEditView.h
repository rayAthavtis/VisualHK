
// teEditView.h : CteEditView 类的接口
//

#pragma once


class CteEditView : public CView
{
protected: // 仅从序列化创建
	CteEditView();
	DECLARE_DYNCREATE(CteEditView)

// 特性
public:
	CteEditDoc* GetDocument() const;

// 操作
public:
	CString str;
	int m_font;
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
	virtual ~CteEditView();
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
	afx_msg void OnteEdit();
	afx_msg void OnSetDFont();
	afx_msg void OnSetSFont();
	afx_msg void OnSetAFont();
};

#ifndef _DEBUG  // teEditView.cpp 中的调试版本
inline CteEditDoc* CteEditView::GetDocument() const
   { return reinterpret_cast<CteEditDoc*>(m_pDocument); }
#endif

