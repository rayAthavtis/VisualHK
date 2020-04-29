
// contrlUView.h : CcontrlUView 类的接口
//

#pragma once


class CcontrlUView : public CView
{
protected: // 仅从序列化创建
	CcontrlUView();
	DECLARE_DYNCREATE(CcontrlUView)

// 特性
public:
	CcontrlUDoc* GetDocument() const;

// 操作
public:
	int m_id;
	CString m_name;
	CString m_birth;
	CString m_place;
	CString m_gender;
	int change;
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
	virtual ~CcontrlUView();
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
	afx_msg void OnCtrl();
};

#ifndef _DEBUG  // contrlUView.cpp 中的调试版本
inline CcontrlUDoc* CcontrlUView::GetDocument() const
   { return reinterpret_cast<CcontrlUDoc*>(m_pDocument); }
#endif

