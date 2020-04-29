
// small-ballView.h : CsmallballView 类的接口
//

#pragma once


class CsmallballView : public CView
{
private:
	int x;
	int y;
	int movex;
	int movey;
	int myr;
	bool pause;

protected: // 仅从序列化创建
	CsmallballView();
	DECLARE_DYNCREATE(CsmallballView)

// 特性
public:
	CsmallballDoc* GetDocument() const;

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
	virtual ~CsmallballView();
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
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	afx_msg void OnDestroy();
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnRadius();
	afx_msg void OnPause_Start();
	afx_msg void OnIncrease();
	afx_msg void OnDecrease();
	afx_msg void OnIncreaseN();
	afx_msg void OnDecreaseN();
	afx_msg void OnSetStep();
	afx_msg void OnPauseorstart();
};

#ifndef _DEBUG  // small-ballView.cpp 中的调试版本
inline CsmallballDoc* CsmallballView::GetDocument() const
   { return reinterpret_cast<CsmallballDoc*>(m_pDocument); }
#endif

