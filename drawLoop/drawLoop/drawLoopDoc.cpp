
// drawLoopDoc.cpp : CdrawLoopDoc ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "drawLoop.h"
#endif

#include "drawLoopDoc.h"

#include <propkey.h>

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// CdrawLoopDoc

IMPLEMENT_DYNCREATE(CdrawLoopDoc, CDocument)

BEGIN_MESSAGE_MAP(CdrawLoopDoc, CDocument)
END_MESSAGE_MAP()


// CdrawLoopDoc ����/����

CdrawLoopDoc::CdrawLoopDoc()
{
	d_str.Empty();
	d_poi=CPoint(0,0);
	// TODO: �ڴ����һ���Թ������

}

CdrawLoopDoc::~CdrawLoopDoc()
{
}

BOOL CdrawLoopDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: �ڴ�������³�ʼ������
	// (SDI �ĵ������ø��ĵ�)

	return TRUE;
}




// CdrawLoopDoc ���л�

void CdrawLoopDoc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		ar<<d_str<<d_poi;
		// TODO: �ڴ���Ӵ洢����
	}
	else
	{
		ar>>d_str>>d_poi;
		// TODO: �ڴ���Ӽ��ش���
	}
}

void CdrawLoopDoc::Set(CString &str,CPoint &point){
	d_str=str;
	d_poi=point;
}

void CdrawLoopDoc::Get(CString &str,CPoint &point){
	str=d_str;
	point=d_poi;
}

#ifdef SHARED_HANDLERS

// ����ͼ��֧��
void CdrawLoopDoc::OnDrawThumbnail(CDC& dc, LPRECT lprcBounds)
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
void CdrawLoopDoc::InitializeSearchContent()
{
	CString strSearchContent;
	// ���ĵ����������������ݡ�
	// ���ݲ���Ӧ�ɡ�;���ָ�

	// ����:  strSearchContent = _T("point;rectangle;circle;ole object;")��
	SetSearchContent(strSearchContent);
}

void CdrawLoopDoc::SetSearchContent(const CString& value)
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

// CdrawLoopDoc ���

#ifdef _DEBUG
void CdrawLoopDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CdrawLoopDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// CdrawLoopDoc ����
