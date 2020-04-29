
// mouse_kbmesView.h : Cmouse_kbmesView ��Ľӿ�
//

#pragma once


class Cmouse_kbmesView : public CView
{
protected: // �������л�����
	Cmouse_kbmesView();
	DECLARE_DYNCREATE(Cmouse_kbmesView)

private:
	CPoint  m_pos;
	CString m_str;

// ����
public:
	Cmouse_kbmesDoc* GetDocument() const;

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
	virtual ~Cmouse_kbmesView();
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
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnRButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnChar(UINT nChar, UINT nRepCnt, UINT nFlags);
	virtual BOOL PreTranslateMessage(MSG* pMsg);
	afx_msg LRESULT OnMyMessage(WPARAM wParam,LPARAM lParam);
	afx_msg void OnHotKey(UINT nHotKeyId, UINT nKey1, UINT nKey2);
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnDestroy();
};

#ifndef _DEBUG  // mouse_kbmesView.cpp �еĵ��԰汾
inline Cmouse_kbmesDoc* Cmouse_kbmesView::GetDocument() const
   { return reinterpret_cast<Cmouse_kbmesDoc*>(m_pDocument); }
#endif

