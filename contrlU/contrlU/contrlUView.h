
// contrlUView.h : CcontrlUView ��Ľӿ�
//

#pragma once


class CcontrlUView : public CView
{
protected: // �������л�����
	CcontrlUView();
	DECLARE_DYNCREATE(CcontrlUView)

// ����
public:
	CcontrlUDoc* GetDocument() const;

// ����
public:
	int m_id;
	CString m_name;
	CString m_birth;
	CString m_place;
	CString m_gender;
	int change;
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
	virtual ~CcontrlUView();
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
	afx_msg void OnCtrl();
};

#ifndef _DEBUG  // contrlUView.cpp �еĵ��԰汾
inline CcontrlUDoc* CcontrlUView::GetDocument() const
   { return reinterpret_cast<CcontrlUDoc*>(m_pDocument); }
#endif

