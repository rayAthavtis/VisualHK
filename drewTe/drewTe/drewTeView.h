
// drewTeView.h : CdrewTeView ��Ľӿ�
//

#pragma once


class CdrewTeView : public CView
{
protected: // �������л�����
	CdrewTeView();
	DECLARE_DYNCREATE(CdrewTeView)

// ����
public:
	CdrewTeDoc* GetDocument() const;

private:
	int m_draw;
	HCURSOR m_cursor;
	CPoint m_old,m_origin;

// ����
public:
	CPoint m_poi;//��¼���λ��
	//CString m_st;//ͼ������

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
	virtual ~CdrewTeView();
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
	afx_msg void OnPopupEllipse();
	afx_msg void OnPopupRectangle();
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnRButtonDown(UINT nFlags, CPoint point);
};

#ifndef _DEBUG  // drewTeView.cpp �еĵ��԰汾
inline CdrewTeDoc* CdrewTeView::GetDocument() const
   { return reinterpret_cast<CdrewTeDoc*>(m_pDocument); }
#endif

