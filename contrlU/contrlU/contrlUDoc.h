
// contrlUDoc.h : CcontrlUDoc ��Ľӿ�
//


#pragma once


class CcontrlUDoc : public CDocument
{
protected: // �������л�����
	CcontrlUDoc();
	DECLARE_DYNCREATE(CcontrlUDoc)

// ����
public:
	int m_id;
	CString m_name;
	CString m_birth;
	CString m_place;
	CString m_gender;
	int change;
// ����
public:
	void Set(int &id,CString &na,CString &bi,CString &pl,CString &ge,int &ch);
	void Get(int &id,CString &na,CString &bi,CString &pl,CString &ge,int &ch);
// ��д
public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
#ifdef SHARED_HANDLERS
	virtual void InitializeSearchContent();
	virtual void OnDrawThumbnail(CDC& dc, LPRECT lprcBounds);
#endif // SHARED_HANDLERS

// ʵ��
public:
	virtual ~CcontrlUDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()

#ifdef SHARED_HANDLERS
	// ����Ϊ����������������������ݵ� Helper ����
	void SetSearchContent(const CString& value);
#endif // SHARED_HANDLERS
};
