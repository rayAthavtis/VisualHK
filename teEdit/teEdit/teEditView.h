
// teEditView.h : CteEditView ��Ľӿ�
//

#pragma once


class CteEditView : public CView
{
protected: // �������л�����
	CteEditView();
	DECLARE_DYNCREATE(CteEditView)

// ����
public:
	CteEditDoc* GetDocument() const;

// ����
public:
	CString str;
	int m_font;
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
	virtual ~CteEditView();
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
	afx_msg void OnteEdit();
	afx_msg void OnSetDFont();
	afx_msg void OnSetSFont();
	afx_msg void OnSetAFont();
};

#ifndef _DEBUG  // teEditView.cpp �еĵ��԰汾
inline CteEditDoc* CteEditView::GetDocument() const
   { return reinterpret_cast<CteEditDoc*>(m_pDocument); }
#endif

