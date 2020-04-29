
// contrlUDoc.cpp : CcontrlUDoc ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "contrlU.h"
#endif

#include "contrlUDoc.h"

#include <propkey.h>

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// CcontrlUDoc

IMPLEMENT_DYNCREATE(CcontrlUDoc, CDocument)

BEGIN_MESSAGE_MAP(CcontrlUDoc, CDocument)
END_MESSAGE_MAP()


// CcontrlUDoc ����/����

CcontrlUDoc::CcontrlUDoc()
{
	// TODO: �ڴ����һ���Թ������
	m_id=17110;
	m_name="����";
    m_birth=_T("1999/06/01");
	m_place="���";
	m_gender="Ů";
	change=0;
}

CcontrlUDoc::~CcontrlUDoc()
{
}

BOOL CcontrlUDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: �ڴ�������³�ʼ������
	// (SDI �ĵ������ø��ĵ�)

	return TRUE;
}

void CcontrlUDoc::Set(int &id,CString &na,CString &bi,CString &pl,CString &ge,int &ch){
	m_id=id;
	m_name=na;
    m_birth=bi;
	m_place=pl;
	m_gender=ge;
	change=ch;
}

void CcontrlUDoc::Get(int &id,CString &na,CString &bi,CString &pl,CString &ge,int &ch){
	id=m_id;
	na=m_name;
    bi=m_birth;
	pl=m_place;
	ge=m_gender;
	ch=change;
}


// CcontrlUDoc ���л�

void CcontrlUDoc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		ar<<m_id<<m_name<<m_birth<<m_place<<m_gender<<change;
		// TODO: �ڴ���Ӵ洢����
	}
	else
	{
		ar>>m_id>>m_name>>m_birth>>m_place>>m_gender>>change;
		// TODO: �ڴ���Ӽ��ش���
	}
}

#ifdef SHARED_HANDLERS

// ����ͼ��֧��
void CcontrlUDoc::OnDrawThumbnail(CDC& dc, LPRECT lprcBounds)
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
void CcontrlUDoc::InitializeSearchContent()
{
	CString strSearchContent;
	// ���ĵ����������������ݡ�
	// ���ݲ���Ӧ�ɡ�;���ָ�

	// ����:  strSearchContent = _T("point;rectangle;circle;ole object;")��
	SetSearchContent(strSearchContent);
}

void CcontrlUDoc::SetSearchContent(const CString& value)
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

// CcontrlUDoc ���

#ifdef _DEBUG
void CcontrlUDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CcontrlUDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// CcontrlUDoc ����
