
// prj_crossy_ver_sdiDoc.h : Cprj_crossy_ver_sdiDoc Ŭ������ �������̽�
//


#pragma once


class Cprj_crossy_ver_sdiDoc : public CDocument
{
protected: // serialization������ ��������ϴ�.
	Cprj_crossy_ver_sdiDoc();
	DECLARE_DYNCREATE(Cprj_crossy_ver_sdiDoc)

// Ư���Դϴ�.
public:

// �۾��Դϴ�.
public:

// �������Դϴ�.
public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
#ifdef SHARED_HANDLERS
	virtual void InitializeSearchContent();
	virtual void OnDrawThumbnail(CDC& dc, LPRECT lprcBounds);
#endif // SHARED_HANDLERS

// �����Դϴ�.
public:
	virtual ~Cprj_crossy_ver_sdiDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ������ �޽��� �� �Լ�
protected:
	DECLARE_MESSAGE_MAP()

#ifdef SHARED_HANDLERS
	// �˻� ó���⿡ ���� �˻� �������� �����ϴ� ����� �Լ�
	void SetSearchContent(const CString& value);
#endif // SHARED_HANDLERS
};
