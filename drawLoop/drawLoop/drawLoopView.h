
// drawLoopView.h : CdrawLoopView ��Ľӿ�
//

#pragma once


class CdrawLoopView : public CView
{
protected: // �������л�����
	CdrawLoopView();
	DECLARE_DYNCREATE(CdrawLoopView)

// ����
public:
	CPoint m_poi[10];
	CPoint p;
	int s,n,speed,pause;
	CdrawLoopDoc* GetDocument() const;

// ����
public:

// ��д
public:
	virtual void OnDraw(CDC* pDC);  // ��д�Ի��Ƹ���ͼ
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// ʵ��
public:
	virtual ~CdrawLoopView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
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

#ifndef _DEBUG  // drawLoopView.cpp �еĵ��԰汾
inline CdrawLoopDoc* CdrawLoopView::GetDocument() const
   { return reinterpret_cast<CdrawLoopDoc*>(m_pDocument); }
#endif

