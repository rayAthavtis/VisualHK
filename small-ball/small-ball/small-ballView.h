
// small-ballView.h : CsmallballView ��Ľӿ�
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

protected: // �������л�����
	CsmallballView();
	DECLARE_DYNCREATE(CsmallballView)

// ����
public:
	CsmallballDoc* GetDocument() const;

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
	virtual ~CsmallballView();
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

#ifndef _DEBUG  // small-ballView.cpp �еĵ��԰汾
inline CsmallballDoc* CsmallballView::GetDocument() const
   { return reinterpret_cast<CsmallballDoc*>(m_pDocument); }
#endif

