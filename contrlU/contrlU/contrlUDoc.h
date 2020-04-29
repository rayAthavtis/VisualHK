
// contrlUDoc.h : CcontrlUDoc 类的接口
//


#pragma once


class CcontrlUDoc : public CDocument
{
protected: // 仅从序列化创建
	CcontrlUDoc();
	DECLARE_DYNCREATE(CcontrlUDoc)

// 特性
public:
	int m_id;
	CString m_name;
	CString m_birth;
	CString m_place;
	CString m_gender;
	int change;
// 操作
public:
	void Set(int &id,CString &na,CString &bi,CString &pl,CString &ge,int &ch);
	void Get(int &id,CString &na,CString &bi,CString &pl,CString &ge,int &ch);
// 重写
public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
#ifdef SHARED_HANDLERS
	virtual void InitializeSearchContent();
	virtual void OnDrawThumbnail(CDC& dc, LPRECT lprcBounds);
#endif // SHARED_HANDLERS

// 实现
public:
	virtual ~CcontrlUDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()

#ifdef SHARED_HANDLERS
	// 用于为搜索处理程序设置搜索内容的 Helper 函数
	void SetSearchContent(const CString& value);
#endif // SHARED_HANDLERS
};
