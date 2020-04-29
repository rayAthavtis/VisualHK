
// drewTeDoc.cpp : CdrewTeDoc ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "drewTe.h"
#endif

#include "drewTeDoc.h"

#include <propkey.h>

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// CdrewTeDoc

IMPLEMENT_DYNCREATE(CdrewTeDoc, CDocument)

BEGIN_MESSAGE_MAP(CdrewTeDoc, CDocument)
END_MESSAGE_MAP()


// CdrewTeDoc ����/����

CdrewTeDoc::CdrewTeDoc()
{
	// TODO: �ڴ����һ���Թ������
	m_str.Empty();
	m_point=CPoint(0,0);

}

CdrewTeDoc::~CdrewTeDoc()
{
}

BOOL CdrewTeDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: �ڴ�������³�ʼ������
	// (SDI �ĵ������ø��ĵ�)

	return TRUE;
}




// CdrewTeDoc ���л�

void CdrewTeDoc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		ar<<m_str<<m_point;
		// TODO: �ڴ���Ӵ洢����
	}
	else
	{
		ar>>m_str>>m_point;
		// TODO: �ڴ���Ӽ��ش���
	}
}

void CdrewTeDoc::Set(CString &str,CPoint &point){
	m_str=str;
	m_point=point;
}

void CdrewTeDoc::Get(CString &str,CPoint &point){
	str=m_str;
	point=m_point;
}

#ifdef SHARED_HANDLERS

// ����ͼ��֧��
void CdrewTeDoc::OnDrawThumbnail(CDC& dc, LPRECT lprcBounds)
{
	// �޸Ĵ˴����Ի����ĵ�����
	dc.FillSolidRect(lprcBounds, RGB(255, 255, 255));

	CString strText = _T("TODO: implement thumbnail drawing here");
	LOGFONT lf;

	CFont* pDefaultGUIFont = CFont::FromHandle((HFONT) GetStockObject(DEFAULT_GUI_FONT));
	pDefaultGUIFont->GetLogFont(&lf);
	lf.lfHeight = 36;

	CFont fontDraw;
	fontDraw.CreateFontIndirect(&lf);

	CFont* pOldFont = dc.SelectObject(&fontDraw);
	dc.DrawText(strText, lprcBounds, DT_CENTER | DT_WORDBREAK);
	dc.SelectObject(pOldFont);
}

// ������������֧��
void CdrewTeDoc::InitializeSearchContent()
{
	CString strSearchContent;
	// ���ĵ����������������ݡ�
	// ���ݲ���Ӧ�ɡ�;���ָ�

	// ����:  strSearchContent = _T("point;rectangle;circle;ole object;")��
	SetSearchContent(strSearchContent);
}

void CdrewTeDoc::SetSearchContent(const CString& value)
{
	if (value.IsEmpty())
	{
		RemoveChunk(PKEY_Search_Contents.fmtid, PKEY_Search_Contents.pid);
	}
	else
	{
		CMFCFilterChunkValueImpl *pChunk = NULL;
		ATLTRY(pChunk = new CMFCFilterChunkValueImpl);
		if (pChunk != NULL)
		{
			pChunk->SetTextValue(PKEY_Search_Contents, value, CHUNK_TEXT);
			SetChunkValue(pChunk);
		}
	}
}

#endif // SHARED_HANDLERS

// CdrewTeDoc ���

#ifdef _DEBUG
void CdrewTeDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CdrewTeDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// CdrewTeDoc ����
