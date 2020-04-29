
// contrlUDoc.cpp : CcontrlUDoc 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
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


// CcontrlUDoc 构造/析构

CcontrlUDoc::CcontrlUDoc()
{
	// TODO: 在此添加一次性构造代码
	m_id=17110;
	m_name="安乔";
    m_birth=_T("1999/06/01");
	m_place="天津";
	m_gender="女";
	change=0;
}

CcontrlUDoc::~CcontrlUDoc()
{
}

BOOL CcontrlUDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: 在此添加重新初始化代码
	// (SDI 文档将重用该文档)

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


// CcontrlUDoc 序列化

void CcontrlUDoc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		ar<<m_id<<m_name<<m_birth<<m_place<<m_gender<<change;
		// TODO: 在此添加存储代码
	}
	else
	{
		ar>>m_id>>m_name>>m_birth>>m_place>>m_gender>>change;
		// TODO: 在此添加加载代码
	}
}

#ifdef SHARED_HANDLERS

// 缩略图的支持
void CcontrlUDoc::OnDrawThumbnail(CDC& dc, LPRECT lprcBounds)
{
	// 修改此代码以绘制文档数据
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

// 搜索处理程序的支持
void CcontrlUDoc::InitializeSearchContent()
{
	CString strSearchContent;
	// 从文档数据设置搜索内容。
	// 内容部分应由“;”分隔

	// 例如:  strSearchContent = _T("point;rectangle;circle;ole object;")；
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

// CcontrlUDoc 诊断

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


// CcontrlUDoc 命令
